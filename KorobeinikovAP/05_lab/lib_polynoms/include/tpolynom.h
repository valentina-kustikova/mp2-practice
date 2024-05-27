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
	TPolynom(const string name);
	TPolynom(TRingList<TMonom>* obj);
	TPolynom(const TPolynom& obj);
	~TPolynom();

	const TPolynom& operator=(const TPolynom& obj);


	TPolynom operator + (const TPolynom& obj) const;
	TPolynom operator -(const TPolynom& obj) const;
	TPolynom operator - () const;
	TPolynom operator * (const TPolynom& obj) const;
	
	TPolynom dif_x() const;
	TPolynom dif_y() const;
	TPolynom dif_z() const;
	double operator () (double x, double y, double z);
	


	TNode<TMonom>* GetCurrent() const;
	string GetString() const {
		return polynom.GetInfix();
	}

	friend ostream& operator<<(ostream& os, const TPolynom& polynom) {
		os <<polynom.GetString();
		return os;
	}
};


#endif // 0