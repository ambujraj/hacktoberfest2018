"""
Name: [Iain Mclaughlan](@Darthmazgar)
Place: Edinburgh, UK
About: Physics student and wanabe coder
Programming Language: Mainly python (small amounts of c, cpp, java)
"""

# I=1, V=5, X=10, L=50, C=100,, D=500, M=1000
num = int(input("Enter a number: "))
if num <= 0:
    print("Enter a positive number.")
string = ""


while num > 0:
    if num >= 900:
        if num >= 900 and num < 1000:
            string += "C"
            num += 100
        string += "M"
        num -= 1000

    if num >= 400 and num < 900:
        if num >= 400 and num < 500:
            string += "C"
            num += 100
        string += "D"
        num -= 500

    if num >= 90 and num < 400:
        if num >= 90 and num < 100:
            string += "X"
            num += 10
        string += "C"
        num -= 100

    if num >= 40 and num < 90:
        if num >= 40 and num < 50:
            string += "X"
            num += 10
        string += "L"
        num -= 50

    if num >= 9 and num < 40:
        if num == 9:
            string += "I"
        string += "X"
        num -= 10

    if num >= 4 and num < 9:
        if num == 4:
            string += "I"
        string += "V"
        num -= 5

    if num < 4 and num > 0:
        string += "I"
        num -= 1

print(string)
