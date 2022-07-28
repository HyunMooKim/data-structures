//c로 배우는 쉬운 자료구조 (이지영) 4판
//응용예제 11 - 미로를 탈출하라!
//난이도: 중~상
//BFS라는 힌트가 없었다면 풀 수 있었을까..? 
/*  0은 이동 가능, 1 은 벽이다.  시작점부터 n,n의 끝점까지 경로를 출력하는 문제. 
입력예시
5
0 1 1 0 1
0 0 0 1 1
0 1 0 1 0
0 0 0 1 1
0 0 0 0 0

출력예시
(1, 1)  (2, 1)  (2, 2)  (2, 3)  (3, 3)  (4, 3)  (5, 3)  (5, 4)  (5, 5)


입력예시2
6
0 0 0 0 0 0
0 1 1 1 1 0
0 0 0 0 1 0
0 1 0 1 0 1
0 1 0 1 1 1
0 1 0 0 0 0
출력예시2
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
//BFS 탐색용 큐
int rear = -1, front = -1;
locat* queue[MAX];
//미로
int maze[max][max];
//방문여부 확인
int visited[max][max];
//각 위치까지 얼마나 이동했는지 확인
int path[max][max];
//경로 저장용 스택
int top = -1;
locat* stack[MAX];

//다음 위치를 반환해주는 함수
locat* next_adjacent(locat* now, int n) {
    locat* next = (locat*)malloc(sizeof(locat));
    //좌표가 0과 n-1 사이이며, 현재 위치와 인접하고, 벽이 아니며, 방문한적 없으면 다음 탐색 대상
    //아래
    if (now->x + 1 <= n - 1) {
        if ((maze[now->x + 1][now->y] == 0) && visited[now->x + 1][now->y] == 0) {
            next->x = now->x + 1;
            next->y = now->y;
            return next;
        }
    }
    //위
    if (0 <= now->x - 1) {
        if ((maze[now->x - 1][now->y] == 0) && visited[now->x - 1][now->y] == 0) {
            next->x = now->x - 1;
            next->y = now->y;
            return next;
        }
    }
    //오른쪽
    if (now->y + 1 <= n - 1) {
        if ((maze[now->x][now->y + 1] == 0) && visited[now->x][now->y + 1] == 0) {
            next->x = now->x;
            next->y = now->y + 1;
            return next;
        }
    }
    //왼쪽
    if (0 <= now->y - 1) {
        if ((maze[now->x][now->y - 1] == 0) && visited[now->x][now->y - 1] == 0) {
            next->x = now->x;
            next->y = now->y - 1;
            return next;
        }
    }

    //더이상 방문할 인접 노드가 없으면
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
    now->x = 0; //출력할때는 1,1 로 출력
    now->y = 0;

    enqueue(now);
    visited[0][0] = 1;
    path[0][0] = 0;

    locat* next = now;
    //BFS 진행
    while (front != rear) {
        now = dequeue();
        //현재 보고 있는 locat의 주변을 전부 enqueue
        for (next = next_adjacent(now, n); next; next = next_adjacent(now, n)) {
            enqueue(next);
            visited[(next->x)][(next->y)] = 1;
            //전 단계의 거리에 1만큼 더한 거리를 기록해준다.
            path[(next->x)][(next->y)] = path[now->x][now->y] + 1;
            //출구(n-1, n-1)에 도달하면 stop
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
    //시작점까지 거꾸로 거슬러 올라가며 스택에 저장
    //거리 8->7->6->5->...... 이런식으로 
    temp->x = n - 1;
    temp->y = n - 1;
    push(temp->x,temp->y);

    while ( temp->x != 0 || temp->y != 0) {

        totalpath--;
        //push(temp) 했는데, temp주소를 이 함수 안에서 만들어서 전부 마지막 저장값인 (0,0)이 되어버렸다. 
        // -> 해결: push에서 주소를 만들도록 바꿈.
        //위아래 양옆 끼리 if else붙였다가 디버그함. 예를들어 x+1이 범위 안에는 들지만, 벽인경우 밑에가 else if 면 다 지나가버림
        //아래 
        if (temp->x + 1 <= n - 1) {
            if ((maze[temp->x+1][temp->y] == 0) && (path[temp->x+1][temp->y] == totalpath)) {
                temp->x = temp->x + 1;
                push(temp->x, temp->y);
            }
        }
        //위
        if (0 <= temp->x -1) {
            if ((maze[temp->x -1][temp->y] == 0) && path[temp->x -1][temp->y] ==totalpath ) {
                temp->x = temp->x - 1;
                push(temp->x, temp->y);
            }
        }
        //오른쪽
        if (temp->y + 1 <= n - 1) {
            if ((maze[temp->x][temp->y + 1] == 0) && path[temp->x][temp->y + 1] == totalpath) {
                temp->y = temp->y + 1;
                push(temp->x, temp->y);
            }
        }
        //왼쪽
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
