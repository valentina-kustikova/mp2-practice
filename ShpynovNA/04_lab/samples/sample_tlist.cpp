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
		cout << list.GetCurrent()->data << " ";
		list.next();
	}
	cout << endl;
	list.reset();
	try { list.next(); }
	catch(...){}
	cout << "now lets put a new integer after " << list.GetCurrent()->data<<": ";
	int tmp = list.GetCurrent()->data;
	cin >> a;
	list.InsertAfter(tmp, a);
	cout << "got ";
	list.reset();
	while (!list.IsEnded()) {
		cout << list.GetCurrent()->data << " ";
		list.next();
	}
	list.reset();
	list.next();
	cout << "now lets put a new integer before " << list.GetCurrent()->data<<": ";
	tmp = list.GetCurrent()->data;
	cin >> a;
	list.InsertBefore(tmp, a);
	cout << "got ";
	list.reset();
	while (!list.IsEnded()) {
		cout << list.GetCurrent()->data << " ";
		list.next();
	}
	list.reset();
}