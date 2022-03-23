#pragma once
#include <iostream>

using namespace std;

template <typename T>

struct TNode
{
	T data;
	TNode<T>* pNext;

	TNode() {
		this->pNext = nullptr;
	};
	TNode(T data)
	{
		this->data = data;
		this->pNext = nullptr;

	};

	TNode(T data, TNode<T>* pNext)
	{
		this->data = data;
		this->pNext = pNext;

	};

	TNode(TNode<T>& node)
	{
		this->data = node.data;
		this->pNext = nullptr;
	
	};
	
	bool operator!=(const TNode<T>& node)
	{
		return !(*this == node);

	}

	bool operator==(const TNode<T>& node)
	{
		return ((data = node.data && pNext = node.pNext));
	
	}

	bool operator<(const TNode<T>& node)
	{
		return data < node.data;
	}

	bool operator> (const TNode<T>& node)
	{
		return data > node.data;
	}

};

template <typename T>

class TList
{
private:
	TNode<T>* pFirst;
	TNode<T>* pCurr;

public:
	TList();
	TList(TNode<T>* pFirst);
	TList(const TList<T>& list);

	~TList();

	TList<T>& operator=(const TList<T>& list);
	
	//Inserts
	void InsertToHead(T data);
	void InsertToTail(T data);
	void InsertAfter(T data, TNode<T>* after_data);

	//Removes
	void RemoveHead();
	void RemoveTail();
	
	TNode<T>* getpCurr() const 
	{
		return pCurr;
	};

	void Next()
	{
		pCurr = pCurr->pNext;
	}
	
	bool operator==(const TList& list) const;
	bool operator!=(const TList& list) const;

	//User's help
	void Reset();
	bool isEnd() const;
	void Print();
	void Clean();
};

template <typename T>
TList<T>::TList()
{
	this->pFirst = NULL;
	this->pCurr = NULL;
}

template <typename T>
TList<T>::TList(TNode<T>* pFirst)
{
	this->pFirst = pFirst;
	this->pCurr = this->pFirst;
}

template <typename T>
TList<T>::TList(const TList<T>& list)
{
	this->pFirst = list.pFirst;
	this->pCurr = list.pCurr;
}

template <typename T>
TList<T>::~TList()
{   
	Clean();
	delete pFirst;
}

template<typename T>
TList<T>& TList<T>::operator=(const TList<T>& list)
{
	Clean();
	
	TNode<T>* temp1 = pFirst;
	TNode<T>* temp2 = list.pFirst;

	while (temp2->pNext != list.pFirst)
	{
		temp2 = temp2->pNext;
		temp1->pNext = new TNode<T>(temp2->data);
		temp1 = temp1->pNext;
	}
	temp1->pNext = pFirst;
	pCurr = pFirst;
	return *this;
}

template <typename T>
void TList<T>::InsertToHead(T data)
{
	pCurr = new TNode<T>(data, pFirst);
	pFirst = pCurr;
}

template <typename T>
void TList<T>::InsertToTail(T data)
{
	if (pFirst == nullptr)
	{
		InsertToHead(data);
	}
	else
	{
		pCurr = this->pFirst;

		while (pCurr->pNext != nullptr)
		{
			pCurr = pCurr->pNext;
		}
		pCurr->pNext = new TNode<T>(data);
	}
}


template <typename T>
void TList<T>::InsertAfter(T data, TNode<T>* after_data)
{
	TNode<T>* temp = after_data->pNext;
	after_data->pNext = new TNode<T>(data);
	after_data->pNext->pNext = temp;
}

template <typename T>
void TList<T>::RemoveHead()
{
	pCurr = pFirst;
	pFirst = pFirst->pNext;
	delete pCurr;
}

template <typename T>
void TList<T>::RemoveTail()
{
	if (pFirst == nullptr)
	{
		RemoveHead();
	}
	else
	{
		pCurr = this->pFirst;

		while (pCurr->pNext->pNext != nullptr)
		{
			pCurr = pCurr->pNext;
		}
		
		TNode<T>* rem = pCurr->pNext;

		pCurr->pNext = rem->pNext;


		delete rem;
	}
}


template<typename T>
bool TList<T>::operator==(const TList& list) const
{
	bool temp = true;

	if (this != &list)
	{
		TNode<T>* first = pFirst->pNext;
		TNode<T>* second = list.pFirst->pNext;

		while (first != pFirst && second != list.pFirst && first->data == second->data)
		{
			first = first->pNext;
			second = second->pNext;
		}

		if (first != pFirst || second != list.pFirst)
		{
			temp = false;
		}

	}
	return temp;
}

template<typename T>
inline bool TList<T>::operator!=(const TList& list) const
{
	bool temp = false;
	if (this != &list)
	{
		TNode<T>* first = pFirst->pNext;
		TNode<T>* second = list.pFirst->pNext;

		while (first != pFirst && second != list.pFirst && first->data != second->data)
		{
			first = first->pNext;
			second = second->pNext;
		}

		if (first != pFirst || second != list.pFirst)
		{
			temp = true;
		}
	}
	return temp;
}

template<typename T>
void TList<T>::Reset()
{
	pCurr = pFirst->pNext;
}

template<typename T>
bool TList<T>::isEnd() const
{
	return pCurr == pFirst;
}

template <typename T>
void TList<T>::Print()
{
	if (pFirst != nullptr)
	{
		pCurr = pFirst;
		while (pCurr != nullptr)
		{
			cout << pCurr->data << endl;
			pCurr = pCurr->pNext;
		}
	}
	else
	{
		cout << "All Clean" << endl;
	}

}

template<typename T>
void TList<T>::Clean()
{
	while (pFirst != nullptr)
	{
		RemoveHead();
	}
}


class TMonom
{
public:
	double coeff;
	int degree;

	TMonom(double coeff = 0, int degree = 0);
	
	TMonom& operator=(const TMonom& monom);
	
	bool operator==(const TMonom& monom) const;
	bool operator!=(const TMonom& monom) const;
	bool operator<(const TMonom& monom) const;
	bool operator>(const TMonom& monom) const;

};
