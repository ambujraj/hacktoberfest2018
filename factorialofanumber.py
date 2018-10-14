# Script to find the factorial of a natural number.
number = int(input('Enter a number to know your factorial: '))
factorial = number
initial_number = number
if number >= 0:
    if number == 0:
        print(f'The factorial of {initial_number} is 1.')
    else:
        while number > 1:
            factorial = factorial * (number - 1)
            number = number - 1
        print(f'The factorial of {initial_number} is {factorial}.')
else:
    print('You not entered a natural number, please try again!')
