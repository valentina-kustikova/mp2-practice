#include <gtest.h>
#include "polinom.h"

TEST(monom, test_m_0)
{
	ASSERT_NO_THROW(monom p);
}
TEST(monom, test_m_1)
{
	monom m;
	EXPECT_EQ(0.0, m.coeff);
	EXPECT_EQ(0, m.xyz);
}

TEST(monom, test_m_2)
{
	monom m(5.3, 111);
	EXPECT_EQ(5.3, m.coeff);
	EXPECT_EQ(111, m.xyz);
}

TEST(monom, test_m_3)
{
	monom m(5.2, 111);
	monom n(m);
	EXPECT_EQ(m, n);
}

TEST(monom, test_m_4)
{
	monom m(5.6, 111);
	monom n;
	n = m;
	EXPECT_EQ(m, n);
}

TEST(monom, test_m_5)
{
	string s = "xyz";
	monom m(s);
	EXPECT_EQ(1.0, m.coeff);
	EXPECT_EQ(111, m.xyz);
}

TEST(monom, test_m_6)
{
	monom m(5.6, 111);
	monom n(5.6, 111);
	EXPECT_EQ(true, m == n);
}

TEST(monom, test_m_7)
{
	monom m(5.6, 111);
	monom n(5.6, 112);
	EXPECT_EQ(true, m != n);
}

TEST(monom, test_m_8)
{
	monom m(5.6, 111);
	monom n(5.6, 211);
	EXPECT_EQ(true, m < n);
}

TEST(monom, test_m_9)
{
	monom m(5.6, 311);
	monom n(5.6, 111);
	EXPECT_EQ(true, m > n);
}

TEST(monom, test_m_10)
{
	monom m(5.6, 111);
	double d = 10.0;
	m = m * d;
	EXPECT_EQ(56.0, m.coeff);
}

TEST(monom, test_m_11)
{
	monom m(5.6, 111);
	monom n(10.0, 111);
	m = m * n;
	EXPECT_EQ(56.0, m.coeff);
	EXPECT_EQ(222, m.xyz);
}

TEST(polinom, test_p_1)
{
	ASSERT_NO_THROW(polinom p);
}
TEST(polinom, test_p_2)
{
	polinom p("x+y");
	ASSERT_NO_THROW(polinom p1(p));
}

TEST(polinom, test_p_3)
{
	ASSERT_NO_THROW(polinom p("x+y"));
}

TEST(polinom, test_p_4)
{
	polinom p("x+y");
	polinom p1(p);
	EXPECT_EQ(p, p1);
}

TEST(polinom, test_p_5)
{
	polinom p("x+y");
	polinom p1;
	p1 = p;
	EXPECT_EQ(p, p1);
}

TEST(polinom, test_p_6)
{
	polinom p("x+y");
	polinom p1("x+y");
	EXPECT_EQ(true, p == p1);
}

TEST(polinom, test_p_7)
{
	polinom p("x+y");
	polinom p1("x");
	EXPECT_EQ(true, p != p1);
}

TEST(polinom, test_p_8)
{
	polinom p("x+y");
	polinom p1("x");
	polinom p2("2x+y");
	EXPECT_EQ(p2, p + p1);
}

TEST(polinom, test_p_9)
{
	polinom p("x+y");
	polinom p1("x");
	polinom p2("x2+xy");
	EXPECT_EQ(p2, p * p1);
}

TEST(polinom, test_p_10)
{
	polinom p("x+y");
	double d = 2.2;
	polinom p1("2.2x+2.2y");
	EXPECT_EQ(p1, p * d);
}

TEST(polinom, test_p_11)
{
	polinom p("x+y");
	double d = 2.2;
	polinom p1("2.2x+2.2y");
	EXPECT_EQ(p1, d * p);
}

TEST(polinom, test_p_12)
{
	polinom p("x+y");
	polinom p1("x");
	polinom p2("y");
	EXPECT_EQ(p2, p - p1);
}

string t[8] = { "xyz", "x2z+y", "z+x3", "y4x5z6+z2y5", "x+y+x-z", "x+y", "x9-y8-z7", "x3y5+x6x9-y4" };

class ParPolinom : public ::testing::TestWithParam<string>
{
protected:
	string s;
public:
	ParPolinom() { s = GetParam(); }
	~ParPolinom() {}
};

TEST_P(ParPolinom, test_p_13)
{
	polinom p(s);
	polinom m;
	EXPECT_EQ(m, p - p);
}
INSTANTIATE_TEST_CASE_P(i1, ParPolinom, ::testing::ValuesIn(t));

TEST(polinom, test_p_14)
{
	polinom p("x+1");
	polinom p1("x-1");
	polinom p2("x2-1");
	EXPECT_EQ(p2, p * p1);
}

TEST(polinom, test_p_15)
{
	polinom p("x+1");
	polinom p1("x+1");
	polinom p2("x2+2x+1");
	EXPECT_EQ(p2, p * p1);
}

TEST(polinom, test_p_16)
{
	polinom p("x+z");
	polinom p1("x-y");
	polinom p2("x2-xy+xz-yz");
	EXPECT_EQ(p2, p * p1);
}

TEST(polinom, test_p_17)
{
	polinom p("x+1");
	polinom p1("x-1");
	polinom p2("2x");
	EXPECT_EQ(p2, p + p1);
}

TEST(polinom, test_p_18)
{
	polinom p("x+1");
	polinom p1("x-1");
	polinom p2("2");
	EXPECT_EQ(p2, p - p1);
}

TEST(polinom, test_p_19)
{
	polinom p("1+x2y+z3x");
	polinom p1("yx2+3+2x");
	polinom p2("2x2y+xz3+2x+4");
	EXPECT_EQ(p2, p + p1);
}

TEST(polinom, test_p_20)
{
	polinom p("y2x+zx+2");
	double d = 2.5;
	polinom p2("2.5xy2+2.5xz+5");
	EXPECT_EQ(p2, p * d);
}

TEST(polinom, test_p_21)
{
	polinom p("y2x+zx+2");
	double d = 2.5;
	polinom p2("2.5xy2+2.5xz+5");
	EXPECT_EQ(p2, d * p);
}