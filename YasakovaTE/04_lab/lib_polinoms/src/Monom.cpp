#include "monom.h"

Monom::Monom(const Monom& _monom)
{
	coeff = _monom.coeff;
	stmonom = _monom.stmonom;
}

const Monom& Monom::operator = (const Monom& _monom)
{
	coeff = _monom.coeff;
	stmonom = _monom.stmonom;
	return *this;
}

bool Monom::operator != (const Monom& _monom) const
{
	return stmonom != _monom.stmonom;
}

bool Monom::operator == (const Monom& _monom) const
{
	return stmonom == _monom.stmonom && coeff == _monom.coeff;
}

bool Monom::operator > (const Monom& _monom) const
{
	return stmonom > _monom.stmonom;
}

bool Monom::operator >= (const Monom &_monom) const
{
	return stmonom >= _monom.stmonom;
}

bool Monom::operator < (const Monom& _monom) const
{
	return stmonom < _monom.stmonom;
}

bool Monom::operator <= (const Monom &_monom) const
{
	return stmonom <= _monom.stmonom;
}

Monom Monom::operator + (const Monom& _monom)
{
	Monom res;
	if ((*this).stmonom == _monom.stmonom)
	{
		res.stmonom = (*this).stmonom;
		res.coeff = (*this).coeff + _monom.coeff;
	}
	else throw "no sum monoms";
	return res;
}