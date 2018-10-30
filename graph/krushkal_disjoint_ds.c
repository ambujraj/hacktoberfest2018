// Implementing Krushkal's Algorithm for minimum spanning tree with disjoint set data structure

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 10

typedef struct Edge {
    int node, another_node, weight;
} Edge;

typedef struct EdgeList {
    Edge data[MAX];
    int total_edges;
} EdgeList;

int Graph[MAX][MAX];


int find(int *array, int node1) {
    return *(array + node1);
}

//change all entries from arr[ A ] to arr[ B ].
void _union(int array[], int number_of_nodes, int node1, int node2) {
    for (int i = 0; i < number_of_nodes; i++) {
        if (array[i] == node2)
            array[i] = node1;
    }
}

void sort(EdgeList edge_list) {
    Edge temp;
    for (int i = 1; i < edge_list.total_edges; i++) {
        for (int j = 0; j < edge_list.total_edges - 1; j++)
            if (edge_list.data[j].weight > edge_list.data[j + 1].weight) {
                temp = edge_list.data[j];
                edge_list.data[j] = edge_list.data[j + 1];
                edge_list.data[j + 1] = temp;
            }
    }
}

EdgeList Krushkal(int n) {
    /*
     * n: total number of vertices
     * returns edge list of minimum spanning tree
     *
     * */
    int disjoint_set[MAX], i, j;
    EdgeList edge_list;
    edge_list.total_edges = 0;

    // store adjacency matrix in to EdgeList structure
    for (i = 1; i < n; i++) {
        for (j = 0; j < i; j++) {
            if (i != j){  // skip self loop (if accidental entry)
                if (Graph[i][j] != 0) {  // consider 0 weight as same node/vertices
                    edge_list.data[edge_list.total_edges].node = i;
                    edge_list.data[edge_list.total_edges].another_node = j;
                    edge_list.data[edge_list.total_edges].weight = Graph[i][j];
                    edge_list.total_edges++;  // increase count of total edges
                }
            }
        }
    }

    // sort edges by weight to pick minimum edge
    sort(edge_list);

    for (i = 0; i < n; i++)
        // initialize disjoint set to point at self
        disjoint_set[i] = i;

    EdgeList span_list;
    register int node1, node2;
    span_list.total_edges = 0;

    for (i = 0; i < edge_list.total_edges; i++) {
        node1 = find(disjoint_set, edge_list.data[i].node);
        node2 = find(disjoint_set, edge_list.data[i].another_node);
        if (node1 != node2) {
            span_list.data[span_list.total_edges] = edge_list.data[i];
            span_list.total_edges++;
            _union(disjoint_set, n, node1, node2);
        }
    }
    return span_list;
}

void pretty_print(EdgeList span_list) {
    int cost = 0;
    printf("\nNode\tNode\tWeight");
    for (int i = 0; i < span_list.total_edges; i++) {
        printf("\n%d\t   %d\t   %d", span_list.data[i].node, span_list.data[i].another_node, span_list.data[i].weight);
        cost = cost + span_list.data[i].weight;
    }
    printf("\n\nCost of minimum spanning tree : %d", cost);
}

int main(int argc, char *argv[]) {
    int number_of_vertices = 0;
    int auto_mode = atoi(argv[1]);
    if (auto_mode)
        number_of_vertices = atoi(argv[1]);
    int num;
    int i, j, total_cost;
    printf("\n-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-"
           "\n-*- Krushkal's Algorithm for finding Minimum Spanning Tree....  -*-"
           "\n-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-\n");
    printf("\nEnter number of vertices: ");
    if (!auto_mode)
        scanf("%d", &number_of_vertices);
    else
        printf("%d", number_of_vertices);
    printf("\nEnter the adjacency matrix:\n");
    for (i = 0; i < number_of_vertices; i++) {
        for (j = 0; j < number_of_vertices; j++) {
            if (!auto_mode)
                scanf("%d", &Graph[i][j]);
            else {
                if (i == j) {
                    printf("\t0");
                } else {
                    num = 1 + (rand() % 10);
                    printf("\t%d", num);
                    Graph[i][j] = num;
                }
            }
        }
        if (auto_mode)
            printf("\n");
    }
    printf("\n");

    EdgeList mst_edges;
    mst_edges = Krushkal(number_of_vertices);
    pretty_print(mst_edges);  // print edges picked for MST
    return 1;
}
