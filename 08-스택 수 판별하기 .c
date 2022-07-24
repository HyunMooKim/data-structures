//c�� ���� ���� �ڷᱸ�� (������) 4�� 
//���뿹�� 8 - ���� �� �Ǻ��ϱ�
//���̵�:��    - �˰��� ��Ʈ�� ���ٸ� ������ ������� ����.
#include <stdio.h>
#include <stdlib.h>

typedef struct queue {
    int que[20];
    int front, rear;
}queue;

typedef struct stack {
    int stack[20];
    int top;
}stack;
//q����
queue* create_queue() {
    queue* q = (queue*)malloc(sizeof(queue));
    q->front = -1;
    q->rear = -1;
    for (int i = 0; i < 20; i++) {
        q->que[i] = 0;
    }
    return q;
}
//���� ����
stack* create_stack() {
    stack* s = (stack*)malloc(sizeof(stack));
    s->top = -1;
    for (int i = 0; i < 20; i++) {
        s->stack[i] = 0;
    }
    return s;
}
//enqueue
void enqueue(queue* q, int v) {
    if (q->rear != -1 && q->rear == q->front) {
        printf("full!");
        return;
    }
    q->rear++;
    q->que[q->rear] = v;
    return;
}
//dequeue
int dequeue(queue* q) {
    if (q->rear == q->front) {
        printf("empty!");
    }
    q->front++;

    return q->que[q->front];
}

//push
void push(stack* s, int v) {
    if (s->top == 19) return;   //overflow 
    s->top++;
    s->stack[s->top] = v;
    return;
}
//pop
int pop(stack* s) {
    if (s->top == -1) return 0; //underflow
    s->top = s->top - 1;
    return s->stack[s->top + 1];
}
//peek
int peek(stack* s) {
    if (s->top == -1) return 0;
    return s->stack[s->top];
}

int main()
{
    int* numbers;
    int n;
    int cnt = 0;
    int now = 0;
    queue* RQ, * LQ;
    stack* s;

    RQ = create_queue();
    LQ = create_queue();
    s = create_stack();
    //��ü ���� ���� �Է�
    scanf("%d", &n);
    //���� �Է�
    numbers = (int*)calloc(n, sizeof(int));
    for (int i = 0; i < n; i++) { //�����Ҵ��� ����� ���� â�� �Ǿ� �����θ� �ߴµ�
        scanf("%d", &numbers[i]);
    }
    //RQä���
    for (int i = 1; i <= n; i++) {
        enqueue(RQ, i);
    }

    //cnt�� ���� �� ���� numbers(�Է�) index,  now �� ���� ���ϰ� �ִ� RQ index
    while (cnt != n) {

        if (numbers[cnt] > RQ->que[now] && now != n) {//�Էº��� ���� ���� push
            push(s, RQ->que[now]);
            now++;
        }
        else if (numbers[cnt] < RQ->que[now] || now == n)    //�Էº��� ū ���� stack���� �̴µ�, �� ���� ���ƾ� �Ѵ�.
        { // 4��-> 4 3 2 1 ó�� ������ ���Ұ� �� �ڿ� ���� ���� �Է��� ���, ������ ���� ���ÿ� ������ ���ð� ��
            if (numbers[cnt] != peek(s)) { //���� �ֱٿ� ���ÿ� �� ���� �ٸ���, ���� �� ���� ����.
                printf("impossible");
                return 0;
            }
            else {
                enqueue(LQ, pop(s)); //���� �� �� ���ڸ� pop�ؼ� LQ�� �ִ´�.
                cnt++;
            }
        }
        else {   //�Է� == RQ 
            enqueue(LQ, RQ->que[now]);
            now++;
            cnt++;
        }
    }

    if (s->top != -1) { //��� �۾� �� stack�� ���� �����ִٸ� �Ұ����� ��
        printf("impossible");
        return 0;
    }

    printf("possible");

    return 0;
}