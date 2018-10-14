def sort_0_1_2(arr, arr_len):
	low = 0
	mid = 0
	high = arr_len - 1
	while mid <= high:
		if arr[mid] == 0:
			arr[low], arr[mid] = arr[mid], arr[low]
			low += 1
			mid += 1
		elif arr[mid] == 1:
			mid += 1
		else:
			arr[high], arr[mid] = arr[mid], arr[high]
			high -= 1
	return arr


def test():
	arr = [0, 1, 1, 0, 1, 2, 1, 2, 0, 0, 0, 1]
	print sort_0_1_2(arr, len(arr))
