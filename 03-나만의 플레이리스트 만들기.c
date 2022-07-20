//c�� ���� ���� �ڷᱸ�� (������) 4�� 
//���뿹�� 3 - ������ �÷��� ����Ʈ �����
//���̵�: ��~��
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    char title;
    struct node* link;
}node;

typedef struct playlist {
    node* head;
}playlist;

//����Ʈ�� �뷡 �߰��ϴ� �Լ�
void insert_node(playlist* a, char song) {
    //ó���� �ٷ� list���� ���� 0�̸� a->head->title = song; ������, head �ּҿ� �ƹ��͵� ���� title�� ���� �Ұ� 
    //���� �߻����� ���׿���.
    node* p = a->head;
    node* new;
    new = (node*)malloc(sizeof(node));
    new->title = song;
    new->link = NULL;
    if (a->head == NULL) {
        a->head = new;
        return;
    }
    while (p->link) p = p->link;
    p->link = new;
    return;
}

//�ִ� �뷡�� 1�� ��ȯ�ϴ� �Լ�
int find_target(playlist* a, char title) {
    node* p = NULL;
    p = a->head;
    while (p->link != NULL) { //p �� �ƴ϶� p->link�� NULL ���� �����Ѵ�.
        if (p->title == title) {
            return 1;
        }
        p = p->link;
    }
    return 0;
}

//����Ʈ ����Լ�
void print_list(playlist* a) {

    node* p = NULL;
    p = a->head;
    while (p != NULL) {
        printf("%c ", p->title);
        p = p->link;
    }

    return;
}

int main()
{
    playlist* all;
    playlist* selected;
    node* p = NULL;
    int n;//��ü ����
    int k;//�ݺ�����
    char target;
    int dif = 0;

    //��ü����Ʈ�� �ݺ�����Ʈ ����
    all = (playlist*)malloc(sizeof(playlist));
    selected = (playlist*)malloc(sizeof(playlist));
    all->head = NULL;
    selected->head = NULL;

    //��ü ���� �ޱ�
    scanf("%d", &n);

    //�÷��̸���Ʈ ��ü ����
    dif = 'A';//�ƽ�Ű�ڵ�
    for (int i = 0; i < n; i++) {
        insert_node(all, i + dif);   //'A'���� ���ʷ� �Է�
    }

    // ��� �ݺ� ����Ʈ�� �������� �Է�
    scanf("%d", &k);
    getchar();

    //�ִ� �뷡�� �ݺ� ����Ʈ�� �߰�
    for (int i = 0; i < k; i++) {
        scanf("%c", &target);
        getchar();  //���鵵 ���ڷ� �νĵǾ �� ���� �ʾ���.
        if (find_target(all, target) == 1) {
            insert_node(selected, target);
        }
        else ("error");
    }

    printf("palylist: ");
    print_list(all);

    printf("\nselected list: ");
    print_list(selected);


    // ����(�ݺ�)���� ����� 
    p = selected->head;
    while (p->link != NULL) {
        p = p->link;
    }
    p->link = selected->head;
    return 0;
}