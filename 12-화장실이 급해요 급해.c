//c로 배우는 쉬운 자료구조 (이지영) 4판
//응용예제 12 - 화장실이 급해요, 급해!
//난이도: 중
#include <stdio.h>
#include <stdlib.h>
#define max 50
#define INF 51
//다익스트라 알고리즘을 위한 distance배열, 간선 배열 weight, 방문여부 확인 집합 s
int distance[max];
int s[max];
int weight[max][max];

//경로 갱신을 기록하기 위한 배열
int record[max] = { 0 };

//경로 저장용 스택
typedef struct path {
    int from;
    int to;
}path;

typedef struct stack {
    path* stack[max]; //반환값이 두개니 주소이용
    int top;
}stack;
//스택 생성
stack* create_stack() {
    stack* s = (stack*)malloc(sizeof(stack));
    s->top = -1;
    for (int i = 0; i < max; i++) {
        s->stack[i] = NULL;
    }
    return s;
}
//push
void push(stack* s, int from, int to) {
    if (s->top == max - 1) {
        printf("overflow");
        return;
    }//overflow 
    s->top++;
    /* 예외발생!
    (s->stack[s->top])->from = from;
    (s->stack[s->top])->to = to;
    */
    path* p = (path*)malloc(sizeof(path));
    p->from = from;
    p->to = to;
    s->stack[s->top] = p;
    
    return;
}
//pop
path* pop(stack* s) {
    if (s->top == -1) return 0; //underflow
    s->top = s->top - 1;
    return s->stack[s->top + 1];
}

int next_vertex(int n) {
    int min;
    int index;
    min = INF;
    for (int i = 0; i < n; i++) {
        if ((distance[i] < min) && (s[i] == 0)) {
            min = distance[i];
            index = i;
        }
    }
    return index;
}

void dijkstra(int start, int n) {
    //초기화 작업 및 시작점 방문 
    for (int i = 0; i < n; i++) {
        distance[i] = weight[start][i];
        s[i] = 0;
    }

    s[start] = 1;
    distance[start] = 0;
    for (int i = 0; i < n - 1; i++) { //마지막은 그냥 정해지니 n-1번 수행
        int u = next_vertex(n);
        s[u] = 1;
        for (int w = 0; w < n; w++) {
            if (s[w] == 0) {
                if (distance[w] > distance[u] + weight[u][w]) {
                    distance[w] = distance[u] + weight[u][w];
                    //갱신 될때마다 어디를 거쳐서 가는걸로 갱신되었는지 기록
                    record[w] = u;
                }
            }
        }
    }

    return;
}

int main()
{
    int n;
    int m;
    int i, j;
    int temp = 0;
    path* p = NULL;
    stack* s = create_stack();

    //총 위치 개수와 간선 개수
    scanf("%d %d", &n, &m);

    //우선 그래프 정점 서로간의 연결을 초기화
    for (int k = 0; k < n; k++) {
        for (int l = 0; l < n; l++) {
            if (k != l) weight[k][l] = INF;
            else weight[k][l] = 0;
        }
    }
    //그래프 간선 입력받기
    for (int k = 0; k < m; k++) {
        scanf("%d %d", &i, &j);
        weight[i-1][j-1] = 1;   //실제 index는 1->0 으로 -1씩 해준다. 
    }

    //현재 위치 1 (index상으로는 0), 화장실 위치 n -> 이건 함수에서 그냥 n-1까지로 처리함
    dijkstra(0, n);
    

    for (i = n - 1; i != 0; i = record[i] ) {
        //목표점부터  (거쳐가는 지점, 해당지점) 을 반복 push
        push(s, record[i], i);        
    }

    while (s->top != -1) {
        p = pop(s);
        printf("(%d, %d)\n", p->from+1, p->to+1);
    }

    return 0;
}
