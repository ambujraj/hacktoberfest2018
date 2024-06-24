# Python program to check if two strings are anagram or not

str1 = input('Enter 1st string: ')
str2 = input('\nEnter 2nd string: ')

s1 = sorted(str1)
s2 = sorted(str2)

if s1 == s2:
    print('\nThe two strings are anagram')
else:
    print('\nThe two strings are not anagram')
