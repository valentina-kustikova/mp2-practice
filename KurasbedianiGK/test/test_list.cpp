#include "list.h"
#include "gtest.h"

TEST(List, can_create_list_with_default_ctor) {
    ASSERT_NO_THROW(List<int>{});
}

TEST(List, new_list_is_empty) {
    EXPECT_EQ(0, List<int>{}.get_size());
}

TEST(List, can_create_list_via_node_ptr) {
    ASSERT_NO_THROW(List<int>{new Node<int>(5, nullptr)});
}

TEST(List, created_list_via_node_ptr_is_not_empty) {
    Node<int> node(5, nullptr);
    List<int> list{&node};

    EXPECT_EQ(1, list.get_size());
}

TEST(List, can_create_list_via_copy_ctor) {
    List<int> list;

    ASSERT_NO_THROW(List<int>{list});
}

TEST(List, created_list_via_copy_ctor_is_correct) {
    List<int> list;
    list.insert(5);

    List<int> list1(list);

    EXPECT_EQ(list.get_head()->data, list1.get_head()->data);
}

TEST(List, can_add_elem_in_empty_list) {
    List<int> list;

    ASSERT_NO_THROW(list.insert(5));
}

TEST(List, added_elem_in_empty_list_is_correct) {
    List<int> list;
    list.insert(5);

    EXPECT_EQ(5, list.get_head()->data);
}

TEST(List, can_add_elem_in_not_empty_list) {
    List<int> list;
    list.insert(4);

    ASSERT_NO_THROW(list.insert(5));
}

TEST(List, added_elem_in_not_empty_list_is_correct) {
    List<int> list;
    list.insert(4);
    list.insert(5);

    EXPECT_EQ(5, list.get_head()->data);
}

TEST(List, no_error_when_remove_from_empty_list) {
    List<int> list;

    ASSERT_NO_THROW(list.remove(5));
}

TEST(List, no_error_when_remove_non_exist_elem) {
    List<int> list;
    list.insert(4);

    ASSERT_NO_THROW(list.remove(5));
}

TEST(List, can_remove_elem) {
    List<int> list;
    list.insert(5);

    ASSERT_NO_THROW(list.remove(5));
}

TEST(List, remove_elem_is_correct) {
    List<int> list;
    list.insert(5);
    list.remove(5);

    EXPECT_EQ(nullptr, list.get_head());
}

TEST(List, remove_head_is_correct) {
    List<int> list;
    list.insert(4);
    list.insert(5);
    list.remove(5);

    EXPECT_EQ(4, list.get_head()->data);
}

TEST(List, remove_tail_is_correct) {
    List<int> list;
    list.insert(5);
    list.insert(4);
    list.remove(5);

    EXPECT_EQ(nullptr, list.get_head()->next);
}

TEST(List, can_assign_list) {
    List<int> list;
    list.insert(5);
    List<int> list1;
    ASSERT_NO_THROW(list1 = list);
}

TEST(List, assigned_list_is_correct) {
    List<int> list;
    list.insert(5);
    List<int> list1;
    list1 = list;

    EXPECT_EQ(list.get_head()->data, list1.get_head()->data);
}