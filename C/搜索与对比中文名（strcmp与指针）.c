#include<stdio.h>
#include<string.h>
int main()
{
   char a[100],*p[10]={"��������","�ܷ�","������","�����","��ʩ��","������","��²���","�����","ɣ��˹","����"};
    gets(a);
    int i,x=0;
    for(i=0;i<10;i++)
    if(strcmp(*(p+i),a)==0) {x=1;break;}
    if(x==1)    printf("Y");
    else printf("N");
}
