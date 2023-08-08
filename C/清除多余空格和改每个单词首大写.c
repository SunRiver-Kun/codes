#include<stdio.h>
#include<string.h>
int main()
{
    char a[50];int i,j,n=0,length;
    gets(a);
    length=strlen(a);
   for(i=0;i<length-1;i++)
    if(a[i]==' '&&a[i+1]==' ')
       {
           for(j=i;j<length-1;j++)
        a[j]=a[j+1];
        n++;
        i--;
       }
if(a[0]==' ')
{
     for(i=0;i<length-1;i++)
    a[i]=a[i+1];
    a[length-1]=' ';
    n++;
}
    a[0]=a[0]-32;
    for(i=1;i<length-n;i++)
        if(a[i-1]==' '&&a[i]!=' ')
        a[i]=a[i]-32;
    for(i=0;i<length-n;i++)
        printf("%c",a[i]);

}

