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
TEST(TPolynom, parsing_test_with_zero_coef)
{
	string s = "2*x^3*y*z+0*x*y";
	TPolynom p(s);
	string n = p.ToString();
	string n1 = "2*x^3*y*z";
	EXPECT_EQ(n1, n);
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
TEST(TPolynom, differentiation_x_degree_one)
{
	string s = "2*x*y*z";
	string dif_x = "2*y*z";
	TPolynom p(s);
	TPolynom p2;
	p2 = p.difx();
	string n = p2.ToString();
	EXPECT_EQ(dif_x, n);
}
TEST(TPolynom, differentiation_x_degree_zero)
{
	string s = "2*y*z";
	string dif_x = "0";
	TPolynom p(s);
	TPolynom p2;
	p2 = p.difx();
	string n = p2.ToString();
	EXPECT_EQ(dif_x, n);
}
//dif_y
TEST(TPolynom, differentiation_y_degree)
{
	string s = "2*x^3*y^4*z";
	string dif_y = "8*x^3*y^3*z";
	TPolynom p(s);
	TPolynom p2;
	p2 = p.dify();
	string n = p2.ToString();
	EXPECT_EQ(dif_y, n);
}
TEST(TPolynom, differentiation_y_degree_one)
{
	string s = "2*x^3*y*z";
	string dif_y = "2*x^3*z";
	TPolynom p(s);
	TPolynom p2;
	p2 = p.dify();
	string n = p2.ToString();
	EXPECT_EQ(dif_y, n);
}
TEST(TPolynom, differentiation_y_degree_zero)
{
	string s = "2*x^3*z";
	string dif_y = "0";
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
TEST(TPolynom, differentiation_z_degree_one)
{
	string s = "2*x^3*y*z";
	string dif_z = "2*x^3*y";
	TPolynom p(s);
	TPolynom p2;
	p2 = p.difz();
	string n = p2.ToString();
	EXPECT_EQ(dif_z, n);
}
TEST(TPolynom, differentiation_z_degree_zero)
{
	string s = "2*x^3*y";
	string dif_z = "0";
	TPolynom p(s);
	TPolynom p2;
	p2 = p.difz();
	string n = p2.ToString();
	EXPECT_EQ(dif_z, n);
}
//HandleX
TEST(TPolynom, handle_x_test_deg)
{
	TPolynom p;
	string deg = "";
	int i = 0;
	string str = "x^3";
	p.HandleX(str, i, deg);
	string deg_res = "300";
	EXPECT_EQ(deg_res, deg);
}
TEST(TPolynom, handle_x_test_mul)
{
	TPolynom p;
	string deg = "";
	int i = 0;
	string str = "x*";
	p.HandleX(str, i, deg);
	string deg_res = "100";
	EXPECT_EQ(deg_res, deg);
}
//HandleY
TEST(TPolynom, handle_y_test_deg)
{
	TPolynom p;
	string deg = "0";
	int i = 0;
	string str = "y^5";
	p.HandleY(str, i, deg);
	string deg_res = "50";
	EXPECT_EQ(deg_res, deg);
}
TEST(TPolynom, handle_y_test_mul)
{
	TPolynom p;
	string deg = "0";
	int i = 0;
	string str = "y*";
	p.HandleY(str, i, deg);
	string deg_res = "10";
	EXPECT_EQ(deg_res, deg);
}
//HandleZ
TEST(TPolynom, handle_z_test_deg)
{
	TPolynom p;
	string deg = "0";
	int i = 0;
	string str = "z^5";
	p.HandleZ(str, i, deg);
	string deg_res = "5";
	EXPECT_EQ(deg_res, deg);
}
TEST(TPolynom, handle_z_test_mul)
{
	TPolynom p;
	string deg = "0";
	int i = 0;
	string str = "z";
	p.HandleZ(str, i, deg);
	string deg_res = "1";
	EXPECT_EQ(deg_res, deg);
}
//CreateAndInsertMonom
TEST(TPolynom, insert_to_empty_list)
{
	TPolynom p;
	TRingList<TMonom>* monomList = new TRingList<TMonom>();
	int degree = 12;
	double coef = 2;
	p.CreateAndInsertMonom(coef, degree, monomList);
	TMonom m = monomList->GetCurrent()->data;
	int d = m.degree;
	EXPECT_EQ(d, degree);
}
TEST(TPolynom, insert_to_not_empty_list)
{
	TPolynom p;
	TRingList<TMonom>* monomList = new TRingList<TMonom>();
	TMonom mon(5, 3);
	monomList->InsertFirst(mon);
	int degree = 12;
	double coef = 2;
	p.CreateAndInsertMonom(coef, degree, monomList);
	monomList->Reset();
	monomList->Next();
	TMonom m = monomList->GetCurrent()->data;
	int d = m.degree;
	EXPECT_EQ(d, degree);
}
TEST(TPolynom, insert_to_not_empty_list_deg_less)
{
	TPolynom p;
	TRingList<TMonom>* monomList = new TRingList<TMonom>();
	TMonom mon(5, 15);
	monomList->InsertFirst(mon);
	int degree = 12;
	double coef = 2;
	p.CreateAndInsertMonom(coef, degree, monomList);
	monomList->Reset();
	TMonom m = monomList->GetCurrent()->data;
	int d = m.degree;
	EXPECT_EQ(d, degree);
}
//ProcessMonom
TEST(TPolynom, process_monom_test_flag)
{
	TPolynom p;
	TRingList<TMonom>* monomList = new TRingList<TMonom>();
	string s = "4*x*y-5*x^3*y";
	int i = 5;
	string numStr = "4";
	string deg = "110";
	int flag = 1;
	p.ProcessMonom(numStr, s, i, deg, flag, monomList);
	EXPECT_EQ(0, flag);
}
TEST(TPolynom, process_monom_test_coef)
{
	TPolynom p;
	TRingList<TMonom>* monomList = new TRingList<TMonom>();
	string s = "4*x*y-5*x^3*y";
	int i = 11;
	string numStr = "5";
	string deg = "310";
	int flag = 0;
	p.ProcessMonom(numStr, s, i, deg, flag, monomList);
	TMonom m = monomList->GetCurrent()->data;
	double k = m.coef;
	double k1 = -5.000000;
	EXPECT_EQ(k, k1);
}
//ProcessDegreeZero
TEST(TPolynom, process_degree_zero_empty_string)
{
	TPolynom p;
	string st = "";
	double k = 5.000000;
	string coef = "5";
	st = p.ProcessDegreeZero(st, coef, k);
	EXPECT_EQ(coef, st);
}
TEST(TPolynom, process_degree_zero_negative_coef)
{
	TPolynom p;
	string st = "2";
	double k = -5.000000;
	string coef = "-5";
	st = p.ProcessDegreeZero(st, coef, k);
	string st1 = "2-5";
	EXPECT_EQ(st1, st);
}
TEST(TPolynom, process_degree_zero_positive_coef)
{
	TPolynom p;
	string st = "2";
	double k = 5.000000;
	string coef = "5";
	st = p.ProcessDegreeZero(st, coef, k);
	string st1 = "2+5";
	EXPECT_EQ(st1, st);
}
//ProcessDegreeX
TEST(TPolynom, process_degree_x)
{
	TPolynom p;
	string st = "2";
	double k = 5.000000;
	string coef_str = "5";
	int flag = 0;
	int d = 300;
	st = p.ProcessDegreeX(st, coef_str, k, d, flag);
	string s1 = "2+5*x^3";
	EXPECT_EQ(s1, st);
}
TEST(TPolynom, process_degree_x_one)
{
	TPolynom p;
	string st = "2";
	double k = 5.000000;
	string coef_str = "5";
	int flag = 0;
	int d = 110;
	st = p.ProcessDegreeX(st, coef_str, k, d, flag);
	string s1 = "2+5*x";
	EXPECT_EQ(s1, st);
}
//ProcessDegreeY
TEST(TPolynom, process_degree_y)
{
	TPolynom p;
	string st = "2";
	double k = 5.000000;
	string coef_str = "5";
	int flag = 0;
	int d = 30;
	st = p.ProcessDegreeY(st, coef_str, k, d, flag);
	string s1 = "2+5*y^3";
	EXPECT_EQ(s1, st);
}
TEST(TPolynom, process_degree_y_one)
{
	TPolynom p;
	string st = "2";
	double k = 5.000000;
	string coef_str = "5";
	int flag = 0;
	int d = 10;
	st = p.ProcessDegreeY(st, coef_str, k, d, flag);
	string s1 = "2+5*y";
	EXPECT_EQ(s1, st);
}
//ProcessDegreeZ
TEST(TPolynom, process_degree_z)
{
	TPolynom p;
	string st = "2";
	double k = 5.000000;
	string coef_str = "5";
	int flag = 0;
	int d = 3;
	st = p.ProcessDegreeZ(st, coef_str, k, d, flag);
	string s1 = "2+5*z^3";
	EXPECT_EQ(s1, st);
}
TEST(TPolynom, process_degree_z_one)
{
	TPolynom p;
	string st = "2";
	double k = 5.000000;
	string coef_str = "5";
	int flag = 0;
	int d = 1;
	st = p.ProcessDegreeZ(st, coef_str, k, d, flag);
	string s1 = "2+5*z";
	EXPECT_EQ(s1, st);
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
