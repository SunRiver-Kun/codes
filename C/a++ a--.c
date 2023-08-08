#include<stdio.h>
int main()
{
    int a,b,c,d;
    scanf("%d",&a);
    b=a++;
    printf("%d %d\n\n",b,a);

    scanf("%d",&c);
    d=++c;
    printf("%d %d",d,c);
}
