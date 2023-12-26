#include "TVector.h"

#include <gtest.h>

TEST(TVector, can_create_vector_with_positive_size) {
	ASSERT_NO_THROW(TVector<int> vec(3));
}
TEST(TVector, can_create_vector_with_positive_start_index) {
	ASSERT_NO_THROW(TVector<int> vec(3, 4));
}
TEST(TVector, throw_when_create_vector_with_negative_size) {
	ASSERT_ANY_THROW(TVector<int> vec(-3));
}
TEST(TVector, throw_when_create_vector_with_negative_start_index) {
	ASSERT_ANY_THROW(TVector<int> vec(3, -4));
}
TEST(TVector, can_get_size) {
	TVector <int> vec(5);
	EXPECT_EQ(5, vec.GetSize());
}
TEST(TVector, can_get_start_index) {
	TVector <int> vec(5, 3);
	EXPECT_EQ(3, vec.GetStartIndex());
}
TEST(TVector, can_access_an_element) {
	TVector<int> vec(3);
	vec[0] = 1;
	EXPECT_EQ(1, vec[0]);
}
TEST(TVector, throw_when_access_to_elemen_with_large_index) {
	TVector<int> vec(5);
	ASSERT_ANY_THROW(vec[7]);
}
TEST(TVector, throw_when_access_to_elemen_with_negative_index) {
	TVector<int> vec(5);
	ASSERT_ANY_THROW(vec[-3]);
}
TEST(TVector, can_assign_with_equal_size) {
	TVector<int> vec1(3), vec2(3);
	vec1[0] = 1;
	vec1[1] = 2;
	vec1[2] = 3;
	vec2 = vec1;
	EXPECT_EQ(vec1, vec2);
}

TEST(TVector, can_assign_with_non_equal_size) {
	TVector<int> vec1(3), vec2(5);
	vec1[0] = 1;
	vec1[1] = 2;
	vec1[2] = 3;
	vec2 = vec1;
	EXPECT_EQ(vec1, vec2);
}
TEST(TVector, can_take_vectors_sum_with_equal_size_and_equal_start_index) {
	TVector<int> vec1(3), vec2(3), vec3(3);
	vec1[0] = 1;
	vec1[1] = 2;
	vec1[2] = 3;
	vec2[0] = 3;
	vec2[1] = 2;
	vec2[2] = 1;
	vec3[0] = 4;
	vec3[1] = 4;
	vec3[2] = 4;
	EXPECT_EQ(vec3, vec1 + vec2);
}

TEST(TVector, throw_when_take_vectors_sum_with_non_equal_size) {
	TVector<int> vec1(3), vec2(4);
	ASSERT_ANY_THROW(vec1 + vec2);
}
TEST(TVector, throw_when_take_vectors_sum_with_non_equal_start_index) {
	TVector<int> vec1(4, 1), vec2(4, 2);
	ASSERT_ANY_THROW(vec1 + vec2);
}
TEST(TVector, can_take_vectors_difference_with_equal_size_and_equal_start_index) {
	TVector<int> vec1(3), vec2(3), vec3(3);
	vec1[0] = 1;
	vec1[1] = 2;
	vec1[2] = 3;
	vec2[0] = 3;
	vec2[1] = 2;
	vec2[2] = 1;
	vec3[0] = -2;
	vec3[1] = 0;
	vec3[2] = 2;
	EXPECT_EQ(vec3, vec1 - vec2);
}
TEST(TVector, throw_when_take_vectors_difference_with_non_equal_size) {
	TVector<int> vec1(4), vec2(3);
	ASSERT_ANY_THROW(vec1 - vec2);
}
TEST(TVector, throw_when_take_vectors_difference_with_non_equal_start_index) {
	TVector<int> vec1(3, 1), vec2(3, 2);
	ASSERT_ANY_THROW(vec1 - vec2);
}
TEST(TVector, can_take_vectors_mul_with_equal_size_and_equal_start_index) {
	TVector<int> vec1(3), vec2(3);
	vec1[0] = 1;
	vec1[1] = 2;
	vec1[2] = 3;
	vec2[0] = 3;
	vec2[1] = 2;
	vec2[2] = 1;
	EXPECT_EQ(10, vec1 * vec2);
}
TEST(TVector, throw_when_take_vectors_mul_with_non_equal_size) {
	TVector<int> vec1(4), vec2(3);
	ASSERT_ANY_THROW(vec1 * vec2);
}
TEST(TVector, throw_when_take_vectors_mul_with_non_equal_start_index) {
	TVector<int> vec1(3, 1), vec2(3, 2);
	ASSERT_ANY_THROW(vec1 * vec2);
}
TEST(TVector, can_add_number_to_vector) {
	TVector<int> vec1(3), vec2(3);
	vec1[0] = 9;
	vec1[1] = 8;
	vec1[2] = 7;
	vec2[0] = 109;
	vec2[1] = 108;
	vec2[2] = 107;
	EXPECT_EQ(vec2, vec1 + 100);
}
TEST(TVector, can_substract_number_from_vector) {
	TVector<int> vec1(3), vec2(3);
	vec2[0] = 9;
	vec2[1] = 8;
	vec2[2] = 7;
	vec1[0] = 109;
	vec1[1] = 108;
	vec1[2] = 107;
	EXPECT_EQ(vec2, vec1 - 100);
}
TEST(TVector, can_mul_vector_by_number) {
	TVector<int> vec1(3), vec2(3);
	vec1[0] = 9;
	vec1[1] = 8;
	vec1[2] = 7;
	vec2[0] = 900;
	vec2[1] = 800;
	vec2[2] = 700;
	EXPECT_EQ(vec2, vec1 * 100);
}
TEST(TVector, equal_test) {
	TVector<int> vec1(3), vec2(3);
	vec1[0] = 1;
	vec1[1] = 2;
	vec1[2] = 3;
	vec2[0] = 1;
	vec2[1] = 2;
	vec2[2] = 3;
	ASSERT_TRUE(vec1 == vec2);
}
TEST(TVector,non_equal_test) {
	TVector<int> vec1(3), vec2(3);
	vec1[0] = 2;
	vec1[1] = 2;
	vec1[2] = 3;
	vec2[0] = 1;
	vec2[1] = 2;
	vec2[2] = 3;
	ASSERT_TRUE(vec1 != vec2);
}
TEST(TVector, vectors_with_non_equal_size_not_equal) {
	TVector<int> vec1(3), vec2(4);
	ASSERT_FALSE(vec1 == vec2);
}
TEST(TVector, vectors_with_non_equal_start_index_not_equal) {
	TVector<int> vec1(3), vec2(3, 4);
	ASSERT_FALSE(vec1 == vec2);
}