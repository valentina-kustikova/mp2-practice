#include <gtest.h>
#include "matrix.h"

TEST(Vector, can_create_vector_with_positive_length)
{
    ASSERT_NO_THROW(Vector<int> v(5));
}

TEST(Vector, throws_when_create_vector_with_negative_length)
{
    ASSERT_ANY_THROW(Vector<int> v(-5));
}

TEST(Vector, throws_when_create_vector_with_negative_startindex)
{
    ASSERT_ANY_THROW(Vector<int> v(5, -2));
}

TEST(Vector, can_create_copied_vector)
{
    Vector<int> v(10);
    ASSERT_NO_THROW(Vector<int> v1(v));
}

TEST(Vector, copied_vector_is_equal_to_source_one)
{
    Vector<int> v(5);
    v[0] = 1;
    Vector<int> v1(v);
    EXPECT_EQ(v, v1);
}

TEST(Vector, copied_vector_has_its_own_memory)
{
    Vector<int> v(5);
    Vector<int> v1(v);
    v[0] = 1;
    v1[0] = 2;
    EXPECT_NE(v[0], v1[0]);
}

TEST(Vector, can_get_size)
{
    Vector<int> v(4);
    EXPECT_EQ(4, v.getSize());
}

TEST(Vector, can_get_start_index)
{
    Vector<int> v(4, 2);
    EXPECT_EQ(2, v.getStartIndex());
}

TEST(Vector, throws_when_set_element_with_negative_index)
{
    Vector<int> v(4);
    ASSERT_ANY_THROW(v[-1] = 4);
}

TEST(Vector, throws_when_set_element_with_too_large_index)
{
    Vector<int> v(4);
    ASSERT_ANY_THROW(v[5] = 4);
}

TEST(Vector, can_assign_vectors_of_equal_size)
{
    Vector<int> v1(4);
    Vector<int> v2(4);
    v1[0] = 1;
    v2 = v1;
    EXPECT_EQ(v1, v2);
}

TEST(Vector, can_assign_vectors_of_different_size)
{
    Vector<int> v1(4);
    Vector<int> v2(2);
    v1[0] = 1;
    v2 = v1;
    EXPECT_EQ(4, v2.getSize());
    EXPECT_EQ(v1[0], v2[0]);
}

TEST(Vector, compare_equal_vectors_return_true)
{
    Vector<int> v1(4);
    Vector<int> v2(4);
    v1[0] = 1;
    v2 = v1;
    EXPECT_TRUE(v1 == v2);
}

TEST(Vector, compare_vector_with_itself_return_true)
{
    Vector<int> v(4);
    EXPECT_TRUE(v == v);
}

TEST(Vector, vectors_with_different_size_are_not_equal)
{
    Vector<int> v(4);
    Vector<int> v1(5);
    EXPECT_FALSE(v == v1);
}

TEST(Vector, can_add_scalar_to_vector)
{
    Vector<int> v(4);
    v[0] = 1;
    Vector<int> result = v + 2;
    EXPECT_EQ(3, result[0]);
}

TEST(Vector, can_subtract_scalar_from_vector)
{
    Vector<int> v(4);
    v[0] = 3;
    Vector<int> result = v - 1;
    EXPECT_EQ(2, result[0]);
}

TEST(Vector, can_multiply_scalar_by_vector)
{
    Vector<int> v(4);
    v[0] = 2;
    Vector<int> result = v * 3;
    EXPECT_EQ(6, result[0]);
}

TEST(Vector, can_add_vectors_with_equal_size)
{
    Vector<int> v1(3);
    Vector<int> v2(3);
    v1[0] = 1;
    v2[0] = 2;
    Vector<int> result = v1 + v2;
    EXPECT_EQ(3, result[0]);
}

TEST(Vector, cant_add_vectors_with_not_equal_size)
{
    Vector<int> v(1);
    Vector<int> v1(10);
    ASSERT_ANY_THROW(v + v1);
}

TEST(Vector, can_subtract_vectors_with_equal_size)
{
    Vector<int> v1(3);
    Vector<int> v2(3);
    v1[0] = 5;
    v2[0] = 2;
    Vector<int> result = v1 - v2;
    EXPECT_EQ(3, result[0]);
}

TEST(Vector, cant_subtract_vectors_with_not_equal_size)
{
    Vector<int> v(10);
    Vector<int> v1(1);
    ASSERT_ANY_THROW(v - v1);
}

TEST(Vector, can_multiply_vectors_with_equal_size)
{
    int result = 6;
    Vector<int> v(4);
    Vector<int> v1(4);
    for (int i = 0; i < 4; i++)
    {
        v[i] = i;
        v1[i] = 1;
    }
    EXPECT_EQ(result, v * v1);
}

TEST(Vector, cant_multiply_vectors_with_not_equal_size)
{
    Vector<int> v(1);
    Vector<int> v1(10);
    ASSERT_ANY_THROW(v * v1);
}