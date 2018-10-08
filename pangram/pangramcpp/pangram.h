#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

class Pangram {
	private:
		string userInput;
		string alphabet;
		string temp;

	public:
		Pangram();
		Pangram(string userInput);
		bool isPangram(string sentence);
		bool isLetterInTemp(char let);
		bool isTempEqualToAlpha(string temp1);
		void printTemp(string temp2);
};