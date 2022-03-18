#pragma once
#include <iostream>

using namespace std;

struct TData
{
	int key;
	TData() { 
		key = 0;
	};
	
	TData(const int key)
	{
		this->key = key;
	};

	friend ostream& operator<<(ostream& out, const TData& data) {
		out << data.key;
		return out;

	};

	friend istream& operator>>(istream& in, TData& data) {
		in >> data.key;
		return in;
	};



};

struct TNode
{
	TData data;
	TNode* pNext;

	TNode() {
		this->pNext = nullptr;
	};
	TNode(const TData& data)
	{
		this->data = data;
		this->pNext = nullptr;

	};

	TNode(const TData& data, TNode* const pNext)
	{
		this->data = data;
		this->pNext = pNext;

	};

	TNode(const TNode& node)
	{
		this->data = node.data;
		this->pNext = nullptr;
	
	};

};

class TList : TData
{
private:
	TNode* pFirst;
	TNode* pCurr;
	TNode* pPrev;
	TNode* pNext;

public:
	TList();
	TList(TNode* pFirst);
	TList(const TList& list);

	~TList();
	
	//Operations
	TNode* Search(const TData& data);
	void InsertToHead(const TData& data);
	void InsertToTail(const TData& data);
	void InsertBefore(const TData& data, const TData& before_data);
	void InsertAfter(const TData& data, const TData& after_data);
	void Remove(const TData& data);
	void Sort();

	//Navigation
	void Next();
	void Reset();
	bool isEmpty() const;
	bool isEnded() const;

	void Print();

};

TList::TList()
{
	this->pFirst = nullptr;
	this->pCurr = nullptr;
	this->pPrev = nullptr;
	this->pNext = nullptr;
}

TList::TList(TNode* pFirst)
{
	this->pFirst = pFirst;
	this->pCurr = this->pFirst;
	this->pPrev = nullptr;
	this->pNext = this->pFirst->pNext;
}

TList::TList(const TList& list)
{
	this->pFirst = list.pFirst;
	this->pCurr = list.pCurr;
	this->pPrev = list.pPrev;
	this->pNext = list.pNext;
}

TList::~TList()
{   

}

TNode* TList::Search(const TData& data)
{
	int counter = 0;
	pCurr = this->pFirst;
	while (pCurr != nullptr)
	{
		if (counter == data.key)
		{
			return new TNode(pCurr->data);	
		}
		pCurr = pCurr->pNext;
		counter++;
	}
}

void TList::InsertToHead(const TData& data)
{
	pCurr = new TNode(data, pFirst);
	pFirst = pCurr;
}

void TList::InsertToTail(const TData& data)
{
	if (pFirst == nullptr)
	{
		pFirst = new TNode(data);
	}
	else
	{
		pCurr = this->pFirst;

		while (pCurr->pNext != nullptr)
		{
			pCurr = pCurr->pNext;
		}
		pCurr->pNext = new TNode(data);
	}
}

void TList::InsertBefore(const TData& data, const TData& before_data)
{
	
	TNode* tmp = Search(before_data);
	pCurr->pNext = new TNode(data);

	
	//if (pPrev == nullptr)
	//{
	//	InsertToHead(data);
	//}
	//else
	//{
	//	pPrev = this->pFirst;
	//	while (pPrev->pNext != pCurr)
	//	{
	//		pPrev = pPrev->pNext;
	//	}
	//	
	//	pCurr = new TNode(data, pPrev->pNext);
	//	pPrev->pNext = pCurr;
	//}


}

void TList::InsertAfter(const TData& data, const TData& after_data)
{
	throw exception("Function not implemented");
}

void TList::Remove(const TData& data)
{
	throw exception("Function not implemented");
}

void TList::Sort()
{
	throw exception("Function not implemented");
}

void TList::Next()
{
	throw exception("Function not implemented");
}

void TList::Reset()
{
	while (pFirst != nullptr)
	{
		pCurr = pFirst;
		pFirst = pFirst->pNext;

		delete pCurr;
	}
}

bool TList::isEmpty() const
{
	throw exception("Function not implemented");
}

bool TList::isEnded() const
{
	throw exception("Function not implemented");
}

void TList::Print()
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
		cout << "All Clear" << endl;
	}

}


class TMonom: public TData
{
public:
	double coeff;
	int degree;
public:
	TMonom(double coeff, int degree);
	
	TMonom& operator=(const TMonom& monom);
	
	int operator==(const TMonom& monom) const;
	int operator!=(const TMonom& monom) const;
	int operator<(const TMonom& monom) const;
	int operator>(const TMonom& monom) const;
	
	virtual TData* Copy(); // создание копии
};
