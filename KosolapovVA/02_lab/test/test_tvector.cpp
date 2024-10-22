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
    TDynamicVector<int> v(3);
    for (int i = 0; i < v.size(); i++)
        v[i] = i;
    TDynamicVector<int> v1(v);
  EXPECT_EQ(v, v1);
}

TEST(TDynamicVector, copied_vector_has_its_own_memory)
{
   TDynamicVector<int> v(10);
   for (int i = 0; i < v.size(); i++) 
       v[i] = i;
   TDynamicVector<int> v1(v);
   EXPECT_NE(&v, &v1);
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
  ASSERT_ANY_THROW(v.at(10));
}

TEST(TDynamicVector, can_assign_vector_to_itself)
{
    TDynamicVector<int> v1(3), v2(4);
    v1[0] = 1;
    v1[1] = 2;
    v1[2] = 3;

    v2[0] = 2;
    v2[1] = 2;
    v2[2] = 2;
    v2[3] = 3;
    v1 = v2;
    EXPECT_EQ(v1, v2);
}

TEST(TDynamicVector, can_assign_vectors_of_equal_size)
{
    const int size = 4;
    TDynamicVector<int> v1(size), v2(size);
    v1[0] = 1;
    v1[1] = 2;
    v2 = v1;
    EXPECT_EQ(v1, v2);
}

TEST(TDynamicVector, assign_operator_change_vector_size)
{
    const int size =4;
    TDynamicVector<int> v1(3), v2(size);
    v1[0] = 1;
    v1[1] = 2;
    v1[2] = 3;

    v2[0] = 2;
    v2[1] = 2;
    v2[2] = 2;
    v2[3] = 3;
    v1 = v2;
    EXPECT_EQ(v1.size(), size);
}

TEST(TDynamicVector, can_assign_vectors_of_different_size)
{
    TDynamicVector<int> v1(3), v2(4);
    v1[0] = 1;
    v1[1] = 2;
    v1[2] = 3;

    v2[0] = 2;
    v2[1] = 2;
    v2[2] = 2;
    v2[3] = 3;
    v1 = v2;
    EXPECT_EQ(v1, v2);
}

TEST(TDynamicVector, compare_equal_vectors_return_true)
{
    int size = 3;
    TDynamicVector<int> v1(size), v2(size);
    v1[0] = 1;
    v1[1] = 1;
    v1[2] = 1;
    v2[0] = 1;
    v2[1] = 1;
    v2[2] = 1;
    // v1=(1,1,1),  v2=(1,1,1)
    EXPECT_EQ(1, (v1==v2));
}

TEST(TDynamicVector, compare_vector_with_itself_return_true)
{
    int size = 3;
    TDynamicVector<int> v1(size);
    v1[0] = 1;
    v1[1] = 1;
    v1[2] = 1;
    EXPECT_EQ(1, (v1 == v1));
}

TEST(TDynamicVector, vectors_with_different_size_are_not_equal)
{
    TDynamicVector<int> v1(2), v2(3);
    v1[0] = 1;
    v1[1] = 1;
    v2[0] = 1;
    v2[1] = 1;
    v2[2] = 1;
    // v1=(1,1),  v2=(1,1,1)
    EXPECT_EQ(1, (v1 != v2));
}

TEST(TDynamicVector, can_add_scalar_to_vector)
{
    int size = 3;
    TDynamicVector<int> v1(size), v2(size), v_res(size);
    v1[0] = 1;
    v1[1] = 1;
    v1[2] = 1;
    int scalar = 5;
    v2 = v1 + scalar;
    v_res[0] = 6;
    v_res[1] = 6;
    v_res[2] = 6;
    // v1=(1,1,1),  v_res=(6,6,6)
    EXPECT_EQ(v_res, v2);
}

TEST(TDynamicVector, can_subtract_scalar_from_vector)
{
    int size = 3;
    TDynamicVector<int> v1(size), v2(size), v_res(size);
    v1[0] = 6;
    v1[1] = 6;
    v1[2] = 6;
    int scalar = 5;
    v2 = v1 - scalar;
    v_res[0] = 1;
    v_res[1] = 1;
    v_res[2] = 1;
    // v_res=(1,1,1),  v1=(6,6,6)
    EXPECT_EQ(v_res, v2);
}

TEST(TDynamicVector, can_multiply_scalar_by_vector)
{
    int size = 3;
    TDynamicVector<int> v1(size), v2(size), v_res(size);
    v1[0] = 1;
    v1[1] = 1;
    v1[2] = 1;
    int scalar = 5;
    v2 = v1 * scalar;
    v_res[0] = 5;
    v_res[1] = 5;
    v_res[2] = 5;
    // v_res=(5,5,5),  v1=(6,6,6)
    EXPECT_EQ(v_res, v2);
}

TEST(TDynamicVector, can_add_vectors_with_equal_size)
{
    int size = 3;
    TDynamicVector<int> v1(size), v2(size), v3(size), v_res(size);
    v1[0] = 1;
    v1[1] = 1;
    v1[2] = 1;

    v2[0] = 1;
    v2[1] = 1;
    v2[2] = 1;
    v3 = v1+v2;
    v_res[0] = 2;
    v_res[1] = 2;
    v_res[2] = 2;
    //v1=(1,1,1), v2=(1,1,1), v_res=(2,2,2)
    EXPECT_EQ(v_res, v3);
}

TEST(TDynamicVector, cant_add_vectors_with_not_equal_size)
{
    TDynamicVector<int> v1(3), v2(4), v3(4);
    v1[0] = 1;
    v1[1] = 1;
    v1[2] = 1;

    v2[0] = 1;
    v2[1] = 1;
    v2[2] = 1;
    v2[3] = 1;
    ASSERT_ANY_THROW(v3=v2+v1);
}

TEST(TDynamicVector, can_subtract_vectors_with_equal_size)
{
    int size = 3;
    TDynamicVector<int> v1(size), v2(size), v3(size), v_res(size);
    v1[0] = 2;
    v1[1] = 2;
    v1[2] = 2;

    v2[0] = 1;
    v2[1] = 1;
    v2[2] = 1;
    v3 = v1 - v2;
    v_res[0] = 1;
    v_res[1] = 1;
    v_res[2] = 1;
    //v1=(2,2,2), v2=(1,1,1), v_res=(2,2,2)
    EXPECT_EQ(v_res, v3);
}

TEST(TDynamicVector, cant_subtract_vectors_with_not_equal_size)
{
    TDynamicVector<int> v1(3), v2(4), v3(4);
    v1[0] = 1;
    v1[1] = 1;
    v1[2] = 1;

    v2[0] = 1;
    v2[1] = 1;
    v2[2] = 1;
    v2[3] = 1;
    ASSERT_ANY_THROW(v3 = v2 - v1);
}

TEST(TDynamicVector, can_multiply_vectors_with_equal_size)
{
    int size = 3;
    TDynamicVector<int> v1(size), v2(size);
    v1[0] = 2;
    v1[1] = 2;
    v1[2] = 2;

    v2[0] = 3;
    v2[1] = 3;
    v2[2] = 3;
    int res = v1 * v2;
    int e_res = 18;
    EXPECT_EQ(e_res, res);
}

TEST(TDynamicVector, cant_multiply_vectors_with_not_equal_size)
{
    TDynamicVector<int> v1(3), v2(4);
    int v3;
    v1[0] = 1;
    v1[1] = 1;
    v1[2] = 1;

    v2[0] = 1;
    v2[1] = 1;
    v2[2] = 1;
    v2[3] = 1;
    ASSERT_ANY_THROW(v3 = v1*v2);
}

