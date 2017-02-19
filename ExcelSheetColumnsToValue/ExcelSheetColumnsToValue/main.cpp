#include <iostream>

using namespace std;

#define lower 96
#define upper 64


int main()
{
	char * columnName = "aA";
	char * tempCounter = columnName;
	int count = 0;
	while(*tempCounter != '\0')
	{
		count++;
		tempCounter++;
	}

	int output = 0;

	while(*columnName != '\0')
	{
		int multiplier = 1;
		int lowerOrUpper = upper;
		if((int)(*columnName) > lower)
			lowerOrUpper = lower;

		for(int i = 1; i<count; i++)
			multiplier*=26;
		
		output += multiplier*((int)(*columnName) - lowerOrUpper);
		count--;
		columnName++;
	}

	cout << "Column number for given column is = " << output << endl;
	system("pause");
	return 0;
}