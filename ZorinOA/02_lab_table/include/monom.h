#pragma once
#include <iostream>

struct Monom
{
	int deg;
	double cf;
	Monom* next;

	Monom(double _cf = 0.0, int _deg = 0, Monom* _next = nullptr)
	{
		if (_deg < 0 || _deg > 999)
			throw std::runtime_error("Wrong monom's degree!");

		deg = _deg;
		cf = _cf;
		next = _next;
	}
	Monom(const Monom& monom2)
	{
		deg = monom2.deg;
		cf = monom2.cf;
		next = monom2.next;
	}
	Monom& operator=(double scalar)
	{
		deg = 0;
		cf = scalar;
		next = nullptr;

		return *this;
	}
	bool operator==(const Monom& m) const
	{
		return (abs(cf) - abs(m.cf) < 1e-10) && (deg == m.deg);
	}
	bool operator!=(const Monom& m) const
	{
		return (abs(cf) - abs(m.cf) > 1e-10) || (deg != m.deg);
	}
	friend std::ostream& operator<<(std::ostream& os, const Monom& m)
	{
		double cf = std::abs(m.cf);
		if (cf > 1e-10)
		{
			//std::cout.setf(std::ios::fixed);
			//std::cout.precision(3);
			int deg_x = m.deg / 100;
			int deg_y = m.deg % 100 / 10;
			int deg_z = m.deg % 10;

			if (m.cf > 0)
				os << "+ " << cf;
			else
				os << "- " << cf;

			if (deg_x != 0)
			{
				if (deg_x == 1)
					os << "x";
				else
					os << "x^" << deg_x;
			}
			if (deg_y != 0)
			{
				if (deg_y == 1)
					os << "y";
				else
					os << "y^" << deg_y;
			}
			if (deg_z != 0)
			{
				if (deg_z == 1)
					os << "z";
				else
					os << "z^" << deg_z;
			}
		}
		return os;
	}
};

class MonomList
{
protected:
	Monom* Tail;
public:
	MonomList();
	MonomList(const MonomList& poly);
	MonomList& operator=(const MonomList& poly);
	~MonomList();
	void Insert(const Monom& monom);

	class Iterator
	{
		Monom* ptr;
	public:
		Iterator(Monom* _ptr = nullptr);
		Iterator& operator++();
		Monom& operator*();
	};
	Iterator begin();
};
