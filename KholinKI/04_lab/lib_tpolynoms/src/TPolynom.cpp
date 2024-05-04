#include "TPolynom.h"
#include <string>

TPolynom::TPolynom() {
	monoms = new TRingList<TMonom>();
	polynom = "";
}


TPolynom::TPolynom(const string& str) {
	monoms = nullptr;
	int size_str = str.size();
	string infix;
	if (size_str != 0) {
		ArithmeticExpression expr(str);
		infix = expr.GetInfix();
	}
	polynom = infix;
	string tmp;
	string str_test;
	int wrap_degree = 0;
	double coeff_monom = 1;
	int size = infix.size();
	bool stop = false;
	bool create_monom = true;
	bool minus_status = false;
	int i = -1;
	while (i < size && size != 0){
		i = Find_const(infix,i);//поиск константы
		tmp = infix[i];
		if ((i - 1) >= 0) {
			if (infix[i - 1] == '-') {coeff_monom = -1;}
			else if (infix[i - 1] == '+') {coeff_monom = 1;}
		}
		if(tmp[0] >= 48 && tmp[0] <= 57) {
			coeff_monom = Read_const(infix, i);//считывание константы
			tmp = infix[i];
			if (coeff_monom == 0) {create_monom = false;}
		}
		if (tmp[0] == '\0') {
			stop = true;
		}
		if (stop == false && create_monom == true) {
			wrap_degree = Read_degrees(infix,i);//считывание степеней монома
			tmp = str[i];
		}
		if (create_monom == true) {
			TMonom m(coeff_monom, wrap_degree);
			Add_monom(m);//добавление монома
		}
		coeff_monom = 1;
		stop = false;
		create_monom = true;
	}
	if (size == 0) {
		monoms = new TRingList<TMonom>();
	}
	if (monoms == nullptr && size != 0) {
		monoms = new TRingList<TMonom>();
	}

}

TPolynom::TPolynom(const TRingList<TMonom>* monoms_list) {
	if (monoms_list->IsEmpty()) {
		return;
	}
	TRingList<TMonom>* copy_monoms_list = new TRingList<TMonom>(*monoms_list);
	copy_monoms_list->Sort();
	TPolynom P = cite_similars(copy_monoms_list);
	monoms = new TRingList<TMonom>(*P.monoms);
	polynom = CreatePolynomString();
}

int TPolynom::Find_const(const string& str,const int& pos) {
	string tmp;
	int index = pos;
	double coeff_monom = 0;
	do {
		index++;
		tmp = str[index];

		if (tmp[0] == '(' || tmp[0] == ')') {
			continue;
		}
		if (tmp[0] >= 65 && tmp[0] <= 90 || tmp[0] >= 97 && tmp[0] <= 122) {
			break;
		}
	} while (!(tmp[0] >= 48 && tmp[0] <= 57));
	return index;
}

double TPolynom::Read_const(const string& str, int& pos) {
	int size = str.size();
	string str_test;
	string tmp;
	tmp = str[pos];
	bool minus_status = false;
	double const_value = 0; 
	if ((pos - 1) >= 0) {
		if (str[pos - 1] == '-') {
			minus_status = true;
		}
	}
	while (tmp[0] >= 48 && tmp[0] <= 57) {
		str_test = str_test + tmp;
		pos++;
		tmp = str[pos];
	}
	if (minus_status == true) {
		const_value = stod(str_test) * (-1);
		if (const_value == 0) {
			while (tmp[0] != '-' && tmp[0] != '+' && pos < size) {
				pos++;
				tmp = str[pos];
			}
			minus_status = false;
		}
	}
	else {
		const_value = stod(str_test);
		if (const_value == 0) {
			while (tmp[0] != '-' && tmp[0] != '+' && pos < size) {
				pos++;
				tmp = str[pos];

			}
		}
	}
	return const_value;
}

int TPolynom::Read_degrees(const string& str, int& pos) {
	int degree_x = 0; int degree_y = 0; int degree_z = 0;
	string tmp; string str_test;
	tmp = str[pos];
	int size = str.size();
	while (tmp[0] != '-' && tmp[0] != '+') {
		if (pos == size) {
			break;
		}
		switch (tmp[0]) {
		case 'x':
			{
			if (str[pos + 1] == '^') {
				str_test = str_test + str[pos + 2];
				degree_x = stod(str_test);
				}
			else {degree_x = 1;}
			break;
			}
		case 'y':
			{
			if (str[pos + 1] == '^') {
				str_test = str_test + str[pos + 2];
				degree_y = stod(str_test);
				}
			else {degree_y = 1;}
			break;
			}
		case 'z':
			{
			if (str[pos + 1] == '^') {
				str_test = str_test + str[pos + 2];
				degree_z = stod(str_test);
				}
			else {degree_z = 1;}
			break;
			}
		}
		str_test = "";
		pos++;
		tmp = str[pos];
	}
	int wrap_degree = degree_x * 100 + degree_y * 10 + degree_z;
	if (wrap_degree < 0 || wrap_degree > 999) {
		throw "Limit degrees exceeded!";
	}
	return wrap_degree;
}

string TPolynom::GetPolynomString()const {
	return polynom;
}

string TPolynom::CreatePolynomString() {
	string _polynom = "";
	int degree_x = 0;
	int degree_y = 0;
	int degree_z = 0;
	while (!monoms->Is_Ended()) {
		TMonom m = monoms->getCurrent()->data;
		double mCoeff = m.GetCoeff();
		int mWP = m.GetWP();
		if (mCoeff > 0) {
			if (monoms->getCurrent() != monoms->getPFirst()) {
				_polynom.append("+");
			}
		}

		degree_x = mWP / 100;
		degree_y = (mWP % 100) / 10;
		degree_z = (mWP % 10);

		string monom = CreateMonomString(mCoeff, degree_x, degree_y, degree_z);
		_polynom.append(monom);
		monoms->next();
	}
	monoms->reset();
	return _polynom;
}

string TPolynom::CreateMonomString(double coeff, int degree_x,int degree_y,int degree_z) {
	string monom;
	monom.append(to_string(coeff));
	if (degree_x != 0) {
		if (degree_x == 1) {
			monom.append("*x");
		}
		else {
			monom.append("*x^");
			monom.append(to_string(degree_x));
		}
	}
	if (degree_y != 0) {
		if (degree_y == 1) {
			monom.append("*y");
		}
		else {
			monom.append("*y^");
			monom.append(to_string(degree_y));
		}
	}
	if (degree_z != 0) {
		if (degree_z == 1) {
			monom.append("*z");
		}
		else {
			monom.append("*z^");
			monom.append(to_string(degree_z));
		}
	}
	return monom;
}

TPolynom::TPolynom(const TPolynom& obj) {
	monoms = new TRingList<TMonom>(*obj.monoms);
	polynom = obj.polynom;
}

TPolynom::~TPolynom() {
	delete monoms;
}

TPolynom TPolynom::operator+(const TPolynom& Q) {
	TPolynom R;

	while (!this->monoms->Is_Ended() && !Q.monoms->Is_Ended()) 
	{
		TMonom mThis = this->monoms->getCurrent()->data;
		TMonom mQ = Q.monoms->getCurrent()->data;

		int mThisWP = mThis.GetWP();
		int mQWP = mQ.GetWP();

		if (mThisWP == mQWP)
		{
			TMonom result = mThis + mQ;
			if (result.GetCoeff() != 0)
			{
				R.monoms->insert_last(result);
			}
			this->monoms->next();
			Q.monoms->next();
		}
		else if (mThisWP < mQWP)
		{
			R.monoms->insert_last(mThis);
			this->monoms->next();
		}
		else
		{
			R.monoms->insert_last(mQ);
			Q.monoms->next();
		}
	}
	while (!Q.monoms->Is_Ended()) 
	{
		TMonom mQ = Q.monoms->getCurrent()->data;
		R.monoms->insert_last(mQ);
		Q.monoms->next();
	}
	while (!this->monoms->Is_Ended()) 
	{
		TMonom mThis= this->monoms->getCurrent()->data;
		R.monoms->insert_last(mThis);
		this->monoms->next();
	}
	Q.monoms->reset();
	this->monoms->reset();
	R.polynom = R.CreatePolynomString();
	return R;
}

TPolynom TPolynom::operator*(const TPolynom& Q) {
	TPolynom R;
	while(!this->monoms->Is_Ended()){
		TMonom mThis = this->monoms->getCurrent()->data;
		while(!Q.monoms->Is_Ended()) {
			TMonom mQ = Q.monoms->getCurrent()->data;
			TMonom m = mThis * mQ;
			if (R.monoms->IsEmpty()) {
				R.monoms->insert_first(m);
				Q.monoms->next();
			}
			else {
				R.monoms->insertion_sort(m);
				Q.monoms->next();
			}
		}
		Q.monoms->reset();
		this->monoms->next();
	}
	this->monoms->reset();
	TPolynom cite_R = R.cite_similars(R.monoms);
	cite_R.polynom = R.CreatePolynomString();
	return cite_R;
}

const TPolynom& TPolynom::operator=(const TPolynom& Q) {
	if (this == &Q)
	{
		return *this;
	}
	polynom = Q.GetPolynomString();
	monoms = new TRingList<TMonom>();
	while (!Q.monoms->Is_Ended()) {
		TMonom mQ = Q.monoms->getCurrent()->data;
		monoms->insert_last(mQ);
		Q.monoms->next();
		monoms->next();
	}
	monoms->reset();
	Q.monoms->reset();
	return *this;
}

bool TPolynom::operator==(const TPolynom& Q)const {
	if (monoms->GetSize() != Q.monoms->GetSize()) {
		return false;
	}
	while (!Q.monoms->Is_Ended()) {
		TMonom mThis = this->monoms->getCurrent()->data;
		TMonom mQ = Q.monoms->getCurrent()->data;
		if (mThis.GetWP() == mQ.GetWP() && mThis.GetCoeff() == mQ.GetCoeff()) {
			monoms->next();
			Q.monoms->next();
		}
		else{
			monoms->reset();
			Q.monoms->reset();
			return false;
		}
	}
	monoms->reset();
	Q.monoms->reset();
	return true;
}

double TPolynom::operator()(double x, double y, double z)const { 
	ArithmeticExpression my_polynom(polynom);
	vector<string> operands = my_polynom.GetOperands();
	map<string, double> values_xyz;
	if (values_xyz.size() == 0) {
		ArithmeticExpression my_polynom(polynom);
		vector<string> my_operands = my_polynom.GetOperands();
		auto it_begin{ my_operands.begin() };
		auto it_end{ my_operands.end() };
		while (it_begin != it_end) {
			if (*it_begin == "x") {
				values_xyz.insert({ *it_begin, x });
			}
			else if (*it_begin == "y") {
				values_xyz.insert({ *it_begin, y });
			}
			else if (*it_begin == "z") {
				values_xyz.insert({ *it_begin, z });
			}
			it_begin++;
		}
		values_xyz = my_polynom.SetOperands_v2(operands, values_xyz);
	}
	double res = my_polynom.Calculate(values_xyz);
	return res;
}


TPolynom TPolynom::differentiate_by_x()const {
	TPolynom R;
	int degree_x = 0;
	int degree_y = 0;
	int degree_z = 0;
	int new_wrap_degree = 0;
	while (!this->monoms->Is_Ended()) {
		TMonom mThis = this->monoms->getCurrent()->data;
		int coeff = mThis.GetCoeff();
		int wp = mThis.GetWP();
		degree_x = wp / 100;
		if (degree_x == 0) {
			this->monoms->next();
		}
		else {
			coeff= coeff * degree_x;//how get coeff = 0?
			degree_x--;
			degree_y = (wp % 100) / 10;
			degree_z = (wp % 10);
			wp = degree_x * 100 + degree_y * 10 + degree_z;
			mThis.SetCoeff(coeff);
			mThis.SetWP(wp);
			R.monoms->insert_last(mThis);
			this->monoms->next();
		}
	}
	this->monoms->reset();
	R.polynom = R.CreatePolynomString();
	return R;
}

TPolynom TPolynom::differentiate_by_y()const {
	TPolynom R;
	int degree_x = 0;
	int degree_y = 0;
	int degree_z = 0;
	int new_wrap_degree = 0;
	while (!this->monoms->Is_Ended()) {
		TMonom mThis = this->monoms->getCurrent()->data;
		int coeff = mThis.GetCoeff();
		int wp = mThis.GetWP();
		degree_y = (wp % 100) / 10;
		if (degree_y == 0) {
			this->monoms->next();
		}
		else {
			coeff= coeff * degree_y; // coeff == 0 ? x*z //how get coeff = 0?
			degree_y--;
			degree_x = wp / 100;
			degree_z = (wp % 10);
			wp = degree_x * 100 + degree_y * 10 + degree_z;
			mThis.SetCoeff(coeff);
			mThis.SetWP(wp);
			R.monoms->insert_last(mThis);
			this->monoms->next();
		}
	}
	this->monoms->reset();
	R.polynom = R.CreatePolynomString();
	return R;
}
TPolynom TPolynom::differentiate_by_z()const {
	TPolynom R;
	int degree_x = 0;
	int degree_y = 0;
	int degree_z = 0;
	int new_wrap_degree = 0;
	while (!this->monoms->Is_Ended()) {
		TMonom mThis = this->monoms->getCurrent()->data;
		int coeff = mThis.GetCoeff();
		int wp = mThis.GetWP();
		degree_z = (wp % 10);
		if (degree_z == 0) {
			this->monoms->next();
		}
		else {
			coeff = coeff * degree_z; // coeff == 0 ? x*y  //how get coeff = 0?
			degree_z--;		
			degree_x = wp / 100;
			degree_y = (wp % 100) / 10;
			new_wrap_degree = degree_x * 100 + degree_y * 10 + degree_z;
			wp=new_wrap_degree;
			mThis.SetCoeff(coeff);
			mThis.SetWP(wp);
			R.monoms->insert_last(mThis);
			this->monoms->next();
		}
	}
	this->monoms->reset();
	R.polynom = R.CreatePolynomString();
	return R;
}

istream& operator>>(istream& istr, TPolynom& Q) {
	int number = 1;
	int i = 0;
	double coeff = 0;
	int wrap_degree = 0;
	int count = 0;
	int d_x = 0; int d_y = 0; int d_z = 0;
	TRingList<TMonom>* new_monoms = nullptr;
	cout << "Welcome to the polynomial builder!" << endl;
	cout << "To create a polynomial you will need to enter " << endl;
	cout << "corresponding coefficients of the monomial and degree ";
	cout << "variables." << endl;
	cout << endl;
	cout << "Specify the number of monomials to create the polynomial: ";
	do {
		cin >> count;
	} while (count <= 0);
	cout << endl;
	cout << "Let`s get started!" << endl;
	cout << "|										" << endl;
	cout << "|										" << endl;
	cout << "|  Constraints:								    " << endl;
	cout << "|  1)The coefficient must not be equal to 0.		" << endl;
	cout << "|  2)The degree of the variable is 0 <= x,y,z <= 9	" << endl;
	while (i < count) {
		cout << "|												    " << endl;
		cout << "|	Set the coefficient of the monomial!			" << endl;
		do {
			cout << "|	coeff =	";
			cin >> coeff;
			cout << "|										 " << endl;
			cout << "|												    " << endl;
			if (coeff == 0) {
				cout << "|	Wrong coeff! Try again.						    " << endl;
			}
		} while (coeff == 0);
		cout << "|	Determine the degrees of the variables x, y, z!	" << endl;
		cout << "|										 " << endl;
		do {
			cout << "|	Degree x = ";
			cin >> d_x;
			cout << "|										" << endl;
			cout << "|												    " << endl;
			cout << "|	Degree y = ";
			cin >> d_y;
			cout << "|										" << endl;
			cout << "|												    " << endl;
			cout << "|	Degree z = ";
			cin >> d_z;
			cout << "|										" << endl;
			cout << "|												    " << endl;
			if ((d_x < 0 || d_x > 9) || (d_y < 0 || d_y > 9) || (d_z < 0 || d_z > 9)) {
				cout << "|	Wrong degrees! Try again.					    " << endl;
				cout << "|												    " << endl;
			}
		} while
			(
				(d_x < 0 || d_x > 9) || (d_y < 0 || d_y > 9) || (d_z < 0 || d_z > 9)
				);
		wrap_degree = d_x * 100 + d_y * 10 + d_z;
		cout << "|													" << endl;
		cout << "|	Data monom " << number << ":" << "			" << endl;
		cout << "|										" << endl;
		cout << "|	coeff = " << coeff << endl;;
		cout << "|	wrap_degree = " << wrap_degree << endl;;
		cout << "|										" << endl;
		cout << "|										" << endl;
		cout << "|										" << endl;
		cout << "===========================================================================" << endl;
		if (new_monoms == nullptr) {
			TMonom m(coeff, wrap_degree);
			new_monoms = new TRingList<TMonom>();
			new_monoms->insert_first(m);
		}
		else {
			TMonom m(coeff, wrap_degree);
			new_monoms->insertion_sort(m);
		}
		number++;
		i++;
	}
	TPolynom new_polynom(new_monoms);
	Q = new_polynom;
	cout << "FLAG END" << endl;
	return istr;
}

ostream& operator<<(ostream& ostr, const TPolynom& Q) {
	cout << Q.GetPolynomString() << endl;
	cout << endl;

	return ostr;
}

TPolynom TPolynom::cite_similars(TRingList<TMonom>* list_monoms) {
	TPolynom R;
	while (!list_monoms->Is_Ended()) {
		TMonom m = list_monoms->getCurrent()->data;
		list_monoms->next();
		if (list_monoms->Is_Ended()) {
			R.monoms->insert_last(m);
			break;
		}
		TMonom nextM = list_monoms->getCurrent()->data;
		while (m.GetWP() == nextM.GetWP()) {
			m += nextM;
			list_monoms->next();
			nextM = list_monoms->getCurrent()->data;
		}
		if (m.GetWP() != nextM.GetWP() && m.GetCoeff() != 0) {
			R.monoms->insert_last(m);
		}
	}
	R.monoms->reset();
	list_monoms->reset();
	return R;
}

TPolynom TPolynom::operator-()const{
	TPolynom Q;
	while (!this->monoms->Is_Ended()) {
		TMonom m = monoms->getCurrent()->data;
		m = -m;
		Q.monoms->insert_last(m);
		this->monoms->next();
	}
	this->monoms->reset();
	return Q;
}

void TPolynom::Add_monom(const TMonom& m) {
	if (monoms == nullptr) {
		monoms = new TRingList<TMonom>();
		monoms->insert_first(m);
	}
	else {
		Node<TMonom>* search_monom = monoms->search(m);
		monoms->reset();
		if (search_monom != nullptr) {
			if ((search_monom->data.GetCoeff() + m.GetCoeff()) != 0) {
				search_monom->data += m;
			}
		}
		else {
			monoms->insertion_sort(m);
		}
	}
}
