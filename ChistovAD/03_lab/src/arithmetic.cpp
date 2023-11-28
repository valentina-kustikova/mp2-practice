#include "stack.h"
#include "arithmetic.h"

bool TArithmeticExpession::IsOperator(const char& c) const {
	return priority.find(c) != priority.end();
}

bool TArithmeticExpession::IsConst(const string& s) const {
	for (int i = 0; i < s.size(); i++) {
		if (s[i] < '0' || s[i] > '9') {
			if (s[i] != '.')
				return false;
		}
		break;
	}
	return true;
}

TArithmeticExpession::TArithmeticExpession(const string& _infix) {
	infix = _infix;
	ToPostfix();
}


void TArithmeticExpession::Parse() {

}

void TArithmeticExpession::ToPostfix() {

}


double TArithmeticExpession::Calculate(const map<string, double>& values) {

}

