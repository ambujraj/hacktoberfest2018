#include <stdio.h>

long factorial(long n) {
    if (n == 0) return 1;
    return n * factorial(n - 1);
}

int main() {
    long num = 0;
    scanf("%li", &num);

    printf("%li\n", factorial(num));

    return 0;
}