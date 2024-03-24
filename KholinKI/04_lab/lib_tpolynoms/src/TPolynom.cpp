#include "TPolynom.h"

#include <string>
TPolynom::TPolynom() {
	monoms = nullptr;
	polynom = "";
}



TPolynom::TPolynom(const string& str) {//учесть случай для ^0,^1 
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
				Node<TMonom>* pFirst = new Node<TMonom>(*(new TMonom(coeff_monom, wrap_degree)));
				monoms = new TRingList<TMonom>(pFirst);
			}
			else {
				wrap_degree = degree_x * 100 + degree_y * 10 + degree_z;
				Node<TMonom> NewMonom = *(new Node<TMonom>(*(new TMonom(coeff_monom, wrap_degree))));
				Node<TMonom>* tmp = monoms->pCurr;
				Node<TMonom>* found = monoms->search(NewMonom.data);
				if (found != nullptr && found != monoms->pStop) {
					found->data.coeff=NewMonom.data.coeff + found->data.coeff;
				}
				else {
					while (tmp != monoms->pStop) {
						if (NewMonom.data < tmp->data) {
							monoms->insert_before(NewMonom.data, tmp->data);
							monoms->reset();
							break;
						}
						monoms->next();
						tmp = monoms->pCurr;
					}
					if (tmp == monoms->pStop) {
						monoms->insert_last(NewMonom.data);
						monoms->reset();
					}
				}
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
}

TPolynom::TPolynom(const TRingList<TMonom>* monoms_list) {
	monoms = new TRingList<TMonom>(*monoms_list);
	string _polynom = "";
	if (monoms->pFirst == nullptr) {
		return;
	}
	int degree_x = 0;
	int degree_y = 0;
	int degree_z = 0;
	Node<TMonom>* tmp = monoms->pCurr;
	while (tmp != monoms->pStop) {
		if (tmp->data.coeff > 0) {
			if (tmp != monoms->pFirst) {
				_polynom.append("+");
				_polynom.append(to_string(tmp->data.coeff));
			}
			else {
				_polynom.append(to_string(tmp->data.coeff));
			}
		}
		else if (tmp->data.coeff < 0) {
			_polynom.append(to_string(tmp->data.coeff));
		}
		degree_x = tmp->data.wrap_degree / 100;
		degree_y = (tmp->data.wrap_degree % 100) / 10;
		degree_z = (tmp->data.wrap_degree % 10);
		if (degree_x != 0) {
			if (degree_x == 1) {
				_polynom.append("*x");
			}
			else {
				_polynom.append("*x^");
				_polynom.append(to_string(degree_x));
			}
		}
		if (degree_y != 0 && degree_y != 1) {
			_polynom.append("*y^");
			_polynom.append(to_string(degree_y));
		}
		if (degree_z != 0 && degree_z != 1) {
			_polynom.append("*z^");
			_polynom.append(to_string(degree_z));
		}
		monoms->next();
		tmp = monoms->pCurr;
	}
	monoms->reset();
	polynom = _polynom;
}

string TPolynom::GetPolynomString()const {
	return polynom;
}

TPolynom::TPolynom(const TPolynom& obj) {
	monoms = new TRingList<TMonom>(*obj.monoms);
	polynom = obj.GetPolynomString();
}

TPolynom::~TPolynom() {
	delete monoms;
	polynom = "";
}



TPolynom TPolynom::operator+(const TPolynom& Q) {
	TPolynom R(*this);//результирующий полином
	Node<TMonom>* tmp_R = R.monoms->pCurr;
	Node<TMonom>* found_node;
	Node<TMonom>* tmp_Q = Q.monoms->pCurr;
	while (tmp_Q != Q.monoms->pStop) {
		found_node = R.monoms->search(tmp_Q->data);
		if (found_node != nullptr) {
			found_node->data.coeff=found_node->data.coeff + tmp_Q->data.coeff;
			if (found_node->data.coeff == 0) {
				if (tmp_R == R.monoms->pFirst) {
					R.monoms->next();
					R.monoms->remove(found_node->data);
					tmp_R = R.monoms->pCurr;
				}
				else {
					R.monoms->remove(found_node->data);
				}
			}
		}
		else {
			while (tmp_R != R.monoms->pStop) {
				if (tmp_Q->data.wrap_degree < tmp_R->data.wrap_degree) {
					R.monoms->insert_before(tmp_Q->data, tmp_R->data);
					R.monoms->reset();
					tmp_R = R.monoms->pCurr;
					break;
				}
				R.monoms->next();
				tmp_R = R.monoms->pCurr;
			}
			if (tmp_R == R.monoms->pStop) {
				R.monoms->insert_last(tmp_Q->data);
				R.monoms->reset();
			}
		}
		Q.monoms->next();
		tmp_Q = Q.monoms->pCurr;
	}
	Q.monoms->reset();
	return TPolynom(R.monoms);
}

TPolynom TPolynom::operator-(const TPolynom& Q) {
	TPolynom R(*this);//результирующий полином
	Node<TMonom>* tmp_R = R.monoms->pCurr;
	Node<TMonom>* found_node;
	Node<TMonom>* tmp_Q = Q.monoms->pCurr;
	while (tmp_Q != Q.monoms->pStop) {
		found_node = R.monoms->search(tmp_Q->data);
		if (found_node != nullptr) {
			found_node->data.coeff=found_node->data.coeff - tmp_Q->data.coeff;
			if (found_node->data.coeff == 0) {
				if (tmp_R == R.monoms->pFirst) {
					R.monoms->next();
					R.monoms->remove(found_node->data);
					tmp_R = R.monoms->pCurr;
				}
				else {
					R.monoms->remove(found_node->data);
				}
			}
		}
		else {
			while (tmp_R != R.monoms->pStop) {
				if (tmp_Q->data.wrap_degree < tmp_R->data.wrap_degree) {
					tmp_Q->data.coeff=tmp_Q->data.coeff * (-1);
					R.monoms->insert_before(tmp_Q->data, tmp_R->data);
					R.monoms->reset();
					tmp_R = R.monoms->pCurr;
					break;
				}
				R.monoms->next();
				tmp_R = R.monoms->pCurr;
			}
			if (tmp_R == R.monoms->pStop) {
				tmp_Q->data.coeff=tmp_Q->data.coeff * (-1);
				R.monoms->insert_last(tmp_Q->data);
				R.monoms->reset();
			}
		}
		Q.monoms->next();
		tmp_Q = Q.monoms->pCurr;
	}
	Q.monoms->reset();
	return TPolynom(R.monoms);
}

TPolynom TPolynom::operator*(const TPolynom& Q) {
	TPolynom R;//результирующий полином 
	Node<TMonom>* this_tmp_ = nullptr;
	Node<TMonom>* tmp_R_ = nullptr;
	Node<TMonom>* found_node = nullptr;
	Node<TMonom>* tmp_Q = nullptr;
	for (this_tmp_ = this->monoms->pCurr; this_tmp_ != this->monoms->pStop;) {
		for (tmp_Q = Q.monoms->pCurr; tmp_Q != Q.monoms->pStop;) {
			if (R.monoms == nullptr) {
				R = *new TPolynom(new TRingList<TMonom>(new Node<TMonom>(this_tmp_->data * tmp_Q->data)));
				Q.monoms->next();
				tmp_Q = Q.monoms->pCurr;
			}
			else {
				Node<TMonom> NewMonom = this_tmp_->data * tmp_Q->data;
				tmp_R_ = R.monoms->pCurr;
				while (tmp_R_ != R.monoms->pStop) {
					if (NewMonom.data <= tmp_R_->data) {
						if (NewMonom.data.wrap_degree == tmp_R_->data.wrap_degree) {//новый моном подобен
							tmp_R_->data.coeff=tmp_R_->data.coeff + NewMonom.data.coeff;
							R.monoms->reset();
							tmp_R_ = R.monoms->pCurr;
							break;
						}
						R.monoms->insert_before(NewMonom.data, tmp_R_->data);
						R.monoms->reset();
						tmp_R_ = R.monoms->pCurr;
						break;
					}
					
					R.monoms->next();
					tmp_R_ = R.monoms->pCurr;
				}
				if (tmp_R_ == R.monoms->pStop) {
					
						R.monoms->insert_last(NewMonom.data);
						R.monoms->reset();
						tmp_R_ = R.monoms->pCurr;
					
				}
				Q.monoms->next();
				tmp_Q = Q.monoms->pCurr;
			}
		}
		Q.monoms->reset();
		tmp_Q = Q.monoms->pCurr;

		this->monoms->next();
		this_tmp_ = this->monoms->pCurr;
	}
	this->monoms->reset();
	this_tmp_ = this->monoms->pCurr;
	return TPolynom(R.monoms);
}

const TPolynom& TPolynom::operator=(const TPolynom& Q) {
	polynom = Q.GetPolynomString();
	int size = polynom.size();
	if (size == 0) {
		monoms = new TRingList<TMonom>();
		return *this;
	}
	Node<TMonom>* tmp_Q = Q.monoms->pCurr;
	monoms = new TRingList<TMonom>(new Node<TMonom>(tmp_Q->data));
	Q.monoms->next();
	tmp_Q = Q.monoms->pCurr;
	Node<TMonom>* tmp_this = monoms->pCurr;
	while (tmp_Q != Q.monoms->pStop) {
		monoms->insert_last(tmp_Q->data);
		Q.monoms->next();
		tmp_Q = Q.monoms->pCurr;
	}
	return *this;
}

bool TPolynom::operator==(const TPolynom& Q)const {//для равных полиномов
	if (monoms->GetSize() != Q.monoms->GetSize()) {
		return false;
	}
	Node<TMonom>* tmp_this = monoms->pCurr;
	Node<TMonom>* tmp_Q = Q.monoms->pCurr;
	while (tmp_Q != Q.monoms->pStop) {
		if (tmp_this->data == tmp_Q->data && tmp_this->data.coeff == tmp_Q->data.coeff) {
			monoms->next();
			tmp_this = monoms->pStop;
			Q.monoms->next();
			tmp_Q = Q.monoms->pStop;
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
	TPolynom R(*this);
	Node<TMonom>* tmp_R = R.monoms->pCurr;
	int degree_x = 0;
	int degree_y = 0;
	int degree_z = 0;
	int new_wrap_degree = 0;
	while (tmp_R != R.monoms->pStop) {
		degree_x = tmp_R->data.wrap_degree / 100;
		if (degree_x == 0) {
			if (tmp_R == R.monoms->pStop) {
				R.monoms->remove(tmp_R->data);
				tmp_R = R.monoms->pCurr;
			}
			else {
				R.monoms->next();
				R.monoms->remove(tmp_R->data);
				tmp_R = R.monoms->pCurr;
			}
		}
		else {
			tmp_R->data.coeff=tmp_R->data.coeff * degree_x;
			degree_x--;
			degree_y = (tmp_R->data.wrap_degree % 100) / 10;
			degree_z = (tmp_R->data.wrap_degree % 10);
			new_wrap_degree = degree_x * 100 + degree_y * 10 + degree_z;
			tmp_R->data.wrap_degree=new_wrap_degree;
			R.monoms->next();
			tmp_R = R.monoms->pCurr;
		}
	}
	R.monoms->reset();
	return TPolynom(R.monoms);
}

TPolynom TPolynom::differentiate_by_y()const {
	TPolynom R(*this);
	Node<TMonom>* tmp_R = R.monoms->pCurr;
	int degree_x = 0;
	int degree_y = 0;
	int degree_z = 0;
	int new_wrap_degree = 0;
	while (tmp_R != R.monoms->pStop) {
		degree_y = (tmp_R->data.wrap_degree % 100) / 10;
		if (degree_y == 0) {
			if (tmp_R == R.monoms->pFirst) {
				R.monoms->remove(tmp_R->data);
				tmp_R = R.monoms->pCurr;
			}
			else {
				R.monoms->next();
				R.monoms->remove(tmp_R->data);
				tmp_R = R.monoms->pCurr;
			}
		}
		else {
			tmp_R->data.coeff=tmp_R->data.coeff * degree_y;
			degree_y--;
			degree_x = tmp_R->data.wrap_degree / 100;
			degree_z = (tmp_R->data.wrap_degree % 10);
			new_wrap_degree = degree_x * 100 + degree_y * 10 + degree_z;
			tmp_R->data.wrap_degree=new_wrap_degree;
			R.monoms->next();
			tmp_R = R.monoms->pCurr;
		}
	}
	R.monoms->reset();
	return TPolynom(R.monoms);
}
TPolynom TPolynom::differentiate_by_z()const {
	TPolynom R(*this);
	Node<TMonom>* tmp_R = R.monoms->pCurr;
	int degree_x = 0;
	int degree_y = 0;
	int degree_z = 0;
	int new_wrap_degree = 0;
	while (tmp_R != R.monoms->pStop) {
		degree_z = (tmp_R->data.wrap_degree % 10);
		if (degree_z == 0) {
			if (tmp_R == R.monoms->pFirst) {
				R.monoms->remove(tmp_R->data);
				tmp_R = R.monoms->pCurr;
			}
			else {
				R.monoms->next();
				R.monoms->remove(tmp_R->data);
				tmp_R = R.monoms->pCurr;
			}
		}
		else {
			tmp_R->data.coeff=tmp_R->data.coeff * degree_z;
			degree_z--;
			degree_x = tmp_R->data.wrap_degree / 100;
			degree_y = (tmp_R->data.wrap_degree % 100) / 10;
			new_wrap_degree = degree_x * 100 + degree_y * 10 + degree_z;
			tmp_R->data.wrap_degree=new_wrap_degree;
			R.monoms->next();
			tmp_R = R.monoms->pCurr;
		}
	}
	R.monoms->reset();
	return TPolynom(R.monoms);
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
		}while
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
			Node<TMonom>* pFirst = new Node<TMonom>(*(new TMonom(coeff, wrap_degree)));
			new_list_monoms = new TRingList<TMonom>(pFirst);
		}
		else {
			Node<TMonom> NewMonom = *(new Node<TMonom>(*(new TMonom(coeff, wrap_degree))));
			Node<TMonom>* tmp = new_list_monoms->pCurr;
			while (tmp != new_list_monoms->pStop) {
				if (NewMonom.data < tmp->data) {
					new_list_monoms->insert_before(NewMonom.data, tmp->data);
					new_list_monoms->reset();
					break;
				}
				new_list_monoms->next();
				tmp = new_list_monoms->pCurr;
			}
			if (tmp == new_list_monoms->pStop) {
				new_list_monoms->insert_last(NewMonom.data);
				new_list_monoms->reset();
			}
		}
		number++;
		i++;
		
	}
	
	TPolynom new_polynom(new_list_monoms);//#пользовательский полином
	Q = new_polynom;
	cout << "FLAG END" << endl;
	return istr;
}

ostream& operator<<(ostream& ostr, const TPolynom& Q) {
	cout << Q.GetPolynomString() << endl;
	cout << endl;

	return ostr;
}

