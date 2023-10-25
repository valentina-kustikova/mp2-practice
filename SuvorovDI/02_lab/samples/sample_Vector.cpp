#include "Vector.h"
#include <iostream>

int main() {
	TVector<int> a(10);
	std::cin >> a;
	std::cout << a[4];

	return 0;
}