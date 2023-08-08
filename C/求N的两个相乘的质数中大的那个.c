#include<stdio.h>
#include<math.h>
int fun(int n)
{   if(n<2) return 0;
    int i,m;
    m=sqrt(n);
    for(i=2;i<m;i++)
        if(n%i==0)  return 0;
    return 1;
}
int main()
{
    int n,i,m;
    scanf("%d",&n);
    m=sqrt(n);
    for(i=2;i<m;i++)
        if(n%i==0&&fun(n/i)&&fun(i))
    {
        printf("%d",n/i);
        break;
    }
}
