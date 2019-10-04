print("Enter time as hh:mm:ssAM/PM")
s=str(input())
s1=""
if s[8]=="A":
    if s[0]=="1" and s[1]=="2":
        s1="00"+s[2:8]
    else:
        s1=s[0:8]
else:
    if s[0]=="1" and s[1]=="2":
        s1="12"+s[2:8]
    else:
        if ord(s[1])<=55:
            s1=chr(ord(s[0])+1)+chr(ord(s[1])+2)+s[2:8]
        else:
            s1=chr(ord(s[0])+2)+chr(ord(s[1])-8)+s[2:8]
print(s1)
z=input()
