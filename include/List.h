#pragma once
#include <iostream>
#include "Node.h"
using namespace std;


template<typename Tkey>
class List {
private:
	Node<Tkey>*root;//указатель на первый элемент списка
public:
	List();//конструктор по умолчанию
	List(const List&);//конструктор копирования
	~List();//деструктор
	void insertend(Tkey key);//вставка в конец списка
	void insertbegin(Tkey key);//вставка в начало списка
	void remove(Tkey key);//удаление элемента
	Node<Tkey>* search(Tkey key);//поиск элемента
	int Size()const;//кол-во элементов списка
	Node<Tkey>* GetRoot();//получить ссылку на первый элемент списка
};
template <typename Tkey>
List<Tkey>::List()
{
	root = nullptr;
};

template <typename Tkey>
List<Tkey>::~List()
{
	delete root;
};

template <typename Tkey>
void List<Tkey>::insertbegin(Tkey key)
{
	Node<Tkey>*nNode = new Node<Tkey>;
	nNode->Key = key;
	nNode->pNext = root;
	root = nNode;
};
template <typename Tkey>
void List<Tkey>::insertend(Tkey key)
{
	if (root == nullptr)
	{
		insertbegin(key);
		return;
	}
	Node*tmp = root;
	while (tmp->pNext != nullptr)
	{
		tmp = tmp->pNext;
	}
	tmp->pNext = new Node<Tkey>;
	tmp->pNext->key = key;
	tmp->pNext->pNext = nullptr;
};

template <typename Tkey>
void List<Tkey>::remove(Tkey key)
{
	if (root == nullptr) return;
	Node<Tkey>*node = root;
	if (root->Key == key)
	{
		root = root->pNext;
		delete node;
		return;
	}
	while ((node->pNext != nullptr) && (node->pNext->Key != key))
	{
		node = node->pNext;
	}

	if (node->pNext == nullptr)
	{
		throw "Element not found";
	}
	Node<Tkey>*node1 = node->pNext;
	node->pNext = node1->pNext;
	delete node1;

};
template <typename Tkey>
Node<Tkey>* List<Tkey>::search(Tkey key)
{
	if (root == nullptr) return;
	Node<Tkey>*node = root;
	while ((node->pNext != nullptr) && (node->pNext->key != key))
	{
		node = node->pNext;
	}
	if (node->pNext == nullptr)
	{
		throw "Element not found";
	}

	return node->pNext;
};

template <typename Tkey>
Node<Tkey>* List<Tkey>::GetRoot()
{
	return root;
};

template <typename Tkey>
int List<Tkey>::Size()const
{
	Node<Tkey>*node = root;
	int count = 0;
	while (node != nullptr)
	{
		node = node->pNext;
		count++;
	}
	return count;
};

template <typename Tkey>
List<Tkey>::List(const List& a)
{
	root = new Node<Tkey>;
	Node<Tkey>*copy = root;//указатель для элементов нового списка
	Node<Tkey>*node = a->GetRoot();//указатель для элементов старого списка
	while (node->pNext != nullptr)
	{
		copy->Key = node->Key;
		copy->pNext = new Node<Tkey>;
		copy = copy->pNext;
		node = node->pNext;
	}
	copy->Key = node->Key;
	copy->pNext = new Node<Tkey>;
	copy->pNext = nullptr;
};
