class LinkedLists:
    class _Node:
        __slots__ = '_data', '_next'


        def __init__(self, data, next):
            self._data = data
            self._next = next


    def __init__(self):
        self._head = None
        self._tail = None
        self._size = 0


    def is_empty(self):
        return self._size == 0


    def add_first(self, value):
        new_node = self._Node(value, None)
        if self.is_empty():
            self._head = new_node
            self._tail = new_node
        else:
            new_node._next = self._head
        self._head = new_node
        self._size += 1


    def add_last(self, value):
        new_node = self._Node(value, None)
        if self.is_empty():
            self._head = new_node
            self._tail = new_node
        else:
            self._tail._next = new_node
        self._tail = new_node
        self._size += 1


    def add_particular(self, value, position):
        new_node = self._Node(value, None)
        if position > self._size+1 and (not self.is_empty()):
            print("The position is invalid")
        elif self.is_empty():
            self._head = new_node
            self._tail = new_node
        else:
            i = 1
            temp = self._head
            while i < position-1:
                temp = temp._next
                i += 1
            new_node._next = temp._next
            temp._next = new_node
        self._size += 1


    def remove_last(self):
        if self.is_empty():
            print("List is Empty")
        temp = self._head
        i = 1
        while i < self._size-2:
            temp = temp._next
            i += 1
        self._tail = temp
        value = temp._next._data
        self._tail._next = None
        self._size -= 1
        if self.is_empty():
            self._head = None
        return value


    def remove_first(self):
        if self.is_empty():
            print("List is Empty")
        value = self._head._data
        self._head = self._head._next
        self._size -= 1
        if self.is_empty():
            self._tail = None
        return value


    def remove_particular(self, position):
        if self.is_empty():
            print("List is Empty")
        temp = self._head
        i = 1
        while i < position-1:
            temp = temp._next
            i += 1
        value = temp._next._data
        temp._next = temp._next._next
        self._size -= 1
        return value


    def print_list(self):
        temp = self._head
        while temp != None:
            print(temp._data, end="-->")
            temp = temp._next
        print()


l = LinkedLists()
l.add_first(1)
l.add_last(3)
l.add_last(5)
l.add_particular(2, 2)
l.add_particular(4, 4)
l.add_particular(6, 6)
l.add_first(12)
l.add_last(10)
l.print_list()
print(l.remove_last())
l.print_list()
print(l.remove_first())
l.print_list()
print(l.remove_particular(4))
l.print_list()