#include <gtest.h>
#include "tpolynom.h"

const string str="x+y+z";

TEST(TPolynom, create_empty_polinom)
{
	ASSERT_NO_THROW(TPolynom p());
}

TEST(TPolynom, create_polinom)
{
	ASSERT_NO_THROW(TPolynom p(str));
}

TEST(TPolynom, can_create_copied_polinom)
{
	TPolynom p1(str);
	ASSERT_NO_THROW(TPolynom p2(p1));
}

TEST(TPolynom, equality_operator_is_correct)
{
	TPolynom p1(str);
	TPolynom p2(str);
  
	EXPECT_EQ(p1, p2);
}

TEST(TPolynom, copied_polinom_is_correct)
{
	TPolynom p1(str);
	TPolynom p2(p1);
	EXPECT_EQ(p1, p2);
}

TEST(TPolynom, no_throw_when_polynom_will_be_empty) 
{
  ASSERT_NO_THROW(TPolynom p("x-x+y-y+z-z"));
}

TEST(TPolynom, correct_to_string_method) // ???
{
  TPolynom p("x^2-y*z^3+3");
  string nm = "3.00-y*z^3+x^2";
  EXPECT_EQ(p.ToString(), nm);
}

TEST(TPolynom, collecting_terms_test) {
	TPolynom p1("x+x-x+x+y+y+z+z+z");
	TPolynom p2("2*x+2*y+3*z");
	EXPECT_EQ(p1, p2);
}

TEST(TPolynom, collecting_terms_to_zero) {
	TPolynom p1("x+x-x-x+y-y");
	TPolynom p2("0");
	EXPECT_EQ(p1, p2);
}

TEST(TPolynom, conversation_test) {
	TPolynom p1("x+x-x+x+y+y+z+z+z");
	TPolynom p2("2*x+2*y+3*z");

	EXPECT_EQ(p1, p2);
}

TEST(TPolynom, can_create_polynom_in_different_order)
{
	TPolynom p("x+y+z");
	TPolynom p_reordered("z+y+x");

	EXPECT_EQ(p, p_reordered);
}

TEST(TPolynom, can_create_polynom_with_negative_coefficient)
{
	ASSERT_NO_THROW(TPolynom p("-10*x^4"));
}

TEST(TPolynom, calculate_is_correct1) 
{
	TPolynom pol(str);
	double res = pol(1,2,3);
	EXPECT_EQ(6, res);
}

TEST(TPolynom, calculate_is_correct2)
{
	TPolynom pol("x^3*z+x^2+y+y+1");
	double res = pol(0.9, 0.2, 0.7);
	ASSERT_NEAR(2.7203, res, 0.001f);
}

TEST(TPolynom, calculate_is_correct3)
{
	TPolynom p("5");
	EXPECT_EQ(p(0, 0, 0), 5);
}

TEST(TPolynom, calculate_is_correct4)
{
	TPolynom pol("x+x^2+y+x+1");
	double res = pol(1, 2, 3);
	EXPECT_EQ(6, pol(1, 2, 3));
}

TEST(TPolynom, dx_is_correct) 
{
	TPolynom pol("5*x^4+x^2+y+z+1");
	TPolynom tmp("20*x^3+2x^1");
	EXPECT_EQ(pol.dx(), tmp);
}

TEST(TPolynom, dy_is_correct) 
{
	TPolynom pol("y^3+y^2+x+z+1");
	TPolynom tmp("3y^2+2y^1");
	EXPECT_EQ(pol.dy() , tmp);
}

TEST(TPolynom, dz_is_correct) 
{
	TPolynom pol("z^3+z^2+y+x+1");
	TPolynom tmp("3z^2+2z^1");
	EXPECT_EQ(pol.dz(), tmp);
}

TEST(TPolynom, empty_dx) 
{
	TPolynom pol("z+y*z");
	TPolynom tmp;
	EXPECT_EQ(pol.dx(), tmp);
}

TEST(TPolynom, empty_dy) 
{
	TPolynom pol("z*x^4+z");
	TPolynom tmp;
	EXPECT_EQ(pol.dy() , tmp);
}

TEST(TPolynom, empty_dz) 
{
	TPolynom pol("3*y+2*x^2+0*z");
	TPolynom tmp;
	EXPECT_EQ(pol.dz(), tmp);
}

TEST(TPolynom,sum_is_correct ) 
{
	TPolynom pol1("x^3+y^2+y+x+1");
	TPolynom pol2("x^3+y+z+1");
	TPolynom pol3("2x^3+y^2+2y+x+2+z");
	EXPECT_EQ(pol1+pol2, pol3);
}

TEST(TPolynom, empty_sum) 
{
	TPolynom pol1("x^3-y^2+4");
	TPolynom pol2("-x^3+y^2-4");
	TPolynom pol3("0");
	EXPECT_EQ(pol1+pol2, pol3);
}

TEST(TPolynom, diff_is_correct) 
{
	TPolynom pol1("2*x^3+y^2+y+x");
	TPolynom pol2("x^3-2y^2+z");
	TPolynom pol3("x^3+3*y^2+y^1+x-z");
	EXPECT_EQ(pol1-pol2, pol3);
}

TEST(TPolynom, empty_diff)
{
	TPolynom p1("-3*x^2-2*y+5");
	TPolynom p2("-3*x^2-4*y+2*y+5");
	TPolynom p3("0");
	EXPECT_EQ(p1 - p2, p3);
}

TEST(TPolynom, mult_is_correct1) 
{
	TPolynom pol1("x^2+y");
	TPolynom pol2("x^3+x");
	TPolynom pol3("x^5+x^3+x^3*y+x*y");

	EXPECT_EQ(pol1*pol2, pol3);
}

TEST(TPolynom, mult_by_zero) 
{
	TPolynom pol1("x^2+y");
	TPolynom pol2("0");
	TPolynom pol3("0");
	EXPECT_EQ(pol1*pol2, pol3);
}

TEST(TPolynom, empty_polynomial_to_string)
{
	TPolynom p("0");
	EXPECT_EQ("0", p.ToString());
}

TEST(TPolynom, can_negate_polynomial)
{
	TPolynom p("x+y-z");
	TPolynom negated = -p;
	TPolynom expected("-x-y+z");
	EXPECT_EQ(expected, negated);
}

TEST(TPolynom, calculate_empty_polynomial)
{
	TPolynom p("0");
	double result = p(1, 2, 3);
	EXPECT_EQ(0, result);
}

TEST(TPolynom, sum_empty_polynomials)
{
	TPolynom p1("0");
	TPolynom p2("0");
	TPolynom sum = p1 + p2;
	EXPECT_EQ("0", sum.ToString());
}

TEST(TPolynom, multiply_by_zero_polynomial)
{
	TPolynom p1("x+y");
	TPolynom p2("0");
	TPolynom result = p1 * p2;
	EXPECT_EQ("0", result.ToString());
}

TEST(TPolynom, chech_dx_1_no_throw)
{
	TPolynom p("1+x");
	ASSERT_NO_THROW(p.dx());
}

TEST(TPolynom, chech_dx_1_correctness)
{
	TPolynom p("1+x");
	TPolynom dx = p.dx();
	EXPECT_EQ(dx.ToString(), "1.00");
}

TEST(TPolynom, can_create_polynom) {
	ASSERT_NO_THROW(TPolynom p());
}
TEST(TPolynom, can_create_polynom_w_string) {
	ASSERT_NO_THROW(TPolynom p("x^2y^3z-xz+y^2"));
}
TEST(TPolynom, can_copy_polynom) {
	TPolynom p1("x^3+y");
	ASSERT_NO_THROW(TPolynom p_copy(p1));
}
TEST(TPolinom, can_right_copy_polynom) {
	TPolynom p1("x^3+y");
	TPolynom p_copy(p1);
	EXPECT_EQ(p1.ToString(), p_copy.ToString());
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
	TPolynom p2("x^3+y+xz");
	EXPECT_EQ("2.00*y+x*z+2.00*x^3", (p1 + p2).ToString());
}

TEST(TPolynom, can_mult_polynoms)
{
	TPolynom p1("x^3+y");
	TPolynom p2("x^3+y+xz");
	ASSERT_NO_THROW(p1 * p2);
}
TEST(TPolynom, right_mult_polynoms) {
	TPolynom p1("x^3+y");
	TPolynom p2("x^3+y+xz");
	EXPECT_EQ("y^2+x*y*z+2.00*x^3*y+x^4*z+x^6", (p1 * p2).ToString());
}

TEST(TPolynom, can_subtract_polynoms)
{
	TPolynom p1("x^3+y");
	TPolynom p2("x^3+y+xz");
	ASSERT_NO_THROW(p1 - p2);
}
TEST(TPolynom, right_subtract_polynoms)
{
	TPolynom p1("x^3+y");
	TPolynom p2("x^3+y+xz");
	EXPECT_EQ("-x*z", (p1 - p2).ToString());
}

TEST(TPolynom, right_sum_polynoms_w_zero_coeff_and_equals)
{
	TPolynom p1("2*x^2-yz-x+0*z+0*y");
	TPolynom p2("3*x^2+2*x^3+xyz+4*x");

	EXPECT_EQ("-y*z+3.00*x+x*y*z+5.00*x^2+2.00*x^3", (p1 + p2).ToString());
}

TEST(TPolynom, can_dx)
{
	TPolynom p3("x^4+3*x+yz+3*y^3z+x^2yz^5");
	ASSERT_NO_THROW(p3.dx());
}
TEST(TPolynom, right_dx)
{
	TPolynom p3("x^4+3*x+yz+3*y^3z+x^2yz^5");
	EXPECT_EQ("3.00+2.00*x*y*z^5+4.00*x^3", p3.dx().ToString());
}
TEST(TPolynom, can_dy)
{
	TPolynom p3("x^4+3*x+yz+3*y^3z+x^2yz^5");
	ASSERT_NO_THROW(p3.dy());
}
TEST(TPolynom, right_dy)
{
	TPolynom p3("x^4+3*x+yz+3*y^3z+x^2yz^5");
	EXPECT_EQ("z+9.00*y^2*z+x^2*z^5", p3.dy().ToString());
}
TEST(TPolynom, can_dz)
{
	TPolynom p3("x^4+3*x+yz+3*y^3z+x^2yz^5");
	ASSERT_NO_THROW(p3.dz());
}
TEST(TPolynom, right_dz)
{
	TPolynom p3("x^4+3*x+yz+3*y^3z+x^2yz^5");
	EXPECT_EQ("y+3.00*y^3+5.00*x^2*y*z^4", p3.dz().ToString());
}