#include "tvector.h"

#include <gtest.h>

TEST(Vector, can_create_vector_with_positive_size_without_start_index)
{
  ASSERT_NO_THROW(Vector<int> vec(10));
}

TEST(Vector, can_create_vector_with_positive_size_with_start_index)
{
    ASSERT_NO_THROW(Vector<int> vec(10, 1));
}


TEST(Vector, throws_when_create_vector_with_negative_size_without_start_index)
{
    ASSERT_ANY_THROW(Vector<int> vec(-3));
}

TEST(Vector, throws_when_create_vector_with_negative_size_with_start_index)
{
    ASSERT_ANY_THROW(Vector<int> vec(-3, 2));
}


TEST(Vector, can_create_copied_vector_without_start_index)
{
    Vector<int> a(3);

    ASSERT_NO_THROW(Vector<int> b(a));
}

TEST(Vector, can_create_copied_vector_with_start_index)
{
    Vector<int> a(3, 1);

    ASSERT_NO_THROW(Vector<int> b(a));
}


TEST(Vector, can_get_size_without_start_index)
{
  Vector<int> vec(3);
  
  EXPECT_EQ(3, vec.GetSize());
}

TEST(Vector, can_get_size_with_start_index)
{
    Vector<int> vec(3, 2);

    EXPECT_EQ(3, vec.GetSize());
}


TEST(Vector, throws_when_create_vector_with_negative_start_index)
{
  ASSERT_ANY_THROW(Vector<int> vec(10, -3));
}


TEST(Vector, can_index_vector_without_start_index)
{
  Vector<int> vec(3);
  vec[0] = 1;
  vec[1] = 2;
  vec[2] = 10;

  EXPECT_EQ(10, vec[2]);
}

TEST(Vector, can_index_vector_with_start_index)
{
    Vector<int> vec(3,3);
    vec[0] = 1;
    vec[1] = 2;
    vec[2] = 10;

    EXPECT_EQ(10, vec[2]);
}


TEST(Vector, throws_when_negative_index_vector_without_start_index)
{
    Vector<int> vec(3);
    ASSERT_ANY_THROW(vec[-2] = 2);
}

TEST(Vector, throws_when_negative_index_vector_with_start_index)
{
    Vector<int> vec(3, 2);
    ASSERT_ANY_THROW(vec[-2] = 2);
}

TEST(Vector, throws_when_too_large_index_vector_without_start_index)
{
    Vector<int> vec(3);
    ASSERT_ANY_THROW(vec[10] = 2);
}

TEST(Vector, throws_when_too_large_index_vector_with_start_index)
{
    Vector<int> vec(3, 2);
    ASSERT_ANY_THROW(vec[10] = 2);
}


TEST(Vector, can_assign_vectors_with_equal_size_without_start_index)
{
    Vector<int> vec1(3);
    vec1[0] = 1;
    vec1[1] = 2;
    vec1[2] = 10;

    Vector<int> vec2(3);
    vec2 = vec1;

    EXPECT_EQ(vec1, vec2);
}

TEST(Vector, can_assign_vectors_with_equal_size_with_start_index)
{
    Vector<int> vec1(3,3);
    vec1[0] = 1;
    vec1[1] = 2;
    vec1[2] = 10;

    Vector<int> vec2(3);
    vec2 = vec1;

    EXPECT_EQ(vec1, vec2);
}


TEST(Vector, can_assign_vectors_with_not_equal_size_without_start_index)
{
    Vector<int> vec1(3);
    vec1[0] = 1;
    vec1[1] = 2;
    vec1[2] = 10;

    Vector<int> vec2(4);
    vec2 = vec1;

    EXPECT_EQ(vec1, vec2);
}

TEST(Vector, can_assign_vectors_with_not_equal_size_with_equal_start_index)
{
    Vector<int> vec1(3, 3);
    vec1[0] = 1;
    vec1[1] = 2;
    vec1[2] = 10;

    Vector<int> vec2(4, 3);
    vec2 = vec1;

    EXPECT_EQ(vec1, vec2);
}

TEST(Vector, can_assign_vectors_with_not_equal_size_with_not_equal_start_index)
{
    Vector<int> vec1(3, 3);
    vec1[0] = 1;
    vec1[1] = 2;
    vec1[2] = 10;

    Vector<int> vec2(4, 5);
    vec2 = vec1;

    EXPECT_EQ(vec1, vec2);
}

TEST(Vector, can_add_vectors_with_equal_size_without_start_index)
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
    ASSERT_NO_THROW(vec3 = vec1 + vec2);
}

TEST(Vector, can_add_vectors_with_equal_size_with_equal_start_index)
{
    Vector<int> vec1(3,3);
    vec1[0] = 1;
    vec1[1] = 2;
    vec1[2] = 10;

    Vector<int> vec2(3,3);
    vec2[0] = 1;
    vec2[1] = 2;
    vec2[2] = 10;

    Vector<int> vec3(3);
    ASSERT_NO_THROW(vec3 = vec1 + vec2);
}

TEST(Vector, can_add_vectors_with_equal_size_with_not_equal_start_index)
{
    Vector<int> vec1(3, 2);
    vec1[0] = 1;
    vec1[1] = 2;
    vec1[2] = 10;

    Vector<int> vec2(3, 3);
    vec2[0] = 1;
    vec2[1] = 2;
    vec2[2] = 10;

    Vector<int> vec3(3);
    ASSERT_ANY_THROW(vec3 = vec1 + vec2);
}

TEST(Vector, add_operator_applied_to_vectors_of_not_equal_size_without_start_index)
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

TEST(Vector, add_operator_applied_to_vectors_of_not_equal_size_with_equal_start_index)
{
    Vector<int> vec1(3, 3);
    vec1[0] = 1;
    vec1[1] = 2;
    vec1[2] = 10;

    Vector<int> vec2(4, 3);
    vec2[0] = 1;
    vec2[1] = 2;
    vec2[2] = 10;
    vec2[3] = 10;

    ASSERT_ANY_THROW(vec1 + vec2);
}

TEST(Vector, add_operator_applied_to_vectors_of_not_equal_size_with_not_equal_start_index)
{
    Vector<int> vec1(3, 3);
    vec1[0] = 1;
    vec1[1] = 2;
    vec1[2] = 10;

    Vector<int> vec2(4, 2);
    vec2[0] = 1;
    vec2[1] = 2;
    vec2[2] = 10;
    vec2[3] = 10;

    ASSERT_ANY_THROW(vec1 + vec2);
}

TEST(Vector, correct_work_add_operator_without_start_index)
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
    vec3[0] = 2;
    vec3[1] = 4;
    vec3[2] = 20;

    EXPECT_EQ(vec3, vec2 + vec1);;
}

TEST(Vector, correct_work_add_operator_with_equal_start_index)
{
    Vector<int> vec1(3, 3);
    vec1[0] = 1;
    vec1[1] = 2;
    vec1[2] = 10;

    Vector<int> vec2(3, 3);
    vec2[0] = 1;
    vec2[1] = 2;
    vec2[2] = 10;

    Vector<int> vec3(3, 3);
    vec3[0] = 2;
    vec3[1] = 4;
    vec3[2] = 20;

    EXPECT_EQ(vec3, vec2 + vec1);;
}



TEST(Vector, can_add_vector_and_number_without_start_index)
{
    Vector<int> vec1(3);
    vec1[0] = 1;
    vec1[1] = 2;
    vec1[2] = 10;

    vec1 = vec1 + 100;

    Vector<int> vec2(3);
    vec2[0] = 101;
    vec2[1] = 102;
    vec2[2] = 110;

    EXPECT_EQ(vec1, vec2);
}

TEST(Vector, can_add_vector_and_number_with_start_index)
{
    Vector<int> vec1(3, 3);
    vec1[0] = 1;
    vec1[1] = 2;
    vec1[2] = 10;

    vec1 = vec1 + 100;

    Vector<int> vec2(3, 3);
    vec2[0] = 101;
    vec2[1] = 102;
    vec2[2] = 110;

    EXPECT_EQ(vec1, vec2);
}


TEST(Vector, can_subtract_number_from_vector_without_start_index)
{
    Vector<int> vec1(3);
    vec1[0] = 1;
    vec1[1] = 2;
    vec1[2] = 10;

    vec1 = vec1 - 100;

    Vector<int> vec2(3);
    vec2[0] = -99;
    vec2[1] = -98;
    vec2[2] = -90;

    EXPECT_EQ(vec1, vec2);
}

TEST(Vector, can_subtract_number_from_vector_with_start_index)
{
    Vector<int> vec1(3, 3);
    vec1[0] = 1;
    vec1[1] = 2;
    vec1[2] = 10;

    vec1 = vec1 - 100;

    Vector<int> vec2(3, 3);
    vec2[0] = -99;
    vec2[1] = -98;
    vec2[2] = -90;

    EXPECT_EQ(vec1, vec2);
}

TEST(Vector, can_multiply_vector_and_number_without_start_index)
{
    Vector<int> vec1(3);
    vec1[0] = 1;
    vec1[1] = 2;
    vec1[2] = 10;


    vec1 = vec1 * 100;
    Vector<int> vec2(3);
    vec2[0] = 100;
    vec2[1] = 200;
    vec2[2] = 1000;

    EXPECT_EQ(vec1, vec2);
}

TEST(Vector, can_multiply_vector_and_number_with_start_index)
{
    Vector<int> vec1(3, 3);
    vec1[0] = 1;
    vec1[1] = 2;
    vec1[2] = 10;

    vec1 = vec1 * 100;
 
    Vector<int> vec2(3, 3);
    vec2[0] = 100;
    vec2[1] = 200;
    vec2[2] = 1000;

    EXPECT_EQ(vec1, vec2);
}

TEST(Vector, can_subtraction_vectors_with_equal_size_without_start_index)
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
    ASSERT_NO_THROW(vec3 = vec1 - vec2);
}

TEST(Vector, can_subtraction_vectors_with_equal_size_with_equal_start_index)
{
    Vector<int> vec1(3, 3);
    vec1[0] = 1;
    vec1[1] = 2;
    vec1[2] = 300;

    Vector<int> vec2(3, 3);
    vec2[0] = 1;
    vec2[1] = 2;
    vec2[2] = 10;

    Vector<int> vec3(3, 3);
    ASSERT_NO_THROW(vec3 = vec1 - vec2);
}

TEST(Vector, subtraction_operator_applied_to_vectors_of_equal_size_with_not_equal_start_index)
{
    Vector<int> vec1(3, 2);
    vec1[0] = 1;
    vec1[1] = 2;
    vec1[2] = 300;

    Vector<int> vec2(3, 3);
    vec2[0] = 1;
    vec2[1] = 2;
    vec2[2] = 10;

    ASSERT_ANY_THROW(vec1 - vec2);
}

TEST(Vector, subtraction_operator_applied_to_vectors_of_not_equal_size_without_start_index)
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

TEST(Vector, subtraction_operator_applied_to_vectors_of_not_equal_size_with_equal_start_index)
{
    Vector<int> vec1(3, 3);
    vec1[0] = 1;
    vec1[1] = 2;
    vec1[2] = 300;

    Vector<int> vec2(4, 3);
    vec2[0] = 1;
    vec2[1] = 2;
    vec2[2] = 10;


    ASSERT_ANY_THROW(vec1 - vec2);
}

TEST(Vector, subtraction_operator_applied_to_vectors_of_not_equal_size_with_not_equal_start_index)
{
    Vector<int> vec1(3, 2);
    vec1[0] = 1;
    vec1[1] = 2;
    vec1[2] = 300;

    Vector<int> vec2(4, 3);
    vec2[0] = 1;
    vec2[1] = 2;
    vec2[2] = 10;


    ASSERT_ANY_THROW(vec1 - vec2);
}

TEST(Vector, correct_work_subtraction_operator_without_start_index)
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
    vec3[0] = 0;
    vec3[1] = 0;
    vec3[2] = 290;

    EXPECT_EQ(vec3, vec1 - vec2);
}

TEST(Vector, correct_work_subtraction_operator_with_equal_start_index)
{
    Vector<int> vec1(3, 3);
    vec1[0] = 1;
    vec1[1] = 2;
    vec1[2] = 300;

    Vector<int> vec2(3, 3);
    vec2[0] = 1;
    vec2[1] = 2;
    vec2[2] = 10;

    Vector<int> vec3(3,3);
    vec3[0] = 0;
    vec3[1] = 0;
    vec3[2] = 290;

    EXPECT_EQ(vec3, vec1 - vec2);
}


TEST(Vector, can_multiplication_vectors_with_equal_size_without_start_index)
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
    ASSERT_NO_THROW(res = vec1 * vec2);
}

TEST(Vector, can_multiplication_vectors_with_equal_size_with_equal_start_index)
{
    Vector<int> vec1(3, 3);
    vec1[0] = 1;
    vec1[1] = 2;
    vec1[2] = 10;

    Vector<int> vec2(3, 3);
    vec2[0] = 1;
    vec2[1] = 2;
    vec2[2] = 10;

    int res;
    ASSERT_NO_THROW(res = vec1 * vec2);
}

TEST(Vector, can_multiplication_vectors_with_equal_size_with_not_equal_start_index)
{
    Vector<int> vec1(3, 3);
    vec1[0] = 1;
    vec1[1] = 2;
    vec1[2] = 10;

    Vector<int> vec2(3, 2);
    vec2[0] = 1;
    vec2[1] = 2;
    vec2[2] = 10;

    int res;
    ASSERT_ANY_THROW(res = vec1 * vec2);
}

TEST(Vector, multiplication_operator_applied_to_vectors_of_not_equal_size_without_start_index)
{
    Vector<int> vec1(3);
    vec1[0] = 1;
    vec1[1] = 2;
    vec1[2] = 10;

    Vector<int> vec2(4);
    vec2[0] = 1;
    vec2[1] = 2;
    vec2[2] = 10;

    int res;
    ASSERT_ANY_THROW(res = vec1 * vec2);
}


TEST(Vector, multiplication_operator_applied_to_vectors_of_not_equal_size_with_equal_start_index)
{
    Vector<int> vec1(3, 3);
    vec1[0] = 1;
    vec1[1] = 2;
    vec1[2] = 10;

    Vector<int> vec2(4, 3);
    vec2[0] = 1;
    vec2[1] = 2;
    vec2[2] = 10;

    int res;
    ASSERT_ANY_THROW(res = vec1 * vec2);
}

TEST(Vector, multiplication_operator_applied_to_vectors_of_not_equal_size_with_not_equal_start_index)
{
    Vector<int> vec1(3, 3);
    vec1[0] = 1;
    vec1[1] = 2;
    vec1[2] = 10;

    Vector<int> vec2(4, 2);
    vec2[0] = 1;
    vec2[1] = 2;
    vec2[2] = 10;

    int res;
    ASSERT_ANY_THROW(res = vec1 * vec2);
}

TEST(Vector, correct_work_smultiplication_operator_without_start_index)
{
    Vector<int> vec1(3);
    vec1[0] = 1;
    vec1[1] = 2;
    vec1[2] = 10;

    Vector<int> vec2(3);
    vec2[0] = 1;
    vec2[1] = 2;
    vec2[2] = 10;

    int res = 105;
    EXPECT_EQ(res, vec1 * vec2);
}

TEST(Vector, correct_work_smultiplication_operator_with_equal_start_index)
{
    Vector<int> vec1(3, 3);
    vec1[0] = 1;
    vec1[1] = 2;
    vec1[2] = 10;

    Vector<int> vec2(3, 3);
    vec2[0] = 1;
    vec2[1] = 2;
    vec2[2] = 10;

    int res = 105;
    EXPECT_EQ(res, vec1 * vec2);
}


TEST(Vector, equal_vectors_without_start_index)
{
    Vector<int> vec1(3);
    vec1[0] = 1;
    vec1[1] = 2;
    vec1[2] = 10;

    Vector<int> vec2(3);
    vec2[0] = 1;
    vec2[1] = 2;
    vec2[2] = 10;

    ASSERT_TRUE(vec1 == vec2);
}

TEST(Vector, equal_vectors_with_equal_start_index)
{
    Vector<int> vec1(3, 3);
    vec1[0] = 1;
    vec1[1] = 2;
    vec1[2] = 10;

    Vector<int> vec2(3, 3);
    vec2[0] = 1;
    vec2[1] = 2;
    vec2[2] = 10;

    ASSERT_TRUE(vec1 == vec2);
}

TEST(Vector, equal_vectors_with_not_equal_start_index)
{
    Vector<int> vec1(3, 3);
    vec1[0] = 1;
    vec1[1] = 2;
    vec1[2] = 10;

    Vector<int> vec2(3, 2);
    vec2[0] = 1;
    vec2[1] = 2;
    vec2[2] = 10;

    ASSERT_TRUE(vec1 != vec2);
}

TEST(Vector, not_equal_vectors_without_start_index)
{
    Vector<int> vec1(3);
    vec1[0] = 1;
    vec1[1] = 2;
    vec1[2] = 10;

    Vector<int> vec2(3);
    vec2[0] = 1;
    vec2[1] = 2;
    vec2[2] = 9;

    ASSERT_TRUE(vec1 != vec2);
}

TEST(Vector, not_equal_vectors_with_equal_start_index)
{
    Vector<int> vec1(3, 3);
    vec1[0] = 1;
    vec1[1] = 2;
    vec1[2] = 10;

    Vector<int> vec2(3, 3);
    vec2[0] = 1;
    vec2[1] = 2;
    vec2[2] = 9;

    ASSERT_TRUE(vec1 != vec2);
}

TEST(Vector, not_equal_vectors_with_not_equal_start_index)
{
    Vector<int> vec1(3, 3);
    vec1[0] = 1;
    vec1[1] = 2;
    vec1[2] = 10;

    Vector<int> vec2(3, 2);
    vec2[0] = 1;
    vec2[1] = 2;
    vec2[2] = 9;

    ASSERT_TRUE(vec1 != vec2);
}

TEST(Vector, vectors_with_different_size_without_start_index)
{
    Vector<int> vec1(3);
    vec1[0] = 1;
    vec1[1] = 2;
    vec1[2] = 10;

    Vector<int> vec2(4);
    vec2[0] = 1;
    vec2[1] = 2;
    vec2[2] = 10;

    ASSERT_TRUE(vec1 != vec2);
}

TEST(Vector, vectors_with_different_size_with_equal_start_index)
{
    Vector<int> vec1(3, 3);
    vec1[0] = 1;
    vec1[1] = 2;
    vec1[2] = 10;

    Vector<int> vec2(4, 3);
    vec2[0] = 1;
    vec2[1] = 2;
    vec2[2] = 10;

    ASSERT_TRUE(vec1 != vec2);
}

TEST(Vector, vectors_with_different_size_with_not_equal_start_index)
{
    Vector<int> vec1(3, 3);
    vec1[0] = 1;
    vec1[1] = 2;
    vec1[2] = 10;

    Vector<int> vec2(4, 2);
    vec2[0] = 1;
    vec2[1] = 2;
    vec2[2] = 10;

    ASSERT_TRUE(vec1 != vec2);
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
