#include <iostream>

using namespace std;



void permutations(char * inputs, int length, int index)
{
	if(index == length)
	{
		int count = 0;
		while(count != length) 
		{
			cout << *(inputs+count);
			count++;
		}
		cout << endl;
		return;
	}

	permutations(inputs, length, index+1);

	for(int i = index+1; i < length; i++)
	{
		char * str = inputs;
		char temp = *(str+i);
		*(str+index) = *(str+i);
		*(str+i) = temp;

		permutations(str, length, index+1);
	}
}

	
	
int main()
{
	permutations("123", 3, 0);
	system("pause");
	return 1;
}