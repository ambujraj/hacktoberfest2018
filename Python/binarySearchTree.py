# This is my favourite code snippet because it provides an effective way of searching

class node:
    def __init__(self,val):
        self.val = val
        self.left = None
        self.right = None
    
class tree:
    def __init__(self):
        self.root=None

    def insert(self,val):
        temp=node(val)
        if self.root:
            iter = self.root
            while iter:
                if iter.val<temp.val:
                    if iter.right:
                        iter=iter.right
                    else:
                        break
                else:
                    if iter.left:
                        iter=iter.left
                    else:
                        break
            if iter.val<temp.val:
                iter.right=temp
            else:
                iter.left=temp
        else:
            self.root=temp

    def inorderPrint(self,r):
        if r:
            self.inorderPrint(r.left)
            print(r.val)
            self.inorderPrint(r.right)

mTree = tree()
print('Enter space seperated values to be inserted: ',end=' ')
vals=list(map(int,input().split()))

for i in vals:
    mTree.insert(i)
mTree.inorderPrint(mTree.root)