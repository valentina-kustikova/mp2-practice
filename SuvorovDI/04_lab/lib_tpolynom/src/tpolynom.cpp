#pragma once
#include "tpolynom.h"
#include "tlist.h"
#include <typeinfo>
#include <iostream>
#include <cmath>
#include <string>


TMonom::TMonom(double coeff, int16_t degree) {
  coeff_ = coeff;
  degree_ = degree;
}

TData* TMonom::copy() const {
  return new TMonom(coeff_, degree_);
}

// Сравнение по коэффициентам!
bool TMonom::operator<(const TData& data) const {
  try {
    const TMonom& monomFromData = dynamic_cast<const TMonom&>(data);
    return degree_ < monomFromData.degree_;
  }
  catch (std::bad_cast& e) {
    std::cout << e.what();
    
  }
}
bool TMonom::operator<=(const TData& data) const {
  try {
    const TMonom& monomFromData = dynamic_cast<const TMonom&>(data);
    return degree_ <= monomFromData.degree_;
  }
  catch (std::bad_cast& e) {
    std::cout << e.what();
  }
}
bool TMonom::operator>(const TData& data) const {
  try {
    const TMonom& monomFromData = dynamic_cast<const TMonom&>(data);
    return degree_ > monomFromData.degree_;
  }
  catch (std::bad_cast& e) {
    std::cout << e.what();
  }
}
bool TMonom::operator>=(const TData& data) const {
  try {
    const TMonom& monomFromData = dynamic_cast<const TMonom&>(data);
    return degree_ >= monomFromData.degree_;
  }
  catch (std::bad_cast& e) {
    std::cout << e.what();
  }
}
// Для приведения подобных
bool TMonom::operator==(const TData& data) const {
  try {
    const TMonom& monomFromData = dynamic_cast<const TMonom&>(data);
    return degree_ == monomFromData.degree_;
  }
  catch (std::bad_cast& e) {
    std::cout << e.what();
  }
}
bool TMonom::operator!=(const TData& data) const {
  try {
    const TMonom& monomFromData = dynamic_cast<const TMonom&>(data);
    return degree_ != monomFromData.degree_;
  }
  catch (std::bad_cast& e) {
    std::cout << e.what();
  }
}

// -----------------------------------------------------------------------------------

TPolynom::TPolynom() : monoms() {
  monoms.InsertLast(TMonom(-1, 0));
}

TPolynom::TPolynom(const std::string& name) : monoms() {
  monoms.InsertLast(TMonom(-1, 0));
  this->name = name;
  tokinize_polynom(name);
}

TPolynom::TPolynom(const THeadRingList* l) : monoms(*l) {}

TPolynom::TPolynom(const TPolynom& p) : monoms(p.monoms), name(p.name) {}

TPolynom TPolynom::operator+(const TPolynom& p) {
  TPolynom res(&(this->monoms));
  TNode* curr = p.monoms.pFirst;
  while (curr != p.monoms.pStop) {
    res.monoms.InsertToSort(*(curr->data));
    curr = curr->pNext;
  }

  return res;
}

TPolynom TPolynom::operator-(const TPolynom& p) {
  TPolynom negativePol(p);
  TNode* curr = negativePol.monoms.pFirst;
  while (curr != negativePol.monoms.pStop) {
    TMonom* monomFromData = dynamic_cast<TMonom*>(curr->data);
    monomFromData->SetCoeff(monomFromData->GetCoeff() * (-1));
    curr = curr->pNext;
  }
  return this->operator+(negativePol);
}

TPolynom TPolynom::operator*(TPolynom& p) {
  THeadRingList pol_list = THeadRingList();
  pol_list.InsertFirst(TMonom(-1, 0));

  monoms.Reset();
  p.monoms.Reset();
  while (!monoms.IsEnded()) {

    while (!p.monoms.IsEnded()) {
      TMonom* mon1 = dynamic_cast<TMonom*>(monoms.pCurr->data);
      TMonom* mon2 = dynamic_cast<TMonom*>(p.monoms.pCurr->data);
      double newCoeff = mon1->GetCoeff()*mon2->GetCoeff();
      int16_t newDegree = mon1->GetDegree() + mon2->GetDegree();

      if (newDegree > 999) throw std::exception("invalid_degree");

      pol_list.InsertToSort(TMonom(newCoeff, newDegree));

      p.monoms.Next();
    }

    monoms.Next();
  }
  return TPolynom(&pol_list);
}

double TPolynom::operator()(double x, double y, double z) const {
  double result;

  TNode* curr = monoms.pFirst;
  while (curr != monoms.pStop) {
    double mn;
    TMonom* mon = dynamic_cast<TMonom*>(curr->data);
    mn = mon->GetCoeff();
    mn *= pow(x, mon->GetDegree()/100);
    mn *= pow(y, mon->GetDegree()/10%10);
    mn *= pow(z, mon->GetDegree()%10);

    result += mn;
    curr = curr->pNext;
  }
  return result;
}

TPolynom TPolynom::dx() const {
  TPolynom dx_pol = TPolynom();

  TNode* curr = monoms.pFirst;
  while (curr != monoms.pStop) {
    TMonom* mon = dynamic_cast<TMonom*>(curr->data);
    if (mon->GetDegree()/100 != 0) {
      double newCoeff = mon->GetCoeff() * (mon->GetDegree()/100);
      int16_t newDegree = mon->GetDegree() - 100;

      dx_pol.monoms.InsertToSort(TMonom(newCoeff, newDegree));
    }

    curr = curr->pNext;
  }
  return dx_pol;
}

TPolynom TPolynom::dy() const {
  TPolynom dy_pol = TPolynom();

  TNode* curr = monoms.pFirst;
  while (curr != monoms.pStop) {
    TMonom* mon = dynamic_cast<TMonom*>(curr->data);
    if (mon->GetDegree()/10%10 != 0) {
      double newCoeff = (mon->GetCoeff()) * (mon->GetDegree()/10%10);
      int16_t newDegree = mon->GetDegree() - 10;

      dy_pol.monoms.InsertToSort(TMonom(newCoeff, newDegree));
    }

    curr = curr->pNext;
  }
  return dy_pol;
}

TPolynom TPolynom::dz() const {
  TPolynom dz_pol = TPolynom();

  TNode* curr = monoms.pFirst;
  while (curr != monoms.pStop) {
    TMonom* mon = dynamic_cast<TMonom*>(curr->data);
    if (mon->GetDegree()%10 != 0) {
      double newCoeff = (mon->GetCoeff()) * (mon->GetDegree()%10);
      int16_t newDegree = mon->GetDegree() - 1;

      dz_pol.monoms.InsertToSort(TMonom(newCoeff, newDegree));
    }

    curr = curr->pNext;
  }
  return dz_pol;
}

const TPolynom& TPolynom::operator=(const TPolynom& p) {
  name = p.name;
  if (p.monoms.IsEmpty())
	{
		monoms.pFirst=nullptr;
		monoms.pLast=nullptr;
		monoms.pCurr=nullptr;
    monoms.pHead = new TNode(p.monoms.pHead->data);
    monoms.pHead->pNext = monoms.pHead;
    monoms.pStop = monoms.pHead;
	}

	monoms.pFirst = new TNode(p.monoms.pFirst->data);
	TNode* tmp = monoms.pFirst; 
  TNode* ltmp = p.monoms.pFirst->pNext;
	while(ltmp != p.monoms.pStop)
	{
		tmp->pNext = new TNode(ltmp->data);
		tmp = tmp->pNext;
		ltmp = ltmp->pNext;
	}
	monoms.pLast = tmp;
	monoms.pCurr = monoms.pFirst;
	monoms.pHead = new TNode(p.monoms.pHead->data);
  monoms.pHead->pNext = monoms.pFirst;
  monoms.pLast->pNext = monoms.pHead;

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
		tmp.SetCoeff((coefficent == "" || coefficent == "+") ? 1 : (coefficent == "-") ? -1 : stod(coefficent));
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
		tmp.SetDegree(degree);
		if (tmp.GetCoeff() != 0) {
			monoms.THeadRingList::InsertToSort(tmp);
		}
	}
}