//c�� ���� ���� �ڷᱸ�� (������) 4�� 
//���뿹�� 5 - �ɺ� ���� ������ ������?
//���̵�: ��-��
#include <stdio.h>
#include <stdlib.h>
/*
�Է� ����
0 0 0 0 0 0 0 2 0 4 2 0 5 3 1
30 20 40 10 20
5 1, 3 5, 3 2, 2 3, 4 2, 3 4, 5 4, 5 3, 2 1, 1 3

��¿���
270�� , 140��, 40��, 50��, 160��
*/
//�� ����
typedef struct stack {
    int point;
    int ary[10];
    int top; // top = -1 ���⼭ �ϸ� �ȵȴ�. 
}stack;

//���� ���θ� ��Ƶ� game ����ü
typedef struct game {
    stack* all_ary[5];
}game;

//���� ���� �Լ�
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
    int total = 0; //����
    //���û���
    stack* one, * two, * three, * four, * five;
    one = create_stack();
    two = create_stack();
    three = create_stack();
    four = create_stack();
    five = create_stack();

    //game����ü�� ���� �ֱ�
    game g;
    g.all_ary[0] = one;
    g.all_ary[1] = two;
    g.all_ary[2] = three;
    g.all_ary[3] = four;
    g.all_ary[4] = five;

    //�⺻���� �Է�
    for (int i = 2; i >= 0; i--) {
        for (int j = 0; j < 5; j++) {
            scanf("%d", &ball);             
            if (ball != 0) {                // 0�� ���ΰ� �ǹ��ִ� �����϶� top�� ���� ��� 
                g.all_ary[j]->ary[i] = ball;
                g.all_ary[j]->top = g.all_ary[j]->top + 1;
            }
        }
    } //one 2�� ĭ-> two 2��ĭ �̷������� five�� 0�� ĭ���� 


    for (int i = 0; i < 5; i++) {
        scanf("%d", &(g.all_ary[i]->point));
    } //one~five �� ���� 1���� �������� ���� �Է�

    // ���� ƨ�� �ֱ� ����
    while (f) {

        scanf("%d %d", &ball, &stack_n);
        //������ ���ٸ� pop
        if (peek(g.all_ary[stack_n - 1]) == ball) {
            pop(g.all_ary[stack_n - 1]);
        }
        //�ƴ϶�� push
        else {
            push(g.all_ary[stack_n - 1], ball);
        }

        //�Է��� ��ӵȴٸ� , �� ���´�
        comma = getchar();
        if (comma != ',') {
            f = 0;
        }
    }


    //���� �ջ�
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j <= g.all_ary[i]->top; j++) {
            total = total + g.all_ary[i]->ary[j];   //���� ���ڸ� �� ���ϰ�
        }
        total = total * g.all_ary[i]->point; // ���� ������ ����ġ ������ŭ ���Ѵ�
        printf("%d�� ", total);
        total = 0;
    }


    return 0;
}
