#include "tvector.h"
#include <gtest.h>

TEST(TVector, can_create_vector_with_positive_length) // с начальным индексом
{
    ASSERT_NO_THROW(TVector<int> v(3, 1));
}

TEST(TVector, throws_when_create_vector_with_negative_length)
{
    ASSERT_ANY_THROW(TVector<int> v(-5, 1));
}

TEST(TVector, can_get_size)
{
    TVector<int> v(3, 1);
    EXPECT_EQ(3, v.GetSize());
}

TEST(TVector, can_get_start_index)
{
    TVector<int> v(3, 1);
    EXPECT_EQ(1, v.GetIndex());
}

TEST(TVector, can_create_copied_vector)
{
    TVector<int> v(10, 1);
    ASSERT_NO_THROW(TVector<int> v1(v));
}

TEST(TVector, copied_vector_is_equal_to_source_one)
{
    TVector<int> v(3, 0);
    v[0] = 0;
    v[1] = 1;
    v[2] = 2;
    TVector<int> v1(v);
    EXPECT_EQ(v, v1);
}

TEST(TVector, copied_vector_has_its_own_memory)
{
    TVector<int> v(3, 1);
    v[0] = 0;
    v[1] = 1;
    v[2] = 2;
    TVector<int> v1(v);
    v1[2] = 0;
    EXPECT_NE(v, v1);
}

TEST(TVector, when_position_is_less_than_0_false)
{
    TVector<int> v(3);
    ASSERT_ANY_THROW(v[-4]);
}

TEST(TVector, when_position_is_greater_than_len_false)
{
    TVector<int> v(3, 1);
    ASSERT_ANY_THROW(v[4]);
}

TEST(TVector, can_set_and_get_element)
{
    TVector<int> v(2, 1);
    v[1] = 3;
    EXPECT_EQ(3, v[1]);
}

TEST(TVector, can_assign_vector_to_itself)
{
    TVector<int>value(3, 1);
    value[1] = 1;
    ASSERT_NO_THROW(value = value);
}

TEST(TVector, throws_when_position_is_greater_than_size)
{
    TVector<int> v(3);
    ASSERT_ANY_THROW(v[5]);
}

TEST(TVector, assign_operator_of_different_size)
{
    TVector<int> v1(3, 1);
    v1[1] = 1;
    v1[2] = 2;
    TVector<int> v2(4, 1);
    v2[1] = 1;
    v2[2] = 2;
    v2 = v1;
    EXPECT_EQ(v1, v2);
}

TEST(TVector, can_assign_vectors_of_equal_size)
{
    TVector<int> v1(3, 1);
    v1[1] = 1;
    v1[2] = 2;
    TVector<int> v2(3);
    v2[1] = 1;
    v2[2] = 2;
    v2 = v1;
    EXPECT_EQ(v1, v2);
}

TEST(TVector, compare_equal_vectors)
{
    TVector<int> v1(3, 1);
    v1[1] = 1;
    v1[2] = 2;
    TVector<int> v2(3, 1);
    v2[1] = 1;
    v2[2] = 2;
    ASSERT_TRUE(v1 == v2);
}

TEST(TVector, vectors_with_different_size_are_not_equal)
{
    TVector<int> v1(3, 1);
    v1[1] = 1;
    v1[2] = 2;
    TVector<int> v2(4, 1);
    v2[1] = 2;
    v2[2] = 3;
    v2[3] = 4;
    ASSERT_FALSE(v1 == v2);
}

TEST(TVector, can_addit_number_to_vector)
{
    TVector<int> v1(3, 1);
    v1[0] = 0;
    v1[1] = 1;
    v1[2] = 2;
    TVector<int> v2(3, 1);
    v2[0] = 1;
    v2[1] = 2;
    v2[2] = 3;
    EXPECT_EQ(v1 + 1, v2);
}

TEST(TVector, can_add_vectors_of_the_same_size)
{
    TVector<int> v1(3, 1);
    v1[0] = 1;
    v1[1] = 1;
    v1[2] = 1;
    TVector<int> v2(3, 1);
    v2[0] = 1;
    v2[1] = 1;
    v2[2] = 1;
    TVector<int> v3(3, 1);
    v3[0] = 2;
    v3[1] = 2;
    v3[2] = 2;
    EXPECT_EQ(v1 + v2, v3);
}

TEST(TVector, can_subtract_number_from_vector)
{
    TVector<int> v1(3, 1);
    v1[0] = 0;
    v1[1] = 1;
    v1[2] = 2;
    TVector<int> v2(3, 1);
    v2[0] = -1;
    v2[1] = 0;
    v2[2] = 1;
    EXPECT_EQ(v1 - 1, v2);
}

TEST(TVector, can_multiply_scalar_by_vector)
{
    TVector<int> v1(3, 1);
    v1[0] = 1;
    v1[1] = 1;
    v1[2] = 1;
    TVector<int> v2(3, 1);
    v2[0] = 2;
    v2[1] = 2;
    v2[2] = 2;
    EXPECT_EQ(v1 * 2, v2);
}

TEST(TVector, can_subtract_vectors_with_same_size)
{
    TVector<int> v1(3, 1);
    v1[0] = 1;
    v1[1] = 1;
    v1[2] = 1;
    TVector<int> v2(3, 1);
    v2[0] = 1;
    v2[1] = 1;
    v2[2] = 1;
    TVector<int> v3(3, 1);
    v3[0] = 0;
    v3[1] = 0;
    v3[2] = 0;
    EXPECT_EQ(v1 - v2, v3);
}

TEST(TVector, can_multiply_vectors_with_same_size)
{
    TVector<int> v1(3, 1);
    v1[0] = 1;
    v1[1] = 1;
    v1[2] = 1;
    TVector<int> v2(3, 1);
    v2[0] = 1;
    v2[1] = 1;
    v2[2] = 1;
    EXPECT_EQ(v1 * v2, 3);
}

TEST(TVector, cant_add_vectors_with_not_same_size)
{
    TVector<int> v1(3, 1);
    v1[0] = 0;
    v1[1] = 1;
    v1[2] = 2;
    TVector<int> v2(4, 1);
    v2[0] = 0;
    v2[1] = 1;
    v2[2] = 2;
    v2[3] = 3;
    ASSERT_ANY_THROW(v1 + v2);
}

TEST(TVector, cant_subtract_vectors_with_not_same_size)
{
    TVector<int> v1(3, 1);
    v1[0] = 0;
    v1[1] = 1;
    v1[2] = 2;
    TVector<int> v2(4, 1);
    v2[0] = 0;
    v2[1] = 1;
    v2[2] = 2;
    v2[3] = 3;
    ASSERT_ANY_THROW(v1 - v2);
}

TEST(TVector, cant_multiply_vectors_with_not_same_size)
{
    TVector<int> v1(4, 1);
    v1[0] = 0;
    v1[1] = 1;
    v1[2] = 2;
    TVector<int> v2(6, 1);
    v2[0] = 0;
    v2[1] = 1;
    v2[2] = 2;
    v2[3] = 3;
    ASSERT_ANY_THROW(v1 * v2);
}

TEST(TVector, can_create_vector_with_positive_size_without_start_index)// без начального индекса
{
    ASSERT_NO_THROW(TVector<int> v(3));
}

TEST(TVector, cant_create_vector_with_negative_size_without_start_index)
{
    ASSERT_ANY_THROW(TVector<int> v(-3));
}

TEST(TVector, can_create_copied_vector_without_start_index)
{
    TVector<int> v(3);
    ASSERT_NO_THROW(TVector<int> vector1(v));
}

TEST(TVector, can_get_size_without_start_index)
{
    TVector<int> v(5);
    EXPECT_EQ(5, v.GetSize());
}

TEST(TVector, can_index_vector_without_start_index)
{
    TVector<int> v(3);
    v[0] = 1;
    v[1] = 2;
    v[2] = 3;
    EXPECT_EQ(1, v[0]);
}

TEST(TVector, cant_negative_index_vector_without_start_index)
{
    TVector<int> v(2);
    ASSERT_ANY_THROW(v[-2] = 1);
}

TEST(TVector, can_assign_vectors_with_equal_size_without_start_index)
{
    TVector<int> v1(3);
    v1[0] = 1;
    v1[1] = 2;
    v1[2] = 3;
    TVector<int> v2(3);
    v2 = v1;
    EXPECT_EQ(v1, v2);
}

TEST(TVector, can_assign_vectors_with_different_size_without_start_index)
{
    TVector<int> v1(3);
    v1[0] = 1;
    v1[1] = 2;
    v1[2] = 3;
    TVector<int> v2(5);
    v2 = v1;
    EXPECT_EQ(v1, v2);
}

TEST(TVector, can_addit_vectors_with_equal_size_without_start_index)
{
    TVector<int> v1(3);
    v1[0] = 1;
    v1[1] = 2;
    v1[2] = 3;
    TVector<int> v2(3);
    v2[0] = 1;
    v2[1] = 2;
    v2[2] = 3;
    TVector<int> v3(3);
    v3[0] = 2;
    v3[1] = 4;
    v3[2] = 6;
    EXPECT_EQ(v1 + v2, v3);
}

TEST(TVector, cant_addit_vectors_of_different_size_without_start_index)
{
    TVector<int> v1(3);
    v1[0] = 1;
    v1[1] = 2;
    v1[2] = 3;
    TVector<int> v2(5);
    v2[0] = 1;
    v2[1] = 2;
    v2[2] = 3;

    ASSERT_ANY_THROW(v1 + v2);
}

TEST(TVector, can_subtract_operator_without_start_index)
{
    TVector<int> v1(3);
    v1[0] = 1;
    v1[1] = 2;
    v1[2] = 3;

    TVector<int> v2(3);
    v2[0] = 1;
    v2[1] = 2;
    v2[2] = 3;

    TVector<int> v3(3);
    v3[0] = 0;
    v3[1] = 0;
    v3[2] = 0;

    EXPECT_EQ(v3, v1 - v2);
}

TEST(TVector, can_multiply_vectors_with_same_size_without_start_index)
{
    TVector<int> v1(3);
    v1[0] = 1;
    v1[1] = 1;
    v1[2] = 1;
    TVector<int> v2(3);
    v2[0] = 1;
    v2[1] = 1;
    v2[2] = 1;
    EXPECT_EQ(v1 * v2, 3);
}

TEST(TVector, cant_subtract_vectors_of_differrent_size_without_start_index)
{
    TVector<int> v1(3);
    v1[0] = 1;
    v1[1] = 2;
    v1[2] = 3;
    TVector<int> v2(5);
    v2[0] = 1;
    v2[1] = 2;
    v2[2] = 3;

    ASSERT_ANY_THROW(v1 - v2);
}

TEST(TVector, can_multiply_vectors_of_different_size_without_start_index)
{
    TVector<int> v1(3);
    v1[0] = 1;
    v1[1] = 2;
    v1[2] = 3;
    TVector<int> v2(5);
    v2[0] = 1;
    v2[1] = 2;
    v2[2] = 3;

    ASSERT_ANY_THROW(v1 * v2);
}
