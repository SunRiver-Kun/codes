#include<stdio.h>
int main()
{
    char a[50],*p=a;
    int k;
    gets(a);
    scanf("%d",&k);
    p=p+k-1;
    printf("%s",p);

}
