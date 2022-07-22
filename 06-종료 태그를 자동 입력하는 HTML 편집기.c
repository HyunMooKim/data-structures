//c�� ���� ���� �ڷᱸ�� (������) 4�� 
//���뿹�� 6 - ���� �±׸� �ڵ� �Է��ϴ� HTML ������
//���̵�: �� - ���ڿ� ó���� ��ٷӴ�
//�׸��� �ϴ� ������ �� ���ذ� �� �ȴ�.

/*
�Է¿���
<body> <div> <img src="hanbit_Academy.jpg"/>
<div> <a href="https://www.hanvit.co.kr/academy/"> �Ѻ���ī���� .

��¿��� 
<body> <div> <img src="hanbit_Academy.jpg"/> </div> <div> <a href="https://www.hanvit.co.kr/academy/"> �Ѻ���ī���� </a> </div> </body>
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct stack {
    char str[50][8]; //���� �� <\body> 
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
    return s->str[s->top + 1];  //���ذ� ��ȯ
}

void push(stack* s, char* str) {
    s->top++;
    strcpy(s->str[s->top], str);
}

void insert(char* str, char a) { // �ι�°�� '/' �����ϴ� �Լ�
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
    char temp[60];  //temp ũ�� �۰� ��Ƽ� corrupted �߻�
    char enter;
    char print[300] = ""; //����� ���ڿ�,�ʱ�ȭ ���� �ʰ� strcat�ϸ� ���� �߻� 
    stack* s = create_stack();
    do {
        scanf("%s", ptr);
        enter = getchar();
        strcpy(temp, ptr);

        //stack ����
        if (temp[strlen(temp) - 2] == '/')  //���������� �ι�°�� / �� ������
            pop(s);  //<img �� ���ش�.
        if (*temp == '<') { //<�� �����ϸ�
            if (temp[strlen(temp) - 1] != '>')  //<a �� ���  </a>�� ������ش�.
            {
                strcat(temp, ">"); 
                insert(temp, '/');
                push(s, temp);
            }
            else {  //<div> �� <body>��  </div> </body> �� ������ش�.
                insert(temp, '/');
                push(s, temp);
            }
        }
        if (strcmp(ptr, ".") != 0) {  //������ . ���� ��� �Է��� �� ��µȴ�.
            strcat(print, ptr);
            strcat(print, " ");
        }
        
        if (enter == '\n') {
        
            strcat(print, pop(s));  //���� �߻� pop ��ȯ�ϴ� �� ����
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