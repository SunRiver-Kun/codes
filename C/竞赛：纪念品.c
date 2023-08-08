#include<stdio.h>
#include<stdlib.h>
int compare (const void * a, const void * b)    //必须是const void 型指针
{
    return ( *(int*)a - *(int*)b );          //b-a即为降序
}
int main()
{
    int w,n,l,num=0;
    scanf("%d%d",&w,&n);
    int a[n],*q,*p=a;
    for(q=a;q<a+n;q++)
        scanf("%d",q);
qsort(a, n, sizeof(int), compare);
    q--;
while(p<=q)
{
    if(*p+*q<=w)
          p++;
    q--;
    num++;
}
printf("%d",num);
}
