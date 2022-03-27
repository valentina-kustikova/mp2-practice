#pragma once
#include "monom.h"
#include <string>
#include <cstdlib>
#include  <cctype>
#include <iostream>

using namespace std;

template <class T>
struct Node //звено циклического списка с головой
{
	T data;
	Node* next;
public:
	Node(); // конструктор по умолчанию
	Node(T val, Node* n);//конструктор, принимающий на вход значения
	~Node() {};//деструктор
	Node(const Node<T>& node2);// конструктор копирования
	bool operator==(const Node<T>& node2) const;//сравнение ==
	bool operator!=(const Node<T>& node2) const { return !(*this == node2); }; //сравнение !=
};

template <class T>
struct List //односвязный линейный список
{
private:
	Node<T>* head; //указатель на голову
	Node<T>* current; // указатель на следующее звено списка
public:
	List(); // конструктор по умолчанию
	List(const List<T>& l1);//конструктор копирования
	~List();//деструктор

	void Clean();//очистить список
	T& GetValue() { return current->data; } //возвращает значения текущего элемента списка
	List<T>& operator=(const List<T>& l1);//присваивание
	void Reset() { current = head; }//указатель на начале списка
	bool IsEnded() const;
	Node<T>* GetNext() { return current = current->next; }//возвращает следующий элемент списка
	void InsertToTail(const T& d); //вставка в конец
	void Insert(const T& d); //вставка в список
	void Delete(const T& d); //удаление звена

	friend std::ostream& operator<<(std::ostream& os, const List<T>& l)
	{
		List<T> list(l);
		list.Reset();
		Node<T>* tmp = list.GetNext();
		while (!list.IsEnded())
		{
			cout << tmp->data;
			tmp = list.GetNext();
			if (!list.IsEnded())
				cout << "+";
		}
		cout << endl;
		return os;
	};
};

template <class T>
Node<T>::Node()
{
	next = NULL;
}

template <class T>
Node<T>::Node(T val, Node* n)
{
	data = val;
	next = n;
}

template <class T>
Node<T>::Node(const Node<T>& node2)
{
	if (this != &node2) 
	{
		data = node2.data;
		next = node2.next;
	}
}

template <class T>
bool Node<T>::operator==(const Node<T>& node2) const
{
	if (data != node2.data)
		return false;
	else return true;
}


template <class T>
List<T>::List()
{
	head = new Node<T>;
	head->next = head;
	current = head;
}

template <class T>
List<T>::List(const List<T>& l1)
{
	if (l1.head->next != l1.head)
	{
		head = new Node<T>;
		current = head;
		Node<T>* tmp2 = l1.head->next;
		while (tmp2 != l1.head)
		{
			current->next = new Node<T>(tmp2->data, tmp2->next);
			current = current->next;
			tmp2 = tmp2->next;
		}
		current->next = head;
	}
	else 
	{
		head = new Node<T>;
		head->next = head;
		current = head;
	}
}

template <class T>
List<T>::~List()
{
	current = head->next;
	Node<T>* tmp2 = current;
	if (head->next != head)
	{
		while (tmp2 != head)
		{
			tmp2 = current->next;
			delete current;
			current = tmp2;
		}
		delete current;
	}
	else
		delete head;
}

template <class T>
bool List<T>::IsEnded() const
{
	if (current == head)
		return true;
	else return false;
}

template <class T>
void List<T>::InsertToTail(const T& d)
{
	current = head;
	if (head->next == head)
		head->next = new Node<T>(d, head);
	else
	{
		while (current->next != head)
		{
			current = current->next;
		}
		current->next = new Node<T>(d, head);
	}
}

template <class T>
void List<T>::Insert(const T& d)
{
	Node<T>* tmp;
	tmp = head;
	current = head->next;
	if (head->next == head)
		head->next = new Node<T>(d, head);
	else
	{
		while (current->data < d)
		{
			tmp = tmp->next;
			current = current->next;
		}
		if (current->data == d)
		{
			current->data = current->data + d;
		}
		else
		{
			tmp->next = new Node<T>(d, current);
		}
	}
}

template <class T>
void List<T>::Delete(const T& d)
{
	Node<T>* prev = head;
	current = head->next;
	if (current != head)
	{
		while ((current != head) && (current->data != d))
		{
			prev = current;
			current = current->next;
		}
		if (current != head)
		{
			prev->next = current->next;
			delete current;
		}
	}
}


template <class T>
List<T>& List<T>::operator=(const List<T>& l1)
{
	if (this != &l1) 
	{
		Clean();
		if (l1.head->next == l1.head) 
		{
			return *this;
		}
		else 
		{
			Node<T>* tmp2 = l1.head->next;
			current = head;
			while (tmp2 != l1.head)
			{
				current->next = new Node<T>(tmp2->data, tmp2->next);
				current = current->next;
				tmp2 = tmp2->next;
			}
			current->next = head;
		}
	}
	return *this;
}

template <class T>
void List<T>::Clean()
{
	current = head->next;
	Node<T>* tmp2 = current;
	if (head->next != head)
	{
		while (!IsEnded())
		{
			tmp2 = GetNext();
			delete current;
			current = tmp2;
		}
		head->next = head;
		current = head;
	}
	else return;
}
