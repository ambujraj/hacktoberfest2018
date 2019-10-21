class Solution:
    def lengthOfLastWord(self, s: str) -> int:
        if(len(s)==0):
            return 0
        count=0
        for i in s:
            if(i==" "):
                count+=1
        if(count==len(s)):
            return (0)
        s=s.split()[-1]
        return len(s)
