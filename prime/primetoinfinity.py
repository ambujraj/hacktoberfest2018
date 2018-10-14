
primelist = [2,3]
prime = 3

print 2
print 3


while True:
    prime=prime+1

    for x in primelist:

            if (prime) % x == 0:
                break

            if x == primelist[-1]:
                primelist.append(prime)
                print (prime)
