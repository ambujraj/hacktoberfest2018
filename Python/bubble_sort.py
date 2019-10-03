#This is my favourite code because it lets us sort integers

#bubble sort function
def bubble_sort(arr):
    n = len(arr)
    for i in range(n):
        for j in range(0, n-i-1):
            if arr[j] > arr[j+1] :
                arr[j], arr[j+1] = arr[j+1], arr[j]

#driver code
arr = [5,4,3,2,1]
#sorting using bubble sort
print('Unsorted: ' + str(arr))
bubble_sort(arr)
print('Sorted: ' + str(arr))