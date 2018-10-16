# @Title:   RomanArabicConverter
# @Version: 1.0
# @Author:  Paul F.
# @Date:    16-Oct-2018
# Summary:
#   Converts Roman Numerals to Arabic Numerals and vice versa
#   Works with passing an argument or in manual mode via log prompts
#   Goes up to 899 (DCCCXCIX)
#
# Changelog:
#   Date            Author          Description
#   15-Oct-2018     Paul F.         First version, still some minor bugs with edge cases
#   16-Oct-2018     Paul F.         Published version, fixed known buggy edge cases, cleaned code for readability
#


import sys

RomanValueDict = {
    'I': 1,
    'V': 5,
    'X': 10,
    'L': 50,
    'C': 100,
    'D': 500
}

#u = unus, q = quinque, d = decem 
RomanOnesTriplet = {'u': 'I', 'q': 'V', 'd': 'X'}
RomanTensTriplet = {'u': 'X', 'q': 'L', 'd': 'C'}
RomanHndsTriplet = {'u': 'C', 'q': 'D', 'd': 'M'}   #Should never have to use the 'M', though

RomanTripleTuple = (RomanOnesTriplet, RomanTensTriplet, RomanHndsTriplet)

manualMode = False

#Manual Mode Print function
#Basically, only print if in Manual Mode
def mmPrint(*objects):
    if manualMode:
        print(*objects)


maxValueArabic = 899

FinalResult = ""


#Main loop start

if (len(sys.argv) == 2):
    #input is argument 2
    inputValue = sys.argv[1]


if (len(sys.argv) == 1):
    #get input via console
    manualMode = True
    mmPrint("No argument detected. Entering manual mode. Please enter input numeral (Roman or Arabic).")
    inputValue = input("Value: ")
    

if (len(sys.argv) > 2):
    print("Error: Invalid number of arguments. Please input one Roman or Arabic numeral.")
    sys.exit()

mmPrint("You have input: ", inputValue)

containsRoman = False
containsArabic = False
isInvalid = False

parsedList = list(inputValue)
for character in parsedList:
    try:
        character = character.upper()
    except:
        x = 1
    try:
        character = int(character)
    except:
        x = 1
    if character in RomanValueDict:
        containsRoman = True
    elif isinstance(character, int):
        containsArabic = True
    else:
        isInvalid = True
        

if ((containsRoman and containsArabic) or isInvalid):
    print("Error: Input is not a Roman or Arabic numeral.")
    sys.exit()
    

if (containsRoman):
    mmPrint("Input is processed as a Roman numeral")
    RValue = inputValue.upper()
    Sum = 0
    for index in range(len(RValue)):
        letter = RValue[index]
        digitSign = 1
        iFollowingNumerals = (len(RValue) - index) - 1
        if iFollowingNumerals >= 1:         #At least one numeral following
            if RomanValueDict[letter] < RomanValueDict[RValue[index+1]]:    #IV, IX, IC, VX, etc.
                if RomanValueDict[letter] in (1, 10, 100):
                    if RomanValueDict[RValue[index+1]] in ((RomanValueDict[letter] * 5), (RomanValueDict[letter] * 10)):
                        if (iFollowingNumerals >=2 and RomanValueDict[letter] == RomanValueDict[RValue[index+2]]): #IVI, XCX, etc.
                            print("Error: Improperly formatted Roman Numeral: misplaced letters.")
                            sys.exit()
                        digitSign = -1          #Event of IV, IX, XL, XC, etc.
                else:
                    print("Error: Improperly formatted Roman Numeral: trailing greater number.")
                    sys.exit()
            if iFollowingNumerals >= 2:         #At least two numerals following
                if RomanValueDict[letter] == RomanValueDict[RValue[index+1]] and RomanValueDict[RValue[index+2]] in ((RomanValueDict[letter] * 5), (RomanValueDict[letter] * 10)):  #IIV, XXC, etc.
                    print("Error: Improperly formatted Roman Numeral: this program uses Subtractive Notation.")
                    sys.exit()
                if iFollowingNumerals >= 3:         #At least three numerals following
                    if RomanValueDict[letter] == RomanValueDict[RValue[index+1]] == RomanValueDict[RValue[index+2]] == RomanValueDict[RValue[index+3]]: #IIII, XXXX, etc.
                        print("Error: Improperly formatted Roman Numeral: over 3 successive matching numerals.")
                        sys.exit()
        #Input character is verified correct
        Sum += (digitSign * RomanValueDict[letter])
    FinalResult = Sum
    
    
if (containsArabic):
    mmPrint("Input is processed as an Arabic numeral")
    if int(inputValue) > maxValueArabic:
        print("Error: Input exceeds maximum value of ", maxValueArabic)
        sys.exit()
    for digit in range(len(parsedList)):
        DigitResult = ""
        column = (len(parsedList) - digit) - 1
        currentTriplet = RomanTripleTuple[column]
        digitValue = int(parsedList[digit])
        if digitValue%5 != 4:
            for i in range(digitValue%5):
                DigitResult += currentTriplet['u']                      #I, II, III, X, XX, (...), CCC
            if digitValue >= 5:
                DigitResult = currentTriplet['q'] + DigitResult         #V, VI, VII, (...), DCCC
        elif digitValue == 4:
            DigitResult += currentTriplet['u'] + currentTriplet['q']    #IV, XL, CD
        elif digitValue == 9:
            DigitResult += currentTriplet['u'] + currentTriplet['d']    #IX, XC
        FinalResult += DigitResult

print(FinalResult)


