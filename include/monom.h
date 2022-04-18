#pragma once

using namespace std;

class Monom
{
public:
	double coeff;//����������� ����� �������
	int degree;//��������� �������

	Monom(const double c = 0.0, const int d = 0); //����������� � �����������
	Monom(const Monom& m);//����������� �����������

	Monom& operator+(const Monom& m); //+
	Monom& operator*(const double& d); //*const
	Monom& operator*(const Monom& m); //*
	bool operator<(const Monom& m)const; //<
	bool operator>(const Monom& m)const;  //>
	const Monom& operator=(const Monom& m); //������������
	bool operator==(const Monom& m)const;//==
	bool operator!=(const Monom& m)const;//!=
};
