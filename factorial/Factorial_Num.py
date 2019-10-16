/*
created by: Keshav Gupta
7:27 PM
*/

# method to calculate factorial

def Factorial(number) :
  factorial_value = 1
  for i in range(1, number + 1) :
    factorial_value *= i
  print("factorial of ", number, " is ", factorial_value)
  
# function calling statements

print("Enter the number to find factorial : ")
number = int(input())
Factorial(number)
