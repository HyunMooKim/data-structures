//c로 배우는 쉬운 자료구조 (이지영) 4판 
//응용예제 6 - 종료 태그를 자동 입력하는 HTML 편집기
//난이도: 중 - 문자열 처리가 까다롭다
//그리고 일단 문제가 잘 이해가 안 된다.

/*
입력예시
<body> <div> <img src="hanbit_Academy.jpg"/>
<div> <a href="https://www.hanvit.co.kr/academy/"> 한빛아카데미 .

출력예시 
<body> <div> <img src="hanbit_Academy.jpg"/> </div> <div> <a href="https://www.hanvit.co.kr/academy/"> 한빛아카데미 </a> </div> </body>
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct stack {
    char str[50][8]; //가장 긴 <\body> 
    int top;
}stack;

stack* create_stack() {
    stack* s;
    s = (stack*)malloc(sizeof(stack));
    s->top = -1;
    return s;
}
char* pop(stack* s) {
    if (s->top == -1) {
        printf("error");
        return NULL;
    }
    s->top--;
    return s->str[s->top + 1];  //없앤걸 반환
}

void push(stack* s, char* str) {
    s->top++;
    strcpy(s->str[s->top], str);
}

void insert(char* str, char a) { // 두번째에 '/' 삽입하는 함수
    int len = strlen(str);
    str[strlen(str) + 1] = '\0';
    for (int i = len - 1; i >= 1; i--) {
        str[i + 1] = str[i];
    }
    str[1] = a;
    return;
}

int main()
{
    char ptr[60];
    char temp[60];  //temp 크기 작게 잡아서 corrupted 발생
    char enter;
    char print[300] = ""; //출력할 문자열,초기화 하지 않고 strcat하면 문제 발생 
    stack* s = create_stack();
    do {
        scanf("%s", ptr);
        enter = getchar();
        strcpy(temp, ptr);

        //stack 관리
        if (temp[strlen(temp) - 2] == '/')  //마지막에서 두번째가 / 로 끝나면
            pop(s);  //<img 를 빼준다.
        if (*temp == '<') { //<로 시작하면
            if (temp[strlen(temp) - 1] != '>')  //<a 인 경우  </a>로 만들어준다.
            {
                strcat(temp, ">"); 
                insert(temp, '/');
                push(s, temp);
            }
            else {  //<div> 와 <body>를  </div> </body> 로 만들어준다.
                insert(temp, '/');
                push(s, temp);
            }
        }
        if (strcmp(ptr, ".") != 0) {  //마지막 . 빼고 모든 입력은 다 출력된다.
            strcat(print, ptr);
            strcat(print, " ");
        }
        
        if (enter == '\n') {
        
            strcat(print, pop(s));  //예외 발생 pop 반환하는 걸 깜빡
            strcat(print, " ");
        }
    
    } while (strcmp(ptr, ".") != 0);

    while (s->top != -1) {
    
        strcat(print, pop(s)); 
        strcat(print, " ");
    }
    printf("%s", print);
    return 0;
}