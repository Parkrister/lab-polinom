#pragma once
#include "TList.h"

template <class T>
class THeadList: public TList<T>
{
protected:
	TLink<T>* pFirst, * pLast, * pCurr, * pPrev, * pStop;
	TLink<T>* pHead;
public:
	THeadList():TList() {
		TLink<T>* t = new TLink<T>;
		pHead = t;
		pStop = pHead;
		pHead->pNext = pHead;
	}
	void InsFirst(T elem) {
		TList<T>::InsFirst(elem);
		pHead->pNext = pFirst;
	}
	// void DelFirst(){}
	~THeadList() {
		TList::~TList();
		delete pHead;
	}
};

