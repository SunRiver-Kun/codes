#include<stdio.h>
#include<stdio.h>
void fun(char str1[],char str2[])
{
    int a=0,i;
    char b[20];
    for(i=0;i<strlen(str2);i++)
        if(str2[i]>='0'&&str2[i]<='9')
        a=a*10+(str2[i]-'0');
    i=sprintf(b,"%d",a); //%d对应一个数
    printf("%d",i);  //返回字符个数
    strcat(str1,b);
    puts(str1);
}
int main()
{
    char a[30],b[30];
   scanf("%s%s",a,b);
    fun(a,b);
}
