#ifndef _GROUP4_HASH
#define _GROUP4_HASH

#include <iostream>

class Group4_Hash
{
	unsigned int* value;
	unsigned int * duplicateValue;
	unsigned int hash_size;
	double to_be_populated;
	unsigned int number_of_values_present;

	void createHash(unsigned int _hash_size, double _to_be_populated);
	void initializeHash(unsigned int _hash_size);

	void expandHash();

public:
	Group4_Hash();
	Group4_Hash(unsigned int _hash_size, double _to_be_populated);
	~Group4_Hash();

	unsigned int getHashSize(){return hash_size;}
	unsigned int getToBePopulated(){return (double)to_be_populated;}
	unsigned int getNumberOfValuesPresent(){return number_of_values_present;}

	bool checkIfHashEqual();
	int getValueAtPosition(unsigned int _position);
	bool addValue(unsigned int _value);
	bool deleteValue(unsigned int _value);
	
};
#endif // _GROUP4_HASH