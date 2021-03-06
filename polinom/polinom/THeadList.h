#pragma once
#include "TList.h"

struct TMonom {
	double coeff;
	int x, y, z;
	friend bool operator<(TMonom& m1, TMonom& m2);
	friend bool operator==(const TMonom& m1, const TMonom& m2 );
};

template <class T>
bool operator<(TMonom& m1, TMonom& m2) {
	return (m1.x * 100 + m1.y * 10 + m1.z) < (m2.x * 100 + m2.y * 10 + m2.z);
}

bool operator==(const TMonom& m1, const TMonom& m2) {
	if (m1.x == m2.x && m1.y == m2.y && m1.z == m2.z) {
		if (m1.coeff == m2.coeff) {
			return true;
		}
	}
	return false;
}


template <class T>
class THeadList: public TList<T>
{
protected:
	TLink<T>* pFirst, * pLast, * pCurr, * pPrev, * pStop;
	TLink<T>* pHead;
public:
	THeadList():TList<T>() {
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
		TList<T>::~TList();
		delete pHead;
	}
};

