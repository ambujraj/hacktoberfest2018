num = int(input("Enter a number: "))
sum = num
a = len(str(num))
sum1 = 0

while(num !=0 ):
    b = num %10
    sum1 = sum1+(b**a)
    num = num // 10

if(sum == sum1):
    print("The number is armstrong")
else:
    print("The number is",sum, "not am armstrong number")
