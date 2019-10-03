import numpy as np


class Graph:
    def __init__(self, vertices):
        self._adjmatrix = np.zeros((vertices, vertices))
        self.vertices = vertices
    def insert(self, u, v, w = 1):
        self._adjmatrix[u][v] = w
    def delete_edge(self, u, v):
        self._adjmatrix[u][v] = 0
    def get_edge(self, u, v):
        return self._adjmatrix[u][v]
    def in_degree(self, u):
        ctr = 0
        for i in range(self.vertices):
            if self._adjmatrix[i][u] == 1:
                ctr += 1
        return ctr
    def out_degree(self, u):
        ctr = 0
        for i in range(self.vertices):
            if self._adjmatrix[u][i] == 1:
                ctr += 1
        return ctr
    def number_of_edges(self):
        ctr = 0
        for i in range(self.vertices):
            for j in range(self.vertices):
                if self._adjmatrix[i][j] == 1:
                    ctr += 1
        return ctr


g = Graph(7)
g.insert(0, 3)
g.insert(0, 2)
g.insert(1, 4)
g.insert(1, 3)
g.insert(1, 2)
g.insert(4, 6)
g.insert(4, 2)
g.insert(3, 5)
g.insert(2, 5)
g.insert(2, 6)
print(g.number_of_edges())
print(g.out_degree(2))
print(g.in_degree(2))