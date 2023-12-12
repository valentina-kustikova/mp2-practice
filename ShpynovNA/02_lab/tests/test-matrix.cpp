#include "matrix.h"
#include <gtest.h>

TEST(TMatrix, can_create_matrix) 
{
	ASSERT_NO_THROW(TMatrix<int> mat(2));
}
TEST(TMatrix, throws_when_negative_length)
{
	ASSERT_ANY_THROW(TMatrix<int> mat(-1));
}
TEST(TMatrix, throws_when_zero_length)
{
	ASSERT_ANY_THROW(TMatrix<int> mat(0));
}

TEST(TMatrix, can_create_copy)
{
	TMatrix<int> mat(2);
	ASSERT_NO_THROW(TMatrix<int> mat1(mat));
}
TEST(TMatrix, check_own_memory)
{
	TMatrix<int> mat(2);
	TMatrix<int> mat1(mat);
	mat[0][0] = 1;
	EXPECT_NE(mat1, mat);
}

TEST(TMatrix, can_create_from_vector)
{
	TVector<TVector<int>> vect(2);
	ASSERT_NO_THROW(TMatrix<int> mat1(vect));
}


TEST(TMatrix, can_work_with_elements)
{
	TMatrix<int> mat(2);
	ASSERT_NO_THROW(mat[0][0]); // <0, >len
}
TEST(TMatrix, throw_on_negative_indexing)
{
	TMatrix<int> mat(2);
	ASSERT_ANY_THROW(mat[0][-1]); // <0, >len
}
TEST(TMatrix, throw_on_out_of_range_indexing)
{
	TMatrix<int> mat(2);
	ASSERT_ANY_THROW(mat[0][4]); // <0, >len
}

TEST(TMatrix, can_assign_from_equal_size)
{
	TMatrix<int> mat(2);
	TMatrix<int> mat1(2);
	mat = mat1;
	EXPECT_EQ(mat, mat1);
}
TEST(TMatrix, can_assign_from_diff_size)
{
	TMatrix<int> mat(2);
	TMatrix<int> mat1(3);
	mat = mat1;
	EXPECT_EQ(mat, mat1);
}

TEST(TMatrix, false_when_compare_with_non_equal_sizes) {
	TMatrix<int> mat(2);
	TMatrix<int> mat1(3);
	EXPECT_NE(mat, mat1);
}
TEST(TMatrix, can_compare_with_equal_sizes)
{
	TMatrix<int> mat(2);
	mat[0][0] = 2;
	mat[0][1] = 3;
	mat[1][0] = 4;
	TMatrix<int> mat1(mat);
	EXPECT_EQ(mat, mat1);
}

TEST(TMatrix, can_compare_with_equal_sizes_not_eq)
{
	TMatrix<int> mat(2);
	TMatrix<int> mat1(mat);
	mat[0][0] = 2;
	mat[0][1] = 3;
	mat[1][0] = 4;
	EXPECT_NE(mat, mat1);
}

TEST(TMatrix, can_add_matrix)
{
	TMatrix<int> mat(2);
	mat[0][0] = 2;
	mat[0][1] = 3;
	mat[1][0] = 4;
	TMatrix<int> mat1(2);
	mat1[0][0] = 0;
	mat1[0][1] = 1;
	mat1[1][0] = 2;
	TMatrix<int> expected_mat(2);
	expected_mat[0][0] = 2;
	expected_mat[0][1] = 4;
	expected_mat[1][0] = 6;
	EXPECT_EQ(mat + mat1, expected_mat);
}
TEST(TMatrix, can_subtr_matrix)
{
	TMatrix<int> mat(2);
	mat[0][0] = 2;
	mat[0][1] = 3;
	mat[1][0] = 4;
	TMatrix<int> mat1(2);
	mat1[0][0] = 0;
	mat1[0][1] = 1;
	mat1[1][0] = 2;
	TMatrix<int> expected_mat(2);
	expected_mat[0][0] = 2;
	expected_mat[0][1] = 2;
	expected_mat[1][0] = 2;
	EXPECT_EQ(expected_mat, mat - mat1);
}
TEST(TMatrix, can_mult_matrix)
{
	TMatrix<int> mat(2);
	mat[0][0] = 2;
	mat[0][1] = 3;
	mat[1][0] = 4;
	TMatrix<int> mat1(2);
	mat1[0][0] = 0;
	mat1[0][1] = 1;
	mat1[1][0] = 2;
	TMatrix<int> expected_mat(2);
	expected_mat[0][0] = 0;
	expected_mat[0][1] = 8;
	expected_mat[1][0] = 8;
	EXPECT_EQ(expected_mat, mat * mat1);
}
TEST(TMatrix, throw_on_multiply_with_different_sizes)
{
	TMatrix<int> mat(2);
	TMatrix<int> mat1(3);
	ASSERT_ANY_THROW(mat1 * mat);
}
TEST(TMatrix, throw_on_addition_with_different_sizes)
{
	TMatrix<int> mat(2);
	TMatrix<int> mat1(3);
	ASSERT_ANY_THROW(mat1 + mat);
}
TEST(TMatrix, throw_on_subtraction_with_different_sizes)
{
	TMatrix<int> mat(2);
	TMatrix<int> mat1(3);
	ASSERT_ANY_THROW(mat1 - mat);
}



