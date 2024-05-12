#include"tpolynom.h"





// почему была ошибка? Я инициализировал polynom а он ругался на входе, что нет конструктора по умолчанию, для TArithmeticExpression

TPolynom::TPolynom(): polynom("\n") {
	monoms = new TRingList<TMonom>();
}


TPolynom::TPolynom(const string &name): polynom(name) {
	GetRingListFromString();
	polynom = TArithmeticExpression(GetStringFromRingList());
}

TPolynom::TPolynom(TRingList<TMonom>* obj){
	monoms = new TRingList<TMonom>;

	obj->Reset();
	int flag = 1;
	while(!obj->IsEnded()) {
		if (flag == 1) {
			monoms->InsertFirst(obj->GetCurrent()->data);
			obj->Next();
			flag = 0;
		}
		else {
			AddMonom(obj->GetCurrent()->data);
			obj->Next();
		}

	}


	obj->Reset();
	
	polynom = TArithmeticExpression(GetStringFromRingList());
}


TPolynom::TPolynom(const TPolynom& obj) {
	monoms = new TRingList<TMonom>(*obj.monoms);
	polynom = TArithmeticExpression(obj.polynom.GetInfix());
}


TPolynom::~TPolynom() {
	if (monoms) delete monoms;
}


void TPolynom::GetRingListFromString() {
	vector<string> lexems_from_polymon = polynom.GetLexems();
	double coeff = 1;
	int degX = 0, degY = 0, degZ = 0;
	int next_const_sign = 1;
	monoms = new  TRingList<TMonom>();

	vector<string> lexems;
	for (const string& token : lexems_from_polymon) {
		if (token != "*" && token != "^") {
			lexems.push_back(token);
		}
	}

	int flag = 1;
	for (int i = 0; i < lexems.size(); i++) {

		if (lexems[i] == "+" || lexems[i] == "-") {
			
			int tmp_st = 100 * degX + 10 * degY + degZ;
			TMonom monom(tmp_st, next_const_sign * coeff);
			//TMonom monom(degX, degY, degZ, next_const_sign * coeff);
			if (flag == 1) {
				monoms->InsertFirst(monom);
				flag = 0;
			}
			else {
				AddMonom(monom);
			}


			if (lexems[i] == "+") next_const_sign = 1;
			else next_const_sign = -1;
			coeff = 1;
			degX = 0;
			degY = 0;
			degZ = 0;
		}
		else {

			if (lexems[i] == "x") {
				if (i < lexems.size() - 1) {
					if (!IsVariable(lexems[i + 1]) && !IsOperator(lexems[i + 1])) {
						degX += stoi(lexems[i + 1]);
						i++;
					}
					else {
						degX += 1;
					}
				}
				else {
					degX += 1;
				}
			}

			else if (lexems[i] == "y") {
				if (i < lexems.size() - 1) {
					if (!IsVariable(lexems[i + 1]) && !IsOperator(lexems[i + 1])) {
						degY += stoi(lexems[i + 1]);
						i++;
					}
					else {
						degY += 1;
					}
				}
				else {
					degY += 1;
				}
			}

			else if (lexems[i] == "z") {
				if (i < lexems.size() - 1) {
					if (!IsVariable(lexems[i + 1]) && !IsOperator(lexems[i + 1])) {
						degZ += stoi(lexems[i + 1]);
						i++;
					}
					else {
						degZ += 1;
					}
				}
				else {
					degZ += 1;
				}
			}

			else {
				if (!IsConst(lexems[i])) {
					string exp = "Error: not valid operand";
					throw exp;
				}
				coeff *= stod(lexems[i]);
			}
		}
	}
	int tmp_st = 100 * degX + 10 * degY + degZ;
	TMonom monom(tmp_st, next_const_sign * coeff);
	//TMonom monom(degX, degY, degZ, next_const_sign * coeff);
	if (flag == 1) {
		monoms->InsertFirst(monom);
		flag = 0;
	}
	else {
		AddMonom(monom);
	}
}


void TPolynom::AddMonom(TMonom& m) {
	if (m.get_koef() == 0) return;

 	while (!monoms->IsLast()) {
		TNode<TMonom>* curr = monoms->GetCurrent();

		if (m == curr->data) {
			double coeff = m.get_koef() + curr->data.get_koef();
			if (coeff == 0.0f) {
				monoms->Remove(curr->data);
				monoms->Reset();
				return;
			}
			else {
				curr->data.set_koef(coeff);
				monoms->Reset();
				return;
			}
		}

		else if (m < curr->data) {
			monoms->InsertBefore(m, curr->data);
			return;
		}

		else {
			monoms->Next();
		}
	}


	TNode<TMonom>* curr = monoms->GetCurrent();

	if (m == curr->data) {
		double coeff = m.get_koef() + curr->data.get_koef();
		if (coeff == 0.0f) {
			monoms->Remove(curr->data);
			monoms->Reset();
			return;
		}
		else {
			curr->data.set_koef(coeff);
			monoms->Reset();
			return;
		}
	}

	else if (m < curr->data) {
		monoms->InsertBefore(m, curr->data);
		return;
	}

	else {
		monoms->InsertAfter(m);
	}

}



string TPolynom:: GetStringFromRingList() {
	if (monoms->GetSize() == 0) return "0.000000";

	string res = "";
	monoms->Reset();
	int flag = 0;
	if (monoms->GetCurrent() == nullptr) {
		return res;
	}
	else {
		res += monoms->GetCurrent()->data.get_string();
		monoms->Next();
		flag = 1;
		while (!monoms->IsEnded()) {
			string monom = monoms->GetCurrent()->data.get_string();
			if (monom[0] == '-') res += monom;
			else res += "+" + monom;
			flag = 0;
			monoms->Next();
		}
	}

	monoms->Reset();

	return res;
}


TNode<TMonom>* TPolynom::GetCurrent() const {
	return monoms->GetCurrent();
}


//операторы

const TPolynom&  TPolynom:: operator=(const TPolynom& obj) {
	if (this == &obj) return (*this);

	if (monoms) delete monoms;
	monoms = new TRingList<TMonom>(*obj.monoms);
	polynom = TArithmeticExpression(obj.GetString());

	return (*this);
}

TPolynom TPolynom:: operator + (const TPolynom& obj) const{
	TPolynom res(*this);

	obj.monoms->Reset();
	while (!obj.monoms->IsEnded()) {
		TMonom curr_monom = obj.GetCurrent()->data;
		if (res.monoms->IsEmpty()) {
			res.monoms->InsertFirst(curr_monom);
		}
		else {
			res.AddMonom(curr_monom);
		}
		obj.monoms->Next();
	}

	obj.monoms->Reset();

	res.polynom = TArithmeticExpression(res.GetStringFromRingList());
	return res;
}

TPolynom TPolynom:: operator - () const {
	TPolynom res(*this);

	res.monoms->Reset();
	while (!res.monoms->IsEnded()) {
		TNode<TMonom>* curr = res.GetCurrent();
		double koef_ = (-1) * curr->data.get_koef();
		curr->data.set_koef(koef_);
		res.monoms->Next();
	}

	res.monoms->Reset();
	res.polynom = TArithmeticExpression(res.GetStringFromRingList());


	return res;
}



TPolynom TPolynom::operator-(const TPolynom& obj) const{
	TPolynom res(-obj + (*this));

	return res;
}
	


TPolynom TPolynom::operator*(const TPolynom& obj) const{
	TPolynom res;
	int flag = 1;
	monoms->Reset();
	while (!monoms->IsEnded()) {
		TMonom curr1 = monoms->GetCurrent()->data;

		obj.monoms->Reset();
		while (!obj.monoms->IsEnded()) {
			if (flag == 1) {
				TMonom curr2 = obj.GetCurrent()->data;
				res.monoms->InsertFirst(curr1 * curr2);
				flag = 0;
				obj.monoms->Next();
			}
			else {
				TMonom curr2 = obj.GetCurrent()->data;
				res.AddMonom(curr1 * curr2);
				obj.monoms->Next();
			}
		}

		monoms->Next();
	}	

	obj.monoms->Reset();
	monoms->Reset();
	res.polynom = TArithmeticExpression(res.GetStringFromRingList());

	return res;
}



//дифференцирование


TPolynom TPolynom::dif_x() const {
	TPolynom res;
	int flag = 1;
	monoms->Reset();
	while (!monoms->IsEnded()) {
		if (flag == 1) {
			TMonom tmp = GetCurrent()->data.dif_x();
			if (tmp.get_koef() != 0) {
				res.monoms->InsertFirst(tmp);
				monoms->Next();
				flag = 0;
			}
			else {
				monoms->Next();
			}
		}
		else {
			TMonom tmp = GetCurrent()->data.dif_x();
			if (tmp.get_koef() != 0) {
				res.AddMonom(tmp);
				monoms->Next();
			}
			else {
				monoms->Next();
			}
		}

	}
	monoms->Reset();
	res.polynom = TArithmeticExpression(res.GetStringFromRingList());
	return res;
}

TPolynom TPolynom::dif_y() const {
	TPolynom res;
	int flag = 1;
	monoms->Reset();
	while (!monoms->IsEnded()) {
		if (flag == 1) {
			TMonom tmp = GetCurrent()->data.dif_y();
			if (tmp.get_koef() != 0) {
				res.monoms->InsertFirst(tmp);
				monoms->Next();
				flag = 0;
			}
			else {
				monoms->Next();
			}
		}
		else {
			TMonom tmp = GetCurrent()->data.dif_y();
			if (tmp.get_koef() != 0) {
				res.AddMonom(tmp);
				monoms->Next();
			}
			else {
				monoms->Next();
			}
		}

	}
	monoms->Reset();
	res.polynom = TArithmeticExpression(res.GetStringFromRingList());
	return res;
}


TPolynom TPolynom::dif_z() const {
	TPolynom res;
	int flag = 1;
	monoms->Reset();
	while (!monoms->IsEnded()) {
		if (flag == 1) {
			TMonom tmp = GetCurrent()->data.dif_z();
			if (tmp.get_koef() != 0) {
				res.monoms->InsertFirst(tmp);
				monoms->Next();
				flag = 0;
			}
			else {
				monoms->Next();
			}
		}
		else {
			TMonom tmp = GetCurrent()->data.dif_z();
			if (tmp.get_koef() != 0) {
				res.AddMonom(tmp);
				monoms->Next();
			}
			else {
				monoms->Next();
			}
		}

	}
	monoms->Reset();
	res.polynom = TArithmeticExpression(res.GetStringFromRingList());
	return res;
}



double TPolynom:: operator () (double x, double y, double z) {
	map<string, double> map_tmp;
	map_tmp["x"] = x;
	map_tmp["y"] = y;
	map_tmp["z"] = z;

	string tmp = GetString();
	polynom = TArithmeticExpression(tmp, map_tmp);

	return polynom.Calculate();
}