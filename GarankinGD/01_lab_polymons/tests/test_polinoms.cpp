#include "gtest.h"
#include "Polynom.h"
using namespace std;

TEST(polynom, create_polynom)
{
	ASSERT_NO_THROW(Polynom p);
}

TEST(polynom, copy_polynom)
{
	Polynom p("x+1");
	ASSERT_NO_THROW(Polynom p1(p));
}

TEST(polynom, check_build_polynom)
{
	ASSERT_NO_THROW(Polynom p("x+1"));
}

TEST(polynom, degree_not_more_than_9_1)
{
	Polynom p("x^4"), q("x^5");
	ASSERT_NO_THROW(p * q);
}

TEST(polynom, degree_not_more_than_9_2)
{
	Polynom p("x^5"), q("x^5");
	ASSERT_ANY_THROW(p * q);
}

TEST(polynom, add_polynoms)
{
	Polynom p("x+1");
	Polynom p1("x+y");
	Polynom p2 = p + p1;
	EXPECT_EQ(p2, p + p1);
}

TEST(polynom, mylty_polynoms)
{
	Polynom p("x+1");
	Polynom p1("x+y");
	Polynom p2 = p * p1;
	EXPECT_EQ(p2, p * p1);
}

TEST(polynom, sub_polynoms)
{
	Polynom p("x+1");
	Polynom p1("x+y");
	Polynom p2 = p - p1;
	EXPECT_EQ(p2, p - p1);
}

TEST(polynom, multy_polynoms_and_num_1)
{
	Polynom p("x+1");
	double a = 5.0;
	Polynom p2 = a * p;
	EXPECT_EQ(p2, a * p);
}

TEST(polynom, multy_polynoms_and_num_2)
{
	Polynom p("x+1");
	double a = 5.0;
	Polynom p2 = p * a;
	EXPECT_EQ(p2, p * a);
}

TEST(polynom, multy_polynoms_and_zero)
{
	Polynom p("x+1");
	double a = 0.0;
	Polynom p2 = p * a;
	EXPECT_EQ(p2, p * a);
}

TEST(polynom, minus_polynom)
{
	Polynom p("x+1");
	Polynom p2 = -p;
	EXPECT_EQ(p2, (-1) * p);
}

TEST(polynom, equal_polynom)
{
	Polynom p("x+1");
	Polynom p2("x+1");
	EXPECT_EQ(p == p2, true);
}

TEST(polynom, not_equal_polynom)
{
	Polynom p("x+1");
	Polynom p2("x^2+y");
	EXPECT_EQ(p != p2, true);
}

TEST(polinom, create_polynom_from_string)
{
	string str = "x+2z+y";
	ASSERT_NO_THROW(Polynom a(str));
}

TEST(polynom, add_some_polynoms_1)
{
	Polynom p("x+1");
	Polynom p1("x-1");
	Polynom res("2x");
	EXPECT_EQ(res, p + p1);
}

TEST(polynom, add_some_polynoms_2)
{
	Polynom p2("x^2+x-z");
	Polynom p3("-x+3z-23y^2");
	Polynom res("+2z-23y^2+x^2");
	EXPECT_EQ(res, p2 + p3);
}

TEST(polynom, add_some_polynoms_3)
{
	Polynom p2("x+5y-z");
	Polynom p3("-x+3z-23y^2");
	Polynom res("+2z+5y-23y^2");
	EXPECT_EQ(res, p2 + p3);
}

TEST(polynom, add_some_polynoms_4)
{
	Polynom p2("x^2+2x^2-z+4y");
	Polynom p3("-x^2-2z-23y^2");
	Polynom res("-3z+4y-23y^2+2x^2");
	EXPECT_EQ(res, p2 + p3);
}
/////////////////////////////////////
TEST(polynom, sub_some_polynoms_1)
{
	Polynom p("x+1");
	Polynom p1("x-1");
	Polynom res("2");
	EXPECT_EQ(res, p - p1);
}

TEST(polynom, sub_some_polynoms_2)
{
	Polynom p2("x^2+x-z");
	Polynom p3("-x+3z-23y^2");
	Polynom res("-4z+23y^2+2x+x^2");
	EXPECT_EQ(res, p2 - p3);
}

TEST(polynom, sub_some_polynoms_3)
{
	Polynom p2("x+5y-z");
	Polynom p3("-x+3z-23y^2");
	Polynom res("-4z+5y+23y^2+2x");
	EXPECT_EQ(res, p2 - p3);
}

TEST(polynom, sub_some_polynoms_4)
{
	Polynom p2("x^2+2x^2-z+4y");
	Polynom p3("-x^2-2z-23y^2");
	Polynom res("z+4y+23y^2+4x^2");
	EXPECT_EQ(res, p2 - p3);
}
////////////////////////////////////////////
TEST(polynom, multy_some_polynoms_1)
{
	Polynom p("x+1");
	Polynom p1("x-1");
	Polynom res("-1+x^2");
	EXPECT_EQ(res, p * p1);
}

TEST(polynom, multy_some_polynoms_2)
{
	Polynom p2("x^2+x-z");
	Polynom p3("-x+3z-23y^2");
	Polynom res("-3z^2+23y^2z+4xz-23xy^2-1x^2+3x^2z-23x^2y^2-1x^3");
	EXPECT_EQ(res, p2 * p3);
}

TEST(polynom, multy_some_polynoms_3)
{
	Polynom p2("x+5y-z");
	Polynom p3("-x+3z-23y^2");
	Polynom res("-3z^2+15yz+23y^2z-115y^3+4xz-5xy-23xy^2-1x^2");
	EXPECT_EQ(res, p2 * p3);
}

TEST(polynom, multy_some_polynoms_4)
{
	Polynom p2("x^2+2x^2-z+4y");
	Polynom p3("-x^2-2z-23y^2");
	Polynom res("2z^2-8yz+23y^2z-92y^3-5x^2z-4x^2y-69x^2y^2-3x^4");
	EXPECT_EQ(res, p2 * p3);
}
////////////////////////////////////////////////////////
TEST(polynom, multy_some_polynoms_D1)
{
	Polynom p("x+1");
	int d = 7;
	Polynom res("7x+7");
	EXPECT_EQ(res, p * d);
}

TEST(polynom, multy_some_polynoms_D2)
{
	Polynom p2("x^2+x-z");
	int d = 7;
	Polynom res("7x^2+7x-7z");
	EXPECT_EQ(res, p2 * d);
}

TEST(polynom, multy_some_polynoms_D3)
{
	Polynom p2("x+5y-z");
	int d = 7;
	Polynom res("7x+35y-7z");
	EXPECT_EQ(res, p2 * d);
}

TEST(polynom, multy_some_polynoms_D4)
{
	Polynom p2("x^2+2x^2-z+4y");
	int d = 7;
	Polynom res("21x^2-7z+28y");
	EXPECT_EQ(res, p2 * d);
}