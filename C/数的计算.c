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
   i=pow(10,i);     //��nǰ���1
        a=n+i;
   if(a>2*n)    return a-i;
   else
   {                        //�ۼ�ǰ���1����Ϊ9�����2*nʱֹͣ���ж��ظ�
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
