import sys

class Graph():

	def __init__(self, vertices):
		self.V = vertices
		self.graph = [[0 for column in range(vertices)]
					for row in range(vertices)]

	def print_solution(self, dist):
		print("Vertex \tDistance from Source")
		for node in range(self.V):
			print(node, "\t", dist[node])

	def min_distance(self, dist, sptSet):

		min = sys.maxsize

		for v in range(self.V):
			if dist[v] < min and sptSet[v] == False:
				min = dist[v]
				min_index = v

		return min_index

	def dijkstra(self, src):

		dist = [sys.maxsize] * self.V
		dist[src] = 0
		sptSet = [False] * self.V

		for cout in range(self.V):
			u = self.min_distance(dist, sptSet)
			sptSet[u] = True

			for v in range(self.V):
				if self.graph[u][v] > 0 and sptSet[v] == False and dist[v] > dist[u] + self.graph[u][v]:
						dist[v] = dist[u] + self.graph[u][v]

		self.print_solution(dist)

# Driver program
if __name__ == "__main__":
	g = Graph(6)
	g.graph = [
			[0, 5, 0, 0, 0, 0],
			[5, 0, 0, 15, 20, 0],
			[0, 0, 0, 30, 35, 0],
			[0, 15, 30, 0, 0, 20],
			[0, 20, 35, 0, 0, 10],
			[0, 0, 0, 20, 10, 00]
		]

	g.dijkstra(0)
