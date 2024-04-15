#include "tlist.h"
#include <iostream>

using namespace std;

void main() {
	TList<int> list;
	cout << "enter some integers:" << endl;
	cout << "amount:";
	int i;
	cin >> i;
	int a;
	for (int n = 0; n < i; n++) {
		cin >> a;
		list.InsertLast(a);
	}
	cout << "got ";
	list.reset();
	while (!list.IsEnded()) {
		cout << list.pCurrent->data << " ";
		list.next();
	}
	cout << endl;
	list.reset();
	try { list.next(); }
	catch(...){}
	cout << "now lets put a new integer after " << list.pCurrent->data<<": ";
	int tmp = list.pCurrent->data;
	cin >> a;
	list.InsertAfter(tmp, a);
	cout << "got ";
	list.reset();
	while (!list.IsEnded()) {
		cout << list.pCurrent->data << " ";
		list.next();
	}
	list.reset();
	list.next();
	cout << "now lets put a new integer before " << list.pCurrent->data<<": ";
	tmp = list.pCurrent->data;
	cin >> a;
	list.InsertBefore(tmp, a);
	cout << "got ";
	list.reset();
	while (!list.IsEnded()) {
		cout << list.pCurrent->data << " ";
		list.next();
	}
	list.reset();
}