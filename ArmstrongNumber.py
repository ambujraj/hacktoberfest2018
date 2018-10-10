num = int(input("Enter a number :\t"))
#1*1*1+5*5*5+3*3*3 =123
sum= 0
x=num
sum=0
while x!=0:
    sum+=(x%10)**3
    x=x//10
if(num==sum):
    print("Armstrong number")
else:
    print("Not a Armstrong Number")

