#ifndef _TRingList_H_
#define _TRingList_H_

#include "tlist.h"
#include <iostream>
using namespace std;


template <class Type>
class TRingList: public TList<Type>
{
private:
	TNode<Type>* fict_head;
public:

	TRingList();
	TRingList(const TRingList<Type>& list);
	TRingList(const TNode<Type>* node);
	
	void pop_first();
	void pop_last();
	void pop_curr();
	void remove(const TNode<Type>* node);
	void remove(const Type& value);

	void next();
	void sort(bool reverse=true);
	void clear();

	TNode<Type>* find(const Type& value) const;
	void push_after_curr(const Type& value);
	void push_back(const Type& value);
	void push_front(const Type& value);
	bool operator==(const TRingList<Type>& list) const;
	friend ostream& operator<<(ostream& buf, TRingList<Type>& list)
	{
		TNode<Type>* tmp = list.fict_head->next;
		
		if (list.empty())
		{
			buf << "List is empty!\n";
			return buf;
		}

		while (tmp != list.fict_head)
		{
			buf << tmp->value << endl;
			tmp = tmp->next;
		}
	

		return buf;
	}
};

template <class Type>
TRingList<Type>::TRingList()
{
	fict_head = new TNode<Type>;
	last = fict_head;
	last->next = fict_head;
}


template <class Type>
TRingList<Type>::TRingList(const TRingList<Type>& list)
{
	if (list.empty())
	{
		*this = TRingList<Type>();
		return;
	}
	TNode<Type>* tmp = list.head;
	head = new TNode<Type>(list.head->value);
	curr = head;
	last = head;
	fict_head = new TNode<Type>;
	fict_head->next = head;

	while (tmp->next != list.fict_head)
	{
		last->next = new TNode<Type>(tmp->next->value);
		last = last->next;
		tmp = tmp->next;
	}
	last->next = fict_head;
}


template <class Type>
TRingList<Type>::TRingList(const TNode<Type>* node)
{
	if (node == nullptr)
	{
		*this = TRingList<Type>();
	}
	else
	{
		TNode<Type>* tmp = node->next;
		head = new TNode<Type>(node->value);
		curr = head;
		last = head;
		fict_head = new TNode<Type>;
		fict_head->next = head;
		while (tmp != nullptr)
		{
			last->next = new TNode<Type>(tmp->value);
			last = last->next;
			tmp = tmp->next;
		}
		last->next = fict_head;
	}
}

template<class Type>
bool TRingList<Type>::operator==(const TRingList<Type>& list) const
{
	TNode<Type>* t = head, *t2 = list.head;
	if (t == nullptr || t2 == nullptr)

	{
		throw "Your polynoms must not be empty!\n";
	}
	while ((t != fict_head) && (t2 != list.fict_head))
	{
		if (t->value != t2->value)
		{
			return false;
		}
		t = t->next;
		t2 = t2->next;
	}
	return (t == fict_head) && (t2 == list.fict_head);
}


template <class Type>
void TRingList<Type>::next()
{
	curr = curr->next;
}


template <class Type>
void TRingList<Type>::pop_first()
{
	if (head == nullptr)
	{
		string ex = "SizeError: can`t remove empty list";
		throw ex;
	}
	
	if (last == head)
	{
		*this = TRingList<Type>();
		return;
	}
	if (curr == head)
	{
		curr = head->next;
	}
	TNode<Type>* tmp = head->next;
	fict_head->next = tmp;
	delete head;
	head = tmp;
}


template <class Type>
void TRingList<Type>::pop_last()
{
	if (head == nullptr)
	{
		string ex = "SizeError: can`t remove empty list";
		throw ex;
	}

	if (last == head)
	{
		*this = TRingList<Type>();
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
	tmp->next = fict_head;

	
	last = tmp;

}

template <class Type>
void TRingList<Type>::push_back(const Type& value)
{
	if (head == nullptr)
	{
		head = new TNode<Type>(value);
		last = head;
		last->next = fict_head;
		fict_head->next = head;
		curr = head;
		return;
	}
	
	TNode<Type>* tmp = new TNode<Type>(value);
	tmp->next = fict_head;
	last->next = tmp;
	last = last->next;
}


template <class Type>
void TRingList<Type>::push_front(const Type& value)
{
	if (head == nullptr)
	{
		head = new TNode<Type>(value);
		last = head;
		curr = head;
		last->next = fict_head;
		fict_head->next = head;
		return;
	}
	TNode<Type>* new_head = new TNode<Type>(value);
	new_head->next = head;
	head = new_head;
	fict_head->next = head;
}

template <class Type>
void TRingList<Type>::remove(const TNode<Type>* node)
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

	while (tmp->next != node && tmp->next != fict_head)
	{
		tmp = tmp->next;
	}

	if (tmp->next == fict_head)
	{
		string ex = "Element was not found\n";
		throw ex;
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
void TRingList<Type>::remove(const Type& value)
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

	while (tmp->next != fict_head)
	{
		if (tmp->next->value == value)
		{
			break;
		}
		tmp = tmp->next;
	}

	if (tmp->next == fict_head)
	{
		if (tmp->value == value)
		{
			this->pop_last();
		}
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
void TRingList<Type>::pop_curr()
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
	TNode<Type>* tmp1 = head, * tmp = curr;
	while (tmp1->next != curr) tmp1 = tmp1->next;
	curr = curr->next;
	tmp1->next = curr;
	delete tmp;

}


template <class Type>
void TRingList<Type>::push_after_curr(const Type& value)
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
void TRingList<Type>::sort(bool reverse)
{
	if (head == nullptr)
		return;

	TNode<Type>* tmp1 = head;
	while (tmp1->next != fict_head)
	{
		TNode<Type>* tmp2 = tmp1->next;
		while (tmp2 != fict_head)
		{
			if (!reverse)
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
void TRingList<Type>::clear()
{
	if (head == nullptr)
	{
		return;
	}
	while (head != fict_head)
	{
		TNode<Type>* tmp;
		tmp = head;
		head = head->next;
		delete tmp;
	}
	head = nullptr;
	curr = nullptr;
	last = fict_head;
	last->next = fict_head;
}


template<class Type>
TNode<Type>* TRingList<Type>::find(const Type& value) const
{
	if (head == nullptr)
	{
		return nullptr;
	}
	TNode<Type>* tmp = head;

	while (tmp != fict_head)
	{
		if (tmp->value == value)
		{
			break;
		}
		tmp = tmp->next;
	}
	if (tmp == fict_head)
	{
		return nullptr;
	}
	return tmp;
}
#endif // 
