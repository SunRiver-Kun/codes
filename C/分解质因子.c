#include<stdio.h>
int main()
{
 int x,i=2,y,j=0;
 char a[50];
 scanf("%d",&x);
 printf("%d=",x);
 while(x!=1)
 {
     y=x%i;
     if(y!=0)
        i++;
     else
     {a[j]=i;
     x=x/i;
     i=2;
     j++;
     }
 }
     printf("%d",a[0]);
     for(i=1;i<j;i++)
        printf("*%d",a[i]);

}
