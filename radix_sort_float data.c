/*
  radix ������ ���� �Ǽ� �����Ϳ��� �̿����� ���Ѵ�.
  �� �ڵ�� �Ǽ� �����͸� �״�� ���ڿ��� �ٲٰ�
  �Ҽ����� ������ ������ ����� ���Ͽ� ����Ѵ�.
*/

#define _CRT_SCURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void radix_sort(int* data, int n, int p) //n- �ڷᰳ�� p - �ڸ���
{
	const int notation = 10;
	int i, pos = 1, * cnt;
	int* tmp;
	tmp = (int*)malloc(n * sizeof(int));
	cnt = (int*)malloc(notation * sizeof(int));
	while (--p >= 0)
	{
		for (i = 0; i < notation; i++)
			cnt[i] = 0;// ī���� �ʱ�ȭ
		for (i = 0; i < n; i++)
			cnt[(data[i] / pos) % notation]++; // ���� ���ϱ�
		for (i = 1; i < notation; i++)
			cnt[i] += cnt[i - 1];// ������ ���ϱ�
		for (i = n - 1; i >= 0; i--)
		{
			tmp[--cnt[(data[i] / pos) % notation]] = data[i];// �ڷ��� ���ġ
		}
		for (i = 0; i < n; i++) // ���ġ�� �ڷḦ ������ �����
		{
			data[i] = tmp[i];
		}
		pos *= notation;
	}
	free(tmp);
	free(cnt);
}
void rip(char* str, char ch)// �Ҽ��� ����
{
	for (; *str != '\0'; str++)
	{
		if (*str == ch) //ch�� ���� ������ ��
		{
			strcpy(str, str + 1);
		}
	}
}
int main()
{
	double array[] = { 3.141592, 121.1234, 121.135, 432.2 , 54.56, 1.152, 1.15, 45.88,80.1112, 391.2, 59.153, 93.11 , 35.135, 15.36, 20.3,
	16.16, 48.24 , 80.1111 , 10.5, 10.15 };
	char str[30] = "";
	int n_ary[20] = { 0 };// ���⿡ �������·� ��Ƽ� �����Ѵ�.
	int n = sizeof(array) / sizeof(array[0]);
	for (int i = 0; i < 20; i++)
	{
		sprintf(str, "%.6lf", array[i]); //���ڿ��� �����
		rip(str, '.'); //�Ҽ��� ����
		n_ary[i] = atoi(str);//����ȭ�Ͽ� ���� ex)3.141592 -> 314159210.12 -> 10120000
	}
	int i;
	printf("========== before sort ==========\n");
	for (i = 0; i < n; i++) printf("%lf ", array[i]); printf("\n");
	printf("\n");
	radix_sort(n_ary, n, 9); // 20���� �����͸� ������, ���� ū �����͸� ����� 9�ڸ���(�����ڸ� +�Ҽ��� �Ʒ� 6)�� ������.
	printf("\n========== after sort ==========\n");
	for (i = 0; i < n; i++) //0��° ~19 ��° ���
	{
		for (int j = 0; j < n; j++)
		{
			sprintf(str, "%.6lf", array[j]);
			rip(str, '.');
			if (n_ary[i] == atoi(str))
			{
				printf("%lf ", array[j]);
			}
		}
	}
	return 0;
}