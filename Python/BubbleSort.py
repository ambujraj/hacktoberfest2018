def bubblesort(a):
    for k in range(len(a)):
        i = 0
        while i < len(a)-1:
            j = i+1
            if a[i] > a[j]:
                a[i], a[j] = a[j], a[i]
            i += 1

arr = [1, 9, 2, 5, 4, 8, 10, 7, 6, 3]
print("Before Sorting =", arr)
print("-----------------Sorting--------------------------")
bubblesort(arr)
print("After Sorting =", arr)