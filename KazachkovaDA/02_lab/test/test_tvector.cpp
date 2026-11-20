#include "tmatrix.h"

#include <gtest/gtest.h>

TEST(TDynamicVector, can_create_vector_with_positive_length)
{
  ASSERT_NO_THROW(TDynamicVector<int> v(5));
}

TEST(TDynamicVector, cant_create_too_large_vector)
{
  ASSERT_ANY_THROW(TDynamicVector<int> v(MAX_VECTOR_SIZE + 1));
}

TEST(TDynamicVector, throws_when_create_vector_with_negative_length)
{
  ASSERT_ANY_THROW(TDynamicVector<int> v(-5));
}

TEST(TDynamicVector, can_create_copied_vector)
{
  TDynamicVector<int> v(10);

  ASSERT_NO_THROW(TDynamicVector<int> v1(v));
}

TEST(TDynamicVector, copied_vector_is_equal_to_source_one)
{
	int* test = new int[4] {1, 2, 3, 4};
	TDynamicVector<int> v(test, 4);
	TDynamicVector<int> v1(v);
	EXPECT_EQ(v, v1);
}

TEST(TDynamicVector, copied_vector_has_its_own_memory)
{
	int* test = new int[4] {1, 2, 3, 4};
	TDynamicVector<int> v(test, 4);
	TDynamicVector<int> v1(v);
	v[0] = 6;
	EXPECT_EQ(v1[0], 1);
}

TEST(TDynamicVector, can_get_size)
{
  TDynamicVector<int> v(4);

  EXPECT_EQ(4, v.size());
}

//TEST(TDynamicVector, can_set_and_get_element)
//{
//  TDynamicVector<int> v(4);
//  v[0] = 4;
//
//  EXPECT_EQ(4, v[0]);
//}

TEST(TDynamicVector, throws_when_set_element_with_negative_index)
{
	TDynamicVector<int> v(4);
	EXPECT_ANY_THROW(v[-1] = 1);
}

TEST(TDynamicVector, throws_when_set_element_with_too_large_index)
{
	TDynamicVector<int> v(4);
	EXPECT_ANY_THROW(v[10] = 1);
}

TEST(TDynamicVector, can_assign_vector_to_itself)
{	
	TDynamicVector<int> v(4);
	EXPECT_NO_THROW(v = v);
}

TEST(TDynamicVector, can_assign_vectors_of_equal_size)
{
	int* test = new int[4] {1, 2, 3, 4};
	TDynamicVector<int> v(test, 4);
	int* test1 = new int[4] {5, 6, 7, 8};
	TDynamicVector<int> v1(test1, 4);
	v = v1;
	EXPECT_EQ(v, v1);

}

TEST(TDynamicVector, assign_operator_change_vector_size)
{
	TDynamicVector<int> v(4);
	TDynamicVector<int> v1(3);
	v = v1;
	EXPECT_EQ(v.size(), 3);
}

TEST(TDynamicVector, can_assign_vectors_of_different_size)
{
	int* test = new int[4] {1, 2, 3, 4};
	TDynamicVector<int> v(test, 4);
	int* test1 = new int[3] {5, 6, 7};
	TDynamicVector<int> v1(test1, 3);
	v = v1;
	EXPECT_EQ(v, v1);
}

TEST(TDynamicVector, compare_equal_vectors_return_true)
{
	int* test = new int[4] {1, 2, 3, 4};
	TDynamicVector<int> v(test, 4);
	int* test1 = new int[3] {5, 6, 7};
	TDynamicVector<int> v1(test1, 3);
	v = v1;
	EXPECT_EQ(v,v1);
}

TEST(TDynamicVector, compare_vector_with_itself_return_true)
{
	int* test = new int[4] {1, 2, 3, 4};
	TDynamicVector<int> v(4);
	EXPECT_TRUE(v == v);
}

TEST(TDynamicVector, vectors_with_different_size_are_not_equal)
{
	int* test = new int[4] {1, 2, 3, 4};
	TDynamicVector<int> v(test, 4);
	int* test1 = new int[3] {5, 6, 7};
	TDynamicVector<int> v1(test1, 3);
	EXPECT_NE(v, v1);
}

TEST(TDynamicVector, can_add_scalar_to_vector)
{
	int* test = new int[4] {1, 2, 3, 4};
	TDynamicVector<int> v(test, 4);
	int* test1 = new int[4] {7, 8, 9, 10};
	TDynamicVector <int> expected(test1, 4);
	EXPECT_EQ(v + 6, expected);
}

TEST(TDynamicVector, can_subtract_scalar_from_vector)
{
	int* test = new int[4] {6, 7, 8, 9};
	TDynamicVector<int> v(test, 4);
	int* test1 = new int[4] {4, 5, 6, 7};
	TDynamicVector <int> expected(test1, 4);
	EXPECT_EQ(v - 2, expected);
}

TEST(TDynamicVector, can_multiply_scalar_by_vector)
{
	int* test = new int[4] {6, 7, 8, 9};
	TDynamicVector<int> v(test, 4);
	int* test1 = new int[4] {24, 28, 32, 36};
	TDynamicVector <int> expected(test1, 4);
	EXPECT_EQ(v * 4, expected);
}

TEST(TDynamicVector, can_add_vectors_with_equal_size)
{
	int* test = new int[4] {6, 7, 8, 9};
	TDynamicVector<int> v(test, 4);
	int* test1 = new int[4] {1, 2, 3, 4};
	TDynamicVector <int> v1(test1, 4);
	int* sum = new int[4] {7, 9, 11, 13};
	TDynamicVector <int> expected(sum, 4);
	EXPECT_EQ(v + v1, expected);
}

TEST(TDynamicVector, cant_add_vectors_with_not_equal_size)
{
	int* test = new int[4] {6, 7, 8, 9};
	TDynamicVector<int> v(test, 4);
	int* test1 = new int[3] {1, 2, 3};
	TDynamicVector <int> v1(test1, 3);
	EXPECT_ANY_THROW(v + v1);
}

TEST(TDynamicVector, can_subtract_vectors_with_equal_size)
{
	int* test = new int[4] {10, 14, 19, 27};
	TDynamicVector<int> v(test, 4);
	int* test1 = new int[4] {1, 2, 3, 4};
	TDynamicVector <int> v1(test1, 4);
	int* sub = new int[4] {9, 12, 16, 23};
	TDynamicVector <int> expected(sub, 4);
	EXPECT_EQ(v - v1, expected);
}

TEST(TDynamicVector, cant_subtract_vectors_with_not_equal_size)
{
	int* test = new int[4] {6, 7, 8, 9};
	TDynamicVector<int> v(test, 4);
	int* test1 = new int[3] {1, 2, 3};
	TDynamicVector <int> v1(test1, 3);
	EXPECT_ANY_THROW(v - v1);
}

TEST(TDynamicVector, can_multiply_vectors_with_equal_size)
{
	int* test = new int[4] {10, 14, 19, 27};
	TDynamicVector<int> v(test, 4);
	int* test1 = new int[4] {1, 2, 3, 4};
	TDynamicVector <int> v1(test1, 4);
	int* mult = new int[4] {10, 28, 57, 108};
	int expected = 203;
	EXPECT_EQ(v * v1, expected);
}

TEST(TDynamicVector, cant_multiply_vectors_with_not_equal_size)
{
	int* test = new int[4] {6, 7, 8, 9};
	TDynamicVector<int> v(test, 4);
	int* test1 = new int[3] {1, 2, 3};
	TDynamicVector <int> v1(test1, 3);
	EXPECT_ANY_THROW(v * v1);
}

