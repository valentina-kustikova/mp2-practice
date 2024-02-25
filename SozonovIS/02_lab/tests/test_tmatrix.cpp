#include "tmatrix.h"
#include <gtest.h>

TEST(TMatrix, can_create_matrix_with_positive_length){
	ASSERT_NO_THROW(TMatrix<int> m(5));
}

TEST(TMatrix, throws_when_create_matrix_with_negative_length){
	ASSERT_ANY_THROW(TMatrix<int> m(-5));
}

TEST(TMatrix, can_create_copied_matrix){
	TMatrix<int> m(5);

	ASSERT_NO_THROW(TMatrix<int> m1(m));
}

TEST(TMatrix, can_create_a_matrix_based_on_a_vector) {
	TVector<TVector<int>> v(5);

	ASSERT_NO_THROW(TMatrix<int> m1(v););
}

TEST(TMatrix, can_get_size){
	TMatrix<int> m(5);

	EXPECT_EQ(5, m.GetSize());
}

TEST(TMatrix, can_set_and_get_element){
	TMatrix <int> m(2);
	m[0][0] = 1;
	m[0][1] = 2;
	m[1][0] = 3;

	EXPECT_EQ(1, m[0][0]);
}

TEST(TMatrix, throws_when_set_element_with_negative_index){
	TMatrix <int> m(2);

	ASSERT_ANY_THROW(m[-1][-1] = 1);
}

TEST(TMatrix, can_assign_matrix_to_itself){
	TMatrix<int>m(2);

	ASSERT_NO_THROW(m = m);
}

TEST(TMatrix, can_assign_matrix_of_equal_size){
	TMatrix <int> m1(2), m2(2);
	m1[0][0] = 1;
	m1[0][1] = 2;
	m1[1][0] = 3;

	m2[0][0] = 4;
	m2[0][1] = 5;
	m2[1][0] = 6;

	ASSERT_NO_THROW(m2 = m1);
}

TEST(TMatrix, can_assign_matrix_of_different_size){

	TMatrix <int> m1(2), m2(1);
	m1[0][0] = 1;
	m1[0][1] = 2;
	m1[1][0] = 3;

	m2[0][0] = 1;

	ASSERT_NO_THROW(m2 = m1);
}

TEST(TMatrix, compare_equal_matrix_return_true){
	TMatrix <int> m1(2), m2(2);
	m1[0][0] = 1;
	m1[0][1] = 2;
	m1[1][0] = 3;

	m2[0][0] = 1;
	m2[0][1] = 2;
	m2[1][0] = 3;

	EXPECT_EQ(m1, m2);
}

TEST(TMatrix, compare_matrix_with_itself_return_true){
	TMatrix <int> m(2);
	m[0][0] = 1;
	m[0][1] = 2;
	m[1][0] = 3;

	ASSERT_EQ(m, m);
}

TEST(TMatrix, matrix_with_different_value_are_not_equal) {
	TMatrix <int> m1(2), m2(2);
	m1[0][0] = 1;
	m1[0][1] = 2;
	m1[1][0] = 3;

	m2[0][0] = 4;
	m2[0][1] = 5;
	m2[1][0] = 6;

	ASSERT_NE(m1, m2);
}

TEST(TMatrix, matrix_with_different_size_are_not_equal){
	TMatrix <int> m1(2), m2(1);
	m1[0][0] = 1;
	m1[0][1] = 2;
	m1[1][0] = 3;

	m2[0][0] = 1;

	ASSERT_NE(m1, m2);
}

TEST(TMatrix, can_add_matrices_with_equal_size){
	TMatrix <int> m1(2), m2(2), m3(2);
	m1[0][0] = 1;
	m1[0][1] = 2;
	m1[1][0] = 3;

	m2[0][0] = 4;
	m2[0][1] = 5;
	m2[1][0] = 6;

	m3[0][0] = 5;
	m3[0][1] = 7;
	m3[1][0] = 9;

	EXPECT_EQ(m3, m1 + m2);
}

TEST(TMatrix, throws_when_add_matrices_with_different_size){
	TMatrix <int> m1(2), m2(1);
	m1[0][0] = 1;
	m1[0][1] = 2;
	m1[1][0] = 3;

	m2[0][0] = 1;

	ASSERT_ANY_THROW(m1 + m2);
}

TEST(TMatrix, can_subtract_matrices_with_equal_size){
	TMatrix <int> m1(2), m2(2), m3(2);
	m1[0][0] = 4;
	m1[0][1] = 5;
	m1[1][0] = 6;

	m2[0][0] = 1;
	m2[0][1] = 2;
	m2[1][0] = 3;

	m3[0][0] = 3;
	m3[0][1] = 3;
	m3[1][0] = 3;

	EXPECT_EQ(m3, m1 - m2);
}

TEST(TMatrix, throws_when_subtract_matrices_with_different_size){
	TMatrix <int> m1(2), m2(1);
	m1[0][0] = 1;
	m1[0][1] = 2;
	m1[1][0] = 3;

	m2[0][0] = 1;

	ASSERT_ANY_THROW(m1 - m2);
}

TEST(TMatrix, can_multiply_matrices_with_equal_size){
	TMatrix <int> m1(2), m2(2), m3(2);
	m1[0][0] = 1;
	m1[0][1] = 2;
	m1[1][0] = 3;

	m2[0][0] = 4;
	m2[0][1] = 5;
	m2[1][0] = 6;

	m3[0][0] = 4;
	m3[0][1] = 17;
	m3[1][0] = 18;

	EXPECT_EQ(m3, m1 * m2);
}

TEST(TMatrix, throws_when_multiply_matrices_with_equal_size){
	TMatrix <int> m1(2), m2(1);
	m1[0][0] = 1;
	m1[0][1] = 2;
	m1[1][0] = 3;

	m2[0][0] = 1;

	ASSERT_ANY_THROW(m1 * m2);
}