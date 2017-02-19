#include"stack.h"
#include<iostream>

using namespace std;

int main()
{
	Stack_OOAD stack;
	cout << "\t\tStack Operations" << endl;
	cout << "\t1. Add Value to Stack" << endl;
	cout << "\t2. Delete Value from Stack" << endl;
	cout << "\t3. Delete Stack" << endl;
	cout << "\t0. Exit" << endl;

	while (true)
	{
		cout << "\nEnter your choice: "<< endl;
		int choice;
		cin >> choice;

		switch(choice)
		{
			case 0:
			{
				cout << "Program will now exit... " << endl;
				system("pause");
				exit(0);
			}

			case 1:
			{
				cout << "Enter the value you want to add to stack: "<< endl;
				int value_to_be_entered;
				cin >> value_to_be_entered;

				stack.add_to_stack(value_to_be_entered);
				cout << "number of elements = " << stack.get_number_of_elements_present() << endl;
				break;
			}

			case 2:
			{
				cout << "number of elements = " << stack.get_number_of_elements_present() << endl;
				stack.delete_from_stack();
				break;
			}

			case 3:
			{
				cout << "Warning:: Do you really want to delete the stack. (Yy/Nn)" << endl;
				char reply;
				cin >> reply;
				if (reply == 'Y' || reply == 'y')
				{
					cout << "Deleting Stack... Program will now exit" << endl;
					system("pause");
					exit(0);
				}

				break;
			}

			default:
			{
				cout << "Wrong choice..."<< endl;
				break;
			}
		}
	}
	return true;
}