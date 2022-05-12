#pragma once

#include "list.h"
#include "headlist.h"
#include"monom.h"
#include <algorithm>
#include <iostream>
#include <string>

class Polynom
{
private:
	List<Monom> list;//������ �������
	List<Monom> similar(List<Monom>& m);//���������� ��������
public:

	Polynom(const Polynom& p); //����������� �����������
	Polynom(const string s = "");//����������� �������������� ������ � �������

	Polynom operator+(const Polynom& p) const; //�������� ���������
	Polynom operator*(const Polynom& p) const; //��������� ���������
	Polynom operator*(const double k) const; //��������� �������� �� ���������
	Polynom operator-(const Polynom& p) const;// ��������� ���������
	Polynom operator-() const;//������� �����
	friend Polynom operator*(const double k, const Polynom& p); //��������� �������� �� ��������� � ������ �������

	const Polynom& operator=(const Polynom& p);//������������
	bool operator==(const Polynom& p) const;//==
	bool operator!=(const Polynom& p) const;//!=
	double operator() (double x, double y, double z);//()

	friend ostream& operator<<(ostream& out, const Polynom& pol);//�����
	friend istream& operator>>(istream& in, Polynom& p);//����
};