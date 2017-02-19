#include<iostream>
#include<math.h>
using namespace std;

void print_subsets(int numbers[], int num_of_numbers) 
{
    int pow_of_num = pow(2.0, num_of_numbers);
    int i;
    for (i = 0; i < pow_of_num; i++) 
	{
        int j = i;
        int digit = 0;
        while (j != 0) 
		{
            if (j % 2) 
			{
               cout << numbers[digit] << endl;
            }
            digit++;
            j /= 2; // This can also be done by bitwise operation
         }
        cout << "===============" << endl;
    }
}

void print_subsets_test_drive() 
{
    int numbers[] = {1, 2, 3};
    print_subsets(numbers, 3);
}

int main() 
{
    print_subsets_test_drive();
	system("pause");
    return 0;
}
