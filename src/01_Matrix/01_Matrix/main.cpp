#include <iostream>
#include <locale.h>
#include "Matrix.h"
int main()
{
	int choise, size, startIndex, _size, _startIndex, msize, m_size, t_size, t_startIndex, __size, __startIndex;
	setlocale(LC_ALL, "Russian");
	try
	{
		cout << "������� 1, ���� ������ �������������� �������, ������� 2, ���� ������ �������������� �������" << endl;
		cin >> choise;
		switch (choise)
		{
		case 1:
		{
			cout << "Vector testing!" << endl;
			cout << "������� ������ ������� �������" << endl;
			cin >> size;
			cout << "������ ����������c �������" << endl;
			cin >> startIndex;
			TVector<int> A(size, startIndex);
			cout << "������� ���������� �������" << endl;
			cin >> A;
			cout << "������ A:" << endl;
			cout << A << endl;
			cout << "������� ������ ������� �������" << endl;
			cin >> _size;
			cout << "������� ����������� �������" << endl;
			cin >> _startIndex;
			TVector<int> B(_size, _startIndex);
			cout << "������� ���������� �������" << endl;
			cin >> B;
			cout << "������ B:" << endl;
			cout << B << endl;
			TVector<int> C(A);
			cout << "������ �:" << endl;
			cout << C << endl;

			cout << "A==B: " << (A == B) << endl;
			cout << "A!=B: " << (A != B) << endl;
			cout << "A+5: " << A + 5 << endl;
			cout << "A-5: " << A - 5 << endl;
			cout << "A*5: " << A * 5 << endl;
			cout << "A/5: " << A / 5 << endl;
			cout << "A+B: " << A + B << endl;
			cout << "A-B: " << A - B << endl;
			cout << "A*B: " << A * B << endl;
			cout << "����� ������� A: " << A.Length() << endl;
			cout << "A=B: " << (A = B) << endl;
			cout << "A[0]: " << A[0] << endl;
			break;
		}
		case 2:
		{
			cout << "Matrix testing!" << endl;
			cout << "������� ������ ������ �������" << endl;
			cin >> msize;
			TMatrix<int> C(msize);
			cout << "������� ���������� ������� " << endl;
			cin >> C;
			cout << "������� C:" << endl;
			cout << C;
			cout << "������� ������ ������ �������" << endl;
			cin >> m_size;
			TMatrix<int> D(m_size);
			cout << "������� ���������� �������" << endl;
			cin >> D;
			cout << "������� D:" << endl;
			cout << D;
			cout << "������� ������ ������� ��� �������� �������� ��������� ������� �� ������" << endl;
			cin >> t_size;
			cout << "������ ����������� �������" << endl;
			cin >> t_startIndex;
			TVector<int> E(t_size, t_startIndex);
			cout << "������� ���������� �������" << endl;
			cin >> E;
			cout << "������ E:" << endl;
			cout << E << endl;
			TMatrix<int> F(C);
			cout << "������� F:" << endl;
			cout << F;
			cout << "������� ������ ������� ��� �������������� �����" << endl;
			cin >> __size;
			cout << "������  ����������� ������� ��� �������������� �����" << endl;
			cin >> __startIndex;
			TVector<TVector<int>> G(__size, __startIndex);
			cout << "��������� ������ ��������" << endl;
			for (int i = 0; i < __size; i++)
			{
				G.elements[i] = TVector<int>(__size - i, i);
				cin >> G.elements[i];
			}
			cout << "������� G:" << endl;
			cout << G << endl;
			TMatrix<int> H(G);
			cout << "������� H:" << endl;
			cout << H;

			cout << "C==D: " << (C == D) << endl << endl;
			cout << "C!=D: " << (C != D) << endl << endl;
			cout << "C+5: " << endl << C + 5 << endl;
			cout << "C-5: " << endl << C - 5 << endl;
			cout << "C*5: " << endl << C * 5 << endl;
			cout << "C*E: " << endl << C * E << endl << endl;
			cout << "C+D: " << endl << C + D << endl;
			cout << "C-D: " << endl << C - D << endl;
			C = D;
			cout << "C=D: " << endl << C << endl; // ��������� ������������ �������� ����� � ������ �����, �������� �������� ���������, ���������� ���������� � ������
			break;
		}
		}
	}
	catch (const char* str)
	{
		cout << str << endl;
	}
	system("pause");
}