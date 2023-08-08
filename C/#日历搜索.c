#include<stdio.h>
void fun(int year,int mouth,int day,int weekday,int pass_day)
{
    int m,a[12]={31,0,31,30,31,30,31,31,30,31,30,31};
    exchange(year,a);
    m=day+pass_day;
    if(pass_day>=0)
    {
    while(a[mouth-1]<m)
    {
        m=m-a[mouth-1];
        mouth++;
        if(mouth>12)
       {    year++;
            exchange(year,a);
           mouth=(mouth-1)%12+1;   //循环，(x-第一个+偏移量)%总数+第一个
       }
    }
    pass_day%=7;
    weekday=(weekday+pass_day-1)%7+1;
    }
    else
    {      while(m<=0)
        {
            mouth--;
            m=m+a[mouth-1];
            if(mouth==1&&m<=0)
            {
                year--;
                exchange(year,a);
                mouth=13;
            }
        }
         pass_day%=7;
         if(weekday+pass_day>0) weekday+=pass_day;
         else weekday=7+weekday+pass_day;
    }
     printf("%d %d %d 星期%d",year,mouth,m,weekday);
}
void exchange(int year,int a[])
{   int day_Feb=28;
    if(year%4==0&&year%100!=0||year%400==0) day_Feb=29;
    a[1]=day_Feb;
}
int main()
{
    int year,mouth,day,weekday,pass_day;
    scanf("%d%d%d%d%d",&year,&mouth,&day,&weekday,&pass_day);
    fun(year,mouth,day,weekday,pass_day);
}
