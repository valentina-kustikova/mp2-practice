#include "tvector.h"

#include <gtest.h>

/*
DefaultConstructorTest: 		Проверка конструктора по умолчанию.
ParameterizedConstructorTest: 	Проверка параметризованного конструктора.
CopyConstructorTest: 			Проверка конструктора копирования.
AssignmentOperatorTest: 		Проверка оператора присваивания.
GetSizeTest: 					Проверка метода GetSize().
GetStartIndexTest: 				Проверка метода GetStartIndex().
IndexingTest: 					Проверка оператора индексации operator[].
ScalarMultiplicationTest: 		Проверка оператора умножения на скаляр.
ScalarAdditionTest: 			Проверка оператора сложения с скаляром.
ScalarSubtractionTest: 			Проверка оператора вычитания с скаляром.
VectorAdditionTest: 			Проверка оператора сложения двух векторов.
VectorSubtractionTest: 			Проверка оператора вычитания двух векторов.
VectorDotProductTest: 			Проверка оператора скалярного произведения векторов.
EqualityTest: 					Проверка оператора сравнения на равенство.
InequalityTest: 				Проверка оператора сравнения на неравенство.
*/


/*

TEST(TVector, ){
	
}

*/



// DefaultConstructorTests
TEST(TVector, DefaultConstructorTest){
	ASSERT_NO_THROW(TVector<int> v);
}

// ParameterizedConstructorTests
TEST(TVector, ParameterizedConstructorTest_PositiveLength){
	ASSERT_NO_THROW(TVector<int> v(3));
}

TEST(TVector, throw_ParameterizedConstructorTest_ZeroLength){
	ASSERT_ANY_THROW(TVector<int> v(0));
}

TEST(TVector, throw_ParameterizedConstructorTest_NegativeLength){
	ASSERT_ANY_THROW(TVector<int> v(-3));
}

TEST(TVector, throw_ParameterizedConstructorTest_NegativeStartIndex){
	ASSERT_ANY_THROW(TVector<int> v(3, -1));
}

// CopyConstructorTests
TEST(TVector, CopyConstructorTest){
	TVector<int> v(3);

	ASSERT_NO_THROW(TVector<int> test(v));
}

// EqualityTests
TEST(TVector, EqualityTest_Equal) {
	int size = 3;
	TVector<int> v1(size);
	TVector<int> v2(size);
	for (int i = 0; i < size; i++) {
		v1[i] = i;
		v2[i] = i;
	}

	EXPECT_EQ(1, v1 == v2);


	TVector<int> v3(size, 2);
	TVector<int> v4(size, 2);
	for (int i = v3.GetStartIndex(); i < size; i++) {
		v3[i] = i;
		v4[i] = i;
	}

	EXPECT_EQ(1, v3 == v4);
}

TEST(TVector, EqualityTest_InequalSize) {
	int size1 = 3;
	int size2 = 4;
	
	TVector<int> v1(size1);
	TVector<int> v2(size2);

	EXPECT_EQ(0, v1 == v2);
}

TEST(TVector, EqualityTest_InequalStartIndex) {
	int size = 3;
	int sind1 = 1, sind2 = 2;

	TVector<int> v1(size, sind1);
	TVector<int> v2(size, sind2);

	EXPECT_EQ(0, v1 == v2);
}

// InequalityTests
TEST(TVector, InequalityTest_Equal) {
	int size = 3;
	TVector<int> v1(size);
	TVector<int> v2(size);
	for (int i = 0; i < size; i++) {
		v1[i] = i;
		v2[i] = i;
	}
	
	EXPECT_EQ(0, v1 != v2);


	TVector<int> v3(size, 2);
	TVector<int> v4(size, 2);
	for (int i = v3.GetStartIndex(); i < size; i++) {
		v3[i] = i;
		v4[i] = i;
	}

	EXPECT_EQ(0, v3 != v4);
}

TEST(TVector, InequalityTest_InequalSize) {
	int size1 = 3;
	int size2 = 4;

	TVector<int> v1(size1);
	TVector<int> v2(size2);

	EXPECT_EQ(1, v1 != v2);
}

TEST(TVector, InequalityTest_InequalStartIndex) {
	int size = 3;
	int sind1 = 1, sind2 = 2;

	TVector<int> v1(size, sind1);
	TVector<int> v2(size, sind2);

	EXPECT_EQ(1, v1 != v2);
}

// AssignmentOperatorTests
TEST(TVector, AssignmentOperatorTest_Self) {
	int size = 3;

	TVector<int> v1(size), expv(size);

	for (int i = 0; i < size; i++) {
		expv[i] = i;
		v1[i] = i;
	}

	v1 = v1;

	EXPECT_EQ(expv, v1);
}

TEST(TVector, AssignmentOperatorTest_EqualSize){
	int size = 3;

	TVector<int> v1(size), expv(size);

	for (int i = 0; i < size; i++) {
		expv[i] = i;
	}

	v1 = expv;

	EXPECT_EQ(expv, v1);
}

TEST(TVector, AssignmentOperatorTest_DifferentSize){
	int size = 3;
	int expsize = 5;

	TVector<int> v1(size), expv(expsize);

	for (int i = 0; i < expsize; i++) {
		expv[i] = i;
	}

	v1 = expv;

	EXPECT_EQ(expv, v1);
}

// GetSizeTests
TEST(TVector, GetSizeTest){
	TVector<int> v(3);

	EXPECT_EQ(3, v.GetSize());
}

// GetStartIndexTests
TEST(TVector, GetStartIndexTest){
	TVector<int> v(2, 2);

	EXPECT_EQ(2, v.GetStartIndex());
}

// IndexingTests
TEST(TVector, IndexingTest){
	
}

TEST(TVector, throw_IndexingTest_TooLargeIndex){
	TVector<int> v1(3);
	ASSERT_ANY_THROW(v1[5]);

	TVector<int> v2(3, 1);
	ASSERT_ANY_THROW(v2[5]);
}

TEST(TVector, throw_IndexingTest_NegativeIndex){
	TVector<int> v(3);

	ASSERT_ANY_THROW(v[-1]);
}

TEST(TVector, throw_IndexingTest_IndexLessThanStartIndex){
	TVector<int> v(3, 2);
	ASSERT_ANY_THROW(v[0]);
}


// ScalarMultiplicationTests
TEST(TVector, ScalarMultiplicationTest){
	int size = 4;
	int sind = 2;
	
	// 1 2 3 4
	TVector<int> v1(size);
	// 2 4 6 8
	TVector<int> expv1(size);

	for (int i = 0; i < size; i++) {
		v1[i] = i + 1;
		expv1[i] = (i + 1) * 2;
	}

	v1 = v1 * 2;

	EXPECT_EQ(expv1, v1);

	// 0 0 1 2 3 4
	TVector<int> v2(size, sind);
	// 0 0 2 4 6 8
	TVector<int> expv2(size, sind);

	for (int i = 0; i < size; i++) {
		v2[i] = i + 1;
		expv2[i] = (i + 1) * 2;
	}

	v2 = v2 * 2;

	EXPECT_EQ(expv2, v2);
}

// ScalarAdditionTests
TEST(TVector, ScalarAdditionTest){
	
}

// ScalarSubtractionTests
TEST(TVector, ScalarSubtractionTest){
	
}

// VectorAdditionTests
TEST(TVector, VectorAdditionTest){
	
}

TEST(TVector, throw_VectorAdditionTest_InequalSize){
	
}

TEST(TVector, throw_VectorAdditionTest_InequalStartIndex){
	
}

// VectorSubtractionTests
TEST(TVector, VectorSubtractionTest){
	
}

TEST(TVector, throw_VectorSubtractionTest_InequalSize){
	
}

TEST(TVector, throw_VectorSubtractionTest_InequalStartIndex){
	
}

// VectorDotProductTests
TEST(TVector, VectorDotProductTest){
	
}

TEST(TVector, throw_VectorDotProductTest_InequalSize){
	
}

TEST(TVector, throw_VectorDotProductTest_InequalStartIndex){
	
}





/////////////////////////////////////////////////////////////
/*
TEST(TVector, can_create_bitfield_with_positive_length) {
    ASSERT_NO_THROW(TVector<int> v(3));
}

TEST(TVecnor, can_get_size) {
    TVector<int> v(3);

    EXPECT_EQ(3, v.GetSize());
}

TEST(TVecnor, can_get_startIndex) {
    TVector<int> v(3, 1);

    EXPECT_EQ(1, v.GetStartIndex());
}

TEST(TVecnor, can_set_value) {
    TVector<int> v(5);

    v[3] = 3;

    EXPECT_EQ(3, v[3]);
	
	v[3] += 1;
	
	EXPECT_EQ(4, v[3]);
}


// THROWS

TEST(TVecnor, throws_when_) {
    ASSERT_ANY_THROW();
}


TEST(TVecnor, throws_when_create_vector_with_negative_size) {
    ASSERT_ANY_THROW(TVector<int> v(-10));
}

TEST(TVecnor, throws_when_create_vector_with_negative_startIndex) {
    ASSERT_ANY_THROW(TVector<int> v(10, -5));
}

TEST(TVecnor, throws_when_index_is_negative) {
    TVector<int> v(10);
    ASSERT_ANY_THROW(v[-5]);
}

TEST(TVecnor, throws_when_index_is_too_large) {
    TVector<int> v(10);
    ASSERT_ANY_THROW(v[15]);
}

TEST(TVecnor, throws_when_index_is_less_than_startIndex) {
    TVector<int> v(10,5);
    ASSERT_ANY_THROW(v[3]);
}
*/
/////////////////////////////////////////////////////////////

/*
// EXAMPLE


TEST(TBitField, new_bitfield_is_set_to_zero)
{
  TBitField bf(100);

  int sum = 0;
  for (int i = 0; i < bf.GetLength(); i++)
  {
    sum += bf.GetBit(i);
  }

  EXPECT_EQ(0, sum);
}

TEST(TBitField, can_set_bit)
{
  TBitField bf(10);

  EXPECT_EQ(0, bf.GetBit(3));

  bf.SetBit(3);
  EXPECT_NE(0, bf.GetBit(3));
}

TEST(TBitField, can_clear_bit)
{
  TBitField bf(10);

  int bitIdx = 3;

  bf.SetBit(bitIdx);
  EXPECT_NE(0, bf.GetBit(bitIdx));

  bf.ClrBit(bitIdx);
  EXPECT_EQ(0, bf.GetBit(bitIdx));
}




TEST(TBitField, throws_when_get_bit_with_negative_index)
{
  TBitField bf(10);

  ASSERT_ANY_THROW(bf.GetBit(-3));
}

TEST(TBitField, throws_when_get_bit_with_too_large_index)
{
  TBitField bf(10);

  ASSERT_ANY_THROW(bf.GetBit(11));
}

TEST(TBitField, throws_when_clear_bit_with_negative_index)
{
  TBitField bf(10);

  ASSERT_ANY_THROW(bf.ClrBit(-3));
}

TEST(TBitField, throws_when_clear_bit_with_too_large_index)
{
  TBitField bf(10);

  ASSERT_ANY_THROW(bf.ClrBit(11));
}

TEST(TBitField, can_assign_bitfields_of_equal_size)
{
  const int size = 2;
  TBitField bf1(size), bf2(size);
  for (int i = 0; i < size; i++)
  {
    bf1.SetBit(i);
  }
  bf2 = bf1;

  EXPECT_NE(0, bf2.GetBit(0));
  EXPECT_NE(0, bf2.GetBit(1));
}

TEST(TBitField, assign_operator_changes_bitfield_size)
{
  const int size1 = 2, size2 = 5;
  TBitField bf1(size1), bf2(size2);
  for (int i = 0; i < size1; i++)
  {
    bf1.SetBit(i);
  }
  bf2 = bf1;

  EXPECT_EQ(2, bf2.GetLength());
}

TEST(TBitField, can_assign_bitfields_of_non_equal_size)
{
  const int size1 = 2, size2 = 5;
  TBitField bf1(size1), bf2(size2);
  for (int i = 0; i < size1; i++)
  {
    bf1.SetBit(i);
  }
  bf2 = bf1;

  EXPECT_NE(0, bf2.GetBit(0));
  EXPECT_NE(0, bf2.GetBit(1));
}

TEST(TBitField, compare_equal_bitfields_of_equal_size)
{
  const int size = 2;
  TBitField bf1(size), bf2(size);
  for (int i = 0; i < size; i++)
  {
    bf1.SetBit(i);
  }
  bf2 = bf1;

  EXPECT_EQ(bf1, bf2);
}

TEST(TBitField, or_operator_applied_to_bitfields_of_equal_size)
{
  const int size = 4;
  TBitField bf1(size), bf2(size), expBf(size);
  // bf1 = 0011
  bf1.SetBit(2);
  bf1.SetBit(3);
  // bf2 = 0101
  bf2.SetBit(1);
  bf2.SetBit(3);

  // expBf = 0111
  expBf.SetBit(1);
  expBf.SetBit(2);
  expBf.SetBit(3);

  EXPECT_EQ(expBf, bf1 | bf2);
}

TEST(TBitField, or_operator_applied_to_bitfields_of_non_equal_size)
{
  const int size1 = 4, size2 = 5;
  TBitField bf1(size1), bf2(size2), expBf(size2);
  // bf1 = 0011
  bf1.SetBit(2);
  bf1.SetBit(3);
  // bf2 = 01010
  bf2.SetBit(1);
  bf2.SetBit(3);

  // expBf = 01110
  expBf.SetBit(1);
  expBf.SetBit(2);
  expBf.SetBit(3);

  EXPECT_EQ(expBf, bf1 | bf2);
}

TEST(TBitField, and_operator_applied_to_bitfields_of_equal_size)
{
  const int size = 4;
  TBitField bf1(size), bf2(size), expBf(size);
  // bf1 = 0011
  bf1.SetBit(2);
  bf1.SetBit(3);
  // bf2 = 0101
  bf2.SetBit(1);
  bf2.SetBit(3);

  // expBf = 0001
  expBf.SetBit(3);

  EXPECT_EQ(expBf, bf1 & bf2);
}

TEST(TBitField, and_operator_applied_to_bitfields_of_non_equal_size)
{
  const int size1 = 4, size2 = 5;
  TBitField bf1(size1), bf2(size2), expBf(size2);
  // bf1 = 0011
  bf1.SetBit(2);
  bf1.SetBit(3);
  // bf2 = 01010
  bf2.SetBit(1);
  bf2.SetBit(3);

  // expBf = 00010
  expBf.SetBit(3);

  EXPECT_EQ(expBf, bf1 & bf2);
}

TEST(TBitField, can_invert_bitfield)
{
  const int size = 2;
  TBitField bf(size), negBf(size), expNegBf(size);
  // bf = 01
  bf.SetBit(1);
  negBf = ~bf;

  // expNegBf = 10
  expNegBf.SetBit(0);

  EXPECT_EQ(expNegBf, negBf);
}

TEST(TBitField, can_invert_large_bitfield)
{
  const int size = 38;
  TBitField bf(size), negBf(size), expNegBf(size);
  bf.SetBit(35);
  negBf = ~bf;

  for(int i = 0; i < size; i++)
    expNegBf.SetBit(i);
  expNegBf.ClrBit(35);

  EXPECT_EQ(expNegBf, negBf);
}

TEST(TBitField, can_invert_many_random_bits_bitfield)
{
  const int size = 38;
  TBitField bf(size), negBf(size), expNegBf(size);

  std::vector<int> bits;
  bits.push_back(0);
  bits.push_back(1);
  bits.push_back(14);
  bits.push_back(16);
  bits.push_back(33);
  bits.push_back(37);

  for (unsigned int i = 0; i < bits.size(); i++)
    bf.SetBit(bits[i]);

  negBf = ~bf;

  for(int i = 0; i < size; i++)
    expNegBf.SetBit(i);
  for (unsigned int i = 0; i < bits.size(); i++)
    expNegBf.ClrBit(bits[i]);

  EXPECT_EQ(expNegBf, negBf);
}

TEST(TBitField, bitfields_with_different_bits_are_not_equal)
{
  const int size = 4;
  TBitField bf1(size), bf2(size);

  bf1.SetBit(1);
  bf1.SetBit(3);

  bf2.SetBit(1);
  bf2.SetBit(2);

  EXPECT_NE(bf1, bf2);
}
*/