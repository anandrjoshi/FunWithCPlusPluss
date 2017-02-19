#include "dictionary_tree.h"
#include <iostream>

using namespace std;

//-----------------------------------------------------------

Dictionary_Tree::Dictionary_Tree()
{
	root=new Node();
}

//-----------------------------------------------------------

Dictionary_Tree::~Dictionary_Tree()
{
	if(root != NULL) delete root;
}
//-----------------------------------------------------------

bool Dictionary_Tree::add_Word(char * _word, unsigned int _word_length)
{
	unsigned int i;
	if (!validate_word(_word, _word_length))
		return false;

	Node * node_pointer = root;
	for(i=0; i<_word_length; i++)
	{
		if(_word[i] == 'A')
		{
			if(node_pointer->get_Node_A() == NULL)
			{
				node_pointer->set_Node_A(new Node());
				node_pointer = node_pointer->get_Node_A();
				continue;
			}
			node_pointer->get_Node_A()->increase_Value();
			node_pointer = node_pointer->get_Node_A();
			continue;
		}
	
		if(_word[i] == 'B')
		{
			if(node_pointer->get_Node_B() == NULL)
			{
				node_pointer->set_Node_B(new Node());
				node_pointer = node_pointer->get_Node_B();
				continue;
			}
			node_pointer->get_Node_B()->increase_Value();
			node_pointer = node_pointer->get_Node_B();
			continue;
		}

		if(_word[i] == 'C')
		{
			if(node_pointer->get_Node_C() == NULL)
			{
				node_pointer->set_Node_C(new Node());
				node_pointer = node_pointer->get_Node_C();
				continue;
			}
			node_pointer->get_Node_C()->increase_Value();
			node_pointer = node_pointer->get_Node_C();
			continue;
		}
	
		if(_word[i] == 'D')
		{
			if(node_pointer->get_Node_D() == NULL)
			{
				node_pointer->set_Node_D(new Node());
				node_pointer = node_pointer->get_Node_D();
				continue;
			}
			node_pointer->get_Node_D()->increase_Value();
			node_pointer = node_pointer->get_Node_D();
			continue;
		}	
	}

	cout << "SUCCESS::Dictionary_tree::add_word() word " << _word << " added successfully to the tree." << endl;
	return true;
}

bool Dictionary_Tree::validate_word(char * _word, unsigned int _word_length)
{
	if(_word_length == 0)
	{
		cout << "ERROR::Dictionary_Tree word sent cannot be empty. " << endl;
		return false;
	}
	unsigned int i;
	for(i=0; i<_word_length; i++)
	{
		if(_word[i] != 'A' && _word[i] != 'B' && _word[i] != 'C' && _word[i] != 'D')
		{
			cout << "ERROR::Dictionary_Tree:: word contains letter " <<_word[i] << ". Only letters A B C D are allowed. " << endl;
            return false;
		}
	}
	return true;
}

unsigned int Dictionary_Tree::find_Word(char *_word, unsigned int _word_length)
{
	if (!validate_word(_word, _word_length))
		return false;

	unsigned int number_of_times_word_exist = 0;
	Node * node_pointer = root;

	unsigned int i;
	for(i=0; i<_word_length; i++)
	{
		if(_word[i] == 'A')
		{
			if(node_pointer->get_Node_A() != NULL)
			{
				number_of_times_word_exist = node_pointer->get_Node_A()->get_Value();
				node_pointer = node_pointer->get_Node_A();
				continue;
			}
			else
			{
				cout << "Word does not exist in the tree." << endl;
				return 0;
			}
		}

		if(_word[i] == 'B')
		{
			if(node_pointer->get_Node_B() != NULL)
			{
				number_of_times_word_exist = node_pointer->get_Node_B()->get_Value();
				node_pointer = node_pointer->get_Node_B();
				continue;
			}
			else
			{
				cout << "Word does not exist in the tree." << endl;
				return 0;
			}
		}

		if(_word[i] == 'C')
		{
			if(node_pointer->get_Node_C() != NULL)
			{
				number_of_times_word_exist = node_pointer->get_Node_C()->get_Value();
				node_pointer = node_pointer->get_Node_C();
				continue;
			}
			else
			{
				cout << "Word does not exist in the tree." << endl;
				return 0;
			}
		}

		if(_word[i] == 'D')
		{
			if(node_pointer->get_Node_D() != NULL)
			{
				number_of_times_word_exist = node_pointer->get_Node_D()->get_Value();
				node_pointer = node_pointer->get_Node_D();
				continue;
			}
			else
			{
				cout << "Word does not exist in the tree." << endl;
				return 0;
			}
		}
	}

	cout << "Word found in the tree " << number_of_times_word_exist << " times." << endl;
	return number_of_times_word_exist;
}
