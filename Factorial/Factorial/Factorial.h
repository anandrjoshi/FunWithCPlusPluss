#include <iostream>

using namespace std;

class Factorial
{
	private:
		double  * factorials;
		unsigned int max_number_of_factorials;

	private:
		bool set_factorial(unsigned int, double);
		void calculate_factorials(unsigned int);

	public:
		Factorial (unsigned int);
		~Factorial();
		double get_factorial(unsigned int);	
		unsigned int get_max_number_of_factorials();
		void resize_factorial_array(unsigned int);
};
