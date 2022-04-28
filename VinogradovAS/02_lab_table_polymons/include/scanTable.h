#pragma once
#include "table.h" 
using namespace std;

template <typename TData, typename TKey>
class ScanTable : public Table<TData, TKey>
{

public:
	ScanTable(int maxSize = 10) : Table(maxSize) {};
	ScanTable(const ScanTable<TData, TKey>& other);
	 ~ScanTable() {};
	 virtual TData* Search(const TKey Key) override;
	 virtual void Insert(TData Data,TKey Key) override;
	
	 virtual void Delete(const TKey Key) override;

};

template<typename TData, typename TKey>
 ScanTable<TData, TKey>::ScanTable(const ScanTable<TData, TKey>& other)
{
	this->count = other.count;
	this->index = other.index;
	this->maxSize = other.maxSize;
	this->rec = new TabRecord<TData, TKey>*[maxSize];
	
	for (int i = 0; i < this->count; i++)
	{
		this->rec[i] = new TabRecord<TData, TKey>(*(other.rec[i]));
	}
}

template<typename TData, typename TKey>
inline TData* ScanTable<TData, TKey>::Search(const TKey Key)
{
	Reset();
	while (!(IsTabEnded()) && (this->rec[this->index]->GetKey() != Key)) {
		index++;
	}
	if (!(this->IsTabEnded())) {
		return rec[index]->GetData();
	}
	else {
		return nullptr;
	}
	
}

template<typename TData, typename TKey>
inline void ScanTable<TData, TKey>::Insert(TData Data, TKey Key)
{
	TabRecord<TData, TKey> ins(Key, Data);
	if (this->IsFull()) {
		throw "ScanTable is full";
	}
	this->Table<TData, TKey>::Reset();
	if (IsEmpty() || Search(Key) == nullptr) {
		rec[count] = new TabRecord<TData, TKey>(ins);
		count++;
	}
	else {
		throw "Element already exists";
	}
	
	
}


template<typename TData, typename TKey>
inline void ScanTable<TData, TKey>::Delete(const TKey Key)
{
	
	if (Search(Key) != nullptr) {
		//delete this->rec[index];
		this->count = this->count - 1;
		this->rec[this->index] = new TabRecord<TData, TKey>(*this->rec[this->count]);
		delete this->rec[count];
		this->index = this->count - 1;
	}
}




