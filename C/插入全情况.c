#include<stdio.h>
int fun(int a[],int x,int cat,int n)
{   //cat==1±íÊ¾µÝÔö£¬cat==2µÝ¼õ
        int temp,i,j;
    if(cat==1)
    {
        if(x<a[0])
     {
          for(i=n;i>=1;i--)
            a[i]=a[i-1];
        a[0]=x;
     }
     else if(x>a[n-1])  a[n]=x;
     else
     {
         for(i=1;i<=n-1;i++)
            if(x>a[i-1]&&x<a[i])
           {
               for(j=n;j>=i+1;j--)
                a[j]=a[j-1];
            break;
           }
         a[i]=x;
     }
    }
    else if(cat==2)
    {
           if(x>a[0])
     {
          for(i=n;i>=1;i--)
            a[i]=a[i-1];
        a[0]=x;
     }
     else if(x<a[n-1])  a[n]=x;
     else
     {
         for(i=1;i<=n-1;i++)
            if(x<a[i-1]&&x>a[i])
          {
              for(j=n;j>=i+1;j--)
            a[j]=a[j-1];
            break;
          }
         a[i]=x;
     }
    }
    for(i=0;i<=n;i++)
        printf("%d ",a[i]);
}
int main()
{
    int n,i,x;
    scanf("%d",&n);
    int a[n+1],cat=1;
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
        scanf("%d",&x);       //n-1
    if(a[0]>a[1])   cat=2;
    fun(a,x,cat,n);
}
