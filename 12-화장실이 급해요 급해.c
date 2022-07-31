//c�� ���� ���� �ڷᱸ�� (������) 4��
//���뿹�� 12 - ȭ����� ���ؿ�, ����!
//���̵�: ��
#include <stdio.h>
#include <stdlib.h>
#define max 50
#define INF 51
//���ͽ�Ʈ�� �˰����� ���� distance�迭, ���� �迭 weight, �湮���� Ȯ�� ���� s
int distance[max];
int s[max];
int weight[max][max];

//��� ������ ����ϱ� ���� �迭
int record[max] = { 0 };

//��� ����� ����
typedef struct path {
    int from;
    int to;
}path;

typedef struct stack {
    path* stack[max]; //��ȯ���� �ΰ��� �ּ��̿�
    int top;
}stack;
//���� ����
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
    /* ���ܹ߻�!
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
    //�ʱ�ȭ �۾� �� ������ �湮 
    for (int i = 0; i < n; i++) {
        distance[i] = weight[start][i];
        s[i] = 0;
    }

    s[start] = 1;
    distance[start] = 0;
    for (int i = 0; i < n - 1; i++) { //�������� �׳� �������� n-1�� ����
        int u = next_vertex(n);
        s[u] = 1;
        for (int w = 0; w < n; w++) {
            if (s[w] == 0) {
                if (distance[w] > distance[u] + weight[u][w]) {
                    distance[w] = distance[u] + weight[u][w];
                    //���� �ɶ����� ��� ���ļ� ���°ɷ� ���ŵǾ����� ���
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

    //�� ��ġ ������ ���� ����
    scanf("%d %d", &n, &m);

    //�켱 �׷��� ���� ���ΰ��� ������ �ʱ�ȭ
    for (int k = 0; k < n; k++) {
        for (int l = 0; l < n; l++) {
            if (k != l) weight[k][l] = INF;
            else weight[k][l] = 0;
        }
    }
    //�׷��� ���� �Է¹ޱ�
    for (int k = 0; k < m; k++) {
        scanf("%d %d", &i, &j);
        weight[i-1][j-1] = 1;   //���� index�� 1->0 ���� -1�� ���ش�. 
    }

    //���� ��ġ 1 (index�����δ� 0), ȭ��� ��ġ n -> �̰� �Լ����� �׳� n-1������ ó����
    dijkstra(0, n);
    

    for (i = n - 1; i != 0; i = record[i] ) {
        //��ǥ������  (���İ��� ����, �ش�����) �� �ݺ� push
        push(s, record[i], i);        
    }

    while (s->top != -1) {
        p = pop(s);
        printf("(%d, %d)\n", p->from+1, p->to+1);
    }

    return 0;
}
