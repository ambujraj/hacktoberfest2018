'''
If we list all the natural numbers below 10 that are multiples of 3 or 5, we get 3, 5, 6 and 9. The sum of these multiples is 23.
Find the sum of all the multiples of 3 or 5 below 1000.
'''

n = 1000
numbers = []
soln = 0

for i in range(n):
  if i%3 == 0:
    if i%5 != 0:
      soln += i
  elif i%5 == 0:
    if i%3 != 0:
      soln += i
      
      
print(f"the sum of all the multiples of 3 or 5 below 1000 is {soln}")
