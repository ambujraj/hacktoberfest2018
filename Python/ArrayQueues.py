class queue:
    def __init__(self):
        self._data = []
        self._size = 0
        self._front = 0


    def enqueue(self, data):
        self._data.append(data)
        self._size += 1


    def isempty(self):
        return self._size == 0


    def dequeue(self):
        if self.isempty():
            print("Queue is empty")
        value = self._data[self._front]
        self._data[self._front] = None
        self._front += 1
        self._size -= 1
        return value


q = queue()
n = int(input("Enter the size of queue"))
print("Enter the elements one by one")
for i in range(n):
    q.enqueue(int(input()))
print(q._data)
print("If you want to delete an element enter 'Y' eles 'N' ")
c = input()
while c == 'Y':
    print(q.dequeue())
    print("Enter your choice again")
    c = input()
print(q._data)