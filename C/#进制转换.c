#include<stdio.h>
void IntTo0X()
{
    int i=0;
    printf("����������i: \n");
    while(1)
    {
        scanf("%d",&i);
        printf("%d�ĵ�ַ��%p\n",i,i);//�������ȫ
        //printf("%d��ʮ������Ϊ%X\n",i,i); //����  ǰ���0
    }
}
void FloatTo0X()
{
    float f=0;
    printf("�����븡��f: \n");
    while(1)
    {
        scanf("%f",&f);
        printf("%.4f�ĵ�ַ��%p\n",f,*((int *)&f));  //%.xf�����Ͳ�����ֺ�����999��������
    }
}

int main()
{

  //  int *p = (int *)&i;
  //  printf("%p\n",*p);
    char opt;
    printf("��ѡ���ʽ(i��f)\n");
    scanf("%c",&opt);
    switch(opt)
    {
    case 'i':
        IntTo0X();
        break;
    case 'f':
        FloatTo0X();
        break;
    default:
        IntTo0X();
        break;
    }
}
