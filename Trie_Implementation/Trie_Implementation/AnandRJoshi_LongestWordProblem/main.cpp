#include<iostream>
#include"Trie.h"
#include<conio.h>
#include<fstream>
#include<string>

using namespace std;

int main()
{
	Trie trie;
	ifstream myInFile;
	//file to be read
	myInFile.open ("words for problem.txt", ofstream::out);

	string longest_word = "";
	string second_longest_word = "";

	//iterate through the file and for each word, check for LengthOfWordAsCombination().
	//Also keep track of longest and second longest words. Then add each word on the trie.
	while(!myInFile.eof())
	{
		string word;
		getline(myInFile, word);
		int length = trie.LengthOfWordAsCombination(word);

		if(longest_word.length()<length)
			longest_word = word;
		if(second_longest_word.length()<length && longest_word != word)
			second_longest_word = word;

		trie.AddWord(word);
	}
	myInFile.close();

	//Display the longest and second longest word that is made of substrings 
	//already on the trie.
	cout << "Longest word: " << longest_word << endl;
	cout << "Second Longest word: " << second_longest_word << endl;

	getch();
}
