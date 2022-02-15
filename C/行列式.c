 #include<stdio.h>
#include<windows.h>
int fun(int n,int a[n][n])
{       // a[i][j]=*(*(a+i)+j)
    if(n==1)    return **a;
    if(n==2)    return a[0][0]*a[1][1]-a[0][1]*a[1][0];
    else if(n>2)
    {
            int sum=0;
            int i,j,k,flag=1;
            int b[n-1][n-1],*p=b[0];
            for(i=0;i<n;i++)
            {
                for(j=1;j<n;j++)
                    for(k=0;k<n;k++)
                    if(k!=i)    *p++=a[j][k];
                sum+=*(*a+i)*fun(n-1,b)*flag;
                flag=-flag;
                p=b[0];
            }
            return sum;
    }
}
int main()
{
    int N,i,k,a[100][100],*p;
    printf("请输入N:-1清屏，0结束, >0 计算 \n");
    scanf("%d",&N);
   while(N)
   {
       if(N==-1)
       {
           system("cls");
        printf("请输入N:-1清屏，0结束, >0 计算 \n");
           scanf("%d",&N);
       }
       else
       {
           k=N*N;
        for(i=0,p=a[0];i<k;i++)
        scanf("%d",p++);
    printf("行列式的结果是:%d\n\n",fun(N,a));
        for(i=0,p=a[0];i<k;i++)
            *p++=0;
        scanf("%d",&N);
       }
   }

}
