// Prim's Algorithm in C
#include <stdio.h>
#include <string.h>
#include "header.h"

void prim(int graph[][V], int start) {
    int no_edge;  // number of edge
    int cost = 0;//�ּҺ�� ����
    // create a array to track selected vertex
    // selected will become true otherwise false
    int selected[V];

    //���ڿ��� ���� ���̴� �Լ�
    memset(selected, 0, sizeof(selected));    //������ �ּҷ� ���� �ش� ũŰ��ŭ�� 0���� ä��� ����

    // set number of edge to 0
    no_edge = 0;

    // �������� �ְ� ����
    selected[start] = 1;

    int x;  //  row number
    int y;  //  col number
    // print for edge and weight
    printf("Edge : Weight\n");

    while (no_edge < V - 1) {
        //selected�� ���� s����. �� s�� ������ ��� vertex�� �����Ѵ�.
        //����ġ�� ���� ���� vertex�� �������ҷ� �����Ѵ�.

        int min = INF;
        x = 0;
        y = 0;

        for (int i = 0; i < V; i++) {
            if (selected[i]) {
                for (int j = 0; j < V; j++) {
                    if (!selected[j] && graph[i][j]) {  //�������� �ʾ�����, ������ �����ϴ� ���� ���� ����ġ �ּҸ� ���Ѵ�.
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