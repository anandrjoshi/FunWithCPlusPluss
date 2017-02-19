#include "Group4_Hash.h"

using namespace std;

#define DEFAULT_HASH_SIZE 3
#define DEFAULT_TO_BE_POPULATED 0.25
#define CHANGE_HASH_SIZE_BY 0.5

Group4_Hash::Group4_Hash()
{
	createHash(DEFAULT_HASH_SIZE, DEFAULT_TO_BE_POPULATED);

	if(value == NULL || duplicateValue ==  NULL)
		cout << "ERROR::Group4_Hash::Group4_Hash(): Unable to create array for this hash."<< endl;
	else
		initializeHash(hash_size);
}

Group4_Hash::Group4_Hash(unsigned int _hash_size, double _to_be_populated)
{
	if (_hash_size <= 0)
	{
		cout << "ERROR::Group4_Hash::Group4_Hash(unsigned int, double): hash size must be greater than 0. Setting it to " << DEFAULT_HASH_SIZE << endl;
		_hash_size = DEFAULT_HASH_SIZE;
	}
	else if(_to_be_populated < 0.1 || _to_be_populated > 0.8)
	{
		cout << "ERROR::Group4_Hash::Group4_Hash(unsigned int, double): to_be_populated must be greater than 0.1 and less than 0.8 Setting it to " << DEFAULT_TO_BE_POPULATED << endl;
		_to_be_populated = DEFAULT_TO_BE_POPULATED;
	}

	createHash(_hash_size, _to_be_populated);

	if(value == NULL || duplicateValue == NULL)
		cout << "ERROR::Group4_Hash::Group4_Hash(unsigned int _hash_size): Unable to create array for this hash" << endl;
	else
		initializeHash(hash_size);
}

Group4_Hash::~Group4_Hash()
{
	if (value != NULL )
		delete []value;
	if (duplicateValue != NULL )
		delete []duplicateValue;
}

int Group4_Hash::getValueAtPosition(unsigned int _position)
{
	if (_position > 0 && _position <= hash_size)
		return value[_position - 1];
	else
		return -1;
}

void Group4_Hash::initializeHash(unsigned int _hash_size)
{
	number_of_values_present = 0;
	for(int i=0; i<_hash_size; i++)
	{
		value[i] = 0;
		duplicateValue[i] = 0;
	}
}

void Group4_Hash::createHash(unsigned int _hash_size, double _to_be_populated)
{
	value = NULL;
	to_be_populated =_to_be_populated;
	hash_size = _hash_size/_to_be_populated;
	value = new unsigned int[hash_size];
	duplicateValue = NULL;
	duplicateValue =  new unsigned int[hash_size];
}

bool Group4_Hash::addValue(unsigned int _value)
{
	int collision_counter = 0;

	if(_value <= 0)
	{
		cout << "ERROR::Group4_Hash::addValue(unsigned int) Value to be added cannot be less than or equal to zero." << endl;
		return false;
	}

	if((double)number_of_values_present/hash_size > 0.8)
	{
		expandHash();
	}

	if((double)number_of_values_present/hash_size > to_be_populated)
		cout << "Warning::Group4_Hash::addValue(unsigned int) Hash is almost full!!! " << endl;

	unsigned int index = 0;
	index = _value % hash_size;

	if(value[index] == 0)
	{
		value[index] = _value;
		number_of_values_present++;
		duplicateValue[index] = _value;
		cout << _value << " added successfully in hash. Collisions encounterd = " << collision_counter << endl;
		return true;
	}

	while (1)
	{
		collision_counter++;
		index++;
		if(index > hash_size) index = 0;

		if(value[index] == 0)
		{
			value[index] = _value;
			number_of_values_present++;
			duplicateValue[index] = _value;
			cout << _value << " added successfully in hash. Collisions encounterd = " << collision_counter << endl;
			return true;
		}
	}
}
	
bool Group4_Hash::deleteValue(unsigned int _value)
{
	int collision_counter = 0;

	if(_value <= 0)
	{
		cout << "ERROR::Group4_Hash::deleteValue(unsigned int) Value to be added cannot be less than or equal to zero." << endl;
		return false;
	}

	unsigned int index = 0;
	index = _value % hash_size;

	while (index < hash_size)
	{
		if(value[index] == _value)
		{
			value[index] = 0;
			number_of_values_present--;
			duplicateValue[index] = 0;
			cout << _value << " deleted successfully in hash. Collisions encounterd = " << collision_counter << endl;
			return true;
		}
		collision_counter++;
		index ++;
	}

	index = 0;
	while (index < _value % hash_size)
	{
		if(value[index] == _value)
		{
			value[index] = 0;
			number_of_values_present--;
			duplicateValue[index] = 0;
			cout << _value << " deleted successfully in hash. Collisions encounterd = " << collision_counter << endl;
			return true;
		}
		collision_counter++;
		index ++;
	}

	cout << _value <<" doesnot exist in the hash Collisions encountered = " << collision_counter << endl; 
	return false;
}

bool Group4_Hash::checkIfHashEqual()
{
	for (int i = 0; i < hash_size; i ++)
	{
		if(value[i] != duplicateValue[i])
			return false;
	}
	return true;
}

void Group4_Hash::expandHash()
{
	unsigned int new_hash_size = hash_size/CHANGE_HASH_SIZE_BY;

	unsigned int* temp_hash = new unsigned int[hash_size];

	for(int i = 0; i < hash_size; i ++)
		temp_hash[i] = value[i];

	delete []value;
	value = NULL;
	delete []duplicateValue;
	duplicateValue = NULL;

	value = new unsigned int[new_hash_size];
	duplicateValue = new unsigned int[new_hash_size];

	for(int i = 0; i < new_hash_size; i ++)
	{
		 value[i] = temp_hash[i];
		 duplicateValue[i] = value[i];
	}

	delete []temp_hash;
	hash_size = new_hash_size;
}
