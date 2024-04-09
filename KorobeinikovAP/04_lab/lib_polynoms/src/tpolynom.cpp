#include"tpolynom.h"





// почему была ошибка? я инициализировал polynom а он ругалс€ на входе, что нет конструктора по умолчанию, дл€ TArithmeticExpression

TPolynom::TPolynom(){
	polynom = TArithmeticExpression("\n");
	monoms = new TRingList<TMonom>();
}


TPolynom::TPolynom(string name) {
	polynom = TArithmeticExpression(name);
	monoms = GetRingListFromString();
}
/*
TPolynom::TPolynom(const TRingList<TMonom>* obj) {
	monoms = &TRingList<TMonom>(*obj);



}
*/



TRingList<TMonom>* TPolynom::GetRingListFromString() {
	vector<string> lexems_from_polymon = polynom.GetLexems();
	double coeff = 1;
	int degX = 0, degY = 0, degZ = 0;
	int next_const_sign = 1;
	TRingList<TMonom>* tmp = new  TRingList<TMonom>();

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
			if (flag == 1) {
				tmp->InsertFirst(monom);
				flag = 0;
			}
			else {
				tmp->InsertAfter(monom);
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
	TMonom monom(next_const_sign * coeff, tmp_st);
	tmp->InsertAfter(monom);
	return tmp;
}
