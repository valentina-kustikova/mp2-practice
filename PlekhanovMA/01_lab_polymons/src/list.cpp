#include "list.h"

TList::TList()
{
	this->pFirst = nullptr;
	TMonom* monomstop = new TMonom(-1, -1, -1, 1000.0f);
	this->pStop = monomstop;
	this->pCurr = monomstop;
	this->pNext = monomstop;
	this->Size = 0;
}

TList::TList(TMonom* pfirst)
{
	this->pFirst = pfirst;
	this->pFirst->pNext = this->pStop;
	TMonom* monomstop = new TMonom(-1, -1, -1, 1000.0f);
	this->pStop = monomstop;
	this->pCurr = this->pFirst;
	this->pNext = this->pStop;
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

TMonom* TList::Search(TData const data)// поиск элемента в списке
{
	TMonom* tempcurr = new TMonom;
	tempcurr = pCurr;
	TMonom* tempsearch = new TMonom;
	if (this->pCurr->data != data)
	{
		while (this->pCurr->data != data)
		{
			Next();
		}
		tempsearch = pCurr;
	}
	else
		tempsearch = pCurr;
	pCurr = tempcurr;
	pNext = tempcurr->pNext;
	return tempsearch;
}

void TList::InsertToHead(TData const data)// вставить элемент в начало
{
	TMonom* tempcurr = new TMonom;
	tempcurr = pCurr;
	if (IsEmpty() == 1)
	{
		TMonom* newfirst = new TMonom(data);
		this->pFirst = newfirst;
		this->pStop->pNext = this->pFirst;
		this->pFirst->pNext = this->pStop;
		this->pCurr = this->pFirst;
		this->pNext = this->pStop;
		this->Size++;
		tempcurr = pCurr;
	}
	else
	{
		Reset();
		TMonom* newfirst = new TMonom(data);
		this->pStop->pNext = newfirst;
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
	TMonom* tempcurr = new TMonom;
	tempcurr = pCurr;
	if (IsEmpty() == 1)
	{
		TMonom* newend = new TMonom(data);
		this->pFirst = newend;
		this->pFirst->pNext = this->pStop;
		this->pStop->pNext = this->pFirst;
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
		TMonom* newend = new TMonom(data);
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
	TMonom* tempcurr = new TMonom;
	tempcurr = pCurr;
	TMonom* el = new TMonom(after_data);
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
	pCurr = tempcurr;
	pNext = pCurr->pNext;
}

void TList::RemoveFirst()// удалить первый элемент
{
	TMonom* tempcurr = new TMonom;
	tempcurr = pCurr;
	if (GetLenght() > 1)
	{
		Reset();
		this->pStop->pNext = this->pNext;
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
	TMonom* tempcurr = new TMonom;
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

void TList::Remove(TMonom* monom)// удалить данный элемент
{
	TMonom* tempcurr = new TMonom;
	if (pCurr != monom)
	{
		tempcurr = pCurr;
	}
	else
	{
		while (this->pNext->data != monom->data)
			Next();
		if (pCurr->data != pStop->data)
		{
			tempcurr = pCurr;
		}
		else
		{
			Next();
			Next();
			tempcurr = pCurr;
			while (this->pNext->data != monom->data)
				Next();
		}
		Next();
	}
	while (this->pNext->data != monom->data)
		Next();
	if (pCurr->data == pStop->data)
	{
		RemoveFirst();
	}
	else
	{
		this->pCurr->pNext = this->pNext->pNext;
		delete pNext;
		this->Size--;
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
	pStop->pNext = pStop;
	pCurr = pStop;
	pNext = pStop;
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
		TMonom* temp = new TMonom;
		TMonom* temp2 = new TMonom;
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

TMonom* TList::GetFirstMonom()
{
	return pFirst;
}

TMonom* TList::GetMonom()
{
	return pCurr;
}

TMonom* TList::GetNextMonom()
{
	return pNext;
}

TMonom* TList::SearchSimilar(TData const data)// поиск подобного элемента в списке
{
	TMonom* nullmonom = new TMonom(-2, -2, -2, 0);
	if (IsEmpty() == 0 && GetLenght() > 1)
	{
		TMonom* tempcurr = new TMonom;
		tempcurr = pCurr;
		TMonom* tempsearch = new TMonom;
		TMonom* tempsimilar = new TMonom(data);
		Reset();
		if (pCurr->data != tempsimilar->data)
		{
			while (pCurr->data != tempsimilar->data)
			{
				Next();
			}
			tempsimilar = pCurr;
		}
		else
			tempsimilar = pCurr;
		Reset();
		for(int i = 0; i < GetLenght(); i++)
		{
			if (pCurr->data.degree == tempsimilar->data.degree && pCurr != tempsimilar)
			{
				tempsearch = pCurr;
				pCurr = tempcurr;
				pNext = pCurr->pNext;
				return tempsearch;
			}
			else
				tempsearch = nullmonom;
			Next();
		}
		pCurr = tempcurr;
		pNext = pCurr->pNext;
		return tempsearch;
	}
	else
		return nullmonom;
}