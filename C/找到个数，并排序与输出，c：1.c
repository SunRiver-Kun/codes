#include<stdio.h>
int number(char c,char *p)
{
    int i=0;
    while(*p!='\0')
    {
        if(*p==c)
            i++;
        p++;
    }
    return i;
}
void siglechar(char *a,char *b)
{   char *p,*head=b;   //����b��䣬�ȷŸ�q�����׵�ַ
    while(*a!='\0')
    {
        for(p=head;*p!='\0';p++)
            if(*p==*a)
            break;  //�ظ���
        if(*p=='\0')
            *b++=*a;    //û���ظ��ģ�������ֵ
        a++;
    }
    *b='\0';
}
int main()
{
    char x[100],a[100]="",*p,temp1;
    int b[100]={0},k=0,i,j,min,temp2; //���˱���ÿ����ĸ�ĸ���
    gets(x);
    siglechar(x,a);
    for(p=a;*p!='\0';p++)
        b[k++]=number(*p,x);
    for(i=0;i<k;i++)
    {
            min=i;
        for(j=i+1;j<k;j++)
            if(b[min]>b[j])
            min=j;
        if(min!=i)
        {
            temp1=*(a+min);     //a�е���ĸ��b�����ֶ�Ӧ
            *(a+min)=*(a+i);
            *(a+i)=temp1;
            temp2=b[min];   //����
            b[min]=b[i];
            b[i]=temp2;
        }
    }
    for(i=0;i<k;i++)
    printf("%c:%d ",*(a+i),b[i]);
}
