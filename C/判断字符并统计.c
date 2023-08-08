#include<stdio.h>
int main()
{
    int a,b,c,d;
    a=b=c=d=0;
    char s;
    while(1)
    {s=getchar();
    if(s=='\\')
     { xxx:     s=getchar();
         if(s=='n'||s=='a'||s=='b'||s=='t')
        d++;
     if(s=='\\')
        goto xxx;
     }
    else if(isdigit(s))
    a++;
    else if(isalpha(s))
        b++;
    else if(s=='+'||s=='-'||s=='*'||s=='/')
        c++;
    if(s=='#')
        break;

}   printf("数字个数：%d\n字母个数：%d\n算术运算符：%d\n转义字符：%d\n",a,b,c,d); }
