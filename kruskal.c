// Kruskal's algorithm in C
#include <stdio.h>
#include "header.h"

edge_list elist;
edge_list spanlist;

// Applying Krushkal Algo
void kruskalAlgo(int Graph[][V]) {
    int belongs[MAX], i, j, cno1, cno2;
    elist.n = 0;
    int n = V;

    for (i = 1; i < n; i++)         // metrix의 오른쪽 아래 삼각형을 통해 edge확인
        for (j = 0; j < i; j++) {
            if (Graph[i][j] != 0) {
                elist.data[elist.n].u = i;
                elist.data[elist.n].v = j;
                elist.data[elist.n].w = Graph[i][j];
                elist.n++;
            }
        }

    sort(); //정렬해서 낮은것부터 간선 추가

    for (i = 0; i < n; i++)
        belongs[i] = i;

    spanlist.n = 0;

    for (i = 0; i < elist.n; i++) {
        cno1 = find(belongs, elist.data[i].u);
        cno2 = find(belongs, elist.data[i].v);

        if (cno1 != cno2) {     //출발 vertex != 도착 vertex
            spanlist.data[spanlist.n] = elist.data[i];
            spanlist.n = spanlist.n + 1;
            applyUnion(belongs, cno1, cno2);
        }
    }
}

int find(int belongs[], int vertexno) {
    return (belongs[vertexno]);
}

void applyUnion(int belongs[], int c1, int c2) {
    int i;
    for (i = 0; i < V; i++)
        if (belongs[i] == c2)
            belongs[i] = c1;
}

// Sorting algo
void sort() {
    int i, j;
    edge temp;

    for (i = 1; i < elist.n; i++)
        for (j = 0; j < elist.n - 1; j++)  //내림차순 버블정렬
            if (elist.data[j].w > elist.data[j + 1].w) {
                temp = elist.data[j];
                elist.data[j] = elist.data[j + 1];
                elist.data[j + 1] = temp;
            }
}

// Printing the result
void print() {
    int i, cost = 0;
    int x, y;
    printf("Edge : Weight\n");
    for (i = 0; i < spanlist.n; i++) {
        x = spanlist.data[i].u;
        y = spanlist.data[i].v;
        printf("%d(%s) - %d(%s) : %d\n", x, city[x], y, city[y], spanlist.data[i].w);
        cost = cost + spanlist.data[i].w;
    }

    printf("\nminimum spanning tree cost by kruskal: %d\n\n", cost);
}
