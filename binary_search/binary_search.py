def binary_search(arr, value, left = 0, right = -1):
    if right == -1:
        right = len(arr)
    
    middle = (left + right) // 2

    if arr[middle] == value:
        return middle
    elif value < arr[middle]:
        return binary_search(arr, value, left, middle)
    else:
        return binary_search(arr, value, middle, right)

foo = [1,2,3,4,5,6,7,8,9,10]
print(binary_search(foo, 9))

bar = [1,2,3,4,5,6,7,8,9]
print(binary_search(bar, 9))
