def dijkstra(graph, start_node):
    """
    Finds the shortest path from a single source node to all other nodes in a graph.

    Args:
        graph: A dictionary mapping node names to lists of adjacent nodes.
        start_node: The name of the source node.

    Returns:
        A dictionary mapping node names to their shortest distances from the
        source node.
    """

    # Initialize the distances.
    distances = {}
    for node in graph:
        distances[node] = float('inf')
    distances[start_node] = 0

    # Initialize the visited set.
    visited = set()

    # Initialize the priority queue.
    queue = [(0, start_node)]

    # While the queue is not empty, do the following:
    while queue:
        # Get the node with the shortest distance from the queue.
        current_node = queue.pop(0)[1]

        # If the current node has already been visited, skip it.
        if current_node in visited:
            continue

        # Add the current node to the visited set.
        visited.add(current_node)

        # Update the distances of all adjacent nodes.
        for adjacent_node in graph[current_node]:
            new_distance = distances[current_node] + graph[current_node][adjacent_node]
            if new_distance < distances[adjacent_node]:
                distances[adjacent_node] = new_distance
                queue.append((new_distance, adjacent_node))

    return distances


graph = {
    'A': {'B': 1, 'C': 3},
    'B': {'C': 2, 'D': 4},
    'C': {'D': 1},
    'D': {},
}

start_node = 'A'

distances = dijkstra(graph, start_node)

print(distances)
