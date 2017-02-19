#include "stack.h"
#include <iostream>

using namespace std;

Stack_OOAD::Stack_OOAD()
{
	// We are assuming that 0 determines the position is empty...
	for(unsigned int i = 0; i <DEFAULT_STACK_SIZE; i++)
		values[i] = 0;

	number_of_elements_present = 0;
}

bool Stack_OOAD::add_to_stack(int _value)
{
	if(number_of_elements_present >= DEFAULT_STACK_SIZE)
	{
		cout << "ERROR::Stack_OOAD::add_to_stack() stack is full cannot add any further elements." << endl;
		return false;
	}

	if(_value == 0)
	{
		cout << "ERROR::Stack_OOAD::add_to_stack() cannot add 0 to the stack." << endl;
		return false;
	}
	values[number_of_elements_present] = _value;
	number_of_elements_present ++;

	cout << "SUCCESS::Stack_OOAD::add_to_stack() value " << _value << " added to stack successfully!!!" << endl;
	return true;
}

bool Stack_OOAD::delete_from_stack()
{
	if(number_of_elements_present == 0)
	{
		cout << "ERROR::Stack_OOAD::delete_from_stack() stack is empty cannot delete any further elements." << endl;
		return false;
	}

	int _value = values[number_of_elements_present - 1];
	values[number_of_elements_present - 1] = 0;
	number_of_elements_present --;

	cout << "SUCCESS::Stack_OOAD::delete_from_stack() value " << _value << " removed from stack successfully!!!" << endl;
	return true;
}
