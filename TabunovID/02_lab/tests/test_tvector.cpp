#include "tvector.h"

#include <gtest.h>

TEST(Vector, can_create_vector_with_positive_size)
{
  ASSERT_NO_THROW(Vector<int> vec(10, 0));
}

TEST(Vector, throws_when_create_vector_with_negative_size)
{
    ASSERT_ANY_THROW(Vector<int> vec(-3));
}

TEST(Vector, can_get_size)
{
  Vector<int> vec(3, 0);
  
  EXPECT_EQ(3, vec.GetSize());
}

TEST(Vector, throws_when_create_vector_with_negative_start_index)
{
  ASSERT_ANY_THROW(Vector<int> vec(10, -3));
}


TEST(Vector, can_index_vector)
{
  Vector<int> vec(3);
  vec[0] = 1;
  vec[1] = 2;
  vec[2] = 10;

  EXPECT_EQ(10, vec[2]);
}

TEST(Vector, can_assign_vectos_with_equal_size)
{
    Vector<int> vec1(3);
    vec1[0] = 1;
    vec1[1] = 2;
    vec1[2] = 10;

    Vector<int> vec2(3);
    vec2 = vec1;

    EXPECT_EQ(10, vec2[2]);
}

TEST(Vector, can_assign_vectos_with_not_equal_size)
{
    Vector<int> vec1(3);
    vec1[0] = 1;
    vec1[1] = 2;
    vec1[2] = 10;

    Vector<int> vec2(4);
    vec2 = vec1;

    EXPECT_EQ(10, vec2[2]);
}


TEST(Vector, can_add_vectors_with_equal_size)
{
    Vector<int> vec1(3);
    vec1[0] = 1;
    vec1[1] = 2;
    vec1[2] = 10;

    Vector<int> vec2(3);
    vec2[0] = 1;
    vec2[1] = 2;
    vec2[2] = 10;

    Vector<int> vec3(3);
    vec3 = vec1 + vec2;

    EXPECT_EQ(20, vec3[2]);
}

TEST(Vector, add_operator_applied_to_vectors_of_not_equal_size)
{
    Vector<int> vec1(3);
    vec1[0] = 1;
    vec1[1] = 2;
    vec1[2] = 10;

    Vector<int> vec2(4);
    vec2[0] = 1;
    vec2[1] = 2;
    vec2[2] = 10;

    ASSERT_ANY_THROW(vec1 + vec2);
}

TEST(Vector, can_add_vector_and_number)
{
    Vector<int> vec1(3);
    vec1[0] = 1;
    vec1[1] = 2;
    vec1[2] = 10;

    vec1 = vec1 + 100;

    EXPECT_EQ(110, vec1[2]);
}

TEST(Vector, can_subtract_number_from_vector)
{
    Vector<int> vec1(3);
    vec1[0] = 1;
    vec1[1] = 2;
    vec1[2] = 10;

    vec1 = vec1 - 100;

    EXPECT_EQ(-90, vec1[2]);
}

TEST(Vector, can_multiply_vector_and_number)
{
    Vector<int> vec1(3);
    vec1[0] = 1;
    vec1[1] = 2;
    vec1[2] = 10;

    vec1 = vec1 * 100;

    EXPECT_EQ(1000, vec1[2]);
}

TEST(Vector, can_subtraction_vectors_with_equal_size)
{
    Vector<int> vec1(3);
    vec1[0] = 1;
    vec1[1] = 2;
    vec1[2] = 300;

    Vector<int> vec2(3);
    vec2[0] = 1;
    vec2[1] = 2;
    vec2[2] = 10;

    Vector<int> vec3(3);
    vec3 = vec1 - vec2;

    EXPECT_EQ(290, vec3[2]);
}

TEST(Vector, subtraction_operator_applied_to_vectors_of_not_equal_size)
{
    Vector<int> vec1(3);
    vec1[0] = 1;
    vec1[1] = 2;
    vec1[2] = 300;

    Vector<int> vec2(4);
    vec2[0] = 1;
    vec2[1] = 2;
    vec2[2] = 10;


    ASSERT_ANY_THROW(vec1 - vec2);
}


TEST(Vector, can_multiplication_vectors_with_equal_size)
{
    Vector<int> vec1(3);
    vec1[0] = 1;
    vec1[1] = 2;
    vec1[2] = 10;

    Vector<int> vec2(3);
    vec2[0] = 1;
    vec2[1] = 2;
    vec2[2] = 10;

    int res;
    res = vec1 * vec2;

    EXPECT_EQ(105, res);
}

TEST(Vector, multiplication_operator_applied_to_vectors_of_not_equal_size)
{
    Vector<int> vec1(3);
    vec1[0] = 1;
    vec1[1] = 2;
    vec1[2] = 10;

    Vector<int> vec2(4);
    vec2[0] = 1;
    vec2[1] = 2;
    vec2[2] = 10;

    ASSERT_ANY_THROW(vec1 * vec2);
}


TEST(Vector, equal_vectors_are_equal)
{
    Vector<int> vec1(3);
    vec1[0] = 1;
    vec1[1] = 2;
    vec1[2] = 10;

    Vector<int> vec2(3);
    vec2[0] = 1;
    vec2[1] = 2;
    vec2[2] = 10;

    EXPECT_EQ(vec1, vec2);
}

TEST(Vector, vectors_with_equal_size_but_non_equal_are_not_equal)
{
    Vector<int> vec1(3);
    vec1[0] = 1;
    vec1[1] = 2;
    vec1[2] = 10;

    Vector<int> vec2(3);
    vec2[0] = 1;
    vec2[1] = 2;
    vec2[2] = 9;

    EXPECT_NE(vec1, vec2);
}

TEST(Vector, vectors_with_different_size_are_not_equal)
{
    Vector<int> vec1(3);
    vec1[0] = 1;
    vec1[1] = 2;
    vec1[2] = 10;

    Vector<int> vec2(4);
    vec2[0] = 1;
    vec2[1] = 2;
    vec2[2] = 10;

    EXPECT_NE(vec1, vec2);
}



TEST(Vector, triple_assignment)
{
    Vector<int> vec1(3);
    vec1[0] = 1;
    vec1[1] = 2;
    vec1[2] = 10;

    Vector<int> vec2(3);
    vec2[0] = 4;
    vec2[1] = 3;
    vec2[2] = 30;

    Vector<int> vec3(3);
    vec3 = vec2 = vec1;

    EXPECT_EQ(10, vec3[2]);
}
