import math 
   
# the recursive function to reverse 
def rev(num): 
    return int(num != 0) and ((num % 10) * \ 
             (10**int(math.log(num, 10))) + \ 
                          rev(num // 10)) 
  
# initializing number  
test_number = 9669669
  
# printing the original number  
print ("The original number is : " + str(test_number)) 
  
# using math.log() + recursion + list comprehension 
# for checking a number is palindrome 
res = test_number == rev(test_number) 
  
# printing result 
print ("Is the number palindrome ? : " + str(res)) 