#pragma once
#include <string>
#include <cstdlib>
#include  <cctype>
#include <iostream>

using namespace std;

class Monom {

public:
	double coeff; //����������� (����� ���� �������������)
	unsigned int degree; //�������

	Monom() {}//����������� �� ���������
	Monom(double _coeff, unsigned int _degree);// �����������, ����������� ��������

	void SetCoeff(double c) { coeff = c; }//���������� �����������
	void SetDegree(int d) { degree = d; } //���������� �������
	double GetCoeff(void) { return coeff; }//�������� �����������
	unsigned int GetIndex(void) { return degree; }//�������� �������

	//���������� ��������
	const Monom& operator=(const Monom& m);
	Monom& operator+(const Monom& m);
	Monom& operator*(const double& d);
	Monom& operator*(const Monom& m);
	bool operator==(const Monom& m) const;
	bool operator!=(const Monom& m) const;
	bool operator<(const Monom& m) const;

	friend ostream& operator<<(ostream& os, const Monom& m)
	{
		Monom Mon;
		Mon = m;
		int degx = (int)Mon.degree / 100;
		int degy = (int)(Mon.degree / 10 % 10);
		int degz = (int)(Mon.degree % 10);

		if (Mon.coeff == 0)
			cout << "0" << endl;
		else
		{
			if (Mon.coeff == 1 && degx == 0 && degy == 0 && degz == 0)
				cout << Mon.coeff;
			else if (Mon.coeff != 1)
				cout << Mon.coeff;

			if (degx != 0)
			{
				if (degx == 1)
					cout << "x";
				else
					cout << "x^" << degx;
			}

			if (degy != 0)
			{
				if (degy == 1)
					cout << "y";
				else
					cout << "y^" << degy;
			}

			if (degz != 0)
			{
				if (degz == 1)
					cout << "z" << degz;
				else
					cout << "z^";
			}
		}
		return os;
	};
};
