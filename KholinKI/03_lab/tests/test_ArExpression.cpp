#include "ArExpression.h"

#include <gtest.h>

//#test
//"---.3)9X!&1-((+-/*6+.11..5()-ARM11.KI)-(-X2*!#@X3+TURBO/(-20*190.)*)-100/(*(-4)"
//предусмотреть русский язык
TEST(Stack, can_ToPostfix) {
	ASSERT_NO_THROW(ArithmeticExpression<double> Expr("X1-(6+11.5-ARM11KI)-(-X2*X1293AMxkl+TUR11BO/(-20*190))-100/(-4)"));
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
