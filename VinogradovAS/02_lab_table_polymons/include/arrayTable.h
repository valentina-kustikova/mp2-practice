#pragma once 
#include <iostream>
#include "table.h" 


template <typename TData, typename TKey>
class ArrayTable : public Table<TData, TKey> 
{
protected:
	int maxSize;
	int index;
	TabRecord<TData, TKey>** rec;
public:
	
	
	ArrayTable(int maxSize =10);
	virtual ~ArrayTable() { delete[] rec; }

	 virtual void Insert(TData data,TKey key) = 0 ;
	 virtual TData* Search(const TKey key) = 0;
	 virtual void Delete(const TKey key) = 0;

	void Reset();
	bool IsFull() const;
	void Next();
	bool IsTabEnded() const { return index == count || index == -1; }// признак окончания таблицы
	TData* GetData() const;
	TKey GetKey() const;
		
	int  GetMaxSize() const { return maxSize; }
	int  GetIndex() const { return index; }
	


};

template<typename TData, typename TKey>
ArrayTable<TData, TKey>::ArrayTable(int maxSize)
{
	this->maxSize = maxSize;
	this->index = -1;
	rec = new TabRecord<TData, TKey>*[maxSize];
}



template<typename TData, typename TKey>
void ArrayTable<TData, TKey>::Reset()
{
	if (count > 0) {
		index = 0;
	}
	else {
		index = -1;
	}
}

template<typename TData, typename TKey>
bool ArrayTable<TData, TKey>::IsFull() const
{
	if (count == maxSize) {
		return true;
	}
	else {
		return false;
	}
}


template<typename TData, typename TKey>
void ArrayTable<TData, TKey>::Next()
{
	if (count > 0) {
		index++;
	}
	else {
		throw - 1;
	}

}

template<typename TData, typename TKey>
inline TData* ArrayTable<TData, TKey>::GetData() const
{
	if (count > 0) {
		return rec[index]->GetData();
	}
	else {
		throw - 1;
	}
}

template<typename TData, typename TKey>
inline TKey ArrayTable<TData, TKey>::GetKey() const
{
	if (count > 0) {
		return rec[index]->GetKey();
	}
	else {
		throw - 1;
	}
}






