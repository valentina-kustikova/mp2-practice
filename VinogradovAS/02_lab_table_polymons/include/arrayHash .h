#pragma once 
#include <iostream>
#include "table.h" 


template<typename TData, typename TKey>
class ArrayHash : public Table<TData, TKey>
{
protected:
	TabRecord<TData, TKey>** rec;
	char* pMark; // маркер для обозначения удаленных записей
	int hashStep;
	int index;
	int maxSize;
public:
	
	int hashFunc(const TKey& Key);
	int hashFunc2(int pos);
	ArrayHash(int maxSize = 10, int step = 1)
		//ArrayTable<TData, TKey>(maxSize)
	{

		this->maxSize = maxSize;
		this->index = -1;
		rec = new TabRecord<TData, TKey>*[maxSize];
		hashStep = step;
		pMark = new char[maxSize];
		for (int i = 0; i < maxSize; i++)
		{
			pMark[i] = 0; // пусто
		}
	};
	virtual ~ArrayHash() {
		delete[] rec;
	}
	bool IsTabEnded() const { return index == count || index == -1; }
	virtual void Insert(const TData Data, const TKey Key) = 0;
	virtual TData* Search(const TKey Key) = 0;
	virtual void Delete(const TKey Key) = 0;
	virtual void Next();
	void Reset();
	bool IsFull() const;
	TData* GetData() const;
	TKey GetKey() const;
	int  GetMaxSize() const { return maxSize; }
	int  GetIndex() const { return index; }
	


};

template<typename TData, typename TKey>
inline int ArrayHash<TData, TKey>::hashFunc(const TKey& Key)
{
	int result = 0;
	for (int i = 0; i < Key.length(); i++) {
		result = result + int(Key[i]);
	}
	return result % maxSize;
}

template<typename TData, typename TKey>
inline int ArrayHash<TData, TKey>::hashFunc2(int pos)
{
	return (pos + hashStep) % this->maxSize;
}

//template<typename TData, typename TKey>
//inline ArrayHash<TData, TKey>::~ArrayHash()
//{
//	delete[]pMark;
//}



template<typename TData, typename TKey>
inline void ArrayHash<TData, TKey>::Reset()
{
	/*if (count != 0) {
		index = 0;
	}
	else {
		index = -1;
	}*/

	if (count)
	{
		index = 0;
		while (pMark[index] != 1)
		{
			index++;
		}
	}
	else
	{
		index = -1;
	}

}

template<typename TData, typename TKey>
inline bool ArrayHash<TData, TKey>::IsFull() const
{
	
		if (count == maxSize) {
			return true;
		}
		else {
			return false;
		}
	
}

template<typename TData, typename TKey>
inline void ArrayHash<TData, TKey>::Next()
{
	if (!IsTabEnded()) {
		while (index < maxSize) {
			if (rec[index] != nullptr && pMark[index] != 1) {
				break;
			}
			else {
				index++;
			}
		}
	}

	
}

	template<typename TData, typename TKey>
	inline TData* ArrayHash<TData, TKey>::GetData() const
	{
		if (count > 0) {
			return rec[index]->GetData();
		}
		else {
			throw - 1;
		}

		
	}

	template<typename TData, typename TKey>
	inline TKey ArrayHash<TData, TKey>::GetKey() const
	{
		if (count > 0) {
			return rec[index]->GetKey();
		}
		else {
			throw - 1;
		}

		
	}






