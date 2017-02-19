/*------------------------------------------------------------------------
The Node class represents a single node of a trie.
Each Node object will have a character and a bool value associated with it.
This bool value indicates if that node forms the end of any word on the 
trie. Each node also contain a vector of child nodes.
Apart from the usual get set methods the class contains FindCharacter() 
and AddChild(). FindCharacter() checks if the children node contain a 
particular character. AddChild() addes a node as a child to the vector.
--------------------------------------------------------------------------*/

#include<vector>
using namespace std;

class Node
{
	char character;
	bool word_end;
	vector<Node*> children;

public:
	Node();
	~Node(){};

	void SetCharacter(char _char){character = _char;}
	char GetCharacter(){return character;}
	bool IsWordEnd(){return word_end;}
	void SetWordEnd(bool _value){word_end = _value;};
	vector<Node*> GetChildren(){return children;};
	void AddChild(Node * node){children.push_back(node);};

	Node * FindCharacter(char _chr);
	
};