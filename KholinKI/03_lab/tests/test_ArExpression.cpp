#include "ArExpression.h"

#include <gtest.h>


TEST(Stack, can_ToPostfix) {
	ArithmeticExpression<double> Expr("-X1-(6+11.5)-(-X2*X3+TURBO/(-20)*)-100*(-4)");
}

//TEST(ArithmeticExpression, can_get_operands) {
//	ArithmeticExpression<double> Expr("c/(a+b/d)");
//	vector<char> operands = Expr.GetOperands();
//}
//
//TEST(ArithmeticExpression, can_set_operands) {
//	ArithmeticExpression<double> Expr("(6+11.5)-(A*D+C)-100*4");
//	vector<string> operands = Expr.GetOperands();
//	map<string, double> init_operands = Expr.SetOperands(operands);
//}
//
//TEST(ArithmeticExpression, can_calculate_postfix) {
//	ArithmeticExpression<double> Expr("-(6+11.5)-(-A*D+C/(-20))-100*(-4)");
//	vector<string> operands = Expr.GetOperands();
//	map<string,double> init_operands = Expr.SetOperands(operands);
//	double result = Expr.Calculate(init_operands);
//}