#pragma once

template <class TKey, class TData>
class Table
{
protected:
	int DataCount;
public:
	Table()
	{
		DataCount = 0;
	}
	virtual ~Table() {};
	int GetDataCount() const
	{
		return DataCount;
	}
	bool isEmpty() const
	{
		return DataCount == 0;
	}
	virtual bool isFull() const = 0;
	//virtual TKey GetKey()const = 0;
	//virtual TData* GetValuePtr() const = 0;
    virtual TData* Find(const TKey& k) = 0;
    virtual void Insert(const TKey& k, const TData& d) = 0;
    virtual void Delete(const TKey& k) = 0;
};

