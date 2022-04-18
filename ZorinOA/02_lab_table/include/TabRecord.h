#pragma once
#include <iostream>

template <class TKey, class TData>
class TabRecord
{
protected:
	TKey key;
    TData* data;
public:
	TabRecord(const TKey& _key = ())
		:key(_key), data(nullptr) {}
	TabRecord(const TKey& _key, const TData& _data)
		:key(_key), data(new TData(_data)) {}
	TabRecord(const TabRecord& tr)
		:key(tr.key), data(new TData(*(tr.data))) {}
	~TabRecord()
	{
		delete data;
	}
	TabRecord& operator=(const TabRecord& tr)
	{
		key = tr.key;
		delete data;
		data = new TData(*(tr.data));
		return *this;
	}
    TKey GetKey() const
	{
		return key;
	}
    TData* GetData() const
	{
        return data;
	}
    bool operator==(const TabRecord& tr) const
	{
		return key == tr.key;
	}
    bool operator<(const TabRecord& tr) const
	{
		return key < tr.key;
	}
    bool operator>(const TabRecord& tr) const
	{
		return key > tr.key;
	}

	friend std::ostream& operator<<(std::ostream& os, const TabRecord& tr)
	{
        os << "key: " << tr.key << ", data:  " << *(tr.data);
		return os;
	}
};

