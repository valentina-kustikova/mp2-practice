#include <iostream>
#include "tset.h"

using namespace std;

int main()
{
    cout << "Prime numbers" <<endl;

	int n, m;
	cout << "Enter the maximum integer: ";
	cin >> n;
	TSet s(n + 1);
	for (m = 2; m <= n; m++)
		s.InsElem(m); // заполнение 
	for (m = 2; m * m <= n; m++) // проверка до sqrt(n) и удаление кратных
		if (s.IsMember(m))
			for (int k = 2 * m; k <= n; k += m)
				if (s.IsMember(k))
					s.DelElem(k);
	// оставшиеся элементы - простые числа
	for (int i = 0; i <= n; i++)
		if (s.IsMember(i))
			cout << i << ' ';
    return 0;
}
