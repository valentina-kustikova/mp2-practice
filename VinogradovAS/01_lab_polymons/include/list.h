
#pragma once
#include <iostream>
#include <sstream>
#include <string>


template <class T>
class TList
{
protected:
	TNode<T>* pFirst; // первый
	TNode<T>* pLast; // последний
	//для добавления в середину
	TNode<T>* pPrev; //предыдущий
	TNode<T>* pCurr;//текущий
	
	TNode<T>* pStop;
	int length;

public:

	TList();
	virtual ~TList();

	bool IsEmpty();
	TNode<T>* GetFirst(){ return pFirst };
	TNode<T>* GetEnd(){ return pStop };
	//Добавление элемента в начало списка
	virtual void InsFirst(T element);
	//Добавление элемента в конец списка
	void InsLast(T element);
	//Добавление элемента в текущую позицию (перед текущим) (текущим становится добавленный)
	void InsCurr(T element);

	//Удаление первого элемента списка
	virtual void DelFirst();
	//Удаление текущего элемента списка (текущим становится следующий за ним)
	void DelCurr();

	//Получение текущего элемента списка
	T GetCurr() const;

	//Возврат итератора в исходное состояние
	void Reset();
	//Перевод итератора далее
	void GoNext();
	//Проверка на достижение итератором конца списка
	bool IsEnd() const; 

	std::string ToStr() const; 

	friend std::ostream& operator<<(std::ostream& os,TList<T>& l)
	{
		os << "[ ";
		TNode<T>* t = l.pFirst;

		while (t != l.pStop)
		{
			os << t->value << " ";
			t = t->pNext;
		}
		os << "]";
		return os;
	}
};

template <class T>
TList<T>::TList()
{
	pStop = nullptr;
	pFirst = pLast = pPrev = pCurr = pStop;
	length = 0;
}

template <class T>
TList<T>::~TList()
{
	while (pFirst != pStop)
	{
		TNode<T>* tmp = pFirst;
		pFirst = pFirst->pNext;
		delete tmp;
	}
}

template <class T>
bool TList<T>::IsEmpty()
{
	return pFirst == pStop;
}



template <class T>
void TList<T>::InsFirst(T element)
{
	TNode<T>* newNode = new TNode<T>();
	newNode->value = element;
	newNode->pNext = pFirst;
	pFirst = newNode;
	length++;
	if (length == 1)
		pLast = pFirst;
}

template <class T>
void TList<T>::InsLast(T element)
{
	if (length > 0)
	{
		TNode<T>* newNode = new TNode<T>();
		newNode->value = element;
		newNode->pNext = pStop;

		pLast->pNext = newNode;
		pLast = newNode;
		length++;
	}
	else
	{
		InsFirst(element);
	}
}

template <class T>
void TList<T>::InsCurr(T element)
{
	if (pCurr == pFirst)
	{
		InsFirst(element);
		pPrev = pFirst; 
	}
	else if (pPrev == pLast)
	{
		InsLast(element);
		pPrev = pLast; 
	}
	else
	{
		TNode<T>* newNode = new TNode<T>();
		newNode->value = element;

		newNode->pNext = pCurr;
		pPrev->pNext = newNode;
		pCurr = newNode;
		length++;
	}
}

template <class T>
void TList<T>::DelFirst()
{
	if (pFirst == pStop)
		throw "Не могу удалить первый элемент";

	TNode<T>* tmp = pFirst;
	pFirst = pFirst->pNext;
	delete tmp;
	length--;
}

template <class T>
void TList<T>::DelCurr()
{
	if (pCurr == pStop)
		throw "Не могу удалить первый элемент";

	if (pCurr == pFirst)
	{
		DelFirst();
		pPrev = pStop; 
		pCurr = pFirst;
	}
	else
	{
		TNode<T>* tmp = pCurr;
		pCurr = pCurr->pNext;
		pPrev->pNext = pCurr;
		delete tmp;
		length--;
	}
}

template <class T>
T TList<T>::GetCurr() const
{
	if (pCurr == pStop)
		throw "Не могу дать первый элемент";
	return pCurr->value;
}

template <class T>
void TList<T>::Reset()
{
	pPrev = pStop;
	pCurr = pFirst;
}

template <class T>
void TList<T>::GoNext()
{
	pPrev = pCurr;
	pCurr = pCurr->pNext;
}

template <class T>
bool TList<T>::IsEnd() const
{
	return pCurr == pStop;
}



template <class T>
std::string TList<T>::ToStr() const
{
	std::stringstream ss;
//	Print(ss);
	return ss.str();
}