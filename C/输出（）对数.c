#include<stdio.h>
#include<string.h>
int main()
{
   char a[50];
   gets(a);
   printf("%d", fun(a,strlen(a)));
}
int fun(char a[],int n)
{
   int num_1=0,num_2=0,i;
    for(i=0;i<n;i++)
    {
        if(a[i]=='(')
           num_1++;
    else if(a[i]==')')
        num_2++;
    }
    if(num_1>num_2) return num_2;

        return num_1;

}
