#include<stdio.h>
int main()
{
    int n;
    scanf("%d",&n);
    printf("%d",fun(n));
}
int fun(int n)
{
   if(n==1) return 2;
   return n-2+fun(n-1);
}
