#include<stdio.h>
#include<string.h>
typedef struct number
{
    char temp[200];
    struct number *next;
}num,*nump;
typedef struct xxx
{
    char temp[1000];
    struct xxx *next;
}xxx,*xxxp;
void *x_fun(char a[],char m) //multiply
{
    int y=0,n,l,k;
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
void add_zero(char a[],int n)
{
    int i,k;
    k=strlen(a);
    for(i=0;i<n;i++)
        *(a+k+i)='0';
    *(a+k+i)='\0';
}
void x_real_fun(char a[],char b[])
{  int i,k;
    char c[150],sum[1000]="0",*l;
    nump p,q,head;
    k=strlen(b);
    l=b+strlen(b)-1;
    head=(nump *)malloc(sizeof(num));
    p=head;
    for(i=0;i<k;i++)
    {   q=(nump *)malloc(sizeof(num));
        strcpy(c,a);
        x_fun(c,*l--);
        add_zero(c,i);
        strcpy(q->temp,c);
        p->next=q;
        p=q;
    }
    p->next=NULL;  //!!!!
    p=head->next;
    while(p)
    {
        add_fun(sum,p->temp);
        p=p->next;
    }
    strcpy(a,sum);
}
void xx_real_fun(int n,char s[])
{   int i=1;
    char x[100]="1",y[2]="1";
    while(i<=n)
    {
        x_real_fun(s,x);
        add_fun(x,y);
        i++;
    }
}
int main()
{
    int n,i;
    scanf("%d",&n);
    xxxp head,p,q;
    head=(xxxp *)malloc(sizeof(xxx));
    p=head;
    for(i=1;i<=n;i++)
    {   q=(xxxp *)malloc(sizeof(xxx));
        strcpy(q->temp,"1");
        xx_real_fun(i,q->temp);
        p->next=q;
        p=q;
    }
    char sum[10000]="0";
    p->next=NULL;
    p=head->next;
    while(p)
    {
        add_fun(sum,p->temp);
        p=p->next;
    }
    puts(sum);
}
