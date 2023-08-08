#include<stdio.h>
int main()
{
   int N,x,y,k=0,l=0,i,j;
   scanf("%d%d%d",&N,&x,&y); //x表示行，y表示列，N表示范围
   for(j=1;j<=N;j++)
    printf("(%d,%d)",x,j);
   printf("\n");
   for(i=1;i<=N;i++)
    printf("(%d,%d)",i,y);
   printf("\n");
   //正斜对角，减减
  while(x-k>1&&y-k>1) k++;
  while(x+l<N&&y+l<N) l++;
    for(i=x-k,j=y-k;i<=x+l&&j<=y+l;i++,j++)
    printf("(%d,%d)",i,j);
printf("\n");
    //反斜对角，一加一减
    k=l=0;
    while(x-k>1&&y+k<N)   k++;
    while(x+l<N&&y-l>1)   l++;
    for(i=x+l,j=y-l;i>=x-k&&j<=y+k;i--,j++)
        printf("(%d,%d)",i,j);
}
