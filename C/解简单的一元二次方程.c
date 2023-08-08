#include<stdio.h>
#include<string.h>
struct cod
{
    char x;
    int d;
}a[100],b[100];
int number=0;
char fuhao;
void get_char(char *x,char *y,char *z,struct cod *p,struct cod *q,int *numb1,int *numb2,int *xishu)
{   while(x<y)
   {
       if(*x=='-') fuhao='-',x++;
        else if(*x=='+')    fuhao='+',x++;
        else fuhao='+';
        if(*x>='0'&&*x<='9')
        sscanf(x,"%d",&number);
        else number=1;
         while(*x>='0'&&*x<='9') x++;
         if(*x>='a'&&*x<='z'&&x!=y)
         {
             if(fuhao=='-')
                *xishu=*xishu-number;
             else
                *xishu=*xishu+number;
            x++;
         }
         else
         {
        p->x=fuhao;
        p->d=number;
        (*numb1)++;
        p++;
         }
   }
   y++;
   while(y<z)
   {
        if(*y=='-') fuhao='-',y++;
        else if(*y=='+')    fuhao='+',y++;
        else fuhao='+';
        if(*y>='0'&&*y<='9')
        sscanf(y,"%d",&number);
        else number=1;
         while(*y>='0'&&*y<='9') y++;
         if((*y>='a'&&*y<='z')&&y!=z)
         {
             if(fuhao=='-')
                *xishu=*xishu+number;
             else
                *xishu=*xishu-number;
             y++;
         }
         else
         {
        q->x=fuhao;
        q->d=number;
        (*numb2)++;
        q++;
         }
   }

}
int main()
{   //ka=12345
    struct cod *p,*q;
    p=a;
    q=b;
    int numb1=0,numb2=0,i,xishu=0;
    char along[1000],*x0=along,*y0=along,*z0,zimu;
    gets(along);
    while(*y0!='=')
    {
        if(*y0>='a'&&*y0<='z')  zimu=*y0;
        y0++;
    }
    z0=y0+1;
    while(*z0!='\0')
    {
        if(*z0>='a'&&*z0<='z')  zimu=*z0;
        z0++;
    }
    get_char(x0,y0,z0,p,q,&numb1,&numb2,&xishu);
    number=0;
    for(i=0;i<numb1;i++)
    {
        if(a[i].x=='-') number=number+a[i].d;
        else number-=a[i].d;
    }
    for(i=0;i<numb2;i++)
    {
        if(b[i].x=='-') number-=b[i].d;
        else number+=b[i].d;
    }
    if(number==0)   printf("%c=0.000",zimu);
    else
    printf("%c=%.3f",zimu,(number+0.0)/xishu);
}
