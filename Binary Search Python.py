class Node:
    def __init__(self, key):
        self.left = None
        self.right = None
        self.val = key

# A utility function to insert a new node with the given key
def insert(root, key):
    if root is None:
        return Node(key)
    else:
        if root.val == key:
            return root
        elif root.val < key:
            root.right = insert(root.right, key)
        else:
            root.left = insert(root.left, key)
    return root

# A utility function to do inorder tree traversal
def inorder(root):
    if root:
        inorder(root.left)
        print(root.val)
        inorder(root.right)


# Driver program to test the above functions
r = Node(450)
r = insert(r, 43530)
r = insert(r, 7680)
r = insert(r, 34230)
r = insert(r, 3420)
r = insert(r, 645540)
r = insert(r, 84340)

# Print inoder traversal of the BST
inorder(r)
