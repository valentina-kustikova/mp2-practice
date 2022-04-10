
// класс или структура Монома (double коэффициент, целая свернутая степень)
#pragma once
#include <iostream>
struct TData {
	int degx; //Показатели степени при x,y,z
	int degy;
	int degz;
	double coef; //коэффициент при мономе
};


class Node
{
public:
	TData data;
	Node* next;

	Node(double _coef = 0.0, int _degx = 0, int _degy = 0, int _degz = 0, Node* _next = nullptr);
	Node(const Node& monom2);
	Node& operator=(const Node& m)
	{

		data.degx = m.data.degx;
		data.degy = m.data.degy;
		data.degz = m.data.degz;
		data.coef = m.data.coef;
		next = m.next;
		return *this;
	}
	Node& operator=(double scalar)
	{
		data.degx = 0;
		data.degy = 0;
		data.degz = 0;
		data.coef = scalar;
		next = nullptr;
		return *this;
	}
	bool operator==(const Node& m) const;
	bool operator!=(const Node& m) const;
	friend std::ostream& operator<<(std::ostream& os, const Node& m);

};


class List
{
protected:
	Node* head;
public:
	~List();//++
	List();//++
	List(const List& poly);//++
	List& operator=(const List& poly);
	void addFirst(const Node& monom); //Добавление в список перед NULL++
	void addLast(const Node& monom);// Добавление в список перед Head++
	void addNow(const Node& monom, Node& ptr); //Добавление в список после конкретного элемента. Правильное взаимодействие через Итератор.++
	
	void delFirst(); //Удаление первого элемента после head ++
	void delLast(); //Удаление последнего элемента ++
	void delElem(Node& ptr); //Удаление элемента на котором находится итератор (вроде бы,хз, надо оттестить) ++

	class Iterator
	{
	public:
		Node* ptr;
		Iterator() {}
		Iterator(Node* _ptr = nullptr);

		Iterator operator++(int);
		Iterator& operator++();
		Node& operator*();
	};
	Iterator begin();
	Iterator end();

};

