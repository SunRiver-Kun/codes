#include<stdio.h>
void fun(int end)
{   //flag==1,����flag==-1����
    //a��ʾ��һ������b��ʾ�ڶ�����
    //direction==-1�J��direction==1�L
    //swith==1����ת
    int cantor=1,flag=1,a=1,b=1,direction=-1,swith=1;
    while(cantor!=end)
   {
    if((a==1||b==1)&&swith==1)
    {
        if(flag==1) b++;
        else a++;
        flag=(-1)*flag;
        cantor++;
        direction=-1*direction;
        swith=0;
        continue;
    }
     if(direction==(-1))
    {
        a--;
        b++;
        cantor++;
        swith=1;
        continue;
    }
    else
    {
        a++;
        b--;
        cantor++;
        swith=1;
    }
   }
   printf("%d/%d\n",a,b);
}
int main()
{
    int n;
   scanf("%d",&n);
    fun(n);
}
