//c로 배우는 쉬운 자료구조 (이지영) 4판 
//응용예제 9 - 나무 위 고양이 구출 대작전
//난이도: 하
/*
입력 예시 
3 2
1 1 1 1 1 1 1 0 0 1 1 0 0 0 1
출력예시
4 6


책에는 없지만
입력예시2 
3 3
1 1 1 1 1 1 1 0 0 1 1 0 0 0 1
출력예시 2
10 11 15
*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main()
{
    int N, K; //N단계 트리, K번 올라간 고양이
    int temp;
    int full = 0; //최대 가능한 노드 수
    int* tree;

    scanf("%d %d", &N, &K);
    full = pow(2, N + 1) - 1;
    tree = (int*)calloc(full, sizeof(int));

    //tree 형태를 입력받는다. 노드가 존재하면 1
    for (int i = 1; i < full; i++) {
        scanf("%d", &temp);
        if (temp == 1) {
            tree[i] = 1;
        }
    }

    //고양이 위치 후보 출력
    for (int i = pow(2, K); i <= pow(2, K + 1); i++) {
        if (i >= pow(2, N) && tree[i] == 1) {    //고양이가 있는 곳이 가장 마지막 단계라면 존재하는 모든 마지막 노드가 후보
            printf("%d ", i);
        }
        //고양이가 마지막 단계가 아닌 곳에 있다면, 하위 트리가 없는 곳이 후보.
        else if (tree[2 * i] == 0 && tree[2 * i + 1] == 0) {
            printf("%d ", i);
        }
    }

    free(tree);

    return 0;
}