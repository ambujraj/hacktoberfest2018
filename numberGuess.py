import random

number = random.randint(1, 10)
print ('='*10,'Number Guessing','='*10)
chances = int(input('How many chances do you want : '))

while (chances > 0) :
    guess = int(input('Guess the number : '))
    if (guess == number) :
        print ('Congratss you guess the right number')
        break
    elif (guess > number) :
        print ('Your guess is too high! try smaller numbert')
    elif (guess < number) :
        print ('Your guess is too low! try bigger number')
    
    chances -= 1

if (chances == 0) :
    print ('You lose the game!!')