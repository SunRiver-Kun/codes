#include<stdio.h>
#include<string.h>
#define N 100
struct student
{
	int num;
	char name[30];
	char place[30];
	float math;
};
int main()
{
	struct student stu[N];
	int i;
	char flag;
	printf("�ó�������¼��100��ѧ����Ϣ��\n");
	for(i = 0;i < N;i++)
	{
		printf("��%d��ѧ����Ϣ��\n",i + 1);
		printf("ѧ�ţ�");
		scanf("%d",&stu[i].num);
		printf("������");
		scanf("%s",&stu[i].name);
		printf("��Դ�أ�");
		scanf("%s",&stu[i].place);
		printf("��ѧ�ɼ���");
		scanf("%f",&stu[i].math);//��Ϣ¼��
		printf("��ѡ���Ƿ����¼��ѧ����Ϣ��\n");
		puts("1������¼��    2������");
		getchar();
		scanf("%c",&flag);
		if(flag=='2')
			break;
	}
}
