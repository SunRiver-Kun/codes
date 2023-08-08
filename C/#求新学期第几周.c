#include <stdio.h>
#define BEGIN 20200906  //�Ե�һ�ܵ�������������
int exchange(int month[],int year)
{
    if (year/10000!=0 ) printf("year is wrong!!");
    if (year%4==0&&year%100!=0||year%400==0)
       {
        month[1] = 29;
        return 366;
       }
    else
       {
          month[1] = 28;
          return 365;
       }

}

int GetPassDay(int begin,int now)
{
    if (now-begin<0 )
    {
         printf("������������");
        return -1;
    }
    int month[12]={31,28,31,30,31,30,31,31,30,31,30,31},BeginYear=begin/10000,NowYear=now/10000,PassDay=0;
    int BeginMonth=(begin%10000)/100,NowMonth=(now%10000)/100,BeginDay=begin%100,NowDay=now%100;
    int i,j,k;
    //printf("%d %d %d %d %d %d",BeginYear,BeginMonth,BeginDay,NowYear,NowMonth,NowDay);
    exchange(month,BeginYear);
    if (BeginYear!=NowYear)
    {
        for(i=BeginYear+1;i<NowYear;i++)
        PassDay+=exchange(month,i);   //�м����
        exchange(month,BeginYear);
        PassDay+=month[BeginMonth-1]-BeginDay;
        for(i=BeginMonth+1;i<=12;i++)
            PassDay+=month[i-1];
        exchange(month,NowYear);
        PassDay+=NowDay;
        for(i=1;i<NowMonth;i++)
            PassDay+=month[i-1];
        return PassDay;
    }
    else
    {
        if (BeginMonth==NowMonth)
            return NowDay-BeginDay;
        else
        {
            PassDay+=month[BeginMonth-1]-BeginDay;
            for(i=BeginMonth+1;i<NowMonth;i++)
                PassDay+=month[i-1];
            PassDay+=NowDay;
            return PassDay;
        }
    }


}



int main()
{
    printf("�����뵱ǰ���ڣ�(����20200906)\n");
    int now,PassDay,week=1;
    scanf("%d",&now);
    PassDay = GetPassDay(BEGIN,now);
    if (PassDay<0)  return -1;
    week+=PassDay/7;
    printf("��ȥ��%d�죬�����ǵ�%d��",PassDay,week);
}
