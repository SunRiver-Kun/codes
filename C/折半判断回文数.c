#include<stdio.h>
#include<string.h>
int fun(char a[])
{
    int i,j;
    for(i=0,j=strlen(a)-1;i<j;i++,j--)
        if(a[i]!=a[j])
        return 0;
    return 1;
}
int main()
{
    char a[30];
    gets(a);
    printf("%d",fun(a));
}
