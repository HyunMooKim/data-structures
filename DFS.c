#include <stdio.h>
#include <stdlib.h>
#include "header.h"

char* city[10] = { "서울","천안","원주","논산","대전","대구","강릉","광주","부산","포항" };

// DFS algo
void DFS(struct Graph* graph, int vertex) {
    struct node* adjList = graph->adjLists[vertex];
    struct node* temp = adjList;
    static int cnt = 0;
    graph->visited[vertex] = 1;
    //printf("Visited %d \n", vertex);
    cnt++;
    if (cnt < graph->numVertices)        // 마지막 원소 뒤에 -> 를 뺴기 위한 cnt
        printf("%d(%s) -> ", vertex, city[vertex]);
    else
        printf("%d(%s)", vertex, city[vertex]);

    while (temp != NULL) {
        int connectedVertex = temp->vertex;

        if (graph->visited[connectedVertex] == 0) {
            DFS(graph, connectedVertex);
        }
        temp = temp->next;
    }
}

// Create a node
struct node* createNode(int v) {
    struct node* nNode = malloc(sizeof(struct node));
    nNode->vertex = v;
    nNode->next = NULL;
    return nNode;
}

// Create graph
struct Graph* createGraph(int vertices) {
    struct Graph* graph = malloc(sizeof(struct Graph));
    graph->numVertices = vertices;

    graph->adjLists = malloc(vertices * sizeof(struct node*));

    graph->visited = malloc(vertices * sizeof(int));

    int i;
    for (i = 0; i < vertices; i++) {
        graph->adjLists[i] = NULL;
        graph->visited[i] = 0;
    }
    return graph;
}

// Add edge
void addEdge(struct Graph* graph, int src, int dest) {
    // Add edge from src to dest
    struct node* newNode = createNode(dest);
    newNode->next = graph->adjLists[src];
    graph->adjLists[src] = newNode;

    // Add edge from dest to src
    newNode = createNode(src);
    newNode->next = graph->adjLists[dest];
    graph->adjLists[dest] = newNode;
}

// Print the graph
void printGraph(struct Graph* graph) {
    int v;
    for (v = 0; v < graph->numVertices; v++) {
        struct node* temp = graph->adjLists[v];
        printf("\n Adjacency list of vertex %d\n ", v);
        while (temp) {

            printf("%d -> ", temp->vertex);
            temp = temp->next;
        }
        printf("\n");
    }
}
