//c�� ���� ���� �ڷᱸ�� (������) 4�� 
//���뿹�� 9 - ���� �� ����� ���� ������
//���̵�: ��
/*
�Է� ���� 
3 2
1 1 1 1 1 1 1 0 0 1 1 0 0 0 1
��¿���
4 6


å���� ������
�Է¿���2 
3 3
1 1 1 1 1 1 1 0 0 1 1 0 0 0 1
��¿��� 2
10 11 15
*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main()
{
    int N, K; //N�ܰ� Ʈ��, K�� �ö� �����
    int temp;
    int full = 0; //�ִ� ������ ��� ��
    int* tree;

    scanf("%d %d", &N, &K);
    full = pow(2, N + 1) - 1;
    tree = (int*)calloc(full, sizeof(int));

    //tree ���¸� �Է¹޴´�. ��尡 �����ϸ� 1
    for (int i = 1; i < full; i++) {
        scanf("%d", &temp);
        if (temp == 1) {
            tree[i] = 1;
        }
    }

    //����� ��ġ �ĺ� ���
    for (int i = pow(2, K); i <= pow(2, K + 1); i++) {
        if (i >= pow(2, N) && tree[i] == 1) {    //����̰� �ִ� ���� ���� ������ �ܰ��� �����ϴ� ��� ������ ��尡 �ĺ�
            printf("%d ", i);
        }
        //����̰� ������ �ܰ谡 �ƴ� ���� �ִٸ�, ���� Ʈ���� ���� ���� �ĺ�.
        else if (tree[2 * i] == 0 && tree[2 * i + 1] == 0) {
            printf("%d ", i);
        }
    }

    free(tree);

    return 0;
}