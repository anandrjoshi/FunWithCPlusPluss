#include "Array.h"

Array::Array( Array &a)
{
	cout<<"Copy Constructor\n";
	array_size=a.array_size;
	value=new int[array_size];
	unsigned int i;
		for(i=0;i<array_size;i++)set_value(i,a.get_value(i));	

}


Array::Array( unsigned int _array_size)
{
	cout<<"Constructor\n";
		value = NULL;
		value=new int [_array_size];
		if(value==NULL)
		{
			cout<<"ERROR: Array::Array() value==NULL!"<<endl;
			array_size=0;
			return;
		}
		unsigned int i;
		for(i=0;i<_array_size;i++)
		{
			value[i]=0;
		}
		array_size = _array_size;
}

Array:: ~Array()
{	
	cout<<"Destructor\n";
	if(value!=NULL) delete [] value;
}

int Array::get_value(unsigned int _position)
{
	int _value=0;
	get_value(_position, _value);
	return _value;
}

bool Array:: get_value(unsigned int _position, int& _value)
{
	_value=0;
	if(_position>=array_size)
	{
		cout<<"ERROR: Array:: get_value()... _position>=array_size!"<<endl;
		return false;
	}
	_value=value[_position];
	return true;
}

bool Array:: set_value(unsigned int _position, int _value)
{
	if(_position>=array_size)
	{
		cout<<"ERROR: Array:: set_value()... _position>=array_size!"<<endl;
		return false;
	}
	value[_position]=_value;
	return true;
}
