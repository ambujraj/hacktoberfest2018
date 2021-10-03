

# finding factorial of a number
num = int(input(" Please enter any Number to find factorial : "))
fact = 1
i = 1

while(i <= num):
    fact = fact * i
    i = i + 1

print("The factorial of %d  = %d" %(num, fact))

