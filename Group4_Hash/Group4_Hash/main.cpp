
#include "Group4_Hash.h"

using namespace std;

#define TO_BE_POPULATED 0.25

int main()
{
	int number_of_elements;
	cout<<"\t\tGroup 4 Hash Implementation: \n\n" << endl; 
	cout<<"Enter the number of elements you wish to store in the hash: " << endl;
	while (!(std::cin>> number_of_elements)) 
	{
		std::cerr<<"An integer is expected... Please try again: ";
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}
	Group4_Hash hash_object = Group4_Hash(number_of_elements, TO_BE_POPULATED);	
	unsigned int choice;

	system("cls");

	while(1)
	{
		cout<<"\n\n\t\tGroup 4 Hash Implementation: \n\n"			
			<<"1. Add Value.\n"
			<<"2. Delete Value.\n"
			<<"3. Find Value.\n"
			<<"4. Read from file.\n"
			<<"5. Write to file.\n"
			<<"6. View Entire Hash. \n"
			<<"0. Exit\n\n";
		cout << "Enter your choice: " << endl;
		while (!(std::cin>> choice)) 
		{
			std::cerr<<"An integer is expected... Please try again: ";
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}

		switch(choice)
		{
			case 0:
				exit(0);
				break;

			case 1:
				system("cls");
				cout<<"Enter the value you want to add: " << endl;
				int element_to_be_added;
				while (!(std::cin>> element_to_be_added)) 
				{
					std::cerr<<"An integer is expected... Please try again: ";
					std::cin.clear();
					std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				}
	
				hash_object.addValue(element_to_be_added);
				break;

			case 2:
				system("cls");
				cout<<"Enter the value you want to delete: ";
				int element_to_be_deleted;
				while (!(std::cin>>element_to_be_deleted)) 
				{
					std::cerr<<"An integer is expected... Please try again: ";
					std::cin.clear();
					std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				}

				hash_object.deleteValue(element_to_be_deleted);
				break;

			case 3:
				system("cls");
				cout<<"Enter the value you want to be found: ";
				int element_to_be_found;
				while (!(std::cin>>element_to_be_found)) 
				{
					std::cerr<<"An integer is expected... Please try again: ";
					std::cin.clear();
					std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				}

				hash_object.findValue(element_to_be_found);
				break;

			case 4:
				system("cls");
				hash_object.readFromFile();
				break;

			case 5:
				system("cls");
				hash_object.writeToFile();
				break;
			
			case 6:
				system("cls");
				hash_object.viewAllContents();
				break;

			default:
				system("cls");
				cout<<"Error: Wrong choice.";
				break;
		}
	}
	system("pause");
	return 0;
}