#include "vector.h"
#include <gtest.h>

TEST(TVector, throws_when_negative_length_without_si)
{
	ASSERT_ANY_THROW(TVector<int> vect(-1));
}
TEST(TVector, throws_when_negative_length)
{
	ASSERT_ANY_THROW(TVector<int> vect(-1, 3));
}

TEST(TVector, throws_when_zero_length)
{
	ASSERT_ANY_THROW(TVector<int> vect(0, 3));
}
TEST(TVector, throws_when_zero_length_n)
{
	ASSERT_ANY_THROW(TVector<int> vect(0));
}

TEST(TVector, can_create_positive_length)
{
	ASSERT_NO_THROW(TVector<int> vect(5, 3));
}
TEST(TVector, can_create_positive_length_n)
{
	ASSERT_NO_THROW(TVector<int> vect(5));
}

TEST(TVector, can_create_a_copy) {
	TVector<int> vect(5);
	ASSERT_NO_THROW(TVector<int> vect1(vect));
}

TEST(TVector, check_own_memory_copied_matrix) {
	TVector<int> vect(5);
	TVector<int> vect1(vect);
	vect1[1] = 2;
	EXPECT_NE(vect, vect1);
}

TEST(TVector, can_use_indexing){
	TVector<int> vect(5);
	ASSERT_NO_THROW(vect[1]);
}
TEST(TVector, throw_on_negative_indexing) {
	TVector<int> vect(5);
	ASSERT_ANY_THROW(vect[-1]);
}
TEST(TVector, throw_on_out_of_range_indexing) {
	TVector<int> vect(5);
	ASSERT_ANY_THROW(vect[7]);
}

TEST(TVector, false_when_compare_with_non_equal_sizes)
{
	TVector<int> vect(4);
	TVector<int> vect1(5);
	EXPECT_NE(vect, vect1);
}

TEST(TVector, false_when_diff_vectors) {
	TVector<int> vect(2);
	TVector<int> vect1(2);
	vect[0] = 4;
	vect[1] = -2;
	vect1[0] = 2;
	vect1[1] = 0;
	EXPECT_NE(vect, vect1);
}

TEST(TVector, true_when_same_vectors) {
	TVector<int> vect(2);
	TVector<int> vect1(2);
	vect[0] = 2;
	vect[1] = 0;
	vect1[0] = 2;
	vect1[1] = 0;
	EXPECT_EQ(vect, vect1);
}


TEST(TVector, can_assign_eq_size) {
	TVector<int> vect(2);
	TVector<int> vect1(2);
	vect[0] = 4;
	vect[1] = -2;
	vect1 = vect;
	EXPECT_EQ(vect, vect1);
}
TEST(TVector, can_assign_diff_size) {
	TVector<int> vect(4);
	TVector<int> vect1(2);
	vect[3] = 3;
	vect1 = vect;
	EXPECT_EQ(vect, vect1);
}

TEST(TVector, can_add_number)
{
	TVector<int> vect(2);
	vect[0] = 4;
	vect[1] = -2;
	TVector<int> expected_vect(2);
	expected_vect[0] = 6;
	expected_vect[1] = 0;
	EXPECT_EQ(vect + 2, expected_vect);
}
TEST(TVector, can_add_vector)
{
	TVector<int> vect(2);
	TVector<int> vect1(2);
	vect[0] = 4;
	vect[1] = -2;
	vect1[0] = 2;
	vect1[1] = 0;
	TVector<int> expected_vec(2);
	expected_vec[0] = 6;
	expected_vec[1] = -2;
	EXPECT_EQ(vect + vect1, expected_vec);
}

TEST(TVector, can_retract_number)
{
	TVector<int> vect(2);
	vect[0] = 4;
	vect[1] = -2;
	TVector<int> expected_vect(2);
	expected_vect[0] = 2;
	expected_vect[1] = -4;
	EXPECT_EQ(vect - 2, expected_vect);
}
TEST(TVector, can_retract_vector)
{
	TVector<int> vect(2);
	TVector<int> vect1(2);
	vect[0] = 4;
	vect[1] = -2;
	vect1[0] = 2;
	vect1[1] = 0;
	TVector<int> expected_vec(2);
	expected_vec[0] = 2;
	expected_vec[1] = -2;
	EXPECT_EQ(vect - vect1, expected_vec);
}

TEST(TVector, can_multiply_number)
{
	TVector<int> vect(2);
	vect[0] = 4;
	vect[1] = -2;
	TVector<int> expected_vect(2);
	expected_vect[0] = 8;
	expected_vect[1] = -4;
	EXPECT_EQ(vect * 2, expected_vect);
}
TEST(TVector, can_multiply_vector)
{
	TVector<int> vect(2);
	TVector<int> vect1(2);
	vect[0] = 4;
	vect[1] = -2;
	vect1[0] = 2;
	vect1[1] = 0;
	TVector<int> expected_vec(2);
	expected_vec[0] = 2;
	expected_vec[1] = -2;
	EXPECT_EQ(vect - vect1, expected_vec);
}

TEST(TVector, throws_on_adding_diff_length)
{
	TVector<int> vect(1);
	TVector<int> vect1(2);
	ASSERT_ANY_THROW(vect+vect1);
}
TEST(TVector, throws_on_retracting_diff_length)
{
	TVector<int> vect(1);
	TVector<int> vect1(2);
	ASSERT_ANY_THROW(vect - vect1);
}
TEST(TVector, throws_on_multiplying_diff_length)
{
	TVector<int> vect(1);
	TVector<int> vect1(2);
	ASSERT_ANY_THROW(vect * vect1);
}

TEST(TVector, throws_on_adding_diff_index)
{
	TVector<int> vect(2, 2);
	TVector<int> vect1(2, 3);
	ASSERT_ANY_THROW(vect + vect1);
}
TEST(TVector, throws_on_retracting_diff_index)
{
	TVector<int> vect(2, 2);
	TVector<int> vect1(2, 3);
	ASSERT_ANY_THROW(vect - vect1);
}
TEST(TVector, throws_on_multiplying_diff_index)
{
	TVector<int> vect(2, 2);
	TVector<int> vect1(2, 3);
	ASSERT_ANY_THROW(vect * vect1);
}


