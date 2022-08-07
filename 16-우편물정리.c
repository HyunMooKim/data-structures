//c�� ���� ���� �ڷᱸ�� (������) 4��
//���뿹�� 16 - ���� ����
//���̵�: ��
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 99

typedef struct mail {
    char str[5];
    struct mail* next;
}mail;
mail hash_table[2][MAX] = {0};

//ȣ���� ������ �ؽ� ���̺� �Է�
void insert(char str[5], int flo, int room_n) {
    mail* new = (mail *) malloc(sizeof(mail));
    mail* m = &hash_table[flo - 6][(room_n)];
   
    //�ֱ� �߰��� ���� ������ ������ �̵�
    while ( m->next != NULL) {
        m = (m->next);
    }
    strcpy(new->str, str);
    new->next = NULL;
    (*m).next = new;
    return;
}

//612A ��� 12�� ��ȯ�ϴ� �Լ�
int roon_num(char str[5]) {
    int where;
    where = (int) str[1] - '0'; //�ƽ�Ű�ڵ带 ���־�� �Ѵ�.
    where = where *10;
    where = where + (int) str[2] - '0';
    return where;
}
int main()
{
    int n;
    int m;
    int floor_number;
    int room_number;
    int where;
    mail mp;
    char temp[5];
    //�繫�� ������ ���� ����
    scanf("%d %d", &n, &m);
    //�繫�� ������ŭ �ؽ� ���̺� ����

   //�Է� ������ ����
    for (int i = 0; i < m; i++) {
        scanf("%s", temp);
        //�� ȣ ���� ����
        where = roon_num(temp) % n;
        //6�� or 7��
        if (temp[0] == '6') {
            insert(temp, 6, where);
        }
        else {
            insert(temp, 7, where);
        }
    }

    //����� ���� �ּ�
    scanf("%d", &where);
    floor_number = where / 100;
    where = where % 100;
    room_number = where % n;
    mp= hash_table[floor_number - 6][room_number];
    
    while ( mp.next!= NULL) {
        printf("%s ", (mp.next)->str);
        mp = *(mp.next);
    }
   
    return 0;
}
