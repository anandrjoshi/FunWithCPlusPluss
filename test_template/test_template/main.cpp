#include <iostream>

using namespace std;

template<class data_type_1, class data_type_2>
double f(data_type_1 x, data_type_2 y)
{
	cout << x << endl;
	cout << y << endl;
	return x*y;
}

void main()
{
	double a = 4.1, b = 2.2;
	double w = f<int, int>(a,b);
	cout << w << endl;
	cout << "-----------------------------------"<< endl;
	w = f<int, double>(a,b);
	cout << w << endl;
	cout << "-----------------------------------"<< endl;
	w = f<double, double>(a,b);
	cout << w << endl;
	cout << "-----------------------------------"<< endl;
	w = f<double, int>(a,b);
	cout << w << endl;
	cout << "-----------------------------------"<< endl;
	char x;
	cin >> x;
}