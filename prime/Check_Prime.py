''' This Algo is based on that every number other then
2 and 3 is of the form 6*k+1 and 6*k-1'''
def prime(x):
    for i in range(2,x//2+1):
        if x%i==0:
            return 0
    return 1
n=int(input())
if n==2 or n==3:
    print ("Prime")
elif (n-1)%6==0 or (n+1)%6==0:
    if prime(n):
        print("Prime")
    else:
        print("Not Prime")
else:
    print("Not Prime")
    
