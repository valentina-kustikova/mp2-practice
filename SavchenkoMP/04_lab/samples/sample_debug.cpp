#include <iostream>
#include "tnode.h"
#include "tlist.h"

using namespace std;

int main() {
	try {
		TList<int> expl;
		TNode<int>* exp;

		expl.InsertLast(1);
		expl.InsertLast(2);
		expl.InsertLast(3);
		exp = expl.Search(1);

		cout << exp->key << endl;
		cout << exp->pNext->key << endl;
		cout << exp->pNext->pNext->key << endl;

		TList<int> list(expl);
		TNode<int>* tmp = list.Search(1);

		cout << tmp->key << endl;
		cout << tmp->pNext->key << endl;
		cout << tmp->pNext->pNext->key << endl;
	}
	catch (...) {
		cout << "Error" << endl;
	}
	
	return 0;
}