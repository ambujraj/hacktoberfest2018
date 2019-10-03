class Deque:
    def __init__(self):
        self._data = []
        self._front = 0
        self._size = 0


    def add_first(self, data):
        self._data.insert(self._front, data)
        self._size += 1


    def add_last(self, data):
        self._data.append(data)
        self._size += 1


    def is_empty(self):
        return self._size == 0


    def remove_last(self):
        if self.is_empty():
            raise IndexError
        value = self._data.pop()
        self._size -= 1
        return value


    def remove_first(self):
        if self.is_empty():
            raise IndexError
        value = self._data.pop(self._front)
        self._size -= 1
        return value


q = Deque()
q.add_first(1)
print(q._data)
q.add_last(2)
print(q._data)
q.add_last(3)
print(q._data)
print(q.remove_last())
print(q.remove_first())
print(q._data)
print(q.remove_last())