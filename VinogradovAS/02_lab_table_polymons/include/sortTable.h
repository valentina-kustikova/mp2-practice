#pragma once 
#include <iostream>
//#include "table.h"
#include "scanTable.h"
using namespace std;

template <typename TData, typename TKey>
class SortTable : public ScanTable<TData, TKey>
{
protected:
	void Sort() {
		int indexMin = 0;
		TabRecord<TData, TKey>* tmp;
		for (int i = 0; i < this->count - 1; i++)
		{
			indexMin = i;
			for (int j = i; j < this->count; j++)
			{
				if (this->rec[j]->GetKey() < this->rec[indexMin]->GetKey()) {
					indexMin = j;
				}
			}
			tmp = rec[i];
			rec[i] = rec[indexMin];
			rec[indexMin] = tmp;
		}
		
	}
public:
	SortTable(int maxSize = 10) : ScanTable<TData, TKey>(maxSize) {};
	SortTable(const SortTable<TData, TKey>& other) : ScanTable<TData, TKey>(other) {};
	SortTable(const ScanTable<TData, TKey>& other) : ScanTable<TData, TKey>(other) {
		Sort();
	};
	~SortTable() {}
	 TData* Search(const TKey Key);
	void Insert(TData Data, TKey Key);

	void Delete(const TKey Key);
	SortTable<TData, TKey>& operator = (const SortTable<TData, TKey>& other) {
		return *this;
	}
};


template<typename TData, typename TKey>
inline TData* SortTable<TData, TKey>::Search(const TKey Key)
{
	this->Reset();
	int left = 0;
	int right = count - 1;
	int middle = 0;
    bool flag = false;
	while (left <= right && flag != true) {
		middle = (left + right) / 2;
			if (rec[middle]->GetKey() == Key)
			{
				flag = true;
			}
		if (rec[middle]->GetKey() > Key)
		{
			right = middle - 1;
		}
		else {
			left = middle + 1;
		}
		
	}
	if (flag == true)
	{
		index = middle;
		return rec[middle]->GetData();
	}
	else
	{
		return nullptr;
	}
	
	
}

template<typename TData, typename TKey>
inline void SortTable<TData, TKey>::Insert(TData Data, TKey Key)
{
	TabRecord<TData, TKey> ins(Key, Data);

	if (this->IsFull()) {
		throw "ScanTable is full";
	}

	this->Table<TData, TKey>::Reset();
	Reset();
	while (!IsTabEnded() && Key >= rec[index]->GetKey()) {
		if (Key == rec[index]->GetKey()) {
			throw "The element exists in the table";
		}
		index++;
	}
	if (IsEmpty()) {
		index++;
	}
	count++;
	for (int i = count - 1; i > index; i--)
	{
		rec[i] = rec[i - 1];
	}
	
	rec[index] = new TabRecord<TData, TKey>(ins);

}

template<typename TData, typename TKey>
inline void SortTable<TData, TKey>::Delete(const TKey Key)
{
	if (Search(Key) != nullptr) {
		//delete this->rec[index];
		this->count = this->count - 1;
		this->rec[this->index] = new TabRecord<TData, TKey>(*this->rec[this->count]);
		delete this->rec[count];
		this->index = this->count - 1;
		Sort();
	}
	else {
		throw "the element does not exist";
	}
}



