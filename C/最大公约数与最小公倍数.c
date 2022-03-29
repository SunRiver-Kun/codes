#include<stdio.h>
int main()
{
    //最大公约数
    int m,n,y,a,b;
    scanf("%d%d",&m,&n); //m>=n
    if(m<n)
    {
        m=n+m;
        n=m-n;
        m=m-n;
    }
    a=m;b=n;
    while(1)
    {
        y=m%n;
        if(y==0)
           {
            printf("the greatest common divisor:%d\n",n);
            break;
            }
        else
        {
            m=n;
            n=y;
        }
    }
    for(y=a;y<=a*b;y++)
    {
        if(y%a==0)
       {
           if(y%b==0)
        {
            printf("the minimum common multiple:%d",y);
            break;  //最小公倍数
        }
       }
    }
}
