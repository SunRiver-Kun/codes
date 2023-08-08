#include<stdio.h>
int main()
{
    int a[10]={1,5,13,15,26,37,48,99,102},num;
    int i,j;
    scanf("%d",&num);
    for(i=1;i<9;i++)
        if(a[i-1]<=num&&a[i]>=num)
  {
        for(j=9;j>i;j--)
            a[j]=a[j-1];
            a[i]=num;
        break;
  }
    for(i=0;i<9;i++)
        printf("%d,",a[i]);
    printf("%d",a[9]);
}
