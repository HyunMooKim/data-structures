/*
  radix 정렬은 원래 실수 데이터에는 이용하지 못한다.
  이 코드는 실수 데이터를 그대로 문자열로 바꾸고
  소수점을 제거해 정수로 만들어 비교하여 출력한다.
*/

#define _CRT_SCURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void radix_sort(int* data, int n, int p) //n- 자료개수 p - 자리수
{
	const int notation = 10;
	int i, pos = 1, * cnt;
	int* tmp;
	tmp = (int*)malloc(n * sizeof(int));
	cnt = (int*)malloc(notation * sizeof(int));
	while (--p >= 0)
	{
		for (i = 0; i < notation; i++)
			cnt[i] = 0;// 카운터 초기화
		for (i = 0; i < n; i++)
			cnt[(data[i] / pos) % notation]++; // 대상수 구하기
		for (i = 1; i < notation; i++)
			cnt[i] += cnt[i - 1];// 누적수 구하기
		for (i = n - 1; i >= 0; i--)
		{
			tmp[--cnt[(data[i] / pos) % notation]] = data[i];// 자료의 재배치
		}
		for (i = 0; i < n; i++) // 재배치된 자료를 원본에 덮어쓰기
		{
			data[i] = tmp[i];
		}
		pos *= notation;
	}
	free(tmp);
	free(cnt);
}
void rip(char* str, char ch)// 소수점 제거
{
	for (; *str != '\0'; str++)
	{
		if (*str == ch) //ch와 같은 문자일 때
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
	int n_ary[20] = { 0 };// 여기에 정수형태로 담아서 정렬한다.
	int n = sizeof(array) / sizeof(array[0]);
	for (int i = 0; i < 20; i++)
	{
		sprintf(str, "%.6lf", array[i]); //문자열로 만든다
		rip(str, '.'); //소수점 제거
		n_ary[i] = atoi(str);//정수화하여 저장 ex)3.141592 -> 314159210.12 -> 10120000
	}
	int i;
	printf("========== before sort ==========\n");
	for (i = 0; i < n; i++) printf("%lf ", array[i]); printf("\n");
	printf("\n");
	radix_sort(n_ary, n, 9); // 20개의 데이터를 돌리며, 제일 큰 데이터를 고려해 9자리수(백의자리 +소수점 아래 6)로 돌린다.
	printf("\n========== after sort ==========\n");
	for (i = 0; i < n; i++) //0번째 ~19 번째 출력
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