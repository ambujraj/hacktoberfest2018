import random

def main():
    min = int(input("Enter lower bound: "))
    max = int(input("Enter upper bound: "))
    print("Random number: " + str(random.randint(min, max)))

if __name__ == '__main__':
    main()
