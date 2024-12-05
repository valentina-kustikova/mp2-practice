// ННГУ, ИИТММ, Курс "Алгоритмы и структуры данных"
//
// Copyright (c) Сысоев А.В.
//
// Тестирование матриц

#include <iostream>
#include "postform.h"
//---------------------------------------------------------------------------

int main() {
	char* a = new char[9];
	a = getPostform("A+B*(C-D)", 9);
	for (int i = 0; i < 9; i++) {
		std::cout << a[i];
	}


	return 1;
}