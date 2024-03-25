#include "tlist.h"
#include <iostream>
#include <stdint.h>
#include <cstring>

// Maybe we can make the TPolynom class friendly to THeadRingList??
// If so, then we won't need to create getters and setters for each pointer in the list.

// Do we really need copy-method for TMonom
// TMonom contains only non-pointer fields!
// As far as I understand, earlier in TNode - "data" there was a pointer to TData (so "copy" was needed for this)
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

  void output_data() const {
    std::cout << coeff_ << "  " << degree_ << std::endl;
  }
};

template <typename TData>
class TPolynom {
protected:
  std::string name;
  THeadRingList<TData> monoms;

public:
  void tokinize_polynom(const std::string& name);

  TPolynom() : monoms() {}
  TPolynom(const std::string& name);
  TPolynom(const THeadRingList<TData>& l);
  TPolynom(const TPolynom<TData>& p);
  ~TPolynom() = default;

  void InsertToSort(const TData& data);
  TPolynom<TData> operator+(const TPolynom<TData>& p);
  TPolynom<TData> operator-(const TPolynom<TData>& p);
  TPolynom<TData> operator*(TPolynom<TData>& p);

  double operator()(double x, double y, double z) const;
  TPolynom<TData> dx() const;
  TPolynom<TData> dy() const;
  TPolynom<TData> dz() const;

  const TPolynom<TData>& operator=(const TPolynom<TData>& p);

  void output_polynom() {
    monoms.Reset();
    while (!monoms.IsEnded()) {
      monoms.GetCurr()->data.output_data();// operator <<
      monoms.Next();
    }
  }
};

template <typename TData>
TPolynom<TData>::TPolynom(const std::string& name) : monoms() {
  this->name = name;
  tokinize_polynom(name);
}

// At first, parameter was a pointer to THeadRingList
// But I don't understand is it necessary?
// So I replaced the pointer with a reference
template <typename TData>
TPolynom<TData>::TPolynom(const THeadRingList<TData>& l) : monoms<TData>(l) {}

template <typename TData>
TPolynom<TData>::TPolynom(const TPolynom<TData>& p) : monoms<TData>(p.monoms), name(p.name) {}

template <typename TData>
void TPolynom<TData>::InsertToSort(const TData& data) {
	if (monoms.IsEmpty() || monoms.GetFirst()->data > data) {
		monoms.InsertFirst(data);
		return;
	}

	TNode<TData>* curr = monoms.GetFirst();
	while (curr->pNext != monoms.GetStop() && curr->pNext->data <= data) {
		curr = curr->pNext;
	}
	if (curr->data == data) {
		curr->data.coeff_ = curr->data.coeff_ + data.coeff_;
		return;
	}
	monoms.InsertAfter(data, curr->data);
}

// Is there some difference between usage curr-variable and while AND pCurr and Next() while isEnded???
// Which way is better???

// And I can't make the following methods constant, if I use Next, 
// because Next change object field pCurr!! Is it normal???
template <typename TData>
TPolynom<TData> TPolynom<TData>::operator+(const TPolynom<TData>& p) {
  TPolynom<TData> res(this->monoms);
  TNode<TData>* curr = p.monoms.GetFirst();
  while (curr != p.monoms.GetStop()) {
    res.InsertToSort(curr->data);
    curr = curr->pNext;
  }

  return res;
}

template <typename TData>
TPolynom<TData> TPolynom<TData>::operator-(const TPolynom<TData>& p) {
  TPolynom<TData> negativePol(p);
  TNode* curr = negativePol.monoms.GetFirst();
  while (curr != negativePol.monoms.GetStop()) {
    curr->data.coeff_ = curr->data.coeff_ * (-1);
    curr = curr->pNext;
  }
  return this->operator+(negativePol);
}

// Please, remind me, what difference between :
// TPolynom<TData> res_pol();
// TPolynom<TData> dx_pol = TPolynom<TData>();
// Only that in the first case, the default constructor is called and initializes the object directly. And in the second, the default constructor is called, creates and returns a new object, which initializes our object using the copy constructor.

template <typename TData>
TPolynom<TData> TPolynom<TData>::operator*(TPolynom<TData>& p) {
  TPolynom<TData> res_pol();

  monoms.Reset();
  p.monoms.Reset();
  while (!monoms.IsEnded()) {

    while (!p.monoms.IsEnded()) {
      TMonom mon1 monoms.GetCurr()->data;
      TMonom mon2 p.monoms.GetCurr()->data;
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

template <typename TData>
double TPolynom<TData>::operator()(double x, double y, double z) const {
  double result = 0;

  TNode<TData>* curr = monoms.GetFirst();
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

template <typename TData>
TPolynom<TData> TPolynom<TData>::dx() const {
  TPolynom<TData> dx_pol = TPolynom<TData>();

  TNode<TData>* curr = monoms.GetFirst();
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

template <typename TData>
TPolynom<TData> TPolynom<TData>::dy() const {
  TPolynom<TData> dy_pol = TPolynom<TData>();

  TNode<TData>* curr = monoms.GetFirst();
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

template <typename TData>
TPolynom<TData> TPolynom<TData>::dz() const {
  TPolynom<TData> dz_pol = TPolynom<TData>();

  TNode<TData>* curr = monoms.GetFirst();
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

// Can I make the following code shorter?
// It would be better if I could call the copy constructor
// Maybe I should make operator= in RingList
template <typename TData>
const TPolynom<TData>& TPolynom<TData>::operator=(const TPolynom& p) {
  name = p.name;
  if (p.monoms.IsEmpty())
	{
		monoms.SetFirst(nullptr);
		monoms.SetLast(nullptr);
		monoms.SetCurr(nullptr);
    monoms.SetHead(new TNode(p.monoms.GetHead()->data, monoms.GetHead()));
    monoms.SetStop(monoms.GetHead());
	}

	monoms.SetFirst(new TNode(p.monoms.GetFirst()->data));
	TNode* tmp = monoms.GetFirst(); 
  TNode* ltmp = p.monoms.GetFirst()->pNext;
	while(ltmp != p.monoms.GetStop())
	{
		tmp->pNext = new TNode(ltmp->data);
		tmp = tmp->pNext;
		ltmp = ltmp->pNext;
	}
	monoms.SetLast(tmp);
	monoms.SetCurr(monoms.GetFirst());
	monoms.SetHead(new TNode(p.monoms.GetHead()->data, monoms.GetFirst()));
  monoms.GetLast()->pNext = monoms.GetHead();

  return *(this);
}

// ===============================================
// FSM!!!

template <typename TData>
void TPolynom<TData>::tokinize_polynom(const std::string& name) {
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