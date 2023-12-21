#include "tstack.h" 
#include <gtest.h> 
class BigStack : public ::testing::Test {
protected:
	Stack<int> bf1;
	Stack<int> bf2;
public:
	BigStack() : bf1(50), bf2(100) {
		for (int i = 0; i < 50; i++)
			bf1.push(i);
		for (int i = 0; i < 100; i++)
			bf2.push(i);
	}
	~BigStack() {}
};
class ParameterizedStack : public ::testing::TestWithParam<int>
{
protected:
	Stack<int> bf1;
public:
	ParameterizedStack() : bf1(GetParam())
	{
		for (int i = 0; i < GetParam() / 2; i++) bf1.push(i);
	}
};

TEST_P(ParameterizedStack, Can_Get_ind)
{
	EXPECT_EQ(GetParam() / 2 - 1, bf1.getInd());
}
TEST_P(ParameterizedStack, can_create_bitfield)
{
	EXPECT_EQ(GetParam(), bf1.GetSizeMax());
}

TEST_P(ParameterizedStack, can_pop_Last_Element)
{
	EXPECT_EQ(GetParam() / 2 - 1, bf1.pop());
}

INSTANTIATE_TEST_CASE_P(Instantiation1,
	ParameterizedStack,
	::testing::Values(20, 100, 1000));

int test_values[] = { 30, 300 };

INSTANTIATE_TEST_CASE_P(Instantiation2,
	ParameterizedStack,
	::testing::ValuesIn(test_values));

TEST_F(BigStack, Can_get_top)
{
	EXPECT_EQ(49, bf1.pop());
}
TEST_F(BigStack, Cant_get_otrichatel)
{
	Stack <int> a(2);
	EXPECT_ANY_THROW(a.pop());
}

TEST_F(BigStack, Cant_fully_push)
{
	bf1.push(100);
	EXPECT_EQ(100, bf1.pop());
}
TEST_F(BigStack, Cant_fully_push2)
{
	bf2.pop();
	bf2.pop();
	EXPECT_EQ(97, bf2.pop());
}
TEST_F(BigStack, Can_Clear)
{
	bf1.Clear();
	ASSERT_ANY_THROW(bf1.pop());
}