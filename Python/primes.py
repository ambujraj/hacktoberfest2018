def findPrimes(n):	
	prime = [True for i in range(n+1)]
	p=2
	while(p*p <= n):
		if(prime[p] == True):
			for i in range(p*p, n+1, p):
				prime[i] = False
		p += 1

	for p in range(2, n):
		if prime[p]:
			print(p)


n = input("enter number to look for primes up to: ")
findPrimes(int(n))