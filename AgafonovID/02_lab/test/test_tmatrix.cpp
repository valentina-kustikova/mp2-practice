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
    TDynamicMatrix<int> m(5), m1(m);
    EXPECT_EQ(m, m1);
}

TEST(TDynamicMatrix, copied_matrix_has_its_own_memory)
{
    TDynamicMatrix<int> m(5);
    m[0][0] = 1;
    TDynamicMatrix<int> m1(m);
    m1[0][0] = 2;
    EXPECT_FALSE(m == m1);
}

TEST(TDynamicMatrix, can_get_size)
{
    TDynamicMatrix<int> m(5);
    EXPECT_EQ(5, m.size());
}

TEST(TDynamicMatrix, can_set_and_get_element)
{
    TDynamicMatrix<int> m(5);
    m[0][0] = 10;
    EXPECT_EQ(10, m[0][0]);
}

TEST(TDynamicMatrix, throws_when_set_element_with_negative_index)
{
    TDynamicMatrix<int> m(5);
    ASSERT_ANY_THROW(m.at(-1).at(0) = 10);
}

TEST(TDynamicMatrix, throws_when_set_element_with_too_large_index)
{
    TDynamicMatrix<int> m(3);
    ASSERT_ANY_THROW(m.at(5).at(0) = 10);
}

TEST(TDynamicMatrix, can_assign_matrix_to_itself)
{
    TDynamicMatrix<int> m(5);
    m[0][0] = 10;
    ASSERT_NO_THROW(m = m);
}

TEST(TDynamicMatrix, can_assign_matrices_of_equal_size)
{
    TDynamicMatrix<int> m(5);
    TDynamicMatrix<int> m1(5);
    EXPECT_EQ(m, m1);
}

TEST(TDynamicMatrix, assign_operator_change_matrix_size)
{
    TDynamicMatrix<int> m(5);
    TDynamicMatrix<int> m1(10);
    m[0][0] = 10;
    m1 = m;
    EXPECT_EQ(m1.size(), m.size());
}

TEST(TDynamicMatrix, can_assign_matrices_of_different_size)
{
    TDynamicMatrix<int> m(5);
    TDynamicMatrix<int> m1(10);
    for (int i = 0; i < m.size(); i++) {
        for (int j = 0; j < m.size() - i; j++) {
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
    m[0][0] = 10;
    m1[0][0] = 10;
    EXPECT_TRUE(m == m1);
}

TEST(TDynamicMatrix, compare_matrix_with_itself_return_true)
{
    TDynamicMatrix<int> m(5);
    m[0][0] = 10;
    EXPECT_TRUE(m == m);
}

TEST(TDynamicMatrix, matrices_with_different_size_are_not_equal)
{
    TDynamicMatrix<int> m(5);
    TDynamicMatrix<int> m1(10);
    m[0][0] = 1;
    m1[0][0] = 2;
    EXPECT_FALSE(m == m1);
}

TEST(TDynamicMatrix, can_add_matrices_with_equal_size)
{
    TDynamicMatrix<int> m(5);
    TDynamicMatrix<int> m1(5);
    TDynamicMatrix<int> res(5);
    for (int i = 0; i < m.size(); i++) {
        for (int j = 0; j < m.size() - i; j++) {
            m[i][j] = i;
            m1[i][j] = i + 2;
            res[i][j] = i + i + 2;
        }
    }
    EXPECT_EQ(res, m + m1);
}

TEST(TDynamicMatrix, cant_add_matrices_with_not_equal_size)
{
    TDynamicMatrix<int> m(5), m1(6);
    ASSERT_ANY_THROW(m + m1);
}

TEST(TDynamicMatrix, can_subtract_matrices_with_equal_size)
{
    TDynamicMatrix<int> m(5);
    TDynamicMatrix<int> m1(5);
    TDynamicMatrix<int> res(5);
    for (int i = 0; i < m.size(); i++) {
        for (int j = 0; j < m.size() - i; j++) {
            m[i][j] = i;
            m1[i][j] = i - 2;
            res[i][j] = i - (i - 2);
        }
    }
    EXPECT_EQ(res, m - m1);
}

TEST(TDynamicMatrix, cant_subtract_matrixes_with_not_equal_size)
{
    TDynamicMatrix<int> m(5), m1(6);
    ASSERT_ANY_THROW(m - m1);
}

TEST(TDynamicMatrix, can_multiply_matrixes_with_equal_size)
{
    TDynamicMatrix<int> m(2), m3(2);
    TDynamicMatrix<int> m1(2);
    TDynamicMatrix<int> res(2);
    m[0][0] = 1;
    m[0][1] = 2;
    m[1][0] = 3;
    
    m1[0][0] = 4;
    m1[0][1] = 5;
    m1[1][0] = 6;

    m3[0][0] = 4;
    m3[0][1] = 17;
    m3[1][0] = 18;

    res = m * m1;
    EXPECT_EQ(res, m3);
}

TEST(TDynamicMatrix, cant_multiply_matrixes_with_not_equal_size)
{
    TDynamicMatrix<int> m(5), m1(10);
    ASSERT_ANY_THROW(m * m1);
}

TEST(TDynamicMatrix, cant_multiply_matrixes_vector_with_equal_size) {

}

TEST(TDynamicMatrix, cant_multiply_matrixes_vector_with_not_equal_size) {
    TDynamicMatrix<int> m(5);
    TDynamicVector<int> v(5);
    ASSERT_ANY_THROW(m * v);
}
