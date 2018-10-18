'''
DOCSTRING: THIS PROGRAM GENERATES THE FIBONACCI SEQUENCE
'''

#GENERATOR TO CREATE A FIBONACCI SEQUENCE
def gen_fibon(num):
    '''
    DOCSTRING: THIS IS A GENERATOR TO GENERATE FIBONACCI SEQUENCE
    '''

    first_number = 1
    second_number = 1

    for _ in range(num):
        yield first_number
        first_number, second_number = second_number, first_number + second_number



#EXCEPTION HANDLING
while True:
    try:
        #TAKING A USER'S INPUT
        USER_INPUT = int(input("Generate fibonacci sequence upto how many numbers? "))

        #OUTPUT LOGIC
        for number in gen_fibon(USER_INPUT):
            print(number)
    except ValueError:
        print("Please enter an integer. Try again!")
        continue
    else:
        break
