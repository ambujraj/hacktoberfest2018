# factorial function
def factorial(n):
  # break condition for recursion
  if n==1 or n==0:
    return 1
  else:
    return n*factorial(n-1)

num = int(input())
fact = factorial(num)
print('Factorial of {0} is {1}'.format(num,fact))
