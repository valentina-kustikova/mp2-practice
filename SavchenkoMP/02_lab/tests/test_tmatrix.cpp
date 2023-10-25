#include "tmatrix.h"

#include <gtest.h>

/*
DefaultConstructorTest: 		Проверка конструктора по умолчанию.
ParameterizedConstructorTest: 	Проверка параметризованного конструктора.
CopyConstructorTest: 			Проверка конструктора копирования.
AssignmentOperatorTest: 		Проверка оператора присваивания.
GetSizeTest: 					Проверка метода GetSize().
GetStartIndexTest: 				Проверка метода GetStartIndex().
IndexingTest: 					Проверка оператора индексации operator[].
MatrixAdditionTest: 			Проверка оператора сложения двух векторов.
MatrixSubtractionTest: 			Проверка оператора вычитания двух векторов.
MatrixDotProductTest: 			Проверка оператора скалярного произведения векторов.
EqualityTest: 					Проверка оператора сравнения на равенство.
InequalityTest: 				Проверка оператора сравнения на неравенство.
*/




/*

TEST(TMatrix, ){
	
}

*/

// DefaultConstructorTests
TEST(TMatrix, DefaultConstructorTest){
	
}

// ParameterizedConstructorTests
TEST(TMatrix, ParameterizedConstructorTest_PositiveLength){
	
}

TEST(TMatrix, throw_ParameterizedConstructorTest_ZeroLength){
	
}

TEST(TMatrix, throw_ParameterizedConstructorTest_NegativeLength){
	
}

TEST(TMatrix, throw_ParameterizedConstructorTest_NegativeStartIndex){
	
}

// CopyConstructorTests
TEST(TMatrix, CopyConstructorTest){
	
}

// AssignmentOperatorTests
TEST(TMatrix, AssignmentOperatorTest_Self){
	
}

TEST(TMatrix, AssignmentOperatorTest_EqualSize){
	
}

TEST(TMatrix, AssignmentOperatorTest_DifferentSize){
	
}

// GetSizeTests
TEST(TMatrix, GetSizeTest){
	
}

// GetStartIndexTests
TEST(TMatrix, GetStartIndexTest){
	
}

// IndexingTests
TEST(TMatrix, IndexingTest){
	
}

TEST(TMatrix, throw_IndexingTest_TooLargeIndex){
	
}

TEST(TMatrix, throw_IndexingTest_NegativeIndex){
	
}

TEST(TMatrix, throw_IndexingTest_IndexLessThanStartIndex){
	
}

// EqualityTests
TEST(TMatrix, EqualityTest_Equal){
	
}

TEST(TMatrix, EqualityTest_InequalSize){
	
}

TEST(TMatrix, EqualityTest_InequalStartIndex){
	
}

// InequalityTests
TEST(TMatrix, InequalityTest_Equal){
	
}

TEST(TMatrix, InequalityTest_InequalSize){
	
}

TEST(TMatrix, InequalityTest_InequalStartIndex){
	
}

// MatrixAdditionTests
TEST(TMatrix, MatrixAdditionTest){
	
}

TEST(TMatrix, throw_MatrixAdditionTest_InequalSize){
	
}

TEST(TMatrix, throw_MatrixAdditionTest_InequalStartIndex){
	
}

// MatrixSubtractionTests
TEST(TMatrix, MatrixSubtractionTest){
	
}

TEST(TMatrix, throw_MatrixSubtractionTest_InequalSize){
	
}

TEST(TMatrix, throw_MatrixSubtractionTest_InequalStartIndex){
	
}

// MatrixDotProductTests
TEST(TMatrix, MatrixDotProductTest){
	
}

TEST(TMatrix, throw_MatrixDotProductTest_InequalSize){
	
}

TEST(TMatrix, throw_MatrixDotProductTest_InequalStartIndex){
	
}