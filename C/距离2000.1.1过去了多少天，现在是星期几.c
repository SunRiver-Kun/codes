#include<stdio.h>
void fun(int year,int month ,int day)
{
    int n=6,pass;
    pass=get_day(year,month,day);
    printf("距离2000.1.1已经过去%d天\n",pass);
    n=1+(n-1+pass)%7;
    printf("现在是星期");
    if(n==1)    printf("一");
    if(n==2)    printf("二");
    if(n==3)    printf("三");
    if(n==4)    printf("四");
    if(n==5)    printf("五");
    if(n==6)    printf("六");
    if(n==7)    printf("日");
}
int get_day(int a,int b,int c)
{   //2000.1.1  星期六
    int n=0,i,j,k,mon2=28;
    if(a%4==0&&a%100!=0||a%400==0)  mon2=29;
    for(i=2000;i<a;i++)
        if(i%4==0&&i%100!=0||i%400==0)
        n+=366;
    else    n+=365;
    int x[12]={31,mon2,31,30,31,30,31,31,30,31,30,31};
    for(i=1;i<b;i++)
        n+=x[i-1];
    n+=c-1;
    return n;
}
int main()
{
    int year,month,day;
    scanf("%d-%d-%d",&year,&month,&day);
    fun(year,month,day);
}
