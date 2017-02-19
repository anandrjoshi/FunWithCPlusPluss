#ifndef NODE_H
# define NODE_H

#include <iostream>

using namespace std;


class Node
{
	unsigned int value;
	Node * next_node;
	
public:

	Node();	
	~Node(); 

	unsigned int get_Value() {return value;}
	bool set_value(unsigned int _number);

	Node * get_next_node() {return next_node;}

	bool set_next_node(Node * node);

};

#endif NODE_H