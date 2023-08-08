#include<stdio.h>
int main()
{
    int n,m;
    scanf("%d",&n);
  xxx:  n=single(n);
    m=n+2;
    m=single(m);
    if(m-n==2)
        printf("%d %d",n,m);
    else
    {
        n++;
        goto xxx;
    }

}
int single(int a)
{
    int i=2,y;
    while(1)
    { if(i<a)
        {y=a%i;
        i++;
        if(y==0)
        {
            a++;
            i=2;
        }
        }
        else
            break;

    }
    return a;
}
