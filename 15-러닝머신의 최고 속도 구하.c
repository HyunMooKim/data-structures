//c로 배우는 쉬운 자료구조 (이지영) 4판
//응용예제 14 - 러닝머신의 최고 속도 구하기
//난이도: 하
#include <stdio.h>
#define MAX 60
/*
입력
10
5 10 15 19 23 24 25 20 12 4

출력
25 
*/
//중간 지점을 확인해보며 범위를 줄여나간다.
void find_peak(int history[MAX], int start, int end) {
    int mid_point = history[(start + end) / 2];
    int left = history[((start + end) / 2) - 1];
    int right = history[((start + end) / 2) + 1];
    if (left > mid_point) {
        find_peak(history, start, ((start + end) / 2) - 1);
    }
    else if (right > mid_point) {
        find_peak(history, ((start + end) / 2) + 1, end);
    }
    else {
        printf("%d", mid_point);
        return;
    }

}

int main()
{
    int n;
    int history[MAX];

    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &history[i]);
    }

    //최고점 찾기 : 원시적 방법
    /*
    for(int i =1; i <= n-2; i++){
        if( history[i-1] < history[i] && history[i] > history[i+1] ){
            printf("%d", history[i]);
            return 0;
        }
    }
    */

    find_peak(history, 0, n - 1);

    return 0;
}