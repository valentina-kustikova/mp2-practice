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
	int i = -1;
	string tmp;
	bool minus_status = false;
	string str_test;
	int degree_x = 0;
	int degree_y = 0;
	int degree_z = 0;
	int wrap_degree = 0;
	double coeff_monom = 1;
	int size = infix.size();
	bool stop = false;
	bool create_monom = true;
	while (i < size && size != 0){
		do {
			i++;
			tmp = infix[i];

			if (tmp[0] == '(' || tmp[0] == ')') {
				continue;
			}
			if (tmp[0] >= 65 && tmp[0] <= 90 || tmp[0] >= 97 && tmp[0] <= 122) {
				if ((i - 1) >= 0) {
					if(infix[i-1] == '-'){
						coeff_monom = -1;
					}
					else if (infix[i - 1] == '+') {
						coeff_monom = 1;
					}
				}
				break;
			}
		} while (!(tmp[0] >= 48 && tmp[0] <= 57));
		if(tmp[0] >= 48 && tmp[0] <= 57) {
			if ((i - 1) >= 0) {
				if (infix[i - 1] == '-') {
					minus_status = true;
				}
			}
			while (tmp[0] >= 48 && tmp[0] <= 57) {
				str_test = str_test + tmp;
				i++;
				tmp = infix[i];
			}
			if (minus_status == true) {
				coeff_monom = stod(str_test) * (-1);
				if (coeff_monom == 0) {
					while (tmp[0] != '-' && tmp[0] != '+' && i < size) {
						i++;
						tmp = infix[i];
						
					}
					create_monom = false;
					minus_status = false;
				}
				
			}
			else {
				coeff_monom = stod(str_test);
				if (coeff_monom == 0) {
					while (tmp[0] != '-' && tmp[0] != '+' && i < size) {
						i++;
						tmp = infix[i];
						
					}
					create_monom = false;
				}
				
			}
			if (tmp[0] == '\0') {
				stop = true;
			}
			str_test = "";
			minus_status = false;
		}
		while (tmp[0] != '-' && tmp[0] != '+' && stop == false && create_monom == true) {
			switch (tmp[0]) {
			case 'x':
				{
				
				if (infix[i + 1] == '^') {
					str_test = str_test + infix[i + 2];
					degree_x = stod(str_test);
					if (degree_x < 0 || degree_x > 9) {
						throw "degree limit!";
					}
					str_test = "";
				}
				else {
					degree_x = 1;
				}
				break;
				}

			case 'y':
				{
				
				if (infix[i + 1] == '^') {

					str_test = str_test + infix[i + 2];
					degree_y = stod(str_test);
					if (degree_y < 0 || degree_y > 9) {
						throw "degree limit!";
					}
					str_test = "";
				}
				else {
					degree_y = 1;
				}
				break;
				}

			case 'z':
				{
				
				if (infix[i + 1] == '^') {
					str_test = str_test + infix[i + 2];
					degree_z = stod(str_test);
					if (degree_z < 0 || degree_z > 9) {
						throw "degree limit!";
					}
					str_test = "";
				}
				else {
					degree_z = 1;
				}
				break;
				}
			}
			i++;
			if (i == size) {
				break;
			}
			tmp = infix[i];
		}
		if (create_monom == true) {
			if (monoms == nullptr) {
				wrap_degree = degree_x * 100 + degree_y * 10 + degree_z;
				TMonom m(coeff_monom, wrap_degree);
				monoms = new TRingList<TMonom>();
				monoms->insert_first(m);
			}
			else {
				wrap_degree = degree_x * 100 + degree_y * 10 + degree_z;
				TMonom m(coeff_monom, wrap_degree);
				monoms->insertion_sort(m);
			}
		}
		degree_x = 0;
		degree_y = 0;
		degree_z = 0;
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
	cite_similars();
}

TPolynom::TPolynom(const TRingList<TMonom>* monoms_list) {
	monoms = new TRingList<TMonom>(*monoms_list);
	if (monoms->IsEmpty()) {
		return;
	}
	Corrector();
	CreatePolynomString();
}

string TPolynom::GetPolynomString()const {
	return polynom;
}

void TPolynom::CreatePolynomString() {
	string _polynom = "";
	int degree_x = 0;
	int degree_y = 0;
	int degree_z = 0;
	while (!monoms->Is_Ended()) {
		TMonom m = monoms->getCurrent()->data;
		if (m.coeff > 0) {
			if (monoms->getCurrent() != monoms->pFirst) {
				_polynom.append("+");

				_polynom.append(to_string(m.coeff));
			}
			else {
				_polynom.append(to_string(m.coeff));
			}
		}
		else if (m.coeff < 0) {
			_polynom.append(to_string(m.coeff));
		}
		degree_x = m.wrap_degree / 100;
		degree_y = (m.wrap_degree % 100) / 10;
		degree_z = (m.wrap_degree % 10);
		if (degree_x != 0) {
			if (degree_x == 1) {
				_polynom.append("*x");
			}
			else {
				_polynom.append("*x^");
				_polynom.append(to_string(degree_x));
			}
		}
		if (degree_y != 0) {
			if (degree_y == 1) {
				_polynom.append("*y");
			}
			else {
				_polynom.append("*y^");
				_polynom.append(to_string(degree_y));
			}
		}
		if (degree_z != 0) {
			if (degree_z == 1) {
				_polynom.append("*z");
			}
			else {
				_polynom.append("*z^");
				_polynom.append(to_string(degree_z));
			}
		}
		monoms->next();
	}
	monoms->reset();
	polynom = _polynom;
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
		if (mThis.wrap_degree == mQ.wrap_degree)
		{
			TMonom result = mThis + mQ;
			if (result.coeff != 0)
			{
				R.monoms->insert_last(result);
			}
			this->monoms->next();
			Q.monoms->next();
		}
		else if (mThis.wrap_degree < mQ.wrap_degree) 
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
	R.CreatePolynomString();
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
	R.cite_similars();
	R.CreatePolynomString();
	return R;
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
		if (mThis.wrap_degree == mQ.wrap_degree && mThis.coeff == mQ.coeff) {
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

double TPolynom::operator()(double x, double y, double z) {
	ArithmeticExpression my_polynom(polynom);
	vector<string> operands = my_polynom.GetOperands();
	map<string, double> values;
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
		values = my_polynom.SetOperands_v2(operands, values_xyz);
	}
	else {
	    values = my_polynom.SetOperands_v2(operands, values_xyz);
	}
	double res = my_polynom.Calculate(values);
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
		degree_x = mThis.wrap_degree / 100;
		if (degree_x == 0) {
			this->monoms->next();
		}
		else {
			mThis.coeff= mThis.coeff * degree_x;
			degree_x--;
			degree_y = (mThis.wrap_degree % 100) / 10;
			degree_z = (mThis.wrap_degree % 10);
			mThis.wrap_degree= degree_x * 100 + degree_y * 10 + degree_z;
			R.monoms->insert_last(mThis);
			this->monoms->next();
		}
	}
	this->monoms->reset();
	R.CreatePolynomString();
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
		degree_y = (mThis.wrap_degree % 100) / 10;
		if (degree_y == 0) {
			this->monoms->next();
		}
		else {
			mThis.coeff= mThis.coeff * degree_y;
			degree_y--;
			degree_x = mThis.wrap_degree / 100;
			degree_z = (mThis.wrap_degree % 10);
			mThis.wrap_degree= degree_x * 100 + degree_y * 10 + degree_z;
			R.monoms->insert_last(mThis);
			this->monoms->next();
		}
	}
	this->monoms->reset();
	R.CreatePolynomString();
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
		degree_z = (mThis.wrap_degree % 10);
		if (degree_z == 0) {
			this->monoms->next();
		}
		else {
			mThis.coeff= mThis.coeff * degree_z;
			degree_z--;
			degree_x = mThis.wrap_degree / 100;
			degree_y = (mThis.wrap_degree % 100) / 10;
			new_wrap_degree = degree_x * 100 + degree_y * 10 + degree_z;
			mThis.wrap_degree=new_wrap_degree;
			R.monoms->insert_last(mThis);
			this->monoms->next();
		}
	}
	this->monoms->reset();
	R.CreatePolynomString();
	return R;
}

istream& operator>>(istream& istr, TPolynom& Q) {
	int number = 1;
	int i = 0;
	double coeff = 0;
	int wrap_degree = 0;
	int count = 0;
	int d_x = 0; int d_y = 0; int d_z = 0;
	TRingList<TMonom>* new_list_monoms = nullptr;
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
		if (new_list_monoms == nullptr) {
			TMonom m(coeff, wrap_degree);
			new_list_monoms = new TRingList<TMonom>();
			new_list_monoms->insert_first(m);
		}
		else {
			TMonom m(coeff, wrap_degree);
			new_list_monoms->insertion_sort(m);
		}
		number++;
		i++;
	}
	TPolynom new_polynom(new_list_monoms);
	Q = new_polynom;
	cout << "FLAG END" << endl;
	return istr;
}

ostream& operator<<(ostream& ostr, const TPolynom& Q) {
	cout << Q.GetPolynomString() << endl;
	cout << endl;

	return ostr;
}

void TPolynom::Corrector() {
	if (!monoms->Is_Sorted()) {
		monoms->Sort();
	}
	cite_similars();
}

void TPolynom::cite_similars() {
	if (monoms->IsEmpty()) {
		return;
	}
	int size = monoms->GetSize();
	while (!monoms->Is_Ended()) {
		Node<TMonom>* edit = monoms->getCurrent();
		Node<TMonom>* comp = monoms->getCurrent()->pNext;
		TMonom m1 = monoms->getCurrent()->data;
		while (comp != monoms->pStop) {
			TMonom m2 = comp->data;
			if (m1.wrap_degree == m2.wrap_degree) {
				edit->data += m2;
				comp = comp->pNext;
				monoms->remove(m2);
			}
			else {
				if (monoms->getCurrent() != comp) {
					monoms->next();
				}
				if (edit->data.coeff == 0) {
					monoms->remove(edit->data);
				}
				break;
			}
		}
		if (comp == monoms->pStop) {
			break;
		}
	}
	monoms->reset();
}

TPolynom TPolynom::operator-() {
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

