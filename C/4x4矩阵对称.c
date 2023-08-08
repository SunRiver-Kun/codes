#include<stdio.h>
int main()
{
    int a[4][4],i,j,x=1,y=1,z=1,k=1;//x,y,j,k为开关
    for(i=0;i<4;i++)
        for(j=0;j<4;j++)
        scanf("%d",&a[i][j]);
    // | x
    for(j=0;j<=1;j++)
        for(i=0;i<4;i++)
        if(a[i][j]!=a[i][3-j])
        x=0;
    // - y
    for(i=0;i<=1;i++)
        for(j=0;j<4;j++)
        if(a[i][j]!=a[3-i][j])
        y=0;
    // \ z 虽然会重复比
    for(i=0;i<4;i++)
        for(j=0;j<4;j++)
        if(a[i][j]!=a[j][i])
        z=0;
    // / k
    for(i=0;i<4;i++)
        for(j=0;j<4;j++)
        if(a[i][j]!=a[3-j][3-i])
        k=0;
    if(x||y||z||k)
        printf("对称");
    else
        printf("不对称");
}
