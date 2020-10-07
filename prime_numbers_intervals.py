def isPrime(a):
	if(a<2):
		return False
	for i in range(2, a//2+1):
		if(a%i==0):
			return False
	return True

x = int(input("Lower Range: "))
y = int(input("Upper Range: "))

for b in range(x,y):
	if isPrime(b):
		print(b, end=" ")
