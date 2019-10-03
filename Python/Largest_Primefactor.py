import math
def greatest_primefactor(num):
    maxprime=0
    while num%2==0:
        num/=2
        maxprime=2

    for i in range(3,int(math.sqrt(num))+1,2):
        while num%i==0:
            num/=i
            maxprime=i
    if num>2:
        maxprime=num
    return maxprime
print(greatest_primefactor(4546513))


