#include<stdio.h>
#include<math.h>
float stdev(int a[],int n)
{
    float ave=0,x=0;
    int i;
    for(i=0;i<n;i++)
        x+=a[i];
    x=x/n;
    for(i=0;i<n;i++)
        ave+=(a[i]-x)*(a[i]-x);
    ave=ave/n;
    ave=sqrt(ave);
    return ave;

}
int main()
{
    int a[100],n,i;
    scanf("%d",&n);
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    printf("%.6f",stdev(a,n));
}
