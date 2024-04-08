#include "Monom.h"
#include "Polynom.h"
#include "ListHeader.h"
#include "RingList.h"

#include <gtest.h>

class TestEx : public TPolynom
{
public:

	using TPolynom::Is_Symbol;
	using TPolynom::isValidExpression;
	using TPolynom::isOperand;
	using TPolynom::operator=;
};


//Default
TEST(TPolynom, create_polynom)
{
	ASSERT_NO_THROW(TPolynom p);
}

//With string
TEST(TPolynom, create_polynom_with_string)
{
	string s = "2*x^4*y";
	ASSERT_NO_THROW(TPolynom p(s));
}
//With ringlist
TEST(TPolynom, create_polynom_with_ringlist)
{
	TMonom m(3, 564);
	TList<TMonom>* l = new TList<TMonom>();
	l->InsertEnd(m);
	TRingList<TMonom>* rl = new TRingList<TMonom>(*l);
	ASSERT_NO_THROW(TPolynom p(*rl));
}
//With polynom
TEST(TPolynom, create_polynom_with_polynom)
{
	TMonom m(3, 564);
	TList<TMonom>* l = new TList<TMonom>();
	l->InsertEnd(m);
	TRingList<TMonom>* rl = new TRingList<TMonom>(*l);
	TPolynom p(*rl);
	ASSERT_NO_THROW(TPolynom p2(p));
}

//Parsing
TEST(TPolynom, parsing_test)
{
	string s = "2*x^3*y*z";
	TPolynom p(s);
	TestEx p1;
	p1 = p;
	string n = p.ToString();
	EXPECT_EQ(s,n);
}
TEST(TPolynom, parsing_test_monom_error)
{
	string s = "2*X^3*y*z";
	
	ASSERT_ANY_THROW(TPolynom p(s));
}
TEST(TPolynom, parsing_test_error_letter_in_degree)
{
	string s = "2*x^a*y*z";

	ASSERT_ANY_THROW(TPolynom p(s));
}
TEST(TPolynom, parsing_test_error_symbol_in_degree)
{
	string s = "2*x^/*y*z";

	ASSERT_ANY_THROW(TPolynom p(s));
}
//operator =
TEST(TPolynom, assignment_test_degree)
{
	string s = "2*x^3*y*z";
	TPolynom p(s);
	TPolynom p2;
	p2 = p;
	string n1 = p.ToString();
	string n2 = p2.ToString();
	EXPECT_EQ(n1, n2);
}
//operator +
TEST(TPolynom, addition_test)
{
	string s = "2*x^3*y*z";
	string s2 = "4*x*y";
	TPolynom p(s);
	TPolynom p2(s2);
	TPolynom p3;
	string n1 = p.ToString();
	string n2 = p2.ToString();
	string add = s2 + "+" + s;
	p3 = p2 + p;
	string n3 = p3.ToString();
	EXPECT_EQ(add, n3);
}
TEST(TPolynom, addition_test_with_opposite_monomes)
{
	string s = "2*x^3*y*z-4*x*y";
	string s2 = "4*x*y";
	TPolynom p(s);
	TPolynom p2(s2);
	TPolynom p3;
	string n1 = p.ToString();
	string n2 = p2.ToString();
	string add = "2*x^3*y*z";
	p3 = p2 + p;
	string n3 = p3.ToString();
	EXPECT_EQ(add, n3);
}
TEST(TPolynom, addition_test_with_same_monomes)
{
	string s = "2*x^3*y*z+4*x*y";
	string s2 = "4*x*y";
	TPolynom p(s);
	TPolynom p2(s2);
	TPolynom p3;
	string add = "8*x*y+2*x^3*y*z";
	p3 = p2 + p;
	string n3 = p3.ToString();
	EXPECT_EQ(add, n3);
}

//Operator -
TEST(TPolynom, substraction_test)
{
	string s = "2*x^3*y*z";
	string s2 = "4*x*y";
	TPolynom p(s);
	TPolynom p2(s2);
	TPolynom p3;
	string sub = "4*x*y-2*x^3*y*z";
	p3 = p2 - p;
	string n3 = p3.ToString();
	EXPECT_EQ(sub, n3);
}
TEST(TPolynom, substraction_test_with_opposite_monomes)
{
	string s = "2*x^3*y*z+4*x*y";
	string s2 = "4*x*y";
	TPolynom p(s);
	TPolynom p2(s2);
	TPolynom p3;
	string sub = "-2*x^3*y*z";
	p3 = p2 - p;
	string n3 = p3.ToString();
	EXPECT_EQ(sub, n3);
}
TEST(TPolynom, substraction_test_with_same_monomes)
{
	string s = "2*x^3*y*z+4*x*y";
	string s2 = "-4*x*y";
	TPolynom p(s);
	TPolynom p2(s2);
	TPolynom p3;
	string sub = "-8*x*y-2*x^3*y*z";
	p3 = p2 - p;
	string n3 = p3.ToString();
	EXPECT_EQ(sub, n3);
}
//Operator *
TEST(TPolynom, multiplication_test)
{
	string s = "2*x^3*y*z-4*x*y";
	string s2 = "4*x*y-z";
	TPolynom p(s);
	TPolynom p2(s2);
	TPolynom p3;
	string mul = "4*x*y*z-16*x^2*y^2-2*x^3*y*z^2+8*x^4*y^2*z";
	p3 = p * p2;
	string n3 = p3.ToString();
	EXPECT_EQ(mul, n3);
}
//operatop-()
TEST(TPolynom, change_signs_test)
{
	string s = "2*x^3*y*z-4*x*y";
	TPolynom p(s);
	TPolynom p2;
	p2 = -p;
	string n2 = p2.ToString();
	string m = "4*x*y-2*x^3*y*z";
	EXPECT_EQ(m, n2);
}
//operator()
TEST(TPolynom, result_operator_test)
{
	string s = "2*x^3*y*z-4*x*y";
	TPolynom p(s);
	double res = p.operator()(2, 3, 4);
	EXPECT_EQ(168, res);
}
TEST(TPolynom, result_operator_test_addition)
{
	string s = "2*x^3*y*z-4*x*y";
	string s2 = "4*x*y";
	TPolynom p(s);
	TPolynom p2(s2);
	TPolynom p3;
	p3 = p + p2;
	double res = p3.operator()(2, 3, 4);
	EXPECT_EQ(192, res);
}
TEST(TPolynom, result_operator_test_diff)
{
	string s = "2*x^3*y^5*z-3*x^4*y+5*x";
	TPolynom p(s);
	TPolynom p2;
	p2 = p.difx();
	double res = p2.operator()(2, 3, 4);
	EXPECT_EQ(23045, res);
}
//dif_x
TEST(TPolynom, differentiation_x_degree)
{
	string s = "2*x^3*y*z";
	string dif_x = "6*x^2*y*z";
	TPolynom p(s);
	TPolynom p2;
	p2 = p.difx();
	string n = p2.ToString();
	EXPECT_EQ(dif_x, n);
}
//dif_y
TEST(TPolynom, differentiation_y_degree)
{
	string s = "2*x^3*y*z";
	string dif_y = "2*x^3*z";
	TPolynom p(s);
	TPolynom p2;
	p2 = p.dify();
	string n = p2.ToString();
	EXPECT_EQ(dif_y, n);
}
//dif_z
TEST(TPolynom, differentiation_z_degree)
{
	string s = "2*x^3*y*z^2";
	string dif_z = "4*x^3*y*z";
	TPolynom p(s);
	TPolynom p2;
	p2 = p.difz();
	string n = p2.ToString();
	EXPECT_EQ(dif_z, n);
}
//To_String
TEST(TPolynom, to_string_test)
{
	string s = "4*x*y+5*x^3*y";
	TPolynom p(s);
	string s2 = p.ToString();
	EXPECT_EQ(s, s2);
}
TEST(TPolynom, valid_expression_test_symbol_in_degree)
{
	TestEx ex;
	string s = "2*x^x";
	ASSERT_FALSE(ex.isValidExpression(s));
}
TEST(TPolynom, valid_expression_test_error_in_number)
{
	TestEx ex;
	string s = "2.*x^x";
	ASSERT_FALSE(ex.isValidExpression(s));
}
TEST(TPolynom, valid_expression_test_operand_in_degree)
{
	TestEx ex;
	string s = "2*x^*";
	ASSERT_FALSE(ex.isValidExpression(s));
}
TEST(TPolynom, valid_expression_test_true)
{
	TestEx ex;
	string s = "2*x^2*y-3*z";
	ASSERT_TRUE(ex.isValidExpression(s));
}
TEST(TPolynom, is_operand_true)
{
	TestEx ex;
	char s = 'x';
	ASSERT_TRUE(ex.isOperand(s));
}
TEST(TPolynom, is_operand_false)
{
	TestEx ex;
	char s = 'X';
	ASSERT_FALSE(ex.isOperand(s));
}
TEST(TPolynom, is_operand_false_any_symbol)
{
	TestEx ex;
	char s = 'a';
	ASSERT_FALSE(ex.isOperand(s));
}
TEST(TPolynom, is_symbol_true)
{
	TestEx ex;
	string s = "^";
	ASSERT_TRUE(ex.Is_Symbol(s));
}
