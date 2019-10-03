class Stacks:
    def __init__(self):
        self._data = []
        self._size = 0


    def push(self, e):
        self._data.append(e)
        self._size += 1


    def is_empty(self):
        return self._size == 0


    def pop(self):
        if self.is_empty():
            print("Stack is empty")
        value = self._data.pop()
        self._size -= 1
        return value


    def top(self):
        if self.is_empty():
            print("Stack is empty")
        return self._data[-1]

s = Stacks()
n = int(input("Enter the size of the stacks "))
print("Enter the elements one by one: ")
for i in range(n):
    s.push(int(input()))
print(s._data)
print("Enter 'Y' to pop last element and 'N' to stop")
c = input()
while c == 'Y':
    print(s.pop())
    print("Enter your choice: ")
    c = input()
print(s.top())
print(s._data)