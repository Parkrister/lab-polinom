#pragma once
#include "THeadList.h"
#include "TList.h"


class TPolinom: public THeadList<TMonom>
{
public:
	TPolinom() : THeadList<TMonom>() {
		THeadList<TMonom>::pHead->val.x = 0;
		THeadList<TMonom>::pHead->val.y = 0;
		THeadList<TMonom>::pHead->val.z = -1;
		THeadList<TMonom>::pHead->val.coeff = 0;

		TList<TMonom>::pFirst = TList<TMonom>::pLast = TList<TMonom>::pCurr = TList<TMonom>::pPrev = TList<TMonom>::pStop;
	}
	void InsMonom(TMonom& m) {
		for (Reset(); !IsEnd(); GoNext()) {
			if (TList<TMonom>::pCurr->val < m) {
				InsCurr(m);
				break;
			}
			if (TList<TMonom>::pCurr->val == m) {
				if (m.coeff + TList<TMonom>::pCurr->val.coeff == 0)
					DelCurr();
				else
					TList<TMonom>::pCurr->val.coeff += m.coeff;
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

	TPolinom& operator= (TPolinom& Q) {
		if (this == &Q)
			return *this;
		while (TList<TMonom>::pFirst != TList<TMonom>::pStop)
		{
			DelFirst();
		}
		for (Q.Reset(); !Q.IsEnd(); Q.GoNext())
			this->InsLast(Q.GetCurr());
		return *this;
	}

	void operator+=(TPolinom& Q) {
		for (Q.Reset(), Reset(); !Q.IsEnd();) {
			if (Q.GetCurr() > GetCurr()) {
				InsCurr(Q.GetCurr());
				Q.GoNext();
			}
			else if (GetCurr() > Q.GetCurr()) {
				GoNext();
			}
			else {
				double tmp = TList<TMonom>::pCurr->val.coeff + Q.TList<TMonom>::pCurr->val.coeff;
				if (tmp) {
					TList<TMonom>::pCurr->val.coeff = tmp;
					GoNext();
					Q.GoNext();
				}
				else {
					DelCurr();
					GoNext();
				}
			}
		}
	}
	
	TPolinom& operator+ (TPolinom& Q) {
		TPolinom tmp;
		TMonom mon;
		for (Reset(); !IsEnd(); GoNext())
			mon = GetCurr();
			tmp.InsMonom(mon);
		tmp += Q;
		return tmp;
	}

	TPolinom& operator- (TPolinom& Q) const{
		TPolinom tmp = *this;
		tmp = tmp * (-1);
		return tmp;
	}

	TPolinom operator* (TPolinom& Q){
		TPolinom tmp = *this;
		TPolinom res;
		for (Q.Reset(); !Q.IsEnd(); Q.GoNext()) {
			for (tmp.Reset(); !tmp.IsEnd(); tmp.GoNext()) {
				TMonom m;
				m.coeff = tmp.GetCurr().coeff * Q.GetCurr().coeff;
				m.x = tmp.GetCurr().x * Q.GetCurr().x;
				m.y = tmp.GetCurr().y * Q.GetCurr().y;
				m.z = tmp.GetCurr().z * Q.GetCurr().z;
				res.InsMonom(m);
			}
		}
		return res;
	}
	
	TPolinom& operator* (int d) {	
		TPolinom tmp = *this;
		for (tmp.Reset(); !tmp.IsEnd(); tmp.GoNext()) {
			tmp.TList<TMonom>::pCurr->val.coeff *= d;
		}
		return tmp;
	}

	TPolinom& operator+ (int d) {
		TPolinom t = *this;
		TMonom m(d, 0, 0, 0);
		t.InsMonom(m);
		return t;
	}
};
