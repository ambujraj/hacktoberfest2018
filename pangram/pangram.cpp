#include <iostream>
using namespace std;

void isPangram() {
	int i;
	int count = 0;
	char str[27];
	cout << "Enter a string to check if its Pangram or not: ";

	cin >> str;

	short flagArr[26]; 
	memset(flagArr, 0, sizeof(flagArr));
	bool panGramFlag = true;

	for (int i = 0; i < 27; i++) {
		if (str[i] >= 'A' && str[i] <= 'Z') {
			flagArr[str[i] - 'A'] = 1;
		}
	}

	for (int i = 0; i < 26; i++) {
		if (flagArr[i] == 0) {
			panGramFlag = false;
			cout << "It is not Pangram" << endl;
			break;
		}
	}

	if (panGramFlag)
		cout << "it is Pangram" << endl;

}

int main() {

	isPangram();

	system("pause");
}
