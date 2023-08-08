#include<stdio.h>
 int fun(int a,int b)
 { int i;
if(a==1||b==1) return 1;
if(a==b) return 1;
else if(a%b==0||b%a==0) return 0;
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

 int Ax(int a,int b)
 {
int i,j,m,num=0,k;
if(b==a) return 1;
else if(b<a) return 0;
else if(b%a!=0) return 0;
m=b/a;
for(i=1; ;i++)
if(m%i==0&&fun(m/i,i))
{ k=m/i;
if(k>i) num++;
else break;
}
return 2*num;

 }
 int  Bx(int x,int y)
 {
int cnt=0,i,j;
for(i=x;i*i<x*y;i+=x){
if(x*y%i==0){
j=x*y/i;
if(j%i!=0&&j%x==0){
cnt++;
}
}
}
return 2*cnt+2;
 }
 int main()
 {      printf("i j  Ax  Bx\n");
     int i,j;
     for(i=2;i<500;i++)
     {
         for(j=2;j<1000;j++)
            if(Ax(i,j)!=Bx(i,j)&&i<j&&j%i==0)
           {
               printf("%d %d  %d %d\n",i,j,Ax(i,j),Bx(i,j));
               break;
           }

     }
 }
