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

	Node(Node<T>* n = nullptr)
	{
		next = n;
	}

	Node(T d, Node<T>* n = nullptr)
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
public:
	List();
	List(const List& list2);
	List& operator=(const List& list2);
	~List();
	bool isEmpty() const { return (head->next == nullptr); }
	T ViewHead() { return head->next->data; }

	void InsertToHead(const T& d);      // вставить элемент d первым
	void InsertToTail(const T& d);     // вставить элемент d последним
	void InsertAfter(Node<T>* node, const T& d); // вставить элемент d после звена node
	void Delete(const T& d);         // удалить звено со значением data = d
	Node<T>* Search(const T& d);    // найти указатель на звено со значением data = d
	void Clean();                  // удалить все звенья
	int GetSize() const;          // узнать число звеньев в списке
	Node<T>* GetHead() const;    // получить указатель на первое звено списка
	friend ostream& operator<<(ostream& os, const List<T>& l);

	Node<T>* returnFictitiousNode() { return head }//для проверки, что фиктивное звено действительно есть и оно такое, какое было создано. 
};

template<typename T>
ostream& operator<<(ostream& os, const List<T>& l)
{
	Node* tmp = l.head;
	tmp = tmp->next;
	while (tmp)
	{
		cout << tmp->data << ' ';
		tmp = tmp->next;
	}
	return os;
}

template<typename T>
List<T>::List()
{
	head = new Node<T>(nullptr);
}

template<typename T>
List<T>::List(const List& list2)
{
	head = new Node<T>(nullptr);

	Node<T>* tmp1 = head;
	Node<T>* tmp2 = list2.head->next;

	while (tmp2 != nullptr)
	{
		tmp1->next = new Node<T>(tmp2->data);
		tmp1 = tmp1->next;
		tmp2 = tmp2->next;
	}
}

template<typename T>
List<T>& List<T>::operator=(const List& list2)
{
	if (this != &list2)
	{
		Node<T>* p = head->next, * q = head->next;
		while (q != nullptr)
		{
			q = p->next;
			delete p;
			p = q;
		}
		if (list2.isEmpty())
			head->next = nullptr;
		else
		{
			head->next = new Node<T>(list2.head->next->data);
			p = head->next;
			q = list2.head->next->next;
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
	tmp1 = head->next;
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
	Node<T>* p = new Node<T>(d, head->next);
	head->next = p;
}

template<typename T>
void List<T>::InsertToTail(const T& d)// вставить элемент d последним
{
	Node<T>* p = new Node<T>(d, nullptr);
	Node<T>* tmp = head;
	while (tmp->next != nullptr)
	{
		tmp = tmp->next;
	}
	tmp->next = p;
}

template<typename T>
void List<T>::InsertAfter(Node<T>* _node, const T& d)// вставить элемент d после звена node
{
	if (_node != nullptr)
	{
		Node<T>* temp = _node->next;
		_node->next = new Node<T>(d, temp);
	}
}

template<typename T>
void List<T>::Delete(const T& d)// удалить звено со значением data = d
{
	Node<T>* del;
	Node<T>* tmp = head->next;
	if (tmp != nullptr)
	{
		if (tmp->data == d)
		{
			del = tmp->next;
			delete head->next;
			head->next = del;
		}
		else {
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
	Node<T>* tmp = head->next;
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

	while (head->next != nullptr)
	{
		tmp = head->next;
		head->next = tmp->next;
		delete tmp;
	}
}

template<typename T>
int List<T>::GetSize() const// узнать число звеньев в списке
{
	int k = 0;
	Node<T>* tmp = head->next;
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
	return head->next;
}

#endif