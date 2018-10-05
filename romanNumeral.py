"""
Name: [Iain Mclaughlan](@Darthmazgar)
Place: Edinburgh, UK
About: Physics student and wanabe coder
Programming Language: Mainly python (small amounts of c, cpp, java)
"""

# I=1, V=5, X=10, L=50, C=100,, D=500, M=1000
num = int(input("Enter a number: "))
string = ""
if num >= 1000:
    pass
elif num < 1000 and num >= 500:
    pass
elif num < 500 and num >= 100:
    pass
elif num < 100 and num >= 50:
    pass
elif num < 50 and num >= 10:
    pass
elif num < 10 and num >= 4:
    pass
else:
    for i in range(num):
        string += 'I'

print(string)
