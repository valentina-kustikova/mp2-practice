#include<gtest.h>

#include "tmonom.h"

TEST(TMonom, can_create_empty_monom)
{
	ASSERT_NO_THROW(TMonom monom);
}

TEST(TMonom, check_correct_empty_monom)
{
	TMonom monom;
	monom.st = 0;
	EXPECT_EQ(monom.st, int());
}


TEST(TMonom, can_create_monom_with_parametrs)
{
	int tmp_st = 654;
	double tmp_coef = 34.2;
	ASSERT_NO_THROW(TMonom mn(tmp_st, tmp_coef));
}

TEST(TMonom, check_correct_create_monom_with_parametrs)
{
	int tmp_st = 654;
	double tmp_coef = 34.2;
	TMonom mn(tmp_st, tmp_coef);
	EXPECT_EQ(mn.st, 654);
}


