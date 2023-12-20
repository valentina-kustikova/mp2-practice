#include "tarithmetic_expression.h"
#include "tstack.h"

TArithmeticExpression::TArithmeticExpression(string infx): infix(infx) {
	priority = { {'(',0}, {'-', 1}, {'+', 1}, {'*', 2}, {'/', 2} };
	ToPostfix();
}


void TArithmeticExpression::Parse() {
	for (char c : infix) {
		lexems.push_back(c);
	}
}

void TArithmeticExpression::ToPostfix() {
	Parse();
	TStack<char> st;
	char StackItem;
	for (char item : lexems) {
		switch (item) 
		{case '(' :
			st.Push(item);
			break;
		case')':
			StackItem = st.Top();
			st.Pop();
			while (StackItem != '(') {
				postfix += StackItem;
				StackItem = st.Top();
				st.Pop();
			}
			break;
		case '+' : case '-': case'*': case '/':
			while (st.IsEmpty()) {
				StackItem = st.Top();
				st.Pop();
				if (priority[item] < priority[StackItem]) {
					postfix += StackItem;
				}
				else {
					st.Push(StackItem);
				}
			}
			st.Push(item);
			break;
		default:
			operands.insert({ item, 0.0 });
			postfix += item;
			break;
		} //switch
	} //for
	while (!st.IsEmpty()) {
		StackItem = st.Top();
		st.Pop();
		postfix += StackItem;
	}
}


vector<char> TArithmeticExpression::GetOperands() const{
	vector<char> op;
	for (const auto& item : operands) {
		op.push_back(item.first);
	}
	return op;
}


double TArithmeticExpression::Calculate(const map<char, double>& values) {
	for (auto& val : values) {
		try
		{
			operands.at(val.first) = val.second;
		}
		catch (out_of_range& e) {}
	}
	TStack<double> st;
	double leftOperand, rightOperand;
	for 
}