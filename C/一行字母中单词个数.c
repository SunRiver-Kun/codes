#include<stdio.h>
#include<string.h>
int main()
{
    int num=0,i,length;
    char a[1024];
    gets(a);
    length=strlen(a);
    for(i=0;i<length;i++)
        if(a[i]!=' ')
    {   num++;
        while(a[i]!=' ')
        {
            i++;
            if(i>=length)
                break;
        }
        i--;
    }
printf("%d",num);
}
