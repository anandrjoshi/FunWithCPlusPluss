
#include "PIV_Hash.h"
#include <iostream>
#include <fstream>


using namespace std;

void main()
{
	unsigned int _number_of_values_to_be_stored = 2;
	double _to_be_populated = 0.25;

	PIV_Hash *piv_hash = new PIV_Hash(_number_of_values_to_be_stored, _to_be_populated);
	for(unsigned int i = 1; i <= 4; i++)
	{
		if (piv_hash->add_Value(i))
			cout <<" Addition successful" << endl;
		else
			cout <<" Addition failed" << endl;
	}

	if(piv_hash->find_Value(0))
		cout << "Value 0 found. " <<  endl;
	else
		cout << "Value 0 not found. " <<  endl;

	if(piv_hash->find_Value(1))
		cout << "Value 1 found. " <<  endl;
	else
		cout << "Value 1 not found. " <<  endl;

	if(piv_hash->find_Value(3))
		cout << "Value 3 found. " <<  endl;
	else
		cout << "Value 3 not found. " <<  endl;

	if(piv_hash->find_Value(10))
		cout << "Value 10 found. " <<  endl;
	else
		cout << "Value 10 not found. " <<  endl;

	if(piv_hash->find_Value(15))
		cout << "Value 15 found. " <<  endl;
	else
		cout << "Value 15 not found. " <<  endl;

	/*	ifstream myInFile;
		myInFile.open ("values.txt", ifstream::in);
		if (myInFile.is_open())
		{
			piv_hash->write_to_Value(myInFile);
			myInFile.close();
		}
		else
			cout << "ERROR::Unable to open input file" << endl;*/

	ofstream myOutFile;
	myOutFile.open ("values.txt", ofstream::out);
	if (myOutFile.is_open())
	{
		piv_hash->write_to_File(myOutFile);
		myOutFile.close();
	}
	else 
		cout << "ERROR::Unable to open output file" << endl;

	delete piv_hash;
	system("pause");
}