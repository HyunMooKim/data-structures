//c로 배우는 쉬운 자료구조 (이지영) 4판 
//응용예제 3 - 나만의 플레이 리스트 만들기
//난이도: 하~중
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    char title;
    struct node* link;
}node;

typedef struct playlist {
    node* head;
}playlist;

//리스트에 노래 추가하는 함수
void insert_node(playlist* a, char song) {
    //처음에 바로 list원소 개수 0이면 a->head->title = song; 했지만, head 주소엔 아무것도 없어 title로 접근 불가 
    //예외 발생으로 버그였다.
    node* p = a->head;
    node* new;
    new = (node*)malloc(sizeof(node));
    new->title = song;
    new->link = NULL;
    if (a->head == NULL) {
        a->head = new;
        return;
    }
    while (p->link) p = p->link;
    p->link = new;
    return;
}

//있는 노래면 1을 반환하는 함수
int find_target(playlist* a, char title) {
    node* p = NULL;
    p = a->head;
    while (p->link != NULL) { //p 가 아니라 p->link가 NULL 인지 봐야한다.
        if (p->title == title) {
            return 1;
        }
        p = p->link;
    }
    return 0;
}

//리스트 출력함수
void print_list(playlist* a) {

    node* p = NULL;
    p = a->head;
    while (p != NULL) {
        printf("%c ", p->title);
        p = p->link;
    }

    return;
}

int main()
{
    playlist* all;
    playlist* selected;
    node* p = NULL;
    int n;//전체 개수
    int k;//반복개수
    char target;
    int dif = 0;

    //전체리스트와 반복리스트 생성
    all = (playlist*)malloc(sizeof(playlist));
    selected = (playlist*)malloc(sizeof(playlist));
    all->head = NULL;
    selected->head = NULL;

    //전체 개수 받기
    scanf("%d", &n);

    //플레이리스트 전체 구성
    dif = 'A';//아스키코드
    for (int i = 0; i < n; i++) {
        insert_node(all, i + dif);   //'A'부터 차례로 입력
    }

    // 몇개로 반복 리스트를 구성할지 입력
    scanf("%d", &k);
    getchar();

    //있는 노래면 반복 리스트에 추가
    for (int i = 0; i < k; i++) {
        scanf("%c", &target);
        getchar();  //공백도 문자로 인식되어서 다 들어가지 않았음.
        if (find_target(all, target) == 1) {
            insert_node(selected, target);
        }
        else ("error");
    }

    printf("palylist: ");
    print_list(all);

    printf("\nselected list: ");
    print_list(selected);


    // 원형(반복)으로 만들기 
    p = selected->head;
    while (p->link != NULL) {
        p = p->link;
    }
    p->link = selected->head;
    return 0;
}