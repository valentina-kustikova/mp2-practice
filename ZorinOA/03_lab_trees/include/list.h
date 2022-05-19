#include <iostream>

template <class TData>
struct Node
{
	TData data;
	Node* next;

	Node(TData d, Node* n = NULL) : data(d), next(n)
	{
	}
	Node(const Node& node2)
	{
		data = node2.data;
	}
	bool operator==(const Node& node2) const
	{
		return (data == node2.data);
	}
};

template <class TData>
class List
{
protected:
	Node<TData>* head;
public:
	List()
	{
		head = nullptr;
	}
	List(const List& list2)
	{
		if (!list2.isEmpty())
		{
			head = new Node<TData>(list2.head->data);
			Node<TData>* tmp1 = head;
			Node<TData>* tmp2 = list2.head->next;

			while (tmp2 != nullptr)
			{
				tmp1->next = new Node<TData>(tmp2->data);
				tmp1 = tmp1->next;
				tmp2 = tmp2->next;
			}
		}
		else
			head = nullptr;
	}
	List& operator=(const List& list2)
	{
		if (this != &list2)
		{
			Node<TData>* p = head, * q = head;
			while (q != nullptr)
			{
				q = p->next;
				delete p;
				p = q;
			}

			if (list2.isEmpty())
				head = nullptr;
			else
			{
				head = new Node<TData>(list2.head->data);
				p = head;
				q = list2.head->next;
				while (q != nullptr)
				{
					p->next = new Node<TData>(q->data);
					p = p->next;
					q = q->next;
				}
			}
		}

		return *this;
	}
	~List()
	{
		Node<TData>* tmp, * tmp1; // указатель-ходилка
		tmp = head;
		tmp1 = tmp;
		while (tmp1 != nullptr)
		{
			tmp1 = tmp->next;
			delete tmp;
			tmp = tmp1;
		}
	}
	bool isEmpty() const
	{
		return (head == nullptr);
	}
	void InsertToHead(const TData& d)
	{
		if (isEmpty())
		{
			head = new Node<TData>(d, nullptr); // это первый и единственный
		}
		else
		{
			head = new Node<TData>(d, head);
		}
	} // вставить элемент d первым
	void DeleteHead()
	{
		if (!isEmpty())
		{
			Node<TData>* tmp = head;
			head = head->next;
			delete tmp;
		}
	}
	void Delete(const TData& d)
	{
		if (!isEmpty())
		{
			Node<TData>* prev = head;
			Node<TData>* tmp;

			if (head->data == d)
			{
				head = head->next;
				delete prev;
				return;
			}

			while (prev->next != nullptr)
			{
				if (prev->next->data == d)
				{
					tmp = prev->next;
					prev->next = prev->next->next;
					delete tmp;
				}
				else
					prev = prev->next;
			}
		}
	}
	void Inverse()
	{
		Node<TData>* p = nullptr, * q = head;
		Node<TData>* tmp;

		while (q != nullptr)
		{
			tmp = q->next;
			q->next = p;
			p = q;
			q = tmp;
		}

		head = p;
	}
	Node<TData>* Search(const TData& d)
	{
		Node<TData>* p = head;
		while (p != nullptr)
		{
			if (p->data == d)
				return p;
			p = p->next;
		}
		return nullptr;
	}
	void Clear()
	{
		if (!isEmpty())
		{
			Node<TData>* p;
			while (head->next != nullptr)
			{
				p = head->next;
				head->next = p->next;
				delete p;
			}
			delete head;
			head = nullptr;
		}
	}

	class Iterator
	{
		Node<TData>* p;
	public:
		Iterator(Node<TData>* _p = nullptr)
		{
			p = _p;
		}
		Iterator& operator++()
		{
			p = p->next;
			return *this;
		}
		TData& operator*() const
		{
			return p->data;
		}
		bool operator==(const Iterator& it) const
		{
			return p == it.p;
		}
		bool operator!=(const Iterator& it) const
		{
			return p != it.p;
		}
	};
	Iterator begin() const
	{
		List::Iterator it(head);
		return it;
	}
	Iterator end() const
	{
		List::Iterator it(nullptr);
		return it;
	}

	friend std::ostream& operator<<(std::ostream& os, const List& l)
	{
		if (!l.isEmpty())
		{
			os << l.head->data;
			Node<TData>* p = l.head->next;
			while (p != nullptr)
			{
				os << " - " << p->data;
				p = p->next;
			}
		}
		return os;
	}
};