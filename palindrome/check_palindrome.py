"""
Author: Mayank Abhishek
"""
def isPalindrome(num):
    """
    This function checks whether a number is palindrome
    Returns - True if palindrome else false
    """
    if ( num == num[::-1]):
        return True
    return False


def main():
    input_num = list(str(input("Enter a number:")))
    if isPalindrome(input_num):
        print("Number is Palindrome")
    else:
        print("Number is not Palindrome")

if __name__ == '__main__':
    main()
