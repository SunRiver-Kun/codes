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
	printf("该程序最多可录入100个学生信息：\n");
	for(i = 0;i < N;i++)
	{
		printf("第%d个学生信息：\n",i + 1);
		printf("学号：");
		scanf("%d",&stu[i].num);
		printf("姓名：");
		scanf("%s",&stu[i].name);
		printf("生源地：");
		scanf("%s",&stu[i].place);
		printf("数学成绩：");
		scanf("%f",&stu[i].math);//信息录入
		printf("请选择是否继续录入学生信息：\n");
		puts("1、继续录入    2、结束");
		getchar();
		scanf("%c",&flag);
		if(flag=='2')
			break;
	}
}
