#include<stdio.h>
#include<string.h>
int main()
{
    char a[50],b[50],*p=b;
   gets(a);
    int i,num_A=0,num_a=0,num;
    num=strlen(a);
    for(i=0;i<num;i++)
        if(a[i]>='A'&&a[i]<='Z')
        {num_A++;
            *p=a[i];
            p++;
        }
    else if(a[i]>='a'&&a[i]<='z')
        num_a++;
    p--;
    printf("%d\n%d\n",num_A,num_a);
    for(p;p>=&b[0];p--)
        printf("%c",*p);
}
