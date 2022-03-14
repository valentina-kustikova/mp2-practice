#pragma once
#include <iostream>

template <class TKey, class TData>
class TabRecord
{
protected:
	TKey key;
    TData data;
public:
	TabRecord() {}
    TabRecord(TKey _key, TData _data)
        :key(_key), data(_data) {}
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
    void Print() const
	{
        std::cout << key << " - " << data << std::endl;
	}
};

