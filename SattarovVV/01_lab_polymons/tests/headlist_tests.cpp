#include <gtest.h>
#include "headlist.h"
#include "monom.h"

TEST(THeadList, CanCreateNewList)
{
	ASSERT_NO_THROW(THeadList t);
}

TEST(THeadList, CanCleanEmptyList)
{
	THeadList t;
	ASSERT_NO_THROW(t.Clear());
}

TEST(TList, CanInsertFirst)
{
	TList t;
	TMonom* a = new TMonom(1, 1);
	TMonom* b = new TMonom(2, 2);

	t.InsertToHead(a);
	t.InsertToHead(b);

	EXPECT_EQ(2, ((TMonom*)t.GetCur()->data)->coeff);
}

TEST(THeadList, CanRemoveHead)
{
	THeadList t;
	TMonom* a = new TMonom(1, 1);

	t.InsertToHead(a);
	ASSERT_NO_THROW(t.RemoveFirst());
}

TEST(THeadList, CanRemoveFirst)
{
	THeadList t;
	TMonom* a = new TMonom(1, 1);
	TMonom* b = new TMonom(2, 2);

	t.InsertToHead(a);
	t.InsertToHead(b);
	ASSERT_NO_THROW(t.RemoveFirst());
}