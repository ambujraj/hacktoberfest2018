a=input()
map={}
for i in a:
    if i not in map.keys():
        map[i]=0
    else:
        map[i]+=1
for i in map:
    print("Frequency of element",i,"is ",map[i])
