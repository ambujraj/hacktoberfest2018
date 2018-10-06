import Queue

INF = 1000000000
adjacentes = [0] * 100001
distancias = [INF] * 100001

def dijkstra(no):
	
	global distancias
	fila = Queue.PriorityQueue()
	
	distancias[no] = 0
	par = (distancias[no], no)
	fila.put(par)
	
	while not fila.empty():
		
		_, topo = fila.get()
		
		if adjacentes[topo] != 0:
			for peso, filho in adjacentes[topo]:
	
				if distancias[filho] > distancias[topo] + peso:
				
					distancias[filho] = distancias[topo] + peso
					fila.put((distancias[filho], filho))


