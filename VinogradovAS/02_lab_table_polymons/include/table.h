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
	 TData* GetData() const { return data; }
	 TKey GetKey() const { return key; }
	
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
class Table  {
protected:
	int count;
public:
	
	Table() { count = 0; }
	virtual ~Table() {};

	 virtual void Insert(TData data,TKey key) = 0 ;
	 virtual TData* Search(const TKey key) = 0;
	 virtual void Delete(const TKey key) = 0;

	 virtual void Reset() = 0;
	 virtual bool IsFull() const = 0;
	 bool IsEmpty() const {
		 return count == 0;
	}
	virtual void Next() = 0;
	virtual bool IsTabEnded() const = 0;// признак окончания таблицы
	virtual TData* GetData() const = 0 ;
	virtual TKey GetKey() const = 0 ;
	int  GetCount()const {return count;}
		
	virtual int  GetMaxSize()const = 0;
	virtual int  GetIndex()const = 0;


};








