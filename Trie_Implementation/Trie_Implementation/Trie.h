/*------------------------------------------------------------------------
The Trie class actually represents a Trie. A trie is collection of nodes
such that each word forms branches of trie. A trie has a root node and all
the other nodes are connected to this root. Major advantage of Trie is that
search cost doesnot depend on number of elements but depends on the depth 
of the trie. It aslo saves space as two words with same prefixes use only 
prefix resulting in saving of space.
AddWord() add the word on to the trie.
LengthOfWordAsCombination() determines the length of the word based on 
prefixes already on the trie.
SearchWord() searches for a word on the trie.
--------------------------------------------------------------------------*/

#include"Node.h"

using namespace std;

class Trie
{
	Node * root;

public:
	Trie();
	~Trie();

	void AddWord(string _str);
	bool SearchWord(string _str);
	int LengthOfWordAsCombination(string _str);
};