#include <iostream>
#include "tnode.h"

using namespace std;

int main() {
	try {
		TNode<int>* tmp = new TNode<int>();
		cout << tmp->key;

		delete tmp;
	}
	catch (...) {
		cout << "Error" << endl;
	}
	
	return 0;
}