def F(n):
    if n in [0,1] return n
    return F(n-1)+F(n-2)

if __name__ == '__main__':
    num = int(input("Enter a number: "))
    print(F(num))
