// ННГУ, ИИТММ, Курс "Алгоритмы и структуры данных"
//
// Copyright (c) Сысоев А.В.
//
// Тестирование матриц

#include <iostream>
#include "postform.h"
//---------------------------------------------------------------------------

int main() {
	setlocale(LC_ALL, "Russian");
	char* st = "(A-C)*T"; 
	cout << "Обычная форма: " << st << endl;
	int n = strlen(st);
	string a;
	//char* a = new char[n];
	a = getPostform(st,n);
	cout << "Постфиксная форма: " << a << endl;;
	cout <<"\n" << endl;
	map<char, int> s;
	s.insert({ 'A', 2 });
	s.insert({ 'C', 5 });
	s.insert({ 'T', 11 });
	cout <<"Ответ: "<< Calculate(a, strlen(a.c_str()), s) << endl;
	
	/*
	string st = "(A-C)*T";
	string a;
	//a = getPostform1(st, sizeof(st));
	cout << getPostform1(st, sizeof(st)) << endl;
	return 1;
	*/
	
}