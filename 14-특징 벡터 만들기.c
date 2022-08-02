//c�� ���� ���� �ڷᱸ�� (������) 4��
//���뿹�� 14 - Ư¡ ���� �����
//���̵�: ��
//heap�̶�� ��Ʈ�� �־���.
#include <stdio.h>
#include <stdlib.h>
#define MAX 50
#define MAX_FOR_HEAP 2500
/*
�Է� ��� ����
5 3
45 50 29 80 55
62 39 30 82 67
81 54 73 56 90
88 83 71 72 28
66 70 88 91 49

->
81 82 90
88 83 90
88 91 91
*/
//�迭�� ���� ����
int heap[MAX_FOR_HEAP];
int heapsize = 0;

//�ִ� ������ ���� �ֱ�
void insert_heap(int item) {
    heapsize++;
    int i = heapsize;
    //ù ���Ұ� �ƴϰ�(0�� ����д�), �θ��庸�� ũ�ٸ� ���� �ٲ۴�. 
    while (i != 1 && item > heap[i / 2]) {
        heap[i] = heap[i / 2];
        i /= 2;
    }
    heap[i] = item;
    return;
}
//���� �ʱ�ȭ (������ ������ ��Ʈ�θ� �̷������)
void renew_heap() {
    while (heapsize) {
        heap[heapsize] = 0;
        heapsize--;
    }
    return;
}

int main()
{
    int n;
    int m;
    int ary[MAX][MAX];
    int result[MAX - 1][MAX - 1];

    scanf("%d %d", &n, &m);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &ary[i][j]);
        }
    }


    //4�� for���� ���� �߸��Ȱ� ����... ��� ���� �� ������?
    for (int i = 0; i <= n - m + 1; i++) {
        for (int j = 0; j <= n - m + 1; j++) {
            for (int k = i; k <= i + m - 1; k++) {
                for (int l = j; l <= j + m - 1; l++) {
                    insert_heap(ary[k][l]);
                }
            }
            result[i][j] = heap[1];
        }
        renew_heap();
    }
    for (int i = 0; i <= n - m; i++) {
        for (int j = 0; j <= n - m; j++) {
            printf("%d  ", result[i][j]);
        }
        printf("\n");
    }

    return 0;
}

