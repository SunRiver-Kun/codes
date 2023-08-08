#include<stdio.h>
#define exchange(a,b) (a)=(a)+(b),(b)=(a)-(b),(a)=(a)-(b)
int main()
{
    int x,y;
    scanf("%d%d",&x,&y);
    exchange(x,y);
    printf("%d %d",x,y);
}
