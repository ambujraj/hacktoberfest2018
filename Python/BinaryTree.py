from LinkedListQueue import queue


class binaryTree:
    class _Node(object):
        __slots__ = '_data', '_left', '_right'


        def __init__(self, value, left = None, right = None):
            self._data = value
            self._left = left
            self._right = right


    def __init__(self):
        self._root = None
        self._size = 0


    def maketree(self, value, left, right):
        self._root = self._Node(value, left._root, right._root)
        left._root = None
        right._root = None


    def levelorder(self):
        temp = self._root
        q = queue()
        print(temp._data, end=' ')
        q.push(temp)
        while not q.is_empty():
            temp = q.pop()
            if temp._left:
                print(temp._left._data, end=' ')
                q.push(temp._left)
            if temp._right:
                print(temp._right._data, end=' ')
                q.push(temp._right)


    def inorder(self, root):
        if root:
            self.inorder(root._left)
            print(root._data, end= ' ')
            self.inorder(root._right)


    def preorder(self, root):
        if root:
            print(root._data, end=' ')
            self.preorder(root._left)
            self.preorder(root._right)


    def postorder(self, root):
        if root:
            self.postorder(root._left)
            self.postorder(root._right)
            print(root._data, end= ' ')


e = binaryTree()
x = binaryTree()
y = binaryTree()
z = binaryTree()
p = binaryTree()
q = binaryTree()
r = binaryTree()
s = binaryTree()

x.maketree(10, e, e)
y.maketree(20, e, e)
z.maketree(30, x, y)
q.maketree(30, e, e)
r.maketree(40, e, e)
s.maketree(70, q, r)
p.maketree(100, z, s)

p.inorder(p._root)
print()
p.preorder(p._root)
print()
p.postorder(p._root)
print()
p.levelorder()