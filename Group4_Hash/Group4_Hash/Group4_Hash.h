#ifndef _GROUP4_HASH
#define _GROUP4_HASH

#include <iostream>

class Group4_Hash
{
	unsigned int* value;
	unsigned int* numberOfTimes;
	unsigned int hash_size;
	double to_be_populated;
	unsigned int number_of_unique_values_present;

	void createHash(unsigned int _hash_size, double _to_be_populated);
	void initializeHash(unsigned int _hash_size, unsigned int*& hash, unsigned int*& numberOfTimes);

	bool changeHashSize(bool);

	bool isValueEnteredValid(int _value);

public:
	Group4_Hash(){};
	Group4_Hash(int _hash_size, double _to_be_populated);
	~Group4_Hash();

	unsigned int getHashSize(){return hash_size;}
	unsigned int getToBePopulated(){return (double)to_be_populated;}
	unsigned int getNumberOfValuesPresent(){return number_of_unique_values_present;}

	bool addValue(int _value);
	bool addValue(unsigned int _value, unsigned int _numberOfTimes);
	bool deleteValue(int _value);
	bool findValue(int _value);
	bool readFromFile();
	bool writeToFile();
	void viewAllContents();
		
};
#endif // _GROUP4_HASH
