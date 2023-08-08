#include<stdio.h>
int fun(int n,int end)
{       if(end==1)  return 1;
        else if(end==2) return 3;
        else
    {
        if(n==2)    return 1+n*fun(n+1,end);
        if(n==end)    return 1+end;
        return 1+n*fun(n+1,end);        //1+2*(1+3*(1+4))  end=4
    }

}
int fun_x(int n)
{
    int s=0,i;
    for(i=1;i<=n;i++)
        s+=fun_y(i);
    return s;
}
int fun_y(int n)
{
    int s=1,i;
    for(i=1;i<=n;i++)
        s*=i;
    return s;
}
int main ()
{
    int i;
   for(i=1;i<20;i++)
    printf("%d %d\n",fun(2,i),fun_x(i));
}
