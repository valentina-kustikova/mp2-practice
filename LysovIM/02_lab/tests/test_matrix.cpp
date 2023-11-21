#include "matrix.h"
#include <gtest.h>

TEST(TMatrix, can_create_matrix)
{
	ASSERT_NO_THROW(TMatrix<int> matrix(3));
}

TEST(TMatrix, throws_when_negative_length)
{
	ASSERT_ANY_THROW(TMatrix<int> matrix(-1));
}

TEST(TMatrix, can_create_copy)
{
	TMatrix<int> matrix(2);
	matrix[0][0] = 1;
	matrix[0][1] = 1;
	matrix[1][0] = 1;
	ASSERT_NO_THROW(TMatrix<int> matrix1(matrix));
}

TEST(TMatrix, can_create_from_vector)
{
	TVector<TVector<int>> vector(2, 0);
	ASSERT_NO_THROW(TMatrix<int> matrix1(vector));
}

TEST(TMatrix, can_work_with_elements)
{
	TMatrix<int> matrix(2);
	matrix[0][0] = 2;
	ASSERT_EQ(2, matrix[0][0]);
}

TEST(TMatrix, can_assigned_from_equal_amounts_of)
{
	TMatrix<int> matrix(2);
	matrix[0][0] = 2;
	TMatrix<int> matrix1(2);
	matrix1 = matrix;
	ASSERT_EQ(2, matrix1[0][0]);
}

TEST(TMatrix, can_assign_from_diverse_size)
{
	TMatrix<int> matrix(2);
	TMatrix<int> matrix1(3);
	matrix1[0][0] = 2;
	matrix = matrix1;
	ASSERT_EQ(2, matrix[0][0]);
}

TEST(TMatrix, ñompare_with_non_equal_sizes)
{
	TMatrix<int> matrix(2);
	TMatrix<int> matrix1(3);
	ASSERT_EQ(0, matrix == matrix1);
}

TEST(TMatrix, can_compare_with_equal_sizes_equal_1)
{
	TMatrix<int> matrix1(2);
	matrix1[0][0] = 1;
	matrix1[0][1] = 2;
	matrix1[1][0] = 3;
	TMatrix<int> matrix(matrix1);
	ASSERT_EQ(true, matrix == matrix1);
}

TEST(TMatrix, can_compare_with_equal_sizes_eq_not)
{
	TMatrix<int> matrix(2);
	matrix[0][0] = 1;
	matrix[0][1] = 2;
	matrix[1][0] = 3;
	TMatrix<int> matrix1(matrix);
	matrix1[1][0] = 1;
	ASSERT_EQ(false, matrix == matrix1);
}

TEST(TMatrix, can_compare_with_equal_sizes_no_equel)
{
	TMatrix<int> matrix(2);
	matrix[0][0] = 2;
	matrix[0][1] = 3;
	matrix[1][0] = 4;
	TMatrix<int> matrix1(matrix);
	ASSERT_EQ(false, matrix != matrix1);
}

TEST(TMatrix, can_set_and_get_element)
{
	TMatrix <int> matrix1(2);
	matrix1[0][0] = 3;
	matrix1[0][1] = 2;
	matrix1[1][0] = 1;
	EXPECT_EQ(matrix1[0][0],3);
}

TEST(TMatrix, can_compare_with_equal_sizes_no_eq_not)
{
	TMatrix<int> matrix(2);
	matrix[0][0] = 2;
	matrix[0][1] = 3;
	matrix[1][0] = 4;
	TMatrix<int> matrix1(matrix);
	matrix1[1][0] = 1;
	ASSERT_EQ(true, matrix != matrix1);
}

TEST(TMatrix, can_addition_matrix)
{
	TMatrix<int> matrix(2);
	matrix[0][0] = 2;
	matrix[0][1] = 3;
	matrix[1][0] = 4;
	TMatrix<int> matrix1(matrix);
	matrix1 = matrix1 + matrix;
	ASSERT_NE(2, matrix1[0][0]);
}

TEST(TMatrix, can_subtraction_matrix)
{
	TMatrix<int> matrix(2);
	matrix[0][0] = 2;
	matrix[0][1] = 3;
	matrix[1][0] = 4;
	TMatrix<int> matrix1(matrix);
	matrix1 = matrix1 - matrix;
	ASSERT_NE(4, matrix1[1][0]);
}

TEST(TMatrix, can_multiplication_matrix)
{
	TMatrix<int> matrix(2);
	matrix[0][0] = 2;
	matrix[0][1] = 3;
	matrix[1][0] = 4;
	TMatrix<int> matrix1(matrix);
	TMatrix<int> matrix2(2);
	matrix2 = matrix1 * matrix;
	ASSERT_EQ(16, matrix2[1][0]);
}

TEST(TMatrix, cant_addition_with_different_sizes)
{
	TMatrix<int> matrix(2);
	TMatrix<int> matrix1(3);
	ASSERT_ANY_THROW(matrix1 + matrix);
}

TEST(TMatrix, cant_on_retraction_with_different_sizes)
{
	TMatrix<int> matrix(2);
	TMatrix<int> matrix1(3);
	ASSERT_ANY_THROW(matrix1 - matrix);
}

TEST(TMatrix, cant_on_multiplication_with_different_sizes)
{
	TMatrix<int> matrix(2);
	TMatrix<int> matrix1(3);
	ASSERT_ANY_THROW(matrix1 * matrix);
}