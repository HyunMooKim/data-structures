//c로 배우는 쉬운 자료구조 (이지영) 4판 
//응용예제 10 - 결정 트리로 동물을 분류하라 
//난이도: 하
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
입력 예시
9
1 날개가 있나요?
2 날 수 있나요?
3 털이 있나요?
4 까치
5 펭귄
6 빨리 움직이나요?
7 개구리
12 다람쥐
13 나무늘보
false true false

출력 예시
나무늘보
*/
typedef struct node {
    char str[50];
}node;

typedef struct tree {
    node* tree_ary[30];    //노드 개수 최대 30개
}tree;

node* create_node(char str[50]) {
    node* temp;
    temp = (node*)malloc(sizeof(node));

    strcpy(temp->str, str);
    return temp;
}

int main()
{
    int n; //노드개수
    int index; //노드 인덱스
    char str[50];
    tree t;
    char answer[6];

    for (int i = 0; i < 30; i++) {
        t.tree_ary[i] = NULL;
    }

    //노드 개수 입력
    scanf("%d", &n);

    //각 노드내용 입력
    for (int i = 0; i < n; i++) {
        scanf("%d", &index);
        scanf("%[^\n]s", str);       //%[^\n]s =  '^' 뒤에오는 문자가 나타날때까지 입력 [^abc]는 a or b or c 중 하나 이다. 
        t.tree_ary[index] = create_node(str);
        //create node 함수에서 받은 주소가 아니라 main함수에서 직접하면 결국 모든 트리노드가 마지막에 temp에 저장된 내용을 가리킨다. 
    }
    /*제대로 입력되었는지 확인하는 구문
    for (int i = 1; i <=index; i++) {
        if(t.tree_ary[i]!=NULL)
            printf("%d - %s \n",i, t.tree_ary[i]->str);
    }
    */

    //입력되는 정답(true, false)에 따라 동물 분류
    index = 1;
    do {
        scanf("%s", answer);
        if (strcmp(answer, "true") == 0) {
            index = 2 * index;
        }
        else {
            index = 2 * index + 1;
        }

    } while (t.tree_ary[index * 2] != NULL);

    printf("%s", t.tree_ary[index]->str);

    return 0;
}
