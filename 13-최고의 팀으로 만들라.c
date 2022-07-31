//c로 배우는 쉬운 자료구조 (이지영) 4판
//응용예제 13 - 최고의 팀으로 만들라!
//난이도: 하
#include <stdio.h>
#include <stdlib.h>
#define MAX 15
/*입출력예시
8 3
85 72 81 90 90 79 76 80
89 91 70 74 90 86 82 91


85 91 81 90 90 90 91 80
81.62 -> 87.25
*/
void trade(int our[], int your[], int n, int k) {
    int min;
    int min_index;
    int max;
    int max_index;
    int temp;
    //총 k 번 트레이드
    for (int i = 0; i < k; i++) {
        min = our[i];
        min_index = i;
        max = your[i];
        max_index = i;
        for (int j = 0; j < n; j++) {
            if (min > our[j]) {
                min = our[j];
                min_index = j;
            }
            if (max < your[j]) {
                max = your[j];
                max_index = j;
            }
        }

        temp = our[min_index];
        our[min_index] = your[max_index];
        your[max_index] = temp;
    }

    return;
}

int main()
{
    int n;
    int k;
    int our[MAX];
    int your[MAX];
    double mean1 = 0;
    double mean2 = 0;

    scanf("%d %d", &n, &k);

    for (int i = 0; i < n; i++) {
        scanf("%d", &our[i]);
        mean1 = mean1 + our[i];
    }
    mean1 = mean1 / n;
    for (int i = 0; i < n; i++) {
        scanf("%d", &your[i]);
    }
    
    //트레이드 진행
    trade(our, your, n, k);

    for (int i = 0; i < n; i++) {
        printf("%d ", our[i]);
        mean2 = mean2 + our[i];
    }
    mean2 = mean2 / n;

    printf("\n%.2lf -> %.2lf", mean1, mean2);

    return 0;
}
