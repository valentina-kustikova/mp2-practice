#include <gtest.h>
#include "Ringlist.h"

TEST(node, test_n_1)
{
	ASSERT_NO_THROW(node<int> l);
}

TEST(node, test_n_2)
{
	node<int> n(1);
	ASSERT_NO_THROW(node<int> l(n));
}

TEST(node, test_n_3)
{
	node<int> n(1);
	node<int> l(n);
	EXPECT_EQ(n, l);
}

TEST(node, test_n_4)
{
	node<int> n(1);
	node<int> l;
	l = n;
	EXPECT_EQ(n, l);
}

TEST(ringlist, test_r_1)
{
	ASSERT_NO_THROW(ringlist<int> l);
}

TEST(ringlist, test_r_2)
{
	ringlist<int> l1;
	l1.insert_to_tail(1);
	l1.insert_to_tail(3);
	l1.insert_to_tail(2);
	ASSERT_NO_THROW(ringlist<int> l(l1));
	ringlist<int> l(l1);
	EXPECT_EQ(l1, l);
}

TEST(ringlist, test_r_3)
{
	ringlist<int> l1;
	l1.insert_to_tail(1);
	l1.insert_to_tail(3);
	l1.insert_to_tail(2);
	ringlist<int> l(l1);
	EXPECT_EQ(l1, l);
}

TEST(ringlist, test_r_4)
{
	ringlist<int> l1;
	l1.insert_to_tail(1);
	l1.insert_to_tail(3);
	l1.insert_to_tail(2);
	ringlist<int> l;
	l = l1;
	EXPECT_EQ(l1, l);
}

TEST(ringlist, test_r_5)
{
	ringlist<int> l1;
	l1.insert_to_tail(1);
	l1.insert_to_tail(3);
	l1.insert_to_tail(2);
	l1.elemdelete(3);
	EXPECT_EQ(NULL, l1.search(3));
}

TEST(ringlist, test_r_6)
{
	ringlist<int> l1;
	l1.insert_to_tail(1);
	l1.insert_to_tail(3);
	l1.insert_to_tail(2);
	node<int>* t = l1.search(3);
	l1.elemdelete(t);
	EXPECT_EQ(NULL, l1.search(3));
}

TEST(ringlist, test_r_7)
{
	ringlist<int> l1;
	l1.insert_to_tail(1);
	l1.insert_to_tail(3);
	l1.insert_to_tail(2);
	l1.insert_to_tail(4);
	EXPECT_EQ(4, l1.search(4)->data);
}

TEST(ringlist, test_r_8)
{
	ringlist<int> l1;
	l1.insert_to_tail(1);
	l1.insert_to_tail(2);
	l1.insert_to_tail(4);
	l1.insertup(3);
	EXPECT_EQ(3, l1.search(3)->data);
}

TEST(ringlist, test_r_9)
{
	ringlist<int> l1;
	l1.insert_to_tail(1);
	l1.insert_to_tail(2);
	l1.insert_to_tail(4);
	l1.gotohead();
	EXPECT_EQ(0, l1.getnowdata());
}

TEST(ringlist, test_r_10)
{
	ringlist<int> l1;
	l1.insert_to_tail(1);
	l1.insert_to_tail(2);
	l1.insert_to_tail(4);
	l1.gotohead();
	l1.gotonext();
	EXPECT_EQ(1, l1.getnowdata());
}

TEST(ringlist, test_r_11)
{
	ringlist<int> l1;
	l1.insert_to_tail(1);
	l1.insert_to_tail(2);
	l1.insert_to_tail(4);
	l1.gotohead();
	l1.gotonext();
	l1.gotonext();
	l1.gotonext();
	l1.gotonext();
	EXPECT_EQ(true, l1.nowhead());
}

TEST(ringlist, test_r_12)
{
	ringlist<int> l1;
	l1.insert_to_tail(1);
	l1.insert_to_tail(2);
	l1.insert_to_tail(4);
	l1.gotohead();
	l1.gotonext();
	l1.gotonext();
	EXPECT_EQ(false, l1.nowhead());
}

TEST(ringlist, test_r_13)
{
	ringlist<int> l1;
	l1.insert_to_tail(1);
	l1.insert_to_tail(2);
	l1.insert_to_tail(4);
	l1.cleanlist();
	l1.gotohead();
	l1.gotonext();
	EXPECT_EQ(true, l1.nowhead());
}