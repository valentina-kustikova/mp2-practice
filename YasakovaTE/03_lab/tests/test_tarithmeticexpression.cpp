#include <gtest.h>
#include <vector>
#include <map>

#include "tarithmeticexpression.h"


// Simple Arithmetic Expressions
TEST(TArithmeticExpression, SimpleAE_Constructor) {
	string str = "A+B*C-D/E";
	string expPostfix = "A B C * + D E / -";
	map<string, double> values = {
		{"A", 1},
		{"B", 2},
		{"C", 3},
		{"D", 4},
		{"E", 5},
	};
	double ans = 6.2;


	ASSERT_NO_THROW(TArithmeticExpression ae(str));
}

TEST(TArithmeticExpression, SimpleAE_Infix) {
	string str = "A+B*C-D/E";
	string expPostfix = "A B C * + D E / -";
	map<string, double> values = {
		{"A", 1},
		{"B", 2},
		{"C", 3},
		{"D", 4},
		{"E", 5},
	};
	double ans = 6.2;

	TArithmeticExpression ae(str);
	EXPECT_EQ(str, ae.GetInfix());
}

TEST(TArithmeticExpression, SimpleAE_Postfix) {
	string str = "A+B*C-D/E";
	string expPostfix = "A B C * + D E / -";
	vector<string> expvPostfix = { "A", "B", "C", "*", "+", "D", "E", "/", "-" };
	map<string, double> values = {
		{"A", 1},
		{"B", 2},
		{"C", 3},
		{"D", 4},
		{"E", 5},
	};
	double ans = 6.2;

	TArithmeticExpression ae(str);
	EXPECT_EQ(expvPostfix, ae.GetPostfix());
}

TEST(TArithmeticExpression, SimpleAE_StringPostfix) {
	string str = "A+B*C-D/E";
	string expPostfix = "A B C * + D E / -";
	map<string, double> values = {
		{"A", 1},
		{"B", 2},
		{"C", 3},
		{"D", 4},
		{"E", 5},
	};
	double ans = 6.2;

	TArithmeticExpression ae(str);
	EXPECT_EQ(expPostfix, ae.GetStringPostfix());
}

TEST(TArithmeticExpression, SimpleAE_Calculate) {
	string str = "A+B*C-D/E";
	string expPostfix = "A B C * + D E / -";
	map<string, double> values = {
		{"A", 1},
		{"B", 2},
		{"C", 3},
		{"D", 4},
		{"E", 5},
	};
	double ans = 6.2;

	TArithmeticExpression ae(str);
	EXPECT_EQ(ans, ae.Calculate(values));
}

TEST(TArithmeticExpression, SimpleAE_Brackets_AtBeginning_Infix) {
	string str = "(A+B)*C-D/E";
	string expPostfix = "A B + C * D E / -";
	map<string, double> values = {
		{"A", 1},
		{"B", 2},
		{"C", 3},
		{"D", 4},
		{"E", 5},
	};
	double ans = 8.2;

	TArithmeticExpression ae(str);
	EXPECT_EQ(str, ae.GetInfix());
}

TEST(TArithmeticExpression, SimpleAE_Brackets_AtBeginning_StringPostfix) {
	string str = "(A+B)*C-D/E";
	string expPostfix = "A B + C * D E / -";
	map<string, double> values = {
		{"A", 1},
		{"B", 2},
		{"C", 3},
		{"D", 4},
		{"E", 5},
	};
	double ans = 8.2;

	TArithmeticExpression ae(str);
	EXPECT_EQ(expPostfix, ae.GetStringPostfix());
}

TEST(TArithmeticExpression, SimpleAE_Brackets_AtBeginning_Calculate) {
	string str = "(A+B)*C-D/E";
	string expPostfix = "A B + C * D E / -";
	map<string, double> values = {
		{"A", 1},
		{"B", 2},
		{"C", 3},
		{"D", 4},
		{"E", 5},
	};
	double ans = 8.2;

	TArithmeticExpression ae(str);
	EXPECT_EQ(ans, ae.Calculate(values));
}

TEST(TArithmeticExpression, SimpleAE_Brackets_AtEnd_Infix) {
	string str = "A+B*(C-D)";
	string expPostfix = "A B C D - * +";
	map<string, double> values = {
		{"A", 1},
		{"B", 2},
		{"C", 3},
		{"D", 4},
	};
	double ans = -1;

	TArithmeticExpression ae(str);
	EXPECT_EQ(str, ae.GetInfix());
}

TEST(TArithmeticExpression, SimpleAE_Brackets_AtEnd_StringPostfix) {
	string str = "A+B*(C-D)";
	string expPostfix = "A B C D - * +";
	map<string, double> values = {
		{"A", 1},
		{"B", 2},
		{"C", 3},
		{"D", 4},
	};
	double ans = -1;

	TArithmeticExpression ae(str);
	EXPECT_EQ(expPostfix, ae.GetStringPostfix());
}

TEST(TArithmeticExpression, SimpleAE_Brackets_AtEnd_Calculate) {
	string str = "A+B*(C-D)";
	string expPostfix = "A B C D - * +";
	map<string, double> values = {
		{"A", 1},
		{"B", 2},
		{"C", 3},
		{"D", 4},
	};
	double ans = -1;

	TArithmeticExpression ae(str);
	EXPECT_EQ(ans, ae.Calculate(values));
}

TEST(TArithmeticExpression, SimpleAE_Brackets_AtMiddle_Infix) {
	string str = "A+B*(C-D)/E";
	string expPostfix = "A B C D - * E / +";
	map<string, double> values = {
		{"A", 1},
		{"B", 2},
		{"C", 3},
		{"D", 4},
		{"E", 5},
	};
	double ans = 0.6;

	TArithmeticExpression ae(str);
	EXPECT_EQ(str, ae.GetInfix());
}

TEST(TArithmeticExpression, SimpleAE_Brackets_AtMiddle_StringPostfix) {
	string str = "A+B*(C-D)/E";
	string expPostfix = "A B C D - * E / +";
	map<string, double> values = {
		{"A", 1},
		{"B", 2},
		{"C", 3},
		{"D", 4},
		{"E", 5},
	};
	double ans = 0.6;

	TArithmeticExpression ae(str);
	EXPECT_EQ(expPostfix, ae.GetStringPostfix());
}

TEST(TArithmeticExpression, SimpleAE_Brackets_AtMiddle_Calculate) {
	string str = "A+B*(C-D)/E";
	string expPostfix = "A B C D - * E / +";
	map<string, double> values = {
		{"A", 1},
		{"B", 2},
		{"C", 3},
		{"D", 4},
		{"E", 5},
	};
	double ans = 0.6;

	TArithmeticExpression ae(str);
	EXPECT_EQ(ans, ae.Calculate(values));
}

TEST(TArithmeticExpression, SimpleAE_Brackets_InBrackets_Infix) {
	string str = "(A+B*(C-D))/E";
	string expPostfix = "A B C D - * + E /";
	map<string, double> values = {
		{"A", 1},
		{"B", 2},
		{"C", 3},
		{"D", 4},
		{"E", 5},
	};
	double ans = -0.2;

	TArithmeticExpression ae(str);
	EXPECT_EQ(str, ae.GetInfix());
}

TEST(TArithmeticExpression, SimpleAE_Brackets_InBrackets_StringPostfix) {
	string str = "(A+B*(C-D))/E";
	string expPostfix = "A B C D - * + E /";
	map<string, double> values = {
		{"A", 1},
		{"B", 2},
		{"C", 3},
		{"D", 4},
		{"E", 5},
	};
	double ans = -0.2;

	TArithmeticExpression ae(str);
	EXPECT_EQ(expPostfix, ae.GetStringPostfix());
}

TEST(TArithmeticExpression, SimpleAE_Brackets_InBrackets_Calculate) {
	string str = "(A+B*(C-D))/E";
	string expPostfix = "A B C D - * + E /";
	map<string, double> values = {
		{"A", 1},
		{"B", 2},
		{"C", 3},
		{"D", 4},
		{"E", 5},
	};
	double ans = -0.2;

	TArithmeticExpression ae(str);
	EXPECT_EQ(ans, ae.Calculate(values));
}



// Arithmetic Expressions with long operands, consts, fractional constants
//// LONG OPERANDS //// 
TEST(TArithmeticExpression, LongOperandAE_Constructor) {
	string str = "Axy+B*C-Dd/E";
	string expPostfix = "Axy B C * + Dd E / -";
	map<string, double> values = {
		{"Axy", 1},
		{"B", 2},
		{"C", 3},
		{"Dd", 4},
		{"E", 5},
	};
	double ans = 6.2;


	ASSERT_NO_THROW(TArithmeticExpression ae(str));
}

TEST(TArithmeticExpression, LongOperandAE_Infix) {
	string str = "Axy+B*C-Dd/E";
	string expPostfix = "Axy B C * + Dd E / -";
	map<string, double> values = {
		{"Axy", 1},
		{"B", 2},
		{"C", 3},
		{"Dd", 4},
		{"E", 5},
	};
	double ans = 6.2;

	TArithmeticExpression ae(str);
	EXPECT_EQ(str, ae.GetInfix());
}

TEST(TArithmeticExpression, LongOperandAE_Postfix) {
	string str = "Axy+B*C-Dd/E";
	string expPostfix = "Axy B C * + Dd E / -";
	vector<string> expvPostfix = { "Axy", "B", "C", "*", "+", "Dd", "E", "/", "-" };
	map<string, double> values = {
		{"Axy", 1},
		{"B", 2},
		{"C", 3},
		{"Dd", 4},
		{"E", 5},
	};
	double ans = 6.2;

	TArithmeticExpression ae(str);
	EXPECT_EQ(expvPostfix, ae.GetPostfix());
}

TEST(TArithmeticExpression, LongOperandAE_StringPostfix) {
	string str = "Axy+B*C-Dd/E";
	string expPostfix = "Axy B C * + Dd E / -";
	map<string, double> values = {
		{"Axy", 1},
		{"B", 2},
		{"C", 3},
		{"Dd", 4},
		{"E", 5},
	};
	double ans = 6.2;

	TArithmeticExpression ae(str);
	EXPECT_EQ(expPostfix, ae.GetStringPostfix());
}

TEST(TArithmeticExpression, LongOperandAE_Calculate) {
	string str = "Axy+B*C-Dd/E";
	string expPostfix = "Axy B C * + Dd E / -";
	map<string, double> values = {
		{"Axy", 1},
		{"B", 2},
		{"C", 3},
		{"Dd", 4},
		{"E", 5},
	};
	double ans = 6.2;

	TArithmeticExpression ae(str);
	EXPECT_EQ(ans, ae.Calculate(values));
}

TEST(TArithmeticExpression, LongOperandAE_Brackets_AtBeginning_Infix) {
	string str = "(Axy+B)*C-Dd/E";
	string expPostfix = "Axy B + C * Dd E / -";
	map<string, double> values = {
		{"Axy", 1},
		{"B", 2},
		{"C", 3},
		{"Dd", 4},
		{"E", 5},
	};
	double ans = 8.2;

	TArithmeticExpression ae(str);
	EXPECT_EQ(str, ae.GetInfix());
}

TEST(TArithmeticExpression, LongOperandAE_Brackets_AtBeginning_StringPostfix) {
	string str = "(Axy+B)*C-Dd/E";
	string expPostfix = "Axy B + C * Dd E / -";
	map<string, double> values = {
		{"Axy", 1},
		{"B", 2},
		{"C", 3},
		{"Dd", 4},
		{"E", 5},
	};
	double ans = 8.2;

	TArithmeticExpression ae(str);
	EXPECT_EQ(expPostfix, ae.GetStringPostfix());
}

TEST(TArithmeticExpression, LongOperandAE_Brackets_AtBeginning_Calculate) {
	string str = "(Axy+B)*C-Dd/E";
	string expPostfix = "Axy B + C * Dd E / -";
	map<string, double> values = {
		{"Axy", 1},
		{"B", 2},
		{"C", 3},
		{"Dd", 4},
		{"E", 5},
	};
	double ans = 8.2;

	TArithmeticExpression ae(str);
	EXPECT_EQ(ans, ae.Calculate(values));
}

TEST(TArithmeticExpression, LongOperandAE_Brackets_AtEnd_Infix) {
	string str = "Axy+B*(C-Dd)";
	string expPostfix = "Axy B C Dd - * +";
	map<string, double> values = {
		{"Axy", 1},
		{"B", 2},
		{"C", 3},
		{"Dd", 4},
	};
	double ans = -1;

	TArithmeticExpression ae(str);
	EXPECT_EQ(str, ae.GetInfix());
}

TEST(TArithmeticExpression, LongOperandAE_Brackets_AtEnd_StringPostfix) {
	string str = "Axy+B*(C-Dd)";
	string expPostfix = "Axy B C Dd - * +";
	map<string, double> values = {
		{"Axy", 1},
		{"B", 2},
		{"C", 3},
		{"Dd", 4},
	};
	double ans = -1;

	TArithmeticExpression ae(str);
	EXPECT_EQ(expPostfix, ae.GetStringPostfix());
}

TEST(TArithmeticExpression, LongOperandAE_Brackets_AtEnd_Calculate) {
	string str = "Axy+B*(C-Dd)";
	string expPostfix = "Axy B C Dd - * +";
	map<string, double> values = {
		{"Axy", 1},
		{"B", 2},
		{"C", 3},
		{"Dd", 4},
	};
	double ans = -1;

	TArithmeticExpression ae(str);
	EXPECT_EQ(ans, ae.Calculate(values));
}

TEST(TArithmeticExpression, LongOperandAE_Brackets_AtMiddle_Infix) {
	string str = "Axy+B*(C-Dd)/E";
	string expPostfix = "Axy B C Dd - * E / +";
	map<string, double> values = {
		{"Axy", 1},
		{"B", 2},
		{"C", 3},
		{"Dd", 4},
		{"E", 5},
	};
	double ans = 0.6;

	TArithmeticExpression ae(str);
	EXPECT_EQ(str, ae.GetInfix());
}

TEST(TArithmeticExpression, LongOperandAE_Brackets_AtMiddle_StringPostfix) {
	string str = "Axy+B*(C-Dd)/E";
	string expPostfix = "Axy B C Dd - * E / +";
	map<string, double> values = {
		{"Axy", 1},
		{"B", 2},
		{"C", 3},
		{"Dd", 4},
		{"E", 5},
	};
	double ans = 0.6;

	TArithmeticExpression ae(str);
	EXPECT_EQ(expPostfix, ae.GetStringPostfix());
}

TEST(TArithmeticExpression, LongOperandAE_Brackets_AtMiddle_Calculate) {
	string str = "Axy+B*(C-Dd)/E";
	string expPostfix = "Axy B C Dd - * E / +";
	map<string, double> values = {
		{"Axy", 1},
		{"B", 2},
		{"C", 3},
		{"Dd", 4},
		{"E", 5},
	};
	double ans = 0.6;

	TArithmeticExpression ae(str);
	EXPECT_EQ(ans, ae.Calculate(values));
}

TEST(TArithmeticExpression, LongOperandAE_Brackets_InBrackets_Infix) {
	string str = "(Axy+B*(C-Dd))/E";
	string expPostfix = "Axy B C Dd - * + E /";
	map<string, double> values = {
		{"Axy", 1},
		{"B", 2},
		{"C", 3},
		{"Dd", 4},
		{"E", 5},
	};
	double ans = -0.2;

	TArithmeticExpression ae(str);
	EXPECT_EQ(str, ae.GetInfix());
}

TEST(TArithmeticExpression, LongOperandAE_Brackets_InBrackets_StringPostfix) {
	string str = "(Axy+B*(C-Dd))/E";
	string expPostfix = "Axy B C Dd - * + E /";
	map<string, double> values = {
		{"Axy", 1},
		{"B", 2},
		{"C", 3},
		{"Dd", 4},
		{"E", 5},
	};
	double ans = -0.2;

	TArithmeticExpression ae(str);
	EXPECT_EQ(expPostfix, ae.GetStringPostfix());
}

TEST(TArithmeticExpression, LongOperandAE_Brackets_InBrackets_Calculate) {
	string str = "(Axy+B*(C-Dd))/E";
	string expPostfix = "Axy B C Dd - * + E /";
	map<string, double> values = {
		{"Axy", 1},
		{"B", 2},
		{"C", 3},
		{"Dd", 4},
		{"E", 5},
	};
	double ans = -0.2;

	TArithmeticExpression ae(str);
	EXPECT_EQ(ans, ae.Calculate(values));
}


//// CONSTS ////
TEST(TArithmeticExpression, ConstAE_Constructor) {
	string str = "A+2*43-10/5";
	string expPostfix = "A 2 43 * + 10 5 / -";
	map<string, double> values = {
		{"A", 1},
	};
	double ans = 85;


	ASSERT_NO_THROW(TArithmeticExpression ae(str));
}

TEST(TArithmeticExpression, ConstAE_Infix) {
	string str = "A+2*43-10/5";
	string expPostfix = "A 2 43 * + 10 5 / -";
	map<string, double> values = {
		{"A", 1},
	};
	double ans = 85;

	TArithmeticExpression ae(str);
	EXPECT_EQ(str, ae.GetInfix());
}

TEST(TArithmeticExpression, ConstAE_Postfix) {
	string str = "A+2*43-10/5";
	string expPostfix = "A 2 43 * + 10 5 / -";
	vector<string> expvPostfix = { "A", "2", "43", "*", "+", "10", "5", "/", "-" };
	map<string, double> values = {
		{"A", 1},
	};
	double ans = 85;

	TArithmeticExpression ae(str);
	EXPECT_EQ(expvPostfix, ae.GetPostfix());
}

TEST(TArithmeticExpression, ConstAE_StringPostfix) {
	string str = "A+2*43-10/5";
	string expPostfix = "A 2 43 * + 10 5 / -";
	map<string, double> values = {
		{"A", 1},
	};
	double ans = 85;

	TArithmeticExpression ae(str);
	EXPECT_EQ(expPostfix, ae.GetStringPostfix());
}

TEST(TArithmeticExpression, ConstAE_Calculate) {
	string str = "A+2*43-10/5";
	string expPostfix = "A 2 43 * + 10 5 / -";
	map<string, double> values = {
		{"A", 1},
	};
	double ans = 85;

	TArithmeticExpression ae(str);
	EXPECT_EQ(ans, ae.Calculate(values));
}


//// FRACTIONAL CONSTS ////
TEST(TArithmeticExpression, FractionalConstAE_Infix) {
	string str = "A+2.2*43.3-10.33/5";
	string expPostfix = "A 2.2 43.3 * + 10.33 5 / -";
	map<string, double> values = {
		{"A", 1},
	};
	double ans = 94.194;

	TArithmeticExpression ae(str);
	EXPECT_EQ(str, ae.GetInfix());
}

TEST(TArithmeticExpression, FractionalConstAE_Postfix) {
	string str = "A+2.2*43.3-10.33/5";
	string expPostfix = "A 2.2 43.3 * + 10.33 5 / -";
	vector<string> expvPostfix = { "A", "2.2", "43.3", "*", "+", "10.33", "5", "/", "-" };
	map<string, double> values = {
		{"A", 1},
	};
	double ans = 94.194;

	TArithmeticExpression ae(str);
	EXPECT_EQ(expvPostfix, ae.GetPostfix());
}

TEST(TArithmeticExpression, FractionalConstAE_StringPostfix) {
	string str = "A+2.2*43.3-10.33/5";
	string expPostfix = "A 2.2 43.3 * + 10.33 5 / -";
	map<string, double> values = {
		{"A", 1},
	};
	double ans = 94.194;

	TArithmeticExpression ae(str);
	EXPECT_EQ(expPostfix, ae.GetStringPostfix());
}

TEST(TArithmeticExpression, FractionalConstAE_Calculate) {
	string str = "A+2.2*43.3-10.33/5";
	string expPostfix = "A 2.2 43.3 * + 10.33 5 / -";
	map<string, double> values = {
		{"A", 1},
	};
	double ans = 94.194;

	TArithmeticExpression ae(str);
	EXPECT_EQ(ans, ae.Calculate(values));
}


//// ANOTHER TESTS ////
TEST(TArithmeticExpression, ConvertingAE_Infix) {
	string str = "-3 + .5 (A -B)(-C- D)+ (E-F/G)2(A + B)3 +3.";
	string expstr = "0-3+0.5*(A-B)*(0-C-D)+(E-F/G)*2*(A+B)*3+3.0";
	string expPostfix = "0 3 - 0.5 A B - * 0 C - D - * + E F G / - 2 * A B + * 3 * + 3.0 +";

	TArithmeticExpression ae(str);
	EXPECT_EQ(expstr, ae.GetInfix());
}

TEST(TArithmeticExpression, ConvertingAE_StringPrefix) {
	string str = "-3 + .5 (A -B)(-C- D)+ (E-F/G)2(A + B)3 +3.";
	string expstr = "0-3+0.5*(A-B)*(0-C-D)+(E-F/G)*2*(A+B)*3+3.0";
	string expPostfix = "0 3 - 0.5 A B - * 0 C - D - * + E F G / - 2 * A B + * 3 * + 3.0 +";

	TArithmeticExpression ae(str);
	EXPECT_EQ(expPostfix, ae.GetStringPostfix());
}

TEST(TArithmeticExpression, ConvertingAE_Calculate) {
	string str = "-3 + .5 (A -B)(-C- D)+ (E-F/G)2(A + B)3 +3.";
	string expstr = "0-3+0.5*(A-B)*(0-C-D)+(E-F/G)*2*(A+B)*3+3.0";
	string expPostfix = "0 3 - 0.5 A B - * 0 C - D - * + E F G / - 2 * A B + * 3 * + 3.0 +";
	map<string, double> values = {
		{"A", 1},
		{"B", 2},
		{"C", 3},
		{"D", 4},
		{"E", 5},
		{"F", 6},
		{"G", 2},
	};
	double ans = 39.5;

	TArithmeticExpression ae(str);
	EXPECT_EQ(ans, ae.Calculate(values));
}


//// INCORRECT ////
// string str = "A+B*C-D/E";
TEST(TArithmeticExpression, throw_IncorrectAE_TooManyOpeningBrackets) {
	string str = "(A+B)*C(-D/E";

	ASSERT_ANY_THROW(TArithmeticExpression ae(str));
}

TEST(TArithmeticExpression, throw_IncorrectAE_TooManyClosingBrackets) {
	string str = "(A+B)*C-D/E)";

	ASSERT_ANY_THROW(TArithmeticExpression ae(str));
}

TEST(TArithmeticExpression, throw_IncorrectAE_EmptyBrackets) {
	string str = "A+B+()*C-D/E";

	ASSERT_ANY_THROW(TArithmeticExpression ae(str));
}

TEST(TArithmeticExpression, throw_IncorrectAE_IncorrectOperators_TwoOperators) {
	string str = "A+B+*C-D/E";

	ASSERT_ANY_THROW(TArithmeticExpression ae(str));
}

TEST(TArithmeticExpression, throw_IncorrectAE_IncorrectOperators_OperatorAndClosingBracket) {
	string str = "A+B*(C-)-D/E";

	ASSERT_ANY_THROW(TArithmeticExpression ae(str));
}

TEST(TArithmeticExpression, throw_IncorrectAE_IncorrectOperators_OperatorAndOpenningBracket) {
	string str = "A+B*(+C)-D/E";

	ASSERT_ANY_THROW(TArithmeticExpression ae(str));
}

TEST(TArithmeticExpression, throw_IncorrectAE_TooManyOpeningDotsInConst_TwoInARow) {
	string str = "A+12..34+B";

	ASSERT_ANY_THROW(TArithmeticExpression ae(str));
}

TEST(TArithmeticExpression, throw_IncorrectAE_TooManyOpeningDotsInConst_Scattered) {
	string str = "A+12.3.4+B";

	ASSERT_ANY_THROW(TArithmeticExpression ae(str));
}

TEST(TArithmeticExpression, throw_IncorrectAE_DivisionByZero) {
	string str = "A/B";
	map<string, double> values = {
		{"A", 1},
		{"B", 0},
	};
	TArithmeticExpression ae(str);

	ASSERT_ANY_THROW(ae.Calculate(values));
}

/*
TEST(TArithmeticExpression, ArithmeticExpression1) {
	string str = "A+B*C";
	string expPostfix = "A B C * +";

	ASSERT_NO_THROW(TArithmeticExpression ae(str));

	TArithmeticExpression ae(str);
	EXPECT_EQ(expPostfix, ae.GetStringPostfix());
}

TEST(TArithmeticExpression, ArithmeticExpression2) {
	string str = "D/(E-F)";
	string expPostfix = "D E F - /";

	ASSERT_NO_THROW(TArithmeticExpression ae(str));

	TArithmeticExpression ae(str);
	EXPECT_EQ(expPostfix, ae.GetStringPostfix());
}

TEST(TArithmeticExpression, ArithmeticExpression3) {
	string str = "(G+H)*I-J";
	string expPostfix = "G H + I * J -";

	ASSERT_NO_THROW(TArithmeticExpression ae(str));

	TArithmeticExpression ae(str);
	EXPECT_EQ(expPostfix, ae.GetStringPostfix());
}

TEST(TArithmeticExpression, ArithmeticExpression4) {
	string str = "K*L/(M+N)";
	string expPostfix = "K L * M N + /";

	ASSERT_NO_THROW(TArithmeticExpression ae(str));

	TArithmeticExpression ae(str);
	EXPECT_EQ(expPostfix, ae.GetStringPostfix());
}

TEST(TArithmeticExpression, ArithmeticExpression5) {
	string str = "(O-P)*Q/R+S";
	string expPostfix = "O P - Q * R / S +";

	ASSERT_NO_THROW(TArithmeticExpression ae(str));

	TArithmeticExpression ae(str);
	EXPECT_EQ(expPostfix, ae.GetStringPostfix());
}

TEST(TArithmeticExpression, ArithmeticExpression6) {
	string str = "T*(U+V)-W/X";
	string expPostfix = "T U V + * W X / -";

	ASSERT_NO_THROW(TArithmeticExpression ae(str));

	TArithmeticExpression ae(str);
	EXPECT_EQ(expPostfix, ae.GetStringPostfix());
}

TEST(TArithmeticExpression, ArithmeticExpression7) {
	string str = "Y/Z-(A+B)*C";
	string expPostfix = "Y Z / A B + C * -";

	ASSERT_NO_THROW(TArithmeticExpression ae(str));

	TArithmeticExpression ae(str);
	EXPECT_EQ(expPostfix, ae.GetStringPostfix());
}

TEST(TArithmeticExpression, ArithmeticExpression8) {
	string str = "D+(E*F)/G-H";
	string expPostfix = "D E F * G / + H -";

	ASSERT_NO_THROW(TArithmeticExpression ae(str));

	TArithmeticExpression ae(str);
	EXPECT_EQ(expPostfix, ae.GetStringPostfix());
}

TEST(TArithmeticExpression, ArithmeticExpression9) {
	string str = "I*(J-K/L)+M";
	string expPostfix = "I J K L / - * M +";

	ASSERT_NO_THROW(TArithmeticExpression ae(str));

	TArithmeticExpression ae(str);
	EXPECT_EQ(expPostfix, ae.GetStringPostfix());
}

TEST(TArithmeticExpression, ArithmeticExpression10) {
	string str = "N/(O+P)-Q*R+S";
	string expPostfix = "N O P + / Q R * - S +";

	ASSERT_NO_THROW(TArithmeticExpression ae(str));

	TArithmeticExpression ae(str);
	EXPECT_EQ(expPostfix, ae.GetStringPostfix());
}
*/
