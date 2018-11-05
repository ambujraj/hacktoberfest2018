def pallen():  # made a function and it will execute  when u call pallen()

    x =int(input("Enter the number"))    # for Interger values..
    s = x  # Assignment s wll hold the value of x
    a = 0   
    while s>0:  Loop....
       
        rem = s%10   # remainder  
        a = a*10 + rem   # reverse of a number
        s = s//10    # integer values 
    if x == a:
        print("Pallendrome")
    else:
        print("Not a pallendrome")   
