#include<stdio.h>
#include<string.h>
int main()
{
    char a[100],b[3],*p=a;
    gets(a);
    gets(b);
    int num=0;
   xxx:     if(strstr(p,b)!=NULL)
    {
         num++;
         p=strstr(p,b)+2;
         goto xxx;
    }
    printf("%d",num);
}

