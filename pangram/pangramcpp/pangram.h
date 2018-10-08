#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

class Pangram {
	private:
		string userInput;
		string alphabet;

	public:
		Pangram();
		Pangram(string userInput);
		bool isPangram(string sentence);
		bool isLetterInTemp(char let);
};