#include "linked_list.h"
#include <iostream>


using namespace std;

Linked_List::Linked_List()
{
	root=new Node();
}

Linked_List::~Linked_List()
{
	if(root != NULL) delete root;
}

bool Linked_List::add_number(unsigned int _number)
{
	if (_number <= 0)
	{
		cout << "ERROR::Linked_List::add_number Linked List cannot contain values less than or equal to ZERO." << endl;
		return false;
	}

	Node * current_node = root;

	while(true)
	{
		if(current_node->get_next_node() == NULL)
		{
			Node * new_node = new Node();
			new_node->set_value(_number);
			current_node->set_next_node(new_node);
			cout << "SUCCESS::Linked_List::add_number number " << _number << " added successfully to the linked list. " << endl;
			return true;
		}

		if(current_node->get_Value() < _number)
		{
			if(current_node->get_next_node()->get_Value() < _number)
			{
				current_node = current_node->get_next_node();
				continue;
			}

			else
			{
				Node * new_node = new Node();
				new_node->set_value(_number);
				new_node->set_next_node(current_node->get_next_node());
				current_node->set_next_node(new_node);
				cout << "SUCCESS::Linked_List::add_number number " << _number << " added successfully to the linked list. " << endl;
				return true;
			}
		}
	}
}

void Linked_List::view_all()
{
	Node * current_node = root;

	cout << "Values in the list are:" << endl;
	while(true)
	{
		cout << current_node->get_Value() << endl;
		current_node = current_node->get_next_node();

		if(current_node == NULL)
			return;
	}
}

bool Linked_List::find_number(unsigned int _number)
{
	if (_number <= 0)
	{
		cout << "ERROR::Linked_List::find_number Linked List cannot contain values less than or equal to ZERO." << endl;
		return false;
	}

	Node * current_node = root;

	while(current_node != NULL)
	{
		if(current_node->get_Value() == _number)
		{
			cout << "SUCCESS::Lisnked_List::find_numbers found value " << _number << " in the linked list " << endl;
			return true;
		}
		else
			current_node = current_node->get_next_node();
	}

	cout << "FAILURE::Lisnked_List::find_numbers value " << _number << " is not present in the linked list " << endl;
	return false;
}

bool Linked_List::delete_number(unsigned int _number)
{
	if (_number <= 0)
	{
		cout << "ERROR::Linked_List::delete_number Linked List cannot contain values less than or equal to ZERO." << endl;
		return false;
	}

	Node * current_node = root;
	Node * previous_node = root;

	while(current_node != NULL)
	{
		if(current_node->get_Value() == _number)
		{
			previous_node->set_next_node(current_node->get_next_node());
			current_node = NULL;
			delete current_node;
			cout << "SUCCESS::Lisnked_List::delete_numbers value " << _number << " deleted from the linked list. " << endl;
			return true;
		}
		else
		{
			previous_node = current_node;
			current_node = current_node->get_next_node();
		}
	}

	cout << "FAILURE::Lisnked_List::delete_numbers value " << _number << " is not present in the linked list " << endl;
	return false;
}

void Linked_List::reverse()
{
	Node * current_node = root;
	Node * temp = new Node();
	Node * previous_node = root;

	while(current_node != NULL)
	{
		temp = current_node->get_next_node();
		current_node->set_next_node(previous_node);
		previous_node = current_node;
		current_node = temp;
	}

	root->set_next_node(NULL);
	root = previous_node;
}
