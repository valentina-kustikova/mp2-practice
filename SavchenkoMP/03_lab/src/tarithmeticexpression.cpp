#include "tarithmeticexpression.h"

map<char, int> TArithmeticExpression::priority = {
	{'*', 3},
	{'/', 3},
	{'+', 2},
	{'-', 2},
	{'(', 1},
	{')', 1}
	//{'=', 0}
};

void TArithmeticExpression::Parse() {
	for (char c : infix)
		lexems.push_back(c);
}
void TArithmeticExpression::ToPostfix() {
	Parse();
	TStack<char> st;
	char stackToken;
	for (char token : lexems) {
		switch (token) {
		case '(':
			st.Push(token);
			break;
		case ')':
			stackToken = st.Top();
			st.Pop();
			while (stackToken != '(') {
				postfix += stackToken;
				stackToken = st.Top();
				st.Pop();
			}
			break;
		case '+': case '-': case '*': case '/': 
			while (!st.IsEmpty()) {
				stackToken = st.Top();
				st.Pop();
				if (priority[token] <= priority[stackToken])
					postfix += stackToken;
				else {
					st.Push(stackToken);
					break;
				}
			}
			st.Push(token);
			break;
		default:
			operands.insert({ token, 0.0 });
			postfix += token;
			break;
		} // switch
	} // for
	while (!st.IsEmpty()) {
		stackToken = st.Top();
		st.Pop();
		postfix += stackToken;
	}
}

TArithmeticExpression::TArithmeticExpression(string _infix) {
	infix = _infix;
	ToPostfix();
}

vector<char> TArithmeticExpression::GetOperands() const {
	vector<char> op;
	for (const auto& item : operands)
		op.push_back(item.first);
	return op;
}
void TArithmeticExpression::SetValues() {
	double val;
	for (auto& op : operands) {
		cout << "Enter value of " << op.first << ": ";
		cin >> val;
		operands[op.first] = val;
	}
	
}
void TArithmeticExpression::SetValues(map<char, double>& values) {
	for (auto& op : operands) {
		operands[op.first] = values[op.first];
	}
}

double TArithmeticExpression::Calculate() {
	return Calculate(operands);
}
double TArithmeticExpression::Calculate(const map<char, double>& values) {
	for (auto& val : values) {
		try {
			operands.at(val.first) = val.second;
		}
		catch (out_of_range& e) { }
	}

	TStack<double> st;
	double leftOp, rightOp;
	for (char lexem : postfix) {
		switch (lexem) {
		case '+':
			rightOp = st.Top();
			st.Pop();
			leftOp = st.Top();
			st.Pop();
			st.Push(leftOp + rightOp);
			break;
		case '-':
			rightOp = st.Top();
			st.Pop();
			leftOp = st.Top();
			st.Pop();
			st.Push(leftOp - rightOp);
			break;
		case '*':
			rightOp = st.Top();
			st.Pop();
			leftOp = st.Top();
			st.Pop();
			st.Push(leftOp * rightOp);
			break;
		case '/':
			rightOp = st.Top();
			st.Pop();
			leftOp = st.Top();
			st.Pop();
			st.Push(leftOp + rightOp);
			break;
		default:
			st.Push(operands[lexem]);
			break;
		}
	}
	return st.Top();
}