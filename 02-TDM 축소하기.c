//c로 배우는 쉬운 자료구조 (이지영) 4판 
//응용예제 2 - TDM 축소하기
//난이도: 중
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
/*
입력예시
5 오늘 데이터 날씨 순차 강아지
10
0 1 0 0 0 0 1 0 2 3
9 0 0 1 0 4 0 0 0 0
0 2 0 0 0 0 1 0 1 5
12 0 0 0 0 7 0 0 0 0
0 1 0 0 0 0 0 0 3 0

출력예시
*/
int main()
{
    int n; //단어 개수
    int m; //문서 개수
    char* terms[30] ={NULL}; //단어개수 최대 30
    char str[150]; // 30개 * 5글자 150으로 잡음
    int** TDM = NULL;  //TDM은 n*m 행렬로 주어진다.

    // 단어 개수 입력
    scanf("%d", &n);
    getchar();

    // 각 단어들 입력
    fgets(str, sizeof(str), stdin);
    str[strlen(str) - 1] = '\0';

    char* ptr = strtok(str, " ");   //공백기준으로 자르기
    for (int i = 0; ptr != NULL; i++) {
        terms[i] = ptr;               // 자른 문자열을 terms에 하나씩 담는다.
        ptr = strtok(NULL, " ");      //다음 문자열을 잘라서 포인터를 반환하는 방법
    }

    //문서개수M 입력
    scanf("%d", &m);

    //TDM은 연습도 할겸 동적할당으로 진행해 보았다. 
    //최대크기에 따라 int TDM[30][50] 으로 선언하고 진행해도 된다.
    TDM = (int**)calloc(n, sizeof(int*));
    if (TDM != NULL) {
        for (int i = 0; i < n; i++) {
            TDM[i] = (int*)calloc(m, sizeof(int));
            if (TDM[i] == NULL) {
                printf("error");
                return -1;
            }
        }
    }
    else {
        printf("error");
        return -1;
    }
    // TDM 입력
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &TDM[i][j]);
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (TDM[i][j] != 0) {
                printf("%s 문서%d %d\n", terms[i], j+1, TDM[i][j]);
            }
        }
    }

    return 0;
}