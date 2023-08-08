#include<stdio.h>
int main()
{
    int n=12;float a[12]={5,0.3,0.2,1,0.9,3,7,15,10,13,0.1,2},num;int i,j;
    scanf("%f",&num);
    for(i=0;i<12;i++)
        if(a[i]<num)
    {for(j=i;j<11;j++)
        a[j]=a[j+1];
        n--;
        i--;
    }
    for(i=0;i<n;i++)
        printf("%.1f ",a[i]);
}
