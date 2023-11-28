#include "vector.h"
#include <gtest.h>

TEST(Vector, can_create_vector_with_positive_length)
{
    ASSERT_NO_THROW(Vector<int> v(5));
}

TEST(Vector, throws_when_create_vector_with_negative_length)
{
    ASSERT_ANY_THROW(Vector<int> v(-5));
}

TEST(Vector, can_create_copied_vector)
{
    Vector<int> v(10);

    ASSERT_NO_THROW(Vector<int> v1(v));
}

TEST(Vector, copied_vector_is_equal_to_source_one)
{
    Vector<int> v(4);
    v[0] = 0;
    v[1] = 1;
    v[2] = 2;
    v[3] = 3;
    Vector<int> v1(v);
    EXPECT_EQ(v, v1);
}

TEST(Vector, copied_vector_has_its_own_memory)
{
    Vector<int> v(4);
    v[0] = 0;
    v[1] = 1;
    v[2] = 2;
    v[3] = 3;

    Vector<int> v1(v);
    v1[2] = 0;

    EXPECT_NE(v, v1);
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


TEST(Vector, can_set_and_get_element)
{
    Vector<int> v(4, 2);
    v[0] = 4;

    EXPECT_EQ(4, v[0]);
}

TEST(Vector, throws_when_set_element_with_negative_index)
{
    Vector<int>v(4, 2);
    ASSERT_ANY_THROW(v[-1] = 1);
}

TEST(Vector, can_assign_vector_to_itself)
{
    Vector<int>v(4);
    v[0] = 1;
    ASSERT_NO_THROW(v = v);
}

TEST(Vector, assign_operator_of_different_size)
{
    Vector<int> v1(4);
    v1[0] = 0;
    v1[1] = 1;
    v1[2] = 2;
    v1[3] = 3;
    Vector<int> v2(5);
    v2[0] = 0;
    v2[1] = 1;
    v2[2] = 2;
    v2[3] = 3;
    v2 = v1;
    EXPECT_EQ(v1, v2);
}

TEST(Vector, can_assign_vectors_of_equal_size)
{
    Vector<int> v1(4);
    v1[0] = 0;
    v1[1] = 1;
    v1[2] = 2;
    v1[3] = 3;
    Vector<int> v2(4);
    v2[0] = 0;
    v2[1] = 1;
    v2[2] = 2;
    v2[3] = 3;
    v2 = v1;
    EXPECT_EQ(v1, v2);
}

TEST(Vector, compare_equal_vectors_return_true)
{
    Vector<int> v1(4);
    v1[0] = 0;
    v1[1] = 1;
    v1[2] = 2;
    v1[3] = 3;
    Vector<int> v2(4);
    v2[0] = 0;
    v2[1] = 1;
    v2[2] = 2;
    v2[3] = 3;
    EXPECT_EQ(v1, v2);
}

TEST(Vector, compare_vector_with_itself_return_true)
{
    Vector<int> v1(4);
    v1[0] = 0;
    v1[1] = 1;
    v1[2] = 2;
    v1[3] = 3;
    EXPECT_EQ(v1, v1);
}

TEST(Vector, vectors_with_different_size_are_not_equal)
{
    Vector<int> v1(4);
    v1[0] = 0;
    v1[1] = 1;
    v1[2] = 2;
    v1[3] = 3;
    Vector<int> v2(5);
    v2[0] = 1;
    v2[1] = 2;
    v2[2] = 3;
    v2[3] = 4;
    v2[4] = 5;
    EXPECT_NE(v1, v2);
}

TEST(Vector, can_add_scalar_to_vector)
{
    Vector<int> v1(4);
    v1[0] = 0;
    v1[1] = 1;
    v1[2] = 2;
    v1[3] = 3;
    Vector<int> v2(4);
    v2[0] = 1;
    v2[1] = 2;
    v2[2] = 3;
    v2[3] = 4;
    EXPECT_EQ(v1 + 1, v2);
}

TEST(Vector, can_subtract_scalar_from_vector)
{
    Vector<int> v1(4);
    v1[0] = 0;
    v1[1] = 1;
    v1[2] = 2;
    v1[3] = 3;
    Vector<int> v2(4);
    v2[0] = -1;
    v2[1] = 0;
    v2[2] = 1;
    v2[3] = 2;
    EXPECT_EQ(v1 - 1, v2);
}

TEST(Vector, can_multiply_scalar_by_vector)
{
    Vector<int> v1(4);
    v1[0] = 0;
    v1[1] = 1;
    v1[2] = 2;
    v1[3] = 3;
    Vector<int> v2(4);
    v2[0] = 0;
    v2[1] = 2;
    v2[2] = 4;
    v2[3] = 6;
    EXPECT_EQ(v1 * 2, v2);
}

TEST(Vector, can_add_vectors_with_equal_size)
{
    Vector<int> v1(4);
    v1[0] = 0;
    v1[1] = 1;
    v1[2] = 2;
    v1[3] = 3;
    Vector<int> v2(4);
    v2[0] = 0;
    v2[1] = 1;
    v2[2] = 2;
    v2[3] = 3;
    Vector<int> v3(4);
    v3[0] = 0;
    v3[1] = 2;
    v3[2] = 4;
    v3[3] = 6;
    EXPECT_EQ(v1 + v2, v3);
}

TEST(Vector, cant_add_vectors_with_not_equal_size)
{
    Vector<int> v1(5);
    v1[0] = 0;
    v1[1] = 1;
    v1[2] = 2;
    v1[3] = 3;
    v1[4] = 3;
    Vector<int> v2(6);
    v2[0] = 0;
    v2[1] = 1;
    v2[2] = 2;
    v2[3] = 3;
    v2[4] = 3;
    v2[5] = 3;
    ASSERT_ANY_THROW(v1 + v2);
}

TEST(Vector, can_subtract_vectors_with_equal_size)
{
    Vector<int> v1(4);
    v1[0] = 0;
    v1[1] = 1;
    v1[2] = 2;
    v1[3] = 3;
    Vector<int> v2(4);
    v2[0] = 0;
    v2[1] = 1;
    v2[2] = 2;
    v2[3] = 3;
    Vector<int> v3(4);
    v3[0] = 0;
    v3[1] = 0;
    v3[2] = 0;
    v3[3] = 0;
    EXPECT_EQ(v1 - v2, v3);
}

TEST(Vector, cant_subtract_vectors_with_not_equal_size)
{
    Vector<int> v1(5);
    v1[0] = 0;
    v1[1] = 1;
    v1[2] = 2;
    v1[3] = 3;
    v1[4] = 4;
    Vector<int> v2(6);
    v2[0] = 0;
    v2[1] = 1;
    v2[2] = 2;
    v2[3] = 3;
    v2[4] = 4;
    v2[5] = 5;
    ASSERT_ANY_THROW(v1 - v2);
}

TEST(Vector, can_multiply_vectors_with_equal_size)
{
    Vector<int> v1(4);
    v1[0] = 0;
    v1[1] = 1;
    v1[2] = 2;
    v1[3] = 3;
    Vector<int> v2(4);
    v2[0] = 0;
    v2[1] = 1;
    v2[2] = 2;
    v2[3] = 3;
    EXPECT_EQ(v1 * v2, 14);
}

TEST(Vector, cant_multiply_vectors_with_not_equal_size)
{
    Vector<int> v1(3);
    v1[0] = 0;
    v1[1] = 1;
    v1[2] = 2;
    Vector<int> v2(4);
    v2[0] = 0;
    v2[1] = 1;
    v2[2] = 2;
    v2[3] = 3;
    ASSERT_ANY_THROW(v1 * v2);
}