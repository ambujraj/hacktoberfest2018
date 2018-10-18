# Script to find the factorial of a natural number.
number = int(input('Enter a number to know your factorial: ')) 
factorial = number
initial_number = number
if number >= 0:
    # Check for number=0 case
    if number == 0:
        print(f'The factorial of {initial_number} is 1.')
    # For all other cases
    else:
        # Loop to calculate factorial
        while number > 1:
            factorial = factorial * (number - 1)
            number = number - 1
        print(f'The factorial of {initial_number} is {factorial}.')
else:
    print('You did not enter a natural number, please try again!')
