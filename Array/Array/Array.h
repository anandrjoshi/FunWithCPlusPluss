#include<iostream>
using namespace std;

class Array
{
private: 
	int * value;
	unsigned int array_size;
public:
	Array( Array &a);
	Array( unsigned int _array_size);
	~Array();
	int  get_value(unsigned int _position);
	bool get_value(unsigned int _position, int & _value);
	bool set_value(unsigned int _position, int _value);

};