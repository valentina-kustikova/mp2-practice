#pragma once
#include <iostream>

// Звено
template <typename TData>
class  Node
{ public:
  TData data;
  Node<TData>* next;
  // конструкторы
  Node(TData D = NULL, Node<TData>* N = nullptr) { data = D; next = N; }
  Node(Node<TData>& N2) { data = N2.data; next = nullptr; } // конструктор копирования
  //перегрузка операций
  bool operator<   (const Node<TData>& N) const { return (data < N.data); }
  bool operator>   (const Node<TData>& N) const { return (data > N.data); }
  bool operator!=  (const Node<TData>& N) const { return !(*this == N); }
  bool operator==  (const Node<TData>& N) const { return (data == N.data && next == N.next); }
};

// Список
template<typename TData>
class List
{ protected:
  Node<TData>* head;
  Node<TData>* it; // текущий элемент (итератор)
  public:
  // Конструкторы, деструктор	
  List();
  List(const List<TData>& L2);  // конструктор копирования
  ~List();
  // Методы 
  void InsertAfter(Node<TData>* N, TData Data);
  void InsertToTail(TData Data);
  void Clean(); 
  Node<TData>* GetIT() const { return it; } 
  void SetNext() { it = it->next; }
  void Reset() { it = head->next; } 
  void End() { it = head; }
  bool IsEnd() const { return it == head; } 
  void Delete(Node<TData>* N);
  // Перегрузка операций
  List<TData>& operator=(const List<TData>& L2);
  bool operator==(const List<TData>& L) const;
  bool operator!=(const List<TData>& L) const { return !(*this == L); }
};

// Pелизация функциий для класса списка
// Конструкторы, деструктор	
template <typename TData>
List<TData>::List()
{ head = new Node<TData>;
  head->data = NULL;
  head->next = head;
  it = head;
}
template <typename TData> // конструктор копирования
List<TData>::List(const List<TData>& L2)
{ Node<TData>* it2 = L2.head;
  head = new Node<TData>(it2->data);
  head->next = head;
  it = head;
  while (it2->next != L2.head)
  { it2 = it2->next;
	it->next = new Node<TData>(it2->data);
	SetNext();
  }
  it->next = head;
}
template <class TData>
List<TData>::~List()
{ Clean();
  delete head;
}
// Перегрузка операций
template <class TData>
List<TData>& List<TData>::operator=(const List<TData>& L2)
{ Clean();
  Node<TData>* it1 = L2.head;
  Node<TData>* it2 = head;
  while (it1->next != L2.head)
  { it1 = it1->next;
	it2->next = new Node<TData>(it1->data);
	it2 = it2->next;
  }
  it2->next = head;
  it = head;
  return *this;
}
template<class TData>
bool List<TData>::operator==(const List<TData>& L) const
{
	bool flag = true;
	if (this != &L)
	{
		Node<TData>* temp1 = head->next;
		Node<TData>* temp2 = L.head->next;

		while (temp1 != head && temp2 != L.head && temp1->data == temp2->data)
		{
			temp1 = temp1->next;
			temp2 = temp2->next;
		}
		if (temp1 != head || temp2 != L.head)
			flag = false;
	}
	return flag;
}
// Методы 
template <class TData>
void List<TData>::InsertAfter(Node<TData>* N, TData Data)
{
	Node<TData>* temp = N->next;
	N->next = new Node<TData>(Data);
	N->next->next = temp;
}
template <class TData>
void List<TData>::Delete(Node<TData>* N)
{ Node<TData>* temp;
  it = head;
  while (it->next != N)
  { SetNext();}
  it->next = N->next;
  delete N;
}
template <class TData>
void List<TData>::InsertToTail(TData Data)
{ Node<TData>* tmp;
  it = head;
  while ((it->next->data > Data) && it->next != head)
  {SetNext();}
  tmp = it->next;
  it->next = new Node<TData>(Data);
  it->next->next = tmp;
}
template <class TData>
void List<TData>::Clean()
{ Node<TData>* it2 = head->next;
  Node<TData>* tmp;
  while (it2 != head)
  { tmp = it2->next;
	delete it2;
	it2 = tmp;
  }
  head->next = head;
}