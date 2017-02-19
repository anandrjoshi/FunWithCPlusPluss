#ifndef NODE_H
# define NODE_H

#include <iostream>

using namespace std;


class Node
{
	unsigned int value;
	Node * node_A;
	Node * node_B;
	Node * node_C;
	Node * node_D;

public:

	Node();	
	~Node(); 

	unsigned int get_Value() {return value;}
	bool increase_Value() {return value++;}

	Node * get_Node_A() {return node_A;}
	Node * get_Node_B() {return node_B;}
	Node * get_Node_C() {return node_C;}
	Node * get_Node_D() {return node_D;}

	bool set_Node_A(Node * node);
	bool set_Node_B(Node * node);
	bool set_Node_C(Node * node);
	bool set_Node_D(Node * node);

};

#endif NODE_H