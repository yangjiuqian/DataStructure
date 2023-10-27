#include<iostream>
#include<string>
using namespace std;

#define MAXSIZE 100
#define TRUE 1
#define FALSE 0
#define MAXSIZE 100
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2

typedef int Status;
typedef char ElemType;

typedef struct Lnode {
	ElemType data;
	struct Lnode* next;
}Lnode, * LinkList;

int Inilist_L(LinkList& L) {
	L = new Lnode;
	L->next = NULL;
	return 0;
}

int ListEmpty(LinkList L) {
	if (L->next) {
		return 0;
	}
	else
		return 1;
}

void DestoryList_L(LinkList& L) {
	Lnode* p;
	while (L) {
		p = L;
		L = L->next;
		delete p;
	}
}

void ClearList(LinkList& L) {
	Lnode* p, * q;
	p = L->next;
	while (p) {
		q = p->next;
		delete p;
		p = q;
	}
	L->next = NULL;
}

int GetElem_L(LinkList& L, int i, ElemType& e) {
	Lnode* p;
	p=L->next;
	int j = 1; 
	while (p && j < i) {
		p = p->next;
		++j;
	}
	if (!p || j > i) {
		return ERROR;
	}
	e = p->data;
	return OK;
}
//取值，去=取第i个元素的值；

Lnode* LocateElem_l(LinkList L, ElemType e) {
	//在线性表中查找值为e的元素
	//找到则返回L中值为e的元素的地址，查找失败返回NULL
	Lnode *p;
	p = L->next;
	while (p && p->data != e) {
		p = p->next;
		return p;
	}
}

int LocateElem_L(LinkList L, ElemType e) {
	//在线性表中查找值为e的元素
	//找到则返回L中值为e的元素的序号，查找失败返回0
	Lnode* p;
	p = L->next;
	int j = 1;
	while (p && p->data != e) {
		p = p->next;
		j++;
	}
	if (p) {
		return j;
	}
	else {
		return 0;
	}
}

void insertAtIndex(LinkList &L, int i, ElemType e) {
	if (i < 0) {
		std::cerr << "Invalid index." << std::endl;
		return;
	}

	Lnode* newNode = new Lnode;
	newNode->data = e;
	Lnode* current = L;
	int currentIndex = 0;
	while (current && currentIndex < i - 1) {
		current = current->next;
		currentIndex++;
	}

	if (!current) {
		std::cerr << "Index out of range." << std::endl;
		delete newNode;//把新创建的节点删除释放内存
		return;
	}
	newNode->next = current->next;
	current->next = newNode;
}

Status ListDelet_L(LinkList& L, int i, ElemType& e) {
	Lnode* p,*q;
	int j = 0;
	while (p->next || j < i - 1) {
		p = p->next;
		++j;
	}
	if (!(p->next) || j > i - 1) {
		return ERROR;
	}
	q = p->next;
	p->next = q->next;
	e = q->data;
	delete q;
	return OK;
}

void CreateList_H(LinkList& L, int n) {
	L = new Lnode;
	L->next = NULL;
	Lnode *p;
	for (int i = n; i > 0; --i) {
		p = new Lnode;
		cin >> p->data;
		p->next = L->next;
		L->next = p;
	}
}//O(n)；头插法

void CreateList_R(LinkList& L, int n) {
	L = new Lnode;
	L->next = NULL;
	Lnode* p,*r;
	r = L;
	for (int i = 0; i < n; i++) {
		p = new Lnode;
		cin >> p->data;
		p->next=NULL;
		r->next = p;
		r = p;
	}
}

/*
1、查找
线性链表只能顺序存取，即在查找时要从头指针找起，查找的时间复杂度为O(n)

2、插入和删除
插入和删除线性表中的元素不需要移动元素，
只需要修改指针，一般情况下时间复杂度为O(1)；
如果要在单链表中进行前插或删除操作，
由于要从头查找前驱节点，所耗时间复杂度为O(n）
*/