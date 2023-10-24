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
TEST(TMatrix, can_create_from_vector)
{
	TVector<TVector<int>> vect(2, 0);
	ASSERT_NO_THROW(TMatrix<int> mat1(vect));
}

//TEST(TMatrix, throw_if_vector_is_not_diagonal)
//{
//	
//	TVector<int> vect(2, 0);
//	TVector<int> vect1(2, 0);
//	vect[0] = 4;
//	vect[1] = -2;
//	vect1[0] = 2;
//	vect1[1] = 0;
//	TVector<TVector<int>> Vvect(2, 0);
//	Vvect[0] = vect;
//	Vvect[1] = vect1;
//	ASSERT_ANY_THROW(TMatrix<int> mat1(Vvect));
//}

TEST(TMatrix, can_work_with_elements)
{
	TMatrix<int> mat(2);
	mat[0][0] = 2;
	ASSERT_EQ(2, mat[0][0]);
}
TEST(TMatrix, all_zeros_beneath_the_triangle)
{
	TMatrix<int> mat(2);
	ASSERT_ANY_THROW(mat[1][0]);
}

TEST(TMatrix, can_assign_fron_equal_size)
{
	TMatrix<int> mat(2);
	mat[0][0] = 2;
	TMatrix<int> mat1(2);
	mat1 = mat;
	ASSERT_EQ(2, mat1[0][0]);
}
TEST(TMatrix, can_assign_fron_diff_size)
{
	TMatrix<int> mat(2);
	TMatrix<int> mat1(3);
	mat[0][0] = 2;
	mat = mat1;
	ASSERT_EQ(2, mat[0][0]);
}

TEST(TMatrix, false_when_compare_with_non_equal_sizes) {
	TMatrix<int> mat(2);
	TMatrix<int> mat1(3);
	ASSERT_EQ(false, mat == mat1);
}
TEST(TMatrix, can_compare_with_equal_sizes_eq1)
{
	TMatrix<int> mat(2);
	mat[0][0] = 2;
	mat[0][1] = 3;
	mat[1][1] = 4;
	TMatrix<int> mat1(mat);
	ASSERT_EQ(true, mat == mat1);
}
TEST(TMatrix, can_compare_with_equal_sizes_eq_not)
{
	TMatrix<int> mat(2);
	mat[0][0] = 2;
	mat[0][1] = 3;
	mat[1][1] = 4;
	TMatrix<int> mat1(mat);
	mat1[1][1] = 1;
	ASSERT_EQ(false, mat == mat1);
}
TEST(TMatrix, can_compare_with_equal_sizes_noeq)
{
	TMatrix<int> mat(2);
	mat[0][0] = 2;
	mat[0][1] = 3;
	mat[1][1] = 4;
	TMatrix<int> mat1(mat);
	ASSERT_EQ(false, mat != mat1);
}
TEST(TMatrix, can_compare_with_equal_sizes_noeq_not)
{
	TMatrix<int> mat(2);
	mat[0][0] = 2;
	mat[0][1] = 3;
	mat[1][1] = 4;
	TMatrix<int> mat1(mat);
	mat1[1][1] = 1;
	ASSERT_EQ(true, mat != mat1);
}

TEST(TMatrix, can_add_matrix)
{
	TMatrix<int> mat(2);
	mat[0][0] = 2;
	mat[0][1] = 3;
	mat[1][1] = 4;
	TMatrix<int> mat1(mat);
	mat1 = mat1 + mat;
	ASSERT_NE(4, mat1[1][1]);
}
TEST(TMatrix, can_retr_matrix)
{
	TMatrix<int> mat(2);
	mat[0][0] = 2;
	mat[0][1] = 3;
	mat[1][1] = 4;
	TMatrix<int> mat1(mat);
	mat1 = mat1 - mat;
	ASSERT_NE(4, mat1[1][1]);
}
TEST(TMatrix, can_mult_matrix)
{
	TMatrix<int> mat(2);
	mat[0][0] = 2;
	mat[0][1] = 3;
	mat[1][1] = 4;
	TMatrix<int> mat1(mat);
	mat1 = mat1 * mat;
	ASSERT_EQ(16, mat1[1][1]);
}
TEST(TMatrix, throw_on_multiply_with_different_sizes)
{
	TMatrix<int> mat(2);
	TMatrix<int> mat1(3);
	ASSERT_ANY_THROW(mat1 * mat);
}




