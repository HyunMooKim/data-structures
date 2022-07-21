//c�� ���� ���� �ڷᱸ�� (������) 4�� 
//���뿹�� 4 - �������ڸ� �����!
//���̵�: ��~��
#include <stdio.h>
#include <stdlib.h>

//�������� 
typedef struct node {
    int n; //���� �� ����
    int f; //�湮 ����
    struct node* next;
}node;
//�������ڷ� �̷���� ���� ����Ʈ
typedef struct circle {
    node* node_ary[10];
}circle;

//�������� �߰�
void insert_node(circle* c, int n) {
    int i = 0;
    node* w = (node*)malloc(sizeof(node));
    w->n = n;
    w->f = 0;
    if (c->node_ary[0] == NULL) {
        w->next = NULL;
        c->node_ary[0] = w;
        return;
    }
    while (c->node_ary[i] != NULL) i++;
    c->node_ary[i] = w;
    return;
}


int main()
{
    int N;
    int value;
    int cnt = 0; //��µ� ���� 
    int sign = 0; //��ȣ Ȯ��
    int now = 0; //index
    circle* c = (circle*)malloc(sizeof(circle));
    
    //box ���� - �ִ� 10��
    scanf("%d", &N);

    //�� �������ھ��� ���� �Է�
    for (int i = 0; i < N; i++) {
        c->node_ary[i] = NULL; //�ʱ�ȭ
        scanf("%d", &value);
        insert_node(c, value);
    }

    /* �� �ԷµǾ����� Ȯ���ϴ� ���� 
    for (int i = 0; i < N; i++) {
        printf("%d��° ��� :  %d\n",i, c->node_ary[i]->n);
    }
    */

    printf("%d ", now + 1);  //������ =1 ���
    cnt++;
     //��� ���ڸ� ����� ������ �ݺ�
    while (cnt != N) { 
        c->node_ary[now]->f = 1; //�湮ó��

        //������ -1 ����� 1���
        if (c->node_ary[now]->n > 0) sign = 1;
        else sign = -1;

        now = (now + c->node_ary[now]->n) % N;   //�����ִ� ���ڸ�ŭ �̵�

        while (now < 0) now = now + 6;   //�����ΰ��� ����� �ٲ��ش�. ex) -1 => 5�� ����

        while (c->node_ary[now]->f == 1) {   //�湮�� ���ڸ� �ǳ� �ڴ�.
            if (sign == 1)
                now = (now + 1) % N;    
            else
                now = (now - 1) % N;
            while (now < 0) now = now + 6;   //�����ΰ��� ����� �ٲ��ش�. ex) -1 => 5�� ����
        }

        printf("%d ", now + 1);
        cnt++;
    }


    return 0;
}
