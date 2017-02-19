#include "linked_list.h"
#include <iostream>

using namespace std;

int main()
{
	
	Linked_List list = Linked_List();	

	system("cls");

	while (true)
	{
		cout << "\n\n\t\tList Operations" << endl;
		cout << "\t1. Add Value to List" << endl;
		cout << "\t2. Delete Value from List" << endl;
		cout << "\t3. Find Value in List" << endl;
		cout << "\t4. Reverse List" << endl;
		//cout << "\t5. Write to File" << endl;
		cout << "\t0. Exit" << endl;

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
				system("cls");
				cout << "Enter the value you want to add to the list: "<< endl;
				int value_to_be_entered;
				cin >> value_to_be_entered;

				list.add_number(value_to_be_entered);
				break;
			}

			case 2:
			{
				system("cls");
				cout << "Enter the value you want to delete from the list: "<< endl;
				int value_to_be_entered;
				cin >> value_to_be_entered;

				list.delete_number(value_to_be_entered);
				break;
			}

			case 3:
			{
				system("cls");
				cout << "Enter the value you want to search in the list: "<< endl;
				int value_to_be_entered;
				cin >> value_to_be_entered;

				list.find_number(value_to_be_entered);
				break;
			}

			case 4:
			{
				system("cls");
				list.reverse();
				list.view_all();
				break;
			}

		/*	case 5:
			{
				system("cls");
				list.writeToFile();
				break;
			}*/

			default:
			{
				system("cls");
				cout << "Wrong choice..."<< endl;
				break;
			}
		}
	}
	return true;
}