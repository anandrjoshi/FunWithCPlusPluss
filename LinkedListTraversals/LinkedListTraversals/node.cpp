#include "node.h"

Node::Node()
{
	value = 0;
	next_node = NULL;
}

Node::~Node()
{
	if(	next_node != NULL) delete next_node;
}

bool Node::set_next_node(Node * node)
{
	next_node = node;
	return true;
}

bool Node::set_value(unsigned int _number)
{
	value = _number;
	return true;
}
