#include <gtest.h>
#include "List.h"


TEST(Node, can_create_node)
{
	ASSERT_NO_THROW(Node<int> a);
}
TEST(Node, can_create_node_copy)
{
	Node<int> a;
	ASSERT_NO_THROW(Node<int> b(a));
}

TEST(List, can_create_list)
{
	//ASSERT_NO_THROW(List<double> l);
}

TEST(List, new_list_is_empty)
{
	List<double> l;
	EXPECT_EQ(true, l.isEmpty());
}

TEST(List, can_add_elem_to_empty_list)
{
	List<double> l;
	ASSERT_NO_THROW(l.InsertToHead(4));
}

TEST(List, can_add_elem_to_notempty_list)
{
	List<int> l;
	l.InsertToHead(4);
	l.InsertToHead(5);
	EXPECT_EQ(5, l.ViewHead());
}

TEST(List, can_add_to_tail_1)
{
	List<int> l;
	l.InsertToTail(4);
	EXPECT_EQ(4, l.ViewHead());
}

TEST(List, can_add_to_tail_2)
{
	List<int> l;
	l.InsertToTail(4);
	l.InsertToTail(5);
	l.InsertToTail(6);
	EXPECT_EQ(4, l.ViewHead());
}

TEST(List, can_clean_empty_list)
{
	List<int> l;
	ASSERT_NO_THROW(l.Clean());
}

TEST(List, can_clean2)
{
	List<int> l;
	l.InsertToTail(4);
	l.Clean();
	EXPECT_EQ(true, l.isEmpty());
}

TEST(List, can_clean3)
{
	List<int> l;
	l.InsertToTail(4);
	l.InsertToTail(5);
	l.InsertToTail(6);
	l.Clean();
	EXPECT_EQ(true, l.isEmpty());
}

TEST(List, can_delete1)
{
	List<int> l;
	l.InsertToTail(4);
	l.InsertToTail(5);
	l.InsertToTail(6);

	l.Delete(5);

	Node<int>* tmp = l.GetHead();
	tmp = tmp->next;
	EXPECT_EQ(6, tmp->data);
}

TEST(List, can_delete2)
{
	List<int> l;
	l.InsertToTail(4);
	l.InsertToTail(5);
	l.InsertToTail(6);

	l.Delete(4);

	Node<int>* tmp = l.GetHead();
	EXPECT_EQ(5, tmp->data);
}

TEST(List, can_delete3)
{
	List<int> l;
	l.InsertToTail(4);
	l.InsertToTail(5);
	l.InsertToTail(6);

	ASSERT_NO_THROW(l.Delete(7));
}


class EmptyList : public testing::Test
{
protected:
	List<int> l;
public:
	EmptyList() {};
	~EmptyList() {};
};
TEST_F(EmptyList, new_list_is_empty)
{
	EXPECT_EQ(NULL, l.GetHead());
}
TEST_F(EmptyList, size_of_new_list_is_zero)
{
	EXPECT_EQ(0, l.GetSize());
}
TEST_F(EmptyList, can_copy_empty_list)
{
	ASSERT_NO_THROW(List<int> l2(l));
}
TEST_F(EmptyList, empty_list_copy_is_correct)
{
	List<int> l2(l);
	EXPECT_EQ(NULL, l2.GetHead());
}
TEST_F(EmptyList, size_of_empty_list_copy_is_correct)
{
	List<int> l2(l);
	EXPECT_EQ(0, l2.GetSize());
}

TEST_F(EmptyList, can_assign_two_empty_lists)
{
	List<int> l2;
	ASSERT_NO_THROW(l = l2);
}
TEST_F(EmptyList, can_assign_empty_list_to_itself)
{
	ASSERT_NO_THROW(l = l);
}
TEST_F(EmptyList, assign_two_empty_lists_is_correct)
{
	List<int> l2;
	l = l2;
	EXPECT_EQ(NULL, l.GetHead());
}
TEST_F(EmptyList, can_insert_to_head_for_empty_list)
{
	l.InsertToHead(5);
	EXPECT_EQ(5, l.GetHead()->data);
	EXPECT_EQ(NULL, l.GetHead()->next);
}
TEST_F(EmptyList, can_insert_to_tail_for_empty_list)
{
	l.InsertToTail(5);
	EXPECT_EQ(5, l.GetHead()->data);
	EXPECT_EQ(NULL, l.GetHead()->next);
}
TEST_F(EmptyList, can_delete_from_empty_list)
{
	ASSERT_NO_THROW(l.Delete(5));
}
TEST_F(EmptyList, delete_from_empty_list_is_correct)
{
	l.Delete(5);
	EXPECT_EQ(NULL, l.GetHead());
}
TEST_F(EmptyList, can_search_for_empty_list)
{
	ASSERT_NO_THROW(l.Search(5));
}
TEST_F(EmptyList, search_for_empty_list_is_correct)
{
	Node<int>* p = l.Search(5);
	EXPECT_EQ(NULL, p);
}
TEST_F(EmptyList, can_clean_empty_list)
{
	ASSERT_NO_THROW(l.Clean());
}
TEST_F(EmptyList, clean_empty_list_is_correct)
{
	l.Clean();
	EXPECT_EQ(NULL, l.GetHead());
}

//------------------------------------------------------------------------------------------
class ThreeNodesList : public testing::Test
{
protected:
	List<int> l;
public:
	ThreeNodesList()
	{
		l.InsertToTail(1);
		l.InsertToTail(2);
		l.InsertToTail(3);
	}
	~ThreeNodesList() {};
};
TEST_F(ThreeNodesList, three_nodes_list_is_correct)
{
	EXPECT_EQ(1, l.GetHead()->data);
	EXPECT_EQ(2, l.GetHead()->next->data);
	EXPECT_EQ(3, l.GetHead()->next->next->data);
	EXPECT_EQ(NULL, l.GetHead()->next->next->next);
}
TEST_F(ThreeNodesList, size_of_new_list_is_three)
{
	EXPECT_EQ(3, l.GetSize());
}
TEST_F(ThreeNodesList, can_copy_not_empty_list)
{
	ASSERT_NO_THROW(List<int> l2(l));
}
TEST_F(ThreeNodesList, copy_of_not_empty_list_is_correct)
{
	List<int> l2(l);
	// так написано, т.к. предполагаем, что == еще не реализовано или не работает
	EXPECT_EQ(1, l2.GetHead()->data);
	EXPECT_EQ(2, l2.GetHead()->next->data);
	EXPECT_EQ(3, l2.GetHead()->next->next->data);
	EXPECT_EQ(NULL, l2.GetHead()->next->next->next);
}
TEST_F(ThreeNodesList, copied_list_has_its_own_memory)
{
	List<int> l2(l);
	EXPECT_NE(l.GetHead(), l2.GetHead());
	EXPECT_NE(l.GetHead()->next, l2.GetHead()->next);
	EXPECT_NE(l.GetHead()->next->next, l2.GetHead()->next->next);
}
TEST_F(ThreeNodesList, size_of_not_empty_list_copy_is_correct)
{
	List<int> l2(l);
	EXPECT_EQ(3, l2.GetSize());
}
TEST_F(ThreeNodesList, can_insert_to_head_for_not_empty_list)
{
	l.InsertToHead(5);
	EXPECT_EQ(5, l.GetHead()->data);
	EXPECT_EQ(1, l.GetHead()->next->data);
}
TEST_F(ThreeNodesList, can_insert_to_tail_for_not_empty_list)
{
	l.InsertToTail(5);
	EXPECT_EQ(5, l.GetHead()->next->next->next->data);
	EXPECT_EQ(NULL, l.GetHead()->next->next->next->next);
}
TEST_F(ThreeNodesList, can_insert_after_null_ptr_for_not_empty_list)
{
	ASSERT_NO_THROW(l.InsertAfter(NULL, 5));
}
TEST_F(ThreeNodesList, can_insert_after_ptr_for_not_empty_list)
{
	Node<int>* p = l.GetHead()->next;
	ASSERT_NO_THROW(l.InsertAfter(p, 5));
}
TEST_F(ThreeNodesList, insert_after_ptr_for_not_empty_list_is_correct)
{
	Node<int>* p = l.GetHead()->next;
	l.InsertAfter(p, 5);
	EXPECT_EQ(2, l.GetHead()->next->data);
	EXPECT_EQ(5, l.GetHead()->next->next->data);
	EXPECT_EQ(3, l.GetHead()->next->next->next->data);
	EXPECT_EQ(NULL, l.GetHead()->next->next->next->next);
}
TEST_F(ThreeNodesList, can_delete_head_from_not_empty_list)
{
	ASSERT_NO_THROW(l.Delete(1));
}
TEST_F(ThreeNodesList, can_delete_head_from_not_empty_list2)
{
	l.Delete(1);
	EXPECT_EQ(2, l.GetHead()->data);
}
TEST_F(ThreeNodesList, can_delete_middle_from_not_empty_list)
{
	l.Delete(2);
	EXPECT_EQ(1, l.GetHead()->data);
	EXPECT_EQ(3, l.GetHead()->next->data);
}
TEST_F(ThreeNodesList, can_delete_tail_from_not_empty_list)
{
	l.Delete(3);
	EXPECT_EQ(1, l.GetHead()->data);
	EXPECT_EQ(2, l.GetHead()->next->data);
	EXPECT_EQ(NULL, l.GetHead()->next->next);
}
TEST_F(ThreeNodesList, can_delete_not_a_member_from_not_empty_list)
{
	ASSERT_NO_THROW(l.Delete(5));
}
TEST_F(ThreeNodesList, can_delete_not_a_member_from_not_empty_list2)
{
	l.Delete(5);
	EXPECT_EQ(1, l.GetHead()->data);
	EXPECT_EQ(2, l.GetHead()->next->data);
	EXPECT_EQ(3, l.GetHead()->next->next->data);
	EXPECT_EQ(NULL, l.GetHead()->next->next->next);
}
TEST_F(ThreeNodesList, can_search_for_not_empty_list)
{
	ASSERT_NO_THROW(l.Search(3));
}
TEST_F(ThreeNodesList, search_for_not_empty_list_is_correct)
{
	Node<int>* p = l.Search(3);
	Node<int>* ptrue = l.GetHead()->next->next;
	EXPECT_EQ(ptrue, p);
}
TEST_F(ThreeNodesList, can_search_not_a_member_for_not_empty_list)
{
	ASSERT_NO_THROW(l.Search(5));
}
TEST_F(ThreeNodesList, search_not_a_member_for_not_empty_list_is_correct)
{
	Node<int>* p = l.Search(5);
	EXPECT_EQ(NULL, p);
}
TEST_F(ThreeNodesList, can_clean_not_empty_list)
{
	ASSERT_NO_THROW(l.Clean());
}
TEST_F(ThreeNodesList, clean_not_empty_list_is_correct)
{
	l.Clean();
	EXPECT_EQ(NULL, l.GetHead());
}
TEST_F(ThreeNodesList, size_of_not_empty_list_after_clean_is_correct)
{
	l.Clean();
	EXPECT_EQ(0, l.GetSize());
}

TEST_F(ThreeNodesList, can_assign_not_empty_list_to_itself)
{
	ASSERT_NO_THROW(l = l);
}
TEST_F(ThreeNodesList, can_assign_two_not_empty_lists)
{
	List<int> l2;
	l2.InsertToTail(22);
	l2.InsertToTail(33);
	ASSERT_NO_THROW(l = l2);
}
TEST_F(ThreeNodesList, list_after_assign_has_its_own_memory)
{
	List<int> l2;
	l2.InsertToTail(22);
	l2.InsertToTail(33);
	l = l2;
	EXPECT_NE(l.GetHead(), l2.GetHead());
	EXPECT_NE(l.GetHead()->next, l2.GetHead()->next);
}
TEST_F(ThreeNodesList, can_assign_two_not_empty_lists_of_eq_size)
{
	List<int> l2;
	l2.InsertToTail(11);
	l2.InsertToTail(22);
	l2.InsertToTail(33);
	l = l2;
	EXPECT_EQ(11, l.GetHead()->data);
	EXPECT_EQ(22, l.GetHead()->next->data);
	EXPECT_EQ(33, l.GetHead()->next->next->data);
	EXPECT_EQ(NULL, l.GetHead()->next->next->next);
}
class TwoListsTest : public testing::Test
{
protected:
	List<int> l;
	List<int> l2;
	List<int> z;
public:
	TwoListsTest()
	{
		l.InsertToTail(1);
		l.InsertToTail(2);
		l.InsertToTail(3);
		l2.InsertToTail(11);
		l2.InsertToTail(22);
	}
	~TwoListsTest() {}
};
TEST_F(TwoListsTest, can_assign_two_not_empty_lists_of_not_eq_size)
{
	ASSERT_NO_THROW(l = l2);
}
TEST_F(TwoListsTest, assign_two_not_empty_lists_of_not_eq_size_is_correct)
{
	l = l2;
	EXPECT_EQ(11, l.GetHead()->data);
	EXPECT_EQ(22, l.GetHead()->next->data);
	EXPECT_EQ(NULL, l.GetHead()->next->next);
}
TEST_F(TwoListsTest, assign_list_to_empty_is_correct)
{
	l = z;
	EXPECT_EQ(NULL, l.GetHead());
}
