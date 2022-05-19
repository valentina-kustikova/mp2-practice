#include <gtest.h>
#include "list.h"
#include "headlist.h"

TEST(Node, can_create_new_node)
{
    ASSERT_NO_THROW(Node<int> n);
}

TEST(List, can_create_empty_list)
{
    ASSERT_NO_THROW(List<int> m);
}
TEST(List, list_is_empty)
{
    List<double> list;
    EXPECT_EQ(true, list.isEmpty());
}
TEST(List, can_copy_empty_list)
{
    List<int> l;
    ASSERT_NO_THROW(List<int> m(l));
}
TEST(List, copy_list_is_empty)
{
    List<int> l;
    List<int> m(l);
    EXPECT_EQ(true, l.isEmpty());
}
TEST(List, list_is_not_empty)
{
    List<int> l;
    l.InsertToTail(4);
    EXPECT_EQ(false, l.isEmpty());
}
TEST(List, list_is_ended)
{
    List<double> list;
    list.InsertToHead(1);
    list.InsertToHead(2);
    EXPECT_EQ(true, list.isEnd());
}
TEST(List, can_insert_to_head0)
{
    List<int> l;
    ASSERT_NO_THROW(l.InsertToHead(1));
}
TEST(List, can_insert_to_tail0)
{
    List<int> l;
    ASSERT_NO_THROW(l.InsertToTail(1));
}
TEST(List, can_insert_to_order0)
{
    List<int> l;
    ASSERT_NO_THROW(l.InsertInOrder(1));
}
TEST(List, can_insert_to_head)
{
    List<int> list;
    list.InsertToHead(1);
    EXPECT_EQ(1, list.Head());
}
TEST(List, can_insert_to_head2)
{
    List<int> list;
    list.InsertToHead(1);
    list.InsertToHead(2);
    EXPECT_EQ(2, list.Head());
}
TEST(List, can_insert_to_tail)
{
    List<int> list;
    list.InsertToTail(1);
    EXPECT_EQ(1, list.Head());
}
TEST(List, can_insert_to_tail2)
{
    List<int> list;
    list.InsertToTail(1);
    list.InsertToTail(2);
    EXPECT_EQ(1, list.Head());
}
TEST(List, can_clean)
{
    List<int> list;
    list.InsertToHead(1);
    list.Clean();
    EXPECT_EQ(true, list.isEmpty());
}
TEST(List, can_clean2)
{
    List<int> list;
    list.InsertToHead(1);
    list.InsertToHead(2);
    list.InsertToHead(3);
    list.Clean();
    EXPECT_EQ(true, list.isEmpty());
}
TEST(List, can_delete)
{
    List<int> list;
    list.InsertToHead(1);
    list.InsertToHead(2);
    list.InsertToHead(3);
    list.Delete(3);
    Node<int>* tmp = list.GetHead();
    EXPECT_EQ(2, tmp->data);
}
TEST(List, can_delete2)
{
    List<int> list;
    list.InsertToTail(1);
    list.InsertToTail(2);
    list.InsertToTail(3);
    list.Delete(2);
    Node<int>* tmp = list.GetHead();
    tmp = tmp->next;
    EXPECT_EQ(3, tmp->data);
}
TEST(HeadList, can_create_headlist)
{
    ASSERT_NO_THROW(HeadList<int> h);
}
TEST(HeadList, can_insert)
{
    HeadList<int> h;
    ASSERT_NO_THROW(h.InsertToTail(1));
}
TEST(HeadList, can_delete)
{
    HeadList<int> h;
    ASSERT_NO_THROW(h.DeleteFirst());
}

