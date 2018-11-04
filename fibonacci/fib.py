def fib():
    x = int(input('enter the last number'))
    a = 0
    b = 1
    sum = 0
    z = a +b
    while z < x:
        
        if z%2 == 0:
            sum = sum + z           
        a = b
        b = z
        z = a +b
    print(sum)
        
