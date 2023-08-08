#include<stdio.h>
int main()
{
    int x,i=1;
    scanf("%d",&x);
 xxx:   if(i*i==x)
        printf("%d",i);
        else
        {i++;
        if(i!=x)
    goto xxx;
    else
        printf("0");
    }
}
