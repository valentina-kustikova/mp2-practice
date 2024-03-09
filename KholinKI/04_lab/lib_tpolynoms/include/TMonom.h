#ifndef _TMONOM_H
#define _TMONOM_H



class TMonom {
private:
	double coeff;
	int wrap_degree;
public:
	TMonom(double c_val = 1, int wd_val = 0);
	TMonom(const TMonom& mon);
	

	
	void SetCoeff(int c_val) { coeff = c_val; }
	void SetWD(int wd_val) { wrap_degree = wd_val; }
	double GetCoeff(void)const { return coeff; }
	int GetWD(void)const { return wrap_degree; }

	TMonom& operator=(const TMonom& monom);
	bool operator<(const TMonom& monom)const;
	bool operator<=(const TMonom& monom)const;
	bool operator!=(const TMonom& monom)const;
	TMonom operator*(const TMonom& monom)const;
	//virtual bool operator>(const TData& data)const;
	//virtual bool operator==(const TData& data)const;
	
};


#endif