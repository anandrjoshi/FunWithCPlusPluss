
#include "Group4_Hash.h"

using namespace std;

#define MAX_SIZE 15
#define TO_BE_POPULATED 0.4

int main()
{
	Group4_Hash new_hash_default = Group4_Hash();

	/*	Group4_Hash new_hash_with_size = Group4_Hash(MAX_SIZE, TO_BE_POPULATED);

		cout << "values in hash default location 4 " << new_hash_default.getValueAtPosition(4) << endl;
		cout << "values in hash default location 1 " << new_hash_default.getValueAtPosition(1) << endl;
		cout << "values in hash default location 9 " << new_hash_default.getValueAtPosition(40) << endl;

		cout << "values in hash size location 4 " << new_hash_with_size.getValueAtPosition(3) << endl;
		cout << "values in hash size location 1 " << new_hash_with_size.getValueAtPosition(1) << endl;
		cout << "values in hash size location MAX_SIZE " <<(int)(MAX_SIZE/TO_BE_POPULATED) << " " << new_hash_with_size.getValueAtPosition((int)(MAX_SIZE/TO_BE_POPULATED)) << endl;*/
	
	cout << " has size before = " << new_hash_default.getHashSize() << endl;
	new_hash_default.deleteValue(5);
	new_hash_default.deleteValue(15);
	new_hash_default.addValue(2);
	new_hash_default.addValue(12);
	new_hash_default.addValue(12);
	new_hash_default.addValue(12);
	//new_hash_default.deleteValue(12);
	//new_hash_default.deleteValue(12);
	//new_hash_default.deleteValue(12);
	//new_hash_default.deleteValue(12);
	new_hash_default.addValue(12);
	new_hash_default.addValue(12);
	new_hash_default.addValue(12);
	new_hash_default.addValue(12);
	new_hash_default.addValue(12);
	new_hash_default.addValue(12);
	new_hash_default.addValue(12);
	new_hash_default.addValue(13);
	
	cout << " has size after = " << new_hash_default.getHashSize() << endl;
	cout << "get value at 1 = "<< new_hash_default.getValueAtPosition(1) << endl;
	cout << "get value at 10 = "<< new_hash_default.getValueAtPosition(10) << endl;
	cout << "get value at " << new_hash_default.getHashSize() << " = "<< new_hash_default.getValueAtPosition(new_hash_default.getHashSize()) << endl;
	cout << "Are hash equal = " << new_hash_default.checkIfHashEqual();

	system("pause");
	return 0;
}