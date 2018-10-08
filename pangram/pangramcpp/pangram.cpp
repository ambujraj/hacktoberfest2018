// A pangram is a sentence or verse that contains all the letters of the alphabet.

#include <iostream>
#include <string>
#include "pangram.h"

using namespace std;

Pangram::Pangram() : userInput(""), alphabet("abcdefghijklmnopqrstuvwxyz ") { }

Pangram::Pangram(string userInput) : userInput(userInput), alphabet("abcdefghijklmnopqrstuvwxyz ") { }

bool Pangram::isPangram(string sentence)
{
	bool allLettersUsed = false;
	string temp = "";
	int k = 0;

	for(int i = 0; i < sentence.length();i++) {
		for(int j = 0; j < alphabet.length();j++){
			if(sentence[i]==alphabet[j]){
				cout << alphabet[j] << " is in sentence" << endl;
				temp[k] = alphabet[j];
				k++;
			}
		}
	}

	return allLettersUsed;
}

bool Pangram::isLetterInTemp(char letter){
	for(int i = 0; i < alphabet.length(); i++){
		
	}
}
 
int main() {

	string user;
	cout << "sentence to check: ";
	cin >> user;

	Pangram p(user);
	p.isPangram(user);

	return 0;
}