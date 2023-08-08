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
            while(*(q+1)!='\0')     //最后q指向'\0'的前一位，多余的一位
                {
                    *q=*(q+1);
                    q++;
                }
            *q='\0';  //让多余的一位变'\0',间接减少while(*p!='\0')的循环次数
            p--;  //保证从原位开始判断
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
