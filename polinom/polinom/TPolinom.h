#pragma once
#include "THeadList.h"

template <class T>
struct TMonom {
	double coeff;
	int x, y, z;
	friend bool operator<(const TMonom& m1, TMonom& m2);

};

template <class T>
bool operator<(const TMonom<T>& m1, TMonom<T>& m2) {
	return (m1.x * 100 + m1.y * 10 + m1.z) < (m2.x * 100 + m2.y * 10 + m2.z);
}


template <class T>
class TPolinom: public THeadList<TMonom<T>>
{

};

