#include "list.h"

TList::TList()
{
	this->pFirst = nullptr;
	this->pStop = nullptr;
	this->pCurr = nullptr;
	this->pNext = nullptr;
	this->Size = 0;
}

TList::TList(TNode* pfirst)
{
	this->pFirst = pfirst;
	this->pStop = nullptr;
	this->pCurr = this->pFirst;
	this->pNext = nullptr;
	this->Size = 1;
}

TList::TList(const TList& list)
{
	pStop = list.pStop;
	pFirst = list.pFirst;
	pCurr = list.pCurr;
	pNext = list.pNext;
	Size = list.Size;
}

TList::~TList()
{
	
}

TNode* TList::Search(TData const data)// поиск элемента в списке
{
	TNode* tempcurr = new TNode;
	tempcurr = pCurr;
	TNode* tempsearch = new TNode;
	if (this->pCurr->data != data)
	{
		while (tempcurr->data != data)
		{
			tempcurr = tempcurr->pNext;
		}
		tempsearch = tempcurr;
	}
	else
		tempsearch = pCurr;
	return tempsearch;
}

void TList::InsertToHead(TData const data)// вставить элемент в начало
{
	TNode* tempcurr = new TNode;
	tempcurr = pCurr;
	if (IsEmpty() == 1)
	{
		TNode* newfirst = new TNode(data);
		this->pFirst = newfirst;
		this->pCurr = this->pFirst;
		this->pNext = this->pStop;
		this->Size++;
		tempcurr = pCurr;
	}
	else
	{
		Reset();
		TNode* newfirst = new TNode(data);
		newfirst->pNext = this->pFirst;
		this->pFirst = newfirst;
		this->pCurr = this->pFirst;
		this->pNext = this->pFirst->pNext;
		this->Size++;
	}
	pCurr = tempcurr;
	pNext = pCurr->pNext;
}

void TList::InsertToTail(TData const data)// вставить элемент в конец
{
	TNode* tempcurr = new TNode;
	tempcurr = pCurr;
	if (IsEmpty() == 1)
	{
		TNode* newend = new TNode(data);
		this->pFirst = newend;
		this->pFirst->pNext = this->pStop;
		this->pCurr = this->pFirst;
		this->pNext = this->pStop;
		this->Size++;
		tempcurr = pCurr;
	}
	else
	{
		if (IsEnded() == 0)
		{
			while (IsEnded() == 0)
				Next();
		}
		TNode* newend = new TNode(data);
		newend->pNext = this->pStop;
		this->pCurr->pNext = newend;
		this->pCurr = newend;
		this->pNext = this->pStop;
		this->Size++;
	}
	pCurr = tempcurr;
	pNext = pCurr->pNext;
}

void TList::InsertAfter(TData const data, TData const after_data)// вставить элемент после данного
{
	TNode* tempcurr = new TNode;
	tempcurr = pCurr;
	TNode* el = new TNode(after_data);
	if (data != pStop->data)
	{
		if (pCurr->data != data)
		{
			while (pCurr->data != data)
			{
				Next();
			}
		}
		this->pCurr->pNext = el;
		el->pNext = this->pNext;
		this->pNext = el;
		this->Size++;
	}
	else
	{
		InsertToHead(el->data);
	}
	pCurr = tempcurr;
	pNext = pCurr->pNext;
}

void TList::RemoveFirst()// удалить первый элемент
{
	TNode* tempcurr = new TNode;
	tempcurr = pCurr;
	if (GetLenght() > 1)
	{
		Reset();
		this->pCurr = this->pNext;
		delete pFirst;
		this->pFirst = this->pCurr;
		this->pNext = this->pNext->pNext;
		this->Size--;
	}
	else
	{
		delete pFirst;
		pCurr = pStop;
		pNext = pStop;
		pFirst = nullptr;
		Size--;
	}
	pCurr = tempcurr;
	pNext = pCurr->pNext;
}

void TList::RemoveLast()// удалить последний элемент
{
	TNode* tempcurr = new TNode;
	tempcurr = pCurr;
	if (GetLenght() > 1)
	{
		while (this->pCurr->pNext->pNext != this->pStop)
			Next();
		this->pCurr->pNext = this->pStop;
		delete pNext;
	}
	else
	{
		delete pCurr;
		tempcurr = pStop;
	}
	this->Size--;
	pCurr = tempcurr;
	pNext = pCurr->pNext;
}

void TList::Remove(TData curr_data)// удалить данный элемент
{
	TNode* tempcurr = new TNode;
	tempcurr = pCurr;
	TNode* tempsearch = new TNode;
	tempsearch = pCurr;
	if (Size > 1 && curr_data != pFirst->data)
	{
		Reset();
		if (pCurr->data != curr_data)
		{
			while (tempsearch->pNext->data != curr_data)
				Next();
			pCurr->pNext = pNext->pNext;
			delete pNext;
			pNext = pCurr->pNext;
			Next();
			Size--;
		}
		else
		{
			while (this->pNext->data != curr_data)
				Next();
			pCurr->pNext = pNext->pNext;
			delete pNext;
			pNext = pCurr->pNext;
			Next();
			tempcurr = pCurr;
			Size--;
		}
	}
	else
	{
		RemoveFirst();
	}
	pCurr = tempcurr;
	pNext = pCurr->pNext;
}

int TList::GetLenght() const// получить длину списка
{
	return this->Size;
}

void TList::Clear()
{
	Reset();
	for (int i = 0; i < GetLenght(); i++)
	{
		RemoveLast();
	}
	delete pFirst;
	pFirst = nullptr;
	pCurr = pStop;
	Size = 0;
}

// Навигация

void TList::Next() // переход к следующему звену
{
	this->pCurr = this->pNext;
	this->pNext = this->pNext->pNext;
}

void TList::Reset() // переход в начало списка
{
	if (IsEmpty() == 0)
	{
		this->pCurr = this->pFirst;
		this->pNext = this->pFirst->pNext;
	}
}

bool TList::IsEnded() const // проверка на конец списка
{
	if (this->pNext == this->pStop)
		return 1;
	else
		return 0;
}

bool TList::IsEmpty() const // проверка на пустоту списка
{
	if (Size == 0)
		return 1;
	else
		return 0;
}

int TList::operator==(const TList list) const
{
	if (Size == list.Size)
	{
		TNode* temp = new TNode;
		TNode* temp2 = new TNode;
		temp = pFirst;
		temp2 = list.pFirst;
		if (temp->data != temp2->data)
			return 0;
		for (int i = 0; i < GetLenght() - 1; i++)
		{
			temp = temp->pNext;
			temp2 = temp2->pNext;
			if (temp->data != temp2->data)
				return 0;
		}
		return 1;
	}
	else
	    return 0;
}

TList& TList::operator =(const TList& list)
{
	pFirst = list.pFirst;
	pStop = list.pStop;
	Size = list.Size;
	return *this;
}

TNode* TList::GetFirst()
{
	return pFirst;
}

TNode* TList::GetLast()
{
	TNode* tempnode = new TNode;
	tempnode = pCurr;
	while (tempnode->pNext != pStop)
	{
		tempnode = tempnode->pNext;
	}
	return tempnode;
}

TNode* TList::GetCurr()
{
	return pCurr;
}

TNode* TList::GetNext()
{
	return pNext;
}