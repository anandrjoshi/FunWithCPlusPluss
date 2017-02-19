#ifndef LINKED_LIST_H
# define LINKED_LIST_H

#include "Node.h"

class Linked_List
{
	Node * root;

public:

	Linked_List(); 

	~Linked_List();

	bool add_number(unsigned int _number);
	bool find_number(unsigned int _number);
	bool delete_number(unsigned int _number);
	void view_all();

	void reverse();
};

#endif LINKED_LIST_H