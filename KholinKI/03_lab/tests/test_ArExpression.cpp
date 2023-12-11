#include "ArExpression.h"

#include <gtest.h>

//#test
//"---.3)9X!&1-((+-/*6+.11..5()-ARM11.KI)-(-X2*!#@X3+TURBO/(-20*190.)*)-100/(*(-4)"
//"X1-(6+11.5-ARM11KI)-(-X2*X1293AMxkl+TUR11BO/(-20*190))-100/(-4)"



TEST(ArExpression, throw_when_check_characters_is_failed) {
	ASSERT_ANY_THROW(ArithmeticExpression<double> Expr("(A+B-D@)*(-400/(-!20)*amx32)+E%"));
}

TEST(ArExpression, throw_when_check_brackets_is_failed) {
	ASSERT_ANY_THROW(ArithmeticExpression<double> Expr("(A+B-D)*(-400/-20)*amx32)+E"));
}

TEST(ArExpression, throw_when_check_brackets_is_failed_op_in_start_bracket) {
	ASSERT_ANY_THROW(ArithmeticExpression<double> Expr("(A+B-D)*((/400/20)*amx32)+E"));
}

TEST(ArExpression, throw_when_check_brackets_is_failed_op_in_end_bracket) {
	ASSERT_ANY_THROW(ArithmeticExpression<double> Expr("(A+B-D)*((400/20)*amx32/)+E"));
}

TEST(ArExpression, throw_when_op_in_start_expression) {
	ASSERT_ANY_THROW(ArithmeticExpression<double> Expr("/(A+B-D)*((400/20)*amx32)+E"));
}


TEST(ArExpression, throw_when_op_in_end_expression) {
	ASSERT_ANY_THROW(ArithmeticExpression<double> Expr("(A+B-D)*((400/20)*amx32)+E/"));
}

TEST(ArExpression, no_throw_when_op_unary_minus_in_start) {
	ASSERT_NO_THROW(ArithmeticExpression<double> Expr("-(A+B-D)*((400/20)*amx32)+E"));
}

TEST(ArExpression, throw_when_brackets_are_next_to_each_other) {
	ASSERT_ANY_THROW(ArithmeticExpression<double> Expr("(A+B-D)*(-400.25//(-20)*()amx32)+E"));
}

TEST(ArExpression, throw_when_check_operations_is_failed_two_ops) {
	ASSERT_ANY_THROW(ArithmeticExpression<double> Expr("(A+B-D)*(-400//(-20)*amx32)+E"));
}

TEST(ArExpression, throw_when_check_operations_is_failed_two_points) {
	ASSERT_ANY_THROW(ArithmeticExpression<double> Expr("(A+B-D)*(-400..25//(-20)*amx32)+E"));
}

TEST(ArExpression, throw_when_to_postfix_) {
	ASSERT_ANY_THROW(ArithmeticExpression<double> Expr("(A+B-D)*(-400//(-20)*amx32)+E"));
}

TEST(ArExpression, throw_when_empty_integer_part) {
	ASSERT_ANY_THROW(ArithmeticExpression<double> Expr(".4+3*(-4)"));
}

TEST(ArExpression, throw_when_empty_fractional_part) {
	ASSERT_ANY_THROW(ArithmeticExpression<double> Expr("4+4.*(-4)"));
}

TEST(ArExpression, throw_when_double_points_in_constant) {
	ASSERT_ANY_THROW(ArithmeticExpression<double> Expr("4+4..4*(-4)"));
}

TEST(ArExpression, throw_when_operand_inside_constant_1) {
	ASSERT_ANY_THROW(ArithmeticExpression<double> Expr("4+421.BMV3*(-4)"));
}


TEST(ArExpression, operand_inside_constant_2) {
	ASSERT_ANY_THROW(ArithmeticExpression<double> Expr("4+4.B4*(-4)"));
}


TEST(ArExpression, point_inside_operand) {
	ASSERT_ANY_THROW(ArithmeticExpression<double> Expr("4+MX.92*(-4)"));
}


TEST(ArExpression, can_to_postfix) {
	ASSERT_NO_THROW(ArithmeticExpression<double> Expr("X1-(6+11.5-ARM11KI)-(-X2*X1293AMxkl+TUR11BO/(-20*190))-100/(-4)"));
}

TEST(ArExpression, unary_minus_after_bracket) {
	ArithmeticExpression<double> Expr("5*(-4)");
	vector<string> operands = Expr.GetOperands();
	map<string, double> values = Expr.SetOperands(operands);
	double unary = Expr.Calculate(values);
	EXPECT_EQ(unary, -20);
}



TEST(ArExpression, can_get_infix) {
	ArithmeticExpression<double> Expr("-5+4*(-m)");
	ASSERT_NO_THROW(Expr.GetInfix());
}

TEST(ArExpression, can_get_postfix) {
	ArithmeticExpression<double> Expr("-5+4*(-m)");
	ASSERT_NO_THROW(Expr.GetPostfix());
}

TEST(ArExpression, can_get_operands) {
	ArithmeticExpression<double> Expr("-5+4*(-m)");
	ASSERT_NO_THROW(vector<string> operands = Expr.GetOperands());
}

TEST(ArExpression, can_calculate_1) {
	ArithmeticExpression<double> Expr("-5+4*(-3)");
	vector<string> operands = Expr.GetOperands();
	map<string, double> values = Expr.SetOperands(operands);
	ASSERT_NO_THROW(double unary = Expr.Calculate(values));
}

TEST(ArExpression, can_calculate_2) {
	ArithmeticExpression<double> Expr("A+(B*C)");
	vector<string> operands = Expr.GetOperands();
	map<string, double> values = Expr.SetOperands(operands);
	ASSERT_NO_THROW(double unary = Expr.Calculate(values));
}

TEST(ArExpression, unary_minus_start_expression) {
	ArithmeticExpression<double> Expr("-5+4");
	vector<string> operands = Expr.GetOperands();
	map<string, double> values = Expr.SetOperands(operands);
	double unary = Expr.Calculate(values);
	EXPECT_EQ(unary, -1);
}

TEST(ArExpression, binary_minus) {
	ArithmeticExpression<double> Expr("5*4-8");
	vector<string> operands = Expr.GetOperands();
	map<string, double> values = Expr.SetOperands(operands);
	double unary = Expr.Calculate(values);
	EXPECT_EQ(unary, 12);
}

