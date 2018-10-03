#include <iostream>
#include <string>

unsigned int length(std::string word) // this is passed by value each time
{
    if (word == "") // this checks when string is reduced to nothing
        return 0;

    else return 1 + length(word.substr(0, word.size() - 1)); // recursive case
}

int main()
{
    std::string word;
    std::cout << "Enter a string: ";
    getline(std::cin, word);
    std::cout << "Your string has a length of " << length(word) << std::endl;
}