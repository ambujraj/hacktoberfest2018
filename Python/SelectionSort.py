def selectionsort(a):
    for i in range(len(a)-1):
        j = i+1
        while j < len(a):
            if arr[i] > arr[j]:
                arr[i], arr[j] = arr[j], arr[i]
            j += 1
arr = [1, 9, 2, 5, 4, 8, 10, 7, 6, 3]
print("Before Sorting =", arr)
print("-----------------Sorting--------------------------")
selectionsort(arr)
print("After Sorting =", arr)
s = {1, 2, 3, 4}
s = list(s)
print(s)