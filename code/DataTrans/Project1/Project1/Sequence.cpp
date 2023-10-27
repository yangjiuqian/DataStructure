#include<iostream>
#include<string>
#include"sequence.h"
using namespace std;


Status InitList_Sq(SqList& L) {
	L.elem = new ElemType[MAXSIZE];
	if (!L.elem) {
		exit(OVERFLOW);
	}
	L.length = 0;
	return OK;
}

void DestroyList(SqList& L) {
	if (L.elem) {
		delete L.elem;
	}
}

void ClearList (SqList& L) {
	L.elem = 0;
}

int GetLength(SqList& L) {
	return(L.length);
}

int IsEmpty(SqList& L) {
	if (L.length == 0) {
		return 1;
	}
	else {
		return 0;
	}
}

int GetElem(SqList L, int i, ElemType& e) {
	if (i<1 || i>L.length) {
		return ERROR;
	}
	e = L.elem[i - 1];
	return OK;
}

int LocateElem(SqList L, ElemType e) {
	for (int i = 0; i < L.length; i++) {
		if (L.elem[i] == e) {
			return i + 1;
		}
	}
	return 0;
}
