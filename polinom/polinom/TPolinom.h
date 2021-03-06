#pragma once
#include "THeadList.h"



class TPolinom: private THeadList<TMonom>
{
	TLink<TMonom>* pFirst, * pLast, * pCurr, * pPrev, * pStop;
	TLink<TMonom>* pHead;
public:
	TPolinom() : THeadList<TMonom>() {
		pHead->val.x = 0;
		pHead->val.y = 0;
		pHead->val.z = 0;
		pHead->val.coeff = 0;
	}
	void InsMonom(TMonom& m) {
		for (Reset(); !IsEnd(); GoNext()) {
			if (pCurr->val < m) {
				InsCurr(m);
				break;
			}
			if (pCurr->val == m) {
				if (m.coeff - pCurr->val.coeff == 0)
					DelCurr();
				else
					pCurr->val.coeff += m.coeff;
				break;
			}
		}
		if (IsEnd())
			InsLast(m);
	}
	
	//void operator+= (TPolinom& Q) {
	//	for(Q.Reset(); !Q.IsEnd(); Q.GoNext()) {
	//		this->InsMonom(Q.GetCurr());
	//	}
	//}

	TPolinom& operator=(TPolinom& Q) {
		if (this == &Q)
			return;
		while (pFirst != pStop)
		{
			DelFirst();
		}
		for (Q.Reset(); !Q.IsEnd(); Q.GoNext())
			this->InsLast(Q.GetCurr());
		return *this;
	}
	void operator+=(TPolinom& Q) {

	}
};

