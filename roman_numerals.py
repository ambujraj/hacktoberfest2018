# -*- coding: utf-8 -*-

lettersDict = {'I': 1, 'V': 5, 'X': 10, 'L': 50, 'C': 100, 'D': 500, 'M': 1000}
roman = list(input('Enter a roman numeral: ').upper())
valid = 1

for letter in roman:
    if letter not in lettersDict:
        valid = 0
        print('Not a valid roman numeral.')
        break
    
if valid == 1:
    result = 0
    previous_letter = 'M'
    for letter in roman:
        current_letter = roman[roman.index(letter)]
        if list(lettersDict.keys()).index(current_letter) > list(lettersDict.keys()).index(previous_letter):
            number = lettersDict.get(current_letter)
            result =- lettersDict.get(previous_letter)
            number = lettersDict.get(current_letter) - lettersDict.get(previous_letter)
            result =+ number
        else:
            number = lettersDict.get(current_letter)
            result += number
        previous_letter = current_letter
    print(result)