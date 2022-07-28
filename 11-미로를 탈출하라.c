//c�� ���� ���� �ڷᱸ�� (������) 4��
//���뿹�� 11 - �̷θ� Ż���϶�!
//���̵�: ��~��
//BFS��� ��Ʈ�� �����ٸ� Ǯ �� �־�����..? 
/*
�Է¿���
5
0 1 1 0 1
0 0 0 1 1
0 1 0 1 0
0 0 0 1 1
0 0 0 0 0

��¿���
(1, 1)  (2, 1)  (2, 2)  (2, 3)  (3, 3)  (4, 3)  (5, 3)  (5, 4)  (5, 5)


�Է¿���2
6
0 0 0 0 0 0
0 1 1 1 1 0
0 0 0 0 1 0
0 1 0 1 0 1
0 1 0 1 1 1
0 1 0 0 0 0
��¿���2
(1, 1)  (2, 1)  (3, 1)  (3, 2)  (3, 3)  (4, 3)  (5, 3)  (6, 3)  (6, 4)  (6, 5)  (6, 6)
*/
#include <stdio.h>
#include <stdlib.h>
#define max 20
#define MAX 400

typedef struct locat {
    int x;
    int y;
}locat;
//BFS Ž���� ť
int rear = -1, front = -1;
locat* queue[MAX];
//�̷�
int maze[max][max];
//�湮���� Ȯ��
int visited[max][max];
//�� ��ġ���� �󸶳� �̵��ߴ��� Ȯ��
int path[max][max];
//��� ����� ����
int top = -1;
locat* stack[MAX];

//���� ��ġ�� ��ȯ���ִ� �Լ�
locat* next_adjacent(locat* now, int n) {
    locat* next = (locat*)malloc(sizeof(locat));
    //��ǥ�� 0�� n-1 �����̸�, ���� ��ġ�� �����ϰ�, ���� �ƴϸ�, �湮���� ������ ���� Ž�� ���
    //�Ʒ�
    if (now->x + 1 <= n - 1) {
        if ((maze[now->x + 1][now->y] == 0) && visited[now->x + 1][now->y] == 0) {
            next->x = now->x + 1;
            next->y = now->y;
            return next;
        }
    }
    //��
    if (0 <= now->x - 1) {
        if ((maze[now->x - 1][now->y] == 0) && visited[now->x - 1][now->y] == 0) {
            next->x = now->x - 1;
            next->y = now->y;
            return next;
        }
    }
    //������
    if (now->y + 1 <= n - 1) {
        if ((maze[now->x][now->y + 1] == 0) && visited[now->x][now->y + 1] == 0) {
            next->x = now->x;
            next->y = now->y + 1;
            return next;
        }
    }
    //����
    if (0 <= now->y - 1) {
        if ((maze[now->x][now->y - 1] == 0) && visited[now->x][now->y - 1] == 0) {
            next->x = now->x;
            next->y = now->y - 1;
            return next;
        }
    }

    //���̻� �湮�� ���� ��尡 ������
    return NULL;
}

void enqueue(locat* next) {
    rear = rear + 1;
    queue[rear] = next;
    return;
}

locat* dequeue() {
    front = front + 1;
    return queue[front];
}

int BFS_to_exit(int n) {
    locat* now = (locat*)malloc(sizeof(locat));
    now->x = 0; //����Ҷ��� 1,1 �� ���
    now->y = 0;

    enqueue(now);
    visited[0][0] = 1;
    path[0][0] = 0;

    locat* next = now;
    //BFS ����
    while (front != rear) {
        now = dequeue();
        //���� ���� �ִ� locat�� �ֺ��� ���� enqueue
        for (next = next_adjacent(now, n); next; next = next_adjacent(now, n)) {
            enqueue(next);
            visited[(next->x)][(next->y)] = 1;
            //�� �ܰ��� �Ÿ��� 1��ŭ ���� �Ÿ��� ������ش�.
            path[(next->x)][(next->y)] = path[now->x][now->y] + 1;
            //�ⱸ(n-1, n-1)�� �����ϸ� stop
            if (next->x == n - 1 && next->y == n - 1) {
                return path[next->x][next->y];
            }
        }
    }
    return -1;
}


void push(int x, int y) {
    locat* temp = (locat*)malloc(sizeof(locat));
    top = top + 1;
    temp->x = x;
    temp->y = y;
    stack[top] = temp;
    return;
}

locat* pop() {
    top = top - 1;
    return stack[top + 1];
}

void back_track(int totalpath, int n) {
    locat* temp = (locat*)malloc(sizeof(locat));
    //���������� �Ųٷ� �Ž��� �ö󰡸� ���ÿ� ����
    //�Ÿ� 8->7->6->5->...... �̷������� 
    temp->x = n - 1;
    temp->y = n - 1;
    push(temp->x,temp->y);

    while ( temp->x != 0 || temp->y != 0) {

        totalpath--;
        //push(temp) �ߴµ�, temp�ּҸ� �� �Լ� �ȿ��� ���� ���� ������ ���尪�� (0,0)�� �Ǿ���ȴ�. 
        // -> �ذ�: push���� �ּҸ� ���鵵�� �ٲ�.
        //���Ʒ� �翷 ���� if else�ٿ��ٰ� �������. ������� x+1�� ���� �ȿ��� ������, ���ΰ�� �ؿ��� else if �� �� ����������
        //�Ʒ� 
        if (temp->x + 1 <= n - 1) {
            if ((maze[temp->x+1][temp->y] == 0) && (path[temp->x+1][temp->y] == totalpath)) {
                temp->x = temp->x + 1;
                push(temp->x, temp->y);
            }
        }
        //��
        if (0 <= temp->x -1) {
            if ((maze[temp->x -1][temp->y] == 0) && path[temp->x -1][temp->y] ==totalpath ) {
                temp->x = temp->x - 1;
                push(temp->x, temp->y);
            }
        }
        //������
        if (temp->y + 1 <= n - 1) {
            if ((maze[temp->x][temp->y + 1] == 0) && path[temp->x][temp->y + 1] == totalpath) {
                temp->y = temp->y + 1;
                push(temp->x, temp->y);
            }
        }
        //����
        if (0 <= temp->y - 1) {
            if ((maze[temp->x][temp->y - 1] == 0) && path[temp->x][temp->y - 1] == totalpath) {
                temp->y = temp->y - 1;
                push(temp->x, temp->y);
            }
        }
        
    }

    return;
}

int main()
{
    int n;
    int totalpath = 0;
    locat* temp;
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &maze[i][j]);
            visited[i][j] = 0;
        }
    }
    totalpath = BFS_to_exit(n);

    back_track(totalpath, n);

    while (top != -1) {
        temp = pop();
        printf("(%d, %d)  ", temp->x+1, temp->y+1);
    }
    return 0;
}