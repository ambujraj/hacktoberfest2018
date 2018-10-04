// Compile: gcc fibonacci.c -o <name>
// Usage: ./<name> <number>

#include <stdio.h>
#include <stdlib.h>

int fibonacci_iterative(int n){
     int number;
     for (int i = 0; i < n; i++) {
          if (!(i == 0 || i == 1)) {
               number = ((i-1) + (i-2));
          } else {
               number = 1;
          }
     }
     return number;
}

int fibonacci_recursive(int n){
     if (n == 1 || n == 2){
          return 1;
     }
     return fibonacci_recursive(n-1) + fibonacci_recursive(n-2);
}

int main(int argc, char const *argv[]) {
     int iterative = fibonacci_iterative(atoi(argv[1]));
     int recursive = fibonacci_recursive(atoi(argv[1]));
     printf("Iterative: %d\n", iterative);
     printf("Recursive: %d\n", recursive);
     return 0;
}
