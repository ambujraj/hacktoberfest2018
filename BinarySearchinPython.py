def binary_search(data, elem):

    low = 0
    high = len(data) - 1

    while low <= high:
      
        middle = (low + high)//2
       
        if data[middle] == elem:
            return middle
        elif data[middle] > elem:
            high = middle - 1
        else:
            low = middle + 1

    return -1
