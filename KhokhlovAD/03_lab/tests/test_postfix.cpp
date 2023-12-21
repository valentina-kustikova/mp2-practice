#include <gtest.h> 
#include <cstring> 
#include <string> 
#include "postfix.h" 
#include "tstack.h"
class ParameterizedStringError : public ::testing::TestWithParam<char* >
{
protected:
	Arifmetics s;
public:
	ParameterizedStringError()
	{
		s.PushStroka(GetParam());
	}
	~ParameterizedStringError() {}
};
class Calculate {
private:
	char a[50];
	double b;
public:
	Calculate(char *v, double h) {
		strcpy(a, v);
		b = h;
	}
	Calculate(const Calculate& r) {
		strcpy(a, r.a);
		b = r.b;
	}

	char* string() {
		return a;
	}
	double Res() const { return b; }
};

class ParameterizedCalculate : public ::testing::TestWithParam <Calculate >
{
protected:
	Calculate w;
public:
	ParameterizedCalculate() : w(GetParam())
	{

	}
};


Calculate e0("(32-22)+5", 15);
Calculate e1("5-12", -7);
Calculate e2("(28.32-6.32)*(2)", 44);
Calculate e3("843-(32*32)-(32-3*6)", -195);
Calculate e4("(123-122)*(-2+4)", 2);
Calculate e5("1+2*3-(3-2)-1", 5);
Calculate e7("3-1+4-1-3+8+(12-6*2)-1+11", 20);
Calculate e[7] = { e0,e1,e2,e3,e4, e5,e7 };

TEST_P(ParameterizedCalculate, can_Calculete_True)
{
	Arifmetics s;
	Calculate x = GetParam();
	s.PushStroka(x.string());
	s.Lexem();
	s.Polsky();
	EXPECT_EQ(x.Res(), s.calculate());
}

INSTANTIATE_TEST_CASE_P(Instantiation3,
	ParameterizedCalculate,
	::testing::ValuesIn(e));

class ParameterizedStringTrue : public ParameterizedStringError
{
};

char a[] = "@74";
char b[] = "2++";
char z[] = "2--";
char k[] = "(4-32*(32-3)2-4";
char d[] = ")(";
char t[] = "23-32,32";
char y[] = "12.32-(32aw)";
char * c[] = { &a[0], &b[0], &z[0], &k[0],&d[0],&t[0],&y[0] };

TEST_P(ParameterizedStringError, can_determinate_eror)
{
	EXPECT_EQ(false, s.Check());
}

INSTANTIATE_TEST_CASE_P(Instantiation1,
	ParameterizedStringError,
	::testing::ValuesIn(c));

TEST_P(ParameterizedStringTrue, can_determinate_True)
{
	EXPECT_EQ(true, s.Check());
}
char a2[] = "(-re+32)";
char b2[] = "2+4*(-32+32)*(+32)";
char z2[] = "(32.32-43)*(+ew)";
char k2[] = "(4-32*32-3)*2-4";
char r2[] = "15/3+(7-2)/5";
char w2[] = "(a+32*4)*(-a+3)";
char q2[] = "23.32-32*3+awe";
char * c2[] = { &a2[0], &b2[0], &z2[0], &k2[0],&r2[0],&w2[0], &q2[0] };

INSTANTIATE_TEST_CASE_P(Instantiation2,
	ParameterizedStringTrue,
	::testing::ValuesIn(c2));


TEST(Lexems, Can_polish_check1)
{
	Arifmetics a;
	a.PushStroka("2+3*(3*1)");
	Lexems b[7];
	b[0].SetNumber(2);
	b[1].SetNumber(3);
	b[2].SetNumber(3);
	b[3].SetNumber(1);
	b[4].SetType(3);
	b[5].SetType(3);
	b[6].SetType(1);
	a.Check();
	a.Lexem();
	a.Polsky();
	EXPECT_EQ(b[0].GetNumber(), a.GetPolish()[0].GetNumber());
	EXPECT_EQ(b[1].GetNumber(), a.GetPolish()[1].GetNumber());
	EXPECT_EQ(b[2].GetNumber(), a.GetPolish()[2].GetNumber());
	EXPECT_EQ(b[3].GetNumber(), a.GetPolish()[3].GetNumber());
	EXPECT_EQ(b[4].GetType(), a.GetPolish()[4].GetType());
	EXPECT_EQ(b[5].GetType(), a.GetPolish()[5].GetType());
	EXPECT_EQ(b[6].GetType(), a.GetPolish()[6].GetType());
}

TEST(Lexems, Can_polish_check2)
{
	Arifmetics a;
	a.PushStroka("34*2-(32-34)*(21-4.4/3)");
	Lexems b[13];
	b[0].SetNumber(34);
	b[1].SetNumber(2);
	b[2].SetType(3);
	b[3].SetNumber(32);
	b[4].SetNumber(34);
	b[5].SetType(2);
	b[6].SetNumber(21);
	b[7].SetNumber(4.4);
	b[8].SetNumber(3);
	b[9].SetType(4);
	b[10].SetType(2);
	b[11].SetType(3);
	b[12].SetType(2);
	a.Check();
	a.Lexem();
	a.Polsky();
	EXPECT_EQ(b[0].GetNumber(), a.GetPolish()[0].GetNumber());
	EXPECT_EQ(b[1].GetNumber(), a.GetPolish()[1].GetNumber());
	EXPECT_EQ(b[2].GetType(), a.GetPolish()[2].GetType());
	EXPECT_EQ(b[3].GetNumber(), a.GetPolish()[3].GetNumber());
	EXPECT_EQ(b[4].GetNumber(), a.GetPolish()[4].GetNumber());
	EXPECT_EQ(b[5].GetType(), a.GetPolish()[5].GetType());
	EXPECT_EQ(b[6].GetNumber(), a.GetPolish()[6].GetNumber());
	EXPECT_EQ(b[7].GetNumber(), a.GetPolish()[7].GetNumber());
	EXPECT_EQ(b[8].GetNumber(), a.GetPolish()[8].GetNumber());
	EXPECT_EQ(b[9].GetType(), a.GetPolish()[9].GetType());
	EXPECT_EQ(b[10].GetType(), a.GetPolish()[10].GetType());
	EXPECT_EQ(b[11].GetType(), a.GetPolish()[11].GetType());
	EXPECT_EQ(b[12].GetType(), a.GetPolish()[12].GetType());
}