#include <gtest.h>
#include "hashtable.h"

TEST(hashtable, test_h_1)
{
	ASSERT_NO_THROW(hashtable h);
}

TEST(hashtable, test_h_2)
{
	hashtable h;
	polinom p("x");
	ASSERT_NO_THROW(h.insRecord("x", p));
}

TEST(hashtable, test_h_3)
{
	hashtable h;
	polinom p("x");
	h.insRecord("x", p);
	EXPECT_EQ(p, *h.findRecord("x"));
}

TEST(hashtable, test_h_4)
{
	hashtable h;
	polinom p("x");
	h.delRecord("x");
	EXPECT_EQ(NULL, h.findRecord("x"));
}

TEST(hashtable, test_h_5)
{
	hashtable h;
	polinom p("x");
	ASSERT_NO_THROW(h.findRecord("x"));
}