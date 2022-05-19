#include <gtest.h>
#include <string>
#include "AVLTreeTable.h"

TEST(TreeTable, cant_goNext_empty_table)
{
	TreeTable<char, int> A;
	A.Reset();
	ASSERT_NO_THROW(A.goNext());
}

TEST(TreeTable, empty_table_getKey_is_default_value)
{
	TreeTable<char, int> A;
	A.Reset();
	EXPECT_EQ(char(), A.getKey());
}

TEST(TreeTable, empty_table_getData_is_nullptr)
{
	TreeTable<char, int> A;
	A.Reset();
	EXPECT_EQ(nullptr, A.getData());
}

TEST(TreeTable, empty_table_isEnd_correct)
{
	TreeTable<char, int> A;
	A.Reset();
	EXPECT_EQ(true, A.isEnd());
}

TEST(TreeTable, getKey_correct)
{
	TreeTable<char, int> A;
	A.Insert('a', 1);
	A.Reset();
	EXPECT_EQ('a', A.getKey());
}

TEST(TreeTable, getData_correct)
{
	TreeTable<char, int> A;
	A.Insert('a', 1);
	A.Reset();
	EXPECT_EQ(1, *A.getData());
}

TEST(TreeTable, empty_after_delete)
{
	TreeTable<char, int> A;
	A.Insert('a', 1);
	A.Delete('a');
	EXPECT_TRUE(A.isEmpty());
}

TEST(TreeTable, correct_insert_after_delete)
{
	TreeTable<char, int> A;
	A.Insert('a', 1);
	A.Insert('b', 2);
	A.Insert('c', 3);
	A.Delete('b');
	A.Insert('b', 100);
	A.Reset(); A.goNext(); //A.goNext();
	EXPECT_EQ(100, *A.getData());
}

TEST(TreeTable, insert_correct)
{
	TreeTable<std::string, int> H;
	H.Insert("first", 1);
	EXPECT_NE(nullptr, H.Find("first"));
}

TEST(TreeTable, delete_correct)
{
	TreeTable<std::string, int> H;
	H.Insert("first", 1);
	H.Insert("second", 2);
	H.Insert("third", 3);
	H.Insert("fourth", 4);
	H.Insert("fifth", 5);
	EXPECT_TRUE(H.Delete("third"));
	EXPECT_EQ(nullptr, H.Find("third"));
}

TEST(TreeTable, delete_when_no_key)
{
	TreeTable<std::string, int> S;
	S.Insert("a", 1);
	S.Insert("b", 3);
	S.Insert("c", 2);
	S.Insert("d", 4);
	S.Insert("f", 6);
	S.Insert("e", 5);
	S.Insert("g", 7);
	EXPECT_FALSE(S.Delete("z"));
}

TEST(TreeTable, clear_correct)
{
	TreeTable<char, int> S;
	S.Insert('a', 1);
	S.Insert('c', 3);
	S.Insert('b', 2);
	S.Insert('d', 4);
	S.Insert('f', 6);
	S.Insert('e', 5);
	S.Insert('g', 7);
	S.Clear();
	EXPECT_TRUE(S.isEmpty());
}