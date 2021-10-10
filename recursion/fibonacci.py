series = int(input("Enter no. of terms"))

cnt = 0
x, y = 0, 1

if series <= 0:
   print("Positive integer only")

elif series == 1:
   print(series)
   print(x)

else:
   print("Fibonacci series:")
   while cnt < series:
       print(x)
       nth = x + y
       x = y
       y = nth
       cnt += 1
