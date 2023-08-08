#include<stdio.h>
#include<string.h>
void x_fun(char a[],char m) //m>='1'&&m<='9'
{   int y=0,n,l,k;
    n=m-'0';
    char *p;
    k=strlen(a);
    for(p=a+k;p>a;p--)
        *p=*(p-1);
    *a='0';  //把a数组倒退一位
    for(p=a+k;p>a;p--)
    {   l=(*p-'0')*n+y;
        if(l>=10)
        {
            *p=l%10+'0';
            y=l/10;
        }
        else
        {
            *p=l+'0';
            y=0;
        }
    }
    if(y!=0)
    {
        *a=y+'0';
        *(a+k+1)='\0';
    }
    else
    {
        for(p=a;p<a+k;p++)
        *p=*(p+1);
        *p='\0';
    }
    puts(a);
}
void add_fun(char a[],char b[])
{
    char c[300]="0";
    int y=0,i,l,k;
    char *p=a+strlen(a)-1,*q=b+strlen(b)-1,*x;
   //指向个位
    if(strlen(a)>strlen(b))     x=c+strlen(a);  //预留c[0]
    else    x=c+strlen(b);
   while(p>=a&&q>=b)
   {
        l=((*p--)-'0')+((*q--)-'0')+y;  //用整型来判断是否大于10
    if(l>=10)
    {
        *x--=l%10+'0';
        y=1;
    }
     else
    {
        *x--=l+'0';
        y=0;
    }
   }
    if(p<a)
  {
        while(q>=b)
        {
            l=(*q--)-'0'+y;
            if(l>=10)
            {
                *x--=l%10+'0';
                y=1;
            }
            else
            {
                *x--=l+'0';
                y=0;
            }
        }
  }
  else if(q<b)
  {
      while(p>=a)
        {
            l=(*p--)-'0'+y;
            if(l>=10)
            {
                *x--=l%10+'0';
                y=1;
            }
            else
            {
                *x--=l+'0';
                y=0;
            }
        }
  }
    c[0]=y+'0';
    k=strlen(c);
   if(c[0]=='0')
   {
       for(x=c;x<c+k-1;x++)
        *x=*(x+1);
        *x='\0';
   }
   else *(c+k)='\0';
   strcpy(a,c);
}
