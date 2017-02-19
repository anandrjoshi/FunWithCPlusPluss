#include <iostream>
#include "Array.h"

Array f(int x)
{
	cout<<"f ===(start)\n";
	
	Array b(10); 
	Array c(10); 

	cout<<"f ===(end)\n";

	if (x>1)return b;
	return c;
}


void main()
{
	int val = 3;
	char c;
	Array a = f(val);
	
	a.set_value(7,11);

	cout<<"a->get_value(7)="<<a.get_value(7)<<endl;

	cin>>c;

}