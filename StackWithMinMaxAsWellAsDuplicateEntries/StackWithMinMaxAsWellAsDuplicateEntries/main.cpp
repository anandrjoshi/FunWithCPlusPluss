#include "Stack.h"
#include <iostream>

using namespace std;

int main()
{
	Stack stack = Stack();
	stack.Push(4);
	stack.Push(2);
	stack.Push(1);
	stack.Push(4);
	stack.Push(1);
	//stack.Pop();

	cout << "************************************" << endl;
	cout << "Current min = " << stack.Get_Min() << endl;
	cout << "Current max = " << stack.Get_Max() << endl;
	cout << "Current stack count = " << stack.Get_Stack_Count() << endl;
	cout << "Current unique count = " << stack.Get_Unique_Count() << endl;
	cout << "************************************" << endl;

	stack.Pop();
	stack.Pop();
	stack.Pop();
	cout << "************************************" << endl;
	cout << "Current min = " << stack.Get_Min() << endl;
	cout << "Current max = " << stack.Get_Max() << endl;
	cout << "Current stack count = " << stack.Get_Stack_Count() << endl;
	cout << "Current unique count = " << stack.Get_Unique_Count() << endl;
	cout << "************************************" << endl;

	system("pause");

	return 1;
}