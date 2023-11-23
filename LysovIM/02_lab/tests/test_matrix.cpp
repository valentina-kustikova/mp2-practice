#include "matrix.h"
#include <gtest.h>

TEST(TMatrix, can_create_matrix_with_positive_length)
{
	ASSERT_NO_THROW(TMatrix<int> matrix(2));
}

TEST(TMatrix, when_create_matrix_with_negative_length_false)
{
	ASSERT_ANY_THROW(TMatrix<int> matrix(-2));
}

TEST(TMatrix, can_create_copied_matrix)
{
	TMatrix<int> matrix(2);
	matrix[0][0] = 1;
	matrix[0][1] = 1;
	matrix[1][0] = 1;
	ASSERT_NO_THROW(TMatrix<int> matrix1(matrix));
}

TEST(TMatrix, copied_matrix_is_equal_to_source)
{
	TMatrix <int> matrix1(2);
	matrix1[0][0] = 1;
	matrix1[0][1] = 1;
	matrix1[1][0] = 1;
	TMatrix<int> matrix2(matrix1);
	EXPECT_EQ(matrix1 == matrix2, 1);
}

TEST(TMatrix, copied_matrix_has_their_own_memory)
{

	TMatrix <int> matrix1(2);
	matrix1[0][0] = 1;
	matrix1[0][1] = 1;
	matrix1[1][0] = 1;
	TMatrix <int> matrix2(matrix1);
	matrix1[0][0] = 2;
	EXPECT_EQ(matrix1 == matrix2, 0);
}

TEST(TMatrix, can_get_size)
{
	TMatrix<int> matrix(3);
	EXPECT_EQ(3, matrix.getSize());
}

TEST(TMatrix, can_set_and_get_element)
{
	TMatrix <int> matrix(2);
	matrix[0][0] = 1;
	matrix[0][1] = 2;
	matrix[1][0] = 3;
	EXPECT_EQ(3, matrix[1][0]);
}

TEST(TMatrix, when_set_element_with_negative_index_false)
{
	TMatrix <int> matrix(2);
	matrix[0][0] = 1;
	matrix[0][1] = 2;
	matrix[1][0] = 3;
	ASSERT_ANY_THROW(matrix[-1][-1] = 1);
}

TEST(TMatrix, may_assign_the_matrix_to_itself)
{
	TMatrix<int>matrix(2);
	matrix[0][0] = 1;
	matrix[0][1] = 2;
	matrix[1][0] = 3;
	ASSERT_NO_THROW(matrix = matrix);
}


TEST(TMatrix, can_assign_matrix_of_different_size)
{

	TMatrix <int> matrix(2);
	matrix[0][0] = 1;
	matrix[0][1] = 2;
	matrix[1][0] = 3;
	TMatrix <int> matrix1(1);
	matrix1[0][0] = 3;
	matrix1 = matrix;
	EXPECT_EQ(matrix, matrix1);
}

TEST(TMatrix, assign_operator_change_matrix_size)
{
	TMatrix <int> matrix(2);
	matrix[0][0] = 1;
	matrix[0][1] = 2;
	matrix[1][0] = 3;
	TMatrix <int> matrix1(1);
	matrix1[0][0] = 0;
	matrix1 = matrix;
	EXPECT_EQ(2, matrix1.getSize());
}

TEST(TMatrix, compare_equal_matrix)
{
	TMatrix <int> matrix(2);
	matrix[0][0] = 1;
	matrix[0][1] = 2;
	matrix[1][0] = 3;
	TMatrix <int> matrix1(2);
	matrix1[0][0] = 1;
	matrix1[0][1] = 2;
	matrix1[1][0] = 3;
	EXPECT_EQ(matrix, matrix1);
}

TEST(TMatrix, compare_matrix_with_itself_true)
{
	TMatrix <int> matrix(2);
	matrix[0][0] = 1;
	matrix[0][1] = 2;
	matrix[1][0] = 3;
	ASSERT_TRUE(matrix == matrix);
}

TEST(TMatrix, matrix_with_different_size_not_equal)
{
	TMatrix <int> matrix(2);
	matrix[0][0] = 1;
	matrix[0][1] = 2;
	matrix[1][0] = 3;
	TMatrix <int> matrix1(1);
	matrix1[0][0] = 2;
	ASSERT_FALSE(matrix == matrix1);
}

TEST(TMatrix, can_addititon_matrices_with_equal_size)
{
	TMatrix <int> matrix1(2);
	matrix1[0][0] = 1;
	matrix1[0][1] = 2;
	matrix1[1][0] = 3;
	TMatrix <int> matrix2(2);
	matrix2[0][0] = 1;
	matrix2[0][1] = 2;
	matrix2[1][0] = 3;
	TMatrix <int> matrix3(2);
	matrix3[0][0] = 2;
	matrix3[0][1] = 4;
	matrix3[1][0] = 6;
	EXPECT_EQ(matrix3, matrix1 + matrix2);
}

TEST(TMatrix, can_subtraction_matrices_with_equal_size)
{
	TMatrix <int> matrix1(2);
	matrix1[0][0] = 1;
	matrix1[0][1] = 2;
	matrix1[1][0] = 3;
	TMatrix <int> matrix2(2);
	matrix2[0][0] = 1;
	matrix2[0][1] = 2;
	matrix2[1][0] = 3;
	TMatrix <int> matrix3(2);
	matrix3[0][0] = 0;
	matrix3[0][1] = 0;
	matrix3[1][0] = 0;
	EXPECT_EQ(matrix3, matrix1 - matrix2);
}

TEST(TMatrix, can_multiplication_with_equal_size)
{
	TMatrix <int> matrix1(2);
	matrix1[0][0] = 1;
	matrix1[0][1] = 2;
	matrix1[1][0] = 3;
	TMatrix <int> matrix2(2);
	matrix2[0][0] = 1;
	matrix2[0][1] = 2;
	matrix2[1][0] = 3;
	TMatrix <int> matrix3(2);
	matrix3[0][0] = 1;
	matrix3[0][1] = 8;
	matrix3[1][0] = 9;
	EXPECT_EQ(matrix3, matrix1 * matrix2);
}

TEST(TMatrix, cant_addition_with_not_equal_size)
{
	TMatrix <int> matrix(2);
	matrix[0][0] = 1;
	matrix[0][1] = 2;
	matrix[1][0] = 3;
	TMatrix<int> matrix1(1);
	matrix1[0][0] = 1;
	ASSERT_ANY_THROW(matrix + matrix1);
}

TEST(TMatrix, cant_subtraction_matrixes_with_not_equal_size)
{
	TMatrix <int> matrix1(2);
	matrix1[0][0] = 1;
	matrix1[0][1] = 2;
	matrix1[1][0] = 3;
	TMatrix<int> matrix2(1);
	matrix2[0][0] = 2;
	ASSERT_ANY_THROW(matrix1 - matrix2);
}

TEST(TMatrix, cant_multiplication_with_not_equal_size)
{
	TMatrix <int> matrix1(2);
	matrix1[0][0] = 1;
	matrix1[0][1] = 2;
	matrix1[1][0] = 1;
	TMatrix <int> matrix2(1);
	matrix2[0][0] = 0;
	ASSERT_ANY_THROW(matrix1 * matrix2);
}