# Classic beginner puzzle - in 9 lines and 1

for i in range(1, 25):
  if i%3 == 0 and i%5 == 0:
    print("Fizzbuzz")
  elif i%3 == 0:
    print("Fizz")
  elif i%5 == 0:
    print("Buzz")
  else:
    print(i)

print("\n".join(["Fizzbuzz" if (not i%3 and not i%5) else "Fizz" if not i%3 else "Buzz" if not i%5 else str(i) for i in range(1, 25)]))
