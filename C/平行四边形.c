#include<stdio.h>
int main()
{
    int m,n,i,j,a,b;
    scanf("%d%d",&m,&n);
    a=m;
    for(b=0;b<a;b++)
    {for(i=m;i>1;i--)
        printf(" ");
    for(j=0;j<n;j++)
        printf("*");
    printf("\n");m--;}
}
