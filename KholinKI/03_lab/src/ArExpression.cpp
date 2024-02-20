#include "ArExpression.h"


ArithmeticExpression::ArithmeticExpression(const string& infix_) :infix(infix_) {
	priority =
	{
		{'(',1},{'+',2},{'-',2},{'*',3}, {'/',3}
	};
	ToPostfix();
}//priority


bool ArithmeticExpression::Is_Operator(char c)const {
	return c == '+' || c == '-' || c == '*' || c == '/' || c == '(' || c == ')';
}


bool ArithmeticExpression::Is_Operand_String(char c)const {
	return c >= 65 && c <= 90 || c >= 97 && c <= 122;
}


bool ArithmeticExpression::Is_Operand_const(char c)const {
	return c >= 48 && c <= 57;
}


double ArithmeticExpression::Transform(string str)const {
	int i = 0;
	string int_part;
	while (i < str.find(".")) {
		int_part += str[i];
		i++;
	}
	int index = str.find(".") + 1;
	string fractal_part_string;
	int count_signs = 0;
	while (index < str.size()) {
		count_signs++;
		fractal_part_string += str[index];
		index++;
	}
	double arg = 1;
	double fractal_part_double = stod(fractal_part_string);
	double multiplier = arg / pow(10, count_signs);
	double fractal_part_transformed = fractal_part_double * multiplier;
	double transformed = stod(int_part) + fractal_part_transformed;
	return transformed;
}


void ArithmeticExpression::Check()const {
	int i = 0;
	char c;
	while (i < infix.size()) {//проверяет на чужеродные символы
		c = infix[i];
		if (Is_Operand_String(c) || Is_Operand_const(c) ||
			Is_Operator(c) || c == '.' || c == ' ') {
			i++;
			continue;
		}
		else {
			throw "Mistake in arithmetic expression!";
		}
	}
	i = 0;

	int count_left_open_bracket = 0;
	int count_right_close_bracket = 0;
	char next_c;
	while (i < infix.size()) {
		c = infix[i];
		next_c = infix[i + 1];
		if (c == '(') {
			if (next_c == '+' || next_c == '*' || next_c == '/'
				|| next_c == ')' || next_c == ' ') {
				throw "Mistake in arithmetic expression!";
			}
			count_left_open_bracket++;
		}
		if (c == ' ' && next_c == ')') {
			throw "Mistake in arithmetic expression!";
		}
		if (c == ')') {
			count_right_close_bracket++;
		}
		i++;
	}
	if (count_left_open_bracket != count_right_close_bracket) {
		throw "Mistake in arithmetic expression!";
	}
	i = 0;

	char cc = 0;
	while (i < infix.size()) {
		c = infix[i];
		switch (c) {
		case '+': case '-': case '*': case '/':
		{
			cc = infix[i + 1];
			if (cc == ')') {
				throw "Mistake in arithmetic expression!";
			}
			auto tmp = priority.find(cc);
			if (tmp != priority.end() && tmp->first != ')'
				&& tmp->first != '(') {//повторы операций
				throw "Mistake in arithmetic expression!";
			}
		}
		default:
			cc = infix[i + 1];
			if (c == '.' && cc == '.') {//повторы точки
				throw "Mistake in arithmetic expression!";
			}
			if (c == ' ' && cc == ' ') {//повторы пробелов
				throw "Mistake in arithmetic expression!";
			}
			break;
		}
		i++;
	}
}


void ArithmeticExpression::Parse() {
//использованы правила идентификаторов переменных
	char c;
	char cc;
	int count_points = 0;
	string str;
	int i = 0;
	char first_c;
	Check();
	for (i = 0; i < (infix.size()); i++) {
		c = infix[i];
		first_c = c;
		switch (c) {
		case '+': case '-': case '*': case '/': case '(': case ')':
		{
			if (i == 0 && c != '-' && c != '(') {
				throw "Mistake in arithmetic expression!";
			}
			if (i == infix.size() - 1 && c != ')') {
				throw "Mistake in arithmetic expression!";
			}
			if ((c == '-' && i == 0) || (c == '-' && infix[i - 1] == '(')) {
				lexemes.push_back("0");
				lexemes.push_back("-");
				str = "";
				continue;
			}
			str = c;
			lexemes.push_back(str);
			str = "";
			continue;
		}
		default:
			while (!Is_Operator(c)) {
				if (c == '.' && str == "") {
					throw "Mistake in arithmetic expression!";
				}
				if (Is_Operand_const(c) && Is_Operand_const(first_c) || c == '.') {
					//константа-операнд
					if (c == '.') {
						count_points++;
						if (count_points > 1) {
							throw "Mistake in arithmetic expression!";
						}
					}
					str += c;
					i++;
					if (i == infix.size()) {
						break;
					}
					c = infix[i];
					cc = infix[i + 1];
					if (Is_Operand_String(c)) {
						throw "Mistake in arithmetic expression!";
						//встретился символ внутри константы-операнда
					}
					if (c == '.' && Is_Operator(infix[i + 1]) && i + 1 != infix.size()) {
						throw "Mistake in arithmetic expression!";
					}
					if (c == ' ' && Is_Operator(cc)) {
						c = cc;
						i++;
					}
					if (c == ' ') {
						throw "Mistake in arithmetic expression!";
					}
				}
				else {
					if (c == ' ' && first_c != ' ') {
						throw "Mistake in arithmetic expression!";
					}
					if (c == ' ' && first_c == ' ') {
						break;
					}
					str += c;
					i++;
					if (i == infix.size()) {
						break;
					}

					c = infix[i];
					cc = infix[i + 1];
					if (!(c != '.')) {
						throw "Mistake in arithmetic expression!";
					}
					if (c == ' ' && Is_Operator(cc)) {
						c = cc;
						i++;
					}
				}

			}
			if (c == ' ' && first_c == ' ') {
				break;
			}
			if (i == infix.size() - 1 && c != ')') {
				throw "Mistake in arithmetic expression!";
			}
			count_points = 0;
			lexemes.push_back(str);
			str = "";
			break;
		}
		if (c == ' ' && first_c == ' ') {
			continue;
		}
		if (c == '\0') {
			continue;
		}
		if (i != infix.size()) {
			str = c;
			lexemes.push_back(str);
			str = "";
		}
	}
}

void ArithmeticExpression::ToPostfix() {
	Parse();
	Stack<char> stack_ops;
	unsigned char c;
	string lexeme;
	char stack_op;
	for (int i = 0; i <= (lexemes.size() - 1); i++) {
		lexeme = lexemes[i];
		c = lexeme[0];
		switch (c) {
		case '(':
		{
			stack_ops.Push(c);
			break;
		}
		case '+': case '-': case '*': case '/': case '—':
		{
			while (!stack_ops.IsEmpty()) {
				stack_op = stack_ops.Pop();
				if (priority[c] <= priority[stack_op]) {
					string tmp_str;
					tmp_str = stack_op;
					postfix.push_back(tmp_str);
				}
				else {
					stack_ops.Push(stack_op);
					break;
				}
			}
			stack_ops.Push(c);
			break;
		}
		case ')':
		{
			stack_op = stack_ops.Pop();
			string tmp_str;
			while (stack_op != '(') {
				tmp_str = stack_op;
				postfix.push_back(tmp_str);
				stack_op = stack_ops.Pop();
			}
			break;
		}
		default:
			if (c >= 47 && c <= 57) {//operand-number
				if (lexeme.find(".") != -1) {
					operands.insert({ lexeme,Transform(lexeme) });
					postfix.push_back(lexeme);
					break;
				}
				operands.insert({ lexeme,stod(lexeme) });
				postfix.push_back(lexeme);
				break;
			}
			operands.insert({ lexeme, 0.0 });//operand-symbol(string)
			postfix.push_back(lexeme);
			break;
		}
	}

	while (!stack_ops.IsEmpty()) {
		stack_op = stack_ops.Pop();
		string tmp_str;
		tmp_str = stack_op;
		postfix.push_back(tmp_str);
	}
}


vector<string> ArithmeticExpression::GetOperands()const {
	vector<string> tmp;
	auto it_begin{ operands.begin() };
	auto it_end{ operands.end() };
	while (it_begin != it_end) {
		tmp.push_back(it_begin->first);
		it_begin++;
	}
	return tmp;
}


map<string, double> ArithmeticExpression::SetOperands
	(const vector<string> operands) {
	map<string, double> tmp;
	double value;
	auto it_begin{ operands.begin() };
	auto it_end{ operands.end() };
	while (it_begin != it_end) {
		if (this->operands.at(*it_begin) != 0 || *it_begin == "0") {
			tmp.insert({ *it_begin, this->operands.at(*it_begin) });
			it_begin++;
			continue;
		}
		cout << "Enter value of operand " << *it_begin << ": ";
		cin >> value;
		tmp.insert({ *it_begin, value });
		it_begin++;
	}
	return tmp;
}


double ArithmeticExpression::Calculate
(const map<string, double>& values) {
	Stack<double> expr_operands;
	string lexeme;
	char c;
	double left_op, right_op;
	auto it_begin = postfix.begin();
	auto it_end = postfix.end();
	while (it_begin != it_end) {
		lexeme = *it_begin;
		c = lexeme[0];
		switch (c) {
		case '+':
		{
			right_op = expr_operands.Pop();
			left_op = expr_operands.Pop();
			expr_operands.Push(left_op + right_op);
			break;
		}
		case '-':
		{
			right_op = expr_operands.Pop();
			left_op = expr_operands.Pop();
			expr_operands.Push(left_op - right_op);
			break;
		}
		case '*':
		{
			right_op = expr_operands.Pop();
			left_op = expr_operands.Pop();
			expr_operands.Push(left_op * right_op);
			break;
		}
		case '/':
		{
			try {
				right_op = expr_operands.Pop();
				left_op = expr_operands.Pop();
				if (right_op == 0) {
					throw std::domain_error("result division for value 0 not undefined!");
				}
				expr_operands.Push(left_op / right_op);
				break;
			}
			catch (const double zero) {
				cout << "Division by zero!" << endl;
			}
		}
		default:
			expr_operands.Push(values.at(lexeme));
			break;
		}
		it_begin++;
	}
	return expr_operands.Top();
}