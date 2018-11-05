def is_armstrong(n):
	m=0
	t=n
	while n>0:
		r=(n%10)
		m=m+(r*r*r)
		n=n/10
	print m
	if m==t:
		print "Yes it is armstrong"
	else:
		print "Not it is not armstrong"
is_armstrong(153)
