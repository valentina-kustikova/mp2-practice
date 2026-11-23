#include "postfix_form.h"
#include "stack.h"
#include <stdexcept>

int PostfixForm::GetPriority(char op) const {
	switch (op) {
	case '+':
	case '-':
		return 1;
	case '*':
	case '/':
		return 2;
	case '(':
		return 0;
	default:
		return -1;
	}
}

PostfixForm::PostfixForm(const std::string& expr) {
	infix = expr;
	TStack<char> operators(infix.size() + 1);
	postfix.clear();

	int i = 0;
	while (i < infix.length()) {
		if (infix[i] == ' ') {
			i++;
			continue;
		}

		if ((infix[i] >= '0' && infix[i] <= '9') || infix[i] == '.') {
			std::string number;
			bool hasDot = false;

			while ((i < infix.length() &&
				infix[i] >= '0' && infix[i] <= '9') || infix[i] == '.') {

				if (infix[i] == '.') {
					if (hasDot || i == 0 ||i + 1 >= infix.length() || 
						infix[i + 1] < '0' || infix[i + 1] > '9') {
						throw std::invalid_argument("Invalid number");
					}
					hasDot = true;
				}
				number += infix[i];
				i++;
			}
			postfix += number + " ";
		}
		
		else if (infix[i] == '(') {
			operators.Push('(');
			i++;
		}

		else if (infix[i] == ')') {
			while (!operators.IsEmpty() && operators.Top() != '(') {
				postfix += operators.Top();
				postfix += " ";
				operators.Pop();
			}

			if (operators.IsEmpty()) {
				throw std::invalid_argument("Mismatched parentheses");
			}

			operators.Pop();
			i++;
		}

		else if (infix[i] == '+' || infix[i] == '-' || 
			infix[i] == '*' || infix[i] == '/') {

			char op = infix[i];

			while (!operators.IsEmpty() &&
				operators.Top() != '(' &&
				
				GetPriority(operators.Top()) >= GetPriority(op)) {
				
				postfix += operators.Top();
				postfix += " ";
				operators.Pop();

			}

			operators.Push(op);
			i++;

		}

		else {
			throw std::invalid_argument("Invalid character");
		}

	}

	while (!operators.IsEmpty()) {
		if (operators.Top() == '(') {
			throw std::invalid_argument("Mismatched parentheses");
		}

		postfix += operators.Top();
		postfix += " ";
		operators.Pop();
	}

	if (!postfix.empty()) {
		postfix.pop_back();
	}

}

double PostfixForm::Calculate() const {
	TStack<double> numbers(postfix.length() + 1);
	
	int i = 0;
	while (i < postfix.length()) {
		if (postfix[i] == ' ') {
			i++;
			continue;
		}
		std::string token;

		while (i < postfix.length() && postfix[i] != ' ') {
			token += postfix[i];
			++i;
		}

		if (token == "+" || token == "-" ||
			token == "*" || token == "/") {
			if (numbers.size() < 2) {
				throw std::invalid_argument("Not enough numbers");
			}
			double b = numbers.Top();
			numbers.Pop();
			double a = numbers.Top();
			numbers.Pop();
			double result;
			
			if (token == "+") {
				result = a + b;
			}

			else if (token == "-") {
				result = a - b;
			}

			else if (token == "*") {
				result = a * b;
			}

			else {
				if (b == 0) {
					throw std::invalid_argument("Division by zero");
				}
				result = a / b;
			}
			numbers.Push(result);
		}

		else {
			double value = std::stod(token);
			numbers.Push(value);
		}
	}
	if (numbers.size() != 1) {
		throw std::invalid_argument("Invalid expression");
	}
	
	return numbers.Top();
}

	

