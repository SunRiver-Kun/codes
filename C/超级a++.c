#include<stdio.h>
int main()
{
    int i=5,p;
    p=++i+(++i)+(++i);//先计算括号内两个++i，既i=7，然后7+7=14，接下来，++i,8+14=22
    printf("p=%d,i=%d",p,i);
}
