#include "TMatrix.h"

#include <gtest.h>

TEST(TMatrix, throw_when_create_matrix_with_negative_dimensionality) {
	ASSERT_THROW(TMatrix<double> matr1(-4), const Exeptions<int>);
}

TEST(TMatrix, can_create_matrix_with_positive_dimensionality) {
	ASSERT_NO_THROW(TMatrix<double> matr1(4));
}

TEST(TMatrix, can_work_constructor_transform) {
	TVector<TVector<double>> vecs(5);
	TMatrix<double> matr(vecs);
	EXPECT_EQ(matr.GetStart(), vecs.GetStart());
	EXPECT_EQ(matr.GetSize(), vecs.GetSize());
	EXPECT_EQ(matr, vecs);
}

TEST(TMatrix, can_compare_matrix_equal_dimension) {
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

	EXPECT_EQ(matr1.GetStart(), matr2.GetStart());
	EXPECT_EQ(matr1.GetSize(), matr2.GetSize());
	EXPECT_EQ(matr1, matr2);
}

TEST(TMatrix, can_compare_matrix_not_equal_dimension) {
	TMatrix<double> matr1(4), matr2(3);
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

	EXPECT_NE(matr1.GetSize(), matr2.GetSize());
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


TEST(can_assign_matrix_equal_dimensions_and_elements) {
	TMatrix<double> matr1(4), matr2(3);

	for (int i = 0; i < matr1.GetSize(); i++) {
		for (int k = matr1.GetStart() + i; k < matr1.GetSize(); k++) {
			matr1[i][k] = k * 2;
		}
	}

	for (int i = 0; i < matr2.GetSize(); i++) {
		for (int k = matr2.GetStart() + i; k < matr2.GetSize(); k++) {
			matr2[i][k] = k * 2;
		}
	}
	matr2 = matr1;
	EXPECT_EQ(matr1, matr2);
}

TEST(TMatrix, no_thrown_when_plus_operator_with_matrix_equal_dimensions) {
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

	ASSERT_THROW(matr1+matr2,const Exeptions<int>);
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

	ASSERT_THROW(matr1 - matr2,const Exeptions<int>);
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

	ASSERT_THROW(matr1 * matr2,const Exeptions<int>);
}

