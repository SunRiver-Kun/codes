#include<stdio.h>
#include<string.h>
int fun(int a,char x,int b)
{
    switch(x)
    {
    case '+':
        return a+b;
    case '-':
        return a-b;
    case '*':
        return a*b;
    case '/':
        return a/(b+0.0);
    default: return a;
    }
}
int main()
{
  int i,a[600],sum[30]={0},k=0,*p=a;
  char x[40]="\n",*q=x,*w=x;
  q++;
  scanf("%d",p);
  p++;
  while(1)
  {
      scanf("%c",q);
      if(*q=='\n')
    {
        if(w+1==q)
            break;          //两个\n之间没有别的字符
        w=q;
    }
      q++;
      scanf("%d",p);
      p++;

  }
  printf("%d",a[0]);
}

