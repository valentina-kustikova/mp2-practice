#pragma once
struct Monom {
	double coeff;
	unsigned int stmonom;
	Monom(const double d = 0.0, const int m = 0) { coeff = d; stmonom = m; };
	Monom(const Monom& _monom);
	const Monom& operator = (const Monom& _monom);
	bool operator != (const Monom& _monom) const;
	bool operator == (const Monom& _monom) const;
	bool operator > (const Monom& _monom) const;
	bool operator < (const Monom& _monom) const;
	Monom operator+ (const Monom& _monom);
};
