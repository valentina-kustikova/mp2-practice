#include <iostream>
#include "tableslib.h"

using namespace std;

int main() {
	try {
		int size = 3;
		ScanTable<int, string> st(3);

		int key = 1;
		string data = "a";
		st.Insert(key, &data);

		TabRecord<int, string>* find = st.Find(2);

		cout << (find == nullptr) << endl;
	}
	catch (string exp) {
		cout << exp << endl;
		//cout << "Error" << endl;
	}
	
	return 0;
}