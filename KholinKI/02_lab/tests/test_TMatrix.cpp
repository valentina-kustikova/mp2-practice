#include "TMatrix.h"

#include <gtest.h>

TEST(TMatrix, throw_when_create_matrix_with_negative_dimensionality) {
	ASSERT_ANY_THROW(TMatrix<double> matr1(-4), const Exeptions<int>);
}

TEST(TMatrix, can_create_matrix_with_positive_dimensionality) {
	ASSERT_NO_THROW(TMatrix<double> matr1(4));
}

TEST(TMatrix, no_throw_when_use_constructor_copy) {
	TMatrix<float> matrix1(3);
	ASSERT_NO_THROW(TMatrix<float> matrix2(matrix1));
}

TEST(TMatrix, can_work_constructor_transform) {
	TVector<TVector<double>> vector_vectors(5);
	ASSERT_NO_THROW(TMatrix<double> matrix(vector_vectors));
}

TEST(TMatrix, check_matrix_start_indices) {
	TMatrix<int> matrix1(4);
	for (int i = 0; i < matrix1.GetSize(); i++) {
		EXPECT_EQ(i,matrix1[i].GetStart());
	}
}

TEST(TMatrix, can_get_element) {
	TMatrix<int> matrix1(4);
	for (int i = 0; i < matrix1.GetSize(); i++) {
		for (int k = matrix1.GetStart() + i; k < matrix1.GetSize(); k++) {
			ASSERT_NO_THROW(matrix1[i][k] = k);
		}
	}
}

TEST(TMatrix, can_get_dimension) {
	TMatrix<int> matrix1(4);
	EXPECT_EQ(4, matrix1.GetSize());
}

TEST(TMatrix, equality) {
	TMatrix<double> matr1(4), matr2(4);
	for (int i = 0; i < matr1.GetSize(); i++) {
		for (int k = matr1.GetStart() + i; k < matr1.GetSize(); k++) {
			matr1[i][k] = k;
		}
	}

	for (int i = 0; i < matr2.GetSize(); i++) {
		for (int k = matr2.GetStart() + i; k < matr2.GetSize(); k++) {
			matr2[i][k] = k;
		}
	}
	ASSERT_TRUE(matr1 == matr2);
}

TEST(TMatrix, non_equality_dimensions) {
	TMatrix<double> matr1(3), matr2(4);
	for (int i = 0; i < matr1.GetSize(); i++) {
		for (int k = matr1.GetStart() + i; k < matr1.GetSize(); k++) {
			matr1[i][k] = k;
		}
	}

	for (int i = 0; i < matr2.GetSize(); i++) {
		for (int k = matr2.GetStart() + i; k < matr2.GetSize(); k++) {
			matr2[i][k] = k;
		}
	}
	ASSERT_FALSE(matr1 == matr2);
}

TEST(TMatrix, non_equality_values) {
	TMatrix<double> matr1(4), matr2(4);
	for (int i = 0; i < matr1.GetSize(); i++) {
		for (int k = matr1.GetStart() + i; k < matr1.GetSize(); k++) {
			matr1[i][k] = 2*k;
		}
	}

	for (int i = 0; i < matr2.GetSize(); i++) {
		for (int k = matr2.GetStart() + i; k < matr2.GetSize(); k++) {
			matr2[i][k] = k;
		}
	}
	ASSERT_FALSE(matr1 == matr2);
}


TEST(can_assign_matrix_not_equal_dimensions) {
	TMatrix<double> matr1(4), matr2(3);

	for (int i = 0; i < matr1.GetSize(); i++) {
		for (int k = matr1.GetStart() + i; k < matr1.GetSize(); k++) {
			matr1[i][k] = k * 2;
		}
	}

	for (int i = 0; i < matr2.GetSize(); i++) {
		for (int k = matr2.GetStart() + i; k < matr2.GetSize(); k++) {
			matr2[i][k] = k * 3;
		}
	}
	matr2 = matr1;
	EXPECT_EQ(matr1,matr2);
}


TEST(can_assign_matrix_equal_dimensions) {
	TMatrix<double> matr1(4), matr2(4);

	for (int i = 0; i < matr1.GetSize(); i++) {
		for (int k = matr1.GetStart() + i; k < matr1.GetSize(); k++) {
			matr1[i][k] = k * 2;
		}
	}

	for (int i = 0; i < matr2.GetSize(); i++) {
		for (int k = matr2.GetStart() + i; k < matr2.GetSize(); k++) {
			matr2[i][k] = k * 3;
		}
	}
	matr2 = matr1;
	EXPECT_EQ(matr1, matr2);
}



TEST(TMatrix, no_throw_when_plus_operator_with_matrix_equal_dimensions) {
	TMatrix<double> matr1(4),matr2(4);

	for (int i = 0; i < matr1.GetSize(); i++) {
		for (int k = matr1.GetStart() + i; k < matr1.GetSize(); k++) {
			matr1[i][k] = k*2;
		}
	}

	for (int i = 0; i < matr2.GetSize(); i++) {
		for (int k = matr2.GetStart() + i; k < matr2.GetSize(); k++) {
			matr2[i][k] = k*3;
		}
	}


	ASSERT_NO_THROW(matr1+matr2);
}

TEST(TMatrix, throw_when_plus_operator_with_matrix_not_equal_dimensions) {
	TMatrix<double> matr1(4), matr2(3);

	for (int i = 0; i < matr1.GetSize(); i++) {
		for (int k = matr1.GetStart() + i; k < matr1.GetSize(); k++) {
			matr1[i][k] = k * 2;
		}
	}

	for (int i = 0; i < matr2.GetSize(); i++) {
		for (int k = matr2.GetStart() + i; k < matr2.GetSize(); k++) {
			matr2[i][k] = k * 3;
		}
	}

	ASSERT_ANY_THROW(matr1+matr2);
}

TEST(TMatrix, no_throw_when_minus_operator_with_matrix_equal_dimension) {
	TMatrix<double> matr1(4), matr2(4);

	for (int i = 0; i < matr1.GetSize(); i++) {
		for (int k = matr1.GetStart() + i; k < matr1.GetSize(); k++) {
			matr1[i][k] = k * 2;
		}
	}

	for (int i = 0; i < matr2.GetSize(); i++) {
		for (int k = matr2.GetStart() + i; k < matr2.GetSize(); k++) {
			matr2[i][k] = k * 3;
		}
	}

	ASSERT_NO_THROW(matr1-matr2);
}

TEST(TMatrix, throw_when_minus_operator_with_matrix_not_equal_dimension) {
	TMatrix<double> matr1(4), matr2(3);

	for (int i = 0; i < matr1.GetSize(); i++) {
		for (int k = matr1.GetStart() + i; k < matr1.GetSize(); k++) {
			matr1[i][k] = k * 2;
		}
	}

	for (int i = 0; i < matr2.GetSize(); i++) {
		for (int k = matr2.GetStart() + i; k < matr2.GetSize(); k++) {
			matr2[i][k] = k * 3;
		}
	}

	ASSERT_ANY_THROW(matr1 - matr2);
}

TEST(TMatrix, no_throw_when_mult_operator_with_matrix_equal_dimension) {
	TMatrix<double> matr1(4), matr2(4);

	for (int i = 0; i < matr1.GetSize(); i++) {
		for (int k = matr1.GetStart() + i; k < matr1.GetSize(); k++) {
			matr1[i][k] = k * 2;
		}
	}

	for (int i = 0; i < matr2.GetSize(); i++) {
		for (int k = matr2.GetStart() + i; k < matr2.GetSize(); k++) {
			matr2[i][k] = k * 3;
		}
	}

	ASSERT_NO_THROW(matr1 * matr2);
}

TEST(TMatrix, throw_when_mult_operator_with_matrix_not_equal_dimension) {
	TMatrix<double> matr1(4), matr2(3);

	for (int i = 0; i < matr1.GetSize(); i++) {
		for (int k = matr1.GetStart() + i; k < matr1.GetSize(); k++) {
			matr1[i][k] = k * 2;
		}
	}

	for (int i = 0; i < matr2.GetSize(); i++) {
		for (int k = matr2.GetStart() + i; k < matr2.GetSize(); k++) {
			matr2[i][k] = k * 3;
		}
	}

	ASSERT_ANY_THROW(matr1 * matr2);
}

TEST(TMatrix, triple_assign) {
	TMatrix<double> matr1(4), matr2(4),matr3(4);

	for (int i = 0; i < matr1.GetSize(); i++) {
		for (int k = matr1.GetStart() + i; k < matr1.GetSize(); k++) {
			matr1[i][k] = k * 2;
		}
	}

	for (int i = 0; i < matr2.GetSize(); i++) {
		for (int k = matr2.GetStart() + i; k < matr2.GetSize(); k++) {
			matr2[i][k] = k * 3;
		}
	}
	matr1 = matr3 = matr2;
	ASSERT_TRUE((matr1 == matr3) && (matr1 == matr2) && (matr2 == matr3));
}


