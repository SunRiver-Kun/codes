#include<stdio.h>
int main()
{
    int n;
    scanf("%d",&n);
    int a[n][n],i,j,c;
    while(1)
    {
        scanf("%d%d%d",&i,&j,&c);
        if(i==0&&j==0&&c==0)
            break;
        else
            a[i-1][j-1]=c;
    }
    int sum[]
}
