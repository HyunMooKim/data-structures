//c�� ���� ���� �ڷᱸ�� (������) 4�� 
//���뿹�� 10 - ���� Ʈ���� ������ �з��϶� 
//���̵�: ��
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
�Է� ����
9
1 ������ �ֳ���?
2 �� �� �ֳ���?
3 ���� �ֳ���?
4 ��ġ
5 ���
6 ���� �����̳���?
7 ������
12 �ٶ���
13 �����ú�
false true false

��� ����
�����ú�
*/
typedef struct node {
    char str[50];
}node;

typedef struct tree {
    node* tree_ary[30];    //��� ���� �ִ� 30��
}tree;

node* create_node(char str[50]) {
    node* temp;
    temp = (node*)malloc(sizeof(node));

    strcpy(temp->str, str);
    return temp;
}

int main()
{
    int n; //��尳��
    int index; //��� �ε���
    char str[50];
    tree t;
    char answer[6];

    for (int i = 0; i < 30; i++) {
        t.tree_ary[i] = NULL;
    }

    //��� ���� �Է�
    scanf("%d", &n);

    //�� ��峻�� �Է�
    for (int i = 0; i < n; i++) {
        scanf("%d", &index);
        scanf("%[^\n]s", str);       //%[^\n]s =  '^' �ڿ����� ����, Ȥ�� ���ڿ��� ��Ÿ�������� �Է�
        t.tree_ary[index] = create_node(str);
        //create node �Լ����� ���� �ּҰ� �ƴ϶� main�Լ����� �����ϸ� �ᱹ ��� Ʈ����尡 �������� temp�� ����� ������ ����Ų��. 
    }
    /*����� �ԷµǾ����� Ȯ���ϴ� ����
    for (int i = 1; i <=index; i++) {
        if(t.tree_ary[i]!=NULL)
            printf("%d - %s \n",i, t.tree_ary[i]->str);
    }
    */

    //�ԷµǴ� ����(true, false)�� ���� ���� �з�
    index = 1;
    do {
        scanf("%s", answer);
        if (strcmp(answer, "true") == 0) {
            index = 2 * index;
        }
        else {
            index = 2 * index + 1;
        }

    } while (t.tree_ary[index * 2] != NULL);

    printf("%s", t.tree_ary[index]->str);

    return 0;
}