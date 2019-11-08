sm=1
no=0
a = int(input("Enter the no. of terms you want to see: "))
for i in range (1, a+1): 
    a = sm
    no += sm
    sm = no
    print (no)
    no = a
    
