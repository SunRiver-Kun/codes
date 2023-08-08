#include<stdio.h>
int fun(int m,int n)
{
    int i,j,k,l,o,x=0;
    if(m>n)
    {
        m=m+n;
        n=m-n;
        m=m-n;
    }
    for(i>=m;i<=n;i++)
    {
        for(j=-100000;j<i;j++)
            for(k=-1000000;k<i;k++)
        if(j*j*j+k*k*k==i)
        {
            for(l=-1000000;l<i;l++)
                for(o=-10000000;o<i;o++)
            if((l*l*l+o*o*o==i)&&(l!=j||o!=k))
            {x=1;goto xxx;}
        }
    }
  xxx:  if(x==1)   return i;
    else return 0;
}
int main()
{
    int m,n;
    scanf("%d%d",&m,&n);
    printf("%d",fun(m,n));
}
