#include "gtest.h"
#include "tpolynom.h"


TEST(TPolynom, create_empty_Polynom)
{
	ASSERT_NO_THROW(TPolynom());
}

TEST(TPolynom, create_polynom_with_string)
{
	string poly = "20x1y^2z^3 + 20 - x";
	ASSERT_NO_THROW(TPolynom(poly));
}

TEST(TPolynom, create_Polynom_with_Polynom)
{
	TPolynom Polynom("20x1y^2z^3 + 20 - x");
	ASSERT_NO_THROW(TPolynom Polynom1(Polynom));
}

TEST(TPolynom, sum)
{
	TPolynom Polynom1("x+y");
	TPolynom Polynom2("2x+y+1");
	TPolynom Polynom("3x+2y+1");
	bool c = Polynom == (Polynom1 + Polynom2);
	ASSERT_EQ(c, true);
}

TEST(TPolynom, sub)
{
	TPolynom Polynom1("x+y");
	TPolynom Polynom2("2x+y+1");
	TPolynom Polynom("x+1");
	bool c = Polynom == (Polynom2 - Polynom1);
	ASSERT_EQ(c, true);
}

TEST(TPolynom, prod)
{
	TPolynom Polynom1("x+y");
	TPolynom Polynom2("2x+y+1");
	TPolynom Polynom("2x^2 + y^2 + x + 3xy + y");
	bool c = Polynom == (Polynom2 * Polynom1);
	ASSERT_EQ(c, true);}

TEST(TPolynom, diff_x)
{
	TPolynom Polynom("2x+y+1");
	TPolynom diff("2");
	bool c = Polynom.dif_x() == diff;
	ASSERT_EQ(c, true);
}

TEST(TPolynom, diff_y)
{
	TPolynom Polynom("2x+y+1");
	TPolynom diff("1");
	bool c = Polynom.dif_y() == diff;
	ASSERT_EQ(c, true);
}

TEST(TPolynom, diff_z)
{
	TPolynom Polynom("2x+y+1");
	TPolynom diff("0");
	bool c = Polynom.dif_z() == diff;
	ASSERT_EQ(c, true);
}

TEST(TPolynom, eval)
{
	TPolynom Polynom("2x+y+1");
	int a12 = Polynom(1, 1, -1000);
	int res = 4;
	bool c = Polynom(1, 1, -1000) == res;
	ASSERT_EQ(c, true);
}

TEST(TPolynom, first_negative)
{
	TPolynom Polynom1("x+y");
	TPolynom Polynom2("-2x+y+1");
	TPolynom Polynom("-3x+1");
	bool c = Polynom == (Polynom2 - Polynom1);
	ASSERT_EQ(c, true);
}

TEST(TPolynom, placement)
{
	TPolynom Polynom1("xyz+xzy+yxz+yzx+zxy+yzx");
	TPolynom Polynom("6xyz");
	bool c = Polynom == Polynom1;
	ASSERT_EQ(c, true);
}
TEST(TPolynom, negative_eq)
{
	TPolynom Polynom1("-xyz+xzy");
	TPolynom Polynom("0");
	bool c = Polynom == Polynom1;
	ASSERT_EQ(c, true);
}

TEST(TPolynom, input_with_sign_power_of)
{
	TPolynom Polynom1("-2.001x^1000zy0 + zxz^5y");
	TPolynom Polynom("-2.001x^1000z + 1xyz^6");
	bool c = Polynom == Polynom1;
	ASSERT_EQ(c, true);
}

TEST(TPolynom, zeros1)
{
	TPolynom Polynom1("1+1+1-1-1-1");
	TPolynom Polynom("0");
	bool c = Polynom == Polynom1;
	ASSERT_EQ(c, true);
}

TEST(TPolynom, zeros2)
{
	TPolynom Polynom1("x^0y^0z^0 - 1");
	TPolynom Polynom("0");
	bool c = Polynom == Polynom1;
	ASSERT_EQ(c, true);
}