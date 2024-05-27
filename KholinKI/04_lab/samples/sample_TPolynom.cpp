#include "TPolynom.h"

int main() {
	cout << "The polynomials P and Q:" << endl << endl;
	TPolynom P("2*x^3*y^3*z+y^2*z^2-7*x");
	TPolynom Q("2*y^3*z^3-5*z^3*x^3+10*y");
	

	cout << "P(x,y,z) = " << P << endl;
	cout << "Q(x,y,z) = " << Q << endl;

	cout << "Getting copy polynomial P..." << endl;
	TPolynom P_copy(P);

	cout << "P_copy(x,y,z) = " << P_copy << endl << endl;

	cout << "Check polynomials P and Q on equality" << endl << endl;
	if (P == Q) {
		cout << "P equal Q!" << endl;
	}
	else {
		cout << "P not equal Q!" << endl;
	}

	cout << endl;

	cout << "Check polynomials P and P_copy on equality" << endl << endl;
	if (P == P_copy) {
		cout << "P equal P_copy!" << endl;
	}
	else {
		cout << "P not equal P_copy!" << endl;
	}

	cout << endl;
	cout << endl;

	TPolynom res1; TPolynom res2;
	TPolynom res3;  
	TPolynom res4; TPolynom res5;
	TPolynom res6; TPolynom res7;

	cout << endl;
	cout << "Let`s start!" << endl;
	cout << endl;

	cout << "Operation +:" << endl;
	res1 = P + Q;
	cout << res1;
	cout << endl;

	cout << "Operation -:" << endl;
	res2 = P + (- Q);
	cout << res2;
	cout << endl;

	cout << "Operation *:" << endl;
	res3 = P * Q;
	cout << res3;
	cout << endl;


	double x = 1;
	double y = 2;
	double z = 0;
	cout << "Value of polynom Q in point (1.25, 2.5, 0) equally " << Q(1, 2, 0) << endl;
	cout << endl;


	cout << "Operation differentiation by x:" << endl;
	res4 = P.differentiate_by_x();
	cout << res4;
	cout << endl;

	cout << "Operation differentiation by y:" << endl;
	res6 = Q.differentiate_by_y();
	cout << res6;
	cout << endl;


	cout << "Operation differentiation by z:" << endl;
	res7 = Q.differentiate_by_z();
	cout << res7;
	cout << endl;
	return 0;
}