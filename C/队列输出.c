#include<stdio.h>
int main()
{
   int N,x,y,k=0,l=0,i,j;
   scanf("%d%d%d",&N,&x,&y); //x��ʾ�У�y��ʾ�У�N��ʾ��Χ
   for(j=1;j<=N;j++)
    printf("(%d,%d)",x,j);
   printf("\n");
   for(i=1;i<=N;i++)
    printf("(%d,%d)",i,y);
   printf("\n");
   //��б�Խǣ�����
  while(x-k>1&&y-k>1) k++;
  while(x+l<N&&y+l<N) l++;
    for(i=x-k,j=y-k;i<=x+l&&j<=y+l;i++,j++)
    printf("(%d,%d)",i,j);
printf("\n");
    //��б�Խǣ�һ��һ��
    k=l=0;
    while(x-k>1&&y+k<N)   k++;
    while(x+l<N&&y-l>1)   l++;
    for(i=x+l,j=y-l;i>=x-k&&j<=y+k;i--,j++)
        printf("(%d,%d)",i,j);
}
