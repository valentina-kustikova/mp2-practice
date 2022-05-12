#include <gtest.h>
#include "data.h"
#include "monom.h"
#include "list.h"
#include "node.h"


TEST(TList, CanCreateNewList)
{
	ASSERT_NO_THROW(TList t);
}

TEST(TList, NewCreatedListIsEmpty)
{
	TList t;
	ASSERT_TRUE(t.IsEmpty());
}

TEST(TList, NotEmptyListIsNotEmpty)
{
	TList t;
	TMonom* a = new TMonom(1, 1);

	t.InsertToTail(a);

	ASSERT_TRUE(!t.IsEmpty());
}

TEST(TList, CanInsertElementToEmptyList)
{
	TList t;
	TMonom* a = new TMonom(1, 1);
	ASSERT_NO_THROW(t.InsertToHead(a));
}

TEST(TList, CanInsertElementToNotEmptyList)
{
	TList t;
	TMonom* a = new TMonom(1, 1);
	TMonom* b = new TMonom(2, 2);
	t.InsertToHead(a);

	ASSERT_NO_THROW(t.InsertToHead(b));
}

TEST(TList, CanAddToTail)
{
	TList t;
	TMonom* a = new TMonom(1, 1);
	ASSERT_NO_THROW(t.InsertToTail(a));
}

TEST(TList, CanAddToTail2)
{
	TList t;
	TMonom* a = new TMonom(1, 1);
	TMonom* b = new TMonom(2, 2);
	TMonom* c = new TMonom(3, 3);
	t.InsertToTail(a);
	t.InsertToTail(b);
	t.InsertToTail(c);
	t.Next();
	EXPECT_EQ(2, ((TMonom*)t.GetCur()->data)->coeff);
}


TEST(TList, CanCleanEmptyList)
{
	TList t;
	ASSERT_NO_THROW(t.Clear());
}

TEST(TList, CanClean)
{
	TList t;
	TMonom* a = new TMonom(1, 1);
	t.InsertToTail(a);
	ASSERT_NO_THROW(t.Clear());
}

TEST(TList, CanClean2)
{
	TList t;
	TMonom* a = new TMonom(1, 1);
	TMonom* b = new TMonom(2, 2);
	TMonom* c = new TMonom(3, 3);
	t.InsertToTail(a);
	t.InsertToTail(b);
	t.InsertToTail(c);
	t.Clear();
	EXPECT_EQ(true, t.IsEmpty());
}

TEST(TList, CanInsertCurrentElementWhenFirst)
{
	TList t;
	TMonom* a = new TMonom(1, 1);
	TMonom* b = new TMonom(2, 2);
	TMonom* c = new TMonom(3, 3);
	TMonom* d = new TMonom(4, 4);
	t.InsertToHead(a);
	t.InsertToHead(b);
	t.InsertToHead(c);

	t.InsertAfter(d, c);

	t.Next();
	EXPECT_EQ(4, ((TMonom*)t.GetCur()->data)->coeff);
}

TEST(TList, CanInsertCurrentElementWhenSecond)
{
	TList t;
	TMonom* a = new TMonom(1, 1);
	TMonom* b = new TMonom(2, 2);
	TMonom* c = new TMonom(3, 3);
	TMonom* d = new TMonom(4, 4);
	t.InsertToHead(a);
	t.InsertToHead(b);
	t.InsertToHead(c);
	t.InsertAfter(d, b);
	t.Next();
	t.Next();
	EXPECT_EQ(4, ((TMonom*)t.GetCur()->data)->coeff);
}

TEST(TList, CanInsertBeforeFirst)
{
	TList t;
	TMonom* a = new TMonom(1, 1);
	TMonom* b = new TMonom(2, 2);
	TMonom* c = new TMonom(3, 3);
	TMonom* d = new TMonom(4, 4);
	t.InsertToTail(a);
	t.InsertToTail(b);
	t.InsertToTail(c);
	t.InsertBefore(d, a);

	EXPECT_EQ(4, ((TMonom*)t.GetCur()->data)->coeff);
}

TEST(TList, CanInsertBeforeSecond)
{
	TList t;
	TMonom* a = new TMonom(1, 1);
	TMonom* b = new TMonom(2, 2);
	TMonom* c = new TMonom(3, 3);
	TMonom* d = new TMonom(4, 4);
	t.InsertToTail(a);
	t.InsertToTail(b);
	t.InsertToTail(c);
	t.InsertBefore(d, b);
	t.Next();
	EXPECT_EQ(4, ((TMonom*)t.GetCur()->data)->coeff);
}

TEST(TList, CanInsertAfterFirst)
{
	TList t;
	TMonom* a = new TMonom(1, 1);
	TMonom* b = new TMonom(2, 2);
	TMonom* c = new TMonom(3, 3);
	TMonom* d = new TMonom(4, 4);
	t.InsertToTail(a);
	t.InsertToTail(b);
	t.InsertToTail(c);
	t.InsertAfter(d, a);
	t.Next();

	EXPECT_EQ(4, ((TMonom*)t.GetCur()->data)->coeff);
}

TEST(TList, CanInsertAfterLast)
{
	TList t;
	TMonom* a = new TMonom(1, 1);
	TMonom* b = new TMonom(2, 2);
	TMonom* c = new TMonom(3, 3);
	TMonom* d = new TMonom(4, 4);
	t.InsertToTail(a);
	t.InsertToTail(b);
	t.InsertToTail(c);
	t.InsertAfter(d, c);
	t.Next();
	t.Next();
	t.Next();
	EXPECT_EQ(4, ((TMonom*)t.GetCur()->data)->coeff);
}

TEST(TList, CanDeleteFirstElement)
{
	TList t;
	TMonom* a = new TMonom(1, 1);
	TMonom* b = new TMonom(2, 2);
	TMonom* c = new TMonom(3, 3);
	TMonom* d = new TMonom(4, 4);
	t.InsertToTail(a);
	t.InsertToTail(b);
	t.InsertToTail(c);
	t.InsertToTail(d);
	t.RemoveFirst();
	EXPECT_EQ(2, ((TMonom*)t.GetCur()->data)->coeff);
}

TEST(TList, CanDeleteFirstElementWhenEmpty)
{
	TList t;
	ASSERT_NO_THROW(t.RemoveFirst());
}

TEST(TList, CanDelete2ElementsFirst)
{
	TList t;
	TMonom* a = new TMonom(1, 1);
	TMonom* b = new TMonom(2, 2);
	TMonom* c = new TMonom(3, 3);
	TMonom* d = new TMonom(4, 4);
	t.InsertToTail(a);
	t.InsertToTail(b);
	t.InsertToTail(c);
	t.InsertToTail(d);

	ASSERT_NO_THROW(t.RemoveFirst(););
	ASSERT_NO_THROW(t.RemoveFirst(););

}

TEST(TList, CanDeleteCurrentElementWhenSecond)
{
	TList t;
	TMonom* a = new TMonom(1, 1);
	TMonom* b = new TMonom(2, 2);
	TMonom* c = new TMonom(3, 3);
	TMonom* d = new TMonom(4, 4);
	t.InsertToTail(a);
	t.InsertToTail(b);
	t.InsertToTail(c);
	t.InsertToTail(d);

	ASSERT_NO_THROW(t.Remove(c));
	t.Next();
	t.Next();
	EXPECT_EQ(4, ((TMonom*)t.GetCur()->data)->coeff);
}

TEST(TList, CanDeleteLastElement)
{
	TList t;
	TMonom* a = new TMonom(1, 1);
	TMonom* b = new TMonom(2, 2);
	TMonom* c = new TMonom(3, 3);
	TMonom* d = new TMonom(4, 4);
	t.InsertToTail(a);
	t.InsertToTail(b);
	t.InsertToTail(c);
	t.InsertToTail(d);

	ASSERT_NO_THROW(t.RemoveLast());
}

TEST(TList, CanDeleteLastElementWhenEmpty)
{
	TList t;
	ASSERT_NO_THROW(t.RemoveLast());
}

TEST(TList, CanGetLenght)
{
	TList t;
	TMonom* a = new TMonom(1, 1);
	TMonom* b = new TMonom(2, 2);
	TMonom* c = new TMonom(3, 3);
	TMonom* d = new TMonom(4, 4);
	t.InsertToTail(a);
	t.InsertToTail(b);
	t.InsertToTail(c);
	t.InsertToTail(d);

	EXPECT_EQ(4, t.GetLenght());
}