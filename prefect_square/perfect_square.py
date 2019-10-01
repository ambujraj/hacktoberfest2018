from math import sqrt

def isSquare(n):
	return sqrt(n) % 1 == 0

if __name__ == "__main__":
	n = int(input())
	if isSquare(n):
		print("This is a perfect square")
	else:
		print("This is not a perfect square")
