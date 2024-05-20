#include "tpolynom.h"
#include <gtest.h>

TEST(TPolynom, can_create_polynom) {
	ASSERT_NO_THROW(TPolynom p);
}
TEST(TPolynom, can_create_polynom_w_string) {
	ASSERT_NO_THROW(TPolynom p("x^2y^3z-x*z+y^2"));
}
TEST(TPolynom, can_create_polynom_w_monom) {
	TRingList<TMonom> m;
	TMonom b(7, 111);
	m.InsertLast(b);
	ASSERT_NO_THROW(TPolynom p(m));
}
TEST(TPolynom, can_copy_polynom) {
	TPolynom p1("x^3+y");
	ASSERT_NO_THROW(TPolynom p_copy(p1));
}
TEST(TPolynom, can_right_copy_polynom) {
	TPolynom p1("x^3+y");
	TPolynom p_copy(p1);
	EXPECT_EQ(p1.get_name(), p_copy.get_name());
}
TEST(TPolynom, can_get_name)
{
	TPolynom p1("x^3+y");
	EXPECT_EQ("1.000000*y^1+1.000000*x^3", p1.get_name());
}

TEST(TPolynom, can_sum_polynoms)
{
	TPolynom p1("x^3+y");
	TPolynom p2("x^3+y+xz");
	ASSERT_NO_THROW(p1 + p2);
}
TEST(TPolynom, right_sum_polynoms)
{
	TPolynom p1("x^3+y");
	TPolynom p2("x^3+y+x*z");
	EXPECT_EQ("2.000000*y^1+1.000000*x^1*z^1+2.000000*x^3", (p1 + p2).get_name());
}

TEST(TPolynom, can_mult_polynoms)
{
	TPolynom p1("x^3+y");
	TPolynom p2("x^3+y+x*z");
	ASSERT_NO_THROW(p1 * p2);
}
TEST(TPolynom, right_mult_polynoms) {
	TPolynom p1("x^3+y");
	TPolynom p2("x^3+y+x*z");
	EXPECT_EQ("1.000000*y^2+1.000000*x^1*y^1*z^1+2.000000*x^3*y^1+1.000000*x^4*z^1+1.000000*x^6", (p1 * p2).get_name());
}

TEST(TPolynom, can_subtract_polynoms)
{
	TPolynom p1("x^3+y");
	TPolynom p2("x^3+y+x*z");
	ASSERT_NO_THROW(p1 - p2);
}
TEST(TPolynom, right_subtract_polynoms)
{
	TPolynom p1("x^3+y");
	TPolynom p2("x^3+y+x*z");
	EXPECT_EQ("-1.000000*x^1*z^1", (p1 - p2).get_name());
}

TEST(TPolynom, right_sum_polynoms_w_zero_coeff_and_equals)
{
	TPolynom p1("2*x^2-y*z-x+0*z+0*y");
	TPolynom p2("3*x^2+2*x^3+x*y*z+4*x");

	EXPECT_EQ("-1.000000*y^1*z^1+3.000000*x^1+1.000000*x^1*y^1*z^1+5.000000*x^2+2.000000*x^3", (p1 + p2).get_name());
}

TEST(TPolynom, can_difX)
{
	TPolynom p3("x^4+3*x+y*z+3*y^3*z+x^2*y*z^5");
	ASSERT_NO_THROW(p3.dif_x());
}

TEST(TPolynom, can_difY)
{
	TPolynom p3("x^4+3*x+y*z+3*y^3*z+x^2*y*z^5");
	ASSERT_NO_THROW(p3.dif_y());
}

TEST(TPolynom, can_difZ)
{
	TPolynom p3("x^4+3*x+y*z+3*y^3*z+x^2*y*z^5");
	ASSERT_NO_THROW(p3.dif_z());
}

TEST(TPolynom, can_dif)
{
	TPolynom p3("x^4+3*x+y*z+3*y^3*z+x^2*y*z^5");
	ASSERT_NO_THROW(p3.dif());
}