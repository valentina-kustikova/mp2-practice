#include "tmatrix.h"

#include <gtest.h>

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
	const int size = 5;
	TDynamicVector<int> v1(size);
	for (int i = 0; i < size; i++)
	{
		v1[i] = i;
	}
	TDynamicVector<int> v2(v1);
	EXPECT_EQ(v1.size(), v2.size());
	for (int i = 0; i < size; i++)
	{
		EXPECT_EQ(v1[i], v2[i]);
	}
}

TEST(TDynamicVector, copied_vector_has_its_own_memory)
{
	const int size = 5; //?
	TDynamicVector<int> v1(size);
	for (int i = 0; i < size; i++)
	{
		v1[i] = i;
	}
	TDynamicVector<int> v2(v1);

	for (int i = 0; i < size; i++)
	{
		EXPECT_EQ(v1[i], v2[i]);
	}
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
	TDynamicVector<int> v(5);
	ASSERT_ANY_THROW(v.at(-1));
}

TEST(TDynamicVector, throws_when_set_element_with_too_large_index)
{
	TDynamicVector<int> v(5);
	ASSERT_ANY_THROW(v.at(v.size() + 1));
}

TEST(TDynamicVector, can_assign_vector_to_itself)
{
	/*const int size = 2;
	TDynamicVector<int> v1(size);
	for (int i = 0; i < size; i++)
	{
		v1[i] = i;
	}
	v1 = v1;
	EXPECT_EQ(v1[0], v1[0]);
	EXPECT_EQ(v1[1], v1[1]);*/
	TDynamicVector<int> v(10);
	ASSERT_NO_THROW(v = v);
}

TEST(TDynamicVector, can_assign_vectors_of_equal_size)
{
	/*const int size1 = 5;
	TDynamicVector<int> v1(size1), v2(size1);
	for (int i = 0; i < size1; i++)
	{
		v1[i] = i;
	}
	v2 = v1;

	for (int i = 0; i < size1; i++)
	{
		EXPECT_EQ(v1[i], v2[i]);
	}*/
	TDynamicVector<int> v1(10), v2(10);
	ASSERT_NO_THROW(v1 = v2);
	
}

TEST(TDynamicVector, assign_operator_change_vector_size)
{
	const int size1 = 3, size2 = 4; 
	TDynamicVector<int> v1(size1), v2(size2);
	for (int i = 0; i < size1; i++)
	{
		v1[i] = i;
	}
	v2 = v1;

	EXPECT_EQ(v2.size(), size1);
}

TEST(TDynamicVector, can_assign_vectors_of_different_size)
{
	/*const int size1 = 3, size2 = 4, size3 = 5;
	TDynamicVector<int> v1(size1), v2(size2), v3(size3);
	
	for (int i = 0; i < size1; i++)
	{
		v1[i] = 1;
	}
	v3 = v1;
	for (int i = 0; i < size1; i++)
	{
		EXPECT_EQ(v1[i], v3[i]);
	}
	
	for (int i = 0; i < size2; i++)
	{
		v2[i] = 2;
	}
	v3 = v2;
	for (int i = 0; i < size2; i++)
	{
		EXPECT_EQ(v2[i], v3[i]);
	}*/
	TDynamicVector<int> v1(9), v2(4);

	ASSERT_NO_THROW(v1 = v2);
}

TEST(TDynamicVector, compare_equal_vectors_return_true)
{
	TDynamicVector<int> v1(7);
	for (int i = 0; i < v1.size(); i++) {
		v1[i] = i;
	}
	TDynamicVector<int> v2(v1);
	EXPECT_EQ(v1 == v2, true);
}

TEST(TDynamicVector, compare_vector_with_itself_return_true)
{
	TDynamicVector<int> v1(7);
	for (int i = 0; i < v1.size(); i++) {
		v1[i] = i;
	}
	EXPECT_EQ(v1 == v1, true);
}

TEST(TDynamicVector, vectors_with_different_size_are_not_equal)
{
	TDynamicVector<int> v1(4), v2(5);
	EXPECT_EQ(v1 == v2, false);
}

TEST(TDynamicVector, can_add_scalar_to_vector)
{
	TDynamicVector<int> v1(5), v2(5);
	for (int i = 0; i < 5; i++) {
		v1[i] = 2;
	}
	for (int i = 0; i < 5; i++) {
		v2[i] = 4;
	}
	for (int i = 0; i < 5; i++) {
		v1[i] = v1[i] + 2;
	}
	for (int i = 0; i < 5; i++)
	{
		EXPECT_EQ(v1[i], v2[i]);
	}
}

TEST(TDynamicVector, can_subtract_scalar_from_vector)
{
	TDynamicVector<int> v1(5), v2(5);
	for (int i = 0; i < 5; i++) {
		v1[i] = 4;
	}
	for (int i = 0; i < 5; i++) {
		v2[i] = 2;
	}
	for (int i = 0; i < 5; i++) {
		v1[i] = v1[i] - 2;
	}
	for (int i = 0; i < 5; i++)
	{
		EXPECT_EQ(v1[i], v2[i]);
	}
}

TEST(TDynamicVector, can_multiply_scalar_by_vector)
{
	TDynamicVector<int> v1(5), v2(5);
	for (int i = 0; i < 5; i++) {
		v1[i] = 2;
	}
	for (int i = 0; i < 5; i++) {
		v2[i] = 4;
	}
	for (int i = 0; i < 5; i++) {
		v1[i] = v1[i] * 2;
	}
	for (int i = 0; i < 5; i++)
	{
		EXPECT_EQ(v1[i], v2[i]);
	}
}

TEST(TDynamicVector, can_add_vectors_with_equal_size)
{
  ADD_FAILURE();
}

TEST(TDynamicVector, cant_add_vectors_with_not_equal_size)
{
  ADD_FAILURE();
}

TEST(TDynamicVector, can_subtract_vectors_with_equal_size)
{
  ADD_FAILURE();
}

TEST(TDynamicVector, cant_subtract_vectors_with_not_equal_size)
{
  ADD_FAILURE();
}

TEST(TDynamicVector, can_multiply_vectors_with_equal_size)
{
  ADD_FAILURE();
}

TEST(TDynamicVector, cant_multiply_vectors_with_not_equal_size)
{
  ADD_FAILURE();
}

