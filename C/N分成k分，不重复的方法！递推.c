#include<stdio.h>
//�����a�ֳ�b�ֵĲ�ͬ�ַ���,ţ���ˣ���
int C(int a,int b)
{   int s=0,i;
    if(b==1)    return 1; //ȫ����һ��
    if(a-b==0||a-b==1)  return 1;   //ƽ�֣�һ��2����ƽ��
    if(a==2)    return 1;  //�ο�ʼ�ĵط�
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
