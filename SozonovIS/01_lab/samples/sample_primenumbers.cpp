#include "tset.h"
#include <iostream>

using namespace std;

int main() {
	size_t n;
	cout << "Enter the maximum integer: ";	
	cin >> n;
	cout << endl;

	TSet s(n + 1);
	// заполнение
	for (size_t i = 2; i <= n; i++)
		s.InsElem(i);
	// проверка до sqrt(n) и удаление кратных
	for (size_t i = 2; i * i <= n; i++)
		// если i в s, удаление кратных
		if (s.IsMember(i))
			for (size_t k = 2 * i; k <= n; k += i)
				if (s.IsMember(k))
					s.DelElem(k);
	// оставшиеся в s элементы - простые числа
	cout << "Prime numbers: " << s << endl;
	return 0;
}
