#include<stdio.h>
void fun(int N)
{
    int a[10]={0},i,j,k,l;
    for(i=1;i<=N;i++)
    {
            j=i;
        while(j)
        {      l=j%10;
            for(k=0;k<10;k++)
            if(l==k)
            {
                a[k]++;
                break;
            }
            j=j/10;
       }
    }
    for(i=0;i<10;i++)
        printf("%d ",a[i]);
        printf("\n");
}
void main()
{
    int i;
    for(i=1;i<101;i++)
    {
        printf("%d:  ",i);
        fun(i);
    }
}
