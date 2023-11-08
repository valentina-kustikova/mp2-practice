#include "TVector.h"

#include <gtest.h>

TEST(TVector, create_vector_with_positive_length_without_start_index)
{
    ASSERT_NO_THROW(TVector<int> vec(3));
}

TEST(TVector, create_vector_with_positive_length_with_start_index)
{
    ASSERT_NO_THROW(TVector<int> vec(3,1));
}

TEST(TVector, create_vector_with_zero_length)
{
    ASSERT_ANY_THROW(TVector<int> vec(0));
}

TEST(TVector, create_vector_with_negative_length_without_start_index)
{
    ASSERT_ANY_THROW(TVector<int> vec(-3));
}

TEST(TVector, create_vector_with_negative_length_with_start_index)
{
    ASSERT_ANY_THROW(TVector<int> vec(-3,1));
}

TEST(TVector, copy_constructor_test)
{
    TVector<int> v(2);
    ASSERT_NO_THROW(TVector<int> vec(v));
}

TEST(TVector, copy_constructor_test_with_start_index)
{
    TVector<int> v(2,1);
    ASSERT_NO_THROW(TVector<int> vec(v));
}

TEST(TVector, can_get_size)
{
    TVector<int> vec(3, 0);

    EXPECT_EQ(3, vec.GetSize());
}

TEST(TVector, can_get_start_index)
{
    TVector<int> vec(3, 1);

    EXPECT_EQ(1, vec.GetStart());
}

TEST(TVector, getting_by_index_without_start_index)
{
    TVector<int> vec(3);
    vec[0] = 4;
    vec[1] = 3;
    vec[2] = 1;
    EXPECT_EQ(3, vec[1]);
}

TEST(TVector, getting_by_index_with_start_index)
{
    TVector<int> vec(3, 1);
    vec[1] = 4;
    vec[2] = 3;
    vec[3] = 1;
    EXPECT_EQ(3, vec[2]);
}

TEST(TVector, large_index_with_start_index)
{
    TVector<int> vec(3, 1);
    ASSERT_ANY_THROW(vec[4]);
}

TEST(TVector, large_index_without_start_index)
{
    TVector<int> vec(3);
    ASSERT_ANY_THROW(vec[4]);
}

TEST(TVector, negative_index_with_start_index)
{
    TVector<int> vec(3, 1);
    ASSERT_ANY_THROW(vec[-1]);
}

TEST(TVector, negative_index_without_start_index)
{
    TVector<int> vec(3);
    ASSERT_ANY_THROW(vec[-1]);
}

TEST(TVector, less_than_start_index_with_start_index)
{
    TVector<int> vec(3, 1);
    ASSERT_ANY_THROW(vec[0]);
}

TEST(TVector, assignment_check_without_start_index)
{
    TVector<int> vec1(3);
    TVector<int> vec2(3);
    for (int i = 0; i < 3; i++)
    {
        vec1[i] = i;
        vec2[i] = i + 2;
    }
    vec2 = vec1;
    EXPECT_EQ(vec1, vec2);
}

TEST(TVector, assignment_with_different_length_without_start_index)
{
    TVector<int> vec1(3);
    TVector<int> vec2(5);
    for (int i = 0; i < 3; i++)
        vec1[i] = i;
    for (int j = 0; j < 5; j++)
        vec2[j] = j + 2;
    vec2 = vec1;
    EXPECT_EQ(3, vec2.GetSize());
}

TEST(TVector, comparison_for_equality_false_without_start_index)
{
    TVector<int> vec1(3);
    TVector<int> vec2(3);
    for (int i = 0; i < 3; i++)
    {
        vec1[i] = i;
        vec2[i] = i + 2;
    }
    
    EXPECT_EQ(0, vec1==vec2);
}
TEST(TVector, comparison_for_equality_true_without_start_index)
{
    TVector<int> vec1(3);
    TVector<int> vec2(3);
    for (int i = 0; i < 3; i++)
    {
        vec1[i] = i;
        vec2[i] = i;
    }

    EXPECT_EQ(1, vec1 == vec2);
}

TEST(TVector, comparison_for_equality_with_diferent_length_without_start_index)
{
    TVector<int> vec1(3);
    TVector<int> vec2(5);
 
    EXPECT_EQ(0, vec1 == vec2);
}

TEST(TVector, comparison_for_inequality_false_without_start_index)
{
    TVector<int> vec1(3);
    TVector<int> vec2(3);
    for (int i = 0; i < 3; i++)
    {
        vec1[i] = i;
        vec2[i] = i + 2;
    }

    EXPECT_EQ(1, vec1 != vec2);
}
TEST(TVector, comparison_for_inequality_true_without_start_index)
{
    TVector<int> vec1(3);
    TVector<int> vec2(3);
    for (int i = 0; i < 3; i++)
    {
        vec1[i] = i;
        vec2[i] = i;
    }

    EXPECT_EQ(0, vec1 != vec2);
}

TEST(TVector, comparison_for_inequality_with_diferent_length_without_start_index)
{
    TVector<int> vec1(3);
    TVector<int> vec2(5);

    EXPECT_EQ(1, vec1 != vec2);
}

TEST(TVector, vector_plus_scalar_without_start_index)
{
    TVector<int> vec1(3);
    TVector<int> vec2(3);
    for (int i = 0; i < 3; i++)
    {
        vec1[i] = i;
        vec2[i] = i + 2;
    }
    EXPECT_EQ(vec2, vec1+2);
}

TEST(TVector, vector_minus_scalar_without_start_index)
{
    TVector<int> vec1(3);
    TVector<int> vec2(3);
    for (int i = 0; i < 3; i++)
    {
        vec1[i] = i;
        vec2[i] = i - 2;
    }
    EXPECT_EQ(vec2, vec1-2);
}

TEST(TVector, vector_multiply_scalar_without_start_index)
{
    TVector<int> vec1(3);
    for (int i = 0; i < 3; i++)
        vec1[i] = i + 2;
    TVector<int> vec2(3);
    for (int i = 0; i < 3; i++)
        vec2[i] = (i + 2) * 3;
    EXPECT_EQ(vec2, vec1 * 3);
}

TEST(TVector, exception_vector_plus_vector_due_to_start_index)
{
    TVector<int> vec1(3, 0);
    TVector<int> vec2(3, 1);
    ASSERT_ANY_THROW(vec1 + vec2);
}

TEST(TVector, exception_vector_plus_vector_due_to_length_without_start_index)
{
    TVector<int> vec1(3);
    TVector<int> vec2(4);
    ASSERT_ANY_THROW(vec1 + vec2);
}

TEST(TVector, vector_plus_vector_without_start_index)
{
    TVector<int> vec1(3);
    TVector<int> vec2(3);
    TVector<int> vec3(3);

    for (int i = 0; i < 3; i++)
    {
        vec1[i] = i + 1;
        vec2[i] = 4;
        vec3[i] = i + 1 + 4;
    }

    EXPECT_EQ(vec3, vec1 + vec2);
}

TEST(TVector, exception_vector_minus_vector_due_to_start_index)
{
    TVector<int> vec1(3, 0);
    TVector<int> vec2(3, 1);
    ASSERT_ANY_THROW(vec1 - vec2);
}
TEST(TVector, exception_vector_minus_vector_due_to_length)
{
    TVector<int> vec1(3, 0);
    TVector<int> vec2(2, 0);
    ASSERT_ANY_THROW(vec1 - vec2);
}

TEST(TVector, vector_minus_vector_without_start_index)
{
    TVector<int> vec1(4);
    TVector<int> vec2(4);
    TVector<int> vec3(4);

    for (int i = 0; i < 4; i++)
    {
        vec1[i] = i + 1;
        vec2[i] = 4;
        vec3[i] = i + 1 - 4;
    }

    EXPECT_EQ(vec3, vec1 - vec2);
}

TEST(TVector, exception_vector_multiply_vector_due_to_start_index)
{
    TVector<int> vec1(3, 0);
    TVector<int> vec2(3, 1);
    ASSERT_ANY_THROW(vec1 * vec2);
}
TEST(TVector, exception_vector_multiply_vector_due_to_length)
{
    TVector<int> vec1(3, 0);
    TVector<int> vec2(2, 0);
    ASSERT_ANY_THROW(vec1 * vec2);
}

TEST(TVector, vector_multiply_vector)
{
    TVector<int> vec1(4, 0);
    TVector<int> vec2(4, 0);
    TVector<int> vec3(4, 0);

    for (int i = 0; i < 4; i++) 
    {
        vec1[i] = i;
        vec2[i] = i+1;
    }

    EXPECT_EQ(20, vec1 * vec2);
}
