#include<stdio.h>
int main()
{
    int j,n,a[100],i=0;
    scanf("%d",&n);
    while(n>=2)
    {
        a[i++]=n%2;
        n=n/2;
    }
    a[i]=n;
    for(j=i;j>=0;j--)
        printf("%d",a[j]);
}
