#include "TPolynom.h"

double pow(double num, int k) {
	double res = 1.0;
	for (int i = 0; i < k; i++) res *= num;
	return res;
}

void TPolynom::SortInsert(Monom& m) {
	TNode<Monom>* less = new TNode<Monom>;
	
	if (findLess(m, less)) {
		if (m.degX == less->key.degX && m.degY == less->key.degY && m.degZ == less->key.degZ) less->key.coef += m.coef;
		else monoms->insertAfter(less->key, m);
	}
	else if (m == less->key) monoms->insertFirst(m);
	else monoms->insertLast(m);
	
}

bool TPolynom::isSimilar(Monom& a, Monom& b) const {
	return (a.degX == b.degX && a.degY == b.degY && a.degZ == b.degZ);
}

bool TPolynom::findLess(Monom& m, TNode<Monom>*& g)
{
	monoms->Reset();
	TNode<Monom>* l = new TNode<Monom>(m);
	g = new TNode<Monom>(m);
	while (monoms->getCurrent() != nullptr && monoms->getCurrent() != monoms->getStop() && 
		  (monoms->getCurrent()->key < m || isSimilar(monoms->getCurrent()->key, m))) 
	{
		l = monoms->getCurrent();
		monoms->Next();
	}
	if (monoms->getCurrent() == nullptr || monoms->getCurrent() == monoms->getFirst()) return false;
	else {
		g = l;
		return true;
	}
}

void TPolynom::setDegree(Monom& m ,string& param, int deg) {
	if (param == "x" || param == "X") m.degX = deg;
	if (param == "y" || param == "Y") m.degY = deg;
	if (param == "z" || param == "Z") m.degZ = deg;
}

void TPolynom::toPolynome()
{
	Monom m;
	string last_elem = mas[0];
	string last_param = "";
	int cf = 1;
	if (IsConst(last_elem)) m.coef = stod(last_elem);
	else if (last_elem == "-") cf = -1;
	else if (this->IsParam(last_elem)) last_param = last_elem;
	for (int i = 1; i < mas.size(); i++) {
		string tok = mas[i];
		if (tok == "+" || tok == "-") {
			if (last_param != "" && !IsConst(last_elem)) setDegree(m, last_param, 1);
			SortInsert(m);
			(tok == "+") ? cf = 1 : cf = -1;
			m = Monom(1.0, 0, 0, 0);
		}
		else if (tok == "*" && IsParam(last_elem)) setDegree(m, last_elem, 1);
		if (this->IsParam(tok)) last_param = tok;
		else if (IsConst(tok)) {
			if (last_elem == "^") setDegree(m, last_param, stoi(tok));
			else if (last_elem == "+" || last_elem == "-") { 
				m.coef = stod(tok) * cf;
				cf = 1;
			}
		}
		last_elem = tok;
	}
	m.coef *= cf;
	if (last_param != "" && !IsConst(last_elem)) setDegree(m, last_param, 1);
	SortInsert(m);
	//giveSimTer();
}

void TPolynom::giveSimTer() {
	monoms->Reset();
	while (monoms->getCurrent() != monoms->getStop()) {
		TNode<Monom>* curr = monoms->getCurrent();
		TNode<Monom>* tmp = new TNode<Monom>(monoms->getCurrent()->pNext);
		while (tmp != monoms->getStop() && curr->pNext != monoms->getStop()) {
			if (tmp->key.degX == curr->key.degX && tmp->key.degY == curr->key.degY && tmp->key.degZ == curr->key.degZ) {
				curr->key.coef += tmp->key.coef;
				TNode<Monom>* toDel = tmp;
				tmp = tmp->pNext;
				monoms->Remove(toDel->key);
			}
			else tmp = tmp->pNext;
		}
		monoms->Next();
	}
}

TPolynom::TPolynom()
{
	arexp = "";
	monoms = new TRingList<Monom>;
}

TPolynom::TPolynom(const string& _polynome)
{
	arexp = _polynome + "\0";
	monoms = new TRingList<Monom>;
	GetTokens();
	toPolynome();
}

TPolynom::TPolynom(const TRingList<Monom>& ringlist) {
	TRingList<Monom> ringListCopy(ringlist);
	ringListCopy.Reset();
	TNode<Monom>* tmp = new TNode<Monom>(ringlist.getFirst());
	monoms = new TRingList<Monom>(tmp);
	while (tmp != ringlist.getStop()) {
		ringListCopy.Next();
		tmp = new TNode<Monom>(ringlist.getCurrent());
		TNode<Monom> *less = new TNode<Monom>;
		if (findLess(tmp->key, less)) {
			if (tmp->key.degX == less->key.degX && tmp->key.degY == less->key.degY && tmp->key.degZ == less->key.degZ) less->key.coef += tmp->key.coef;
			else monoms->insertAfter(less->key, tmp->key);
		}
		else if (tmp->key == less->key) monoms->insertFirst(tmp->key);
		else monoms->insertLast(tmp->key);
	}
}

TPolynom::TPolynom(const TPolynom& polynom) {
	monoms = new TRingList<Monom>(*(polynom.monoms));
	arexp = polynom.arexp;
	mas = polynom.mas;
	post_form = polynom.post_form;
	values = polynom.values;
}

TPolynom::~TPolynom()
{
	if (monoms->isEmpty() == true) return;
	monoms->Clear();
}

const TPolynom& TPolynom::operator=(const TPolynom& polynom) {
	if (this == &polynom)
	{
		return *this;
	}
	monoms = new TRingList<Monom>(*(polynom.monoms));
	arexp = polynom.arexp;
	mas = polynom.mas;
	post_form = polynom.post_form;
	values = polynom.values;
	return *this;
}

TPolynom TPolynom::operator+(TPolynom& polynom) {
	TPolynom res(*this);
	TNode<Monom>* tmp = polynom.monoms->getFirst();
	while (tmp != polynom.monoms->getStop()) {
		TNode<Monom> *less = new TNode<Monom>;
		if (res.findLess(tmp->key, less)) {
			if (tmp->key.degX == less->key.degX && tmp->key.degY == less->key.degY && tmp->key.degZ == less->key.degZ) less->key.coef += tmp->key.coef;
			else res.monoms->insertAfter(less->key, tmp->key);
		}
		else if (tmp->key == less->key) res.monoms->insertFirst(tmp->key);
		else res.monoms->insertLast(tmp->key);
		tmp = tmp->pNext;
	}
	//res.giveSimTer();
	res.arexp = res.InfixForm();
	return res;
}

TPolynom TPolynom::operator-(TPolynom& polynom) {
	polynom *= -1;
	TPolynom res = *this + polynom;
	return res;
}

TPolynom TPolynom::operator*(TPolynom& polynom) {
	TPolynom res;
	monoms->Reset();
	while (monoms->getCurrent() != monoms->getStop()) {
		TNode<Monom>* tmp = polynom.monoms->getFirst();
		while (tmp != polynom.monoms->getStop()) {
			TNode<Monom>* k = monoms->getCurrent();
			if (k->key.coef == 0) break;
			Monom m(k->key.coef * tmp->key.coef,
					k->key.degX + tmp->key.degX,
					k->key.degY + tmp->key.degY,
					k->key.degZ + tmp->key.degZ);
			res.SortInsert(m);
			tmp = tmp->pNext;
		}
		monoms->Next();
	}
	res.arexp = res.InfixForm();
	return res;
}

TPolynom TPolynom::operator*=(int num) {
	this->monoms->Reset();
	while (this->monoms->getCurrent() != this->monoms->getStop()) {
		this->monoms->getCurrent()->key.coef *= num;
		this->monoms->Next();
	}
	return *this;
}

TPolynom TPolynom::operator*=(float num) {
	this->monoms->Reset();
	while (this->monoms->getCurrent() != this->monoms->getStop()) {
		this->monoms->getCurrent()->key.coef *= num;
		this->monoms->Next();
	}
	return *this;
}

double TPolynom::operator()(double x, double y, double z) {
	double res = 0.0;
	monoms->Reset();
	TNode<Monom>* cur = monoms->getCurrent();
	while (cur != monoms->getStop()) {
		double num = 1.0;
		num *= cur->key.coef;
		num *= pow(x, cur->key.degX);
		num *= pow(y, cur->key.degY);
		num *= pow(z, cur->key.degZ);
		cur = cur->pNext;
		res += num;
	}
	return res;
}

TPolynom TPolynom::dif_x() const {
	TPolynom res;
	monoms->Reset();
	TNode<Monom>* cur = monoms->getCurrent();
	while (cur != monoms->getStop()) {
		if (cur->key.coef == 0 || cur->key.degX == 0) { 
			cur = cur->pNext;
			Monom m = Monom(0, 0, 0, 0);
			res.SortInsert(m);
			continue;
		}
		Monom m(cur->key.coef * cur->key.degX, cur->key.degX - 1, cur->key.degY, cur->key.degZ);
		res.monoms->insertLast(m);
		cur = cur->pNext;
	}
	res.arexp = res.InfixForm();
	if (res.monoms->getFirst()->key.coef == 0 && res.monoms->getFirst()->pNext != res.monoms->getStop()) res.monoms->Remove(Monom(0, 0, 0, 0));
	return res;
}

TPolynom TPolynom::dif_y() const {
	TPolynom res;
	monoms->Reset();
	TNode<Monom>* cur = monoms->getCurrent();
	while (cur != monoms->getStop()) {
		if (cur->key.coef == 0 || cur->key.degY == 0) {
			cur = cur->pNext;
			Monom m = Monom(0, 0, 0, 0);
			res.SortInsert(m);
			continue;
		}
		Monom m(cur->key.coef * cur->key.degY, cur->key.degX, cur->key.degY - 1, cur->key.degZ);
		res.monoms->insertLast(m);
		cur = cur->pNext;
	}
	res.arexp = res.InfixForm();
	if (res.monoms->getFirst()->key.coef == 0 && res.monoms->getFirst()->pNext != res.monoms->getStop()) res.monoms->Remove(Monom(0, 0, 0, 0));
	return res;
}

TPolynom TPolynom::dif_z() const {
	TPolynom res;
	monoms->Reset();
	TNode<Monom>* cur = monoms->getCurrent();
	while (cur != monoms->getStop()) {
		if (cur->key.coef == 0 || cur->key.degZ == 0) {
			cur = cur->pNext;
			Monom m = Monom(0, 0, 0, 0);
			res.SortInsert(m);
			continue;
		}
		Monom m(cur->key.coef * cur->key.degZ, cur->key.degX, cur->key.degY, cur->key.degZ - 1);
		res.monoms->insertLast(m);
		cur = cur->pNext;
	}
	res.arexp = res.InfixForm();
	if (res.monoms->getFirst()->key.coef == 0 && res.monoms->getFirst()->pNext != res.monoms->getStop()) res.monoms->Remove(Monom(0, 0, 0, 0));
	return res;
}

bool TPolynom::operator==(const TPolynom& polynom) const {
	monoms->Reset();
	polynom.monoms->Reset();
	while (monoms->getCurrent() != monoms->getStop() && polynom.monoms->getCurrent() != polynom.monoms->getStop()) {
		if (monoms->getCurrent()->key != polynom.monoms->getCurrent()->key) return false;
		monoms->Next();
		polynom.monoms->Next();
	}
	if (monoms->getCurrent() != monoms->getStop() && polynom.monoms->getCurrent() == polynom.monoms->getStop() ||
		monoms->getCurrent() == monoms->getStop() && polynom.monoms->getCurrent() != polynom.monoms->getStop()) return false;
	return true;
}

void TPolynom::ToString() {
	arexp = "";
	monoms->Reset();
	while (monoms->getCurrent() != monoms->getStop()) {
		if (monoms->getCurrent()->key.coef > 0 && arexp != "") arexp += "+";
		arexp += monoms->getCurrent()->key.toString();
		monoms->Next();
	}
	if (arexp == "") arexp = "0";
}