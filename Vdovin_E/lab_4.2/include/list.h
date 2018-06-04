#pragma once
#include "node.h"

template <class valtype>
class list
{
	node<valtype> *head; //указатель на голову списка
public:
	list() { head = NULL; } //конструктор по умолчанию
	~list(); //деструктор
	list(const list<valtype> &l); //конструктор копирования

	void insert_to_tail(const valtype &d); //вставка в конец, если таких данных нет
	void elemdelete(const valtype &d); //удаление элемента по данным
	void cleanlist(); //очистка списка

	node<valtype>* search(const valtype &d); //поиск звена по данным

	list<valtype>& operator=(const list<valtype> &l); //оператор присваивания

	friend ostream & operator<<(ostream &out, const list<valtype> &l) //перегрузка оператора вывода
	{
		node<valtype>* t = l.head;
		while (t != NULL)
		{
			out << t->data << endl;
			t = t->next;
		}
		return out;
	}
};

template<class valtype>
inline list<valtype>::~list()
{
	cleanlist();
}

template<class valtype>
inline list<valtype>::list(const list<valtype>& l)
{
	if (this != &l)
	{
		if (l.head != NULL)
		{
			head = new node<valtype>(l.head->data);
			node<valtype> *t = l.head->next;
			node<valtype> *tt = head;
			while (t != NULL)
			{
				tt->next = new node<valtype>(t->data);
				t = t->next;
				tt = tt->next;
			}
		}
		else
			head = NULL;
	}
}

template<class valtype>
inline void list<valtype>::insert_to_tail(const valtype & d)
{
	if (head == NULL)
		head = new node<valtype>(d);
	else
	{
		node<valtype> *t = head;
		bool f = true;
		while ((t->next != NULL) && (f))
		{
			if (t->data == d)
				f = false;
			t = t->next;
		}
		if ((f) && (t->data != d))
		{
			t->next = new node<valtype>(d);
		}
	}
}

template<class valtype>
inline void list<valtype>::elemdelete(const valtype & d)
{
	if (head != NULL)
	{
		if (head->data == d)
		{
			node<valtype> *t = head->next;
			delete head;
			head = t;
		}
		else
		{
			node<valtype> *t = head->next;
			node<valtype> *tt = head;
			while ((t != NULL) && (t->data != d))
			{
				tt = t;
				t = t->next;
			}
			if (t != NULL)
			{
				tt->next = t->next;
				delete t;
			}
		}
	}
}

template<class valtype>
inline void list<valtype>::cleanlist()
{
	node<valtype> *t = head;
	while (t != NULL)
	{
		node<valtype> *tt = t->next;
		delete t;
		t = tt;
	}
	head = NULL;
}

template<class valtype>
inline node<valtype>* list<valtype>::search(const valtype & d)
{
	node<valtype> *t = head;
	while ((t != NULL) && (t->data != d))
		t = t->next;
	if (t == NULL)
		return NULL;
	else
		return t;
}

template<class valtype>
inline list<valtype>& list<valtype>::operator=(const list<valtype>& l)
{
	if (this != &l)
	{
		cleanlist();
		if (l.head != NULL)
		{
			head = new node<valtype>(l.head->data);
			node<valtype> *t = l.head->next;
			node<valtype> *tt = head;
			while (t != NULL)
			{
				tt->next = new node<valtype>(t->data);
				t = t->next;
				tt = tt->next;
			}
		}
		else
			head = NULL;
	}
	return *this;
}