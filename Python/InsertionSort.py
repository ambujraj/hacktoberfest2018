def insertionsort(a):
    for i in range(1, len(a)):
        key = arr[i]
        j = i - 1
        while j >= 0 and key < arr[j]:
            arr[j + 1] = arr[j]
            j -= 1
        arr[j + 1] = key


arr = [1, 9, 2, 5, 4, 8, 10, 7, 6, 3]
print("Before Sorting =", arr)
print("-----------------Sorting--------------------------")
insertionsort(arr)
print("After Sorting =", arr)