#include<stdio.h>
void zhijie_sort(int a[],int n)
{
    int i,j,t;
    for(i=1;i<n;i++)
    {
        t=a[i];
        for(j=i-1;j>=0;j--)
            if(t<a[j])  //ÉýÐò
            a[j+1]=a[j];
        else
            break;
        a[j+1]=t;
    }
}
