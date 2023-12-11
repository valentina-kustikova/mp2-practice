#include "Stack.h"

#include <gtest.h>
#include <clocale>



TEST(Stack, throw_when_create_stack_with_negative_size) {
	ASSERT_ANY_THROW(Stack<char> my_stack(-5));
}

TEST(Stack, throw_when_create_stack_with_zero_size) {
	ASSERT_ANY_THROW(Stack<char> my_stack(0));
}

TEST(Stack, no_throw_when_use_constructor_copy) {
	Stack<double> stack1;
	ASSERT_NO_THROW(Stack<double> stack2(stack1));
}

TEST(Stack, original_adresses_memory) {
	Stack<double> stack1;
	Stack<double> stack2(stack1);
	EXPECT_TRUE(stack1.GetMemory() != stack2.GetMemory());
}

TEST(Stack, no_throw_when_use_destructor) {
	Stack<int>* my_stack = new Stack<int>(5);
	ASSERT_NO_THROW(delete my_stack);
}

TEST(Stack, can_get_top_value) {
	Stack<char> my_stack(3);

	my_stack.Push('A');


	EXPECT_TRUE(my_stack.GetTop() == 0);
}

TEST(Stack, can_push_element) {
	Stack<char> my_stack(3);

	EXPECT_NO_THROW(my_stack.Push('A'));
}



TEST(Stack, can_get_size_value) {
	Stack<char> my_stack(3);

	my_stack.Push('A');

	EXPECT_TRUE(my_stack.Size() == 1);
}

TEST(Stack, throw_when_push_element_in_full_stack) {
	Stack<char> my_stack(3);

	my_stack.Push('A');
	my_stack.Push('+');
	my_stack.Push('(');

	ASSERT_ANY_THROW(my_stack.Push(')'));
}

TEST(Stack, can_pop_element) {
	Stack<char> my_stack(3);
	my_stack.Push('A');

	ASSERT_NO_THROW(my_stack.Pop());
}

TEST(Stack, throw_when_get_top_from_empty_stack) {
	Stack<char> my_stack;
	char ch;
	ASSERT_ANY_THROW(ch = my_stack.Top());
}

TEST(Stack, check_pushed_element) {
	Stack<char> my_stack(3);

	my_stack.Push('A');

	EXPECT_TRUE(my_stack.Top() == 'A');
}

TEST(Stack, check_popped_element) {
	Stack<char> my_stack(3);

	my_stack.Push('A');
	my_stack.Push('+');
	my_stack.Push('(');


	char elem1 = my_stack.Pop();
	char elem2 = my_stack.Pop();

	EXPECT_TRUE(elem1 == '(');
	EXPECT_TRUE(elem2 == '+');
}









