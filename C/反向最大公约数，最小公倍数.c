#include<stdio.h>
int fun(int a,int b)
{       int i;
    if(a==1||b==1)  return 1;
    if(a==b)    return 1;
    else if(a%b==0||b%a==0)  return 0;
    else
    {
        if(a<b)
        {
            a=a+b;
            b=a-b;
            a=a-b;
        }
    for(i=2;i<b;i++)
        if(b%i==0&&a%i==0)
        return 0;
    }
    return 1;
}
int main()
{
    int a,b,i,j,m,num=0,k,num_same=0;
    scanf("%d%d",&a,&b);
    if(b==a)  printf("1");
    else if(b<a)    printf("0");
    else if(b%a!=0) printf("0");
    else
    {
         m=b/a;
    for(i=1; ;i++)
      if(m%i==0&&fun(m/i,i))
      {     k=m/i;
           if(k>i)  num++;
          else break;
      }
    printf("%d",2*num);
    }

}
