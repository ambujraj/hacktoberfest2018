## test palindrome for input text

# function which return reverse of a string 
def reverse(s): 
        return s[::-1] 

def isPalindrome(s):
    # Calling reverse function 
    rev = reverse(s) 
    # Checking if both string are equal or not 
    if (s == rev): 
        return True
    return False

# Driver code 
s = str(input("Please enter the text: \n"))
ans = isPalindrome(s.lower()) 

if ans == 1: 
    print("Yes, It's a PALINDROME") 
    
else: 
    `print("Not PALINDROME")
