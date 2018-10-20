import math

def isPS(x)
    res = math.sqrt(x)
    # square root of input, let's compare 9 and 10
    return ((res -  math.floor(res)) == 0)
    # return true if result (square root of x) - rounded result equals to 0, return false if not
    # in case of 9, it is true as sqrt(9) is 3
    # in case of 10, it is false as sqrt(10) is 3.16... 
