def insertion_sort(arr):
         for i in range(len(arr)):
                        cursor = arr[i]
                        pos = i

         while pos > 0 and arr[pos - 1] > cursor:
            # Swap the number down the list
                arr[pos] = arr[pos - 1]
                pos = pos - 1
            # Break and do the final swap
                arr[pos] = cursor
         return arr
