
#This is my favorite python algorithm
#because I am still very much a beginner
#and this was the very first algorithm
#I was able to figure out on my own without
#any searching through StackOverflow

def reverse(text):
    """Takes a string and returns the reverse"""
    
    rev_word = ""
    for char in text:
        rev_word = char + rev_word
        
    return rev_word

def is_palindrome(text):
    """checks to see if string is a palindrome"""
    
    return text == reverse(text)
    
print(is_palindrome('racecar'))