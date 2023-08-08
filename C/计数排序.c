#include<stdio.h>
void jishu_sort(int a[],int length,int k)
{   //范围是0到k
    int c[k+1],y[length],i,j; //0~k
    for(i=0;i<=k;i++)
        c[i]=0;
    for(i=0;i<length;i++)
        c[a[i]]+=1;     //统计个数
    for(i=1;i<=k;i++)
        c[i]=c[i]+c[i-1];
    for(i=0;i<length;i++)
    {
        j=a[i];
        y[c[j]-1]=j;
        c[j]--;
    }
    for(i=0;i<length;i++)
        a[i]=y[i];      //y只是存了排好的数组
}

