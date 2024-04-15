#include <iostream>
#include <string>
#include <vector>
#include "tnode.h"
#include "tlist.h"
#include "tringlist.h"
#include "tmonom.h"
#include "tpolynom.h"
#include "tableslib.h"

using namespace std;

int main() {
	try {
		int size = 3;
		ScanTable<int, string> st(3);

		/*cout << st.IsFull() << endl;
		cout << st.IsEmpty() << endl;
		cout << st.IsTabEnded() << endl;
		cout << st.Reset() << endl;
		cout << st.Next() << endl;
		cout << st.GetDataCount() << endl;
		cout << st.GetMaxSize() << endl;*/
		//cout << st.GetKey() << endl;
		//cout << st.GetData() << endl;
	}
	catch (string exp) {
		cout << exp << endl;
		//cout << "Error" << endl;
	}
	
	return 0;
}