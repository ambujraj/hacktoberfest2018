''' This DFS Algorithm will find out all the possible paths from all nodes in the Graph'''

from collections import defaultdict


class Graph:

    def __init__(self):
        self.graph = defaultdict(list)  # create from existing library

    def addEdge(self, i, j):
        self.graph[i].append(j)  # add a new edge

    # Actual algorithm of DFS in python
    def DFSUtil(self, j, isvisited):
        isvisited[j] = True
        print(j)
        for i in self.graph[j]:
            if isvisited[i] == False:
                self.DFSUtil(i, isvisited)

    def DFS(self, j):
        visited = [False] * (len(self.graph))
        self.DFSUtil(j, visited)


graph = Graph()
graph.addEdge(0, 1)
graph.addEdge(0, 2)
graph.addEdge(1, 2)
graph.addEdge(2, 0)
graph.addEdge(2, 3)
graph.addEdge(3, 3)

for i in range(4):
    print("DFS from vertex " + str(i) + ": ")
    graph.DFS(i)
