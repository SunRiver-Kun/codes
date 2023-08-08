#include<stdio.h>
void xier_sort(int a[],int n)
{
    int i,j,d,t;
    d=n/2;
    while(d)
    {
        for(i=d;i<n;i++)
        {
            t=a[i];
            for(j=i-d;j>=0;j-=d)
                if(t<a[j])  // ÉýÐò
                a[j+d]=a[j];
            else
                break;
            a[j+d]=t;
        }
        d=d/2;
    }
}
