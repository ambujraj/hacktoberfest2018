// A pangram is a sentence or verse that contains all the letters of the alphabet.

// This program only works for sentences that don't have capital letters.
// test cases still needed

#include <iostream>
#include <string>
#include <algorithm>
#include <locale>
#include "pangram.h"

using namespace std;

Pangram::Pangram() : userInput(""), alphabet("abcdefghijklmnopqrstuvwxyz\0"),
temp("") { }

Pangram::Pangram(string userInput) : userInput(userInput), alphabet("abcdefghijklmnopqrstuvwxyz\0"),
temp("") { }

bool Pangram::isPangram(string sentence){
	int k = 0;

	// I tried to make it also work for capital letters
	// locale loc;

	// for(int l=0; l < sentence.length();l++){
		// cout << tolower(sentence[l],loc);
	// }

	// cout << "sentence: " << sentence << endl;

	for(int i = 0; i < sentence.length();++i) {
		if(sentence[i] == ' '){
				cout << "sentence[i]: " << sentence[i] << endl;
				i++;
		}	
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
	// cout << "temp1: " << temp1.length() << endl;
	// cout << "alphabet length :" << alphabet.length() << endl;
	sort(temp1.begin(), temp1.end());
	cout << "sorted: " << temp1 << endl; 
	
	if(temp1.length() != alphabet.length()){
		return false;
	}
	else{
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