#include<stdio.h>
#include<string.h>
int main()
{
    char a[5][20],b[20];    //a来输入人名，b来做temp
    int i,j,min_i,k;
    for(i=0;i<5;i++)
        gets(*(a+i));
    for(i=0;i<5;i++)
    {
        min_i=i;    //选择排序法
        for(j=i+1;j<5;j++)
            if(strlen(*(a+j))<strlen(*(a+min_i)))
            min_i=j;
        for(k=min_i;k<5;k++)        //找到min长度了，看看后面有没有相同长度的
        {
            if(strlen(*(a+k))==strlen(*(a+min_i)))
               if(strcmp(*(a+k),*(a+min_i))<0)
                min_i=k;
        }
        if(min_i!=i)
        {
            strcpy(b,*(a+i));
            strcpy(*(a+i),*(a+min_i));
            strcpy(*(a+min_i),b);
        }
    }
    for(i=0;i<5;i++)
        puts(*(a+i));
}
