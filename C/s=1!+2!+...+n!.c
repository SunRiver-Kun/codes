#include<stdio.h>
int main()
{
    int s=0,n,i,j,m;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        m=i;
        for(j=1;j<=i-1;j++)
            m=m*m;
        s+=m;
    }
    printf("%d",s);
}
