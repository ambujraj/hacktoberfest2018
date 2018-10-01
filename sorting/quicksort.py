def quicksort(l):
	if(len(l) > 1):
		pivot = l[0]
		left = [i for i in l[1:] if i <= pivot]
		right = [i for i in l[1:] if i > pivot]
		return quicksort(left) + [pivot] + quicksort(right)
	else:
		return l

def main():
	n = int(input("Enter how many numbers in the list: "))
	myList = list()
	for i in range(n):
		myList.append(int(input("Enter number: ")))
	myList = quicksort(myList)

	print("----------Sorted List----------")
	for i in range(n):
		print(myList[i])

if __name__ == '__main__':
	main()