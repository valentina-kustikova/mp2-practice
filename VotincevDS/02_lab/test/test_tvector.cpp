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
    TDynamicVector<int> v1(6);
    for (int i = 0; i < 6; i++) {
        v1[i] = i;
    }
    TDynamicVector<int> v2(v1);
    EXPECT_EQ(v1,v2);
  //ADD_FAILURE();
}

TEST(TDynamicVector, copied_vector_has_its_own_memory)
{
    TDynamicVector<int> v1(6);
    for (int i = 0; i < 6; i++) {
        v1[i] = i;
    }
    TDynamicVector<int> v2(v1);
    EXPECT_NE(&v1[0],&v2[0]);
  //ADD_FAILURE();
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
    TDynamicVector<int> v(2);
    ASSERT_ANY_THROW(v[-5]);
  //ADD_FAILURE();
}

TEST(TDynamicVector, throws_when_set_element_with_too_large_index)
{
    TDynamicVector<int> v(2);
    ASSERT_ANY_THROW(v[MAX_VECTOR_SIZE]);
  //ADD_FAILURE();
}

TEST(TDynamicVector, can_assign_vector_to_itself)
{
    TDynamicVector<int> v(5);
    for (int i = 0; i < v.size() ; i++) {
        v[i] = i;
    }
    EXPECT_EQ(v, v = v);
}

TEST(TDynamicVector, can_assign_vectors_of_equal_size)
{
    TDynamicVector<int> v1(5);
    TDynamicVector<int> v2(5);
    for (int i = 0; i < v1.size(); i++) {
        v1[i] = i;
    }
    v2 = v1;
    EXPECT_EQ(v1, v2);
  //ADD_FAILURE();
}

TEST(TDynamicVector, assign_operator_change_vector_size)
{
    TDynamicVector<int> v1(5);
    TDynamicVector<int> v2(50);
    for (int i = 0; i < v1.size(); i++) {
        v1[i] = i;
    }
    v2 = v1;
    EXPECT_EQ(v1.size(), v2.size());
  //ADD_FAILURE();
}

TEST(TDynamicVector, can_assign_vectors_of_different_size)
{
    TDynamicVector<int> v1(5);
    TDynamicVector<int> v2(50);
    for (int i = 0; i < v1.size(); i++) {
        v1[i] = i;
    }
    v2 = v1;
    EXPECT_EQ(v1, v2);
  //ADD_FAILURE();
}

TEST(TDynamicVector, compare_equal_vectors_return_true)
{
    TDynamicVector<int> v1(5);
    TDynamicVector<int> v2(50);
    for (int i = 0; i < v1.size(); i++) {
        v1[i] = i;
    }
    v2 = v1;
    EXPECT_EQ(1, v1==v2);
  //ADD_FAILURE();
}

TEST(TDynamicVector, compare_vector_with_itself_return_true)
{
    TDynamicVector<int> v1(20);
    for (int i = 0; i < v1.size(); i++) {
        v1[i] = i;
    }
    EXPECT_EQ(1, v1==v1);
  //ADD_FAILURE();
}

TEST(TDynamicVector, vectors_with_different_size_are_not_equal)
{
    TDynamicVector<int> v1(5);
    TDynamicVector<int> v2(6);
    for (int i = 0; i < v1.size(); i++) {
        v1[i] = i;
    }
    EXPECT_EQ(1, v1!=v2);
  //ADD_FAILURE();
}

TEST(TDynamicVector, can_add_scalar_to_vector)
{
    TDynamicVector<int> v1(5);
    TDynamicVector<int> v2(5);
    size_t scalar = 10;
    for (int i = 0; i < v1.size(); i++) {
        v1[i] = i;
        v2[i] = v1[i] + scalar;
    }
    EXPECT_EQ(v1+scalar,v2);
  //ADD_FAILURE();
}

TEST(TDynamicVector, can_subtract_scalar_from_vector)
{
    TDynamicVector<int> v1(5);
    TDynamicVector<int> v2(5);
    size_t scalar = 10;
    for (int i = 0; i < v1.size(); i++) {
        v1[i] = i*(i-3);
        v2[i] = v1[i] - scalar;
    }
    EXPECT_EQ(v1 - scalar, v2);
  //ADD_FAILURE();
}

TEST(TDynamicVector, can_multiply_scalar_by_vector)
{
    TDynamicVector<int> v1(5);
    TDynamicVector<int> v2(5);
    size_t scalar = 10;
    for (int i = 0; i < v1.size(); i++) {
        v1[i] = i*(i-15);
        v2[i] = v1[i] * scalar;
    }
    EXPECT_EQ(v1 * scalar, v2);
  //ADD_FAILURE();
}

TEST(TDynamicVector, can_add_vectors_with_equal_size)
{
    TDynamicVector<int> v1(5);
    TDynamicVector<int> v2(5);
    TDynamicVector<int> res(5);
    for (int i = 0; i < v1.size(); i++) {
        v1[i] = i*(i-1);
        v2[i] = (i-3) * (i-10);
        res[i] = v1[i] + v2[i];
    }
    EXPECT_EQ(v1 + v2, res);
  //ADD_FAILURE();
}

TEST(TDynamicVector, cant_add_vectors_with_not_equal_size)
{
  ADD_FAILURE();
}

TEST(TDynamicVector, can_subtract_vectors_with_equal_size)
{
    TDynamicVector<int> v1(5);
    TDynamicVector<int> v2(5);
    TDynamicVector<int> res(5);
    for (int i = 0; i < v1.size(); i++) {
        v1[i] = i * (i - 1);
        v2[i] = (i - 3) * (i - 10);
        res[i] = v1[i] - v2[i];
    }
    EXPECT_EQ(v1 - v2, res);
  //ADD_FAILURE();
}

TEST(TDynamicVector, cant_subtract_vectors_with_not_equal_size)
{
  ADD_FAILURE();
}

TEST(TDynamicVector, can_multiply_vectors_with_equal_size)
{
    TDynamicVector<int> v1(5);
    TDynamicVector<int> v2(5);
    int res = 0;
    for (int i = 0; i < v1.size(); i++) {
        v1[i] = i * (i - 1);
        v2[i] = (i - 3) * (i - 10);
        res += v1[i] * v2[i];
    }
    EXPECT_EQ(v1 * v2, res);
  //ADD_FAILURE();
}

TEST(TDynamicVector, cant_multiply_vectors_with_not_equal_size)
{
  ADD_FAILURE();
}

