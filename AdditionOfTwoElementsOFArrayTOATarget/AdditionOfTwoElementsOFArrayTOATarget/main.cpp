#include <iostream>

using namespace std;

void FindTarget(int arr[], int sizeOfArr, int target);

int main()
{
	int arr1[] = {2,4,6,8,3,1,5,2,3};
	int target = 7;
	int sizeOfArr = sizeof(arr1)/sizeof(int);

	FindTarget(arr1, sizeOfArr, target);

	system("pause");
	return 0;
}

void FindTarget(int arr[], int sizeOfArr, int target)
{
	int count = 0;
	for(int i = 0; i < sizeOfArr; i ++)
	{
		for(int j = i+1; j < sizeOfArr; j++)
		{
			if(*(arr+i) + *(arr+j) == target)
			{
				cout << "addition of " << *(arr+i) << " and " <<*(arr+j) << " equals " << target << endl;
				count ++;
			}
		}
	}
	cout << "therefore number of pairs are " << count << endl; 
}