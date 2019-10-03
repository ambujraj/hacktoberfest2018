def partition(a, start=0, end=0):
    pivot = a[end]
    pi = start
    for i in range(start, end):
        if a[i] <= pivot:
            a[i], a[pi] = a[pi], a[i]
            pi += 1
    a[pi], a[end] = a[end], a[pi]
    return pi


def quicksort(a, start = 0, end = 0):
    if start < end:
        pi = partition(a, start, end)
        quicksort(a, start, pi-1)
        quicksort(a, pi+1, end)

arr = [1, 9, 2]
print("Before Sorting =", arr)
print("-----------------Sorting--------------------------")
quicksort(arr, 0, len(arr)-1)
print("After Sorting =", arr)
