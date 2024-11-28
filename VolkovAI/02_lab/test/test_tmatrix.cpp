#include "tmatrix.h"

#include <gtest.h>

TEST(TDynamicMatrix, can_create_matrix_with_positive_length)
{
  ASSERT_NO_THROW(TDynamicMatrix<int> m(5));
}

TEST(TDynamicMatrix, cant_create_too_large_matrix)
{
  ASSERT_ANY_THROW(TDynamicMatrix<int> m(MAX_MATRIX_SIZE + 1));
}

TEST(TDynamicMatrix, throws_when_create_matrix_with_negative_length)
{
  ASSERT_ANY_THROW(TDynamicMatrix<int> m(-5));
}

TEST(TDynamicMatrix, can_create_copied_matrix)
{
  TDynamicMatrix<int> m(5);

  ASSERT_NO_THROW(TDynamicMatrix<int> m1(m));
}

TEST(TDynamicMatrix, copied_matrix_is_equal_to_source_one)
{
  TDynamicMatrix<int> m(2);
  m[0][0] = 1;
  m[0][1] = 2;
  m[1][0] = 3;
  TDynamicMatrix<int> m1(m);
  EXPECT_EQ(m1, m);
}

TEST(TDynamicMatrix, copied_matrix_has_its_own_memory)
{
    TDynamicVector<int> v(5);
    for (int i = 0; i < v.size(); i++) {
        v[i] = i;
    }
    TDynamicVector<int> v1(v);
    v1[3] = 5;
    EXPECT_NE(v, v1);
}

TEST(TDynamicMatrix, can_get_size)
{
  TDynamicMatrix<int> m(5);
  EXPECT_EQ(5, m[0].size());
}

TEST(TDynamicMatrix, can_set_and_get_element)
{
  TDynamicMatrix<int> m(5);
  TDynamicVector<int> v(5);
  for (int i = 0; i < v.size(); i++) {
    v[i] = i;
  }
  m[0] = v;
  EXPECT_EQ(m[0], v);
}

TEST(TDynamicMatrix, throws_when_set_element_with_negative_index)
{
  TDynamicMatrix<int> m(5);
  ASSERT_ANY_THROW(m[-1][-1] = 10);
}

TEST(TDynamicMatrix, throws_when_set_element_with_too_large_index)
{
    TDynamicMatrix<int> m(5);
    ASSERT_ANY_THROW(m[0].at(MAX_VECTOR_SIZE) = 5);
}

TEST(TDynamicMatrix, can_assign_matrix_to_itself)
{
  TDynamicMatrix<int> m(5);
  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 5-i; j++) {
      m[i][j] = i;
    }
  }
  TDynamicMatrix<int> m1(5);
  m1 = m;
  EXPECT_EQ(m1, m);
}

TEST(TDynamicMatrix, can_assign_matrices_of_equal_size)
{
  TDynamicMatrix<int> m(5);
  TDynamicMatrix<int> m1(5);
  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 5-i; j++) {
      m[i][j] = i;
    }
  }
  m1 = m;
  EXPECT_EQ(m, m1); // todo
}

TEST(TDynamicMatrix, assign_operator_change_matrix_size)
{
    TDynamicMatrix<int> m(5);
    TDynamicMatrix<int> m1(6);
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5 - i; j++) {
            m[i][j] = i;
        }
    }
    m1 = m;
    EXPECT_EQ(m.size(), m1.size()); // todo
}

TEST(TDynamicMatrix, can_assign_matrices_of_different_size)
{
    TDynamicMatrix<int> m(5);
    TDynamicMatrix<int> m1(6);
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5 - i; j++) {
            m[i][j] = i;
        }
    }
    m1 = m;
    EXPECT_EQ(m, m1);
}

TEST(TDynamicMatrix, compare_equal_matrices_return_true)
{
  TDynamicMatrix<int> m(5);
  TDynamicMatrix<int> m1(5);
  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 5-i; j++) {
      m[i][j] = i;
      m1[i][j] = i;
    }
  }
  EXPECT_TRUE(m == m1);
}

TEST(TDynamicMatrix, compare_matrix_with_itself_return_true)
{
  TDynamicMatrix<int> m(5);
  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 5-i; j++) {
      m[i][j] = i;
    }
  }
  EXPECT_TRUE(m == m);
}


TEST(TDynamicMatrix, matrices_with_different_size_are_not_equal)
{
  TDynamicMatrix<int> m(5);
  TDynamicMatrix<int> m1(6);
  EXPECT_NE(m, m1);
}

TEST(TDynamicMatrix, can_add_matrices_with_equal_size)
{
  TDynamicMatrix<int> m(5);
  TDynamicMatrix<int> m1(5);
  TDynamicMatrix<int> res(5);
  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 5-i; j++) {
      m[i][j] = i;
      m1[i][j] = i+3;
      res[i][j] = i+i+3;
    }
  }
  EXPECT_EQ(res, m+m1);
}

TEST(TDynamicMatrix, cant_add_matrices_with_not_equal_size)
{
  TDynamicMatrix<int> m(5);
  TDynamicMatrix<int> m1(6);
  ASSERT_ANY_THROW(m+m1);
}

TEST(TDynamicMatrix, can_subtract_matrices_with_equal_size)
{
    TDynamicMatrix<int> m(5);
    TDynamicMatrix<int> m1(5);
    TDynamicMatrix<int> res(5);
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5-i; j++) {
            m[i][j] = i;
            m1[i][j] = i+3;
            res[i][j] = i-i-3;
        }
    }
    EXPECT_EQ(res, m-m1);
}

TEST(TDynamicMatrix, cant_subtract_matrixes_with_not_equal_size)
{
  TDynamicMatrix<int> m(5);
  TDynamicMatrix<int> m1(6);
  ASSERT_ANY_THROW(m-m1);
}

// Multiplying test's

TEST(TDynamicMatrix, can_multiply_matrix_by_vector) {
    TDynamicMatrix<int> m(3);
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3 - i; j++) {
            m[i][j] = i + j;
        }
    }
    TDynamicVector<int> v(3);
    for (int i = 0; i < 3; i++) {
        v[i] = i + 3;
    }
    TDynamicVector<int> answ(3);
    answ[0] = 14;
    answ[1] = 14;
    answ[2] = 10;
    EXPECT_EQ(answ, m*v);
}

TEST(TDynamicMatrix, cant_multiply_matrix_by_vector_with_not_equal_size) {
  TDynamicMatrix<int> m(3);
  TDynamicVector<int> v(4);
  ASSERT_ANY_THROW(m*v);
}

TEST(TDynamicMatrix, can_multiply_matrix_by_matrix)
{
  TDynamicMatrix<int> m(3), m2 (3), answ (3);
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3 - i; j++) {
      m[i][j] = i + j;
      m2[i][j] = 2*j;
    }
  }
  answ[0][2] = 2;
  answ[1][1] = 2;
  EXPECT_EQ(m*m2, answ);
}

TEST(TDynamicMatrix, cant_multiply_matrix_by_matrix_with_not_equal_size)
{
  TDynamicMatrix<int> m(3), m2 (5);
  EXPECT_ANY_THROW(m*m2);
}