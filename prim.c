// Prim's Algorithm in C
#include <stdio.h>
#include <string.h>
#include "header.h"

void prim(int graph[][V], int start) {
    int no_edge;  // number of edge
    int cost = 0;//최소비용 계산용
    // create a array to track selected vertex
    // selected will become true otherwise false
    int selected[V];

    //문자열에 많이 쓰이는 함수
    memset(selected, 0, sizeof(selected));    //적혀진 주소로 가서 해당 크키만큼을 0으로 채우는 구문

    // set number of edge to 0
    no_edge = 0;

    // 시작점을 넣고 시작
    selected[start] = 1;

    int x;  //  row number
    int y;  //  col number
    // print for edge and weight
    printf("Edge : Weight\n");

    while (no_edge < V - 1) {
        //selected가 집합 s역할. 이 s와 인접한 모든 vertex를 검토한다.
        //가중치가 가장 적은 vertex를 다음원소로 결정한다.

        int min = INF;
        x = 0;
        y = 0;

        for (int i = 0; i < V; i++) {
            if (selected[i]) {
                for (int j = 0; j < V; j++) {
                    if (!selected[j] && graph[i][j]) {  //선택하지 않았으며, 간선이 존재하는 인접 정점 가중치 최소를 구한다.
                        if (min > graph[i][j]) {
                            min = graph[i][j];
                            x = i;
                            y = j;
                        }
                    }
                }
            }
        }

        cost = cost + graph[x][y];
        printf("%d(%s) - %d(%s) : %d\n", x, city[x], y, city[y], graph[x][y]);
        selected[y] = 1;
        no_edge++;
    }
    printf("\nminimum spanning tree cost by prim: %d", cost);
    return;
}