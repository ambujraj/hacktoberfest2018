#include <iostream>

// Function to calculate the next fibonacci number recursively
long unsigned int fibonacci(int n)
{
    if (n == 0) {
        return 0;
    } else if (n == 1) {
        return 1;
    } else {
        return fibonacci(n - 1) + fibonacci(n -2);
    }
}

int main()
{
    int fibonacciNumber;
    // We ask for which Fibonacci number the user is curious of
    std::cout << "Enter which Fibonacci number you want to know from the Fibonacci series: ";
    std::cin >> fibonacciNumber;
    // We check if the number is an integer or we write out an error message
    if (fibonacciNumber > 0) {
        std::cout << "The Fibonacci number which is on the given position (" << fibonacciNumber << ") is: " << fibonacci(fibonacciNumber) << std::endl;
    } else {
        std::cout << "You've either entered zero, a negative or a decimal number which isn't supported. Please re-run the program." << std::endl;
    }
    
    return 0;
}
