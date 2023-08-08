#include<stdio.h>
#include<windows.h>
void fun(int m,int n,int p)
{
    int a[m][n],b[n][p],c[m][p],i,j,k,sum;
    for(i=0;i<m;i++)
        for(j=0;j<n;j++)
        scanf("%d",&a[i][j]);
    for(i=0;i<n;i++)
        for(j=0;j<p;j++)
        scanf("%d",&b[i][j]);
    for(i=0;i<m;i++)
        for(j=0;j<p;j++)
    {
        sum=0;
        for(k=0;k<n;k++)
            sum+=a[i][k]*b[k][j];
        c[i][j]=sum;
    }
    for(i=0;i<m;i++)
        {
            for(j=0;j<p;j++)
            printf("%d ",c[i][j]);
            printf("\n");
        }
}
int main()
{
    int m,n,p;
    scanf("%d%d%d",&m,&n,&p);
    while(m&&n&&p)
    {
        if(m==-1||n==-1||p==-1)
        {
            system("cls");
            scanf("%d%d%d",&m,&n,&p);
        }
        else
            fun(m,n,p);
    }
}
