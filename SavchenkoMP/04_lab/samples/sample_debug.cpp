#include <iostream>
#include "tnode.h"
#include "tlist.h"
#include "tringlist.h"

using namespace std;

int main() {
	try {
		TRingList<int> expl;
		TNode<int>* exp;

		TRingList<int> list(expl);
	}
	catch (...) {
		cout << "Error" << endl;
	}
	
	return 0;
}