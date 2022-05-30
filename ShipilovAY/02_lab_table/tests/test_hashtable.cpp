#include <gtest.h>
#include <string>
#include "ListHash.h"
#include "HashTable.h"
TEST(ListHash, ListHash_cannot_be_isempty)
{
	using ListHash = ListHash<std::string, string>;
	ASSERT_ANY_THROW(ListHash A(-5));
}

TEST(ListHash, ListHash_can_be_with_size)
{
	using ListHash = ListHash<std::string, string>;
	ASSERT_NO_THROW(ListHash(5));
}

TEST(ListHash, cannot_SetNext_isempty)
{
	ListHash<string, string> A;
	A.Reset();
	ASSERT_NO_THROW(A.SetNext());
}

TEST(ListHash, copy_isempty)
{
	using ListHash = ListHash<std::string, string>;
	ListHash A;
	ASSERT_NO_THROW(ListHash (A));
}

TEST(ListHash, correct_isempty_isEnd)
{
	ListHash<string, string> A;
	A.Reset();
	EXPECT_EQ(true, A.IsEnd());
}

TEST(ListHash, isempty_GetData_nullptr)
{
	ListHash<string, string> A;
	A.Reset();
	EXPECT_EQ(nullptr, A.GetData());
}

TEST(ListHash, isempty_GetKey_default)
{
	ListHash<string, string> A;
	A.Reset();
	EXPECT_EQ(string(), A.GetKey());
}

TEST(ListHash, correct_GetKey)
{
	ListHash<string, string> A;
	string a1 = "x";
	string a2 = "1";
	A.Insert(a1, a2);
	A.Reset();
	EXPECT_EQ(a2, A.GetKey());
}

TEST(ListHash, correct_GetData)
{
	ListHash<string, string> A;
	string a1 = "x";
	string a2 = "1";
	A.Insert(a1, a2);
	A.Reset();
	EXPECT_EQ(a1, *A.GetData());
}

TEST(ListHash, after_Delete_isempty)
{
	ListHash<string, string> A;
	string a1 = "x";
	string a2 = "1";
	A.Insert(a1, a2);
	A.Delete(a2);
	EXPECT_TRUE(A.IsEmpty());
}

TEST(ListHash, correct_Insert_after_delete)
{
	ListHash<string, string> A;
	string a1 = "x";
	string a2 = "1";
	string b1 = "y";
	string b2 = "2";
	string c1 = "z";
	string c2 = "3";
	string d = "4";
	A.Insert(a1, a2);
	A.Insert(b1, b2);
	A.Insert(c1, c2);
	A.Delete(b2);
	A.Insert(b1, d);
	A.Reset(); A.SetNext();
	EXPECT_EQ(d, A.GetKey());
}

TEST(ListHash, correct_Delete)
{
	ListHash<string, string> A(5);
	A.Insert("x", "1");
	A.Insert("y", "2");
	A.Insert("z", "3");
	A.Insert("x^2", "4");
	A.Insert("y^2", "5");
	A.Delete("3");
	EXPECT_EQ(nullptr, A.Search("3"));
}

TEST(ListHash, throw_Delete_no_key)
{
	ListHash<string, string> A;(7);
	A.Insert("x", "1");
	A.Insert("z", "3");
	A.Insert("y", "2");
	A.Insert("x^2", "4");
	A.Insert("z^2", "6");
	A.Insert("x^2y", "7");
	ASSERT_ANY_THROW(A.Delete("5"));
}