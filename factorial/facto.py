def factorial(a):
    if(a==0):
        return 1
    else:
        return a*factorial(a-1)

num = input("Enter the number: ")
try:
   val = int(num)
except ValueError:
   print("Please input an integer!")

print("Factorial of",val,"is",factorial(val))