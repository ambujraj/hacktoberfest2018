
#this function merges the subarrays
def merge(arr, left ,mid ,right) :
    n1 = int(mid - left + 1)
    n2 = int(right - mid)
    
    #Creating temporary left and
    #right subarrays
    L = [0] * (n1)
    R = [0] * (n2)
    
    #Filling the subarrays
    for i in range(0,n1):
        L[i] = arr[left + i]
        
    for j in range(0,n2):
        R[j] = arr[mid + j + 1]
        
    i = 0
    j = 0
    k = left;
    
    #Merge operation
    while i < n1 and j < n2 :
        if L[i] <= R[j]:
            arr[k] = L[i]
            k+=1
            i+=1
        else:
            arr[k] = R[j]
            k+=1
            j+=1
      
    #Remaining elements of left subarray      
    while i < n1:
        arr[k] = L[i]
        k+=1
        i+=1
        
        
    #Remaining elements of right subarray
    while j < n2:
        arr[k] = R[j]
        k+=1
        j+=1
        
 
#mergesort function       
def mergeSort(arr, left, right):
    
    if left < right:
        #calculating mid
        mid = int((left + (right - 1)) / 2)
    
        #sort left subarray
        mergeSort(arr, left, mid)
        #sort right subarray
        mergeSort(arr, mid + 1, right)
        #merge left and right subarray
        merge(arr, left, mid, right)
    

#sample array to be sorted
arr = [4, 5, 1, 2, -2, 0]
size = len(arr)
print("Before sorting : ")

for i in range(size):
    print("%d" %arr[i]);

mergeSort(arr, 0, size - 1);

print("After sorting : ")

for j in range(size):
    print("%d" %arr[j]);
    
    
