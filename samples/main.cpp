#include "polinom.h"

using namespace std;

void main()
{
	setlocale(LC_ALL, "Russian");
	string s1;
	string s2;
	int q = 2;
	int k;
	while (q == 2)
	{
		cout << "������� ������ �������. ���������� ������������ ������ ���������� x, y, z." << endl;
		cin >> s1;
		Polinom P1(s1);
		cout << "�������� ��������." << endl;
		cout << "1) �������� ���������." << endl;
		cout << "2) ��������� ���������." << endl;
		cout << "3) ��������� ���������." << endl;
		cout << "4) ��������� �������� �� ���������" << endl;
		cin >> k;
		switch (k)
		{
		case 1:
		{
			cout << "������� ������ �������." << endl;
			cin >> s2;
			Polinom P2(s2);
			cout << "���������:" << P1 + P2;
			break;
		}
		case 2:
		{
			cout << "������� ������ �������." << endl;
			cin >> s2;
			Polinom P2(s2);
			cout << "���������:" << P1 - P2;
			break;
		}
		case 3:
		{
			cout << "������� ������ �������." << endl;
			cin >> s2;
			Polinom P2(s2);
			cout << "���������:" << P1 * P2;
			break;
		}
		case 4:
		{
			double d;
			cout << "������� ���������." << endl;
			cin >> d;
			cout << "���������:" << P1 * d;
			break;
		}
		}

		cout << "\n �����? " << endl;
		cout << "1)��. " << endl;
		cout << "2)���. " << endl;
		cin >> q;

	}
}