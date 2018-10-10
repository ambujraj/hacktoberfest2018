string = input("Enter a String :")
reversed_string = reversed(string)
print(reversed_string)
if list(string) != list(reversed_string):
    print("Not a Palindrome")
else:
    print("It is a Palindrome")    

