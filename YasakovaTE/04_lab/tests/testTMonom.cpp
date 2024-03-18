#include "gtest.h"
#include "Polinom.h"
#include "Monom.h"

TEST(Monom, can_create_empty_monom)
{
	ASSERT_NO_THROW(Monom m);
}
TEST(Monom, can_create_monom)
{
	ASSERT_NO_THROW(Monom m(1, 123));
}

TEST(Monom, can_compare_monoms)
{
	Monom m(1, 123);
	Monom b(1, 123);
	EXPECT_EQ(m, b);
}

TEST(Monom, can_compare2_monoms2)
{
	Monom m(1, 123);
	Monom b(1, 223);
	EXPECT_EQ(m < b, true);
}

TEST(Monom, can_compare3_monoms2)
{
	Monom m(1, 223);
	Monom b(1, 123);
	EXPECT_EQ(m > b, true);
}
