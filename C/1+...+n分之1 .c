#include<stdio.h>
double fun(int n)
{
    double sum=0;
    while(n!=0)
    {
        sum += 1.0/n;
        --n;
    }
    return sum;
}
int main()
{
    int a,b;
    double x,y;
    scanf("%d%d",&a,&b);
    x=fun(a);
    y=fun(b);
    printf("%.2lf",x*y);
}
