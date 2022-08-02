//c로 배우는 쉬운 자료구조 (이지영) 4판
//응용예제 14 - 특징 벡터 만들기
//난이도: 하
//heap이라는 힌트가 있었다.
#include <stdio.h>
#include <stdlib.h>
#define MAX 50
#define MAX_FOR_HEAP 2500
/*
입력 출력 예시
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
//배열로 만든 히프
int heap[MAX_FOR_HEAP];
int heapsize = 0;

//최대 히프에 원소 넣기
void insert_heap(int item) {
    heapsize++;
    int i = heapsize;
    //첫 원소가 아니고(0은 비워둔다), 부모노드보다 크다면 위와 바꾼다. 
    while (i != 1 && item > heap[i / 2]) {
        heap[i] = heap[i / 2];
        i /= 2;
    }
    heap[i] = item;
    return;
}
//히프 초기화 (히프의 삭제는 루트로만 이루어진다)
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


    //4중 for문이 뭔가 잘못된거 같다... 어떻게 줄일 수 있을까?
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

