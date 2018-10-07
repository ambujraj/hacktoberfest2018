def fibo(n):  
	if n <= 1:
		return n
	else:
		return fibo(n-1) + fibo(n-2)

num = int(input("Enter a number: "))   

if num < 2:  
	print("0 1")
elif num == 1:
    print("0")
elif num == 0:
    print("Limit should be greater than 0") 
else:  
	for i in range(num):
 		print(fibo(i), end=' ')