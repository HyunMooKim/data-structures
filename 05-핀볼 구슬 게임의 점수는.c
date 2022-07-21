//c로 배우는 쉬운 자료구조 (이지영) 4판 
//응용예제 5 - 핀볼 구슬 게임의 점수는?
//난이도: 하-중
#include <stdio.h>
#include <stdlib.h>
/*
입력 예시
0 0 0 0 0 0 0 2 0 4 2 0 5 3 1
30 20 40 10 20
5 1, 3 5, 3 2, 2 3, 4 2, 3 4, 5 4, 5 3, 2 1, 1 3

출력예시
270점 , 140점, 40점, 50점, 160점
*/
//각 스택
typedef struct stack {
    int point;
    int ary[10];
    int top; // top = -1 여기서 하면 안된다. 
}stack;

//스택 전부를 모아둔 game 구조체
typedef struct game {
    stack* all_ary[5];
}game;

//스택 생성 함수
stack* create_stack() {
    stack* s = (stack*)malloc(sizeof(stack));
    s->top = -1;
    for (int i = 0; i < 10; i++) {
        s->ary[i] = 0;
    }
    return s;
}


void push(stack* s, int v) {
    if (s->top == 9) return;   //overflow 
    s->top++;
    s->ary[s->top] = v;
    return;
}

void pop(stack* s) {
    if (s->top == -1) return; //underflow
    s->top = s->top - 1;
}

int peek(stack* s) {
    if (s->top == -1) return 0;
    return s->ary[s->top];
}

int main()
{
    int f = 1; //flag
    char comma;
    int ball, stack_n;
    int total = 0; //점수
    //스택생성
    stack* one, * two, * three, * four, * five;
    one = create_stack();
    two = create_stack();
    three = create_stack();
    four = create_stack();
    five = create_stack();

    //game구조체에 스택 넣기
    game g;
    g.all_ary[0] = one;
    g.all_ary[1] = two;
    g.all_ary[2] = three;
    g.all_ary[3] = four;
    g.all_ary[4] = five;

    //기본상태 입력
    for (int i = 2; i >= 0; i--) {
        for (int j = 0; j < 5; j++) {
            scanf("%d", &ball);             
            if (ball != 0) {                // 0은 냅두고 의미있는 숫자일때 top과 같이 기록 
                g.all_ary[j]->ary[i] = ball;
                g.all_ary[j]->top = g.all_ary[j]->top + 1;
            }
        }
    } //one 2번 칸-> two 2번칸 이런식으로 five의 0번 칸까지 


    for (int i = 0; i < 5; i++) {
        scanf("%d", &(g.all_ary[i]->point));
    } //one~five 의 구슬 1점당 곱해지는 점수 입력

    // 구슬 튕겨 넣기 시작
    while (f) {

        scanf("%d %d", &ball, &stack_n);
        //맨위와 같다면 pop
        if (peek(g.all_ary[stack_n - 1]) == ball) {
            pop(g.all_ary[stack_n - 1]);
        }
        //아니라면 push
        else {
            push(g.all_ary[stack_n - 1], ball);
        }

        //입력이 계속된다면 , 가 나온다
        comma = getchar();
        if (comma != ',') {
            f = 0;
        }
    }


    //점수 합산
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j <= g.all_ary[i]->top; j++) {
            total = total + g.all_ary[i]->ary[j];   //구슬 숫자를 다 합하고
        }
        total = total * g.all_ary[i]->point; // 각각 정해진 가중치 점수만큼 곱한다
        printf("%d점 ", total);
        total = 0;
    }


    return 0;
}
