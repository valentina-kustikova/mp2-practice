#include "tpolynom.h"
#include "tmonom.h"

TPolynom::TPolynom(const std::string& name) : monoms() {
  this->name = name;
  tokinize_polynom(name);
}
 
TPolynom::TPolynom(const THeadRingList<TMonom>& l) : monoms(l) {}

TPolynom::TPolynom(const std::string& name, const TPolynom& p) : monoms(p.monoms), name(p.name) {}

TPolynom::TPolynom(const TPolynom& p) : monoms(p.monoms), name(p.name) {}

void TPolynom::InsertToSort(const TMonom& monom) {
  monoms.Reset();
	if (monoms.IsEmpty() || monoms.GetCurr()->data > monom) {
		monoms.InsertFirst(monom);
		return;
	}

	while (monoms.IsEnded() && monoms.GetCurr()->pNext->data <= monom) {
		monoms.Next();
	}
	if (monoms.GetCurr()->data == monom) {
		monoms.GetCurr()->data.coeff_ = monoms.GetCurr()->data.coeff_ + monom.coeff_;
		return;
	}
	monoms.InsertAfter(monom, monoms.GetCurr()->data);
}

TPolynom operator-(const TPolynom& p) {
  std::string nm = p.GetName();
  if (nm[0] != '-') nm = '+' + nm;
  for (char& c : nm) {
    if (c == '-') c = '+';
    else if (c == '+') c = '-';
  }
  TPolynom negativePol(nm, p);

  while (negativePol.monoms.IsEnded()) {
    negativePol.monoms.GetCurr()->data.coeff_ = negativePol.monoms.GetCurr()->data.coeff_ * (-1);
    negativePol.monoms.Next();
  }

  return negativePol;
}

TPolynom TPolynom::operator+(const TPolynom& p) {
  std::string nm = p.GetName();
  if (nm[0] != '-' && nm[0] != '+') nm = '+' + nm;
  TPolynom res(name + nm, p);
  
  monoms.Reset();
  while (monoms.IsEnded()) {
    res.InsertToSort(monoms.GetCurr()->data);
    monoms.Next();
  }

  return res;
}
 
TPolynom TPolynom::operator-(const TPolynom& p) {
  return this->operator+(-p);
}
 
TPolynom TPolynom::operator*(const TPolynom& p) { // const
  TPolynom res_pol;
  TPolynom tmp_p(p);

  monoms.Reset();
  tmp_p.monoms.Reset();
  while (!monoms.IsEnded()) {

    while (!p.monoms.IsEnded()) {
      TMonom mon1 = monoms.GetCurr()->data;
      TMonom mon2 = tmp_p.monoms.GetCurr()->data;
      double newCoeff = mon1.coeff_ * mon2.coeff_;
      int16_t newDegree = mon1.degree_ + mon2.degree_;

      if (newDegree > 999) throw std::exception("invalid_degree");

      res_pol.InsertToSort(TMonom(newCoeff, newDegree));

      tmp_p.monoms.Next();
    }

    monoms.Next();
  }
  return res_pol;
}

double TPolynom::operator()(double x, double y, double z) const {
  double result = 0;

  TNode<TMonom>* curr = monoms.GetFirst();
  while (curr != monoms.GetStop()) {
    double mn;
    mn = curr->data.coeff_;
    mn *= pow(x, curr->data.degree_ / 100);
    mn *= pow(y, curr->data.degree_ / 10 % 10);
    mn *= pow(z, curr->data.degree_ % 10);

    result += mn;
    curr = curr->pNext;
  }
  return result;
}

TPolynom TPolynom::dx() const {
  TPolynom dx_pol;
  TPolynom tmp_this(*this);

  while (tmp_this.monoms.IsEnded()) {
    if (tmp_this.monoms.GetCurr()->data.degree_ / 100 != 0) {
      double newCoeff = tmp_this.monoms.GetCurr()->data.coeff_ * (tmp_this.monoms.GetCurr()->data.degree_ / 100);
      int16_t newDegree = tmp_this.monoms.GetCurr()->data.degree_ - 100;

      dx_pol.InsertToSort(TMonom(newCoeff, newDegree));
    }

    tmp_this.monoms.Next();
  }
  return dx_pol;
}

TPolynom TPolynom::dy() const {
  TPolynom dy_pol;
  TPolynom tmp_this(*this);

  while (tmp_this.monoms.IsEnded()) {
    if (tmp_this.monoms.GetCurr()->data.degree_ / 10 % 10 != 0) {
      double newCoeff = tmp_this.monoms.GetCurr()->data.coeff_ * (tmp_this.monoms.GetCurr()->data.degree_ / 10 % 10);
      int16_t newDegree = tmp_this.monoms.GetCurr()->data.degree_ - 10;

      dy_pol.InsertToSort(TMonom(newCoeff, newDegree));
    }

    tmp_this.monoms.Next();
  }
  return dy_pol;
}

TPolynom TPolynom::dz() const {
  TPolynom dz_pol;
  TPolynom tmp_this(*this);

  while (tmp_this.monoms.IsEnded()) {
    if (tmp_this.monoms.GetCurr()->data.degree_  % 10 != 0) {
      double newCoeff = tmp_this.monoms.GetCurr()->data.coeff_ * (tmp_this.monoms.GetCurr()->data.degree_  % 10);
      int16_t newDegree = tmp_this.monoms.GetCurr()->data.degree_ - 1;

      dz_pol.InsertToSort(TMonom(newCoeff, newDegree));
    }

    tmp_this.monoms.Next();
  }
  return dz_pol;
}

const TPolynom& TPolynom::operator=(const TPolynom& p) {
  name = p.name;
  monoms = p.monoms;

  return *(this);
}

// ===============================================

void TPolynom::tokinize_polynom(const std::string& name) {
	std::string str = name;
	while (!str.empty()) {
		int degree = 0;
		size_t j = str.find_first_of("+-", 1);
		std::string monom = str.substr(0, j);
		str.erase(0, j);
		std::string coefficent = monom.substr(0, monom.find_first_of("xyz"));
		TMonom tmp(0.0, -1);
		tmp.coeff_ = (coefficent == "" || coefficent == "+") ? 1 : (coefficent == "-") ? -1 : stod(coefficent);
		monom.erase(0, monom.find_first_of("xyz"));
		for (size_t i = 0; i < monom.size(); ++i) {
			if (isalpha(monom[i])) {
				int exp = 1;
				if (monom[i + 1] == '^') {
					size_t exp_start = i + 2;
					while (isdigit(monom[exp_start])) {
						exp_start++;
					}
					exp = stoi(monom.substr(i + 2, exp_start - i - 2));
				}
				switch (monom[i]) {
				case 'x':
					degree += exp * 100;
					break;
				case 'y':
					degree += exp * 10;
					break;
				case 'z':
		    		degree += exp * 1;
					break;
				default:
					throw ("exp");
					break;
				}
			}
		}
		tmp.degree_ = degree;
		if (tmp.coeff_ != 0) {
			this->InsertToSort(tmp);
		}
	}
}