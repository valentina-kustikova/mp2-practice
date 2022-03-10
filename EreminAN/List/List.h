#ifndef __AISD_LIST__
#define __AISD_LIST__

#include <iostream>
using namespace std;



template<typename T>
struct Node
{
public:
	T data;
	Node<T>* next;

	Node(T d = 0, Node<T>* n = nullptr)
	{
		data = d; next = n;
	}
	Node(const Node<T>& node2)
	{
		data = node2.data; next = node2.next;
	}
	bool operator==(const Node<T>& node2) const
	{
		return (data == node2.data) && (next == node2.next);
	}
};
template<typename T>
class List
{
	Node<T>* head;
	Node<T>* first;
public:
	List(const T& d);
	List(const List& list2);
	List& operator=(const List& list2);
	~List();
	bool isEmpty() const { return (first == nullptr); }
	T ViewHead() { return first->data; }

	void InsertToHead(const T& d);  // вставить элемент d первым
	void InsertToTail(const T& d); // вставить элемент d последним
	void InsertAfter(Node<T>* node, const T& d); // вставить элемент d после звена node
	void Delete(const T& d);      // удалить звено со значением data = d
	Node<T>* Search(const T& d); // найти указатель на звено со значением data = d
	void Clean();               // удалить все звенья
	int GetSize() const;       // узнать число звеньев в списке
	Node<T>* GetHead() const; // получить указатель на первое звено списка
	friend ostream& operator<<(ostream& os, const List<T>& l);

	Node<T>* returnFictitiousNode() { return head }//для проверки, что фиктивное звено действительно есть и оно такое, какое было создано. 
};

template<typename T>
ostream& operator<<(ostream& os, const List<T>& l)
{
	Node* tmp = l.first;
	while (tmp)
	{
		cout << tmp->data << ' ';
		tmp = tmp->next;
	}
	return os;
}

template<typename T>
List<T>::List(const T& d)
{
	head = new Node<T>(d, nullptr);
	first = nullptr;
}

template<typename T>
List<T>::List(const List& list2)
{
	if (!list2.isEmpty())
	{
		head = new Node<T>(list2.head->data, list2.head->next);
		first = new Node<T>(list2.first->data, list2.first->next);
		Node<T>* tmp1 = first;
		Node<T>* tmp2 = list2.first->next;

		while (tmp2 != nullptr)
		{
			tmp1->next = new Node<T>(tmp2->data);
			tmp1 = tmp1->next;
			tmp2 = tmp2->next;
		}
	}
	else
	{
		head = new Node<T>(list2.head->data, list2.head->next);
		first = nullptr;
	}
}

template<typename T>
List<T>& List<T>::operator=(const List& list2)
{
	if (this != &list2)
	{
		Node<T>* p = first, * q = first;
		while (q != nullptr)
		{
			q = p->next;
			delete p;
			p = q;
		}

		if (list2.isEmpty())
			first = nullptr;
		else
		{
			first = new Node<T>
				(list2.first->data);
			p = first;
			q = list2.first->next;
			while (q != nullptr)
			{
				p->next = new Node<T>(q->data);
				p = p->next;
				q = q->next;
			}
		}
	}

	return *this;
}

template<typename T>
List<T>::~List()
{
	Node<T>* tmp1, * tmp2;
	tmp1 = first;
	tmp2 = tmp1;
	while (tmp2 != nullptr)
	{
		tmp2 = tmp1->next;
		delete tmp1;
		tmp1 = tmp2;
	}
	delete head;
}

template<typename T>
void List<T>::InsertToHead(const T& d)// вставить элемент d первым
{
	if (isEmpty())
	{
		first = new Node<T>(d, nullptr);
		head->next = first;
	}
	else
	{
		first = new Node<T>(d, first);
	}
}

template<typename T>
void List<T>::InsertToTail(const T& d)// вставить элемент d последним
{
	if (isEmpty())
	{
		first = new Node<T>(d, nullptr);
		head->next = first;
	}
	else
	{
		Node<T>* p = new Node<T>(d, nullptr);
		Node<T>* tmp = first;
		while (tmp->next != nullptr)
		{
			tmp = tmp->next;
		}
		tmp->next = p;
	}
}

template<typename T>
void List<T>::InsertAfter(Node<T>* _node, const T& d)// вставить элемент d после звена node
{
	if (!isEmpty())
	{
		if (_node != nullptr)
		{
			Node<T>* temp = _node->next;
			_node->next = new Node<T>(d, temp);
		}
	}
	else
		throw "Error";
}

template<typename T>
void List<T>::Delete(const T& d)// удалить звено со значением data = d
{
	Node<T>* del;
	Node<T>* tmp = first;
	if (first != nullptr)
	{
		if (first->data == d)
		{
			del = tmp->next;
			delete first;
			first = del;
		}
		else
		{
			while (tmp->next)
			{
				if (tmp->next->data == d)
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

template<typename T>
Node<T>* List<T>::Search(const T& d)// найти указатель на звено со значением data = d
{
	Node<T>* tmp = first;
	while (tmp != nullptr)
	{
		if (tmp->data == d)
		{
			return tmp;
		}
		tmp = tmp->next;
	}
	return nullptr;
}

template<typename T>
void List<T>::Clean()// удалить все звенья
{
	Node<T>* tmp;
	if (isEmpty())
		return;

	while (first->next != nullptr)
	{
		tmp = first->next;
		first->next = tmp->next; // head->next->next;
		delete tmp;
	}
	delete first;
	first = nullptr;
}

template<typename T>
int List<T>::GetSize() const// узнать число звеньев в списке
{
	int k = 0;
	Node<T>* tmp = first;
	while (tmp != nullptr)
	{
		k++;
		tmp = tmp->next;
	}
	return k;
}

template<typename T>
Node<T>* List<T>::GetHead() const// получить указатель на первое звено списка
{
	return first;
}


















//template<typename T>
//class List
//{
//	Node<T>* head;
//public:
//	List() { head = nullptr; };
//	List(const List& list2);
//	List& operator=(const List& list2);
//	~List();
//	bool isEmpty() const { return (head == nullptr); }
//	T ViewHead() { return head->data; }
//
//	void InsertToHead(const T& d);  // вставить элемент d первым
//	void InsertToTail(const T& d); // вставить элемент d последним
//	void InsertAfter(Node<T>* node, const T& d); // вставить элемент d после звена node
//	void Delete(const T& d);      // удалить звено со значением data = d
//	Node<T>* Search(const T& d); // найти указатель на звено со значением data = d
//	void Clean();               // удалить все звенья
//	int GetSize() const;       // узнать число звеньев в списке
//	Node<T>* GetHead() const; // получить указатель на первое звено списка
//	friend ostream& operator<<(ostream& os, const List<T>& l);
//
//};
//
//template<typename T>
//ostream& operator<<(ostream& os, const List<T>& l)
//{
//	Node* tmp = l.head;
//	while (tmp)
//	{
//		cout << tmp->data << ' ';
//		tmp = tmp->next;
//	}
//	return os;
//}
//
//template<typename T>
//List<T>::List(const List& list2)
//{
//	if (!list2.isEmpty())
//	{
//		head = new Node<T>(list2.head->data, list2.head->next);
//		Node<T>* tmp1 = head;
//		Node<T>* tmp2 = list2.head->next;
//
//		while (tmp2 != nullptr)
//		{
//			tmp1->next = new Node<T>(tmp2->data);
//			tmp1 = tmp1->next;
//			tmp2 = tmp2->next;
//		}
//	}
//	else
//		head = nullptr;
//}
//
//template<typename T>
//List<T>& List<T>::operator=(const List& list2)
//{
//	if (this != &list2)
//	{
//		Node<T>* p = head, * q = head;
//		while (q != nullptr)
//		{
//			q = p->next;
//			delete p;
//			p = q;
//		}
//
//		if (list2.isEmpty())
//			head = nullptr;
//		else
//		{
//			head = new Node<T>
//				(list2.head->data);
//			p = head;
//			q = list2.head->next;
//			while (q != nullptr)
//			{
//				p->next = new Node<T>(q->data);
//				p = p->next;
//				q = q->next;
//			}
//		}
//	}
//
//	return *this;
//}
//
//template<typename T>
//List<T>::~List()
//{
//	Node<T>* tmp1, * tmp2;
//	tmp1 = head;
//	tmp2 = tmp1;
//	while (tmp2 != nullptr)
//	{
//		tmp2 = tmp1->next;
//		delete tmp1;
//		tmp1 = tmp2;
//	}
//}
//
//template<typename T>
//void List<T>::InsertToHead(const T& d)// вставить элемент d первым
//{
//	if (isEmpty())
//	{
//		head = new Node<T>(d, nullptr);
//	}
//	else
//	{
//		head = new Node<T>(d, head);
//	}
//}
//
//template<typename T>
//void List<T>::InsertToTail(const T& d)// вставить элемент d последним
//{
//	if (isEmpty())
//	{
//		head = new Node<T>(d, nullptr);
//	}
//	else
//	{
//		Node<T>* p = new Node<T>(d, nullptr);
//		Node<T>* tmp = head;
//		while (tmp->next != nullptr)
//		{
//			tmp = tmp->next;
//		}
//		tmp->next = p;
//	}
//}
//
//template<typename T>
//void List<T>::InsertAfter(Node<T>* _node, const T& d)// вставить элемент d после звена node
//{
//	if (!isEmpty())
//	{
//		if (_node != nullptr)
//		{
//			Node<T>* temp = _node->next;
//			_node->next = new Node<T>(d, temp);
//		}
//	}
//	else
//		throw "Error";
//}
//
//template<typename T>
//void List<T>::Delete(const T& d)// удалить звено со значением data = d
//{
//	Node<T>* del;
//	Node<T>* tmp = head;
//	if (head != nullptr)
//	{
//		if (head->data == d)
//		{
//			del = tmp->next;
//			delete head;
//			head = del;
//		}
//		else
//		{
//			while (tmp->next)
//			{
//				if (tmp->next->data == d)
//				{
//					del = tmp->next;
//					break;
//				}
//				tmp = tmp->next;
//			}
//			if (tmp->next)
//			{
//				tmp->next = del->next;
//				delete del;
//			}
//		}
//	}
//}
//
//template<typename T>
//Node<T>* List<T>::Search(const T& d)// найти указатель на звено со значением data = d
//{
//	Node<T>* tmp = head;
//	while (tmp != nullptr)
//	{
//		if (tmp->data == d)
//		{
//			return tmp;
//		}
//		tmp = tmp->next;
//	}
//	return nullptr;
//}
//
//template<typename T>
//void List<T>::Clean()// удалить все звенья
//{
//	Node<T>* tmp;
//	if (isEmpty())
//		return;
//
//	while (head->next != nullptr)
//	{
//		tmp = head->next;
//		head->next = tmp->next; // head->next->next;
//		delete tmp;
//	}
//	delete head;
//	head = nullptr;
//}
//
//template<typename T>
//int List<T>::GetSize() const// узнать число звеньев в списке
//{
//	int k = 0;
//	Node<T>* tmp = head;
//	while (tmp != nullptr)
//	{
//		k++;
//		tmp = tmp->next;
//	}
//	return k;
//}
//
//template<typename T>
//Node<T>* List<T>::GetHead() const// получить указатель на первое звено списка
//{
//	return head;
//}



#endif