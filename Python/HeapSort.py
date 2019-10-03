class heap:
    def __init__(self, size):
        self._maxsize = size
        self._data = [0]*size

    def leftChild(self, i):
        return 2*i+1
    def rightChild(self, i):
        return 2*i+2
    def parent(self, i):
        return (i-1)//2
    def Heapify(self, n, i):
        l = self.leftChild(i)
        r = self.rightChild(i)
        largest = i
        if l < n and self._data[largest] < self._data[l]:
            largest = l
        if r < n and self._data[largest] < self._data[r]:
            largest = r
        if largest != i:
            self._data[i], self._data[largest] = self._data[largest], self._data[i]
            self.Heapify(n, largest)
    def HeapSort(self):
        i = self._maxsize//2 - 1
        while i >= 0:
            self.Heapify(self._maxsize, i)
            i -= 1
        i = self._maxsize - 1
        while i >= 0:
            self._data[0], self._data[i] = self._data[i], self._data[0]
            self.Heapify(i, 0)
            i -= 1

h = heap(10)
h._data = [20, 1, 5, 30, 8, 32, 65, 15, 10, 18]
print("Before Sorting")
print(h._data)
print("----------------Sorting--------------------")
h.HeapSort()
print(h._data)