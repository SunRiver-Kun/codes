#include<stdio.h>
void prm(int n)
{
            int i,j,k;
         for(i=1;i<=n;i++)
            {
                 for(k=n;k>i;k--)   printf(" ");
                for(j=1;j<=i;j++)   printf("* ");
                printf("\n");
            }
}
int main()
{
    int n;
    scanf("%d",&n);
    prm(n);
}
