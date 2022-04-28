#pragma once 
#include <iostream>


using namespace std;
template <typename TData, typename TKey>
class TabRecord {
	
protected:
	TKey key;
	TData* data;
public:
	
	TabRecord() {
		key = {};
		data = {};
	}

	TabRecord(TKey key = {}, TData data = {}) {
		this->key = key;
		this->data = new TData(data);
	}

	TabRecord(const TabRecord& other) {
		this->key = other.key;
		this->data = new TData(*(other.data));
	}
	 TData* GetData() { return data; }
	 TKey GetKey() { return key; }
	
	TabRecord<TData, TKey>& operator=(const TabRecord<TData, TKey>& TabR)
	{
		data = new TData(*(TabR.data)); key = TabR.key; return *this;
	}
	bool operator<(const TabRecord<TData, TKey>& tr) const
	{
		return key < tr.key;
	}
	bool operator!=(const TabRecord<TData, TKey>& TabR) const
	{
		return !(this->key == TabR.key);
	}
};


template <typename TData, typename TKey>
class Table {
	public:
	TabRecord<TData, TKey>** rec;
	int maxSize;
	int count;
	int index;
	//virtual void Repacking() = 0;

	Table(int maxSize =10);
	virtual ~Table() { delete[] rec; }

	 virtual void Insert(TData data,TKey key) = 0 ;
	 virtual TData* Search(const TKey key) = 0;
	 virtual void Delete(const TKey key) = 0;

	void Reset();
	bool IsFull() const;
	bool IsEmpty() const;
	void Next();
	bool IsTabEnded() const { return index == count || index == -1; }// признак окончания таблицы
	TData* GetData() ;
	TKey GetKey() ;
	int const GetCount() { return count; }
	int const GetMaxSize() { return maxSize; }
	int const GetIndex() { return index; }
	template<class TData> friend std::ostream& operator<< (std::ostream& os, const Table<TData, TKey>& Tab)
	{
		 int i = 0;
		while (i < Tab.count)
		{
			os << "\t" << left << Tab.rec[i]->GetKey() << " | " << *(Tab.rec[i]->TabRecord<TData, TKey>::GetData()) << '\n';
			i++;
		}
		if (Tab.count == 0)
			os << "\n\tTable is Empty\n";
		return os;
	}


};

template<typename TData, typename TKey>
Table<TData, TKey>::Table(int maxSize)
{
	this->maxSize = maxSize;
	this->count = 0;
	this->index = -1;
	rec = new TabRecord<TData, TKey>*[maxSize];
}



template<typename TData, typename TKey>
void Table<TData, TKey>::Reset()
{
	if (count > 0) {
		index = 0;
	}
	else {
		index = -1;
	}
}

template<typename TData, typename TKey>
bool Table<TData, TKey>::IsFull() const
{
	if (count == maxSize) {
		return true;
	}
	else {
		return false;
	}
}

template<typename TData, typename TKey>
inline bool Table<TData, TKey>::IsEmpty() const
{
	if (count == 0) {
		return true;
	}
	else {
		return false;
	}
}

template<typename TData, typename TKey>
void Table<TData, TKey>::Next()
{
	if (count >= 0) {
		index++;
	}
	else {
		throw - 1;
	}

}

template<typename TData, typename TKey>
inline TData* Table<TData, TKey>::GetData() 
{
	return rec[index]->GetData();
	
}

template<typename TData, typename TKey>
inline TKey Table<TData, TKey>::GetKey() 
{
	return rec[index]->GetKey();
}






