import math


def bucketsort(l):
    bucket = list()
    slots = 10
    for i in range(slots):
        bucket.append(list())
    div = math.ceil((max(l)+1)/10)

    #inserting elements into the buckets, where ith element is put inside (i//div)th bucket.
    for i in l:
        bi = i//div
        bucket[bi].append(i)

    #sorting each bucket.
    for i in range(slots):
        bucket[i] = sorted(bucket[i])
    newlist = list()

    #collecting each element inside the buckets sequentially and pushing to newlist.
    for i in range(slots):
        for j in range(len(bucket[i])):
            newlist.append(bucket[i][j])
    return newlist

l = [22, 31, 42, 54, 81, 32, 55, 68, 72, 50, 10, 35]
print("Unsorted list")
print(l)
print("Sorted list")
print(bucketsort(l))
