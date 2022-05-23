#include "gtest.h"
#include "Polinom.h"
/*
TEST(TMonom, can_create_empty_monom)
{
	ASSERT_NO_THROW(TMonom m);
}
TEST(TMonom, can_create_monom)
{
	ASSERT_NO_THROW(TMonom m(1, 123));
}
TEST(TMonom, can_not_create_monom_degree_more_999)
{
	ASSERT_ANY_THROW(TMonom m(2, 1000));
}
TEST(TMonom, can_compare_monoms)
{
	TMonom m(1, 123);
	TMonom b(1, 123);
	EXPECT_EQ(m, b);
}
TEST(TMonom, can_compare2_monoms)
{
	TMonom m(1, 123);
	TMonom b(2, 123);
	EXPECT_EQ(m < b, true);
}
TEST(TMonom, can_compare2_monoms2)
{
	TMonom m(1, 123);
	TMonom b(1, 223);
	EXPECT_EQ(m < b, true);
}
TEST(TMonom, can_compare3_monoms)
{
	TMonom m(2, 123);
	TMonom b(1, 123);
	EXPECT_EQ(m > b, true);
}
TEST(TMonom, can_compare3_monoms2)
{
	TMonom m(1, 223);
	TMonom b(1, 123);
	EXPECT_EQ(m > b, true);
}
TEST(TMonom, Mult_monom_and_const)
{
	TMonom m(1, 123);
	m = m * 2;
	TMonom b(2, 123);
	EXPECT_EQ(m, b);
}
/**/