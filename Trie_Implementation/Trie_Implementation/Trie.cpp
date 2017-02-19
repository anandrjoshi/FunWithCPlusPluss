#include"Trie.h"
#include<iostream>

using namespace std;

Trie::Trie()
{
	root = new Node();
}

Trie::~Trie()
{
	if(root!=NULL) delete root;
}

//This function is used to add a word on to the trie. In this we iterate through the
//entire word and move down the trie until we have reached the end of common prefix
//between trie as well as word. Once this is reached the remainder of the word is 
//added as new nodes.
void Trie::AddWord(string _str)
{
	if(_str.length() == 0)
	{
		cout << "ERROR::AddWord(string str) Cannot add word of length 0." << endl;
		return;
	}

	Node * current_node = root;

	for(int i = 0; i < _str.length(); i++)
	{
		Node * current_child = current_node->FindCharacter(_str[i]);
		if ( current_child != NULL )
        {
            current_node = current_child;
        }
        else
        {
            Node * temp = new Node();
            temp->SetCharacter(_str[i]);
            current_node->AddChild(temp);
            current_node = temp;
        }
		if(i == _str.length() - 1)
			current_node->SetWordEnd(true);
	}
}

//This function is used to search for a word on a trie.
//Given a word we iterate through it and at the same time move down the
//trie. if we find the word we return true else we return false.
bool Trie::SearchWord(string _str)
{
	Node* current_node = root;

    while (current_node != NULL)
    {
        for ( int i = 0; i < _str.length(); i++ )
        {
            Node* temp = current_node->FindCharacter(_str[i]);
            if ( temp == NULL )
                return false;
            current_node = temp;
        }
		return current_node->IsWordEnd();
    }
}

//This function checks for prefix words already present on the trie and 
//that are also part of the given word. If we find a word that is completely
//made of substrings that are already present on the trie, then it returns the 
//length of the word. Else it returns 0. 
int Trie::LengthOfWordAsCombination(string _str)
{
	Node* current_node = root;

    while (current_node != NULL)
    {
		Node* temp = NULL;
        for ( int i = 0; i < _str.length(); i++ )
        {
            temp = current_node->FindCharacter(_str[i]);

			if(temp != NULL)
				current_node = temp;

			else
			{
				if(current_node->IsWordEnd())
				{
					current_node = root;
					i--;
					continue;
				}
				else
					return 0;
			}
        }
		if(temp->IsWordEnd())
			return _str.length();
		else
			return 0;
    }
}