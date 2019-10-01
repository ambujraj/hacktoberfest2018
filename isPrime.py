
# Python program to display all the prime numbers within an interval

# change the values of lower and upper for a different result
lower = 900
upper = 1000

# uncomment the following lines to take input from the user
#lower = int(input("Enter lower range: "))
#upper = int(input("Enter upper range: "))

print(f"Prime numbers between {lower} and {upper} are:")

for num in range(lower,upper + 1):
   # prime numbers are greater than 1
   if num > 1:
       # divide by every number between 2 and half of the subject number (num)
       for i in range(2,num // 2): # you only need to check to half of the subject number (num)
           # is it evenly divisible by a number?
           if (num % i) == 0:
               break
       else:
           # print if it is prime
           print(num)
