def convert(b,m):
    l=len(m)
    i=0
    n=0
    j=l-1
    while(i<l and j>=0):
        n=n+((b**i)*m[j])
        i=i+1
        j=j-1
    return n
t=input()
while(t):
    t=t-1
    nn=input()
    badi=[]*nn
    for ii in range(0,nn):
        b,s=raw_input().split()
        b=int(b)
        l=len(s)
        n=[]
        for i in range(0,l):
            k=0
            max=1
            if(ord(s[i])>=ord('0') and ord(s[i])<=ord('9')):
                k=int(s[i])
                n.append(k)
            else:
                k=ord(s[i])-ord('A')+10
                n.append(k)
            if(k>max):
                max=k
        if(b==-1):
            a=[]*(36-max)
            for i in range(max+1,37):
                a.append(convert(i,n))
            badi.append(a)
        else:
            a=[]*1
            a.append(convert(b,n))
            badi.append(a)
    count=0
    flag=0
    for y in badi:
        for j in y:
            val=j
            count=0
           # print val
##       #print '/n'
            for xx in badi:
                innercount=0
                for yy in xx:
                    if val==yy:
                        innercount=1
                 #       print val,yy
                        break
                if innercount==1:
                    #print "here"
                    count=count+1
                    mainval=val
                else:
                    break
           # print count
            if count==nn:
                flag=1 
                break    
        break
    if flag==0 or mainval>1000000000000L :
        print "-1"
    else:
        print mainval
