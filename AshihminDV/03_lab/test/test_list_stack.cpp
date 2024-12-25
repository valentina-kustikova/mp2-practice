//#include "list_stack.h"
//#include <gtest.h>
//
//TEST(list_stack, can_create_Lstack)
//{
//	ASSERT_NO_THROW(list_stack<int> ls());
//}
//TEST(list_stack, copied_stack_eq_original)
//{
//	list_stack<int> ls;
//	ls.Push(10);
//	ls.Push(20);
//	ls.Push(30);
//	list_stack<int> ls1(ls);
//	EXPECT_EQ(ls, ls1);
//}
//TEST(list_stack, cant_create_Astack_with_ToLarge_size)
//{
//	ASSERT_ANY_THROW(array_stack<int> m(MAX_STACK_SIZE + 1));
//}
//TEST(list_stack, cant_create_Astack_with_negative_size)
//{
//	ASSERT_ANY_THROW(array_stack<int> m(-5));
//}
//TEST(list_stack, can_push_element)
//{
//	list_stack<int> m;
//	ASSERT_NO_THROW(m.Push(5));
//}
//TEST(list_stack, cant_push_element_in_full_stack)
//{
//	array_stack<int> m(2);
//	m.Push(5);
//	m.Push(5);
//	ASSERT_ANY_THROW(m.Push(5));
//}
//TEST(list_stack, correct_push_and_top_element)
//{
//	array_stack<int> m(5);
//	m.Push(5);
//	EXPECT_EQ(5, m.Top());
//}
//TEST(list_stack, can_pop_element)
//{
//	array_stack<int> m(5);
//	m.Push(5);
//	ASSERT_NO_THROW(m.pop());
//}
//TEST(list_stack, cant_pop_element_in_empty_stack)
//{
//	array_stack<int> m(5);
//	ASSERT_ANY_THROW(m.pop());
//}
//TEST(list_stack, empty_stack_is_empty)
//{
//	array_stack<int> m(5);
//	array_stack<int> m1(5);
//	m.Push(5);
//	EXPECT_NE(m.is_empty(), m1.is_empty());
//}