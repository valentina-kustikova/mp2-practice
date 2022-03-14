#pragma once
#include <iostream>

template <class TKey, class TData>
class TabRecord
{
protected:
	TKey key;
	TData* p_value;
public:
	TabRecord()
		:p_value(nullptr) {}
	TabRecord(TKey _key, TData* _value)
		:key(_key), p_value(_value) {}
	~TabRecord() {}
	TabRecord& operator=(const TabRecord& tr)
	{
		key = tr.key;
		p_value = tr.p_value;
		return *this;
	}
	void SetKey(TKey _key)
	{
		key = _key;
	}
	TKey GetKey()
	{
		return key;
	}
	void SetValuePtr(TData* ptr)
	{
		p_value = ptr;
	}
	TData* GetValuePtr()
	{
		return p_value;
	}
	bool operator==(const TabRecord& tr)
	{
		return key == tr.key;
	}
	bool operator<(const TabRecord& tr)
	{
		return key < tr.key;
	}
	bool operator>(const TabRecord& tr)
	{
		return key > tr.key;
	}
	void Print()
	{
		std::cout << key << " - " << *p_value << std::endl;
	}
};

