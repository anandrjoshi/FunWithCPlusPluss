#include <iostream>

using namespace std;

void f(int *&b);
int main()
{
	int a[10];
	a[0] = 5;
	int *b =a;
	f(b);
	cout << a[0]<< endl;
	char c;
	cin >> c;
// all variables of the main function are allocated on the stack.
	return 1;
}


void f(int *&b)
{
	int a[10];
	b=a;
	b[0]=10;
}
