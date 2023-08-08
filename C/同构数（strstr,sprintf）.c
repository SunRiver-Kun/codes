#include<stdio.h>
#include<string.h>
void fun(char a[],char b[])
{
    int m,i,k=0;
    char c[100];
    m=strlen(a);
    if(m%2==0)
        m=m/2;
    else m=(m+1)/2;
    for(i=m;i<strlen(a);i++)
        c[k++]=a[i];
    if(strstr(c,b)!=NULL) printf("1");
    else
        printf("0");
}
int main()
{
       char a[100],b[100];
       int n;
       scanf("%d",&n);
       sprintf(b,"%d",n);
      n=n*n;
      sprintf(a,"%d",n);
      fun(a,b);

}
