#include "TPolynom.h"

int main() {
	cout << "The polynomials P and Q:" << endl << endl;
	TPolynom P("2*x^3*y^3*z+y^2*z^2-7*x");
	TPolynom Q("2*y^3*z^3-5*z^3*x^3+10*y");
	TPolynom U_P("");
	

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

	cout << "Before we start performing operations on polynomials," << endl;
	cout << "create your own polynomial: " << endl;
	cin >> U_P;
	cout << "User polynom: " << endl;
	cout << "U_P(x,y,z) = ";
	cout << U_P;

	TPolynom res1; TPolynom res2;     
	TPolynom res3;  
	TPolynom res4; TPolynom res5;
	TPolynom res6; TPolynom res7;

	cout << endl;
	cout << "Let`s start!" << endl;
	cout << endl;

	cout << "Operation +:" << endl;
	res1 = P + U_P;
	cout << res1;
	cout << endl;

	cout << "Operation -:" << endl;
	res2 = P - Q;
	cout << res2;
	cout << endl;

	cout << "Operation *:" << endl;
	res3 = P * Q;
	cout << res3;
	cout << endl;

	cout << "For your polynom set point which you want calculate value polynom: " << endl;

	double x; double y; double z;
	cout << "x = ";
	cin >> x;
	cout << "y = ";
	cin >> y;
	cout << "z = ";
	cin >> z;

	cout << "U_P(" << x << "," << y << "," << z << ")" << " = " << U_P(x, y, z) << endl;//

	cout << "Time for differentiation!" << endl;
	cout << "Your polynom(x,y,z) = " << U_P;

	cout << "Operation differentiation by x:" << endl;
	res4 = U_P.differentiate_by_x();
	cout << res4;
	cout << endl;

	cout << "Operation differentiation by y:" << endl;
	res6 = U_P.differentiate_by_y();
	cout << res6;
	cout << endl;


	cout << "Operation differentiation by z:" << endl;
	res7 = U_P.differentiate_by_z();
	cout << res7;
	cout << endl;
	return 0;
}