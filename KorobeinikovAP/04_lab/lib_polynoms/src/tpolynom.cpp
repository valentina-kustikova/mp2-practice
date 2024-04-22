#include"tpolynom.h"





// почему была ошибка? я инициализировал polynom а он ругалс€ на входе, что нет конструктора по умолчанию, дл€ TArithmeticExpression

TPolynom::TPolynom(): polynom("\n") {
	monoms = new TRingList<TMonom>();
}


TPolynom::TPolynom(string name): polynom(name) {
	GetRingListFromString();
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
	/*
	while (!obj->IsEnded()) {
		AddMonom(obj->GetCurrent()->data);
		obj->Next();
	}
	*/
	if (flag == 1) {
		monoms->InsertFirst(obj->GetCurrent()->data);
		obj->Next();
		flag = 0;
	}
	else {
		AddMonom(obj->GetCurrent()->data);
		obj->Next();
	}

	obj->Reset();
	
	polynom = TArithmeticExpression(GetStringFromRingList());
}


TPolynom::TPolynom(const TRingList<TMonom>* obj) {
	monoms = &TRingList<TMonom>(*obj);



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

	//TNode<TMonom>* tmp = monoms->first();
 	while (!monoms->IsEnded()) {
		TNode<TMonom>* curr = monoms->GetCurrent();

		if (m == curr->data) {
			double coeff = m.get_koef() + curr->data.get_koef();
			if (coeff == 0.0f) {
				monoms->Remove(curr->data);
				return;
			}
			else {
				curr->data.koef = coeff;
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
			return;
		}
		else {
			curr->data.koef = coeff;
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
	if (monoms->GetCurrent() == nullptr) {
		return res;
	}
	else {
		res += monoms->GetCurrent()->data.get_string();
		monoms->Next();
		while (!monoms->IsEnded()) {
			string monom = monoms->GetCurrent()->data.get_string();
			if (monom[0] == '-') res += monom;
			else res += "+" + monom;
			monoms->Next();
		}
	}

	string monom = monoms->GetCurrent()->data.get_string();
	if (monom[0] == '-') res += monom;
	else res += "+" + monom;
	monoms->Next();

	monoms->Reset();

	return res;
}


TNode<TMonom>* TPolynom::GetCurrent() {
	return monoms->GetCurrent();
}
