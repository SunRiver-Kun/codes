#include<stdio.h>
#include<string.h>
int is_cr_cnumber(char a[])
{
   char *p,*q;
   for(p=a,q=a+strlen(a)-1;p<q;p++,q--)
    if(*p!=*q)
    return 0;
   return 1;
}
int get_number(char a)
{
    if(a>='A'&&a<='F')
        return a-'A'+10;
    else if(a>='0'&&a<='9')
        return a-'0';
    else
        printf("!!!!!!!!!!!!!!!!wrong!!!!!!!!!!!!!!!!");
}
char put_number(int n)
{
    if(n>=10&&n<=15)
        return n-10+'A';
    else if(n<10&&n>=0) return n+'0';
    else
        printf("!!!!!!!!!!!!!!!!wrong!!!!!!!!!!!!!!!!");
}
void ex_add(char a[],int M)
{
    int y=0,k;
    char *p=a,*q=a+strlen(a)-1,b[1000]="",*x=b,temp;
    if(M==16)
    {
        while(p<a+strlen(a)) //开始到结尾
        {
            k=get_number(*p)+get_number(*q)+y;
            if(k>=16)
            {
                *x++=put_number(k-16);
                y=1;
            }
            else
            {
                *x++=put_number(k);
                y=0;
            }
            p++;
            q--;
        }
    }
    else if(M>=2&&M<=10)
    {
        while(p<a+strlen(a))
       {
           k=*p+*q-2*'0'+y;
        if(k>=M)
        {
            *x=k-M+'0';
            y=1;
        }
        else
        {
            *x=k+'0';
            y=0;
        }
        x++;
        p++;
        q--;
       }
    }
   if(y!=0) *x=y+'0';
    for(p=b,q=b+strlen(b)-1;p<q;p++,q--)
    {
        temp=*p;
        *p=*q;
        *q=temp;

    }
    strcpy(a,b);
    //strlen(x)>=strlen(a) 显然
}
int main()
{
    int M,step=1,flag=0;
    char a[100];
    scanf("%d%s",&M,a);
    ex_add(a,M);
   while(step<=30)
    {
        if(is_cr_cnumber(a))
        {   flag=1;
            printf("STEP=%d",step);
            break;
        }
        else
        {
            ex_add(a,M);
            step++;
        }
    }
    if(flag==0)
        printf("Impossible!");
}
