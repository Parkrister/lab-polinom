#pragma once
#include "TList.h"
#include <iostream>


///////////////////////////////////
template <class T>
class THeadList: public TList<T>
{
protected:
	TLink<T>* pHead;
public:
	THeadList():TList<T>() {
		pHead = new TLink<T>;
		TList<T>::pStop = pHead;
		pHead->pNext = pHead;

		//pFirst = pLast = pCurr = pPrev = pStop;
	}
	void InsFirst(T elem) {
		TList<T>::InsFirst(elem);
		pHead->pNext = TList<T>::pFirst;
	}
	// void DelFirst(){}
	~THeadList() {
		TList<T>::~TList();
		delete pHead;
	}

	T GetCurr() {
		return TList<T>::pCurr->val;
	}
};

