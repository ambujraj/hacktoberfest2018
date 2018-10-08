class Solution:
    # @param A : integer
    # @return an integer
    def isPalindrome(self, A):
        
        if A<0:
            return 0
        
        r = 0
        b = A
        while A > 0:
            r *= 10
            r += A % 10
            A = A//10
        
        # verify what is the value for the reversed number by printing it
        # b = ''.join(reversed(A))
        
        if r == b:
            # return 1 if its a palindrome
            return 1
        else:
            # return -1 if its not a palindrome
            return -1