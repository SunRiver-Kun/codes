#include<stdio.h>
 struct student
{
    int id,score[6];
} x;
void getMaxScore()
{
    int i,max=x.score[0];
    for(i=1;i<6;i++)
        if(max<x.score[i])
        max=x.score[i];
    printf("%d ",max);
}
void getMinScore()
{
    int i,min=x.score[0];
    for(i=1;i<6;i++)
        if(min>x.score[i])
        min=x.score[i];
    printf("%d ",min);
}
void getAveScore()
{
    int i;
    float ave=0;
    for(i=0;i<6;i++)
        ave+=x.score[i];
    printf("%.0f ",ave/6);
}
void getPassed()
{
    int i,num=0;
    for(i=0;i<6;i++)
        if(x.score[i]>=60)
        num++;
    printf("%d",num);
}
int main()
{   int i;
   scanf("%d",&x.id);
   for(i=0;i<6;i++)
    scanf("%d",&x.score[i]);
   getMaxScore();
   getMinScore();
   getAveScore();
   getPassed();
}
