#include "ArExpression.h"


#include <gtest.h>

//#test
//"---.3)9X!&1-((+-/*6+.11..5()-ARM11.KI)-(-X2*!#@X3+TURBO/(-20*190.)*)-100/(*(-4)"
// 
//"X1-(6+11.5-ARM11KI)-(-X2*X1293AMxkl+TUR11BO/(-20*190))-100/(-4)"



TEST(ArExpression, throw_when_check_operations_is_failed_two_ops_2_degree) {
	ASSERT_ANY_THROW(ArithmeticExpression Expr("(A + B - D)*(-400 ^^ (-20) * amx32) + E"));
}

TEST(ArExpression, throw_when_check_characters_is_failed) {
	ASSERT_ANY_THROW(ArithmeticExpression Expr("(A + B - D@)*(-400 / (-!20) * amx32) + E%"));
}

TEST(ArExpression, throw_when_check_brackets_is_failed) {
	ASSERT_ANY_THROW(ArithmeticExpression Expr("(A + B - D) * (-400 / -20) * amx32) + E"));
}

TEST(ArExpression, throw_when_check_brackets_is_failed_op_in_start_bracket) {
	ASSERT_ANY_THROW(ArithmeticExpression Expr("(A + B - D) * ((/400 / 20) * amx32) + E"));
}

TEST(ArExpression, throw_when_check_brackets_is_failed_op_in_end_bracket) {
	ASSERT_ANY_THROW(ArithmeticExpression Expr("(A + B - D)*((400 / 20) * amx32/) + E"));
}

TEST(ArExpression, throw_when_op_in_start_expression) {
	ASSERT_ANY_THROW(ArithmeticExpression Expr("/(A+B-D)*((400/20)*amx32)+E"));
}


TEST(ArExpression, throw_when_op_in_end_expression) {
	ASSERT_ANY_THROW(ArithmeticExpression Expr("(A+B-D)*((400/20)*amx32)+E/"));
}

TEST(ArExpression, no_throw_when_op_unary_minus_in_start) {
	ASSERT_NO_THROW(ArithmeticExpression Expr("-(A+B-D)*((400/20)*amx32)+E"));
}

TEST(ArExpression, throw_when_brackets_are_next_to_each_other) {
	ASSERT_ANY_THROW(ArithmeticExpression Expr("(A + B - D) * (-400.25 // (-20) * () amx32) + E"));
}

TEST(ArExpression, throw_when_check_operations_is_failed_two_ops_1_division) {
	ASSERT_ANY_THROW(ArithmeticExpression Expr("(A + B - D)*(-400 // (-20) * amx32) + E"));
}



TEST(ArExpression, throw_when_double_space) {
	ASSERT_ANY_THROW(ArithmeticExpression Expr("(A + B - D) * (-400 / (-20) * am  x32) + E"));
}

TEST(ArExpression, throw_when_check_operations_is_failed_two_points) {
	ASSERT_ANY_THROW(ArithmeticExpression Expr("(A+B-D)*(-400..25/(-20)*amx32)+E"));
}

TEST(ArExpression, throw_when_to_postfix_) {
	ASSERT_ANY_THROW(ArithmeticExpression Expr("(A+B-D)*(-400//(-20)*amx32)+E"));
}

TEST(ArExpression, throw_when_empty_integer_part) {
	ASSERT_ANY_THROW(ArithmeticExpression Expr(".4 + 3 * (-4)"));
}

TEST(ArExpression, throw_when_empty_fractional_part) {
	ASSERT_ANY_THROW(ArithmeticExpression Expr("4+4.*(-4)"));
}

TEST(ArExpression, throw_when_double_points_in_constant) {
	ASSERT_ANY_THROW(ArithmeticExpression Expr("4+4..4*(-4)"));
}

TEST(ArExpression, throw_when_operand_inside_constant_1) {
	ASSERT_ANY_THROW(ArithmeticExpression Expr("4 + 421.BMV3 * (-4)"));
}

TEST(ArExpression, throw_when_space_within_operand_1) {
	ASSERT_ANY_THROW(ArithmeticExpression Expr("4+42 1*(-4)"));
}

TEST(ArExpression, throw_when_space_within_operand_2) {
	ASSERT_ANY_THROW(ArithmeticExpression Expr("4+421-A BC*(-4)"));
}

TEST(ArExpression, throw_when_space_in_start_bracket) {
	ASSERT_ANY_THROW(ArithmeticExpression Expr("4+421*( -4)"));
}

TEST(ArExpression, throw_when_degree_in_start_bracket) {
	ASSERT_ANY_THROW(ArithmeticExpression Expr("4+421*(^-4)"));
}

TEST(ArExpression, throw_when_space_in_the_end_bracket) {
	ASSERT_ANY_THROW(ArithmeticExpression Expr("4+421*(-4 )"));
}

TEST(ArExpression, throw_when_degree_in_the_end_bracket) {
	ASSERT_ANY_THROW(ArithmeticExpression Expr("4+421*(-4^)"));
}


TEST(ArExpression, throw_when_operand_inside_constant_2) {
	ASSERT_ANY_THROW(ArithmeticExpression Expr("4+4.B4*(-4)"));
}


TEST(ArExpression, throw_when_point_inside_operand) {
	ASSERT_ANY_THROW(ArithmeticExpression Expr("4+MX.92*(-4)"));
}


TEST(ArExpression, unary_minus_after_bracket) {
	ArithmeticExpression Expr("5*(-4)");
	vector<string> operands = Expr.GetOperands();
	map<string, double> values = Expr.SetOperands(operands);
	double unary = Expr.Calculate(values);
	EXPECT_EQ(unary, -20);
}

TEST(ArExpression, can_to_postfix) {
	ASSERT_NO_THROW(ArithmeticExpression Expr("X1 - (6 + 11.5 - ARM11KI) - (-X2 * X1293AMxkl + TUR11BO / (-20 * 190)) - 100 / (-4)"));
}


TEST(ArExpression, no_throw_when_can_get_infix) {
	ArithmeticExpression Expr("-5+4*(-m)");
	ASSERT_NO_THROW(Expr.GetInfix());
}

TEST(ArExpression, no_throw_when_get_postfix) {
	ArithmeticExpression Expr("-5+4*(-m)");
	ASSERT_NO_THROW(Expr.GetPostfix());
}

TEST(ArExpression, no_throw_when_get_operands) {
	ArithmeticExpression Expr("-B + DLK * (-m)");
	ASSERT_NO_THROW(vector<string> operands = Expr.GetOperands());
}

TEST(ArExpression, can_get_operands) {
	ArithmeticExpression Expr("-B + DLK * (-m)");
	vector<string> operands = Expr.GetOperands();

	ASSERT_TRUE(operands.at(0) == "0");
	ASSERT_TRUE(operands.at(1) == "B");
	ASSERT_TRUE(operands.at(2) == "DLK");
}


TEST(ArExpression, quadruple_work) {
	ASSERT_NO_THROW(Quadruple(2,7));
}

TEST(ArExpression, quadruple_check_expected_value) {
	double result = Quadruple(2, 7);
	EXPECT_EQ(128, result);
}


TEST(ArExpression, no_throw_when_can_calculate_1) {
	ArithmeticExpression Expr("-5 + 4 * (-3)");
	vector<string> operands = Expr.GetOperands();
	map<string, double> values = Expr.SetOperands(operands);
	ASSERT_NO_THROW(double result = Expr.Calculate(values));
}

TEST(ArExpression, no_throw_when_can_calculate_3) {
	ArithmeticExpression Expr("8+2*43-10/5");
	vector<string> operands = Expr.GetOperands();
	map<string, double> values = Expr.SetOperands(operands);
	ASSERT_NO_THROW(double result = Expr.Calculate(values));
}

TEST(ArExpression, no_throw_when_can_calculate_4) {
	ArithmeticExpression Expr("9+2.2*43.3-10.33/5");
	vector<string> operands = Expr.GetOperands();
	map<string, double> values = Expr.SetOperands(operands);
	ASSERT_NO_THROW(double result = Expr.Calculate(values));
}

TEST(ArExpression, _can_calculate_3) {
	ArithmeticExpression Expr("3+2*43-10/5");
	vector<string> operands = Expr.GetOperands();
	map<string, double> values = Expr.SetOperands(operands);
	double result = Expr.Calculate(values);
	EXPECT_EQ(87, result);
}

TEST(ArExpression, can_calculate_4) {
	ArithmeticExpression Expr("6+2.0*43.5-10.5/5");
	vector<string> operands = Expr.GetOperands();
	map<string, double> values = Expr.SetOperands(operands);
	double result = Expr.Calculate(values);
	EXPECT_EQ(90.9, result);
}

TEST(ArExpression, _can_calculate_5_with_digree) {
	ArithmeticExpression Expr("3+2^4-10/5");
	vector<string> postfix = Expr.GetPostfix();
	vector<string> operands = Expr.GetOperands();
	map<string, double> values = Expr.SetOperands(operands);
	double result = Expr.Calculate(values);
	EXPECT_EQ(17, result);
}


TEST(ArExpression, unary_minus_start_expression) {
	ArithmeticExpression Expr("-5 + 4");
	vector<string> operands = Expr.GetOperands();
	map<string, double> values = Expr.SetOperands(operands);
	double unary = Expr.Calculate(values);
	EXPECT_EQ(unary, -1);
}

TEST(ArExpression, binary_minus) {
	ArithmeticExpression Expr("5 * 4 - 8");
	vector<string> operands = Expr.GetOperands();
	map<string, double> values = Expr.SetOperands(operands);
	double unary = Expr.Calculate(values);
	EXPECT_EQ(unary, 12);
}

TEST(ArExpression, division_by_zero) {
	ArithmeticExpression Expr("5 * 4/0 +(9*3-15)");
	vector<string> operands = Expr.GetOperands();
	map<string, double> values = Expr.SetOperands(operands);
	ASSERT_ANY_THROW(double unary = Expr.Calculate(values));
}


