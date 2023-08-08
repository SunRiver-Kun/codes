#include<stdio.h>
int dev(int a)
{
    int i=1;
    while(a/10)
       {i++;
       a=a/10;}
    return i;

}
int main()
{
    int a,b,c,d,s;
    scanf("%d%d",&a,&b);
    c=dev(a);
    d=dev(b);
    s=c+d;
    printf("%d",s);
}
