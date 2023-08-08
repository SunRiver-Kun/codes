#include<stdio.h>
void IntTo0X()
{
    int i=0;
    printf("请输入整数i: \n");
    while(1)
    {
        scanf("%d",&i);
        printf("%d的地址是%p\n",i,i);//输出的是全
        //printf("%d的十六进制为%X\n",i,i); //忽略  前面的0
    }
}
void FloatTo0X()
{
    float f=0;
    printf("请输入浮数f: \n");
    while(1)
    {
        scanf("%f",&f);
        printf("%.4f的地址是%p\n",f,*((int *)&f));  //%.xf这样就不会出现后面是999的尴尬了
    }
}

int main()
{

  //  int *p = (int *)&i;
  //  printf("%p\n",*p);
    char opt;
    printf("请选择格式(i或f)\n");
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
