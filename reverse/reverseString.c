#include <stdio.h>
#include <string.h>

/* Reverses the given string in place */
void reverse(char str[]) {
	int front = 0;
	int back = strlen(str) - 1;

	char t;

	while(front < back) {
		t = str[front];
		str[front] = str[back];
		str[back] = t;
		front++;
		back--;
	}
}


int main() {
	char str[] = "Programming is fun!";
	printf("%s\n", str);
	reverse(str);
	printf("%s\n", str);

	return 0;
}
