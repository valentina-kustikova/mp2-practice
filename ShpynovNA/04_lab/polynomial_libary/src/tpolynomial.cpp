#include "tpolynomial.h"

bool TPolynomial::operator==(const TPolynomial& p) const {
	TPolynomial tmpThis(*this);
	tmpThis.monomials.reset();
	TPolynomial tmpP(p);
	tmpP.monomials.reset();
	while (!tmpP.monomials.IsEnded() || !tmpThis.monomials.IsEnded()) {
		if ((!tmpP.monomials.IsEnded() && tmpThis.monomials.IsEnded()) || (tmpP.monomials.IsEnded() && !tmpThis.monomials.IsEnded()))
			return false;
		if (tmpP.monomials.GetCurrent()->data != tmpThis.monomials.GetCurrent()->data)
			return false;
		tmpP.monomials.next();
		tmpThis.monomials.next();
	}
	return true;
}


string TPolynomial::ToString() const {
	string S;
	TPolynomial p(*this);
	p.monomials.reset();
	if (p.monomials.IsEmpty())
		return "0";
	if ((p.monomials.GetCurrent()->data.coef == 0) && (p.monomials.GetCurrent()->data.degr == 0))
		S.push_back('0');
	else if ((p.monomials.GetCurrent()->data.coef == 0) && (p.monomials.GetCurrent()->data.degr != 0)) {}
	else if ((p.monomials.GetCurrent()->data.coef < 0) && (p.monomials.GetCurrent()->data.degr == 0)) {
		S.append("-");
		string tmp;
		tmp = p.monomials.GetCurrent()->data.ToString();
		tmp.erase(0, 1);
		S.append(tmp);
	}else if ((p.monomials.GetCurrent()->data.coef < 0) && (p.monomials.GetCurrent()->data.degr != 0)) {
		S.append("-");
		S.append(p.monomials.GetCurrent()->data.ToString());
	}
	else
		S.append(p.monomials.GetCurrent()->data.ToString());
	try { p.monomials.next(); }
	catch (...) { return S; }
	int k = -1;
	while (!p.monomials.IsEnded()) {
		k++;
		if ((p.monomials.GetCurrent()->data.coef < 0)&&(p.monomials.GetCurrent()->data.degr == 0)) {
			S.append(" - ");
			string tmp;
			tmp = p.monomials.GetCurrent()->data.ToString();
			tmp.erase(0, 1);
			S.append(tmp);
			p.monomials.next();
			continue;
		}
		else if ((p.monomials.GetCurrent()->data.coef < 0) && (p.monomials.GetCurrent()->data.degr != 0)) {
			S.append(" - ");
			S.append(p.monomials.GetCurrent()->data.ToString());
			p.monomials.next();
			continue;
		}
		else if (p.monomials.GetCurrent()->data.coef > 0)
			S.append(" + ");
		else if ((p.monomials.GetCurrent()->data.coef == 0) && (k == 0))
			return S;
		else if ((p.monomials.GetCurrent()->data.coef == 0) && (k != 0)) {
			p.monomials.next();
			continue;
		}
		S.append(p.monomials.GetCurrent()->data.ToString());
		p.monomials.next();
	}
	return S;
}


void TPolynomial::PutNewMonomialInPlace(TMonomial& m) {
	monomials.reset();
	if (monomials.IsEmpty()) {
		monomials.InsertFirst(m);
		return;
	}
	if ((monomials.GetCurrent()->data.coef == 0) &&(monomials.GetCurrent()->data.degr == 0)){
		monomials.clear();
		monomials.InsertFirst(m);
		return;
	}
	if (monomials.GetCurrent()->data < m) {
		monomials.InsertFirst(m);
		return;
	}
	while ((monomials.GetCurrent()->data > m) && (!monomials.IsEnded()))
		monomials.next();
	if (monomials.GetCurrent()->data.degr == m.degr) {
		monomials.GetCurrent()->data.coef += m.coef;
		if (monomials.GetCurrent()->data.coef == 0) {
			monomials.DeleteCurrentNode();
		}
		return;
	}
	if (!monomials.IsEnded())
		monomials.InsertBefore(monomials.GetCurrent()->data, m);
	else
		monomials.InsertLast(m);
}

TPolynomial TPolynomial::operator+(const TPolynomial& p) {
	TPolynomial result(*this);
	TPolynomial tmp(p);
	tmp.monomials.reset();
	while (!tmp.monomials.IsEnded() && (tmp.monomials.GetCurrent() != nullptr))
	{
		result.PutNewMonomialInPlace(tmp.monomials.GetCurrent()->data);
		tmp.monomials.next();
	}
	return result;
}
TPolynomial TPolynomial::operator*(const double& b) {
	TPolynomial tmp(*this);
	tmp.monomials.reset();
	while (!tmp.monomials.IsEnded())
	{
		try {
			tmp.monomials.GetCurrent()->data.coef *= b;
			tmp.monomials.next();
		}
		catch (...) {
			continue;
		}
	}
	return tmp;
}
TPolynomial TPolynomial::operator-(const TPolynomial& p) {
	TPolynomial tmpNeg(p);
	return this->operator+(tmpNeg * (-1));
}
TPolynomial TPolynomial::operator*(const TPolynomial& p) {
	TPolynomial result("0");
	TPolynomial tmpThis(*this);
	TPolynomial tmpP(p);
	tmpThis.monomials.reset();
	while (!tmpThis.monomials.IsEnded()) {
		tmpP.monomials.reset();
		while (!tmpP.monomials.IsEnded()) {
			TMonomial tmpMonomial = tmpThis.monomials.GetCurrent()->data;
			TMonomial tmpMonomial1 = tmpP.monomials.GetCurrent()->data;
			double Coef = tmpMonomial.coef * tmpMonomial1.coef;
			short int Degr = tmpMonomial.degr + tmpMonomial1.degr;

			if (Degr > 999)
				throw;

			result.PutNewMonomialInPlace(TMonomial(Coef, Degr));

			tmpP.monomials.next();
		}

		tmpThis.monomials.next();
	}
	return result;
}

const TPolynomial& TPolynomial::operator=(const TPolynomial& p) {
	if (this == &p)
	{
		return *this;
	}
	name = p.name;
	monomials = p.monomials;
	return (*this);
}
double TPolynomial::operator()(const double x, const double y, const double z) const {
	TPolynomial tmp(*this);
	double result = 0;
	tmp.monomials.reset();
	while (!tmp.monomials.IsEnded()) {
		double i = tmp.monomials.GetCurrent()->data.coef;
		i *= pow(x, tmp.monomials.GetCurrent()->data.degr / 100);
		i *= pow(y, tmp.monomials.GetCurrent()->data.degr / 10 % 10);
		i *= pow(z, tmp.monomials.GetCurrent()->data.degr % 10);
		result += i;
		tmp.monomials.next();
	}
	return result;
}

TPolynomial TPolynomial::DerivativeX() const {
	TPolynomial tmp(*this);
	tmp.monomials.reset();
	TPolynomial tmpdx = TPolynomial("0");
	while (!tmp.monomials.IsEnded()) {
		if (tmp.monomials.GetCurrent()->data.degr / 100 != 0) {
			double Coef = tmp.monomials.GetCurrent()->data.coef * (tmp.monomials.GetCurrent()->data.degr / 100);
			int16_t Degr = tmp.monomials.GetCurrent()->data.degr - 100;
			tmpdx.PutNewMonomialInPlace(TMonomial(Coef, Degr));
		}
		tmp.monomials.next();
	}
	tmpdx.name = tmpdx.ToString();
	return tmpdx;
}
TPolynomial TPolynomial::DerivativeY() const {
	TPolynomial tmp(*this);
	tmp.monomials.reset();
	TPolynomial tmpdx = TPolynomial("0");
	while (!tmp.monomials.IsEnded()) {
		if (tmp.monomials.GetCurrent()->data.degr / 10 % 10 != 0) {
			double Coef = tmp.monomials.GetCurrent()->data.coef * (tmp.monomials.GetCurrent()->data.degr / 10 % 10);
			int16_t Degr = tmp.monomials.GetCurrent()->data.degr - 10;
			tmpdx.PutNewMonomialInPlace(TMonomial(Coef, Degr));
		}
		tmp.monomials.next();
	}
	return tmpdx;
}
TPolynomial TPolynomial::DerivativeZ() const {
	TPolynomial tmp(*this);
	tmp.monomials.reset();
	TPolynomial tmpdx = TPolynomial("0");
	while (!tmp.monomials.IsEnded()) {
		if (tmp.monomials.GetCurrent()->data.degr % 10 != 0) {
			double Coef = tmp.monomials.GetCurrent()->data.coef * (tmp.monomials.GetCurrent()->data.degr % 10);
			int16_t Degr = tmp.monomials.GetCurrent()->data.degr - 1;
			tmpdx.PutNewMonomialInPlace(TMonomial(Coef, Degr));
		}
		tmp.monomials.next();
	}
	return tmpdx;
}

void TPolynomial::DividePolynomialName(const string& str1) {
	if (str1 == "") {
		this->PutNewMonomialInPlace(TMonomial(0, 0));
		return;
	}
	string str;
	for (int i = 0; i < str1.length(); i++) {
		if (str1[i] != ' ')
			str.push_back(str1[i]);
	}
	if (str.length() == 1)
	{
		this->PutNewMonomialInPlace(TMonomial(str[0]-48, 0));
		return;
	}
	string tmpMonoms[30];
	if ((str[0] != '-') && (str[0] != '+'))
		str = "+" + str;
	for (int i = 0, k = -1; i < str.length(); i++) {
		if ((str[i] != '-') && (str[i] != '+')) {
			tmpMonoms[k] += str[i];
		}
		else
			k++;
	}
	string signs;
	for (int i = 0; i < str.length(); i++) {
		if (str[i] == '+')
			signs += "+";
		else if (str[i] == '-')
			signs += "-";
	}
	for (int i = 0; i < signs.length(); i++) {
		if (signs[i] == '-')
			tmpMonoms[i] = "-" + tmpMonoms[i];
	}
	for (int i = 0; i < signs.length(); i++) {
		short degr = 0;
		double coef = 1.0;
		int t = 0;
		if (tmpMonoms[i][t] == '-') {
			coef *= -1;
			t++;
		}
		bool wasChanged = false;
		while (((int)(tmpMonoms[i][t]) - 48 >= 0) && ((int)(tmpMonoms[i][t]) - 48 <= 9)) {
			if (((coef == 1) || (coef == -1)) && (!wasChanged)) {
				coef *= (int)(tmpMonoms[i][t]) - 48;
				wasChanged = true;
			}
			else if (coef >= 0) {
				coef = coef * 10 + ((int)(tmpMonoms[i][t]) - 48);
				wasChanged = true;
			}
			else {
				coef = coef * 10 - ((int)(tmpMonoms[i][t]) - 48);
				wasChanged = true;
			}
			t++;
		}
		for (int n = 0; n < tmpMonoms[i].size(); n++) {
			if ((tmpMonoms[i][n] == 'x') && (tmpMonoms[i][n + 1] == '^'))
				degr += (int(tmpMonoms[i][n + 2]) - 48) * 100;
			if ((tmpMonoms[i][n] == 'x') && (tmpMonoms[i][n + 1] != '^'))
				degr += 100;
			if ((tmpMonoms[i][n] == 'y') && (tmpMonoms[i][n + 1] == '^'))
				degr += (int(tmpMonoms[i][n + 2]) - 48) * 10;
			if ((tmpMonoms[i][n] == 'y') && (tmpMonoms[i][n + 1] != '^'))
				degr += 10;
			if ((tmpMonoms[i][n] == 'z') && (tmpMonoms[i][n + 1] == '^'))
				degr += (int(tmpMonoms[i][n + 2]) - 48);
			if ((tmpMonoms[i][n] == 'z') && (tmpMonoms[i][n + 1] != '^'))
				degr += 1;
		}
		this->PutNewMonomialInPlace(TMonomial(coef, degr));
	}
}

/*void TPolynomial::DividePolynomialName(const string& str1) {
	string str;
	for (int i = 0; i < str1.length(); i++) {
		if (str1[i] != ' ')
			str.push_back(str1[i]);
	}
	string subdiv[30];
	int k = 0;
	int kostyl[30] = { 0 };
	int kostyl2 = 0;
	for (int i = 0; i < str.size(); i++) {
		if (str[i] == '-') {
			if (k == 0)
				if (i == 1)
					kostyl[k + 1] = -1;
				else
					kostyl[k] = -1;
			else
				kostyl[k + 1] = -1;
		}
		if ((str[i] != '+') && (str[i] != '-'))
			subdiv[k] += str[i];
		else if (i != 0)
			k++;

	}
	k++;
	for (int i = 0; i < k; i++) {
		if (subdiv[i][subdiv[i].length() - 1] == '^')
			throw;
		short degr = 0;
		double coef = 1.0;
		int n = 0;
		string tmpstr = "";
		while ((subdiv[i][n] != 'x') && (subdiv[i][n] != 'y') && (subdiv[i][n] != 'z') && (n != subdiv[i].size())) {
			tmpstr += subdiv[i][n];
			if (kostyl[i] == -1)
				kostyl2 = -1;
			else
				kostyl2 = 0;
			n++;
		}
		if ((subdiv[i][0] == 'x') || (subdiv[i][0] == 'y') || (subdiv[i][0] == 'z')) {
			coef = 1;
			if (kostyl[i] == -1)
				coef *= -1;
		}
		if (tmpstr != "") {
			coef = stod(tmpstr);
			if (kostyl2 == -1)
				coef *= -1;
		}
		for (n = 0; n < subdiv[i].size(); n++) {
			if ((subdiv[i][n] == 'x') && (subdiv[i][n + 1] == '^'))
				degr += (int(subdiv[i][n + 2]) - 48) * 100;
			if ((subdiv[i][n] == 'x') && (subdiv[i][n + 1] != '^'))
				degr += 100;
			if ((subdiv[i][n] == 'y') && (subdiv[i][n + 1] == '^'))
				degr += (int(subdiv[i][n + 2]) - 48) * 10;
			if ((subdiv[i][n] == 'y') && (subdiv[i][n + 1] != '^'))
				degr += 10;
			if ((subdiv[i][n] == 'z') && (subdiv[i][n + 1] == '^'))
				degr += (int(subdiv[i][n + 2]) - 48);
			if ((subdiv[i][n] == 'z') && (subdiv[i][n + 1] != '^'))
				degr += 1;
		}
		if ((coef != 0.0) || (tmpstr == "0"))
			this->PutNewMonomialInPlace(TMonomial(coef, degr));
	}
}
*/