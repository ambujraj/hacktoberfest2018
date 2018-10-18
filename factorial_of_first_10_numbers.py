def fact(n):
	if n==1:
		return 1
	return n*fact(n-1)

i=1

while i<=10:
	print (fact(i))
	i=i+1