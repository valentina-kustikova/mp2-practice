#pragma once
#include "polinom.h"
template <typename TData, typename TKey>
class TTabRecord
{
public:
	TData* data;
	TKey key;
	TTabRecord(TKey key)
	{
		this->data = nullptr;
		this->key = key;
	}
	TTabRecord(TData data, TKey key)
	{
		this->data = new TData(data);
		this->key = key;
	}
	~TTabRecord() {};
	TData* GetData() const
	{
		return data;
	}
	TKey GetKey() const
	{
		return key;
	}
	friend std::ostream& operator<<(std::ostream& out, TTabRecord<TData, TKey>* rec )
	{
	    out << "Key:" << rec->key << " Polinom: " << *rec->data << '\n';
	    return out;
	}
};