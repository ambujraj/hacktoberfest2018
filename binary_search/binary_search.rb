def binary_search(arr, value, left = 0, right = 0)
	if right == 0
		right = arr.length()
	end
	middle = (left + right) / 2
	
	if arr[middle] == value
		return middle
	elsif value < arr[middle]
		return binary_search(arr, value, left, middle)
	else
		return binary_search(arr, value, middle, right)
	end
end
