#include "Factorial.h"

using namespace std;

int main()
{
	char _do_you_want_to_continue = 'y';
	Factorial _factorials(10);

	if(_factorials.get_max_number_of_factorials() < 0 )
	{
		cout << "unable to create factorial. program will now exit..." << endl;
		exit(0);
	}
	else
	{
		while(_do_you_want_to_continue == 'y' || _do_you_want_to_continue == 'Y')
		{
			cout << "Which number's factorial would you like to find?"<< endl;
			unsigned int _number_of_factorials;
			float _ignore_decimal_of_float;
			while (!(std::cin>> _ignore_decimal_of_float)) 
			{
				std::cerr<<"An integer is expected... Please try again: ";
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			}

			//typecast to ignore the decimal point of the float to get an unsigned int
			_number_of_factorials = (unsigned int) _ignore_decimal_of_float; 

			if (_number_of_factorials >=0 && _number_of_factorials<=170)
			{
				double _value_of_factorial;
				if(_factorials.get_max_number_of_factorials()-1 < _number_of_factorials)
				{
					_factorials.resize_factorial_array(_number_of_factorials);
					_value_of_factorial = _factorials.get_factorial(_number_of_factorials);
					if (_value_of_factorial >= 0)
						cout << "Factorial of "<< _number_of_factorials << " is " << _value_of_factorial << endl;
				}
				else
				{
					_value_of_factorial = _factorials.get_factorial(_number_of_factorials);
					if (_value_of_factorial >= 0)
						cout << "Factorial of "<< _number_of_factorials << " is " << _value_of_factorial << endl;
				}
			}
			else
				cout << "ERROR: Entered number must be greater than or equal to 0 or less than 171." << endl;

			cout << "Press y/Y to continue..." << endl;
			cin >> _do_you_want_to_continue;
		}
	}
	return 1;
}
