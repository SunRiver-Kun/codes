#include<stdio.h>
int fun(int n,char a,char b,char c)  //本算法是从下往上看↑
{
    if(n==1)
        printf("%c->%c    ",a,c);
    else
    {
        fun(n-1,a,c,b);     //目标n的上一个子n-1（a->b）
        printf("%c->%c    ",a,c);   //把n直接放c上
        fun(n-1,b,a,c);    //把n-1个子再搬到c
    }
}
int main()
{
    int m;
    scanf("%d",&m);
    fun(m,'A','B','C');     //第m个子出来就结束

}
