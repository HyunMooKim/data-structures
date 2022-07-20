//c로 배우는 쉬운 자료구조 (이지영) 4판 
//응용예제 1 - 게이트볼 공은 어디에? 
//난이도: 쉬움
#include <stdio.h>

int main()
{
    int x=1, y=1;  //게이트볼의 위치, 시작은 (1,1)
    int n; //경기장 크기
    char* p = NULL; 
    char str[51]; //스윙기록 - 최대 50회 스윙 
 
    //경기장 크기 입력
    scanf("%d", &n);
    getchar();
    //스윙 기록 입력 
    scanf("%s", str);
    
    //포인터로 순회하며 스윙 기록에 따라 공을 움직인다.
    p= str;
    while( *p ){
        if(*p == 'D' && x != n){
            x= x+1;
        }
        if(*p == 'U' && x != 1){
            x = x-1;
        }
        if(*p == 'L' && y != 1 ){
            y= y-1;
        }
        if(*p == 'R' && y != n){
            y = y+1;
        }
        p = p + 1; 
        //printf("(%d, %d)\n", x, y); //과정 확인용 코드 
    }
    
    printf("(%d, %d)", x, y);
    
    return 0;
}