#include<stdio.h>
struct
{
    int id;
    char name[9];
    int score;
}s[5]={{201,"Zhang",78},{202,"Li",85},{203,"Wang",60},{204,"Wang",75},{205,"Xue",80}},temp;
int main()
{
    int i,j,min;
    for(i=0;i<5;i++)
    {
        min=i;
        for(j=i+1;j<5;j++)
            if(s[j].score<s[min].score)
            min=j;
        if(min!=i)
        {
            temp=s[min];
            s[min]=s[i];
            s[i]=temp;
        }
    }
    int n;
    scanf("%d",&n);
    if(n==2)
    {
        for(i=0;i<5;i++)
            printf("%d\t%s\t%d\n",s[i].id,s[i].name,s[i].score);
    }
    else if(n==1)
    {
        for(i=4;i>=0;i--)
             printf("%d\t%s\t%d\n",s[i].id,s[i].name,s[i].score);
    }
}

