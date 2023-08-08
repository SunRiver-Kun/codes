#include<stdio.h>
int main()
{
    int a[5][5],i,j,temp;
    for(i=0;i<5;i++)
        for(j=0;j<5;j++)
        scanf("%d",&a[i][j]);
    for(i=0;i<5;i++)
    {
         for(j=0;j<5;j++)
            printf("%d ",a[j][i]);
         printf("\n");
    }


}
