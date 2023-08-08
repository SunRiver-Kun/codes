#include<stdio.h>
int main()
{
    int a[10],i,j,min_i,temp;
    for(i=0;i<10;i++)
        scanf("%d",&a[i]);
    for(j=0;j<10;j++)
    {
        min_i=j;
        for(i=j;i<10;i++)
        if(a[i]<a[min_i])
            min_i=i;
        temp=a[min_i];
        a[min_i]=a[j];
        a[j]=temp;
    }
    for(i=9;i>=0;i--)
        printf("%d ",a[i]);  //降序（3 2 1），反过来就是升序（1 2 3）

}
