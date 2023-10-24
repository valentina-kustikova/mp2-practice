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
	
}

// ParameterizedConstructorTests
TEST(TVector, ParameterizedConstructorTest_PositiveLength){
	
}

TEST(TVector, ParameterizedConstructorTest_ZeroLength_throw){
	
}

TEST(TVector, ParameterizedConstructorTest_NegativeLength_throw){
	
}

TEST(TVector, ParameterizedConstructorTest_NegativeStartIndex_throw){
	
}

// CopyConstructorTests
TEST(TVector, CopyConstructorTest){
	
}

// AssignmentOperatorTests
TEST(TVector, AssignmentOperatorTest_Self){
	
}

TEST(TVector, AssignmentOperatorTest_EqualSize){
	
}

TEST(TVector, AssignmentOperatorTest_DifferentSize){
	
}

// GetSizeTests
TEST(TVector, GetSizeTest){
	
}

// GetStartIndexTests
TEST(TVector, GetStartIndexTest){
	
}

// IndexingTests
TEST(TVector, IndexingTest){
	
}

TEST(TVector, IndexingTest_TooLargeIndex_throw){
	
}

TEST(TVector, IndexingTest_NegativeIndex_throw){
	
}

TEST(TVector, IndexingTest_IndexLessThanStartIndex_throw){
	
}

// EqualityTests
TEST(TVector, EqualityTest_Equal){
	
}

TEST(TVector, EqualityTest_InequalSize){
	
}

TEST(TVector, EqualityTest_InequalStartIndex){
	
}

// InequalityTests
TEST(TVector, InequalityTest_Equal){
	
}

TEST(TVector, InequalityTest_InequalSize){
	
}

TEST(TVector, InequalityTest_InequalStartIndex){
	
}

// ScalarMultiplicationTests
TEST(TVector, ScalarMultiplicationTest){
	
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

TEST(TVector, VectorAdditionTest_InequalSize_throw){
	
}

TEST(TVector, VectorAdditionTest_InequalStartIndex_throw){
	
}

// VectorSubtractionTests
TEST(TVector, VectorSubtractionTest){
	
}

TEST(TVector, VectorSubtractionTest_InequalSize_throw){
	
}

TEST(TVector, VectorSubtractionTest_InequalStartIndex_throw){
	
}

// VectorDotProductTests
TEST(TVector, VectorDotProductTest){
	
}

TEST(TVector, VectorDotProductTest_InequalSize_throw){
	
}

TEST(TVector, VectorDotProductTest_InequalStartIndex_throw){
	
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