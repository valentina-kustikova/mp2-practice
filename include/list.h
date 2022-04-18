#pragma once
#include "node.h"
#include <iostream>

using namespace std;

template<class T>
class List
{
protected:

	Node<T>* head;//указатель на голову
	Node<T>* curr;//указатель на текущее звено списка 

public:

	List(); //конструктор по умолчанию
	List(const List<T>& l); //конструктор копирования
	~List(); //деструктор

	Node<T>* Search(const T& elem);//поиск элемента
	void InsertToHead(const T& elem); //вставка в начало
	void InsertInOrder(const T& elem);//вставка в упорядоченный список
	void InsertToTail(const T& elem); //вставка в конец
	void InsertAfter(Node<T>* temp1, const T& elem);//вставка после элемента
	void Delete(const T& elem); //удаление звена
	void Clean(); //очистить список

	void Reset() { curr = head->next; } //переход в начало списка
	void Next() { curr = curr->next; } //переход к следующему звену
	bool isEnd() const { return curr == head; }//проверка на конец списка
	bool isEmpty() const { return (head->next == head); }//проверка на пустоту
	T& GetCurr() const { return curr->data; } //получение данных 
	T Head() { return head->next->data; };//данные начала списка
	Node<T>* GetHead() { return head->next; }; //получение начала списка

	const List<T>& operator=(const List<T>& l); //присваивание
	bool operator==(const List<T>& l) const; //операция ==
	bool operator!=(const List<T>& l) const; //операция !=

	friend std::ostream& operator<<(std::ostream& os, const List<T>& l)
	{
		List<T> list(l);
		list.Reset();
		Node<T>* tmp = list.Next();
		while (!list.isEnd())
		{
			cout << tmp->data;
			tmp = list.Next();
			if (!list.isEnd())
				cout << "+";
		}
		cout << endl;
		return os;
	};
};

template <class T>
List<T>::List()
{
	head = new Node<T>;
	head->next = head;
	curr = head;
}

template <class T>
List<T>::List(const List<T>& l)
{
	head = new Node<T>;
	Node<T>* A = l.head;
	Node<T>* B = head;
	if (A->next == l.head)
	{
		head->next = head;
		return;
	}
	while (A->next != l.head)
	{
		A = A->next;
		B->next = new Node<T>(A->data);
		B = B->next;
	}
	B->next = head;
	curr = head->next;
}

template <class T>
List<T>::~List()
{
	Clean();
	delete head;
}

template <class T>
Node<T>* List<T>::Search(const T& elem)
{
	Node<T>* tmp = head->next;
	while (tmp != nullptr)
	{
		if (tmp->data == elem)
		{
			return tmp;
		}
		tmp = tmp->next;
	}
	return nullptr;
}

template <class T>
void List<T>::InsertToHead(const T& elem)
{
	Node<T>* node = new Node<T>(elem, head->next);
	head->next = node;
}

template <class T>
void List<T>::InsertInOrder(const T& elem)
{
	if (isEmpty())
	{
		head->next = new Node<T>(elem);
		head->next->next = head;
	}
	else
	{
		Node<T>* tmp = new Node<T>(elem);
		Node<T>* curr = head;

		while ((*(curr->next) < *tmp) && curr->next != head)
			curr = curr->next;
		Node<T>* tmp2 = curr->next;
		curr->next = tmp;
		curr->next->next = tmp2;
	}
}

template<class T>
inline void List<T>::InsertToTail(const T& elem)
{
	Reset();
	while (curr->next != head)
	{
		Next();
	}
	Node<T>* tmp = curr->next;
	curr->next = new Node<T>(elem);
	curr->next->next = tmp;
}

template <class T>
void List<T>::InsertAfter(Node<T>* temp1, const T& elem)
{
	if (head == NULL)
		throw "List is empty";
	else
	{
		Node<T>* temp = temp1->next;
		temp1->next = new Node<T>(elem, temp);
	}
}

template <class T>
void List<T>::Delete(const T& elem)
{
	Node<T>* del;
	Node<T>* tmp = head->next;
	if (tmp != nullptr)
	{
		if (tmp->data == elem)
		{
			del = tmp->next;
			delete head->next;
			head->next = del;
		}
		else
		{
			while (tmp->next)
			{
				if (tmp->next->data == elem)
				{
					del = tmp->next;
					break;
				}
				tmp = tmp->next;
			}
			if (tmp->next)
			{
				tmp->next = del->next;
				delete del;
			}
		}
	}
}

template <class T>
void List<T>::Clean()
{
	Node<T>* curr = head->next;
	while (curr != head)
	{
		Node<T>* tmp = curr->next;
		delete curr;
		curr = tmp;
	}
	head->next = head;
}

template <class T>
const List<T>& List<T>::operator=(const List<T>& l)
{
	Clean();
	Node<T>* tmp = l.head;
	Node<T>* tmp2 = head;
	while (tmp->next != l.head)
	{
		tmp = tmp->next;
		tmp2->next = new Node<T>(tmp->data);
		tmp2 = tmp2->next;
	}
	tmp2->next = head;
	curr = head->next;
	return *this;
}

template<class T>
bool List<T>::operator==(const List<T>& l) const
{
	bool k = true;
	if (this != &l)
	{
		Node<T>* tmp = l.head->next;
		Node<T>* tmp2 = head->next;
		while (tmp->data == tmp2->data && tmp2 != head && tmp != l.head)
		{
			tmp = tmp->next;
			tmp2 = tmp2->next;
		}
		if (tmp != l.head || tmp2 != head)
			k = false;
	}
	return k;
}

template<class T>
inline bool List<T>::operator!=(const List<T>& l) const
{
	return !(*this == l);
}
