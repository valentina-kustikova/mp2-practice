#include "Matrix.h"
#include <gtest.h>

TEST(TMatrix, can_create_a_matrix_with_a_positive_length) {
  ASSERT_NO_THROW(TMatrix<int> m(4));
}

TEST(TMatrix, cannot_create_a_matrix_with_a_negative_length) {
  ASSERT_ANY_THROW(TMatrix<int> m(-4));
}

TEST(TMatrix, can_create_a_matrix_based_on_another_matrix_with_the_same_type_of_arguments) {
  TMatrix<int> m1(6);

  ASSERT_NO_THROW(TMatrix<int> m2(m1););
}

TEST(TMatrix, can_create_a_matrix_based_on_a_vector_with_the_same_type_of_arguments) {
  TVector<TVector<int>> v(6);

  ASSERT_NO_THROW(TMatrix<int> m2(v););
}

TEST(TMatrix, checking_correctness_of_the_comparison_operation_for_an_equal_matrixes) {
  TMatrix<int> m1(2);
  TMatrix<int> m2(2);

  m1[0][0] = -12;
  m1[0][1] = 2;
  m1[1][0] = 5;

  m2[0][0] = -12;
  m2[0][1] = 2;
  m2[1][0] = 5;

  EXPECT_EQ(m1, m2);
}

TEST(TMatrix, checking_correctness_of_the_comparison_operation_for_an_matrixes_with_different_values) {
  TMatrix<int> m1(2);
  TMatrix<int> m2(2);

  m1[0][0] = -5;
  m1[0][1] = 2;
  m1[1][0] = 0;

  m2[0][0] = -12;
  m2[0][1] = 2;
  m2[1][0] = 5;

  EXPECT_NE(m1, m2);
}

TEST(TMatrix, checking_correctness_of_the_comparison_operation_for_an_matrixes_with_different_sizes) {
  TMatrix<int> m1(1);
  TMatrix<int> m2(2);

  m1[0][0] = -5;

  m2[0][0] = -12;
  m2[0][1] = 2;
  m2[1][0] = 5;

  EXPECT_NE(m1, m2);
}

TEST(TMatrix, checking_the_matrix_assignment_operation) {
  TMatrix<int> m1(2);
  TMatrix<int> m2(1);

  m1[0][0] = -12;
  m1[0][1] = 2;
  m1[1][0] = 5;

  m2[0][0] = -5;

  m1 = m2;
  EXPECT_EQ(m1, m2);
}

TEST(TMatrix, checking_the_correct_result_of_matrix_plus) {
  TMatrix<int> m1(2);
  TMatrix<int> m2(2);
  TMatrix<int> expect_m(2);

  m1[0][0] = -12;
  m1[0][1] = 2;
  m1[1][0] = 5;

  m2[0][0] = 1;
  m2[0][1] = 9;
  m2[1][0] = 3;

  expect_m[0][0] = -11;
  expect_m[0][1] = 11;
  expect_m[1][0] = 8;

  EXPECT_EQ(m1 + m2, expect_m);
}

TEST(TMatrix, checking_the_correct_result_of_matrix_minus) {
  TMatrix<int> m1(2);
  TMatrix<int> m2(2);
  TMatrix<int> expect_m(2);

  m1[0][0] = -12;
  m1[0][1] = 2;
  m1[1][0] = 5;

  m2[0][0] = 1;
  m2[0][1] = 9;
  m2[1][0] = 3;

  expect_m[0][0] = -13;
  expect_m[0][1] = -7;
  expect_m[1][0] = 2;

  EXPECT_EQ(m1 - m2, expect_m);
}

TEST(TMatrix, checking_the_correct_result_of_matrix_mult) {
  TMatrix<int> m1(2);
  TMatrix<int> m2(2);
  TMatrix<int> expect_m(2);

  m1[0][0] = -12;
  m1[0][1] = 2;
  m1[1][0] = 5;

  m2[0][0] = 1;
  m2[0][1] = 9;
  m2[1][0] = 3;

  expect_m[0][0] = -12;
  expect_m[0][1] = -102;
  expect_m[1][0] = 15;

  EXPECT_EQ(m1 * m2, expect_m);
}