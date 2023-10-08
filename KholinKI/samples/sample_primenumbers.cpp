#include <iostream>

#include "tset.h"
int main()
{
	setlocale(LC_ALL, "rus");
    std::cout << "Prime numbers" << std::endl;
	setlocale(LC_ALL, "rus");
	cout << "Решето Эратосфена" << endl;
	cout << "Введите максимально целое число: " << endl;
	size_t n;
	cin >> n;
	TSet s(n + 1);
	for (size_t i = 2; i <= n; i++) {
		s.InsElem(i);
	}
	for (size_t i = 2; i * i <= n; i++) {
		if (s.IsMember(i)) {
			for (size_t k = 2 * i; k <= n; k += i) {
				if (s.IsMember(k)) {
					s.DelElem(k);
				}
			}
		}
	}
	cout << "Простые числа" << s << endl;
    return 0;
}
