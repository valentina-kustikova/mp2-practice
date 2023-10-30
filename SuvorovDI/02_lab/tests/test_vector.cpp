#include "Vector.h"
#include <gtest.h>

TEST(TVector, can_create_a_vector_with_a_positive_length) {
  ASSERT_NO_THROW(TVector<int> v(10, 0));
}

TEST(TVector, cannot_create_a_vector_with_a_negative_length) {
  ASSERT_ANY_THROW(TVector<int> v(-1, 0));
}

TEST(TVector, can_create_a_vector_with_a_positive_start_index_value) {
  ASSERT_NO_THROW(TVector<int> v(10, 4));
}

TEST(TVector, cannot_create_a_vector_with_a_negative_start_index_value) {
  ASSERT_ANY_THROW(TVector<int> v(10, -2));
}

TEST(TVector, can_create_a_vector_based_on_another_vector_with_the_same_type_of_arguments) {
  TVector<int> v1(10, 0);

  ASSERT_NO_THROW(TVector<int> v2(v1));
}

TEST(TVector, can_get_a_correct_size_of_a_vector) {
  TVector<int> v1(10, 0);

  EXPECT_EQ(v1.GetSize(), 10);
}

TEST(TVector, can_get_a_correct_start_index_value_of_a_vector) {
  TVector<int> v1(10, 3);

  EXPECT_EQ(v1.GetStartIndex(), 3);
}

TEST(TVector, can_get_the_correct_value_of_the_vector_element) {
  TVector<int> v(10);
  v[3] = 5;

  EXPECT_EQ(v[3], 5);
}

TEST(TVector, cannot_get_some_value_with_a_negative_index) {
  TVector<int> v(10);

  ASSERT_ANY_THROW(v[-3]);
} 

TEST(TVector, cannot_get_some_value_with_an_index_beyond_size) {
  TVector<int> v(10);

  ASSERT_ANY_THROW(v[15]);
}

TEST(TVector, checking_a_result_of_the_comparison_operation_for_equal_vectors) {
  TVector<int> v1(10);
  TVector<int> v2(10);
  
  v1[0] = 4;
  v1[1] = 0;
  v1[2] = 0;
  v1[3] = 0;
  v1[4] = -1;

  v2[0] = 4;
  v2[1] = 0;
  v2[2] = 0;
  v2[3] = 0;
  v2[4] = -1;

  EXPECT_EQ(v1, v2);
}

TEST(TVector, checking_a_result_of_the_comparison_operation_for_vectors_with_different_lengths) {
  TVector<int> v1(10);
  TVector<int> v2(9);
  
  v1[0] = 4;
  v1[1] = 0;
  v1[2] = 0;
  v1[3] = 0;
  v1[4] = -1;

  v2[0] = 4;
  v2[1] = 0;
  v2[2] = 0;
  v2[3] = 0;
  v2[4] = -1;

  EXPECT_NE(v1, v2);
}

TEST(TVector, checking_a_result_of_the_comparison_operation_for_vectors_with_different_start_index) {
  TVector<int> v1(10, 1);
  TVector<int> v2(10, 0);
  
  v1[0] = 4;
  v1[1] = 0;
  v1[2] = 0;
  v1[3] = 0;
  v1[4] = -1;

  v2[0] = 4;
  v2[1] = 0;
  v2[2] = 0;
  v2[3] = 0;
  v2[4] = -1;

  EXPECT_NE(v1, v2);
}

TEST(TVector, checking_a_result_of_the_comparison_operation_for_vectors_with_different_values) {
  TVector<int> v1(5);
  TVector<int> v2(5);
  
  v1[0] = 0;
  v1[1] = 0;
  v1[2] = 0;
  v1[3] = 1;
  v1[4] = -2;

  v2[0] = 4;
  v2[1] = 0;
  v2[2] = 0;
  v2[3] = 0;
  v2[4] = -1;

  EXPECT_NE(v1, v2);
}

TEST(TVector, checking_the_assignment_operation) {
  TVector<int> v1(7);
  TVector<int> v2(10);

  v1[6] = 1;
  v2[4] = -2;

  v2[0] = 4;
  v1[4] = -1;

  v1 = v2;
  EXPECT_EQ(v1, v2);
}

TEST(TVector, checking_the_correct_result_of_vector_scalar_mult) {
  TVector<int> v(4);
  TVector<int> expect_v(4);

  v[0] = 1;
  v[1] = 0;
  v[2] = 3;
  v[3] = 0;

  expect_v[0] = 4;
  expect_v[1] = 0;
  expect_v[2] = 12;
  expect_v[3] = 0;

  v = v * 4;

  EXPECT_EQ(v, expect_v);
}

TEST(TVector, checking_the_correct_result_of_vector_scalar_plus) {
  TVector<int> v(4);
  TVector<int> expect_v(4);

  
  v[0] = 1;
  v[1] = 0;
  v[2] = 3;
  v[3] = 0;

  expect_v[0] = 5;
  expect_v[1] = 4;
  expect_v[2] = 7;
  expect_v[3] = 4;

  v = v + 4;

  EXPECT_EQ(v, expect_v);
}

TEST(TVector, checking_the_correct_result_of_vector_scalar_minus) {
  TVector<int> v(4);
  TVector<int> expect_v(4);

  v[0] = 1;
  v[1] = 0;
  v[2] = 3;
  v[3] = 0;

  expect_v[0] = 0;
  expect_v[1] = -1;
  expect_v[2] = 2;
  expect_v[3] = -1;

  v = v - 1;

  EXPECT_EQ(v, expect_v);
}

TEST(TVector, checking_the_correct_result_of_vector_plus) {
  TVector<int> v1(4);
  TVector<int> v2(4);
  TVector<int> expect_v(4);

  v1[0] = 1;
  v1[1] = 0;
  v1[2] = 3;
  v1[3] = 0;

  v2[0] = 10;
  v2[1] = 6;
  v2[2] = -23;
  v2[3] = 0;

  expect_v[0] = 11;
  expect_v[1] = 6;
  expect_v[2] = -20;
  expect_v[3] = 0;

  EXPECT_EQ(v1 + v2, expect_v);
}

TEST(TVector, cannot_add_two_vectors_of_different_lengths) {
  TVector<int> v1(4);
  TVector<int> v2(2);

  ASSERT_ANY_THROW(v1 + v2);
}

TEST(TVector, checking_the_correct_result_of_vector_minus) {
  TVector<int> v1(4);
  TVector<int> v2(4);
  TVector<int> expect_v(4);

  v1[0] = 1;
  v1[1] = 0;
  v1[2] = 3;
  v1[3] = 0;

  v2[0] = 10;
  v2[1] = 6;
  v2[2] = -23;
  v2[3] = 0;

  expect_v[0] = -9;
  expect_v[1] = -6;
  expect_v[2] = 26;
  expect_v[3] = 0;

  EXPECT_EQ(v1 - v2, expect_v);
}

TEST(TVector, cannot_subtract_two_vectors_of_different_lengths) {
  TVector<int> v1(4);
  TVector<int> v2(2);

  ASSERT_ANY_THROW(v1 - v2);
}

TEST(TVector, checking_the_correct_result_of_vector_mult) {
  TVector<int> v1(4);
  TVector<int> v2(4);

  v1[0] = 2;
  v1[1] = 5;
  v1[2] = 3;
  v1[3] = 1;

  v2[0] = 2;
  v2[1] = 1;
  v2[2] = 2;
  v2[3] = 1;

  EXPECT_EQ(v1 * v2, 4.0);
}

TEST(TVector, cannot_multiply_two_vectors_of_different_lengths) {
  TVector<int> v1(4);
  TVector<int> v2(2);

  ASSERT_ANY_THROW(v1 * v2);
}
