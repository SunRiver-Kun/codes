#include<stdio.h>
void fun(char *p,char a)
{
    char *q;int flag=0;
    while(*p!='\0')
    {
        if(*p==a)
        {
            flag=1;
            q=p;
            while(*(q+1)!='\0')     //���qָ��'\0'��ǰһλ�������һλ
                {
                    *q=*(q+1);
                    q++;
                }
            *q='\0';  //�ö����һλ��'\0',��Ӽ���while(*p!='\0')��ѭ������
            p--;  //��֤��ԭλ��ʼ�ж�
        }
        p++;
    }
    if(flag==0) printf("Not find!");
}
int main()
{
    char a[100],b;
    gets(a);
    b=getchar();
    fun(a,b);
    puts(a);
}
