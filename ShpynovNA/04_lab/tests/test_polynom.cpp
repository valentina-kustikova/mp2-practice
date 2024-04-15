#include "tpolynomial.h"
#include <gtest.h>
#include <utility>
#include <vector>

class TestPolynomial : public TPolynomial
{
public:
	TestPolynomial():TPolynomial(){}
	TestPolynomial(const string& n) :TPolynomial(n) {}
	TestPolynomial(const THeadRingList<TMonomial>& l) :TPolynomial(l) {}
	TestPolynomial(const TPolynomial& p) :TPolynomial(p) {}
	using TPolynomial::name;
	using TPolynomial::monomials;
};

TEST(TMonomial, can_create_default_monomial) {
	TMonomial tmp = TMonomial();
	std::pair<double, short> test = std::pair<double, short>(0.0, -1);
	std::pair<double, short> test1 = std::pair<double, short>(tmp.coef, tmp.degr);
	ASSERT_EQ(test1, test);
}
TEST(TMonomial, can_create_custom_monomial) {
	TMonomial tmp = TMonomial(4.5, 3);
	std::pair<double, short> test = std::pair<double, short>(4.5, 3);
	std::pair<double, short> test1 = std::pair<double, short>(tmp.coef, tmp.degr);
	ASSERT_EQ(test1, test);
}
TEST(TMonomial, can_compare_monomials) {
	TMonomial tmp = TMonomial(4.5, 321);
	TMonomial tmp1 = TMonomial(4.5, 200);
	ASSERT_TRUE(tmp1<tmp);
}



TEST(TPolynomial, can_create_default_polynomial) {
	EXPECT_NO_THROW(TPolynomial());
}
TEST(TPolynomial, can_create_polynomial_from_string) {
	EXPECT_NO_THROW(TPolynomial("5x^2*y^3*z^4+11*x^3+7"));
}
TEST(TPolynomial, can_create_constant) {
	EXPECT_NO_THROW(TPolynomial("7"));
}
TEST(TPolynomial, constant_correct) {
	TestPolynomial tmp = TPolynomial("7");
	tmp.monomials.reset();
	EXPECT_EQ(tmp.monomials.GetCurrent()->data.coef, 7);
}
TEST(TPolynomial, can_create_zero) {
	EXPECT_NO_THROW(TPolynomial("0"));
}
TEST(TPolynomial, zero_correct) {
	TestPolynomial tmp = TPolynomial("0");
	tmp.monomials.reset();
	EXPECT_EQ(tmp.monomials.GetCurrent()->data.coef, 0);
}
TEST(TPolynomial, can_create_polynomial_from_list) {
	TestPolynomial tmp = TPolynomial("5x^2*y^3*z^4+11*x^3+7");

	EXPECT_NO_THROW(TPolynomial(tmp.monomials));
}
TEST(TPolynomial, can_create_polynomial_from_poly) {
	TPolynomial tmp = TPolynomial("5x^2*y^3*z^4+11*x^3+7");
	EXPECT_NO_THROW(TPolynomial(tmp));
}
TEST(TPolynomial, can_compare_polynomials) {
	TPolynomial tmp = TPolynomial("5x^2*y^3*z^4+11*x^3+7");
	TPolynomial tmp1 = TPolynomial(tmp);
	EXPECT_EQ(tmp, tmp1);
}
TEST(TPolynomial, string_division_is_correct) {
	TestPolynomial tmp = TPolynomial("5x*y^3*z^4+11*x^3-7");
	vector<pair<double, short>> A;
	tmp.monomials.reset();
	while (!tmp.monomials.IsEnded()) {
		A.push_back(pair<double, short>(tmp.monomials.GetCurrent()->data.coef, tmp.monomials.GetCurrent()->data.degr));
		tmp.monomials.next();
	}
	vector<pair<double, short>> B;
	B.push_back((pair<double, short>(11.0, 300)));
	B.push_back((pair<double, short>(5.0, 134)));
	B.push_back((pair<double, short>(-7.0, 0)));
	ASSERT_EQ(A, B);
}
TEST(TPolynomial, string_division_is_correct_if_wrong_placement) {
	TestPolynomial tmp = TPolynomial("5y^3*x^2*z^4+11*x^3-7");
	vector<pair<double, short>> A;
	tmp.monomials.reset();
	while (!tmp.monomials.IsEnded()) {
		A.push_back(pair<double, short>(tmp.monomials.GetCurrent()->data.coef, tmp.monomials.GetCurrent()->data.degr));
		tmp.monomials.next();
	}
	vector<pair<double, short>> B;
	B.push_back((pair<double, short>(11.0, 300)));
	B.push_back((pair<double, short>(5.0, 234)));
	B.push_back((pair<double, short>(-7.0, 0)));
	ASSERT_EQ(A, B);
}
TEST(TPolynomial, can_assign_polynomials) {
	TPolynomial tmp = TPolynomial("5x^2*y^3*z^4+11*x^3+7");
	TPolynomial tmp1 = tmp;
	EXPECT_EQ(tmp, tmp1);
}
TEST(TPolynomial, can_sum_polynomials) {
	TPolynomial tmp = TPolynomial("5x^2*y^3*z^4+11*x^3+7");
	TPolynomial tmp1 = TPolynomial("3x^2*y^3*z^4");
	TPolynomial tmp2 = TPolynomial("7+8*x^2*y^3*z^4+11*x^3");
	EXPECT_EQ(tmp2, tmp1+tmp);
}
TEST(TPolynomial, can_subtr_polynomials) {
	TPolynomial tmp = TPolynomial("5x^2*y^3*z^4+11*x^3+7");
	TPolynomial tmp1 = TPolynomial("3x^2*y^3*z^4");
	TPolynomial tmp2 = TPolynomial("7+2*x^2*y^3*z^4+11*x^3");
	EXPECT_EQ(tmp2, tmp1 - tmp);
}
TEST(TPolynomial, can_mult_polynomials) {
	TPolynomial tmp = TPolynomial("5x^2*y^3*z^4+11*x^3+7");
	TPolynomial tmp1 = TPolynomial("3x^2*y^3*z^4");
	TPolynomial tmp2 = TPolynomial("21*x^2*y^3*z^4+33*x^5*y^3*z^4+15*x^4*y^6*z^8");
	EXPECT_EQ(tmp2, tmp1*tmp);
}
TEST(TPolynomial, can_deriv_x) {
	TPolynomial tmp = TPolynomial("5x^2*y^3*z^4+11*x^3+7");
	TPolynomial tmp1 = TPolynomial("10*x^1*y^3*z^4+33*x^2");
	EXPECT_EQ(tmp.DerivativeX(), tmp1);
}
TEST(TPolynomial, can_deriv_x_if_no_x_is_present) {
	TPolynomial tmp = TPolynomial("5*y^3*z^4+11");
	TPolynomial tmp1 = TPolynomial("0");
	EXPECT_EQ(tmp.DerivativeX(), tmp1);
}
TEST(TPolynomial, can_deriv_x_if_no_variables_is_present) {
	TPolynomial tmp = TPolynomial("5+11");
	TPolynomial tmp1 = TPolynomial("0");
	EXPECT_EQ(tmp.DerivativeX(), tmp1);
}
TEST(TPolynomial, can_deriv_y) {
	TPolynomial tmp = TPolynomial("5x^2*y^3*z^4+11*x^3+7");
	TPolynomial tmp1 = TPolynomial("15x^2*y^2*z^4");
	EXPECT_EQ(tmp.DerivativeY(), tmp1);
}
TEST(TPolynomial, can_deriv_y_if_no_y_is_present) {
	TPolynomial tmp = TPolynomial("5*x^3*z^4+11");
	TPolynomial tmp1 = TPolynomial("0");
	EXPECT_EQ(tmp.DerivativeY(), tmp1);
}
TEST(TPolynomial, can_deriv_y_if_no_variables_is_present) {
	TPolynomial tmp = TPolynomial("5+11");
	TPolynomial tmp1 = TPolynomial("0");
	EXPECT_EQ(tmp.DerivativeY(), tmp1);
}
TEST(TPolynomial, can_deriv_z) {
	TPolynomial tmp = TPolynomial("5x^2*y^3*z^4+11*x^3+7");
	TPolynomial tmp1 = TPolynomial("20*x^2*y^3*z^3");
	EXPECT_EQ(tmp.DerivativeZ(), tmp1);
}
TEST(TPolynomial, can_deriv_z_if_no_z_is_present) {
	TPolynomial tmp = TPolynomial("5*y^3*x^4+11");
	TPolynomial tmp1 = TPolynomial("0");
	EXPECT_EQ(tmp.DerivativeZ(), tmp1);
}
TEST(TPolynomial, can_deriv_z_if_no_variables_is_present) {
	TPolynomial tmp = TPolynomial("5+11");
	TPolynomial tmp1 = TPolynomial("0");
	EXPECT_EQ(tmp.DerivativeZ(), tmp1);
}
TEST(TPolynomial, can_assign_polynomial) {
	TPolynomial tmp = TPolynomial("5x^2*y^3*z^4+11*x^3+7");
	TPolynomial tmp1 = tmp;
	EXPECT_EQ(tmp, tmp1);
}
TEST(TPolynomial, can_calculate_polynomial) {
	TPolynomial tmp = TPolynomial("5x^2*y^3*z^4+11*x^3+7");
	double test = 23;
	EXPECT_EQ(tmp(1, 1, 1), test);
}