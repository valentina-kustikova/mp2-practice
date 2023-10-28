#include "TMatrix.h"

#include <gtest.h>

TEST(TMatrix, can_create_matrix_positive_size) {
	ASSERT_NO_THROW(TMatrix<int> mtr(10));
}
TEST(TMatrix, throw_when_create_matrix_negative_size) {
	ASSERT_ANY_THROW(TMatrix<int> mtr(-5));
}
TEST(TMatrix, can_create_matrix_with_copy_cons) {
	TMatrix<int> m1(5);
	ASSERT_NO_THROW(TMatrix<int>  m2(m1));
}
TEST(TMatrix, can_perform_type_conversions) {
	TVector<TVector<int>> vecs(3);
	ASSERT_NO_THROW(TMatrix<int> m(vecs));
}
TEST(TMatrix, assignment_operator) {
	TMatrix<int> vec1(2);
	vec1[0][0] = 1;
	vec1[0][1] = 2;
	vec1[1][1] = 3;
	TMatrix<int> vec2(2);
	vec2 = vec1;
	EXPECT_EQ(vec1, vec2);
}
TEST(TMatrix, matrix_with_same_size_are_equal) {
	TMatrix<int> vec1(2), vec2(2);
	vec1[0][0] = 1;
	vec1[0][1] = 2;
	vec1[1][1] = 3;
	vec2[0][0] = 1;
	vec2[0][1] = 2;
	vec2[1][1] = 3;
	EXPECT_EQ(1, vec1 == vec2);
}
TEST(TMatrix, matrix_with_same_size_are_not_equal) {
	TMatrix<int> vec1(2), vec2(2);
	vec1[0][0] = 1;
	vec1[0][1] = 2;
	vec1[1][1] = 3;
	vec2[0][0] = 2;
	vec2[0][1] = 2;
	vec2[1][1] = 3;
	EXPECT_EQ(1, vec1 != vec2);
}
TEST(TMatrix, matrix_with_different_size_are_not_equal) {
	TMatrix<int> vec1(2), vec2(3);
	EXPECT_EQ(0, vec1 == vec2);
}
TEST(TMatrix, can_take_matrix_sum_with_same_size) {
	TMatrix<int> vec1(2), vec2(2), vec3(2);
	vec1[0][0] = 4;
	vec1[0][1] = 5;
	vec1[1][1] = 1;
	vec2[0][0] = 6;
	vec2[0][1] = 4;
	vec2[1][1] = 2;
	vec3[0][0] = 10;
	vec3[0][1] = 9;
	vec3[1][1] = 3;
	EXPECT_EQ(vec3, vec1 + vec2);
}
TEST(TMatrix, throw_when_take_matrix_sum_with_different_size) {
	TMatrix<int> vec1(2), vec2(3);
	ASSERT_ANY_THROW(vec1 + vec2);
}
TEST(TMatrix, can_take_matrix_difference_with_same_size) {
	TMatrix<int> vec1(2), vec2(2), vec3(2);
	vec1[0][0] = 4;
	vec1[0][1] = 5;
	vec1[1][1] = 1;
	vec2[0][0] = 6;
	vec2[0][1] = 4;
	vec2[1][1] = 2;
	vec3[0][0] = -2;
	vec3[0][1] = 1;
	vec3[1][1] = -1;
	EXPECT_EQ(vec3, vec1 - vec2);
}
TEST(TMatrix, throw_when_take_matrix_difference_with_different_size) {
	TMatrix<int> vec1(2), vec2(3);
	ASSERT_ANY_THROW(vec1 - vec2);
}
TEST(TMatrix, can_take_matrix_mul_with_same_size) {
	TMatrix<int> vec1(2), vec2(2), vec3(2);
	vec1[0][0] = 4;
	vec1[0][1] = 5;
	vec1[1][1] = 1;
	vec2[0][0] = 6;
	vec2[0][1] = 4;
	vec2[1][1] = 2;
	vec3[0][0] = 24;
	vec3[0][1] = 26;
	vec3[1][1] = 2;
	EXPECT_EQ(vec3, vec1 * vec2);
}
TEST(TMatrix, throw_when_take_matrix_mul_with_different_size) {
	TMatrix<int> vec1(2), vec2(3);
	ASSERT_ANY_THROW(vec1 * vec2);
}