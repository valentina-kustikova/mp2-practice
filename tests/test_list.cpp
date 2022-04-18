#include <gtest.h>
#include "list.h"

TEST(List, can_create_empty_list)
{
    ASSERT_NO_THROW(List<int> m);
}

TEST(List, list_is_empty)
{
    List<double> list;
    EXPECT_EQ(true, list.isEmpty());
}

TEST(List, list_is_ended)
{
    List<double> list;
    list.InsertToHead(1);
    list.InsertToHead(2);
    EXPECT_EQ(true, list.isEnd());
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
