#include<stdio.h>
void delete_t(char in[],char out[])  //ɾ���ַ����е�\t
{
    char *p=in,*q=out;
    while(*p)   //p���������һ���ַ�
    {
        if(*p=='\\')
        {
            if(*(p+1)=='t') //��\t��
            {
                if(*(p+2))  //�Ƿ�ͷ��
                    p=p+2;
                else
                    break;
            }
        }
        *q++=*p++;
    }
}
int main()
{
    char in[100]="",out[100]="";
    gets(in);
    delete_t(in,out);
    printf("ԭ�����ַ�����\n");
    puts(in);
    printf("ɾ��\t����ַ�����\n");
    puts(out);
}
