print("fibonacci till n")

endTerm = input("Enter till what number you want the series printed till: ")
n = int(endTerm)
a = 0
b = 1

while a < n:
	print(b, end=' ')
	'''the end= helps the series to be printed in the same line instead of new lines.'''
	a, b = b, a+b
print()
