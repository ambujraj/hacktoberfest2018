n=int(input('How many fibonacci numbers do you want to be printed: '))
f1=1
f2=1

if(n ==1):
	print(f1)
elif(n==2):
	print(f1,f2)
else:
	print(f1,f2,end=' ')
	for i in range(3,n+1,1):
		f3=f1+f2
		if(i < n):
			print(f3,end=' ')
		else:
			print(f3)
		f1,f2=f2,f3

		