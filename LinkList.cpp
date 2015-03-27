// LinkList.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <ctime>
#include <iostream>
using namespace std;
#define OK 1
#define ERROR 0
typedef int ElemType;

/*���Ա�ĵ�����洢�ṹ*/
typedef struct Node
{
	ElemType data;
	struct Node * next;
} Node;
typedef struct Node * LinkList;/*����LinkList*/

bool GetElem(LinkList L,int i,ElemType * e)
{
	int j;
	LinkList p;
	p = L->next;
	j = 1;
	while(p&&j<i)
	{
		p = p->next;
		++j;
	}
	if(!p||j>i)
		return ERROR;
	*e = p->data;
	return OK;
}

bool ListInsert(LinkList * L,int i,ElemType e)
{
	int j;
	LinkList p,s;
	p = *L;
	j = 1;
	while(p && j<i)
	{
		p = p->next;
		++j;
	}
	if(!p||j>i)
		return ERROR;
	s = (LinkList)malloc(sizeof(Node));
	s->data = e;
	s->next = p->next;
	p->next = s;
	return OK;
}

bool ListDelete(LinkList * L,int i,ElemType * e)
{
	int j;
	LinkList p,q;
	p = *L;
	j = 1;
	while(p->next && j < i)
	{
		p = p->next;
		++j;
	}
	if(!(p->next)||j>i)
		return ERROR;
	q = p->next;
	p->next = q->next;
	*e = q->data;
	free(q);
	return OK;
}

void CreateListHead(LinkList * L,int n)
{
	LinkList p;
	int i;
	srand(time(0));
	*L = (LinkList)malloc(sizeof(Node));
	(*L)->next = NULL;
	for(i = 0;i<n;++i)
	{
		p = (LinkList)malloc(sizeof(Node));
		p->data = rand()%100 + 1;
		p->next = (*L)->next;
		(*L)->next = p;
	}
}

void CreateListTail(LinkList * L,int n)
{
	LinkList p,r;
	int i;
	srand(time(0));
	*L = (LinkList)malloc(sizeof(Node));
	r = *L;
	for(i = 0;i<n;++i)
	{
		p = (Node *)malloc(sizeof(Node));
		p->data = rand()%100+1;
		r->next = p;
		r = p;
	}
	r->next = NULL;
}

bool ClearList(LinkList *L)
{
	LinkList p,q;
	p = (*L)->next;
	while(p)
	{
		q = p->next;
		free(p);
		p = q;
	}
	(*L)->next = NULL;
	return OK;
}

int _tmain(int argc, _TCHAR* argv[])
{
	int x = 0;
	int y = 0;
//	cout<<x<<endl;
	LinkList LL;//��������
//	CreateListHead(&LL,10);//Head����10����������
	CreateListTail(&LL,10);//Tail����10����������
	for (int i = 1;i <= 10;++i)
	{
		GetElem(LL,i,&x);
//		cout<<x<<endl;
	}
	GetElem(LL,5,&x);//��ȡԪ�ص�x
	cout<<x<<endl;

	ListInsert(&LL,5,999);//����999����5��λ��
	GetElem(LL,5,&x);//��ȡԪ�ص�x
	cout<<x<<endl;

	ListDelete(&LL,5,&y);//ɾ����5��Ԫ�أ���ɾ����Ԫ�ش洢��y
	GetElem(LL,5,&x);//��ȡԪ�ص�x
	cout<<x<<endl;

	ClearList(&LL);//�������
	return 0;
}

