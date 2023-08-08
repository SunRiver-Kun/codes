#include<stdio.h>
#include<string.h>
int main()
{
   char a[100],*p[10]={"本·拉登","杰夫","布格勒","戈德文","费施勒","格里纳","戈德伯格","奥择科","桑德斯","威布"};
    gets(a);
    int i,x=0;
    for(i=0;i<10;i++)
    if(strcmp(*(p+i),a)==0) {x=1;break;}
    if(x==1)    printf("Y");
    else printf("N");
}
