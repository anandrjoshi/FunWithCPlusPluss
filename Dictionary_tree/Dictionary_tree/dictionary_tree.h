#ifndef DICTIONARY_TREE_H
# define DICTIONARY_TREE_H

#include "Node.h"

class Dictionary_Tree
{
	Node * root;

private:
	bool validate_word(char * _word, unsigned int _word_length);

public:

	Dictionary_Tree();
	Dictionary_Tree(char * file_name);
	Dictionary_Tree(Dictionary_Tree * d_Tree); 

	~Dictionary_Tree();

	bool add_Word(char * _word, unsigned int _word_length);
	unsigned int find_Word(char * _word, unsigned int _word_length);


	bool write_To_File(char * _file_name);

};

#endif DICTIONARY_TREE_H