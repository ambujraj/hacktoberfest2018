number = int(input("Input a number to generate a list of prime numbers up to your number: "))

def is_prime(num):
    for i in range(2, num):
        if num % i == 0:
            return False
    return True
print(f"Prime numbers til {number}:\n")
for i in range(2, number+1):
    if is_prime(i):
        print(i, "\n")
