#include<stdio.h>
int fun(int n,char a,char b,char c)  //���㷨�Ǵ������Ͽ���
{
    if(n==1)
        printf("%c->%c    ",a,c);
    else
    {
        fun(n-1,a,c,b);     //Ŀ��n����һ����n-1��a->b��
        printf("%c->%c    ",a,c);   //��nֱ�ӷ�c��
        fun(n-1,b,a,c);    //��n-1�����ٰᵽc
    }
}
int main()
{
    int m;
    scanf("%d",&m);
    fun(m,'A','B','C');     //��m���ӳ����ͽ���

}
