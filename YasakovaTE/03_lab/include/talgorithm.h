#ifndef _TALGOTITM_H
#define _TALGOTITM_H

#include "stack.h"
#include <map>
#include <vector>
#include <string>
using namespace std;

class Talgorithm {
private:
	static bool isOperator(const string& str);
	static int getPrecedence(const string& op);
public:
	static void isValidTalgorithm(const vector<string>& infixTalgorithm);
	static vector<string> splitTalgorithm(const string& expression);
	static Stack<string> infixToPostfix(const vector<string>& infixTalgorithm);
	static map<string, double> getOperandValues(const vector<string>& strs);
	static double evaluatePostfixTalgorithm(const map<string, double>& operandValues, Stack<string>& postfixTalgorithm);
};

#endif
