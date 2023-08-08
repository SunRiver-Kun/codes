#include<stdio.h>
int main()
{
    int n,i,j,k;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
        for(k=1;k<=n;k++)
    if(i!=j&&j!=k&&i!=k)
        printf("%d %d %d\n",i,j,k);
}
