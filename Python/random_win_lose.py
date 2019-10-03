from random import randint

def winOrLose(wanted):
    dice_throw =  randint(1,6)
    print('you got the number',dice_throw)
    if(wanted=='even'):
        if(dice_throw%2==0):
            print('You win in the random dice throw')
        else:
            print('you lose in the randome dice throw')
    else:
        if(dice_throw%2==1):
            print('you win in this random dice throw')
        else:
            print('you lose in this random dice throw')

wanted = input('enter "odd" or "even" as a string: ')
winOrLose(wanted)