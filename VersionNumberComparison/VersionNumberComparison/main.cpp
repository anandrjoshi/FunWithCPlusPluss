#include <iostream>
#include <string.h>
#include <vector>

using namespace std;

std::vector<int> parse_string(char string[]);
int compare_versions(std::vector<int>, std::vector<int>);

int main()
{
	char str1[] = "12.35.4.1";
	char str2[] = "13.35.3.1";
	char * token;
	std::vector<int> int_str1 = parse_string(str1);
	std::vector<int> int_str2 = parse_string(str2);

	int compare =  compare_versions(int_str1, int_str2);
	
	if(compare == -1)
		cout << "Version 1 is greater than Version 2." << endl;
	else if(compare == 1)
		cout << "Version 2 is greater than Version 1." << endl;
	else
		cout << "Version 1 and Version 2 are equal." << endl;
	
	system("pause");
	return 0;
}

std::vector<int> parse_string(char string[])
{
	char * token;
	std::vector<int> int_str;

	token = strtok(string,".");
	
	while(token!=NULL)
	{
		int temp = atoi(token);
		int_str.push_back(temp);
		token = strtok(NULL, ".");
	}

	return int_str;
}

int compare_versions(std::vector<int>int_str1, std::vector<int>int_str2)
{
	int compare = 0;
	int it_str1 = 0;
	int it_str2 = 0;

	while(it_str1 != int_str1.size() && it_str2 != int_str2.size())
	{
		if(int_str1.at(it_str1) > int_str2.at(it_str2))
		{
			compare = -1;
			break;
		}
		else if(int_str1.at(it_str1) < int_str2.at(it_str2))
		{
			compare = 1;
			break;
		}
		else
		{
			it_str1++;
			it_str2++;
		}
	}

	if(compare == 0)
	{
		if(int_str1.size() > int_str2.size() && int_str1.at(int_str2.size()) > 0)
			compare = -1;
		else if(int_str1.size() > int_str2.size() && int_str1.at(int_str2.size()) == 0)
			compare = 0;

		if(int_str1.size() < int_str2.size() && int_str2.at(int_str1.size()) > 0)
			compare = 1;
		else if(int_str1.size() < int_str2.size() && int_str2.at(int_str1.size()) == 0)
			compare = 0;
	}

	return compare;
}