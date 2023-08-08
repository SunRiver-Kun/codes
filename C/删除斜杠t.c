#include<stdio.h>
void delete_t(char in[],char out[])  //删除字符串中的\t
{
    char *p=in,*q=out;
    while(*p)   //p到不了最后一个字符
    {
        if(*p=='\\')
        {
            if(*(p+1)=='t') //是\t了
            {
                if(*(p+2))  //是否到头了
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
    printf("原来的字符串：\n");
    puts(in);
    printf("删除\t后的字符串：\n");
    puts(out);
}
