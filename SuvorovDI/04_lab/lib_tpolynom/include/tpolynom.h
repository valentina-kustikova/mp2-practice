#include "tlist.h"
#include <iostream>
#include <stdint.h>
#include <cstring>

// move TMonom and TPolynom to different files
// I should make these files into VS Code

class TMonom {
public:
  double coeff_;
  int16_t degree_;

  TMonom();
  TMonom(double coeff, int16_t degree);
  bool operator<(const TMonom&) const;
  bool operator<=(const TMonom&) const;
  bool operator>(const TMonom&) const;
  bool operator>=(const TMonom&) const;
  bool operator==(const TMonom&) const;
  bool operator!=(const TMonom&) const;

  friend std::ostream& operator<< (std::ostream& out, const TMonom& m) {
    out << m.coeff_ << "  " << m.degree_ << std::endl;
	  return out;
  }
};


// Add operator unaryminus!
class TPolynom {
protected:
  std::string name;
  THeadRingList<TMonom> monoms;

  void tokinize_polynom(const std::string& name);
  void InsertToSort(const TMonom& monom);

public:
  TPolynom() : monoms() {}
  TPolynom(const std::string& name);
  TPolynom(const THeadRingList<TMonom>& l);
  TPolynom(const TPolynom& p);
  ~TPolynom() = default;
  
  TPolynom operator+(const TPolynom& p);
  TPolynom operator-(const TPolynom& p);
  TPolynom operator*(TPolynom& p);

  double operator()(double x, double y, double z) const;
  TPolynom dx() const;
  TPolynom dy() const;
  TPolynom dz() const;

  const TPolynom& operator=(const TPolynom& p);

  friend std::ostream& operator<< (std::ostream& out, TPolynom& pol) {
	  pol.monoms.Reset();
    while (!pol.monoms.IsEnded()) {
		  out << pol.monoms.GetCurr()->data;
		  pol.monoms.Next();
    }
	  return out;
  }
};


// NAVIGATIONS INSTEAD GETTERS AND SETTERS!
TPolynom::TPolynom(const std::string& name) : monoms() {
  this->name = name;
  tokinize_polynom(name);
}
 
TPolynom::TPolynom(const THeadRingList<TMonom>& l) : monoms(l) {}

TPolynom::TPolynom(const TPolynom& p) : monoms(p.monoms), name(p.name) {}

void TPolynom::InsertToSort(const TMonom& monom) {
	if (monoms.IsEmpty() || monoms.GetFirst()->data > monom) {
		monoms.InsertFirst(monom);
		return;
	}

	TNode<TMonom>* curr = monoms.GetFirst();
	while (curr->pNext != monoms.GetStop() && curr->pNext->data <= monom) {
		curr = curr->pNext;
	}
	if (curr->data == monom) {
		curr->data.coeff_ = curr->data.coeff_ + monom.coeff_;
		return;
	}
	monoms.InsertAfter(monom, curr->data);
}

// In following operators + - * : I should make the cop of the input TPolynom
// Input -> will remain const, duplicate will use Next()
TPolynom TPolynom::operator+(const TPolynom& p) {
  TPolynom res(this->monoms);
  TNode<TMonom>* curr = p.monoms.GetFirst();
  while (curr != p.monoms.GetStop()) {
    res.InsertToSort(curr->data);
    curr = curr->pNext;
  }

  return res;
}
 
TPolynom TPolynom::operator-(const TPolynom& p) {
  TPolynom negativePol(p);
  TNode<TMonom>* curr = negativePol.monoms.GetFirst();
  while (curr != negativePol.monoms.GetStop()) {
    curr->data.coeff_ = curr->data.coeff_ * (-1);
    curr = curr->pNext;
  }
  return this->operator+(negativePol);
}
 
TPolynom TPolynom::operator*(TPolynom& p) { // const
  TPolynom res_pol;

  monoms.Reset();
  p.monoms.Reset();
  while (!monoms.IsEnded()) {

    while (!p.monoms.IsEnded()) {
      TMonom mon1 = monoms.GetCurr()->data;
      TMonom mon2 = p.monoms.GetCurr()->data;
      double newCoeff = mon1.coeff_ * mon2.coeff_;
      int16_t newDegree = mon1.degree_ + mon2.degree_;

      if (newDegree > 999) throw std::exception("invalid_degree");

      res_pol.InsertToSort(TMonom(newCoeff, newDegree));

      p.monoms.Next();
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
  TPolynom dx_pol = TPolynom();

  TNode<TMonom>* curr = monoms.GetFirst();
  while (curr != monoms.GetStop()) {
    if (curr->data.degree_ / 100 != 0) {
      double newCoeff = curr->data.coeff_ * (curr->data.degree_ / 100);
      int16_t newDegree = curr->data.degree_ - 100;

      dx_pol.InsertToSort(TMonom(newCoeff, newDegree));
    }

    curr = curr->pNext;
  }
  return dx_pol;
}

TPolynom TPolynom::dy() const {
  TPolynom dy_pol = TPolynom();

  TNode<TMonom>* curr = monoms.GetFirst();
  while (curr != monoms.GetStop()) {
    if (curr->data.degree_ / 10 % 10 != 0) {
      double newCoeff = (curr->data.coeff_) * (curr->data.degree_ / 10 % 10);
      int16_t newDegree = curr->data.degree_ - 10;

      dy_pol.InsertToSort(TMonom(newCoeff, newDegree));
    }

    curr = curr->pNext;
  }
  return dy_pol;
}

TPolynom TPolynom::dz() const {
  TPolynom dz_pol = TPolynom();

  TNode<TMonom>* curr = monoms.GetFirst();
  while (curr != monoms.GetStop()) {
    if (curr->data.degree_ % 10 != 0) {
      double newCoeff = (curr->data.coeff_) * (curr->data.degree_ % 10);
      int16_t newDegree = curr->data.degree_ - 1;

      dz_pol.InsertToSort(TMonom(newCoeff, newDegree));
    }

    curr = curr->pNext;
  }
  return dz_pol;
}

const TPolynom& TPolynom::operator=(const TPolynom& p) {
  name = p.name;
  if (p.monoms.IsEmpty()) // operator= для HeadRingList
	{
		monoms.SetFirst(nullptr);
		monoms.SetLast(nullptr);
		monoms.SetCurr(nullptr);
    monoms.SetHead(new TNode<TMonom>(p.monoms.GetHead()->data, monoms.GetHead()));
    monoms.SetStop(monoms.GetHead());
	}

	monoms.SetFirst(new TNode<TMonom>(p.monoms.GetFirst()->data));
	TNode<TMonom>* tmp = monoms.GetFirst();
  TNode<TMonom>* ltmp = p.monoms.GetFirst()->pNext;
	while(ltmp != p.monoms.GetStop())
	{
		tmp->pNext = new TNode<TMonom>(ltmp->data);
		tmp = tmp->pNext;
		ltmp = ltmp->pNext;
	}
	monoms.SetLast(tmp);
	monoms.SetCurr(monoms.GetFirst());
	monoms.SetHead(new TNode<TMonom>(p.monoms.GetHead()->data, monoms.GetFirst()));
  monoms.GetLast()->pNext = monoms.GetHead();

  return *(this);
}

// ===============================================
// FSM!!!

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