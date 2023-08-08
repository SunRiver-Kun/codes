#include<stdio.h>
void fun(char *p,int n)
{
    int a=0,b=0;
    while(*p!='E')
    {   if(a+b==n)
        {
        printf("%d:%d\n",a,b);
        a=b=0;
        }
        if(*p=='W') a++;
        else if(*p=='L')    b++;
        p++;
    }
  printf("%d:%d\n",a,b);
}
int main()
{
   char x,y[1000]="",*p=y;
   x=getchar();
   while(x!='E')
   {    if(x!='\n') *p++=x;
        x=getchar();
   }
   *p='E';
    fun(y,11);
   printf("\n");
   fun(y,21);
   return 0;
}
