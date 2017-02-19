#include <iostream>
#include"dictionary_tree.h"
#include "node.h"

using namespace std;

int main()
{
	Dictionary_Tree tree = Dictionary_Tree();

	tree.add_Word("ABCD", 4);
	tree.add_Word("ABCD", 4);
	tree.add_Word("P", 1);
	tree.add_Word("AAAA", 4);

	tree.find_Word("AAAA", 4);
	tree.find_Word("P", 1);
	tree.find_Word("ABCD", 4);

	system("pause");
	return 0;

}
