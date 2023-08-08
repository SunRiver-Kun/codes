#include<stdio.h>
int fun(int n)
{
    int a[100]={1,1},i;
    if(n>1)
    {

    for(i=2;i<=n;i++)
        a[i]=a[i-1]+a[i-2];
    return a[i-1];
    }
    else return 1;
}
int main()
{
    int n;
    scanf("%d",&n);
    printf("%d",fun(n));
}
