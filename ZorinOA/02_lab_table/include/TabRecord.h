#pragma once
#include <iostream>

template <class TKey, class TData>
class TabRecord
{
protected:
	TKey key;
    TData data;
public:
	TabRecord() 
	{
		key = TKey();
		data = TData();
	}
    TabRecord(TKey _key, TData _data)
        :key(_key), data(_data) {}
	TabRecord(TKey _key)
		:key(_key) 
	{
		data = TData();
	}
	~TabRecord() {}
	TabRecord& operator=(const TabRecord& tr)
	{
		key = tr.key;
        data = tr.data;
		return *this;
	}
	void SetKey(TKey _key)
	{
		key = _key;
	}
    TKey GetKey() const
	{
		return key;
	}
    void SetData(TData _data)
	{
        data = _data;
	}
    TData& GetData()
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
		os << "|\t" << tr.key << "\t:\t " << tr.data << "\t|";
		return os;
	}
};

