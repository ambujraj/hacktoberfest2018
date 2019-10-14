class Node():
  def __init__(self, data):
    self.data = data
    self.next = None

class SinglyLinkedList():
  ### Start of dunder function definitions
  def __init__(self, data=None): ## Initialiser
    if data is None:
      self.head = None
    else:
      if isinstance(data, SinglyLinkedList):
        self.head = data.head
      elif isinstance(data, list):
        self.head = None
        i = 0
        for e in data:
          self.insert(e, i)
          i+=1
      else:
        self.head = Node(data)

  def __repr__(self):
    if self.head is None:
      return "SinglyLinkedList()"
    else:
      return "SinglyLinkedList({})".format(list(self))

  def __str__(self):
    s = ''
    curr = self.head
    if curr is None:
      return "Empty List"
    while curr is not None:
      s+='{}->'.format(curr.data)
      curr = curr.next
    s+="NULL"
    return s

  def __iter__(self):
    self._curr = self.head
    return self

  def __next__(self):
    if self._curr is not None:
      d = self.curr.data
      self.curr = self.curr.next
      return d
    raise StopIteration 

  # def __add__(self, other):
  #   if isinstance(other, SinglyLinkedList):
  #     curr = self.head
  #     if curr is None:
  #       return SinglyLinkedList(other)
  #     else:
  #       while curr.next is not None:
  #         curr = curr.next
  #       curr.next = other
  #       return SinglyLinkedList(self)
  #   else:
  #     raise TypeError("Cannot convert SinglyLinkedList and {}".format(type(other)))
  ### End of dunder function definitions

  def show(self):
    print(self.__str__())

  def insert(self, d, index=0):
    '''
    purpose:
        To insert a given value at any given index of the linked list
    params: 
        d : Data to be inserted 
        index: Position at which d will be inserted
    return: None
    '''
    #at index, d will be added
    curr = self.head
    if curr is None:
      if index == 0:
        self.head = Node(d)
      else:
        print("Index out of bounds")
    else:
      if index == 0:
        temp = Node(d)
        temp.next = curr
        self.head = temp
      else:
        while index>1:
          curr = curr.next
          index-=1
        temp = Node(d)
        temp.next = curr.next
        curr.next = temp

  def insert_at_beginning(self, d):
    '''
    purpose: 
        To insert a given value at the start of the linked list
    params: 
        d : Data to be inserted 
    return: None
    '''
    self.insert(d, 0)

  def insert_at_end(self, d):
    '''
    purpose: 
        To insert a given value at the end of the linked list
    params: 
        d : Data to be inserted 
    return: None
    '''
    self.insert(d, self.length)

  def remove(self, d):
    '''
    purpose: 
        To remove a given value off the linked list if present
    params: 
        d : Data to be removed 
    return: None
    '''
    curr = self.head
    if curr is None:
      print("Can't delete from empty list")
      return
    if curr.data == d:
      self.head = curr.next
      return;
    while curr.next is not None:
      if curr.next.data == d:
        curr.next = curr.next.next
        break
      curr = curr.next
    else:
      print("Element not found in the list")

  def search(self, k):
    '''
    purpose:
        To search and return index if k in present in SinglyLinkedList
    params:
        k: Key to be searched
    return: <int> index if present : else -1
    '''
    curr = self.head
    i = 0
    while curr is not None:
      if curr.data == k:
        return i
      i+=1
      curr = curr.next
    else:
      return -1


  @property
  def length(self):
    '''
    purpose:
        To get the length of the SinglyLinkedList
    params:
        None
    return: <int> length
    '''
    l = 0
    curr = self.head
    while(curr is not None):
      l+=1
      curr = curr.next
    return l

'''
Usage:
  <object_name> = SinglyLinkedList() will create a singly linked list
  Example: singly_linked_list_object = SinglyLinkedList()
           will create an empty Singly Linked List
  Other operations can be done by using <object_name>.method_name({params})
  Example: singly_linked_list_object.insert(1, 0)
'''
