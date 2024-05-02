#include "tpolynom.h"
#include <gtest.h>

TEST(TPolynom, can_create_empty_polynom) {
	ASSERT_NO_THROW(TPolynom polynom);
}

TEST(TPolynom, can_create_polynom) {
	ASSERT_NO_THROW(TPolynom polynom("6*x^3*y^2*z"));
}

TEST(TPolynom, throws_when_polynom_contains_invalid_characters) {
	ASSERT_ANY_THROW(TPolynom polynom("6?x^3*y^2*z"));
}

TEST(TPolynom, throws_when_polynom_contains_repetitive_operators) {
	ASSERT_ANY_THROW(TPolynom polynom("6**x^3*y^2*z"));
}

TEST(TPolynom, can_cancellate_polynom) {
	TPolynom p1("6*x^3*y^2*z+3*x^3*y^2*z+0*x^3*y^2*z");
	TPolynom p2("9*x^3*y^2*z");
	EXPECT_EQ(p1, p2);
}

TEST(TPolynom, can_copy_polynom) {
	TPolynom p1("6*x^3*y^2*z");
	TPolynom p2(p1);
	EXPECT_EQ(p1, p2);
}

TEST(TPolynom, can_assign_polynom) {
	TPolynom p1("6*x^3*y^2*z");
	TPolynom p2 = p1;
	EXPECT_EQ(p1, p2);
}

TEST(TPolynom, can_calculate_polynom) {
	TPolynom p1("6*x^3*y^2*z");
	EXPECT_EQ(p1(1, 2, 3), 72);
}

TEST(TPolynom, can_compare_equal_polynoms) {
	TPolynom p1("6*x^2*z^3-3.1*x^3*y^2*z");
	TPolynom p2("6*x^2*z^3-3.1*x^3*y^2*z");
	EXPECT_TRUE(p1 == p2);
}

TEST(TPolynom, can_compare_not_equal_polynoms) {
	TPolynom p1("6*x^2*z^3-3.1*x^3*y^2*z");
	TPolynom p2("-16*x^2*z^3+3.5*x^3*y^2*z");
	EXPECT_FALSE(p1 == p2);
}

TEST(TPolynom, can_add_polynoms) {
	TPolynom p1("6*x^2*z^3-3*x^3*y^2*z+17*x-3.14");
	TPolynom p2("-16*x^2*z^3+3.5*x^3*y^2*z+x*y");
	TPolynom p3("0.5*x^3*y^2*z-10*x^2*z^3+x*y+17*x-3.14");
	EXPECT_EQ(p1 + p2, p3);
}

TEST(TPolynom, can_subtract_polynoms) {
	TPolynom p1("6*x^2*z^3-3.1*x^3*y^2*z+17*x-3.14");
	TPolynom p2("-16*x^2*z^3+3.5*x^3*y^2*z+x*y");
	TPolynom p3("-6.6*x^3*y^2*z+22*x^2*z^3-x*y+17*x-3.14");
	EXPECT_EQ(p1 - p2, p3);
}

TEST(TPolynom, difference_of_equal_polynoms_returns_zero) {
	TPolynom p1("6*x^2*z^3-3.1*x^3*y^2*z+17*x-3.14");
	TPolynom p2("6*x^2*z^3-3.1*x^3*y^2*z+17*x-3.14");
	TPolynom p3("0");
	EXPECT_EQ(p1 - p2, p3);
}

TEST(TPolynom, can_multiply_polynoms) {
	TPolynom p1("6*x^2*z^3-3.1*x^3*y^2*z+17*x-3.14");
	TPolynom p2("-16*x^2*z^3+3.5*x^3*y^2*z+x*y");
	TPolynom p3("-10.85*x^6*y^4*z^2+70.6*x^5*y^2*z^4-3.1*x^4*y^3*z+59.5*x^4*y^2*z-96*x^4*z^6-10.99*x^3*y^2*z+6*x^3*y*z^3-272*x^3*z^3+17*x^2*y+50.24*x^2*z^3-3.14*x*y");
	EXPECT_EQ(p1 * p2, p3);
}

TEST(TPolynom, throws_when_multiplication_degree_out_of_range) {
	TPolynom p1("6*x^9*y^2*z^3");
	TPolynom p2("12*x^9*y^6*z^5");
	ASSERT_ANY_THROW(p1 * p2);
}

TEST(TPolynom, can_differentiate_polynom_with_respect_to_x) {
	TPolynom p1("6*x^2*z^3-3.1*x^3*y^2*z+17*x-3.14");
	TPolynom p2("-9.3*x^2*y^2*z+12*x*z^3+17");
	EXPECT_EQ(p1.dx(), p2);
}

TEST(TPolynom, can_differentiate_polynom_with_respect_to_y) {
	TPolynom p1("6*x^2*z^3-3.1*x^3*y^2*z+17*x-3.14");
	TPolynom p2("-6.2*x^3*y*z");
	EXPECT_EQ(p1.dy(), p2);
}

TEST(TPolynom, can_differentiate_polynom_with_respect_to_z) {
	TPolynom p1("6*x^2*z^3-3.1*x^3*y^2*z+17*x-3.14");
	TPolynom p2("-3.1*x^3*y^2+18*x^2*z^2");
	EXPECT_EQ(p1.dz(), p2);
}