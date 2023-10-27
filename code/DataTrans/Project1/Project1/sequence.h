#pragma once
#ifndef SEQUENCE_H
#define SEQUENCE_H

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

typedef struct {
	ElemType* elem;
	int length;
}SqList;

Status InitList_Sq(SqList& L);
void DestroyList(SqList& L);
void ClearList(SqList& L);
int GetLength(SqList& L);
int IsEmpty(SqList& L);
int GetElem(SqList L, int i, ElemType& e);
int LocateElem(SqList L, ElemType e);


#endif // !HEAD_H

