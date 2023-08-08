#include<stdio.h>
int fun(char x,int down,int up,int now,int change)
{
    int a;
    if(x=='+')
        a=down+(now-down+change)%(up-down+1);
    else if(x=='-')
        a=up-(up-now+change)%(up-down+1);
    return a;
}
int main()
{
    int change,up,down,now;
    char x;
    x=getchar();
   scanf("%d%d%d%d",&down,&up,&now,&change);
    printf("%d %d %d\n",down,up,fun(x,down,up,now,change));
}
