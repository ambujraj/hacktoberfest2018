// A pangram is a sentence or verse that contains all the letters of the alphabet.
#include <iostream>
#include <string>
#include "pangram.h"

using namespace std;

Pangram::Pangram() : userInput(""), alphabet("abcdefghijklmnopqrstuvwxyz"),
temp("") { }

Pangram::Pangram(string userInput) : userInput(userInput), alphabet("abcdefghijklmnopqrstuvwxyz"),
temp("") { }

bool Pangram::isPangram(string sentence){
	// bool allLettersUsed = false;
	int k = 0;

	for(int i = 0; i < sentence.length();i++) {
		for(int j = 0; j < alphabet.length();j++){
			if(sentence[i] == alphabet[j]){
				cout << sentence[i] << " is in sentence" << endl;
				// cout << "sentence.length(): " << sentence.length() << endl;
				if(!this->isLetterInTemp(sentence[i])){
					temp[k] = sentence[i];
					cout << "temp[" << k << "]: " << temp[k] << endl;
					k++;
				}
			}
		}
	}

	this->printTemp(temp);

	return this->isTempEqualToAlpha(temp);
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
	cout << "temp1: " << temp1 << endl;
	cout << "temp1.length(): " << temp1.length() << endl;
	if(temp1.length() != alphabet.length()){
		return false;
	}
	else{
		sort(string temp1, string temp1+temp1.length());

		for(int i = 0; i<temp1.length();i++){
			if(temp1[i]==alphabet[i]){
				return true;
			}
			else{
				return false;
			}
		}
	}
}

void Pangram::printTemp(string temp2){
	cout << "array: " << temp2 << endl;
	cout << "alphabet: " << alphabet << endl;
}

int main() {

	string user;
	cout << "sentence to check: ";
	cin >> user;

	Pangram p(user);

	if(p.isPangram(user)){
		cout << user << " is a Pangram!" << endl;
	}
	else{
		cout << user << " is not a Pangram!" << endl;
	}
	return 0;
}