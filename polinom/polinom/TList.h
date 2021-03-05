#pragma once

template <class T>
struct TLink
{
	T val;
	TLink<T>* pNext;
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
			TLink<T>* tmp = pCurr;
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
		pCurr = pFirst;
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
		pCurr = pLast;
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
		pCurr = pCurr->pNext;
		delete tmp;
		size--;
	}

	void InsCurr(T elem) {
		if (pCurr == pStop)
			InsLast(elem);
		else if (pCurr == pFirst)
			InsFirst();
		else {
			TLink<T>* tmp = new TLink<T>;
			tmp->pNext = pCurr;
			tmp->pPrev = pPrev;
			pPrev->pNext = tmp;
			pPrev = tmp;
			tmp->val = elem;
			size++;
		}
	}

	T GetCurr() {
		if (pCurr == pStop)
			throw 0;
		else
			return pCurr->val;
	}
	void SetCurr(T elem) { pCurr->val = elem; }
	void Reset() { pCurr = pFirst; }
	void GoNext() {
		pPrev = pCurr;
		pCurr = pCurr->pNext;
	}
	bool IsEnd() { pCurr == pStop; }
	int GetSize() { return size; }

	void Print() {
		pCurr = pFirst;
		while (pCurr != pStop)
		{
			std::cout << GetCurr() << ' ';
			pCurr = pCurr->pNext;
		}
		putchar('\n');
	}
};

