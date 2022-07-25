#pragma once
#define SIZE 40 // BFS 
#define MAX 90 // kruskal
#define INF 99999 // PRIM�� floyd � ���� ���Ѵ� 
#define V 10 //��� �Լ��� ���� vertex ����


//////////////////////DFS ��� ///////////////////////
char* city[10];  // �� ������ index�� ���� �̸��� �����س��� �迭��, ��� ���� ��¿� ���δ�. 

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


//////////////////////BFS ��� ///////////////////////

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

//////////////////////prim ��� ///////////////////////
void prim(int graph[][V], int start);




//////////////////////kruskal ��� ///////////////////////
typedef struct edge {
    int u, v, w;
} edge;

typedef struct edge_list {
    edge data[MAX];  //���� ������ 10������ ���� �� �ִ�.
    int n;
} edge_list;

void kruskalAlgo(int Graph[][V]);
int find(int belongs[], int vertexno);
void applyUnion(int belongs[], int c1, int c2);
void sort();
void print();


//////////////////////dijkstra ��� ///////////////////////

void Dijkstra(int Graph[][V], int start);


//////////////////////floydwarshall ��� ///////////////////////
void printMatrix(int graph[][V]);
void floydWarshall(int graph[][V] );
void printpath(int from, int to);
void printpath_all();