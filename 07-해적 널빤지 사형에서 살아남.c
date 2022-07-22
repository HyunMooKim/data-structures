//c�� ���� ���� �ڷᱸ�� (������) 4�� 
//���뿹�� 7 - ���� �κ��� �������� ��Ƴ���
//���̵�:��, �似Ǫ�� ����
/*
�Է� ����
7 3
���
3 6 2 7 5 1 4

�Է�
10 4
���
4 8 2 7 3 10 9 1 6 5
*/
#include <stdio.h>
#include <stdlib.h>

int queue[50];
int front = 0;
int rear = 0;

void enqueue(int v, int n) {
    if (rear + 1 == front) {
        printf("full!"); //�����δ� �� ĭ ����ִ�.
        return;
    }
    rear = (rear + 1) % n;
    queue[rear] = v;
    return;
}

int dequeue(int n) {
    if (rear == front) {
        printf("empty!");
    }
    front = (front + 1) % n;

    return queue[front];
}

int is_q_empty() {
    if (front == rear)
        return 1;
    return 0;
}

void printq() {
    for (int i = 0; i < 8; i++) {
        printf("%d ", queue[i]);
    }
    printf("\n\n");
}

int main()
{
    int n;
    int k;
    int cnt = 0;
    int temp = 0;
    scanf("%d %d", &n, &k);
    n = n + 1; //�迭 ���� ť�� ������ ��ĭ ��� ������ 1 �÷��ش�.
    //�� �����
    for (int i = 1; i < n; i++) {
        enqueue(i, n);
    }

    while (cnt != n - 1) {
        //k-1��ŭ �ڷ� ������.
        for (int i = 0; i < k - 1; i++) {
            temp = dequeue(n);
            enqueue(temp, n);
        }
        //k ��°�� ����߸���.
        temp = dequeue(n);
        printf("%d ", temp);
        cnt++;
    }
    return 0;
}
