#ifndef _TARITHMETIC_EXPRESSION_H
#define _TARITHMETIC_EXPRESSION_H

#include <iostream>
#include <map>
#include <vector>
#include "tstack.h"

using namespace std;

static map<char, int> OperatorPriority = {
	{'*', 3},
	{'/', 3},
	{'+', 2},
	{'-', 2},
	{'(', 1},
	{')', 1},
	{'=', 0},
};

static bool IsOperator(const char& op) {
	auto it = OperatorPriority.find(op);
	if (it != OperatorPriority.end())
		return true;
	else
		return false;
}


TStack<char> ConvertToPostfixForm(const string& InfixForm) {
	TStack<char> pf;
	TStack<char> op;

	for (int i = 0; i < InfixForm.size(); i++) {
		char token = InfixForm[i];
		if (IsOperator(token)) {

			if (token == ')') {
				while (!op.IsEmpty()) {
					if (op.Top() == '(') {
						op.Pop();
						break;
					} 
					pf.Push(op.Top());
					op.Pop();
				}
			}

			else if (token == '(') op.Push(token);

			else if (!op.IsEmpty()) {
				if (OperatorPriority[token] < OperatorPriority[op.Top()]) {
					while (OperatorPriority[op.Top()] >= OperatorPriority[token]) {
						pf.Push(op.Top());
						op.Pop();
						if (op.IsEmpty()) break;
					}
				}
				else op.Push(token);
			}
		}
		else pf.Push(token);
	}

	while (!op.IsEmpty()) {
		pf.Push(op.Top());
		op.Pop();
	}

	return pf;
}

double Calculate(const string& PostfixForm, map<char, double> values) {
	TStack<double> s;
	for (int i = 0; i < PostfixForm.size(); i++) {
		char token = PostfixForm[i];
		if (!IsOperator(token)) {
			s.Push(values[token]);
		}
		else {
			double a, b;
			b = values[s.Top()];
			s.Pop();
			a = values[s.Top()];
			s.Pop();

			switch (token) {
			case '*':
				s.Push(a * b);
				break;
			
			case '/':
				s.Push(a / b);
				break;
			
			case '+':
				s.Push(a + b);
				break;
			
			case '-':
				s.Push(a - b);
				break;
			
			default:
				throw "Error: calculation error";
				break;
			}
		}
	}
	return values[s.Top()];
}

//
//class TArithmeticExpression {
//private:
//	string InfixForm;
//	TStack<char> PostfixForm;
//
//	//map<string, double> OperandValues;
//
//public:
//	TArithmeticExpression(string _InfixForm = "");
//
//	void PrintInfixForm();
//	void PrintPostfixForm();
//
//	//TStack<string> GetInfixArrayForm();
//	//TStack<string> GetInfixArrayForm_reversed();
//
//	void ConvertToPostfixForm();
//
//	double Calculate(map<char, double> OperandValues);
//
//	void DEBUG_PrintPostfixForm();
//};
//
//TArithmeticExpression::TArithmeticExpression(string _InfixForm) {
//	InfixForm = _InfixForm;
//}
//
//void TArithmeticExpression::ConvertToPostfixForm() {
//	TStack<char> pf;
//	TStack<char> op;
//
//	for (int i = 0; i = InfixForm.size(); i++) {
//		char token = InfixForm[i];
//		if (IsOperator(token)) {
//
//			if (token == ')') {
//				while (op.Top() != '(' || !op.IsEmpty()) {
//					pf.Push(op.Top());
//					op.Pop();
//				}
//			}
//
//			else if (token == '(') op.Push(token);
//
//			else if (OperatorPriority[token] < OperatorPriority[op.Top()]) {
//				while (OperatorPriority[op.Top()] >= OperatorPriority[token] && !op.IsEmpty()) {
//					pf.Push(op.Top());
//					op.Pop();
//				}
//			}
//
//			else op.Push(token);
//
//		}
//		else pf.Push(token);
//	}
//
//	while (!op.IsEmpty()) {
//		pf.Push(op.Top());
//		op.Pop();
//	}
//	
//	PostfixForm = pf;
//}
//
///*
//void TArithmeticExpression::ConvertToPostfixForm() {
//	TStack<char> operators;
//
//	for (int i = 0; i < InfixForm.size(); i++) {
//		char token = InfixForm[i];
//		
//		if (!IsOperator(token)) {
//			PostfixForm.Push(token);
//		}
//		
//		else {
//			if (token == ')') {
//				while (!operators.IsEmpty() || operators.Top() != '(') {
//					PostfixForm.Push(operators.Top());
//					operators.Pop();
//				}
//			}
//
//			else {
//				if (OperatorPriority[token] < OperatorPriority[operators.Top()]) {
//					while (OperatorPriority[operators.Top()] >= OperatorPriority[token]) {
//						PostfixForm.Push(operators.Top());
//						operators.Pop();
//					}
//				}
//
//				else {
//					operators.Push(token);
//				}
//			}
//		}
//	}
//
//	while (!operators.IsEmpty()) {
//		PostfixForm.Push(operators.Top());
//		operators.Pop();
//	}
//}
//*/
//
//void TArithmeticExpression::PrintInfixForm() {
//	cout << InfixForm;
//}
//
//void TArithmeticExpression::PrintPostfixForm() {
//	TStack<char> pf(PostfixForm);
//	TStack<char> rpf;
//
//	while (!pf.IsEmpty()) {
//		rpf.Push(pf.Top());
//		pf.Pop();
//	}
//
//	while (!rpf.IsEmpty()) {
//		cout << rpf.Top();
//		rpf.Pop();
//	}
//}
//
//void TArithmeticExpression::DEBUG_PrintPostfixForm() {
//	PostfixForm.DUBUG_Print();
//}
////void TArithmeticExpression::PrintPostfixForm() {
////	TStack<char> pf(PostfixForm);
////	TStack<char> rpf;
////
////	while (!pf.IsEmpty()) {
////		rpf.Push(pf.Top());
////		pf.Pop();
////	}
////
////	while (!rpf.IsEmpty()) {
////		cout << rpf.Top();
////		rpf.Pop();
////	}
////}


#endif // !_TARITHMETIC_EXPRESSION_H
