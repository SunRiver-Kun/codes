#include<stdio.h>
int main()
{
    int n1,n2,i,j,k,n;
    scanf("%d",&n);  //n为大于4的正整数
    for(i=n;i>=2;i--)
    {
        for(j=2;j<=i/2;j++)
            if(i%j==0)
            break;
        if(j==i/2+1)
        {   n2=i;
            n1=n2-2;
            for(k=2;k<=n1/2;k++)
                if(n1%k==0)
                break;
            if(k==n1/2+1)
            {
                 printf("%d %d",n1,n2);
                 goto end;
            }


        }



    }
    end: return 0;
}
