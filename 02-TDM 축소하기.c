//c�� ���� ���� �ڷᱸ�� (������) 4�� 
//���뿹�� 2 - TDM ����ϱ�
//���̵�: ��
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
/*
�Է¿���
5 ���� ������ ���� ���� ������
10
0 1 0 0 0 0 1 0 2 3
9 0 0 1 0 4 0 0 0 0
0 2 0 0 0 0 1 0 1 5
12 0 0 0 0 7 0 0 0 0
0 1 0 0 0 0 0 0 3 0

��¿���
*/
int main()
{
    int n; //�ܾ� ����
    int m; //���� ����
    char* terms[30] ={NULL}; //�ܾ�� �ִ� 30
    char str[150]; // 30�� * 5���� 150���� ����
    int** TDM = NULL;  //TDM�� n*m ��ķ� �־�����.

    // �ܾ� ���� �Է�
    scanf("%d", &n);
    getchar();

    // �� �ܾ�� �Է�
    fgets(str, sizeof(str), stdin);
    str[strlen(str) - 1] = '\0';

    char* ptr = strtok(str, " ");   //����������� �ڸ���
    for (int i = 0; ptr != NULL; i++) {
        terms[i] = ptr;               // �ڸ� ���ڿ��� terms�� �ϳ��� ��´�.
        ptr = strtok(NULL, " ");      //���� ���ڿ��� �߶� �����͸� ��ȯ�ϴ� ���
    }

    //��������M �Է�
    scanf("%d", &m);

    //TDM�� ������ �Ұ� �����Ҵ����� ������ ���Ҵ�. 
    //�ִ�ũ�⿡ ���� int TDM[30][50] ���� �����ϰ� �����ص� �ȴ�.
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
    // TDM �Է�
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &TDM[i][j]);
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (TDM[i][j] != 0) {
                printf("%s ����%d %d\n", terms[i], j+1, TDM[i][j]);
            }
        }
    }

    return 0;
}