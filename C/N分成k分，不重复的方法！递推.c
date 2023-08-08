#include<stdio.h>
//完成了a分成b分的不同种方法,牛逼了！！
int C(int a,int b)
{   int s=0,i;
    if(b==1)    return 1; //全部给一份
    if(a-b==0||a-b==1)  return 1;   //平分，一份2其他平分
    if(a==2)    return 1;  //梦开始的地方
    else
        for(i=1;i<=a-b&&i<=b;i++)
        s+=C(a-b,i);
    return s;
    // (7,4)->(3,1)+(3,2)+(3,3)
}
int main()
{
    int N,k;
    scanf("%d%d",&N,&k);
    printf("%d",C(N,k));
}
