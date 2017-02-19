#include <iostream>

using namespace std;

int brute_force(int * arr1, int *arr2, int k);

int main()
{
	int arr1[] = {10,22,30,42,50,62,70,82,90,102,110,122,130,143,150};
	int arr2[] = {11,21,30,41,51,61,71,81,91,101,111,121,131};
	int k;

	cout << "provide k:" << endl;
	cin >> k;

	int length_arr1 = sizeof(arr1)/sizeof(int);
	int length_arr2 = sizeof(arr2)/sizeof(int);

	if(k >= length_arr1+length_arr2)
		cout << "k is out of bounds" << endl;

	else
	{
		cout << "kth largest element using brute force is: " << 
			brute_force(arr1, arr2, k);
	}
	system("pause");
	return 1;
}

int brute_force(int *arr1, int *arr2, int k)
{
	int kth_return = 0;
	int count = 0;

	while(count != k)
	{
		if(*arr1 < *arr2)
		{
			kth_return = *arr1;
			*arr1++;
		}
		else if(*arr1 == *arr2)
		{
			kth_return = *arr1;
			*arr1++;
			*arr2++;
			count++;
		}
		else
		{
			kth_return = *arr2;
			*arr2++;
		}
		count++;
	}
	
	return kth_return;
}