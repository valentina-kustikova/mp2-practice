#include "gtest.h"
#include "tlist.h"
#include "tringlist.h"


TEST(TList, create_empty_list)
{
	ASSERT_NO_THROW(TList<int> list());
}

TEST(TList, create_list_with_list)
{
	TList<int> list;
	for (int i = 0; i < 5; i++) list.push_back(i);
	ASSERT_NO_THROW(TList<int> list1(list));

	TList<int> list1(list);
	for (int i = 0; i < 5; i++)
	{
		ASSERT_EQ(list.get_curr()->value, list1.get_curr()->value);
	}

}

TEST(TList, create_list_with_Node)
{
	TNode<int>* node1 = new TNode<int>(1), *node2 = new TNode<int>(2);
	node1->next = node2;
	ASSERT_NO_THROW(TList<int> list(node1));
	
	TList<int> list(node1);

	ASSERT_EQ(list.get_curr()->value, node1->value);
	ASSERT_NO_THROW(list.next());
	ASSERT_EQ(list.get_curr()->value, node2->value);
	

}

TEST(TList, can_get_element) {
	TList<int> l;
	int num = 1;
	l.push_back(num);
	ASSERT_EQ(l.get_curr()->value, 1);
}

TEST(TList, can_iterate_with_next) {
	TList<int> l;
	l.push_back(1); l.push_back(2);
	l.next();
	ASSERT_EQ(l.get_curr()->value, 2);
}

TEST(TList, can_remove_any_element) 
{
	TList<int> l;
	for (int i = 0; i < 5; i++) l.push_back(i);
	l.remove(3);
	
	for (int i = 0; i < 3; i++)
	{
		ASSERT_EQ(l.get_curr()->value, i);
		l.next();
	}

	ASSERT_EQ(l.get_curr()->value, 4);
}

TEST(TList, can_remove_first_element)
{
	TList<int> l;
	for (int i = 0; i < 5; i++) l.push_back(i);
	l.remove(0);

	for (int i = 0; i < 4; i++)
	{
		ASSERT_EQ(l.get_curr()->value, i+1);
		l.next();
	}
}

TEST(TList, can_remove_last_element)
{
	TList<int> l;
	for (int i = 0; i < 5; i++) l.push_back(i);
	l.remove(5);

	for (int i = 0; i < 4; i++)
	{
		ASSERT_EQ(l.get_curr()->value, i);
		l.next();
	}
}

TEST(TList, can_push_front_element)
{
	TList<int> l;
	ASSERT_NO_THROW(l.push_front(1));
	l.push_front(1);
	
	ASSERT_EQ(l.get_curr()->value, 1);
}

TEST(TList, can_push_after_curr)
{
	TList<int> l;
	for (int i = 0; i < 5; i++) l.push_back(i);
	l.next(); l.next();
	l.push_after_curr(-1);
	l.next();
	ASSERT_EQ(l.get_curr()->value, -1);
}



TEST(TRingList, create_empty_list)
{
	ASSERT_NO_THROW(TRingList<int> list());
}

TEST(TRingList, create_list_with_list)
{
	TRingList<int> list;
	for (int i = 0; i < 5; i++) list.push_back(i);
	ASSERT_NO_THROW(TRingList<int> list1(list));

	TRingList<int> list1(list);
	for (int i = 0; i < 5; i++)
	{
		ASSERT_EQ(list.get_curr()->value, list1.get_curr()->value);
	}

}

TEST(TRingList, create_list_with_Node)
{
	TNode<int>* node1 = new TNode<int>(1), * node2 = new TNode<int>(2);
	node1->next = node2;
	ASSERT_NO_THROW(TRingList<int> list(node1));

	TRingList<int> list(node1);

	ASSERT_EQ(list.get_curr()->value, node1->value);
	ASSERT_NO_THROW(list.next());
	ASSERT_EQ(list.get_curr()->value, node2->value);


}

TEST(TRingList, can_get_element) {
	TRingList<int> l;
	int num = 1;
	l.push_back(num);
	ASSERT_EQ(l.get_curr()->value, 1);
}

TEST(TRingList, can_iterate_with_next) {
	TRingList<int> l;
	l.push_back(1); l.push_back(2);
	l.next();
	ASSERT_EQ(l.get_curr()->value, 2);
}

TEST(TRingList, can_remove_any_element)
{
	TRingList<int> l;
	for (int i = 0; i < 5; i++) l.push_back(i);
	l.remove(3);

	for (int i = 0; i < 3; i++)
	{
		ASSERT_EQ(l.get_curr()->value, i);
		l.next();
	}

	ASSERT_EQ(l.get_curr()->value, 4);
}

TEST(TRingList, can_remove_first_element)
{
	TRingList<int> l;
	for (int i = 0; i < 5; i++) l.push_back(i);
	l.remove(0);

	for (int i = 0; i < 4; i++)
	{
		ASSERT_EQ(l.get_curr()->value, i + 1);
		l.next();
	}
}

TEST(TRingList, can_remove_last_element)
{
	TRingList<int> l;
	for (int i = 0; i < 5; i++) l.push_back(i);
	l.remove(5);

	for (int i = 0; i < 4; i++)
	{
		ASSERT_EQ(l.get_curr()->value, i);
		l.next();
	}
}

TEST(TRingList, can_push_front_element)
{
	TRingList<int> l;
	ASSERT_NO_THROW(l.push_front(1));
	l.push_front(1);

	ASSERT_EQ(l.get_curr()->value, 1);
}

TEST(TRingList, can_push_after_curr)
{
	TRingList<int> l;
	for (int i = 0; i < 5; i++) l.push_back(i);
	l.next(); l.next();
	l.push_after_curr(-1);
	l.next();
	ASSERT_EQ(l.get_curr()->value, -1);
}

TEST(TRingList, check_ring)
{
	TRingList<int> l;
	for (int i = 0; i < 2; i++) l.push_back(i);

	l.next(); l.next();
	ASSERT_NO_THROW(l.get_curr()->value);
	ASSERT_EQ(l.get_curr()->value, 0);
}