#include<stdio.h>
int main()
{
    int i=5,p;
    p=++i+(++i)+(++i);//�ȼ�������������++i����i=7��Ȼ��7+7=14����������++i,8+14=22
    printf("p=%d,i=%d",p,i);
}
