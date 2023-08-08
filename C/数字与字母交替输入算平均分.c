#include<stdio.h>
int main()
{
    float sum=0;
    int i=5,n;
    char c;
    while(i-->0)
    {       n=0;
        scanf("%d",&n);
        sum+=n;
        c=getchar();
        if(c>='A'&&c<='E')  sum+=95-(c-'A')*10;
    }
    printf("%.1f",sum/5.0);
}
