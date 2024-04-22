#ifndef __TPOLYNOM_H__
#define __TPOLYNOM_H__

#include <tmonom.h>
#include "tringlist.h"
#include "tarithmetic_expression.h"

class TPolynom{
private:
	TArithmeticExpression polynom;
	TRingList<TMonom>* monoms;


	void GetRingListFromString();  
	string GetStringFromRingList();
	void AddMonom(TMonom& m);

	
	
public:
	TPolynom();
	TPolynom(string name);
	TPolynom(TRingList<TMonom>* obj);
	TPolynom(const TPolynom& obj);
	~TPolynom();
	/*
	TPolynom operator + (const TPolynom& obj);
	TPolynom operator -(const TPolynom& obj);
	TPolynom operator * (const TPolynom& obj);
	const TPolynom operator = (const TPolynom& obj);
	TPolynom dif_x();
	TPolynom dif_y();
	TPolynom dif_z();
	double operator () (double x, double y, double z);
	*/


	TNode<TMonom>* GetCurrent();
	string GetString() {
		return polynom.GetInfix();
	}
};


#endif // 0