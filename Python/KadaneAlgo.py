#Kadane's Algorithm to calculate the maximum sum of the contiguous subarray of given array.


def kadane(l):
    maxsum, cursum = l[0], l[0]
    for i in range(1, len(l)):
        cursum = max(cursum, l[i]+cursum)
        if cursum > maxsum:
            maxsum = cursum
    return maxsum

n = int(input("Enter the size of the array: "))
l = list()
print("Enter the array elements one by one")
for i in range(n):
    l.append(int(input()))
print(kadane(l))
