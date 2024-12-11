// ННГУ, ИИТММ, Курс "Алгоритмы и структуры данных"
//
// Copyright (c) Сысоев А.В.
//
// Тестирование матриц

#include <iostream>
#include "postform.h"
//---------------------------------------------------------------------------

int main() {
	char* st = "(A-C)*T"; 
	int n = strlen(st);
	char* a = new char[n];
	a = getPostform(st,n);
	n = n - getSymb(st, n);
	for (int i = 0; i < n; i++) {
		std::cout << a[i];
	}
	cout << endl;
	map<char, int> s;
	s.insert({ 'A', 2 });
	s.insert({ 'C', 5 });
	s.insert({ 'T', 11 });
	cout << Calculate(a, n, s) << endl;
	return 1;
	
}