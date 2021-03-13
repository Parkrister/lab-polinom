#pragma once

template <class T>
struct TLink
{
	T val;
	TLink<T>* pNext;
};

//////////////////////////////////////////
	//--------------------------//
struct TMonom {
	double coeff;
	int x, y, z;

	friend bool operator< (const TMonom& m1, const TMonom& m2);
	friend bool operator> (const TMonom& m1, const TMonom& m2);
	friend bool operator== (const TMonom& m1, const TMonom& m2);

	friend std::ostream& operator<< (std::ostream& out, const TMonom& m);
	TMonom& operator=(const TMonom& m) {
		if (this == &m) 
			return *this;
		coeff = m.coeff;
		x = m.x;
		y = m.y;
		z = m.z;
		return *this;
	}
	TMonom(int tcoeff = 0, int tx = 0, int ty = 0, int tz = 0) {
		coeff = tcoeff;
		x = tx;
		y = ty;
		z = tz;
	}
};
	//--------------------------//
bool operator< (const TMonom& m1, const TMonom& m2) {
	if ((m1.x * 100 + m1.y * 10 + m1.z) < (m2.x * 100 + m2.y * 10 + m2.z)) {
		return true;
	}
	else
		return false;
}

bool operator> (const TMonom& m1, const TMonom& m2) {
	if ((m1.x * 100 + m1.y * 10 + m1.z) > (m2.x * 100 + m2.y * 10 + m2.z)) {
		return true;
	}
	else
		return false;
}

bool operator== (const TMonom& m1, const TMonom& m2) {
	if ((m1.x == m2.x) && (m1.y == m2.y) && (m1.z == m2.z)) {
			return true;
	}
	return false;
}

std::ostream& operator<< (std::ostream& out, const TMonom& m) {
	//if (m.coeff == 1)
	//	out << "x^" << m.x << "y^" << m.y << "z^" << m.z;
	//else if (m.coeff > 0)
	//	out << "+ " << m.coeff << "x^" << m.x << "y^" << m.y << "z^" << m.z;
	//else if (m.coeff < 0)
	//	out << "- " <<  -m.coeff << "x^" << m.x << "y^" << m.y << "z^" << m.z;
	out << m.coeff << "x" << m.x << "y" << m.y << "z" << m.z; 
	return out;
}

//-------------------------------------------------------------------------------------//


template <class T>
class TList
{
protected:
	TLink<T> *pFirst, *pLast, *pCurr, *pPrev, *pStop;
	int size, pos;
public:
	TList() {
		pStop = NULL;
		pFirst = pLast = pCurr = pPrev = pStop;
		size = pos = 0;
	}
	~TList() {
		while (pFirst != pStop) {
			TLink<T>* tmp = pFirst;
			pFirst = pFirst->pNext;
			tmp = pStop;
		}
		pLast = pCurr = pPrev = pStop;
	}

	void InsFirst(T elem) {
		if (size) {
			TLink<T>* tmp = new TLink<T>;
			tmp->val = elem;
			tmp->pNext = pFirst;
			pFirst = tmp;
		}
		else {
			pFirst = new TLink<T>;
			pFirst->val = elem;
			pFirst->pNext = pStop;
			pLast = pFirst;
		}
		size++;
	}

	void InsLast(T elem) {
		if (size) {
			TLink<T>* tmp = new TLink<T>;
			tmp->val = elem;
			tmp->pNext = pStop;
			pLast->pNext = tmp;
			pLast = tmp;
			size++;
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
				tmp = pStop;
			}
			else {
				pFirst = pLast = pStop;
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
			InsFirst(elem);
		else {
			TLink<T>* tmp = new TLink<T>;
			tmp->pNext = pCurr;
			pPrev->pNext = tmp;
			pPrev = tmp;
			tmp->val = elem;
			size++;
		}
	}

	virtual T GetCurr() {
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
	bool IsEnd() { return pCurr == pStop; }
	int GetSize() { return size; }

	void Print() {
		TLink<T> *tmp  = pFirst;
		while (tmp != pStop)
		{
			std::cout << tmp->val << ' ';
			tmp = tmp->pNext;
		}
	}
};

