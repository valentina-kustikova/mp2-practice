#ifndef _TLIST_H_
#define _TLIST_H_

#include "tnode.h"
#include <iostream>

using namespace std;

template <class Type>
class TList
{
protected:
	TNode<Type>* head;		// first element
	TNode<Type>* curr;		// current node 
	TNode<Type>* last;		// last element
	TNode<Type>* stop;		

public:

	TList();
	TList(const TList<Type>& list);
	TList(const TNode<Type>* node);
	virtual ~TList();
	virtual void pop_first();
	virtual void pop_last();
	virtual void pop_curr();
	void remove(const TNode<Type>* node);
	void remove(const Type& value);

	virtual void push_back(const Type& value);
	virtual void push_front(const Type& value);
	virtual void push_after_curr(const Type& value);

	virtual TNode<Type>* find_prev(const Type& value) const;
	virtual TNode<Type>* find(const Type& value) const;
	

	TNode<Type>* get_curr() const;
	int get_size() const;
	
	void start();
	bool empty() const;
	virtual void next();
	void sort(bool reverse=true);
	virtual void clear();
	virtual void copy(const TNode<Type>* node);

	friend istream& operator>>(istream& buf, TList<Type>& list)
	{
		int count;
		cout << "Input a count of elements:\n";
		cin >> count;
		cout << "Input values:" << endl;
		while (count)
		{
			count--;
			Type value; cin >> value;
			list.push_back(value);
		}

		return buf;
	}
	friend ostream& operator<<(ostream& buf, TList<Type>& list)
	{
		TNode<Type>* tmp = list.head;
		if (list.empty())
		{
			buf << "List is empty!\n";
			return buf;
		}
		while (tmp != nullptr)
		{
			buf << tmp->value << " ";
			tmp = tmp->next;
		}
		buf << endl;

		return buf;
	}

};

template <class Type>
TList<Type>::TList()
{
	head = nullptr;
	last = nullptr;
	curr = nullptr;
	stop = nullptr;
}


template <class Type>
void TList<Type>::copy(const TNode<Type>* node)
{
	TNode<Type>* tmp = node->next;
	head = new TNode<Type>(node->value);
	curr = head;
	last = head;
	stop = nullptr;
	while (tmp != nullptr)
	{
		last->next = new TNode<Type>(tmp->value);
		last = last->next;
		tmp = tmp->next;
	}
}


template <class Type>
TList<Type>::TList(const TList<Type>& list): TList<Type>()
{
	if (list.empty())
	{
		return;
	}
	copy(list.head);
}


template <class Type>
TList<Type>::TList(const TNode<Type>* node)
{
	if (node == nullptr)
	{
		return;
	}
	copy(node);
}


template <class Type>
TList<Type>::~TList<Type>()
{
	clear();
}

template <class Type>
bool TList<Type>::empty() const
{
	return head == nullptr;
}


template <class Type>
void TList<Type>::next()
{
	if (curr == nullptr)
	{
		string ex = "next isn`t exist";
		throw ex;
	}
	curr = curr->next;
}


template <class Type>
int TList<Type>::get_size() const
{
	TNode<Type>* tmp = head;
	int size = 0;
	while (tmp != stop)
	{
		size++;
		tmp = tmp->next;
	}
	return size;
}


template <class Type>
TNode<Type>* TList<Type>::get_curr() const
{
	return curr;
}


template <class Type>
TNode<Type>* TList<Type>::find_prev(const Type& value) const
{
	TNode<Type>* tmp = head;
	
	if (head->value == value)
	{
		return nullptr;
	}

	while (tmp != stop)
	{
		if (tmp->next->value == value) break;
		tmp = tmp->next;
	}
	if (tmp == stop)
	{
		return nullptr;
	}
	return tmp;
}


template <class Type>
TNode<Type>* TList<Type>::find(const Type& value) const
{
	if (head == nullptr) return nullptr;
	TNode<Type>* tmp = head;
	
	while (tmp != stop)
	{
		if (tmp->value == value)
		{
			break;
		}
		tmp = tmp->next;
	}
	if (tmp == stop)
	{
		return nullptr;
	}
	return tmp;
}


template <class Type>
void TList<Type>::pop_first()
{
	if (head == nullptr)
	{
		string ex = "SizeError: can`t remove empty list";
		throw ex;
	}
	
	if (last == head)
	{
		*this = TList<Type>();
		return;
	}
	if (curr == head)
	{
		curr = head->next;
	}
	TNode<Type>* tmp = head->next;
	delete head;
	head = tmp;
}


template <class Type>
void TList<Type>::pop_last()
{
	if (head == nullptr)
	{
		string ex = "SizeError: can`t remove empty list";
		throw ex;
	}

	if (last == head)
	{
		*this = TList<Type>();
		return;
	}

	

	TNode<Type>* tmp = head;
	while (tmp->next != last)
	{
		tmp = tmp->next;
	}

	if (curr == last)
	{
		curr = tmp;
	}

	delete tmp->next;
	tmp->next = nullptr;

	
	last = tmp;

}


template <class Type>
void TList<Type>::remove(const TNode<Type>* node)
{
	if (head == nullptr)
	{
		string ex = "SizeError: can`t remove empty list";
		throw ex;
	}

	if (node == nullptr)
	{
		return; 
	}

	if (head == node)
	{
		this->pop_first();
		return;
	}

	if (last == node)
	{
		this->pop_last();
		return;
	}

	TNode<Type>* tmp = head;

	while (tmp->next != node && tmp != stop)
	{
		tmp = tmp->next;
	}
	
	if (tmp == stop)
	{
		return;
	}

	TNode<Type>* tmp1 = tmp->next->next;
	
	// rightward shift
	if (curr == node)
	{
		curr = tmp1;
	}

	delete tmp->next;
	tmp->next = tmp1;
}


template <class Type>
void TList<Type>::remove(const Type& value)
{
	TNode<Type>* tmp = head;
	
	if (head == nullptr)
	{
		string ex = "SizeError: can`t remove empty list";
		throw ex;
	}

	if (head->value == value)
	{
		this->pop_first();
		return;
	}

	while (tmp->next != stop)
	{
		if (tmp->next->value == value)
		{
			break;
		}
		tmp = tmp->next;
	}
	
	if (tmp->next == stop)
	{
		return;
	}
	if (tmp->next->next == stop && tmp->next->value == value)
	{
		this->pop_last();
		return;
	}
	TNode<Type>* tmp1 = tmp->next->next;

	// rightward shift
	if (curr == tmp->next)
	{
		curr = tmp1;
	}
	delete tmp->next;
	tmp->next = tmp1;
}


template <class Type>
void TList<Type>::pop_curr()
{
	if (head == curr)
	{
		this->pop_first();
		return;
	}
	if (last == curr)
	{
		this->pop_last();
		return;
	}
	TNode<Type>* tmp1 = head, *tmp = curr;
	while (tmp1->next != curr) tmp1 = tmp1->next;
	curr = curr->next;
	tmp1->next = curr;
	delete tmp;
}


template <class Type>
void TList<Type>::push_back(const Type& value)
{
	if (last == nullptr)
	{
		last = new TNode<Type>(value);
		head = last;
		curr = head;
		return;
	}

	last->next = new TNode<Type>(value);
	last = last->next;
}


template <class Type>
void TList<Type>::push_front(const Type& value)
{
	if (head == nullptr)
	{
		head = new TNode<Type>(value);
		last = head;
		curr = head;
		return;
	}
	TNode<Type>* new_head = new TNode<Type>(value);
	new_head->next = head;
	head = new_head;
}


template <class Type>
void TList<Type>::push_after_curr(const Type& value)
{
	if (curr == last)
	{
		this->push_back(value);
		return;
	}

	TNode<Type>* tmp = curr->next;
	curr->next = new TNode<Type>(value);
	curr->next->next = tmp;
}


template<class Type>
void TList<Type>::sort(bool reverse)
{
	if (head == nullptr)
		return;

	TNode<Type>* tmp1 = head;
	while (tmp1->next != stop)
	{
		TNode<Type>* tmp2 = tmp1->next;
		while (tmp2 != stop)
		{
			if (reverse)
			{
				if (tmp1->value < tmp2->value)
				{
					Type tmp = tmp1->value;
					tmp1->value = tmp2->value;
					tmp2->value = tmp;
				}
				tmp2 = tmp2->next;
			}
			else
			{
				if (tmp1->value > tmp2->value)
				{
					Type tmp = tmp1->value;
					tmp1->value = tmp2->value;
					tmp2->value = tmp;
				}
				tmp2 = tmp2->next;
			}
		}
		tmp1 = tmp1->next;
	}
}


template<class Type>
void TList<Type>::clear()
{
	
	while (head != stop)
	{
		TNode<Type>* tmp;
		tmp = head;
		head = head->next;
		delete tmp;
	}
	curr = nullptr;
	last = nullptr;
	stop = nullptr;
}


template<class Type>
void TList<Type>::start()
{
	curr = head;
}


#endif // 
