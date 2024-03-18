#include "Monom.h"
#include "ListHeader.h"
#include "RingList.h"

#include <gtest.h>
class TestEx : public TPolynom
{
public:
	using TPolynom::Is_Symbol;
	using TPolynom::isValidExpression;
	using TPolynom::isOperand;
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
	TPolynom p;
	p.Parse_Polynom(s);
	TMonom m = p.GetMonom()->GetCurrent()->data;
	int d = m.GetDegree();
	EXPECT_EQ(311, d);
}
TEST(TPolynom, parsing_test_monom_error)
{
	string s = "2*X^3*y*z";
	TPolynom p;
	ASSERT_ANY_THROW(p.Parse_Polynom(s));
}
TEST(TPolynom, parsing_test_error_letter_in_degree)
{
	string s = "2*x^a*y*z";
	TPolynom p;
	ASSERT_ANY_THROW(p.Parse_Polynom(s));
}
TEST(TPolynom, parsing_test_error_symbol_in_degree)
{
	string s = "2*x^/*y*z";
	TPolynom p;
	ASSERT_ANY_THROW(p.Parse_Polynom(s));
}
//operator =
TEST(TPolynom, assignment_test_degree)
{
	string s = "2*x^3*y*z";
	TPolynom p;
	TPolynom p2;
	p.Parse_Polynom(s);
	p2 = p;
	TMonom m = p2.GetMonom()->GetCurrent()->data;
	int d = m.GetDegree();
	EXPECT_EQ(311, d);
}
TEST(TPolynom, assignment_test_coef)
{
	string s = "2*x^3*y*z";
	TPolynom p;
	TPolynom p2;
	p.Parse_Polynom(s);
	p2 = p;
	TMonom m = p2.GetMonom()->GetCurrent()->data;
	EXPECT_EQ(2, m.GetCoef());
}
//operator +
TEST(TPolynom, addition_test)
{
	string s = "2*x^3*y*z";
	string s2 = "4*x*y";
	TPolynom p;
	TPolynom p2;
	TPolynom p3;
	p.Parse_Polynom(s);
	p2.Parse_Polynom(s2);
	p3 = p2 + p;
	EXPECT_EQ(2, p3.GetMonom()->GetSize());
}
TEST(TPolynom, addition_test_with_opposite_monomes)
{
	string s = "2*x^3*y*z-4*x*y";
	string s2 = "4*x*y";
	TPolynom p;
	TPolynom p2;
	TPolynom p3;
	p.Parse_Polynom(s);
	p2.Parse_Polynom(s2);
	p3 = p2 + p;
	EXPECT_EQ(1, p3.GetMonom()->GetSize());
}
TEST(TPolynom, addition_test_with_same_monomes)
{
	string s = "2*x^3*y*z+4*x*y";
	string s2 = "4*x*y";
	TPolynom p;
	TPolynom p2;
	TPolynom p3;
	p.Parse_Polynom(s);
	p2.Parse_Polynom(s2);
	p3 = p2 + p;
	TRingList<TMonom>* rl = p3.GetMonom();
	TMonom c = rl->GetCurrent()->data;
	EXPECT_EQ(8, c.GetCoef());
}
//Operator -
TEST(TPolynom, substraction_test)
{
	string s = "2*x^3*y*z";
	string s2 = "4*x*y";
	TPolynom p;
	TPolynom p2;
	TPolynom p3;
	p.Parse_Polynom(s);
	p2.Parse_Polynom(s2);
	p3 = p2 - p;
	EXPECT_EQ(2, p3.GetMonom()->GetSize());
}
TEST(TPolynom, substraction_test_with_opposite_monomes)
{
	string s = "2*x^3*y*z+4*x*y";
	string s2 = "4*x*y";
	TPolynom p;
	TPolynom p2;
	TPolynom p3;
	p.Parse_Polynom(s);
	p2.Parse_Polynom(s2);
	p3 = p2 - p;
	EXPECT_EQ(1, p3.GetMonom()->GetSize());
}
TEST(TPolynom, substraction_test_with_same_monomes)
{
	string s = "2*x^3*y*z-4*x*y";
	string s2 = "4*x*y";
	TPolynom p;
	TPolynom p2;
	TPolynom p3;
	p.Parse_Polynom(s);
	p2.Parse_Polynom(s2);
	p3 = p2 - p;
	TRingList<TMonom>* rl = p3.GetMonom();
	TMonom c = rl->GetCurrent()->data;
	EXPECT_EQ(8, c.GetCoef());
}
//Operator *
TEST(TPolynom, multiplication_test)
{
	string s = "2*x^3*y*z-4*x*y";
	string s2 = "4*x*y-z";
	TPolynom p;
	TPolynom p2;
	TPolynom p3;
	p.Parse_Polynom(s);
	p2.Parse_Polynom(s2);
	p3 = p * p2;
	TRingList<TMonom>* rl = p3.GetMonom();
	TMonom c = rl->GetCurrent()->data;
	EXPECT_EQ(4, p3.GetMonom()->GetSize());
}
TEST(TPolynom, multiplication_test_coef)
{
	string s = "2*x^3*y*z-4*x*y";
	string s2 = "4*x*y";
	TPolynom p;
	TPolynom p2;
	TPolynom p3;
	p.Parse_Polynom(s);
	p2.Parse_Polynom(s2);
	p3 = p * p2;
	TRingList<TMonom>* rl = p3.GetMonom();
	rl->Next();
	TMonom c = rl->GetCurrent()->data;
	EXPECT_EQ(8, c.GetCoef());
}
TEST(TPolynom, multiplication_test_degree)
{
	string s = "2*x^3*y*z-4*x*y";
	string s2 = "4*x*y";
	TPolynom p;
	TPolynom p2;
	TPolynom p3;
	p.Parse_Polynom(s);
	p2.Parse_Polynom(s2);
	p3 = p * p2;
	TRingList<TMonom>* rl = p3.GetMonom();
	rl->Next();
	TMonom c = rl->GetCurrent()->data;
	EXPECT_EQ(421, c.GetDegree());
}
//operator()
TEST(TPolynom, result_operator_test)
{
	string s = "2*x^3*y*z-4*x*y";
	TPolynom p(s);
	p.Parse_Polynom(s);
	double res = p.operator()(2, 3, 4);
	EXPECT_EQ(168, res);
}
TEST(TPolynom, result_operator_test_addition)
{
	string s = "2*x^3*y*z-4*x*y";
	string s2 = "4*x*y";
	TPolynom p;
	TPolynom p2;
	TPolynom p3;
	p.Parse_Polynom(s);
	p2.Parse_Polynom(s2);
	p3 = p + p2;
	double res = p3.operator()(2, 3, 4);
	EXPECT_EQ(192, res);
}
TEST(TPolynom, result_operator_test_diff)
{
	string s = "2*x^3*y^5*z-3*x^4*y+5*x";
	TPolynom p(s);
	TPolynom p2;
	p.Parse_Polynom(s);
	p2 = p.difx();
	double res = p2.operator()(2, 3, 4);
	EXPECT_EQ(23040, res);
}
//dif_x
TEST(TPolynom, differentiation_x_degree)
{
	string s = "2*x^3*y*z";
	TPolynom p;
	TPolynom p2;
	p.Parse_Polynom(s);
	p2 = p.difx();
	TMonom m = p2.GetMonom()->GetCurrent()->data;
	EXPECT_EQ(211, m.GetDegree());
}
TEST(TPolynom, differentiation_x_coef)
{
	string s = "2*x^3*y*z";
	TPolynom p;
	TPolynom p2;
	p.Parse_Polynom(s);
	p2 = p.difx();
	TMonom m = p2.GetMonom()->GetCurrent()->data;
	EXPECT_EQ(6, m.GetCoef());
}
//dif_y
TEST(TPolynom, differentiation_y_degree)
{
	string s = "2*x^3*y*z";
	TPolynom p;
	TPolynom p2;
	p.Parse_Polynom(s);
	p2 = p.dify();
	TMonom m = p2.GetMonom()->GetCurrent()->data;
	EXPECT_EQ(301, m.GetDegree());
}
TEST(TPolynom, differentiation_y_coef)
{
	string s = "2*x^3*y*z";
	TPolynom p;
	TPolynom p2;
	p.Parse_Polynom(s);
	p2 = p.dify();
	TMonom m = p2.GetMonom()->GetCurrent()->data;
	EXPECT_EQ(2, m.GetCoef());
}
//dif_z
TEST(TPolynom, differentiation_z_degree)
{
	string s = "2*x^3*y*z";
	TPolynom p;
	TPolynom p2;
	p.Parse_Polynom(s);
	p2 = p.difz();
	TMonom m = p2.GetMonom()->GetCurrent()->data;
	EXPECT_EQ(310, m.GetDegree());
}
TEST(TPolynom, differentiation_z_coef)
{
	string s = "2*x^3*y*z";
	TPolynom p;
	TPolynom p2;
	p.Parse_Polynom(s);
	p2 = p.difz();
	TMonom m = p2.GetMonom()->GetCurrent()->data;
	EXPECT_EQ(2, m.GetCoef());
}
//To_String
TEST(TPolynom, to_string_test)
{
	string s = "4.000000*x*y+5.000000*x^3*y";
	TPolynom p;
	p.Parse_Polynom(s);
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
