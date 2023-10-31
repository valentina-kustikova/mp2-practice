#include <iostream>
#include "TVector.h"

using namespace std;

int main() {
	TVector<int> vec1(5), vec2(5);

	cout << "Enter vec1 (size = 5): ";
	cin >> vec1;
	cout << "Enter vec2 (size = 5): ";
	cin >> vec2;

	// vector - vector operations
	TVector<int> vec_sum(5), vec_dif(5);
	int vec_mul;
	cout << "\nvector-vector operations";
	vec_sum = vec1 + vec2;
	vec_dif = vec1 - vec2;
	vec_mul = vec1 * vec2;
	cout << "\nvec1 + vec2 = " << vec_sum << "\nvec1 - vec2 = " << vec_dif << "\nvec1 * vec2 = " << vec_mul << endl;

	// vector - scalar operations
	cout << "\nvector-scalar operations";
	cout << "\nvec1 + 15 = " << vec1 + 15 << "\nvec2 - 10 = " << vec2 - 10 << "\nvec1 * 5 = " << vec1 * 5 << endl;

	// bool operations
	cout << "\nbool operations";
	cout << "\nvec1 == vec2? - " << (vec1 == vec2) << "\nvec1 != vec2? - " << (vec1 != vec2) << endl;
	return 0;
}