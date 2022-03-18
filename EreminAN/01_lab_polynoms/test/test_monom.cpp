#include <gtest.h>
#include "Polynom.h"
#include "Monom.h"
TEST(Monom, can_create_monom)
{
	ASSERT_NO_THROW(Monom M);
}

TEST(Monom, can_create_monom_with_value_1)
{
	ASSERT_NO_THROW(Monom M(2, 1, 2, 3));
}

TEST(Monom, can_create_monom_with_value_2)
{
	ASSERT_NO_THROW(Monom M(-12, 1, 2, 3));
}

TEST(Monom, can_create_monom_with_value_3)
{
	ASSERT_NO_THROW(Monom M(-12, 0, 2, 0));
}

TEST(Monom, can_create_monom_with_value_4)
{
	ASSERT_NO_THROW(Monom M(0, 9, 2, 5));
}

TEST(Monom, can_create_monom_with_double_value)
{
	ASSERT_NO_THROW(Monom M(-1.2, 1, 2, 3));
}

TEST(Monom, not_can_create_monom_with_negative_degreeX)
{
	ASSERT_ANY_THROW(Monom M(2, -2, 1, 3));
}

TEST(Monom, not_can_create_monom_with_negative_degreeY)
{
	ASSERT_ANY_THROW(Monom M(8, 1, -2, 3));
}

TEST(Monom, not_can_create_monom_with_negative_degreeZ)
{
	ASSERT_ANY_THROW(Monom M(2, 1, 2, -3));
}

TEST(Monom, can_create_monom_copy)
{
	Monom M;
	ASSERT_NO_THROW(Monom Mon(M));
}

TEST(Monom, can_compare_1)
{
	Monom M(2, 1, 2, 3);
	Monom Mon(2, 1, 2, 3);
	ASSERT_EQ(M, Mon);
}

TEST(Monom, can_compare_2)
{
	Monom M(2, 1, 2, 0);
	Monom Mon(2, 1, 2, 0);
	ASSERT_EQ(M, Mon);
}

TEST(Monom, can_compare_3)
{
	Monom M(2, 1, 2, 3);
	Monom Mon(2, 2, 2, 3);
	ASSERT_NE(M, Mon);
}

TEST(Monom, can_compare_4)
{
	Monom M(-2, 1, 2, 3);
	Monom Mon(2, 2, 2, 3);
	ASSERT_NE(M, Mon);
}

TEST(Monom, can_compare_5)
{
	Monom M(5, 1, 2, 3);
	Monom Mon(2, 1, 2, 3);
	ASSERT_NE(M, Mon);
}

TEST(Monom, copy_constructor_correctly)
{
	Monom M(1.2, 5, 9, 2);
	Monom Mon(M);
	ASSERT_EQ(M, Mon);
}

TEST(Monom, equality_operator)
{
	Monom M(1.2, 5, 9, 2);
	Monom Mon(0, 0, 0, 0);
	Mon = M;
	ASSERT_EQ(M, Mon);
}

TEST(Monom, function_coeff)
{
	Monom M(25, 5, 5, 10);
	double coeff = M.coeff();
	ASSERT_EQ(25, coeff);
}

TEST(Monom, function_degree)
{
	Monom M(10, 9, 5, 10);
	double coeff = M.degree();
	ASSERT_EQ(24, coeff);
}

TEST(Monom, function_degreeEq_1)
{
	Monom M(10, 9, 5, 10);
	Monom M2(2.5, 9, 5, 10);
	ASSERT_EQ(1, M2.degreeEq(M));
}

TEST(Monom, function_degreeEq_2)
{
	Monom M(-85, 9, 99, 10);
	Monom M2(2.5, 9, 99, 10);
	ASSERT_EQ(1, M2.degreeEq(M));
}

TEST(Monom, function_degreeEq_3)
{
	Monom M(-85, 9, 5, 10);
	Monom M2(2.5, 9, 2, 10);
	ASSERT_EQ(0, M2.degreeEq(M));
}

//////////////////////////////////////////
TEST(Monom, addition_monom_no_throw_1)
{
	Monom M1(2, 2, 5, 10);
	Monom M2(5, 2, 5, 10);
	ASSERT_NO_THROW(M1 + M2);
}

TEST(Monom, addition_monom_no_throw_2)
{
	Monom M1(2, 1, 8, 5);
	Monom M2(-5, 1, 8, 5);
	ASSERT_NO_THROW(M1 + M2);
}

TEST(Monom, addition_monom_no_throw_3)
{
	Monom M1(-6, 10, 8, 5);
	Monom M2(-5, 10, 8, 5);
	ASSERT_NO_THROW(M1 + M2);
}

TEST(Monom, addition_monom_no_throw_4)
{
	Monom M1(-6, 6, 1, 2);
	Monom M2(0, 6, 1, 2);
	ASSERT_NO_THROW(M1 + M2);
}

TEST(Monom, addition_monom_no_throw_5)
{
	Monom M1(-6.6, 6, 1, 2);
	Monom M2(0.9, 6, 1, 2);
	ASSERT_NO_THROW(M1 + M2);
}

TEST(Monom, addition_monom_no_throw_6)
{
	Monom M1(0.2, 0, 0, 0);
	ASSERT_NO_THROW(M1 + 5);
}

TEST(Monom, addition_monom_any_throw_1)
{
	Monom M1(-6.6, 5, 1, 2);
	Monom M2(0.9, 6, 1, 2);
	ASSERT_ANY_THROW(M1 + M2);
}

TEST(Monom, addition_monom_any_throw_2)
{
	Monom M1(-6.6, 5, 1, 2);
	Monom M2(0.9, 5, 5, 2);
	ASSERT_ANY_THROW(M1 + M2);
}

TEST(Monom, addition_monom_any_throw_4)
{
	Monom M1(9, 5, 5, 25);
	Monom M2(5, 5, 5, 2);
	ASSERT_ANY_THROW(M1 + M2);
}

TEST(Monom, addition_monom_any_throw_5)
{
	Monom M1(0.2, 0, 5, 0);
	ASSERT_ANY_THROW(M1 + 2);
}

TEST(Monom, addition_monom_1)
{
	Monom M1(2, 2, 5, 10);
	Monom M2(5, 2, 5, 10);
	Monom Res(7, 2, 5, 10);
	ASSERT_EQ(Res, M1 + M2);
}

TEST(Monom, addition_monom_2)
{
	Monom M1(0.2, 2, 5, 1);
	Monom M2(5, 2, 5, 1);
	Monom Res(5.2, 2, 5, 1);
	ASSERT_EQ(Res, M1 + M2);
}

TEST(Monom, addition_monom_3)
{
	Monom M1(-3.6, 2, 5, 1);
	Monom M2(-5.2, 2, 5, 1);
	Monom Res(-8.8, 2, 5, 1);
	ASSERT_EQ(Res, M1 + M2);
}

TEST(Monom, addition_monom_4)
{
	Monom M1(-3.6, 2, 5, 1);
	Monom M2(0, 2, 5, 1);
	Monom Res(-3.6, 2, 5, 1);
	ASSERT_EQ(Res, M1 + M2);
}

TEST(Monom, addition_monom_5)
{
	Monom M1(5, 0, 0, 0);
	Monom Res(10, 0, 0, 0);
	ASSERT_EQ(Res, M1 + 5);
}

TEST(Monom, addition_monom_6)
{
	Monom M1(-5, 0, 0, 0);
	Monom Res(0, 0, 0, 0);
	ASSERT_EQ(Res, M1 + 5);
}
//////////////////////////////////////////
TEST(Monom, minus_monom_no_throw_1)
{
	Monom M1(-6.6, 5, 1, 2);
	Monom M2(0.9, 5, 1, 2);
	ASSERT_NO_THROW(M1 - M2);
}

TEST(Monom, minus_monom_no_throw_2)
{
	Monom M1(2, 5, 1, 2);
	Monom M2(-5.5, 5, 1, 2);
	ASSERT_NO_THROW(M1 - M2);
}

TEST(Monom, minus_monom_no_throw_3)
{
	Monom M1(2, 0, 0, 0);
	ASSERT_NO_THROW(M1 - 3.2);
}

TEST(Monom, minus_monom_any_throw_1)
{
	Monom M1(2, 5, 5, 2);
	Monom M2(-5.5, 6, 1, 2);
	ASSERT_ANY_THROW(M1 - M2);
}

TEST(Monom, minus_monom_any_throw_2)
{
	Monom M1(2, 5, 5, 8);
	Monom M2(-5.5, 6, 1, 2);
	ASSERT_ANY_THROW(M1 - M2);
}

TEST(Monom, minus_monom_any_throw_3)
{
	Monom M1(2, 0, 5, 0);
	ASSERT_ANY_THROW(M1 - 5);
}

TEST(Monom, minus_monom_1)
{
	Monom M1(5, 1, 2, 3);
	Monom M2(9, 1, 2, 3);
	Monom Res(-4, 1, 2, 3);
	ASSERT_EQ(Res, M1 - M2);
}

TEST(Monom, minus_monom_2)
{
	Monom M1(5, 1, 2, 3);
	Monom M2(9, 1, 2, 3);
	Monom Res(-4, 1, 2, 3);
	ASSERT_EQ(Res, M1 - M2);
}

TEST(Monom, minus_monom_3)
{
	Monom M1(1.5, 1, 2, 3);
	Monom M2(-6.2, 1, 2, 3);
	Monom Res(7.7, 1, 2, 3);
	ASSERT_EQ(Res, M1 - M2);
}

TEST(Monom, minus_monom_4)
{
	Monom M1(0, 1, 2, 3);
	Monom M2(-6.2, 1, 2, 3);
	Monom Res(6.2, 1, 2, 3);
	ASSERT_EQ(Res, M1 - M2);
}

TEST(Monom, minus_monom_5)
{
	Monom M1(5.5, 0, 0, 0);
	Monom Res(0.5, 0, 0, 0);
	ASSERT_EQ(Res, M1 - 5);
}
//////////////////////////////////////////
TEST(Monom, multiplication_monom_no_throw_1)
{
	Monom M1(2, 1, 2, 3);
	Monom M2(3, 3, 2, 1);
	ASSERT_NO_THROW(M1 * M2);
}

TEST(Monom, multiplication_monom_no_throw_2)
{
	Monom M1(-2, 1, 2, 3);
	Monom M2(3.6, 3, 2, 1);
	ASSERT_NO_THROW(M1 * M2);
}

TEST(Monom, multiplication_monom_no_throw_3)
{
	Monom M1(-2, 1, 2, 3);
	ASSERT_NO_THROW(M1 * 3);
}

TEST(Monom, multiplication_monom_1)
{
	Monom M1(5, 1, 2, 3);
	Monom M2(5, 3, 2, 1);
	Monom Res(25, 4, 4, 4);
	ASSERT_EQ(Res, M1 * M2);
}

TEST(Monom, multiplication_monom_2)
{
	Monom M1(-5.2, 1, 10, 3);
	Monom M2(5, 3, 2, 1);
	Monom Res(-26, 4, 12, 4);
	ASSERT_EQ(Res, M1 * M2);
}

TEST(Monom, multiplication_monom_3)
{
	Monom M1(-5.2, 1, 10, 3);
	Monom M2(-5, 3, 2, 1);
	Monom Res(26, 4, 12, 4);
	ASSERT_EQ(Res, M1 * M2);
}

TEST(Monom, multiplication_monom_4)
{
	Monom M1(-5.2, 1, 10, 3);
	Monom M2(0, 3, 2, 1);
	Monom Res(0, 4, 12, 4);
	ASSERT_EQ(Res, M1 * M2);
}

TEST(Monom, multiplication_monom_5)
{
	Monom M1(-5.2, 1, 10, 3);
	Monom Res(0, 1, 10, 3);
	ASSERT_EQ(Res, M1 * 0);
}

TEST(Monom, multiplication_monom_6)
{
	Monom M1(-5.2, 1, 10, 3);
	Monom Res(-28.6, 1, 10, 3);
	ASSERT_EQ(Res, M1 * 5.5);
}
//////////////////////////////////////////
TEST(Monom, can_create_Lexema)
{
	ASSERT_NO_THROW(Lexema lexem1(LEX_VAR, LEX_NULL, "z"));
}

