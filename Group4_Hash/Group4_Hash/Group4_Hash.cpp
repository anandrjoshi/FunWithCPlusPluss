
#include <fstream>
#include "Group4_Hash.h"


using namespace std;

#define DEFAULT_HASH_SIZE 3
#define DEFAULT_TO_BE_POPULATED 0.25
#define CHANGE_HASH_SIZE_BY 0.75
#define DELETED_LOCATION_IN_HASH (unsigned int) -1

Group4_Hash::Group4_Hash(int _hash_size, double _to_be_populated)
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

	if(value == NULL || numberOfTimes == NULL)
		cout << "ERROR::Group4_Hash::Group4_Hash(unsigned int _hash_size): Unable to create array for this hash" << endl;
	else
	{
		number_of_unique_values_present = 0;
		initializeHash(hash_size, value, numberOfTimes);
	}
}

Group4_Hash::~Group4_Hash()
{
	if (value != NULL )
		delete []value;
	if (numberOfTimes != NULL )
		delete []numberOfTimes;
}

void Group4_Hash::initializeHash(unsigned int _hash_size, unsigned int*& hash_to_be_initialized, unsigned int*& numberOfTimes_to_be_initialized)
{
	for(int i = 0; i < _hash_size; i ++)
	{
		hash_to_be_initialized[i] = 0;
		numberOfTimes_to_be_initialized[i] = 0;
	}
}

void Group4_Hash::createHash(unsigned int _hash_size, double _to_be_populated)
{
	value = NULL;
	to_be_populated =_to_be_populated;
	hash_size = _hash_size/_to_be_populated;
	value = new unsigned int[hash_size];
	numberOfTimes = NULL;
	numberOfTimes = new unsigned int[hash_size];
}

bool Group4_Hash::isValueEnteredValid(int _value)
{
	if(_value <= 0 || _value >= DELETED_LOCATION_IN_HASH)
		return false;
	else	
		return true;
}

bool Group4_Hash::addValue(int _value)
{
	int collision_counter = 0;

	if(!isValueEnteredValid(_value))
	{
		cout << "ERROR::Group4_Hash::addValue(unsigned int) Value to be added has to be in between 0 and "<< DELETED_LOCATION_IN_HASH << endl;
		return false;
	}

	if((double)number_of_unique_values_present/hash_size > 0.8)
		changeHashSize(true);

	if((double)number_of_unique_values_present/hash_size > to_be_populated)
		cout << "Warning::Group4_Hash::addValue(unsigned int) Hash is almost full!!! " << endl;

	unsigned int index = 0;
	index = _value % hash_size;

	while (true)
	{
		if(index > hash_size) index = 0;

		if(value[index] == _value)
		{
			numberOfTimes[index]++;
			cout << _value << " exists in hash for "<<numberOfTimes[index] <<" times. Collisions encounterd = " << collision_counter << endl;
			return true;
		}

		if(value[index] == 0)
		{
			value[index] = _value;
			number_of_unique_values_present++;
			numberOfTimes[index]++;
			cout << _value << " added successfully in hash. Collisions encounterd = " << collision_counter << endl;
			return true;
		}
		collision_counter++;
		index++;
	}
}

bool Group4_Hash::deleteValue(int _value)
{
	int collision_counter = 0;

	if(!isValueEnteredValid(_value))
	{
		cout << "ERROR::Group4_Hash::deleteValue(unsigned int) Value to be added has to be in between 0 and "<< DELETED_LOCATION_IN_HASH << endl;
		return false;
	}

	unsigned int index = 0;
	index = _value % hash_size;	

	while (value[index] != 0)
	{
		if(index > hash_size) index = 0;

		if(value[index] == _value)
		{
			if(numberOfTimes[index] > 1)
			{
				numberOfTimes[index]--;
				cout << "instance of " << _value << " deleted from hash. Collisions encounterd = " << collision_counter << endl;
				return true;
			}

			numberOfTimes[index] = 0;
			number_of_unique_values_present--;
			value[index] = DELETED_LOCATION_IN_HASH;
			cout << _value << " deleted from hash. Collisions encounterd = " << collision_counter << endl;

			if((double)2*number_of_unique_values_present/hash_size < 0.8)
				changeHashSize(false);
			return true;
		}
		collision_counter++;
		index++;
	}
	cout << _value <<" doesnot exist in the hash." << endl; 
	return false;	
}

bool Group4_Hash::findValue(int _value)
{
	int collision_counter = 0;

	if(!isValueEnteredValid(_value))
	{
		cout << "ERROR::Group4_Hash::findValue(unsigned int) Value to be added has to be in between 0 and "<< DELETED_LOCATION_IN_HASH << endl;
		return false;
	}

	unsigned int index = 0;
	index = _value % hash_size;	

	while (value[index] != 0)
	{
		if(index > hash_size) index = 0;

		if(value[index] == _value)
		{
			cout << _value << " found at location " << index 
				 << " in hash. Number of instances  = " << numberOfTimes[index] 
			     <<". Collision counter = " << collision_counter << endl;
			return true;
		}
		collision_counter++;
		index++;
	}
	cout << _value <<" not found in the hash." << endl; 
	return false;	
}

bool Group4_Hash::changeHashSize(bool _operation)
{	
	int new_hash_index=0;
	unsigned int new_hash_size = 0;

	if (_operation)
	{
		cout << "\nExpanding..." << endl;
		new_hash_size= hash_size/CHANGE_HASH_SIZE_BY;
	}
	else
	{
		cout<<"\nContracting... \n" << endl;
		new_hash_size= hash_size*CHANGE_HASH_SIZE_BY;
	}

	unsigned int* new_temp_hash = new unsigned int[new_hash_size];
	unsigned int* new_temp_numberOfTimes = new unsigned int[new_hash_size];

	if(new_temp_hash == NULL || new_temp_numberOfTimes == NULL)
	{
		cout << "ERROR::bool Group4_Hash::changeHashSize() unable to allocate memory." << endl;
		return false;
	}

	initializeHash(new_hash_size, new_temp_hash, new_temp_numberOfTimes);

	for(int i = 0; i < hash_size; i ++)
	{
		if(value[i] != 0 && value[i] != DELETED_LOCATION_IN_HASH)
		{
			unsigned int index = 0;
			index = value[i] % new_hash_size;

			while (true)
			{
				if(index > new_hash_size) index = 0;

				if(new_temp_hash[index] == 0)
				{
					new_temp_hash[index] = value[i];
					new_temp_numberOfTimes[index] = numberOfTimes[i]; 
					break;
				}
				index++;
			}
		}
	}

	delete []value;
	value = new_temp_hash;
	delete []numberOfTimes;
	numberOfTimes = new_temp_numberOfTimes;

	hash_size = new_hash_size;
	cout << "\nnew hash_size " << hash_size << endl;
	return true;
}

bool Group4_Hash::readFromFile()
{
	ifstream readFromFile;
	readFromFile.open("hash_file.txt");

	if (!readFromFile.is_open())
	{
		cout << "ERROR: Group4_Hash::readFromFile() Unable to open file."<< endl;
		return false;
	}

	while(!readFromFile.eof())
	{
		unsigned int value;
		readFromFile >> value;
		if(value <= 0 || value >= DELETED_LOCATION_IN_HASH)
		{
			cout << "ERROR::Group4_Hash::readFromFile() Value to be added has to be in between 0 and "<< DELETED_LOCATION_IN_HASH << endl;
			break;
		}

		if(!addValue(value))
		{
			cout<<"ERROR::Group4_Hash::readFromFile() Unable to add value to the Hash"<<endl;
			readFromFile.close();
			return false;
		}
	}
	readFromFile.close();
	return true;
}

bool Group4_Hash::writeToFile()
{
	ofstream writeToFile;
	writeToFile.open("hash_file.txt");

	if (!writeToFile.is_open())
	{
		cout << "ERROR: Group4_Hash::writeToFile() Unable to open file."<< endl;
		return false;
	}

	for(int i = 0; i < hash_size; i ++)
	{
		for(int j = 0; j < numberOfTimes[i]; j++)
			writeToFile << value[i] << endl;
	}
		
	writeToFile.close();
	return true;
}

void Group4_Hash::viewAllContents()
{
	cout << "\n\nContents of Hash are as follows:" << endl;
	cout << "\n\tSize of Hash = " << getHashSize() << endl;
	cout << "\tNumber of unique Elements = " << getNumberOfValuesPresent() << endl;

	cout << "\n\t Element \tIndex \tNumber of Times" << endl;
	for(int i = 0; i < getHashSize(); i ++)
	{
		if(value[i] != 0)
			cout <<"\t   " << value[i] << "\t\t   " << i << "\t\t   "<< numberOfTimes[i] << endl;
	}
}
