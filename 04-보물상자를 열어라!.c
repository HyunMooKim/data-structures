//c로 배우는 쉬운 자료구조 (이지영) 4판 
//응용예제 4 - 보물상자를 열어라!
//난이도: 하~중
#include <stdio.h>
#include <stdlib.h>

//보물상자 
typedef struct node {
    int n; //상자 안 내용
    int f; //방문 여부
    struct node* next;
}node;
//보물상자로 이루어진 원형 리스트
typedef struct circle {
    node* node_ary[10];
}circle;

//보물상자 추가
void insert_node(circle* c, int n) {
    int i = 0;
    node* w = (node*)malloc(sizeof(node));
    w->n = n;
    w->f = 0;
    if (c->node_ary[0] == NULL) {
        w->next = NULL;
        c->node_ary[0] = w;
        return;
    }
    while (c->node_ary[i] != NULL) i++;
    c->node_ary[i] = w;
    return;
}


int main()
{
    int N;
    int value;
    int cnt = 0; //출력된 개수 
    int sign = 0; //부호 확인
    int now = 0; //index
    circle* c = (circle*)malloc(sizeof(circle));
    
    //box 개수 - 최대 10개
    scanf("%d", &N);

    //각 보물상자안의 숫자 입력
    for (int i = 0; i < N; i++) {
        c->node_ary[i] = NULL; //초기화
        scanf("%d", &value);
        insert_node(c, value);
    }

    /* 잘 입력되었는지 확인하는 구문 
    for (int i = 0; i < N; i++) {
        printf("%d번째 노드 :  %d\n",i, c->node_ary[i]->n);
    }
    */

    printf("%d ", now + 1);  //시작점 =1 출력
    cnt++;
     //모든 상자를 출력할 때까지 반복
    while (cnt != N) { 
        c->node_ary[now]->f = 1; //방문처리

        //음수면 -1 양수면 1기록
        if (c->node_ary[now]->n > 0) sign = 1;
        else sign = -1;

        now = (now + c->node_ary[now]->n) % N;   //적혀있는 숫자만큼 이동

        while (now < 0) now = now + 6;   //음수로가면 양수로 바꿔준다. ex) -1 => 5번 으로

        while (c->node_ary[now]->f == 1) {   //방문한 상자면 건너 뛴다.
            if (sign == 1)
                now = (now + 1) % N;    
            else
                now = (now - 1) % N;
            while (now < 0) now = now + 6;   //음수로가면 양수로 바꿔준다. ex) -1 => 5번 으로
        }

        printf("%d ", now + 1);
        cnt++;
    }


    return 0;
}
