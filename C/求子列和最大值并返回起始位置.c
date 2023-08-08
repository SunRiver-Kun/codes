#include<stdio.h>
#include<stdlib.h>
struct xxx
{
    int sum,start,end_max;
};
void fun(int p[],int m)
{
    struct xxx a[m];
    int i,j,sum_temp,i_max;
    for(i=0;i<m;i++)
  {
    a[i].start=i;
    a[i].end_max=i;
    a[i].sum=p[i];
    sum_temp=0;
        for(j=i;j<m;j++)
    {
        sum_temp+=p[j];
        if(sum_temp>a[i].sum)
        {
            a[i].sum=sum_temp;
            a[i].end_max=j;
        }
    }
  }
  for(i=i_max=0;i<m;i++)
    if(a[i_max].sum<a[i].sum)
    i_max=i;
  printf("%d %d %d\n\n",a[i_max].sum,a[i_max].start+1,a[i_max].end_max+1);
}
int main()
{
    int n,*p,m,i,j,sum;
    scanf("%d",&n);
    for(j=1;j<=n;j++)
    {
        scanf("%d",&m);
        p=malloc(sizeof(int)*m);
        for(i=0;i<m;i++)
            scanf("%d",p+i);
        printf("Case %d:\n",j);
        fun(p,m);
        free(p);
    }
}
