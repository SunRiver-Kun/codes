#include<stdio.h>
int main()
{
    int a[10]={3,6,1,0,5,2,7,8,3,4},n,i,j=0,k,x=0,temp;
    scanf("%d",&n);
    for(i=0;i<=9;i++)
        if(n==a[i])
        {x=1;temp=a[i];
        for(j=i;j<9;j++)
            a[j]=a[j+1];
        a[9]=temp;
        break;}
        j=0;
    if(x==0)
        printf("Wrong number!");
    else
    {
        while(j<10)
    {       if(a[j]==n)  break;
        if(a[j]>n)
    {
        temp=a[j];
        for(k=j;k<9;k++)
        a[k]=a[k+1];
        a[9]=temp;

    }
    else  j++;
    }
    printf("%d",a[0]);
     for(i=1;i<10;i++)
        printf(",%d",a[i]);


    }

}
