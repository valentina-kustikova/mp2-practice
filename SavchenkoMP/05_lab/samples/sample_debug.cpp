#include <iostream>
#include "tableslib.h"

using namespace std;

int main() {
	try {
		ScanTable<int, std::string> scanTable(10);
		std::string data1 = "data1";
		std::string data2 = "data2";
		scanTable.insert(2, &data1);
		scanTable.insert(1, &data2);

		SortedTable<int, std::string> sortedTable(scanTable);
		cout << sortedTable.get_size() << endl;
		cout << *sortedTable.find(1)->data << endl;
		cout << *sortedTable.find(2)->data << endl;
	}
	catch (string exp) {
		cout << exp << endl;
		return -1;
	}
	
	return 0;
}