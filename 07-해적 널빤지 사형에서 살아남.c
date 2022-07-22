//c로 배우는 쉬운 자료구조 (이지영) 4판 
//응용예제 7 - 해적 널빤지 사형에서 살아남기
//난이도:하, 요세푸스 순열
/*
입력 예시
7 3
출력
3 6 2 7 5 1 4

입력
10 4
출력
4 8 2 7 3 10 9 1 6 5
*/
#include <stdio.h>
#include <stdlib.h>

int queue[50];
int front = 0;
int rear = 0;

void enqueue(int v, int n) {
    if (rear + 1 == front) {
        printf("full!"); //실제로는 한 칸 비어있다.
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
    n = n + 1; //배열 원형 큐는 실제로 한칸 비어 있으니 1 늘려준다.
    //줄 세우기
    for (int i = 1; i < n; i++) {
        enqueue(i, n);
    }

    while (cnt != n - 1) {
        //k-1만큼 뒤로 보낸다.
        for (int i = 0; i < k - 1; i++) {
            temp = dequeue(n);
            enqueue(temp, n);
        }
        //k 번째는 떨어뜨린다.
        temp = dequeue(n);
        printf("%d ", temp);
        cnt++;
    }
    return 0;
}
