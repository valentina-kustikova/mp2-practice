#include "tpolynom.h"
#include <gtest.h>

TEST(TPolinom, can_create_polynom) {
	ASSERT_NO_THROW(TPolinom p());
}
TEST(TPolinom, can_create_polynom_w_string) {
	ASSERT_NO_THROW(TPolinom p("x^2y^3z-xz+y^2"));
}
TEST(TPolinom, can_create_polynom_w_monom) {
	TRingList<TMonom> m;
	m.InsertLast(7);
	ASSERT_NO_THROW(TPolinom p(m));
}
TEST(TPolinom, can_copy_polynom) {
	TPolinom p1("x^3+y");
	ASSERT_NO_THROW(TPolinom p_copy(p1));
}
TEST(TPolinom, can_right_copy_polynom) {
	TPolinom p1("x^3+y");
	TPolinom p_copy(p1);
	EXPECT_EQ(p1.getFormula(), p_copy.getFormula());
}
TEST(TPolinom, can_getFormula)
{	
	TPolinom p1("x^3+y");
	EXPECT_EQ("+x^3+y", p1.getFormula());
}
TEST(TPolinom, can_getStringMonoms)
{
	TPolinom p1("x^3+y");
	EXPECT_EQ("+x^3+y", p1.getStringMonoms());
}

TEST(TPolinom, can_sum_polynoms)
{
	TPolinom p1("x^3+y");
	TPolinom p2("x^3+y+xz");
	ASSERT_NO_THROW(p1+p2);
}
TEST(TPolinom, right_sum_polynoms)
{
	TPolinom p1("x^3+y");
	TPolinom p2("x^3+y+xz");
	EXPECT_EQ("+2.000*x^3+xz+2.000*y", (p1+p2).getFormula());
}

TEST(TPolinom, can_mult_polynoms)
{
	TPolinom p1("x^3+y");
	TPolinom p2("x^3+y+xz");
	ASSERT_NO_THROW(p1 * p2);
}
TEST(TPolinom, right_mult_polynoms) {
	TPolinom p1("x^3+y");
	TPolinom p2("x^3+y+xz");
	EXPECT_EQ("+x^6+x^4z+2.000*x^3y+xyz+y^2", (p1 * p2).getFormula());
}

TEST(TPolinom, can_subtract_polynoms)
{
	TPolinom p1("x^3+y");
	TPolinom p2("x^3+y+xz");
	ASSERT_NO_THROW(p1 - p2);
}
TEST(TPolinom, right_subtract_polynoms)
{
	TPolinom p1("x^3+y");
	TPolinom p2("x^3+y+xz");
	EXPECT_EQ("-xz", (p1 - p2).getFormula());
}

TEST(TPolinom, right_sum_polynoms_w_zero_coeff_and_equals)
{
	TPolinom p1("2*x^2-yz-x+0*z+0*y");
	TPolinom p2("3*x^2+2*x^3+xyz+4*x");

	EXPECT_EQ("+2.000*x^3+5.000*x^2+xyz+3.000*x-yz", (p1 + p2).getFormula());
}

TEST(TPolinom, can_defX)
{
	TPolinom p3("x^4+3*x+yz+3*y^3z+x^2yz^5");
	ASSERT_NO_THROW(p3.defX());
}
TEST(TPolinom, right_defX)
{
	TPolinom p3("x^4+3*x+yz+3*y^3z+x^2yz^5");
	EXPECT_EQ("+4.000*x^3+2.000*xyz^5+3.000", p3.defX().getFormula());
}
TEST(TPolinom, can_defY)
{
	TPolinom p3("x^4+3*x+yz+3*y^3z+x^2yz^5");
	ASSERT_NO_THROW(p3.defY());
}
TEST(TPolinom, right_defY)
{
	TPolinom p3("x^4+3*x+yz+3*y^3z+x^2yz^5");
	EXPECT_EQ("+x^2z^5+9.000*y^2z+z", p3.defY().getFormula());
}
TEST(TPolinom, can_defZ)
{
	TPolinom p3("x^4+3*x+yz+3*y^3z+x^2yz^5");
	ASSERT_NO_THROW(p3.defZ());
}
TEST(TPolinom, right_defZ)
{
	TPolinom p3("x^4+3*x+yz+3*y^3z+x^2yz^5");
	EXPECT_EQ("+5.000*x^2yz^4+3.000*y^3+y", p3.defZ().getFormula());
}