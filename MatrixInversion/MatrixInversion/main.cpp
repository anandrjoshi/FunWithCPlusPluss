#include <iostream>

using namespace std;

#define DEFAULT_DIMENSION 1

int main()
{
	int dimensions = 0;
	
	cout << "number of rows in the matrix: " << endl;
	cin >> dimensions;
	
	int *original_array = new int[dimensions*dimensions];
	int *inverted_array = new int[dimensions*dimensions];

	for (int row = 0; row < dimensions; row++)
		for (int col = 0; col < dimensions; col++)
		{
			cout << "element for row = " << row << " and column = " << col << endl;
			cin >> original_array[col + row*dimensions];
		}

	cout <<"Inverted matrix by creating new matrix " << endl;
	for (int row = 0; row < dimensions; row++)
		for (int col = 0; col < dimensions; col++)
		{
			inverted_array[col*dimensions + row] = original_array[col + row*dimensions];
		}

	for (int row = 0; row < dimensions; row++)
		for (int col = 0; col < dimensions; col++)
		{
			cout << "element at row = " << row << " and column = " << col << " is " << inverted_array[col + row*dimensions]<< endl;
		}

	cout <<"Inverted matrix by reading same matrix differently" << endl;
	for (int row = 0; row < dimensions; row++)
		for (int col = 0; col < dimensions; col++)
		{
			cout << "element at row = " << row << " and column = " << col << " is " << original_array[col*dimensions + row]<< endl;
		}
	
	cout <<"Inverted matrix by swapping elements within originl array " << endl;
	for (int row = 0; row < dimensions; row++)
		for (int col = row; col < dimensions; col++)
		{
			int temp = original_array[col + row*dimensions];
			original_array[col + row*dimensions] = original_array[row + col*dimensions];
			original_array[row + col*dimensions] = temp;
		}

	for (int row = 0; row < dimensions; row++)
		for (int col = 0; col < dimensions; col++)
		{
			cout << "element at row = " << row << " and column = " << col << " is " << original_array[col + row*dimensions]<< endl;
		}

	system("pause");

	return 0;
}

