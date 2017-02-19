#include <iostream>
#include <vector>
#include <fstream>
#include <string>

using namespace std;

int NumberOfTriangleWordsInLine(string line);
string ReadLineFromFile(char* filename);
int TriangleNumberForWord(char * word);
bool IsTriangleWord(int triangleValueOfWord);
char * StringToCharStar(string line);

int main()
{
	string line = ReadLineFromFile("words.txt");

	cout << "Number of Traingle words in given file = " << NumberOfTriangleWordsInLine(line) << endl;

	system("pause");
	return 0;
}

string ReadLineFromFile(char* filename)
{
	string line;
	ifstream myInFile;
	myInFile.open (filename, ofstream::out);
	if (myInFile.is_open())
	{
		getline(myInFile, line);
		myInFile.close();
	}

	return line;
}

int NumberOfTriangleWordsInLine(string line)
{
	char * word;
	char * toCharStar = new char[line.size() + 1];
	std::copy(line.begin(), line.end(), toCharStar);
	toCharStar[line.size()] = '\0';

	word = strtok(toCharStar,",");
	int numberOfTriangleWords = 0;
	while(word != NULL)
	{
		int triangleValueOfWord = TriangleNumberForWord(word);
		if(IsTriangleWord(triangleValueOfWord))
			numberOfTriangleWords ++;
		word = strtok(NULL, ",");
	}

	delete []toCharStar;
	return numberOfTriangleWords;
}

int TriangleNumberForWord(char * word)
{
	int triangleValue = 0;
	char *readPointer = word;
	while(*readPointer != '\0')
	{
		triangleValue += (int(*readPointer) - 64);
		readPointer++;
	}
	return triangleValue;
}

bool IsTriangleWord(int triangleValueOfWord)
{
	int a = 1;
	int b = 1;
	int c = (-2)*triangleValueOfWord;

	double BSquareMinus4AC = b*b - 4*a*c;
	double root1 = ((-1)*b + sqrt(BSquareMinus4AC))/(2*a);
	double root2 = ((-1)*b - sqrt(BSquareMinus4AC))/(2*a);

	return (!(abs(root1) - floor(abs(root1))) && !(abs(root2) - floor(abs(root2))));
}