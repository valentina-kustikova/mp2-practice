#include "ArExpression.h"

#include <gtest.h>


//TEST(Stack, can_ToPostfix) {
//	ArithmeticExpression<double> Expr("(a+b*c)*(d/c-e)+g");//контроль на чужеродные символы
//}

TEST(ArithmeticExpression, can_get_operands) {
	ArithmeticExpression<double> Expr("c/(a+b/d)");
	vector<char> operands = Expr.GetOperands();
}

TEST(ArithmeticExpression, can_set_operands) {
	ArithmeticExpression<double> Expr("c/(a+b/d)");
	vector<char> operands = Expr.GetOperands();
	map<char, double> init_operands = Expr.SetOperands(operands);
}

TEST(ArithmeticExpression, can_calculate_postfix) {
	ArithmeticExpression<double> Expr("c/(a+b/d)");
	vector<char> operands = Expr.GetOperands();
	map<char, double> init_operands = Expr.SetOperands(operands);
	double result = Expr.Calculate(init_operands);
}
