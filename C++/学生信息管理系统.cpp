#include<stdio.h>
#include<stdlib.h>
#include<string>
#define OK 1
#define ERROR 0;
#define OVERFLOW -2;
//学生信息管理系统  
//存入、查找、删除、修改、输出学生信息，学生信息包括姓名，性别，年龄，学号，电话； 
typedef struct LNode{
	int data; 
	char name[10];
	char sex[10];
	int old;
	int id;
	int tel;
	struct LNode *next;
}LNode,*LinkList; 

// 函数声明 
LinkList creatlist();
void disp(LinkList L);
void search(LinkList L);
void del(LinkList L);
void choose();
void menu();
void input(LinkList L);
void change(LinkList L);

//主函数入口 
int main(){
choose();
	return 0;
}

//选择功能函数  嵌套菜单函数 
void choose(){
	//struct LNode *L=NULL;
	LinkList L=NULL;
	int n;
	int a=1;
	while(a>0)
	{
		menu();
		printf("请选择功能:");
		scanf("%d",&n);
	switch (n)
	{
	case 1:
		L=creatlist();
		break;
	case 2:
		disp(L);
		break;
	case 3:
		search(L);
		break;
	case 4:
		del(L);
		break;
	case 5:
		input(L);
		break;
	case 6:
		change(L);
		break;
	default:
		a=-1;
		break;
	}
	}
}

//菜单函数 
void menu()
{
printf("\n\n");
printf("\t\t    欢迎使用学生信息管理系统\n      ");
printf("\t\t1.创建学生信息\n");
printf("\t\t2.输出学生信息\n");
printf("\t\t3.查询学生信息\n");
printf("\t\t4.删除学生信息\n");
printf("\t\t5.插入学生信息\n");
printf("\t\t6.修改学生信息\n");
printf("\t\t7.退出\n");
}

//尾插法带头节点创建单链表 
LinkList creatlist(){
//	int val;
	int n;
	LinkList L=(LinkList)malloc(sizeof(LNode));
	LinkList r=NULL;
	L->next=NULL;
	r=L;
	printf("请输入几个学生信息？");
	scanf("%d",&n);
	L->data=n;
	for(int i=0;i<n;i++){
		LinkList p=(LinkList)malloc(sizeof(LNode));
	//	p->data=val;
		printf("第%d个学生的姓名:\n",i+1);
			scanf("%s",&p->name);
			printf("第%d个学生的性别:\n",i+1);
			scanf("%s",&p->sex);
			printf("第%d个学生的年龄:\n",i+1);
			scanf("%d",&p->old);
			printf("第%d个学生的学号:\n",i+1);
			scanf("%d",&p->id);
			printf("第%d个学生的电话:\n",i+1);
			scanf("%d",&p->tel);
		p->next=NULL;
		r->next=p;
		r=p;	
	}
	return L;
}

//输出函数 
void disp(LinkList L){
	//LinkList p=L->next;
	LinkList p=NULL;
	p=L;
	if(p==NULL){
		printf("暂无数据！");
	}	
	else{		printf("共有%d个学生信息！\n",L->data);
	for(int i=0;i<L->data;i++){
	p=p->next;
		printf("姓名:%s\n",p->name);
		 	printf("性别：%s\n",p->sex); 
		 		printf("年龄：%d\n",p->old);
		 			printf("学号：%d\n",p->id);
		 				printf("电话：%d\n",p->tel);
						 printf("\n\n")	;}		
	}	
	}

//查找 
void search(LinkList L){
	int a;
//	LinkList p=L->next;
	LinkList p=L; 
	printf("您要查找的学生学号是:\n");
	scanf("%d",&a);
	for(int i=0;i<L->data;i++){
		p=p->next;
		if(a==p->id){
				printf("查找成功！");
			printf("姓名:%s",p->name);
		 	printf("性别：%s\n",p->sex); 
		 		printf("年龄：%d",p->old);
		 			printf("学号：%d",p->id);
		 				printf("电话：%d",p->tel);break;
		}
		else{
			printf("查无此人！");
		}
	}

}


//删除函数 
void del(LinkList L){
	int a;
	int j=1;
	int i; 
LinkList p=L;
LinkList q=NULL;
if(p==NULL){
	printf("暂无数据！");
	return;
}
if(p!=NULL){
printf("删除学生的学号是:");
scanf("%d",&a);
for(i=1;i<L->data;i++){
	if(a==p->next->id){
		printf("查找成功！");
	q=p->next;
		p->next=q->next;
		delete q;
		printf("删除成功！");
		L->data=L->data-1;
		break;
	}
	else{
		printf("不存在该学生 请检查输入学号是否有误！"); 
	}
	p=p->next;
}
}
}

//插入函数 
void input(LinkList L)
{
LinkList p=L;
int i;int j;
	if(p==NULL){
	printf("您还未创建学生信息！");
	return;
	}

	else{
		printf("插入到第几个节点？");
	scanf("%d",&i);

	if(i>0&&i<=L->data){		
	for(j=0;j<i-1;j++){
		p=p->next;		
		}	
		LinkList s=(LinkList)malloc(sizeof(LNode));
		printf("姓名:\n");
		scanf("%s",&p->name);
		 	printf("性别:\n"); 
		 		scanf("%s",&p->sex);
		 		printf("年龄：\n");
		 			scanf("%d",&p->old);
		 			printf("学号：\n");
		 				scanf("%d",&p->id);
		 				printf("电话：\n");
				scanf("%d",&p->tel);		
		s->next=p->next;
		p->next=s;	
		L->data=L->data+1;
	}   
	else printf("不存在的节点！");
}
} 

//修改函数 
void change(LinkList L) {
	LinkList p=L;
	int i,j;
	int a; 
	if(p==NULL){
		printf("你还未创建链表！"); 
		return;
	}
	
	else{printf("您要修改的学生信息的学号是："); 
	scanf("%d",&a);
	for(i=0;i<L->data;i++){
		p=p->next;
		if(a==p->id){
			printf("查找成功！\n");
			printf("姓名修改为：\n");
			scanf("%s",&p->name);
			printf("性别修改为:\n");
			scanf("%s",&p->sex);
			printf("年龄修改为:\n");
			scanf("%d",&p->old);
			printf("学号修改为：\n");
			scanf("%d",&p->id);
			printf("修改成功\n");
			break;
		}
		else
		{
			printf("不存在的学生信息！请检查信息输入是否有误\n");
		}
		}
	}
}
			
