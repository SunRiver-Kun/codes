#include<stdio.h>
int main()
{
    int x,a,i=0;
    scanf("%d",&x);
    do
    {a=x%10;
    printf("%d ",a);
    i++;
    x=x/10;
    }while(x!=0);
    printf("\n%d digit number",i);
}
