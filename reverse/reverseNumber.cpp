#include <iostream>

int main()
{
    // Algorithm is for positive numbers only
    long unsigned int numberToReverse;
    std::cout << "Number to reverse is: ";
    std::cin >> numberToReverse;
    std::cout << "Reversed number is: ";
    // Classical reverse mode using while loop
    while(numberToReverse != 0) {
        std::cout << numberToReverse % 10;
        numberToReverse /= 10;
    }
    // In case someone runs it in Terminal on Linux
    // like I did, this is for readability reasons
    std::cout << std::endl;

    return 0;
}
