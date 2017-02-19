#include"Node.h"

Node::Node()
{
	character = ' ';
	word_end = false;
}

//This function takes in a character and iterates through the child nodes
//and checks of the character is part of the children vector. If so then
//it returns the node. Else returns NULL indicating that the character is 
//not part of the child nodes.
Node * Node::FindCharacter(char _chr)
{
	for ( int i = 0; i < children.size(); i++ )
    {
        Node* temp = children.at(i);
		if ( temp->GetCharacter() == _chr )
        {
            return temp;
        }
    }
    return NULL;
}
