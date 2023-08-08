#include<stdio.h>
int fibonacci(int i)
{
    if(i==1||i==2)
        return 1;
    else
        return fibonacci(i-1)+fibonacci(i-2);
}
int main()
{
    int m,n,i;
    scanf("%d%d",&m,&n);
    if(m>n)
    {
        m=m+n;
        n=m-n;
        m=m-m;
    }
    for(i=m;i<=n;i++)
        printf("%d ",fibonacci(i));

}
