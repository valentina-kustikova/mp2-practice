#include "arexp.h"

map <string, int> pr = {
	{"*", 3},
	{"/", 3},
	{"+", 2},
	{"-", 2},
	{"(", 1},
};

ArithmeticExpression::ArithmeticExpression() { 
	cin >> arexp; 
	arexp += '\0';
	GetTokens();
	ToPostfixForm();
}
ArithmeticExpression::ArithmeticExpression(const string& str) { 
	arexp = str; 
	arexp += '\0';
	GetTokens();
	ToPostfixForm();
}

bool ArithmeticExpression::IsOperation(const string& symbol) const noexcept {
	switch (symbol[0])
	{
	case '+': return true;
	case '-': return true;
	case '/': return true;
	case '*': return true;
	case '(': return true;
	case ')': return true;
	default:
		return false;
	}
}
bool ArithmeticExpression::IsOperation(const char& symbol) const noexcept {
	switch (symbol)
	{
	case '+': return true;
	case '-': return true;
	case '/': return true;
	case '*': return true;
	case '(': return true;
	case ')': return true;
	default:
		return false;
	}
}
bool ArithmeticExpression::IsInvalidSign(const char& symbol) const noexcept {
	return !IsOperation(symbol) && !isdigit(symbol) && !isalpha(symbol) && symbol != '.';
}
void ArithmeticExpression::GetTokens() {
	int i = 0;
	while (arexp[i] != '\0') {
		string tok = "";
		char symb = arexp[i];
		while (!IsOperation(symb) && symb != '\0' && symb != ' ') {
			tok += symb;
			i += 1;
			symb = arexp[i];
		}
		if (tok != "") mas.push_back(tok);
		if (IsOperation(symb)) { 
			string c(1, symb);
			mas.push_back(c);
		}
		i += 1;
	}
}
void ArithmeticExpression::GetValues() {
	for (const string& i : mas) {
		if (!IsOperation(i) && !IsConst(i) && !values.count(i)) {
			double val;
			cout << i << " = ";
			cin >> val;
			values[i] = val;
		}
		else if (IsConst(i)) values[i] = stod(i);
	}
}
bool ArithmeticExpression::IsParam(const string& tok) const noexcept{
	if (isdigit(tok[0])) return false;
	int i = 0;
	while (tok[i] != '\0'){
		if (IsInvalidSign(tok[i]) || IsOperation(tok[i])) return false;
		i += 1;
	}
	return true;
}
bool ArithmeticExpression::IsConst(const string& tok) const noexcept {
	int i = 0;
	while (tok[i] != '\0') {
		if (IsInvalidSign(tok[i]) || isalpha(tok[i]) || IsOperation(tok[i])) return false;
		i += 1;
	}
	return true;
}


void ArithmeticExpression::ToPostfixForm() {
	TStack<string> oper(mas.size());
	for (const string& i : mas) {
		if (IsConst(i) || IsParam(i)) post_form.push_back(i);
		else if (IsOperation(i)) {
			if (i == "(") oper.Push(i);
			else if (i == ")") {
				while (oper.Top() != "(") post_form.push_back(oper.Pop());
				if (oper.IsEmpty()) throw "not found left bracket";
				else oper.Pop();
			}
			else if (oper.IsEmpty() || pr[oper.Top()] < pr[i]) oper.Push(i);
			else {
				while (!oper.IsEmpty() && pr[oper.Top()] >= pr[i]) post_form.push_back(oper.Pop());
				oper.Push(i);
			}
		}
		else throw ("invalid name %s", i);
	}
	while (!oper.IsEmpty()) {
		if (oper.Top() == "(") throw "right bracket not found";
		post_form.push_back(oper.Pop());
	}
}
float ArithmeticExpression::Calculate() {
	GetValues();
	TStack<float> st(post_form.size());
	st.Push(0);
	for (const string& i : post_form) {
		if (!IsOperation(i)) st.Push(values[i]);
		else {
			switch (i[0]) {
			case '+': {
				float b = st.Pop(), a = st.Pop();
				st.Push(a + b);
				break;
			}
			case '*': {
				float b = st.Pop(), a = st.Pop();
				st.Push(a * b);
				break;
			}
			case '-': {
				float b = st.Pop(), a = st.Pop();
				st.Push(a - b);
				break;
			}
			case '/': {
				float b = st.Pop(), a = st.Pop();
				st.Push(a / b);
				if (b == 0) throw "Division by zero";
				break;
			}
			}
		}
	}
	return st.Pop();
}

string ArithmeticExpression::InfixForm() const{
	string str = "";
	for (string i : mas) {
		str += i;
	}
	return str;
}
string ArithmeticExpression::PostfixForm() const {
	string str = "";
	for (string i : post_form) {
		str += i;
	}
	return str;
}
