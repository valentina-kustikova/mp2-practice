#include <gtest.h>
#include "sorttable.h"

TEST(sorttable, test_st_1)
{
	ASSERT_NO_THROW(sorttable h(5));
}

TEST(sorttable, test_st_2)
{
	sorttable h;
	polinom p("x");
	ASSERT_NO_THROW(h.insRecord("x", p));
}

TEST(sorttable, test_st_3)
{
	sorttable h;
	polinom p("x");
	h.insRecord("x", p);
	EXPECT_EQ(p, *h.findRecord("x"));
}

TEST(sorttable, test_st_4)
{
	sorttable h;
	polinom p("x");
	h.delRecord("x");
	EXPECT_EQ(NULL, h.findRecord("x"));
}

TEST(sorttable, test_st_5)
{
	sorttable h;
	polinom p("x");
	ASSERT_NO_THROW(h.findRecord("x"));
}