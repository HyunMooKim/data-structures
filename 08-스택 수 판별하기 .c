//c로 배우는 쉬운 자료구조 (이지영) 4판 
//응용예제 8 - 스택 수 판별하기
//난이도:중    - 알고리즘 힌트가 없다면 굉장히 어려웠을 문제.
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
//q생성
queue* create_queue() {
    queue* q = (queue*)malloc(sizeof(queue));
    q->front = -1;
    q->rear = -1;
    for (int i = 0; i < 20; i++) {
        q->que[i] = 0;
    }
    return q;
}
//스택 생성
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
    //전체 원소 개수 입력
    scanf("%d", &n);
    //원소 입력
    numbers = (int*)calloc(n, sizeof(int));
    for (int i = 0; i < n; i++) { //동적할당은 디버그 로컬 창에 맨앞 변수로만 뜨는듯
        scanf("%d", &numbers[i]);
    }
    //RQ채우기
    for (int i = 1; i <= n; i++) {
        enqueue(RQ, i);
    }

    //cnt는 현재 비교 중인 numbers(입력) index,  now 는 현재 비교하고 있는 RQ index
    while (cnt != n) {

        if (numbers[cnt] > RQ->que[now] && now != n) {//입력보다 작은 수는 push
            push(s, RQ->que[now]);
            now++;
        }
        else if (numbers[cnt] < RQ->que[now] || now == n)    //입력보다 큰 수면 stack에서 뽑는데, 맨 위와 같아야 한다.
        { // 4개-> 4 3 2 1 처럼 마지막 원소가 맨 뒤에 있지 않은 입력의 경우, 남은건 전부 스택에 있으니 스택과 비교
            if (numbers[cnt] != peek(s)) { //가장 최근에 스택에 들어간 수와 다르면, 만들어낼 수 없는 수다.
                printf("impossible");
                return 0;
            }
            else {
                enqueue(LQ, pop(s)); //스택 맨 위 숫자면 pop해서 LQ로 넣는다.
                cnt++;
            }
        }
        else {   //입력 == RQ 
            enqueue(LQ, RQ->que[now]);
            now++;
            cnt++;
        }
    }

    if (s->top != -1) { //모든 작업 후 stack에 수가 남아있다면 불가능한 수
        printf("impossible");
        return 0;
    }

    printf("possible");

    return 0;
}