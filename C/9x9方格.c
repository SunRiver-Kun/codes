#include<stdio.h>
int main()
{
    int a[3][3],b[9],c=0,i,j,sum[8]={0,0,0,0,0,0,0,0},k=0;
    for(i=0;i<3;i++)
        for(j=0;j<3;j++)
        scanf("%d",&a[i][j]);
for(i=0;i<3;i++)
    for(j=0;j<3;j++)
{b[c]=a[i][j];c++;}
        c=1;
for(i=0;i<3;i++)
    for(j=0;j<3;j++)
    {   while(c<=8)
        {if(a[i][j]==b[c])
            goto no;
            c++;
        }
        c=3*i+j+1+1;

    }

    for(i=0;i<3;i++)
     {
          for(j=0;j<3;j++)
        {
            sum[k]+=a[i][j]; //ÐÐ
            sum[k+3]+=a[j][i] ;//ÁÐ
        }
        printf("%d %d\n",sum[k],sum[k+3]);
        k++;

     }
     sum[6]=a[0][0]+a[1][1]+a[2][2];
     sum[7]=a[2][0]+a[1][1]+a[0][2];
     if(sum[0]==sum[1]&&sum[1]==sum[2]&&sum[2]==sum[3]&&sum[3]==sum[4]&&sum[4]==sum[5]&&sum[5]==sum[6]&&sum[6]==sum[7])
        printf("yes");
     else
   no:     printf("no");
}
