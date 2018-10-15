#Title:     RomanArabicConverter
#Author:    Paul F.
#Date:      15-Oct-2018
#Description:
#   Converts Roman Numerals to Arabic Numerals and vice versa
#   Works with passing an argument or via log prompts
#   Goes up to 899 (DCCCXCIX)
#Remaining Issues:
#   CCD returns 500 despite having invalid formatting
#       Likewise, XXC=>100, IIV=>5, IIIV=>6 etc.
#To-Do:
#   Sort out section for Roman>Arabic into "Before format is verified" and "After format is verified".


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
RomanHndsTriplet = {'u': 'C', 'q': 'D', 'd': 'M'}   #Should never use the 'M', though

#Not yet implemented
RomanTripleTuple = (RomanOnesTriplet, RomanTensTriplet, RomanHndsTriplet)

maxValueArabic = 899

FinalResult = ""

if (len(sys.argv) == 2):
    #input is argument 2
    inputValue = sys.argv[1]


if (len(sys.argv) == 1):
    #get input via console
    print("Error: No argument detected. Please enter input numeral (Roman or Arabic).")
    inputValue = input("Value: ")

if (len(sys.argv) > 2):
    print("Error: Invalid number of arguments. Please input one Roman or Arabic numeral.")
    sys.exit()

print("You have input: ", inputValue)

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
    print("Input is processed as a Roman numeral")
    RValue = inputValue.upper()
    Sum = 0
    for index in range(len(RValue)):
        letter = RValue[index]
        digitSign = 1
        iFollowingNumerals = (len(RValue) - index) - 1
        #print("iFollowingNumerals = ",iFollowingNumerals)
        if iFollowingNumerals >= 1:   #At least one numeral following
            if ((RomanValueDict[RValue[index+1]] == (RomanValueDict[letter] * 5)) or (RomanValueDict[RValue[index+1]] == RomanValueDict[letter] * 10)):
                digitSign = -1         #Event of IV, IX, XL, XC, etc.
                if iFollowingNumerals >= 2:
                    if RomanValueDict[RValue[index+1]] <= RomanValueDict[RValue[index+2]]:
                        print("Error: Improperly formatted Roman Numeral: improper numeral ordering type A.")
                        sys.exit()
            elif RomanValueDict[letter] < RomanValueDict[RValue[index+1]]:
                print("Error: Improperly formatted Roman Numeral: improper numeral ordering type B.")
                sys.exit()
            elif iFollowingNumerals >= 3: #At least three numerals following
                if RomanValueDict[letter] == RomanValueDict[RValue[index+1]] == RomanValueDict[RValue[index+2]] == RomanValueDict[RValue[index+3]]:
                    print("Error: Improperly formatted Roman Numeral: over 3 successive matching numerals.")
                    sys.exit()
        Sum += (digitSign * RomanValueDict[letter])
    FinalResult = Sum
    
if (containsArabic):
    print("Input is processed as an Arabic numeral")
    if int(inputValue) > maxValueArabic:
        print("Error: Input exceeds maximum value of ", maxValueArabic)
        sys.exit()
    for digit in range(len(parsedList)):
        DigitResult = ""
        column = len(parsedList) - digit
        if column == 3:     #In hundreds column
            currentTriplet = RomanHndsTriplet
        elif column == 2:   #In tens column
            currentTriplet = RomanTensTriplet
        else:               #In ones column
            currentTriplet = RomanOnesTriplet
        digitValue = int(parsedList[digit])
        if digitValue%5 != 4:
            for i in range(digitValue%5):
                DigitResult += currentTriplet['u']                      #I, II, III, X, XX, (...), CCC
            if digitValue >= 5:
                DigitResult = currentTriplet['q'] + DigitResult         #V, VI, VII...
        elif digitValue == 4:
            DigitResult += currentTriplet['u'] + currentTriplet['q']    #IV, XL, CD
        elif digitValue == 9:
            DigitResult += currentTriplet['u'] + currentTriplet['d']    #IX, XC
        FinalResult += DigitResult

print(FinalResult)


