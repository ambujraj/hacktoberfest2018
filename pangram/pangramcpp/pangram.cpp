// A pangram is a sentence or verse that contains all the letters of the alphabet.
#include <iostream>
#include <string>
#include "pangram.h"

using namespace std;

Pangram::Pangram() : userInput(""), alphabet("abcdefghijklmnopqrstuvwxyz "),
temp("") { }

Pangram::Pangram(string userInput) : userInput(userInput), alphabet("abcdefghijklmnopqrstuvwxyz "),
temp("") { }

bool Pangram::isPangram(string sentence){
	bool allLettersUsed = false;
	int k = 0;

	for(int i = 0; i < sentence.length();i++) {
		for(int j = 0; j < alphabet.length();j++){
			if(sentence[i] == alphabet[j]){
				cout << sentence[i] << " is in sentence" << endl;
				if(this->isLetterInTemp(sentence[i]) == false){
					temp[k] = sentence[i];
					k++;
				}
			}
		}
	}

	this->printTemp(temp);

	allLettersUsed = this->isTempEqualToAlpha(temp);

	return allLettersUsed;
}

// checks if the letter is already in the temp character array
bool Pangram::isLetterInTemp(char letter){
	for(int i = 0; i < alphabet.length(); i++){
		if (temp[i] == letter){
			return true;
		}
	}
	return false;
}
 
bool Pangram::isTempEqualToAlpha(string temp1){
	bool idk = false;

	for(int i = 0; i<temp.length();i++){
		for(int j = 0; j < alphabet.length();j++){
			if(temp[i] == alphabet[j]){
				idk = true;
			}
			else{
				idk = false;
				goto endloop;
			}
		}
	}

endloop:
	if(idk){
		return true;
	}
	else {
		return false;
	}

}

void Pangram::printTemp(string temp2){
	cout << "temp array: ";
	for(int i = 0; i < temp2.length(); i++){
		cout << temp2[i];
	}
}

int main() {

	string user;
	cout << "sentence to check: ";
	cin >> user;

	Pangram p(user);

	if(p.isPangram(user) == true){
		cout << user << " is a Pangram!" << endl;
	}
	else{
		cout << user << " is not a Pangram!" << endl;
	}
	return 0;
}