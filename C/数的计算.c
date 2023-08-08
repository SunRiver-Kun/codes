#include<stdio.h>
#include<math.h>
int fun(int n)
{
    int a,num=1,i=0;
    a=n;
     while(a)
   {
    i++;
    a=a/10;
   }
   i=pow(10,i);     //求n前面的1
        a=n+i;
   if(a>2*n)    return a-i;
   else
   {                        //累加前面的1，当为9或大于2*n时停止，判断重复
       while(a<2*n&&num<=9)
       {
           a=a+i;
           num++;
       }
       if(a<2*n)    return fun(a);
       else return a-i;
   }
}
int main()
{   int i=501;
    while(i--)
        printf("%d\n",fun(i));
}
