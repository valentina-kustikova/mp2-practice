#include "tables_manager.h"

int main() {
	try {
		Tables example;
		example.menu();
	}
	catch (char* exp) {
		std::cout << exp << "\n";
	}
	return 0;
}