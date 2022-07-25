#include <stdio.h>
#include <stdlib.h>
#include "header.h" 

int main()
{
	printf("HyUN_MOO\n\n");

    //그래프 생성:  DFS/BFS 는 linked list로 구현
    struct Graph* graph = createGraph(10);
    addEdge(graph, 0, 1);  // 양방향 모두 추가된다.
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
    for (int i = 0; i < 10; i++) {      //visited 초기화 후 BFS 진행
        graph->visited[i] = 0;
    }
    bfs(graph, 0);


    //그래프 생성 prim과 kruskal은 2차원 배열로 구현한다.
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
    prim(grap, 0);               //0(서울)부터 

    printf("\n\n============================KRUSKAL============================\n");
    kruskalAlgo(grap);
    print();


    printf("\n============================DIJKSTRA============================\n");
    Dijkstra(grap, 0);

    printf("\n============================FlOYDWARSHALL============================\n");
    floydWarshall(grap);   //전체를 출력하고  동시에 6번 문제인 from 서울 to 부산 의 루트까지 한번에 처리 
                                  //0은 서울 8이 부산 


    printf("\n============================shortist way============================\n");
    
    printpath_all();

	return 0; 
}