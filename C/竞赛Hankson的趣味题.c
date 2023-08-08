#include<stdio.h>
int hu_zhi(int a,int b)
{
    if(a==1||b==1)  return 1;
    if(a%b==0||b%a==0)    return 0;
    int i,k;
    k=(a>b?b:a);
    for(i=2;i<=k/2;i++)
        if(a%i==0&&b%i==0)
        return 0;
    return 1;
}
int double_num(int a,int b,int c)
{   if(c%a!=0)  return 0;
    if(hu_zhi(c/a,c/b))
        return 1;
}
int fun(int a[])
{
    int num=0,x;
    for(x=a[1];x<=a[3];x+=a[1])
        if((hu_zhi(x/a[1],a[0]/a[1]))&&double_num(x,a[2],a[3]))
       num++;
    return num;
}
int main()
{
    int n;
    scanf("%d",&n);
    int a[n][4],(*p)[4];
    for(p=a;p<a+n;p++)
        scanf("%d%d%d%d",*p,*p+1,*p+2,*p+3);
    for(p=a;p<a+n;p++)
        printf("%d\n",fun(p));
}
