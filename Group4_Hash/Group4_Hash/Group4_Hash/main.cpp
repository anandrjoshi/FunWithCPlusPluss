
#include "Group4_Hash.h"

using namespace std;

#define TO_BE_POPULATED 0.25

int main()
{
	int number_of_elements;
	cout<<"Enter the number of elements you wish to store in the hash table:";
	cin>>number_of_elements;
	Group4_Hash new_hash_default = Group4_Hash(number_of_elements, TO_BE_POPULATED);	
	unsigned int choice;

	while(1)
	{
		cout<<"\n\nEnter your choice: \n"			
			<<"1. Add Value.\n"
			<<"2. Delete Value.\n"
			<<"0. Exit\n";
		cin>>choice;

		switch(choice)
		{
			case 0:
				cout<<"End of program!"<<endl;
				exit(0);
				break;
			case 1:
				cout<<"Enter the value you want to add: " << endl;
				int element_to_be_added;
				cin>>element_to_be_added;
				new_hash_default.addValue(element_to_be_added);
				break;
			case 2:
				cout<<"Enter the value you want to delete: ";
				int element_to_be_deleted;
				cin>>element_to_be_deleted;
				new_hash_default.deleteValue(element_to_be_deleted);
				break;		
			default:
				cout<<"Error: Wrong choice.";
				break;
		}
	}
	system("pause");
	return 0;
}