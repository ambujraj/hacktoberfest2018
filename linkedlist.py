class Node:

    def __init__(self,data):
        self.data=data
        self.next=None

a=Node(96)
b=Node(2)
c=Node(52)
d=Node(18)
e=Node(36)
f=Node(13)
a.next=b
b.next=c
c.next=d
d.next=e
e.next=f
b=None
c=None
d=None
e=None
f=None

a.next.next.next=a.next.next.next.next


temp=a
while temp!=None:
    print(temp.data)
    temp=temp.next
