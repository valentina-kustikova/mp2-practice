#include <gtest.h>
#include "scantable.h"

TEST(scantable, test_sc_1)
{
	ASSERT_NO_THROW(scantable h(5));
}

TEST(scantable, test_sc_2)
{
	scantable h;
	polinom p("x");
	ASSERT_NO_THROW(h.insRecord("x", p));
}

TEST(scantable, test_sc_3)
{
	scantable h;
	polinom p("x");
	h.insRecord("x", p);
	EXPECT_EQ(p, *h.findRecord("x"));
}

TEST(scantable, test_sc_4)
{
	scantable h;
	polinom p("x");
	h.delRecord("x");
	EXPECT_EQ(NULL, h.findRecord("x"));
}

TEST(scantable, test_sc_5)
{
	scantable h;
	polinom p("x");
	ASSERT_NO_THROW(h.findRecord("x"));
}