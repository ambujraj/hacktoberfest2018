def factorial():
    #for get input by user
    number = int(input("Enter a number: "))
    if(number==0):
        return 1
    else:
        return number*factorial(number-1)
    
