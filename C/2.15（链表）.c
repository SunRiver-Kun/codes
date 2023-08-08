#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#include<assert.h>
#define ERROR 0

typedef struct LNode {
	int data; //结点的数据域
	struct LNode *next; //结点的指针域
} LNode, *PNode; //LinkList为指向结构体LNode的指针类型

int n=0, m=0;
char st = 'A';


PNode InitList(PNode L) //创建链表
{
	L = (PNode)malloc(sizeof(LNode));
	L->next = NULL;
	return L;
}

void PNodeInput(PNode L, int n) //链表数据的输入
{
	int i;
	PNode p, r;
	r = L;
	char filename[20] = { 0 };
	printf("请输入顺序表L%c的数据文件名称（文件名+“.txt”，如List%c.txt: \n",st,st);
	++st;
	gets(filename);
	FILE *file;
	file = fopen(filename,"r+");
	if (!file) {
        printf( "未找到相关文件，无法打开！\n" );
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


bool LocateElem(PNode L, int e) //判断List里有没有e这个元素
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

void PNodeInsert(PNode L, int e) //将e插入到List中
{
	PNode p;
	p = (PNode)malloc(sizeof(LNode));
	p->data = e;
	p->next = L->next;
	L->next = p;
}

void PNodeOutput(PNode L) //输出List
{
	PNode p;
	p = L->next;
	while (p != NULL) {
        printf("%d ",p->data);
		p = p->next;
	}
	printf("\n");
}

void unionList(PNode LA, PNode LB) //算法2.15 线性表的合并（链表）
{
	//将所有在线性表LB中但不在LA中的数据元素插入到LA中
	int e;
	PNode p;
	p = LB->next;
	while (p != NULL) {
		e = p->data;
		if (!LocateElem(LA, e)) //LA中不存在和e相同的数据元素，则插入之
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

	printf("LA和LB合并后的集合为：\n");
	PNodeOutput(LA);
	return 0;
}


