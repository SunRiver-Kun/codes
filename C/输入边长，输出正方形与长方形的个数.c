#include<stdio.h>
int main()
{
    int n,m,a,b,i,j,*p;
    scanf("%d%d",&n,&m);    //n宽，m长
    a=b=0;  //a,b分别是正方形，长方形的数量
    for(i=1;i<=m;i++)   //i,j为边长
        for(j=1;j<=n;j++)
    {
        if(i==j)    p=&a;
        else p=&b;
        *p+=(n-j+1)*(m-i+1);
    }
    printf("%d %d",a,b);
}
