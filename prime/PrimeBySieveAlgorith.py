# this is the program to find the no of primes in the range of 1 to N
# using Sieve of Eratosthenes
from math import sqrt
# enter the Number N ,to find the prime number till N.
N = int(input())
if N <= 1:
    print(0)
else:
    isPrime = [1] * N
    isPrime[0] = 0
    isPrime[1] = 0
    count = 0
    for i in range(2, int(sqrt(N)) + 1):
        if isPrime[i] == 1:
            for j in range(2 * i, N, i):
                isPrime[j] = 0
    for i in range(1, N):
        if isPrime[i] == 1:
            print(i, end=" ")
