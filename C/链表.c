#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define N 5
typedef struct  student
{
    char id[9];
    char name[7];
    int score[N];
    struct student *next;
}stu,*stup;
stup input(stup head,int n,int score_n)
{
    printf("请输入学生id，名字，成绩（共5门）\n");
        stup p,q;
        p=head;
        int i,j;
        for(i=0;i<n;i++)
        {   q=(stup *)malloc(sizeof(stu)+N*sizeof(int));
            scanf("%s%s",q->id,q->name);
            for(j=0;j<score_n;j++)
                scanf("%d",&q->score[j]);
           p->next=q;
            p=q;
        }
        p->next=NULL;
        return head;
}
void sortup_id(stup head)
{
    stup p,q,min;
    char tid[9],tname[7];
    int i,temp;
    for(p=head->next;p->next!=NULL;p=p->next)
    {
        min=p;
        for(q=p->next;q;q=q->next)
            if(strcmp(q->id,min->id)<0) //递增
            min=q;
        if(min!=p)
        {
            strcpy(tid,p->id);strcpy(p->id,min->id);strcpy(min->id,tid);
            strcpy(tname,p->name); strcpy(p->name,min->name); strcpy(min->name,tname);
            for(i=0;i<N;i++)
            {
                temp=p->score[i];
                p->score[i]=min->score[i];
                min->score[i]=temp;
            }
        }
    }

}
void sum(stup head,int *a,int n)
{   stup p;
    p=head->next;
    int i,j;
    for(i=0;i<n;i++)
    {   *a=0;
        for(j=0;j<N;j++)
        *a+=p->score[j];
        a++;
        p=p->next;
    }
}
void ave(int *p,float *q,int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        *q=(*p+0.0)/N;
        p++;
        q++;
    }
}
void output(stup head,int *s,float *k)
{   int i;
    stup p;
    p=head->next;
    printf("学号    姓名    成绩     总分     平均分\n");
    while(p)
    {
        printf("%s %s\n",p->id,p->name);
        for(i=0;i<N;i++)
            printf("%d ",p->score[i]);
       printf("\n");
      printf("%d %.2f\n",*s,*k);
        p=p->next;
        s++;
        k++;
    }
}
int main()
{   int n;  //学生个数
    printf("请输入学生个数：\n");
    scanf("%d",&n);
    int s[n];
    float k[n];
    stup p;
    p=(stup *)malloc(sizeof(stu)+N*sizeof(int));
    p=input(p,n,N);
   sortup_id(p);
   sum(p,s,n);
    ave(s,k,n);
    output(p,s,k);
}
