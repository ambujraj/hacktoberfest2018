#include <iostream>
#include <string>
#include <stack>

bool isPalindrome(std::string word)
{
    std::stack<char> temp;
    std::string reversed = "";
    for (char letter : word)
        temp.push(letter);
    
    while(!(temp.empty()))
    {
       reversed += temp.top();
       temp.pop();
    }

    if (reversed == word)
        return true;
    
    else return false;
}

int main()
{
    std::cout << "Enter a word!: ";
    std::string word;
    std::cin >> word;

    isPalindrome(word) ? std::cout << word << " is a palindrome!" : std::cout << word << " is not a palindrome!";
    std::cout << std::endl;
    
    return 0;
}