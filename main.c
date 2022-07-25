#include <stdio.h>
#include <stdlib.h>
#include "header.h" 

int main()
{
	printf("HyUN_MOO\n\n");

    //�׷��� ����:  DFS/BFS �� linked list�� ����
    struct Graph* graph = createGraph(10);
    addEdge(graph, 0, 1);  // ����� ��� �߰��ȴ�.
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 1, 4);
    addEdge(graph, 2, 5);
    addEdge(graph, 2, 6);
    addEdge(graph, 3, 4);
    addEdge(graph, 3, 7);
    addEdge(graph, 4, 5);
    addEdge(graph, 5, 8);
    addEdge(graph, 5, 9);
    addEdge(graph, 6, 9);
    addEdge(graph, 7, 8);
    addEdge(graph, 8, 9);
    printf("============================DFS============================\n\n");
    DFS(graph, 0);

    printf("\n\n============================BFS============================\n\n");
    for (int i = 0; i < 10; i++) {      //visited �ʱ�ȭ �� BFS ����
        graph->visited[i] = 0;
    }
    bfs(graph, 0);


    //�׷��� ���� prim�� kruskal�� 2���� �迭�� �����Ѵ�.
    int grap[][V] = {
        {0,12,15,0,0,0,0,0,0,0},
        {12,0,0,4,10,0,0,0,0,0},
        {15,0,0,0,0,7,21,0,0,0},
        {0,4,0,0,3,0,0,13,0,0},
        {0,10,0,3,0,10,0,0,0,0},
        {0,0,7,0,10,0,0,0,9,19},
        {0,0,21,0,0,0,0,0,0,25},
        {0,0,0,13,0,0,0,0,15,0},
        {0,0,0,0,0,9,0,15,0,5},
        {0,0,0,0,0,19,25,0,5,0}
    };
    printf("\n\n============================PRIM============================\n\n");
    prim(grap, 0);               //0(����)���� 

    printf("\n\n============================KRUSKAL============================\n");
    kruskalAlgo(grap);
    print();


    printf("\n============================DIJKSTRA============================\n");
    Dijkstra(grap, 0);

    printf("\n============================FlOYDWARSHALL============================\n");
    floydWarshall(grap);   //��ü�� ����ϰ�  ���ÿ� 6�� ������ from ���� to �λ� �� ��Ʈ���� �ѹ��� ó�� 
                                  //0�� ���� 8�� �λ� 


    printf("\n============================shortist way============================\n");
    
    printpath_all();

	return 0; 
}