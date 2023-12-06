#include "vector.h"
#include <gtest.h>
//with start index
TEST(TVector, can_create_vector_with_positive_length)
{
    ASSERT_NO_THROW(TVector<int> vector(3,1));
}

TEST(TVector, throws_when_create_vector_with_negative_length)
{
    ASSERT_ANY_THROW(TVector<int> vector(-5,1));
}

TEST(TVector, can_create_copied_vector)
{
    TVector<int> vector(10,1);
    ASSERT_NO_THROW(TVector<int> vector1(vector));
}

TEST(TVector, copied_vector_is_equal_to_source_one)
{
    TVector<int> vector(3,0);
    vector[0] = 0;
    vector[1] = 1;
    vector[2] = 2;
    TVector<int> vector1(vector);
    EXPECT_EQ(vector, vector1);
}

TEST(TVector, copied_vector_has_its_own_memory)
{
    TVector<int> vector(3,1);
    vector[0] = 0;
    vector[1] = 1;
    vector[2] = 2;
    TVector<int> vector1(vector);
    vector1[2] = 0;
    EXPECT_NE(vector, vector1);
}

TEST(TVector, can_get_size)
{
    TVector<int> vector(3,1);
    EXPECT_EQ(3, vector.getSize());
}

TEST(TVector, can_get_start_index)
{
    TVector<int> vector(3, 1);
    EXPECT_EQ(1, vector.getStartIndex());
}

TEST(TVector, cant_when_set_element_with_negative_index)
{
    TVector<int>value(4, 1);
    ASSERT_ANY_THROW(value[-6] = 1); //>len
}

TEST(TVector, can_set_and_get_element)
{
    TVector<int> vector(2, 1);
    vector[1] = 3;
    EXPECT_EQ(3, vector[1]);
}

TEST(TVector, can_assign_vector_to_itself)
{
    TVector<int>value(3,0);
    value[0] = 1;
    ASSERT_NO_THROW(value = value);
}

TEST(TVector, assign_operator_of_different_size)
{
    TVector<int> vector1(3,1);
    vector1[1] = 1;
    vector1[2] = 2;
    TVector<int> vector2(4,1);
    vector2[1] = 1;
    vector2[2] = 2;
    vector2 = vector1;
    EXPECT_EQ(vector1, vector2);
}

TEST(TVector, can_assign_vectors_of_equal_size)
{
    TVector<int> vector1(3,1);
    vector1[1] = 1;
    vector1[2] = 2;
    TVector<int> vector2(3);
    vector2[1] = 1;
    vector2[2] = 2;
    vector2 = vector1;
    EXPECT_EQ(vector1, vector2);
}

TEST(TVector, compare_equal_vectors)
{
    TVector<int> vector1(3,1);
    vector1[1] = 1;
    vector1[2] = 2;
    TVector<int> vector2(3,1);
    vector2[1] = 1;
    vector2[2] = 2;
    EXPECT_EQ(vector1, vector2);
}

TEST(TVector, vectors_with_different_size_are_not_equal)
{
    TVector<int> vector1(3,1);
    vector1[1] = 1;
    vector1[2] = 2;
    TVector<int> vector2(4,1);
    vector2[1] = 2;
    vector2[2] = 3;
    vector2[3] = 4;
    EXPECT_NE(vector1, vector2);
}

TEST(TVector, can_addition_numbers_to_vector)
{
    TVector<int> vector1(3,1);
    vector1[0] = 0;
    vector1[1] = 1;
    vector1[2] = 2;
    TVector<int> vector2(3,1);
    vector2[0] = 1;
    vector2[1] = 2;
    vector2[2] = 3;
    EXPECT_EQ(vector1 + 1, vector2);
}

TEST(TVector, can_subtraction_numbers_from_vector)
{
    TVector<int> vector1(3,1);
    vector1[0] = 0;
    vector1[1] = 1;
    vector1[2] = 2;
    TVector<int> vector2(3,1);
    vector2[0] = -1;
    vector2[1] = 0;
    vector2[2] = 1;
    EXPECT_EQ(vector1 - 1, vector2);
}

TEST(TVector, can_multiplication_scalar_by_vector)
{
    TVector<int> vector1(3,0);
    vector1[0] = 1;
    vector1[1] = 1;
    vector1[2] = 1;
    TVector<int> vector2(3,0);
    vector2[0] = 2;
    vector2[1] = 2;
    vector2[2] = 2;
    EXPECT_EQ(vector1 * 2, vector2);
}

TEST(TVector, can_addition_vectors_of_the_same_size)
{
    TVector<int> vector1(3,0);
    vector1[0] = 1;
    vector1[1] = 1;
    vector1[2] = 1;
    TVector<int> vector2(3,0);
    vector2[0] = 1;
    vector2[1] = 1;
    vector2[2] = 1;
    TVector<int> vector3(3,0);
    vector3[0] = 2;
    vector3[1] = 2;
    vector3[2] = 2;
    EXPECT_EQ(vector1 + vector2, vector3);
}

TEST(TVector, can_subtraction_vectors_with_same_size)
{
    TVector<int> vector1(3,0);
    vector1[0] = 1;
    vector1[1] = 1;
    vector1[2] = 1;
    TVector<int> vector2(3,0);
    vector2[0] = 1;
    vector2[1] = 1;
    vector2[2] = 1;
    TVector<int> vector3(3,0);
    vector3[0] = 0;
    vector3[1] = 0;
    vector3[2] = 0;
    EXPECT_EQ(vector1 - vector2, vector3);
}

TEST(TVector, can_multiplication_vectors_with_same_size)
{
    TVector<int> vector1(3,0);
    vector1[0] = 1;
    vector1[1] = 1;
    vector1[2] = 1;
    TVector<int> vector2(3,0);
    vector2[0] = 1;
    vector2[1] = 1;
    vector2[2] = 1;
    EXPECT_EQ(vector1 * vector2, 3);
}

TEST(TVector, cant_struct_vectors_with_not_same_size)
{
    TVector<int> vector1(3,0);
    vector1[0] = 0;
    vector1[1] = 1;
    vector1[2] = 2;
    TVector<int> vector2(4,0);
    vector2[0] = 0;
    vector2[1] = 1;
    vector2[2] = 2;
    vector2[3] = 3;
    ASSERT_ANY_THROW(vector1 + vector2);
}

TEST(TVector, cant_subtraction_vectors_with_not_same_size)
{
    TVector<int> vector1(3,0);
    vector1[0] = 0;
    vector1[1] = 1;
    vector1[2] = 2;
    TVector<int> vector2(4,0);
    vector2[0] = 0;
    vector2[1] = 1;
    vector2[2] = 2;
    vector2[3] = 3;
    ASSERT_ANY_THROW(vector1 - vector2);
}

TEST(TVector, cant_multiplication_vectors_with_not_same_size)   
{
    TVector<int> vector1(4,0);
    vector1[0] = 0;
    vector1[1] = 1;
    vector1[2] = 2;
    TVector<int> vector2(6,0);
    vector2[0] = 0;
    vector2[1] = 1;
    vector2[2] = 2;
    vector2[3] = 3;
    ASSERT_ANY_THROW(vector1 * vector2);
}

//without start index
TEST(TVector, can_create_vector_with_positive_size_without_start_index)
{
    ASSERT_NO_THROW(TVector<int> vector(3));
}

TEST(TVector, cant_create_vector_with_negative_size_without_start_index)
{
    ASSERT_ANY_THROW(TVector<int> vector(-3));
}

TEST(TVector, can_create_copied_vector_without_start_index)
{
    TVector<int> vector(3);
    ASSERT_NO_THROW(TVector<int> vector1(vector));
}

TEST(TVector, can_get_size_without_start_index)
{
    TVector<int> vector(5);
    EXPECT_EQ(5, vector.getSize());
}

TEST(Vector,  can_index_vector_without_start_index)
{
    TVector<int> vector(3);
    vector[0] = 1;
    vector[1] = 2;
    vector[2] = 3;
    EXPECT_EQ(1, vector[0]);
}

TEST(TVector, cant_negative_index_vector_without_start_index)
{
    TVector<int> vector(2);
    ASSERT_ANY_THROW(vector[-2] = 1);
}

TEST(TVector, can_assign_vectors_with_equal_size_without_start_index)
{
    TVector<int> vector1(3);
    vector1[0] = 1;
    vector1[1] = 2;
    vector1[2] = 3;
    TVector<int> vector2(3);
    vector2 = vector1;
    EXPECT_EQ(vector1, vector2);
}

TEST(TVector, can_assign_vectors_with_different_size_without_start_index)
{
    TVector<int> vector1(3);
    vector1[0] = 1;
    vector1[1] = 2;
    vector1[2] = 3;
    TVector<int> vector2(5);
    vector2 = vector1;
    EXPECT_EQ(vector1, vector2);
}

TEST(TVector, can_addition_vectors_with_equal_size_without_start_index)
{
    TVector<int> vector1(3);
    vector1[0] = 1;
    vector1[1] = 2;
    vector1[2] = 3;
    TVector<int> vector2(3);
    vector2[0] = 1;
    vector2[1] = 2;
    vector2[2] = 3;
    TVector<int> vector3(3);
    vector3[0] = 2;
    vector3[1] = 4;
    vector3[2] = 6;
    EXPECT_EQ(vector1+vector2,vector3);
}

TEST(TVector, cant_addition_vectors_of_different_size_without_start_index)
{
    TVector<int> vector1(3);
    vector1[0] = 1;
    vector1[1] = 2;
    vector1[2] = 3;
    TVector<int> vector2(5);
    vector2[0] = 1;
    vector2[1] = 2;
    vector2[2] = 3;

    ASSERT_ANY_THROW(vector1 + vector2);
}

TEST(TVector, can_subtraction_operator_without_start_index)
{
    TVector<int> vector1(3);
    vector1[0] = 1;
    vector1[1] = 2;
    vector1[2] = 3;

    TVector<int> vector2(3);
    vector2[0] = 1;
    vector2[1] = 2;
    vector2[2] = 3;

    TVector<int> vector3(3);
    vector3[0] = 0;
    vector3[1] = 0;
    vector3[2] = 0;

    EXPECT_EQ(vector3, vector1 - vector2);
}

TEST(TVector, cant_subtraction_vectors_of_differrent_size_without_start_index)
{
    TVector<int> vector1(3);
    vector1[0] = 1;
    vector1[1] = 2;
    vector1[2] = 3;
    TVector<int> vector2(5);
    vector2[0] = 1;
    vector2[1] = 2;
    vector2[2] = 3;

    ASSERT_ANY_THROW(vector1 - vector2);
}

TEST(TVector, can_multiplication_vectors_of_different_size_without_start_index)
{
    TVector<int> vector1(3);
    vector1[0] = 1;
    vector1[1] = 2;
    vector1[2] = 3;
    TVector<int> vector2(5);
    vector2[0] = 1;
    vector2[1] = 2;
    vector2[2] = 3;

    ASSERT_ANY_THROW(vector1 * vector2);
}

TEST(TVector, can_multiplication_vectors_with_same_size_without_start_index)
{
    TVector<int> vector1(3);
    vector1[0] = 1;
    vector1[1] = 1;
    vector1[2] = 1;
    TVector<int> vector2(3);
    vector2[0] = 1;
    vector2[1] = 1;
    vector2[2] = 1;
    EXPECT_EQ(vector1 * vector2, 3);
}


