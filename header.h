#pragma once
#define SIZE 40 // BFS 
#define MAX 90 // kruskal
#define INF 99999 // PRIM과 floyd 등에 쓰인 무한대 
#define V 10 //모든 함수에 쓰인 vertex 개수


//////////////////////DFS 헤더 ///////////////////////
char* city[10];  // 각 도시의 index에 따른 이름을 저장해놓은 배열로, 모든 문제 출력에 쓰인다. 

struct node {
    int vertex;
    struct node* next;
};
struct node* createNode(int v);
struct Graph {
    int numVertices;
    struct node** adjLists;
    int* visited;

};

void DFS(struct Graph* graph, int vertex);
struct node* createNode(int v);
struct Graph* createGraph(int vertices);
void addEdge(struct Graph* graph, int src, int dest);
void printGraph(struct Graph* graph);


//////////////////////BFS 헤더 ///////////////////////

struct queue {
    int items[SIZE];
    int front;
    int rear;
};

struct queue* createQueue();
void enqueue(struct queue* q, int);
int dequeue(struct queue* q);
int isEmpty(struct queue* q);
void bfs(struct Graph* graph, int startVertex);

//////////////////////prim 헤더 ///////////////////////
void prim(int graph[][V], int start);




//////////////////////kruskal 헤더 ///////////////////////
typedef struct edge {
    int u, v, w;
} edge;

typedef struct edge_list {
    edge data[MAX];  //간선 개수는 10개보다 많을 수 있다.
    int n;
} edge_list;

void kruskalAlgo(int Graph[][V]);
int find(int belongs[], int vertexno);
void applyUnion(int belongs[], int c1, int c2);
void sort();
void print();


//////////////////////dijkstra 헤더 ///////////////////////

void Dijkstra(int Graph[][V], int start);


//////////////////////floydwarshall 헤더 ///////////////////////
void printMatrix(int graph[][V]);
void floydWarshall(int graph[][V] );
void printpath(int from, int to);
void printpath_all();