#!/usr/bin/env python2

num = int(raw_input("enter no. for calculating its factorial: "))
fact=1
for i in range(1,num+1):
	fact=fact*i
print "factorial is:",fact
