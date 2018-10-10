// Written by: Nikka Yalung
// Completed 10/09/2018

// A pangram is a sentence or verse that contains all the letters of the alphabet.

// test cases and proper comments still needed

#include <iostream>
#include <string>
#include <algorithm>
#include "pangram.h"

using namespace std;

Pangram::Pangram() : userInput(""), alphabet("abcdefghijklmnopqrstuvwxyz\0"),
temp("") { }

Pangram::Pangram(string userInput) : userInput(userInput), alphabet("abcdefghijklmnopqrstuvwxyz\0"),
temp("") { }

bool Pangram::isPangram(string sentence){
	int k = 0;

	//changes the sentence to lower case
	transform(sentence.begin(), sentence.end(), sentence.begin(), ::tolower);


	for(int i = 0; i < sentence.length();++i) {
		for(int j = 0; j < alphabet.length();j++){
			if(sentence[i] == alphabet[j]){
				if(!this->isLetterInTemp(sentence[i])){
					temp[k] = sentence[i];
					k++;
				}
			}
		}
	}

	//this->printTemp(temp);

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
	
	if(temp1.length() != alphabet.length()){
		return false;
	}
	else{
		sort(temp1.begin(), temp1.end());
		
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
	getline(cin, user);

	Pangram p(user);

	if(p.isPangram(user)){
		cout << user << " is a Pangram!" << endl;
	}
	else{
		cout << user << " is not a Pangram!" << endl;
	}
	return 0;
}