#include "pch.h"
#include"../Polinom/Polinom.h"

TEST(Polinom, create_polinom)
{
	ASSERT_NO_THROW(Polinom p);
}

TEST(Polinom, copy_polinom)
{
	Polinom p("x+1");
	ASSERT_NO_THROW(Polinom p1(p));
}

TEST(Polinom, check_build_polinom)
{
	ASSERT_NO_THROW(Polinom p("x+1"));
}

TEST(Polinom, create_polinom_from_string)
{
	string str = "x+2z+y";
	ASSERT_NO_THROW(Polinom a(str));
}

TEST(Polinom, degree_not_more_than_9_1)
{
	Polinom p("x^4"), q("x^5");
	ASSERT_NO_THROW(p * q);
}

TEST(Polinom, degree_not_more_than_9_2)
{
	Polinom p("x^5"), q("x^5");
	ASSERT_ANY_THROW(p * q);
}

TEST(Polinom, Summa_1)
{
	Polinom a("10x^2");
	Polinom b("12y^2");
	ASSERT_NO_THROW(a + b);
}

TEST(Polinom, Summa_2)
{
	Polinom a("x^3+2y^2-z");
	Polinom b("y^3-3xy+2xy^3");
	ASSERT_NO_THROW(a + b);
}

TEST(Polinom, Summa_is_Correct_1)
{
	Polinom a("5x^2");
	Polinom b("6x^7");
	Polinom c("6x^7+5x^2");
	EXPECT_EQ(c, a + b);
}

TEST(Polinom, Summa_is_Correct_2)
{
	Polinom a("x+y+z");
	Polinom b("x-2y+z^2");
	Polinom c("2x-y+z^2+z");
	EXPECT_EQ(c, a + b);
}

TEST(Polinom, Substract_1)
{
	Polinom a("x+1");
	Polinom b("x-1");
	ASSERT_NO_THROW(a + b);
}
TEST(Polinom, Substract_2)
{
	Polinom a("x^2+5");
	Polinom b("x^2-4");
	ASSERT_NO_THROW(a + b);
}

TEST(Polinom, Substract_is_Correct_1)
{
	Polinom a("x+1");
	Polinom b("x-1");
	Polinom c("-2");
	EXPECT_EQ(c, b - a);
}

TEST(Polinom, Substract_is_Correct_2)
{
	Polinom a("x+2y");
	Polinom b("x-z");
	Polinom c("2y+z");
	EXPECT_EQ(c, a - b);
}

TEST(Polinom, Mult_Two_Pol_1)
{
	Polinom a("x^3");
	Polinom b("y^4");
	ASSERT_NO_THROW(a * b);
}
TEST(Polinom, Mult_Two_Pol_2)
{
	Polinom a("10x^2");
	Polinom b("12y^2");
	ASSERT_NO_THROW(a * b);
}

TEST(Polinom, Mult_Two_Pol_is_Correct_1)
{
	Polinom a("2x^2");
	Polinom b("2y^2");
	Polinom c("4x^2y^2");
	EXPECT_EQ(c, a * b);
}
TEST(Polinom, Mult_Two_Pol_is_Correct_2)
{
	Polinom a("x+1");
	Polinom b("x-1");
	Polinom c("x^2-1");
	EXPECT_EQ(c, a * b);
}

TEST(Polinom, ERROR_Mult_St_Over_10_1)
{
	Polinom a("3x^4");
	Polinom b("x^8");
	ASSERT_ANY_THROW(a * b);
}
TEST(Polinom, ERROR_Mult_St_Over_10_2)
{
	Polinom a("y^2");
	Polinom b("y^8");
	ASSERT_ANY_THROW(a * b);
}

TEST(Polinom, Group_Equal_St_1)
{
	Polinom a("xyz+xy");
	Polinom b("z+2");
	Polinom c("xyz^2+xyz+2xyz+2xy");
	Polinom d("xyz^2+3xyz+2xy");
	EXPECT_EQ(c, a * b);
	EXPECT_EQ(c, d);
}

TEST(Polinom, Group_Equal_St_2)
{
	Polinom a("x+yz");
	Polinom b("2x+yz");
	Polinom c("2x^2+2xyz+xyz+y^2z^2");
	Polinom d("2x^2+3xyz+y^2z^2");
	EXPECT_EQ(c, a * b);
	EXPECT_EQ(c, d);
}
TEST(Polinom, Mult_Pol_On_Double_1)
{
	Polinom a("x^2");
	double b = 20.9;
	ASSERT_NO_THROW(a * b);
}

TEST(Polinom, Mult_Pol_On_Double_2)
{
	Polinom a("x^2+y-z");
	double b = 5.5;
	ASSERT_NO_THROW(a * b);
}

TEST(Polinom, Mult_Pol_On_Double_is_Correct_1)
{
	Polinom a("100x^3");
	double b = 19.5;
	Polinom c("1950x^3");
	EXPECT_EQ(c, a * b);
}
TEST(Polinom, Mult_Pol_On_Double_is_Correct_2)
{
	Polinom a("10x^2-2y+4z");
	double b = 3.5;
	Polinom c("35x^2-7y+14z");
	EXPECT_EQ(c, a * b);
}
TEST(Polinom, Mult_Pol_On_Double_OtherSide_1)
{
	double b = 20.9;
	Polinom a("x^2");
	ASSERT_NO_THROW(a * b);
}

TEST(Polinom, Mult_Pol_On_Double_OtherSide_2)
{
	double b = 5.5;
	Polinom a("x^2+y-z");
	ASSERT_NO_THROW(a * b);
}

TEST(Polinom, Mult_Pol_On_Double_OtherSide_is_Correct_1)
{
	double b = 19.5;
	Polinom a("100x^3");
	Polinom c("1950x^3");
	EXPECT_EQ(c, a * b);
}
TEST(Polinom, Mult_Pol_On_Double_OtherSide_is_Correct_2)
{
	double b = 3.5;
	Polinom a("10x^2-2y+4z");
	Polinom c("35x^2-7y+14z");
	EXPECT_EQ(c, a * b);
}