#include<stdio.h>
int Afun(int a[],int n)
{
    int i,num=0;
    for(i=0;i<n;i++)
        if(*(a+i)<*(a+n))
            num++;
        return num;
}
int Bfun(){}
int main()
{
    int N,i;
    char c;
    scanf("%d",&N);
    getchar();
    int a[N],b[N];
    scanf("%c=(",&c);
    for(i=0;i<N-1;i++)
        scanf("%d,",a+i);
    scanf("%d)",a+N-1);
    if(c=='A')
    {
        for(i=0;i<N;i++)
            *(b+i)=Afun(a,i);
        printf("B=(");
        for(i=0;i<N-1;i++)
            printf("%d,",*(b+i));
        printf("%d)",*(b+N-1));
    }
    else
    {
       int C[N],num=0,*p=C,*t;
        for(i=0;i<N;i++)
        {
            if(a[i]<num)
         {
             for(t=p++;t>C+a[i];t--)
                *t=*(t-1);
            *t=i;
         }
         else
            *p++=i;
        num++;
        }
    for(i=0;i<N;i++)
        b[C[i]]=i;
     printf("A=(");
        for(i=0;i<N-1;i++)
            printf("%d,",*(b+i));
        printf("%d)",*(b+N-1));
    }
}
