word = input("Input \"stop\" to stop\nWhat word would you like to check? \n>")
reverse = word[::-1]

while (word != "stop"):

    if reverse == word:
        print ("This is a palindrome.")
    else:
        print ("This is not a palindrome.")

    word = input("Input \"stop\" to stop\nWhat word would you like to check? \n>")
    reverse = word[::-1]
