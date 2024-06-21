def mySqrt(x):
    if x == 1:
        return 1
    return binarySearch(0, x/2, x)

def binarySearch(start,end,target):
    if start == end-1 or start == end:
      if end * end > target:
          return start
      else:
          return end
    else:
      middle = (start+end)/2
      if middle * middle > target:
          return binarySearch(start, middle-1,target)
      elif middle * middle == target:
          return middle
      else:
          return binarySearch(middle, end,target)

userin = input("\nEnter the number whose square root is to be calculated: ")
try:
   val = int(userin)
except ValueError:
   print("Please input an int!")

print(mySqrt(val))


