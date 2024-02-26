#include "tstack.h" 
#include <gtest.h> 


//constructors
//////////////////////////////////////////////////////////////////////////////////
TEST(TStack, can_create_stack)
{
	ASSERT_NO_THROW(TStack<int> stack);
}

TEST(TStack, can_create_stack_with_positive_size)
{
	ASSERT_NO_THROW(TStack<int> stack(12));
}


TEST(TSack, cant_create_stack_with_negative_size)
{
	ASSERT_ANY_THROW(TStack<int> stack(-2));
}


TEST(TStack, can_copy_stack)
{
	TStack<int> stack;
	ASSERT_NO_THROW(TStack<int> st(stack));
}

TEST(TStack, can_copy_stack_with_bigger_size)
{
	TStack<int> stack(100);
	ASSERT_NO_THROW(TStack<int> st(stack));
}
//////////////////////////////////////////////////////////////////////////////////


//empty/full
//////////////////////////////////////////////////////////////////////////////////
TEST(TStack, empty_stack_is_empty)
{
	TStack<int> stack;
	ASSERT_TRUE(stack.isEmpty());
}

TEST(TStack, not_empty_isnt_empty)
{
	TStack<int> stack;
	stack.push(12);
	ASSERT_FALSE(stack.isEmpty());
}

TEST(TStack, empty_isnt_full)
{
	TStack<int> stack;
	ASSERT_FALSE(stack.isFull());
}

TEST(TStack, not_empty_isnt_full)
{
	TStack<int> stack;
	stack.push(12);
	ASSERT_FALSE(stack.isFull());
}

TEST(TStack, full_is_full) {
	TStack<int> stack(1);
	stack.push(12);
	ASSERT_TRUE(stack.isFull());
}
//////////////////////////////////////////////////////////////////////////////////

//top
//////////////////////////////////////////////////////////////////////////////////
TEST(TStack, cant_return_top_in_empty_stack)
{
	TStack<int> stack;
	ASSERT_ANY_THROW(stack.Top());
}

TEST(TStack, can_return_top_in_not_empty_stack)
{
	TStack<int> stack;
	int a = 2;
	stack.push(a);
	EXPECT_EQ(a, stack.Top());
}

TEST(TStack, can_return_top_in_full_stack)
{
	TStack<int> stack(1);
	int a = 2;
	stack.push(a);
	EXPECT_EQ(a, stack.Top());
}
//////////////////////////////////////////////////////////////////////////////////

//push
//////////////////////////////////////////////////////////////////////////////////
TEST(TStack, can_push)
{
	TStack<int> stack;
	ASSERT_NO_THROW(stack.push(2));
}

TEST(TStack, cant_push_in_full_stack)
{
	TStack<int> stack(1);
	stack.push(2);
	ASSERT_ANY_THROW(stack.push(2));
}
//////////////////////////////////////////////////////////////////////////////////

//pop
//////////////////////////////////////////////////////////////////////////////////
TEST(TStack, can_pop_in_not_empty_stack)
{
	TStack<int> stack;
	stack.push(2);
	ASSERT_NO_THROW(stack.Pop());
}

TEST(TStack, can_pop_in_full_stack)
{
	TStack<int> stack(1);
	stack.push(2);
	ASSERT_NO_THROW(stack.Pop());
}

TEST(TStack, cant_pop_in_empty_stack)
{
	TStack<int> stack;
	ASSERT_ANY_THROW(stack.Pop());
}
//////////////////////////////////////////////////////////////////////////////////