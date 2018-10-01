print('Enter the number of terms: ')
num = int(input())

alist = []

for i in range(0, num):
	if(i == 0):
		alist.append(0)
	elif(i == 1):
		alist.append(1)
	else:
		alist.append(alist[i - 1] + alist[i - 2])

print('The fibonnaci series is: ')
for i in range(num):
	print(alist[i], end = ' ')
