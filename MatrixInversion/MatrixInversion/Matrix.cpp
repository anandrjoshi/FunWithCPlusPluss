#include "Matrix.h"
#include <iostream>

using namespace std;

Matrix::Matrix(unsigned int _dimensions)
{
	if (_dimensions <= 0)
	{
		cout << "ERROR::Stack_OOAD::Stack_OOAD(unsigned int): stack size must be greater than 0. Setting it to " << DEFAULT_DIMENSIONS << endl;
		dimensions = DEFAULT_DIMENSIONS;
	}
	else
		dimensions = _dimensions;

	matrix = NULL;
	matrix = new int[dimensions*dimensions];
}
