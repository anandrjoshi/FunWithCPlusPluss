#include <iostream>

using namespace std;

void find_subsequence(int * given_array, int* set, int array_length, int set_length);

int main()
{
	int given_array[] = {1,2,2,3,2,4,5,5,3,3,4,3,2,4,1,5,6,5,3,5};
	int set_of_integers[] = {0};

	int array_length = sizeof(given_array)/sizeof(int);
	int set_length = sizeof(set_of_integers)/sizeof(int);

	find_subsequence(given_array, set_of_integers, array_length, set_length);	
	system("pause");
	return 0;
}

void find_subsequence(int* given_array, int* set, int array_length, int set_length)
{
	int sequence_index[] = {0,0};

	int front = 0;
	int back = 0;
	int length = 0;
	int counter = 0;

	while(back < array_length)
	{
		int found_match = false;
		for(int i=0; i<set_length; i++)
		{
			if(given_array[back] == set[i])
			{
				found_match = true;
				back++;
			}
		}

		if(!found_match)
		{
			if((back-front) > length)
			{
				sequence_index[0]=front;
				sequence_index[1]=back;
				length = (back-front);
			}
			front = back;
			back++;
		}
	}	

	cout << "length of longest sub-sequence = " << length-1 << endl;

	if((length-1) == 0)
		cout << "No subsequence found" << endl;
	else
	{
		cout << "longest sub-sequence for the given array is = ";

		for(int i = sequence_index[0]+1; i < sequence_index[1]; i++)
			cout << given_array[i];
	}
}