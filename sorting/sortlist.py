def sortlist():
    n = int(input("Enter the number of elements in list: "))
    l2 = []
    for i in range(n):
        l2.append(int(input("Enter the element: ")))
    for i in range(n):
        for j in range(i, n):
            if(l2[i]>l2[j]):
                t = l2[i]
                l2[i] = l2[j]
                l2[j] = t
    print(l2)