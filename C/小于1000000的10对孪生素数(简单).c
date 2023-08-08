#include<stdio.h>
int isprime(int a)
{
    int i;
    if(a==2||a==3)  return 1;
    for(i=2;i<a;i++)
        if(a%i==0)
        return 0;
    return 1;
}
int main()
{
    int num=0,i;
    for(i=1000000;i>0;i--)
     {
         if(isprime(i))
         if(isprime(i-2))
         {
             printf("%d,%d\n",i,i-2);
             num++;
         }
         if(num==10)
            break;
     }
}
