#include<stdio.h>
int main()
{
    int n,m,a,b,i,j,*p;
    scanf("%d%d",&n,&m);    //n��m��
    a=b=0;  //a,b�ֱ��������Σ������ε�����
    for(i=1;i<=m;i++)   //i,jΪ�߳�
        for(j=1;j<=n;j++)
    {
        if(i==j)    p=&a;
        else p=&b;
        *p+=(n-j+1)*(m-i+1);
    }
    printf("%d %d",a,b);
}
