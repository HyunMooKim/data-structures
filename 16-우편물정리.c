//c로 배우는 쉬운 자료구조 (이지영) 4판
//응용예제 16 - 우편물 정리
//난이도: 중
/*
입력
12 15
603A 701C 615B 612J 707W 701A 612U 601X 703Y 612Z 601L 702M 611N 710O 612A
612

출력
612J 612U 612Z 612A

입력
12 15
603A 701C 615B 612J 707W 701A 612U 601X 703Y 612Z 601L 702M 611N 710O 612A
701

출력
701C 701A
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 99

typedef struct mail {
    char str[5];
    struct mail* next;
}mail;
mail hash_table[2][MAX] = {0};

//호수와 층수로 해시 테이블에 입력
void insert(char str[5], int flo, int room_n) {
    mail* new = (mail *) malloc(sizeof(mail));
    mail* m = &hash_table[flo - 6][(room_n)];
   
    //최근 추가한 원소 옆까지 포인터 이동
    while ( m->next != NULL) {
        m = (m->next);
    }
    strcpy(new->str, str);
    new->next = NULL;
    (*m).next = new;
    return;
}

//612A 라면 12를 반환하는 함수
int roon_num(char str[5]) {
    int where;
    where = (int) str[1] - '0'; //아스키코드를 빼주어야 한다.
    where = where *10;
    where = where + (int) str[2] - '0';
    return where;
}
int main()
{
    int n;
    int m;
    int floor_number;
    int room_number;
    int where;
    mail mp;
    char temp[5];
    //사무실 개수와 우편물 개수
    scanf("%d %d", &n, &m);
    //사무실 개수만큼 해시 테이블 생성

   //입력 받으며 저장
    for (int i = 0; i < m; i++) {
        scanf("%s", temp);
        //몇 호 인지 저장
        where = roon_num(temp) % n;
        //6층 or 7층
        if (temp[0] == '6') {
            insert(temp, 6, where);
        }
        else {
            insert(temp, 7, where);
        }
    }

    //출력할 우편물 주소
    scanf("%d", &where);
    floor_number = where / 100;
    where = where % 100;
    room_number = where % n;
    mp= hash_table[floor_number - 6][room_number];
    
    while ( mp.next!= NULL) {
        printf("%s ", (mp.next)->str);
        mp = *(mp.next);
    }
   
    return 0;
}
