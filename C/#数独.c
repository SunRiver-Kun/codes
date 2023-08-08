#include<stdio.h>
int fun(int a[9][9],int b,int c,int d)
{   //c==1,ºá£»2×İ£¬3×óĞ±£¬4ÓÒĞ±
    int i=0;
    if(c==1)
    {
        while(a[d][i])  if(a[d][i++]==b)    return 0;
    }
    else if(c==2)
    {
        while(a[i][d])  if(a[i++][d]==b)    return 0;
    }
    else if(c==3)
    {
        while(a[i][i])
        {
            if(a[i][i]==b)
                return 0;
            i++;
        }
    }
    else if(c==4)
    {
        while(a[i][8-i])
        {
            if(a[i][8-i]==b)
                return 0;
            i++;
        }
    }
    return 1;
}
int fun_block(int a[9][9],int b,int row,int line)
{
    int i,j,c,d;
    if(row<=2)  i=0;
    else if(row<=5) i=3;
    else  i=6;
    c=i+2;
    if(line<=2)  j=0;
    else if(line<=5) j=3;
    else  j=6;
    d=j+2;
    for(;i<=c;i++)
        for(;j<=d;j++)
         if(a[i][j]==b) return 0;
    return 1;
}
void rebuild(int a[9][9])
{
    int i,j;
    for(i=0;i<9;i++)
        for(j=0;j<9;j++)
    a[i][j]=0;
}
int build(int a[9][9])
{
    int i,j,b,count;
    for(i=0;i<9;i++)
        for(j=0;j<9;j++)
    {
        count=0;
        b=rand()%9+1;
        if(i==j)
            while(!(fun(a,b,3,0)&&fun(a,b,1,i)&&fun(a,b,2,j)&&fun_block(a,b,i,j)))
            {
                b=rand()%9+1;
                count++;
                if(count>150)   return 0;
            }
        else if(i+j==8)
            while(!(fun(a,b,4,0)&&fun(a,b,1,i)&&fun(a,b,2,j)&&fun_block(a,b,i,j)))
            {
                b=rand()%9+1;
                count++;
                if(count>150)   return 0;
            }
        else
            while(!(fun(a,b,1,i)&&fun(a,b,2,j)&&fun_block(a,b,i,j)))
            {
                b=rand()%9+1;
                count++;
                if(count>150)   return 0;
            }
        a[i][j]=b;
    }
    return 1;
}
int main()
{
    int a[9][9]={0},i,j;
    while(!(build(a)))
        rebuild(a);
    for(i=0;i<9;i++)
    {
        for(j=0;j<9;j++)
            printf("%2d",a[i][j]);
        printf("\n");
    }

}
