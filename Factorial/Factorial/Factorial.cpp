#include "Factorial.h"


Factorial::Factorial(unsigned int _max_number_of_factorials)
{
	if (_max_number_of_factorials < 0 || _max_number_of_factorials > 170)
	{
		cout <<"ERROR: Factorial::Factorial(): Unable to create array of factorials of size less than zero or greater than 170" << endl;
		max_number_of_factorials = 0;
	}
	else
	{	
		factorials = NULL;
		calculate_factorials(_max_number_of_factorials);
	}
}

Factorial::~Factorial()
{
	free(factorials);
	factorials = NULL;
}

double Factorial::get_factorial(unsigned int _position)
{
	if (_position < max_number_of_factorials)
	{
		return factorials[_position];
	}
	cout << "ERROR: Factorial::get_factorial(): invlaid position being searched" << endl;
	return -1;
}

bool Factorial::set_factorial(unsigned int _position, double _factorial)
{
	if(_position > max_number_of_factorials)
	{
		cout<<"ERROR: Factorial::set_factorials(): invlaid position being searched!"<<endl;
		return false;
	}
	factorials[_position]=_factorial;
	return true;
}

unsigned int Factorial::get_max_number_of_factorials()
{
	return max_number_of_factorials;
}

void Factorial::resize_factorial_array(unsigned int _new_max_number_of_factorials)
{
		free(factorials);
		factorials = NULL;
		calculate_factorials(_new_max_number_of_factorials); 
}

void Factorial::calculate_factorials(unsigned int _max_number_of_factorials)
{
	factorials = (double*)malloc((_max_number_of_factorials+1)*sizeof(double));
	if(factorials == NULL)
	{
		cout<<"ERROR: Factorial::calculate_factorials() == NULL!"<<endl;
		max_number_of_factorials = 0;
		return;
	}
	factorials[0] = 1;
	unsigned int i;
	for(i=1; i<= _max_number_of_factorials ;i++)
	{
		factorials[i] = factorials[i-1] * i;
	}
	max_number_of_factorials = _max_number_of_factorials + 1; 
}