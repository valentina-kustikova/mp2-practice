#include "vector.h"
#include <gtest.h>

TEST(TVector, throws_when_negative_length)
{
	ASSERT_ANY_THROW(TVector<int> vect(-1, 3));
}
TEST(TVector, throws_when_zero_length)
{
	ASSERT_ANY_THROW(TVector<int> vect(0, 3));
}
TEST(TVector, can_create_positive_length)
{
	ASSERT_NO_THROW(TVector<int> vect(5, 3));
}
TEST(TVector, can_create_a_copy) {
	TVector<int> vect(5, 3);
	ASSERT_NO_THROW(TVector<int> vect1(vect));
}

TEST(TVector, can_use_indexing){
	TVector<int> vect(5, 3);
	ASSERT_NO_THROW(vect[0]);
}
TEST(TVector, can_get_size)
{
	TVector<int> vect(5, 3);
	EXPECT_EQ(5, vect.getsize());
}
TEST(TVector, can_get_index)
{
	TVector<int> vect(5, 3);
	EXPECT_EQ(3, vect.getindex());
}

TEST(TVector, false_when_compare_with_non_equal_indexes)
{
	TVector<int> vect(5, 3);
	TVector<int> vect1(5, 2);
	ASSERT_EQ(false, vect==vect1);
}
TEST(TVector, false_when_compare_with_non_equal_sizes)
{
	TVector<int> vect(4, 3);
	TVector<int> vect1(5, 3);
	ASSERT_EQ(false, vect == vect1);
}

TEST(TVector, false_when_diff_vectors_eq) {
	TVector<int> vect(2, 3);
	TVector<int> vect1(2, 3);
	vect[0] = 4;
	vect[1] = -2;
	vect1[0] = 2;
	vect1[1] = 0;
	ASSERT_EQ(false, vect == vect1);
}
TEST(TVector, true_when_diff_vectors_uneq) {
	TVector<int> vect(2, 3);
	TVector<int> vect1(2, 3);
	vect[0] = 4;
	vect[1] = -2;
	vect1[0] = 2;
	vect1[1] = 0;
	ASSERT_EQ(true, vect != vect1);
}
TEST(TVector, true_when_same_vectors_eq) {
	TVector<int> vect(2, 3);
	TVector<int> vect1(2, 3);
	vect[0] = 2;
	vect[1] = 0;
	vect1[0] = 2;
	vect1[1] = 0;
	ASSERT_EQ(true, vect == vect1);
}
TEST(TVector, false_when_same_vectors_uneq) {
	TVector<int> vect(2, 3);
	TVector<int> vect1(2, 3);
	vect[0] = 2;
	vect[1] = 0;
	vect1[0] = 2;
	vect1[1] = 0;
	ASSERT_EQ(false, vect != vect1);
}

TEST(TVector, can_assign_eq_size) {
	TVector<int> vect(2, 3);
	TVector<int> vect1(2, 3);
	vect[0] = 4;
	vect[1] = -2;
	vect1 = vect;
	ASSERT_EQ(4, vect1[0]);
}
TEST(TVector, can_assign_diff_size) {
	TVector<int> vect(4, 3);
	TVector<int> vect1(2, 3);
	vect[0] = 4;
	vect[1] = -2;
	vect[2] = 1;
	vect[3] = 6;
	vect1 = vect;
	ASSERT_EQ(3, vect1[3]);
}

TEST(TVector, can_add_number)
{
	TVector<int> vect(2, 3);
	vect[0] = 4;
	vect[1] = -2;
	vect = vect + 2;
	ASSERT_NE(4, vect[0]);
}
TEST(TVector, can_add_vector)
{
	TVector<int> vect(2, 3);
	TVector<int> vect1(2, 3);
	vect[0] = 4;
	vect[1] = -2;
	vect1[0] = 2;
	vect1[1] = 0;
	vect = vect + vect1;
	ASSERT_NE(4, vect[0]);
}

TEST(TVector, can_retract_number)
{
	TVector<int> vect(2, 3);
	vect[0] = 4;
	vect[1] = -2;
	vect = vect - 2;
	ASSERT_NE(4, vect[0]);
}
TEST(TVector, can_retract_vector)
{
	TVector<int> vect(2, 3);
	TVector<int> vect1(2, 3);
	vect[0] = 4;
	vect[1] = -2;
	vect1[0] = 2;
	vect1[1] = 0;
	vect = vect - vect1;
	ASSERT_NE(4, vect[0]);
}

TEST(TVector, can_multiply_number)
{
	TVector<int> vect(2, 3);
	vect[0] = 4;
	vect[1] = -2;
	vect = vect * 2;
	ASSERT_NE(4, vect[0]);
}
TEST(TVector, can_multiply_vector)
{
	TVector<int> vect(2, 3);
	TVector<int> vect1(2, 3);
	vect[0] = 4;
	vect[1] = -2;
	vect1[0] = 2;
	vect1[1] = 0;
	vect = vect - vect1;
	ASSERT_EQ(8, vect*vect1);
}

TEST(TVector, throws_when_adding_diff_length)
{
	TVector<int> vect(1, 3);
	TVector<int> vect1(2, 3);
	ASSERT_ANY_THROW(vect+vect1);
}
TEST(TVector, throws_when_retracting_diff_length)
{
	TVector<int> vect(1, 3);
	TVector<int> vect1(2, 3);
	ASSERT_ANY_THROW(vect - vect1);
}
TEST(TVector, throws_when_multiplying_diff_length)
{
	TVector<int> vect(1, 3);
	TVector<int> vect1(2, 3);
	ASSERT_ANY_THROW(vect * vect1);
}

TEST(TVector, throws_when_adding_diff_index)
{
	TVector<int> vect(2, 2);
	TVector<int> vect1(2, 3);
	ASSERT_ANY_THROW(vect + vect1);
}
TEST(TVector, throws_when_retracting_diff_index)
{
	TVector<int> vect(2, 2);
	TVector<int> vect1(2, 3);
	ASSERT_ANY_THROW(vect - vect1);
}
TEST(TVector, throws_when_multiplying_diff_index)
{
	TVector<int> vect(2, 2);
	TVector<int> vect1(2, 3);
	ASSERT_ANY_THROW(vect * vect1);
}


