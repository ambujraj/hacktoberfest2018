#include <stdio.h>

int pangram(const char *str) {
	unsigned int alphabet = 0;
	while (*str) {
		if ((*str >= 'A' && *str <= 'Z') || (*str >= 'a' && *str <= 'z')) {
			alphabet |= 1 << ((*str & 0x1F) - 1);
		}
		if ((alphabet ^ 0x3FFFFFF) == 0) {
			return 1;
		}
		str++;
	}
	return 0;
}

int main(int argc, char **argv) {
	if (argc != 2) {
		printf("Usage: %s string\n", argv[0]);
		return 1;
	}
	if (pangram(argv[1])) {
		printf("\"%s\" is a pangram\n", argv[1]);
	}
	else {
		printf("\"%s\" is not a pangram\n", argv[1]);
	}
}