#Time complexity O(n^2) Space complexity O(n)

def selection_sort(arr):
    for i in range(len(arr)):
        position_of_max = i
        for j in range(i+1,len(arr)):
            if arr[j]>arr[position_of_max]:
                position_of_max = j
        temp = arr[i]
        arr[i] = arr[position_of_max]
        arr[position_of_max] = temp
    return arr
    
arr = [13,4,12,1,5]
print selection_sort(arr)
