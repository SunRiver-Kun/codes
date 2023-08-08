#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#include<assert.h>
#define ERROR 0

typedef struct LNode {
	int data; //����������
	struct LNode *next; //����ָ����
} LNode, *PNode; //LinkListΪָ��ṹ��LNode��ָ������

int n=0, m=0;
char st = 'A';


PNode InitList(PNode L) //��������
{
	L = (PNode)malloc(sizeof(LNode));
	L->next = NULL;
	return L;
}

void PNodeInput(PNode L, int n) //�������ݵ�����
{
	int i;
	PNode p, r;
	r = L;
	char filename[20] = { 0 };
	printf("������˳���L%c�������ļ����ƣ��ļ���+��.txt������List%c.txt: \n",st,st);
	++st;
	gets(filename);
	FILE *file;
	file = fopen(filename,"r+");
	if (!file) {
        printf( "δ�ҵ�����ļ����޷��򿪣�\n" );
		exit(ERROR);
	}
	while (!feof(file)) {
		p = (PNode)malloc(sizeof(LNode));
		fscanf(file,"%d",&p->data);
		p->next = NULL;
		r->next = p;
		r = p;
		n++;
	}
	fclose(file);

}


bool LocateElem(PNode L, int e) //�ж�List����û��e���Ԫ��
{
	PNode p;
	p = L->next;
	while (p != NULL) {
		if (p->data == e)
			return true;
		p = p->next;
	}
	return false;
}

void PNodeInsert(PNode L, int e) //��e���뵽List��
{
	PNode p;
	p = (PNode)malloc(sizeof(LNode));
	p->data = e;
	p->next = L->next;
	L->next = p;
}

void PNodeOutput(PNode L) //���List
{
	PNode p;
	p = L->next;
	while (p != NULL) {
        printf("%d ",p->data);
		p = p->next;
	}
	printf("\n");
}

void unionList(PNode LA, PNode LB) //�㷨2.15 ���Ա�ĺϲ�������
{
	//�����������Ա�LB�е�����LA�е�����Ԫ�ز��뵽LA��
	int e;
	PNode p;
	p = LB->next;
	while (p != NULL) {
		e = p->data;
		if (!LocateElem(LA, e)) //LA�в����ں�e��ͬ������Ԫ�أ������֮
			PNodeInsert(LA, e);
		p = p->next;
	}
} //unionList

int main() {
	PNode LA, LB;

	LA = InitList(LA);

	LB = InitList(LB);

	PNodeInput(LA, n);
	PNodeInput(LB, m);

	unionList(LA, LB);

	printf("LA��LB�ϲ���ļ���Ϊ��\n");
	PNodeOutput(LA);
	return 0;
}


