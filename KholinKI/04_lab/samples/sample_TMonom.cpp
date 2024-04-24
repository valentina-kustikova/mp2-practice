#include "TMonom.h"


int main(){ 
	cout << "The monomials M1 and M2 and M3" << endl << endl;
	TMonom M1(-2, 123); TMonom M2(4, 987); TMonom M3(8, 123); TMonom U_M;

	cout << "M1" << endl;
	cout << M1;

	cout << "M2" << endl;
	cout << M2;
	

	cout << "M3" << endl;
	cout << M3;


	cout << "Getting copy monomial M2..." << endl;
	TMonom M2_copy(M2);
	
	cout << "Before we start performing operations on monomials," << endl;
	cout << "create your own monom: " << endl << endl;
	cin >> U_M;
	cout << endl;
	cout << U_M;

	cout << endl;
	cout << "Let`s start!" << endl;
	cout << endl;

	cout << "The monomials M1 and M2 and M3" << endl << endl;
	cout << "M1" << endl;
	cout << M1;

	cout << "M2" << endl;
	cout << M2;

	cout << "M3" << endl;
	cout << M3;

	cout << "M1 < M2?" << endl;
	if (M1 < M2) {
		cout << "Yes" << endl;
	}
	else {
		cout << "No" << endl;
		cout << endl;
		cout << "M1 == M2?" << endl;
		if (M1 == M2) {
			cout << "Yes,it`s equal monomials" << endl;
		}
		else {
			cout << "No" << endl;
		}
		cout << endl;
	}
	cout << endl;

	cout << "M2 <= M3?" << endl;
	if (M2 <= M3) {
		if (M2 == M3) {
			cout << "Yes,it`s equal monomials" << endl;
		}
		else{
			cout << "Yes, M2 < M3" << endl;
		}
	}
	else {
		cout << "No" << endl;
	}
	cout << endl;

	cout << "M1 != M2?" << endl;

	int M1Coeff = M1.GetCoeff();
	int M2Coeff = M2.GetCoeff();

	if (M1 != M2) {
		if (M1Coeff != M2Coeff) {
			cout << "Yes" << endl;
		}
	}
	else {
		if (M1Coeff == M2Coeff) {
			cout << "Yes,it`s equal monomials" << endl;
		}
		else {
			cout << "No" << endl;
		}
		cout << endl;
	}
	cout << endl;

	cout << "M2 == M2_copy?" << endl;
	if (M2 == M2_copy) {
		cout << "Yes!" << endl;
	}
	else {
		cout << "No!" << endl;
	}
	cout << endl;

	cout << "Operation * M1 and M3" << endl;
	TMonom res1 = M1 * M3;
	cout << res1;
	cout << endl;

	cout << "Operation + M1 and M3" << endl;
	TMonom res2 = M1 + M3;
	cout << res2;
	cout << endl;

	cout << "Operation - M1 and M3" << endl;
	TMonom res3 = M1 + (-M3);
	cout << res3;
	cout << endl;

	return 0;
}