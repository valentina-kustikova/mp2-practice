#include "tmatrix.h"

#include <gtest\gtest.h>

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
	int arr[] = { 1, 2, 3, 4, 5 };
	TDynamicVector<int> v1(arr, 5);
	TDynamicVector<int> v2(v1);
	EXPECT_TRUE(v1 == v2);
}

TEST(TDynamicVector, copied_vector_has_its_own_memory) {
	int arr[] = { 1, 2, 3, 4, 5 };
	TDynamicVector<int> v1(arr, 5);
	TDynamicVector<int> v2(v1);
	v2[0] = 10;
	EXPECT_EQ(v1[0], 1);
}

TEST(TDynamicVector, can_get_size)
{
  TDynamicVector<int> v(4);

  EXPECT_EQ(4, v.size());
}

TEST(TDynamicVector, can_set_and_get_element)
{
  TDynamicVector<int> v(4);
  v[0] = 4;

  EXPECT_EQ(4, v[0]);
}

TEST(TDynamicVector, throws_when_set_element_with_negative_index)
{
	TDynamicVector<int> v(5);
	ASSERT_ANY_THROW(v.at(-3) = 5);
}

TEST(TDynamicVector, throws_when_set_element_with_too_large_index)
{
	TDynamicVector<int> v(5);
	ASSERT_ANY_THROW(v.at(5) = 5);
}

TEST(TDynamicVector, can_assign_vector_to_itself)
{
	int arr[] = { 1, 2, 3, 4, 5 };
	TDynamicVector<int> v(arr, 5);
	ASSERT_NO_THROW(v = v);
}

TEST(TDynamicVector, can_assign_vectors_of_equal_size)
{
	int arr[] = { 1, 2, 3, 4, 5 };
	TDynamicVector<int> v1(arr, 5);
	TDynamicVector<int> v2(5);
	v1 = v2;
	EXPECT_EQ(v1, v2);
}

TEST(TDynamicVector, assign_operator_change_vector_size)
{
	TDynamicVector<int> v1(10);
	TDynamicVector<int> v2(5);
	v1 = v2;
	EXPECT_EQ(v1.size(), v2.size());
}

TEST(TDynamicVector, can_assign_vectors_of_different_size)
{
	TDynamicVector<int> v1(10);
	TDynamicVector<int> v2(5);
	ASSERT_NO_THROW(v1 = v2);
}

TEST(TDynamicVector, compare_equal_vectors_return_true)
{
	int arr[] = { 1, 2, 3, 4, 5 };
	TDynamicVector<int> v1(arr, 5);
	TDynamicVector<int> v2(arr, 5);
	EXPECT_TRUE(v1 == v2);
}

TEST(TDynamicVector, compare_vector_with_itself_return_true)
{
	TDynamicVector<int> v(5);
	EXPECT_TRUE(v == v);
}

TEST(TDynamicVector, vectors_with_different_size_are_not_equal)
{
	TDynamicVector<int> v1(10);
	TDynamicVector<int> v2(5);
	EXPECT_FALSE(v1 == v2);
}

TEST(TDynamicVector, can_add_scalar_to_vector)
{
	int arr1[] = { 1, 2, 3, 4, 5 };
	int arr2[] = { 11, 12, 13, 14, 15 };
	TDynamicVector<int> v1(arr1, 5);
	TDynamicVector<int> v2(arr2, 5);
	EXPECT_EQ(v1 + 10, v2);
}

TEST(TDynamicVector, can_subtract_scalar_from_vector)
{
	int arr1[] = { 11, 12, 13, 14, 15 };
	int arr2[] = { 1, 2, 3, 4, 5 };
	TDynamicVector<int> v1(arr1, 5);
	TDynamicVector<int> v2(arr2, 5);
	EXPECT_EQ(v1 - 10, v2);
}

TEST(TDynamicVector, can_multiply_scalar_by_vector)
{
	int arr1[] = { 1, 2, 3, 4, 5 };
	int arr2[] = { 2, 4, 6, 8, 10 };
	TDynamicVector<int> v1(arr1, 5);
	TDynamicVector<int> v2(arr2, 5);
	EXPECT_EQ(v1 * 2, v2);
}

TEST(TDynamicVector, can_add_vectors_with_equal_size)
{
	int arr1[] = { 1, 2, 3, 4, 5 };
	int arr2[] = { 2, 4, 6, 8, 10 };
	int arr_res[] = { 3, 6, 9, 12, 15 };
	TDynamicVector<int> v1(arr1, 5);
	TDynamicVector<int> v2(arr2, 5);
	TDynamicVector<int> result(arr_res, 5);
	EXPECT_EQ(v1 + v2, result);
}

TEST(TDynamicVector, cant_add_vectors_with_not_equal_size)
{
	TDynamicVector<int> v1(5), v2(7);
	ASSERT_ANY_THROW(v1 + v2);
}

TEST(TDynamicVector, can_subtract_vectors_with_equal_size)
{
	int arr1[] = { 1, 2, 3, 4, 5 };
	int arr2[] = { 2, 4, 6, 8, 10 };
	int arr_res[] = { -1, -2, -3, -4, -5 };
	TDynamicVector<int> v1(arr1, 5);
	TDynamicVector<int> v2(arr2, 5);
	TDynamicVector<int> result(arr_res, 5);
	EXPECT_EQ(v1 - v2, result);
}

TEST(TDynamicVector, cant_subtract_vectors_with_not_equal_size)
{
	TDynamicVector<int> v1(5), v2(7);
	ASSERT_ANY_THROW(v1 - v2);
}

TEST(TDynamicVector, can_multiply_vectors_with_equal_size)
{
	int arr1[] = { 1, 2, 3 };
	int arr2[] = { 4, 5, 6 };
	TDynamicVector<int> v1(arr1, 3);
	TDynamicVector<int> v2(arr2, 3);
	EXPECT_EQ(v1 * v2, 32);
}

TEST(TDynamicVector, cant_multiply_vectors_with_not_equal_size)
{
	TDynamicVector<int> v1(3);
	TDynamicVector<int> v2(4);
	ASSERT_ANY_THROW(v1 * v2);
}

