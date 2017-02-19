#include "PIV_Hash.h"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

PIV_Hash::PIV_Hash(unsigned _number_of_values_to_be_stored, double _to_be_populated)
{
	number_of_values_present = 0;
	collision_counter = 0;
	values = NULL;

	if(_number_of_values_to_be_stored == 0)
	{
		cout << "WARNING::PIV_Hash::PIV_Hash number of values to be stored cannot be 0. Number of values to be stored set to 10" << endl;
		_number_of_values_to_be_stored = 10;
	}

	if(_to_be_populated < 0.1 || _to_be_populated > 0.8)
	{
		cout << "WARNING::PIV_Hash::PIV_Hash to be populated cannot be less than 0.1 or greater than 0.8. to be populated set to 0.25" << endl;
		_to_be_populated = 0.25;
	}

	to_be_populated = _to_be_populated;
	array_size = _number_of_values_to_be_stored / _to_be_populated;
	
	values = new unsigned int[array_size];

	if(values == NULL)
	{
		array_size = 0;
		cout << "ERROR::PIV_Hash::PIV_Hash Allocation of memory was not successful. " << endl;
		return;
	}
	unsigned int i;
	for(i=0; i<array_size; i++) values[i] = 0;	
}

PIV_Hash::PIV_Hash(char * _file_name, double _to_be_populated)
{
}

PIV_Hash::PIV_Hash(PIV_Hash * _piv_hash, double _to_be_populated)
{
}

PIV_Hash::~PIV_Hash()
{
	if(values != NULL)
		delete [] values;
}

bool PIV_Hash::add_Value(unsigned int _value)
{
	if(_value < 1)
	{
		cout << "ERROR::PIV_Hash::add_Value::Values entered in Hash cannot be less than 1" << endl;
		return false;
	}

	if(number_of_values_present/array_size < to_be_populated) 
	{
		unsigned int _index;
		collision_counter = 0;
		_index = _value % array_size;

		if(values[_index] == 0)
		{
			values[_index] = _value;
			number_of_values_present ++;
			return true;
		}

		for(;;)
		{
			_index++;
			collision_counter++;
			if(_index >= array_size) _index = 0;

			if(values[_index] != 0)
			{
				continue;
			}
			values[_index] == _value;
			number_of_values_present ++;
			return true;
		}
	}
	return false;
}

bool PIV_Hash::find_Value(unsigned _value)
{
	unsigned int _index = 0;
	collision_counter = 0;
	if(_value < 1)
	{
		cout << "ERROR::PIV_Hash::find_Value::Values entered in Hash cannot be less than 1" << endl;
		return false;
	}
	_index = _value % array_size;

	if (values[_index] == 0) return false;
	if (values[_index] == _value) return true;

	for(;;)
	{
		collision_counter++;
		_index++;

		if(_index >= array_size) _index = 0;

		if (values[_index] == 0) return false;
		if (values[_index] == _value) return true;
	}
}

bool PIV_Hash::write_to_File(ofstream &_file_name)
{
	_file_name << number_of_values_present << endl;
	for(unsigned int i = 0; i< array_size; i++)
		if(values[i] != 0) _file_name << values[i] << endl;
	return true;
}

bool PIV_Hash::write_to_Value(ifstream &_file_name)
{
	string line;
	while ( _file_name.good() )
    {
		getline(_file_name, line);
		unsigned int value;
		stringstream myStream(line);
		myStream>>value;
		if (add_Value(value))
			cout <<" Addition successful" << endl;
		else
			cout <<" Addition failed" << endl;
    }
	return true;
}

unsigned int PIV_Hash::get_Array_Size()
{
	return array_size;
}

unsigned int PIV_Hash::get_Number_of_Values_Present()
{
	return number_of_values_present;
}