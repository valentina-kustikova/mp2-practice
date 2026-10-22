#include "tmatrix.h"

#include <gtest\gtest.h>

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
  TDynamicMatrix<int> m(3);
  for (size_t i = 0; i < 3; i++)
    for (size_t j = i; j < 3; j++)
    {
      m[i][j - i] = i * 10 + j;
    }
  TDynamicMatrix<int> p(m);
  EXPECT_TRUE(p == m);
}

TEST(TDynamicMatrix, copied_matrix_has_its_own_memory)
{
  TDynamicMatrix<int> m(3);
  m[0][0] = 3;
  TDynamicMatrix<int> p(m);
  m[0][0] = 1;
  EXPECT_NE(p[0][0] , m[0][0]);
}

TEST(TDynamicMatrix, can_get_size)
{
  TDynamicMatrix<int> m(3);
  EXPECT_EQ(3, m.size());
}

TEST(TDynamicMatrix, can_set_and_get_element)
{
  TDynamicMatrix<int> m(4);
   m[0][0] = 4;
   EXPECT_EQ(4, m[0][0]);
}

TEST(TDynamicMatrix, throws_when_set_element_with_negative_index)
{
  TDynamicMatrix<int> m(10);
  EXPECT_ANY_THROW(m[0].at(-1));
}

TEST(TDynamicMatrix, throws_when_set_element_with_too_large_index)
{
  TDynamicMatrix<int> m(10);
  EXPECT_ANY_THROW(m[0].at(50));
}

TEST(TDynamicMatrix, can_assign_matrix_to_itself)
{
  TDynamicMatrix<int> m(2);
  m[0][0] = 1; m[1][0] = 3; m[0][1] = 2;
  ASSERT_NO_THROW(m = m);
  /*EXPECT_EQ(1, m[0][0]);
  EXPECT_EQ(3, m[1][0]);
  EXPECT_EQ(2, m[0][1]);*/
}

TEST(TDynamicMatrix, can_assign_matrices_of_equal_size)
{
  TDynamicMatrix<int> m(2);
  TDynamicMatrix<int> p(2);
  m[0][0] = 1; m[1][0] = 3; m[0][1] = 2;
  p[0][0] = 2; p[1][0] = 4; p[0][1] = 3;
  m = p;
  ASSERT_NO_THROW(m = p);
  EXPECT_EQ(m, p);
  /*EXPECT_EQ(2, m[0][0]);
  EXPECT_EQ(4, m[1][0]);
  EXPECT_EQ(3, m[0][1]);*/
}

TEST(TDynamicMatrix, assign_operator_change_matrix_size)
{
  TDynamicMatrix<int> m(3), p(5);
  m = p;
  EXPECT_EQ(5, m.size());
}

TEST(TDynamicMatrix, can_assign_matrices_of_different_size)
{
  TDynamicMatrix<int> m(4), p(3);
  m[0][0] = 1; m[1][0] = 3; m[0][1] = 2;
  p[0][0] = 2; p[1][0] = 4; p[0][1] = 3;
  m = p;
  ASSERT_NO_THROW(m = p);
  EXPECT_EQ(m, p);
  /*EXPECT_EQ(2, m[0][0]);
  EXPECT_EQ(4, m[1][0]);
  EXPECT_EQ(3, m[0][1]);
  EXPECT_EQ(3, m.size());*/
}

TEST(TDynamicMatrix, compare_equal_matrices_return_true)
{
  TDynamicMatrix<int> m(3), p(3);
  m[0][0] = 1; m[1][0] = 3; m[0][1] = 2;
  p[0][0] = 1; p[1][0] = 3; p[0][1] = 2;
  EXPECT_TRUE(p == m);
}

TEST(TDynamicMatrix, compare_matrix_with_itself_return_true)
{
  TDynamicMatrix<int> m(3);
  m[0][0] = 1; m[1][0] = 3; m[0][1] = 2;
  EXPECT_TRUE(m == m);
}

TEST(TDynamicMatrix, matrices_with_different_size_are_not_equal)
{
  TDynamicMatrix<int> m(5), p(3);
  EXPECT_FALSE(m == p);
}

TEST(TDynamicMatrix, can_add_matrices_with_equal_size)
{
  TDynamicMatrix<int> m(3), p(3), c(3);
  m[0][0] = 1; m[1][0] = 3; m[0][1] = 2;
  p[0][0] = 2; p[1][0] = 4; p[0][1] = 3;
  c = m + p;
  ASSERT_NO_THROW(m + p);
  EXPECT_EQ(c, m+p);
  /*EXPECT_EQ(3, c[0][0]);
  EXPECT_EQ(7, c[1][0]);
  EXPECT_EQ(5, c[0][1]);*/
}

TEST(TDynamicMatrix, cant_add_matrices_with_not_equal_size)
{
  TDynamicMatrix<int> m(3), p(5);
  EXPECT_ANY_THROW(m + p);
}

TEST(TDynamicMatrix, can_subtract_matrices_with_equal_size)
{
  TDynamicMatrix<int> m(3), p(3), c(3);
  m[0][0] = 1; m[1][0] = 3; m[0][1] = 2;
  p[0][0] = 2; p[1][0] = 4; p[0][1] = 3;
  ASSERT_NO_THROW(p - m);
  c = p - m;
  EXPECT_EQ(c, p - m);
  /*EXPECT_EQ(1, c[0][0]);
  EXPECT_EQ(1, c[1][0]);
  EXPECT_EQ(1, c[0][1]);*/
}

TEST(TDynamicMatrix, cant_subtract_matrixes_with_not_equal_size)
{
  TDynamicMatrix<int> m(3), p(5);
  EXPECT_ANY_THROW(m - p);
}

