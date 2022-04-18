#pragma once

#include "list.h"
#include"monom.h"
#include <algorithm>
#include <iostream>
#include <string>

class Polinom
{
private:
	List<Monom> list;//������ �������
	List<Monom> similar(List<Monom>& m);//���������� ��������
public:

	Polinom(const Polinom& p); //����������� �����������
	Polinom(const string s = "");//����������� �������������� ������ � �������

	Polinom operator+(const Polinom& p) const; //�������� ���������
	Polinom operator*(const Polinom& p) const; //��������� ���������
	Polinom operator*(const double k) const; //��������� �������� �� ���������
	Polinom operator-(const Polinom& p) const;// ��������� ���������
	Polinom operator-() const;//������� �����
	friend Polinom operator*(const double k, const Polinom& p); //��������� �������� �� ��������� � ������ �������

	const Polinom& operator=(const Polinom& p);//������������
	bool operator==(const Polinom& p) const;//==
	bool operator!=(const Polinom& p) const;//!=
	double operator() (double x, double y, double z);//()

	friend ostream& operator<<(ostream& out, const Polinom& pol);//�����
	friend istream& operator>>(istream& in, Polinom& p);//����
};
