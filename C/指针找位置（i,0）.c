#include<stdio.h>
#include<string.h>
int main()
{
    char a[50],c,*p=a;
    int i=1;
    gets(a);
    c=getchar();
    while(c!=*p++)
        i++;
    if(i>=strlen(a))
        printf("0");
    else
        printf("%d",i);
}
