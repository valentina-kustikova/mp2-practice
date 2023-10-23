#include "TMatrix.h"

#include <gtest.h>

TEST(TMatrix, non_commutativity_multi_matrix) {
	TMatrix<int> Matrix1(4),Matrix2(4),result1(1),result2(1);

	for (int i = 0; i < Matrix1.GetSize(); i++) {
		for (int j = 0; j < Matrix1.GetSize(); j++) {
			Matrix1[i][j] = j;
		}
	}

	for (int i = 0; i < Matrix2.GetSize(); i++) {
		for (int j = 0; j < Matrix2.GetSize(); j++) {
			Matrix2[i][j] = j+j;
		}
	}

	result1 = Matrix1 * Matrix2;
	result2 = Matrix2 * Matrix1;

	EXPECT_NE(result1, result2);
}

