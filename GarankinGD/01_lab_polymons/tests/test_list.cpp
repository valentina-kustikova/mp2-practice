#include "gtest.h"
#include "CList.h"

TEST(lists, create_empty_list)
{
	ASSERT_NO_THROW(CList<double> m);
}

class List : public ::testing::Test {
protected:
	CList<int> l;
	CList<int> l2;

public:
	List()
	{
		l2.InsertCList(10);
		l2.InsertCList(20);
	}

	~List() {}
};

TEST_F(List, created_empty_list_is_correct)
{
	EXPECT_EQ(true, l.Empty());
}

TEST_F(List, copy_empty_list)
{
	ASSERT_NO_THROW(CList<int> m(l));
}

TEST_F(List, copied_empty_list_is_correct)
{
	CList<int> m(l);
	EXPECT_EQ(true, m.Empty());
}

TEST_F(List, assign_empty_list)
{
	ASSERT_NO_THROW(CList<int> m = l);
}

TEST_F(List, assigned_empty_list_is_correct)
{
	CList<int> m = l;
	EXPECT_EQ(true, m.Empty());
}

TEST_F(List, insert_in_empty_list)
{
	ASSERT_NO_THROW(l.InsertCList(5));
}

TEST_F(List, insert_in_empty_list_is_correct)
{
	l.InsertCList(5);
	l.First();
	EXPECT_EQ(5, l.GetCurr());
	l.Change();
	l.Change();
	EXPECT_EQ(l.GetCurr(), l.GetCurr());
}

TEST_F(List, compare_list_with_itself)
{
	EXPECT_EQ(true, l == l);
}

TEST_F(List, empty_lists_are_equal)
{
	CList<int> m(l);
	EXPECT_EQ(true, m == l);
}

TEST_F(List, copy_full_list)
{
	ASSERT_NO_THROW(CList<int> m(l2));
}

TEST_F(List, copied_full_list_is_correct)
{
	CList<int> m(l2);
	m.First();
	EXPECT_EQ(10, m.GetCurr());
	m.Change();
	EXPECT_EQ(20, m.GetCurr());
}

TEST_F(List, assign_full_list)
{
	ASSERT_NO_THROW(CList<int> m = l2);
}

TEST_F(List, insert_in_the_beginning)
{
	l2.InsertCList(0);
	l2.First();
	EXPECT_EQ(0, l2.GetCurr());
	l2.Change();
	EXPECT_EQ(10, l2.GetCurr());
	l2.First();
	EXPECT_EQ(0, l2.GetCurr());
}

TEST_F(List, insert_in_the_middle)
{
	l2.InsertCList(15);
	l2.First();
	EXPECT_EQ(10, l2.GetCurr());
	l2.Change();
	EXPECT_EQ(15, l2.GetCurr());
	EXPECT_EQ(15, l2.GetCurr());
}

TEST_F(List, insert_in_the_end)
{
	l2.InsertToTail(5);
	l2.First();
	EXPECT_EQ(10, l2.GetCurr());
	l2.Change();
	EXPECT_EQ(20, l2.GetCurr());
	l2.Change();
	EXPECT_EQ(5, l2.GetCurr());
}

TEST_F(List, full_lists_are_equal)
{
	CList<int> m(l2);
	EXPECT_EQ(true, m == l2);
}

TEST_F(List, empty_and_full_lists_are_not_equal)
{
	EXPECT_NE(true, l2 == l);
}

TEST_F(List, lists_with_different_sizes_and_same_beginnings_are_not_equal)
{
	l.InsertCList(1);
	EXPECT_NE(true, l2 == l);
}