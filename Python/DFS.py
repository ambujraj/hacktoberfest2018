import numpy
class Graph:
    def __init__(self, vertices):
        self._vertices = vertices
        self._adjMatrix = numpy.zeros((vertices, vertices))
        self._visited = [False]*vertices
    def addEdge(self, u, v, w = 1):
        self._adjMatrix[u][v] = w
    def deleteEdge(self, u, v):
        self._adjMatrix[u][v] = 0
    def DFS(self, source):
        if self._visited[source] == False:
            print(source, end= '->')
            self._visited[source] = True
            for j in range(self._vertices):
                if self._adjMatrix[source][j] == 1 and self._visited[j] == False:
                    self.DFS(j)
g = Graph(7)
g.addEdge(0, 1)
g.addEdge(0, 5)
g.addEdge(0, 4)
g.addEdge(0, 2)
g.addEdge(2, 5)
g.addEdge(2, 3)
g.addEdge(6, 3)
g.addEdge(1, 3)
g.addEdge(6, 4)
g.addEdge(1, 6)
print(g._adjMatrix)
g.DFS(0)