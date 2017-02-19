#include "node.h"

//----------------------------------------------------
Node::Node()
{
	value = 1;
	node_A = NULL;
	node_B = NULL;
	node_C = NULL;
	node_D = NULL;
}

//----------------------------------------------------
Node::~Node()
{

	if(	node_A != NULL) delete node_A;
	if(	node_B != NULL) delete node_B;
	if(	node_C != NULL) delete node_C;
	if(	node_D != NULL) delete node_D;
}

bool Node::set_Node_A(Node * node)
{
	node_A = node;
	return true;
}

bool Node::set_Node_B(Node * node)
{
	node_B = node;
	return true;
}

bool Node::set_Node_C(Node * node)
{
	node_C = node;
	return true;
}

bool Node::set_Node_D(Node * node)
{
	node_D = node;
	return true;
}