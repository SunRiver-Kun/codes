#include<stdio.h>
#include<stdlib.h>
#include<string>
#define OK 1
#define ERROR 0;
#define OVERFLOW -2;
//ѧ����Ϣ����ϵͳ  
//���롢���ҡ�ɾ�����޸ġ����ѧ����Ϣ��ѧ����Ϣ�����������Ա����䣬ѧ�ţ��绰�� 
typedef struct LNode{
	int data; 
	char name[10];
	char sex[10];
	int old;
	int id;
	int tel;
	struct LNode *next;
}LNode,*LinkList; 

// �������� 
LinkList creatlist();
void disp(LinkList L);
void search(LinkList L);
void del(LinkList L);
void choose();
void menu();
void input(LinkList L);
void change(LinkList L);

//��������� 
int main(){
choose();
	return 0;
}

//ѡ���ܺ���  Ƕ�ײ˵����� 
void choose(){
	//struct LNode *L=NULL;
	LinkList L=NULL;
	int n;
	int a=1;
	while(a>0)
	{
		menu();
		printf("��ѡ����:");
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

//�˵����� 
void menu()
{
printf("\n\n");
printf("\t\t    ��ӭʹ��ѧ����Ϣ����ϵͳ\n      ");
printf("\t\t1.����ѧ����Ϣ\n");
printf("\t\t2.���ѧ����Ϣ\n");
printf("\t\t3.��ѯѧ����Ϣ\n");
printf("\t\t4.ɾ��ѧ����Ϣ\n");
printf("\t\t5.����ѧ����Ϣ\n");
printf("\t\t6.�޸�ѧ����Ϣ\n");
printf("\t\t7.�˳�\n");
}

//β�巨��ͷ�ڵ㴴�������� 
LinkList creatlist(){
//	int val;
	int n;
	LinkList L=(LinkList)malloc(sizeof(LNode));
	LinkList r=NULL;
	L->next=NULL;
	r=L;
	printf("�����뼸��ѧ����Ϣ��");
	scanf("%d",&n);
	L->data=n;
	for(int i=0;i<n;i++){
		LinkList p=(LinkList)malloc(sizeof(LNode));
	//	p->data=val;
		printf("��%d��ѧ��������:\n",i+1);
			scanf("%s",&p->name);
			printf("��%d��ѧ�����Ա�:\n",i+1);
			scanf("%s",&p->sex);
			printf("��%d��ѧ��������:\n",i+1);
			scanf("%d",&p->old);
			printf("��%d��ѧ����ѧ��:\n",i+1);
			scanf("%d",&p->id);
			printf("��%d��ѧ���ĵ绰:\n",i+1);
			scanf("%d",&p->tel);
		p->next=NULL;
		r->next=p;
		r=p;	
	}
	return L;
}

//������� 
void disp(LinkList L){
	//LinkList p=L->next;
	LinkList p=NULL;
	p=L;
	if(p==NULL){
		printf("�������ݣ�");
	}	
	else{		printf("����%d��ѧ����Ϣ��\n",L->data);
	for(int i=0;i<L->data;i++){
	p=p->next;
		printf("����:%s\n",p->name);
		 	printf("�Ա�%s\n",p->sex); 
		 		printf("���䣺%d\n",p->old);
		 			printf("ѧ�ţ�%d\n",p->id);
		 				printf("�绰��%d\n",p->tel);
						 printf("\n\n")	;}		
	}	
	}

//���� 
void search(LinkList L){
	int a;
//	LinkList p=L->next;
	LinkList p=L; 
	printf("��Ҫ���ҵ�ѧ��ѧ����:\n");
	scanf("%d",&a);
	for(int i=0;i<L->data;i++){
		p=p->next;
		if(a==p->id){
				printf("���ҳɹ���");
			printf("����:%s",p->name);
		 	printf("�Ա�%s\n",p->sex); 
		 		printf("���䣺%d",p->old);
		 			printf("ѧ�ţ�%d",p->id);
		 				printf("�绰��%d",p->tel);break;
		}
		else{
			printf("���޴��ˣ�");
		}
	}

}


//ɾ������ 
void del(LinkList L){
	int a;
	int j=1;
	int i; 
LinkList p=L;
LinkList q=NULL;
if(p==NULL){
	printf("�������ݣ�");
	return;
}
if(p!=NULL){
printf("ɾ��ѧ����ѧ����:");
scanf("%d",&a);
for(i=1;i<L->data;i++){
	if(a==p->next->id){
		printf("���ҳɹ���");
	q=p->next;
		p->next=q->next;
		delete q;
		printf("ɾ���ɹ���");
		L->data=L->data-1;
		break;
	}
	else{
		printf("�����ڸ�ѧ�� ��������ѧ���Ƿ�����"); 
	}
	p=p->next;
}
}
}

//���뺯�� 
void input(LinkList L)
{
LinkList p=L;
int i;int j;
	if(p==NULL){
	printf("����δ����ѧ����Ϣ��");
	return;
	}

	else{
		printf("���뵽�ڼ����ڵ㣿");
	scanf("%d",&i);

	if(i>0&&i<=L->data){		
	for(j=0;j<i-1;j++){
		p=p->next;		
		}	
		LinkList s=(LinkList)malloc(sizeof(LNode));
		printf("����:\n");
		scanf("%s",&p->name);
		 	printf("�Ա�:\n"); 
		 		scanf("%s",&p->sex);
		 		printf("���䣺\n");
		 			scanf("%d",&p->old);
		 			printf("ѧ�ţ�\n");
		 				scanf("%d",&p->id);
		 				printf("�绰��\n");
				scanf("%d",&p->tel);		
		s->next=p->next;
		p->next=s;	
		L->data=L->data+1;
	}   
	else printf("�����ڵĽڵ㣡");
}
} 

//�޸ĺ��� 
void change(LinkList L) {
	LinkList p=L;
	int i,j;
	int a; 
	if(p==NULL){
		printf("�㻹δ��������"); 
		return;
	}
	
	else{printf("��Ҫ�޸ĵ�ѧ����Ϣ��ѧ���ǣ�"); 
	scanf("%d",&a);
	for(i=0;i<L->data;i++){
		p=p->next;
		if(a==p->id){
			printf("���ҳɹ���\n");
			printf("�����޸�Ϊ��\n");
			scanf("%s",&p->name);
			printf("�Ա��޸�Ϊ:\n");
			scanf("%s",&p->sex);
			printf("�����޸�Ϊ:\n");
			scanf("%d",&p->old);
			printf("ѧ���޸�Ϊ��\n");
			scanf("%d",&p->id);
			printf("�޸ĳɹ�\n");
			break;
		}
		else
		{
			printf("�����ڵ�ѧ����Ϣ��������Ϣ�����Ƿ�����\n");
		}
		}
	}
}
			
