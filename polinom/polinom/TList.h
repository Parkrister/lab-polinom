#pragma once

template <class T>
struct TLink
{
	T val;
	TLink* pNext;
};

template <class T>
class TList
{
protected:
	TLink<T>* pFirst, * pLast, * pCurr, * pPrev, * pStop;
	int size, pos;
public:
	TList() {
		pStop = NULL;
		pFirst = pLast = pCurr = pPrev = pStop;
		size = pos = 0;
	}
	~TList() {
		pCurr = pLast;
		while (pCurr) {
			tmp = pCurr;
			pCurr = pPrev;
			tmp = pStop;
		}
	}

	void InsFirst(T elem) {
		if (size++) {
			TLink<T>* tmp = new TLink<T>;
			tmp->val = elem;
			tmp->pNext = pFirst;
			pFirst = tmp;
		}
		else {
			pFirst = new TLink<T>;
			pFirst->val = elem;
			pLast = pFirst;
		}
	}

	void InsLast(T elem) {
		if (size++) {
			TLink<T>* tmp = new TLink<T>;
			tmp->val = elem;
			pLast->pNext = tmp;
			pLast = tmp;
		}
		else {
			InsFirst(elem);
		}
	}

	void DelFirst() {
		if (size) {
			if (size > 1) {
				TLink<T>* tmp = pFirst;
				pFirst = pFirst->pNext;
				tmp = NULL;
			}
			else {
				pFirst = NULL;
			}
			size--;
		}
	}

	void DelCurr() {
		if (pCurr == pStop) {
			throw - 1;
		}
		if (pCurr = pFirst) {
			DelFirst();
			return;
		}
		TLink<T>* tmp = pCurr;
		pPrev->pNext = pCurr->pNext;

	}
};

