// Floyd-Warshall Algorithm in C
#include <stdio.h>
#include "header.h"

// defining the number of vertices
// Implementing floyd warshall algorithm

// Implementing floyd warshall algorithm
int path[V][V] = { 0 };

void floydWarshall(int graph[][V]) {
    int matrix[V][V], i, j, k;

    for (i = 0; i < V; i++)
        for (j = 0; j < V; j++) {
            path[i][j] = -1; //-1 �� �ٸ� ���� ��ġ�� �ʰ� �ٷ� �� �� �ִٴ� ��
            matrix[i][j] = graph[i][j];
            if (matrix[i][j] == 0 && (i != j))// ���⼱ �ڱ� �ڽ����� �̵��ϴ� �� �ܿ��� 0�� INF�� �ٲپ��ִ� �۾��� �ʿ��ϴ�. �ƴϸ� ���� 0�� ���
            {
                matrix[i][j] = INF;
            }
        }

    // Adding vertices individually
    for (k = 0; k < V; k++) {
        for (i = 0; i < V; i++) {
            for (j = 0; j < V; j++) {
                if (matrix[i][k] + matrix[k][j] < matrix[i][j]) {
                    matrix[i][j] = matrix[i][k] + matrix[k][j];
                    path[i][j] = k;
                }
            }
        }
    }
    printMatrix(matrix);

    return;
}


void printpath(int from, int to) {
    if (path[from][to] != -1){
        printpath(from, path[from][to]);
        printf("%s->", city[path[from][to]]);
        printpath(path[from][to], to);
    }
    return;
}

void printpath_all() {
    for (int i = 0; i < V; i++) {
       
        for (int j = 0; j < V; j++) {
            if (i != j) {
                printf("%s->", city[i]);
                printpath(i, j);
                printf("%s\n", city[j]);
            }
            
        }
    }
    return;
}

void printMatrix(int matrix[][V]) {
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            if (matrix[i][j] == INF){
                printf("%4s", "INF");
            }
            else {
                printf("%4d", matrix[i][j]);
            }
        }
        printf("\n");
    }
}
