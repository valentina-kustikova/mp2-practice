#include "scan_table.h"
#include "sorted_table.h"
#include "array_hash_table.h"
#include "tpolynom.h"

#include <iostream>

using namespace std;

int main() {
	TPolynom p("x*y*z");
	ScanTable <TPolynom, string> A(5);
	return 0;
}
