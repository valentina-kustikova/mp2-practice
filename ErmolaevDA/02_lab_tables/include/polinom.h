// класс Полином - упорядоченный односвязный список Мономов
// поддерживает операции Печать, Вставка монома, Удаление монома,
// Поиск монома, Сложение полиномов(слияние упорядоченных списков),
// Умножение полиномов


#include "monom.h"
#include <vector>
#include <string>

class Polinom :
	public List
{
	std::vector<std::string> Lexs;

	void parser(const std::string& input);
	bool check_vars() const;
	bool check_points() const;
	bool isCorrect() const;
	void converter();

public:
	Polinom& operator+=(const Node& monom);
	Polinom& operator-=(const Node& monom);
	Polinom operator+(const Node& monom) const;
	Polinom operator-(const Node& monom) const;
	Polinom operator*(const Node& monom) const;
	Polinom& operator*=(const Node& monom);
	Polinom& operator+=(double scalar);
	Polinom& operator-=(double scalar);
	Polinom operator+(double scalar) const;
	Polinom operator-(double scalar) const;
	Polinom operator*(double scalar) const;
	Polinom& operator*=(double scalar);
	Polinom& operator+=(const Polinom& poly);
	Polinom& operator-=(const Polinom& poly);
	Polinom operator+(const Polinom& poly) const;
	Polinom operator-(const Polinom& poly) const;
	Polinom operator*(const Polinom& poly) const;
	double operator()(double x, double y, double z) const;
	bool operator==(const Polinom& poly) const;
	friend std::ostream& operator<< (std::ostream& out, const Polinom& polinom);
	//Отдельные функции только для полиномов
	void podobnyi();//++
	void differents(int t);//++
	void fulldiff();//++
	void str_to_poly(const std::string& _input);
	void showList() const; //Чистый вывод++
	void showList2() const; //Вывод с косяками++
	void showList3() const;//++
};

