#ifndef _SCANTABLE_H_
#define _SCANTABLE_H_

#include "Table.h"

#include <iostream>

template<typename TKey, typename TData>
class TScanTable : public Table<TKey, TData>
{
protected:

	TTabRecord<TKey, TData>** recs;

public:

	TScanTable(int _maxSize = 100);
	TScanTable(const TScanTable<TKey, TData>& ScanTable);
	virtual ~TScanTable();

	virtual void Insert(const TKey& _key, TData* _data);
	virtual void Remove(const TKey& _key);
	virtual TTabRecord<TKey, TData>* Find(const TKey& _key);


	friend ostream& operator<<(ostream& out, const TScanTable<TKey, TData>& st)
	{
		if (st.IsEmpty())
		{
			out << "table is empty" << endl;
			return out;
		}
		out << "______________________________________" << endl;
		for (int i = 0; i < st.GetCount(); i++)
		{
			out /*<< "|" << st.recs[i]->GetKey() << " | "*/ << *(st.recs[i]->GetData()) << "|" << endl;
		}
		out << "______________________________________" << endl;
		return out;
	}

};

template<typename TKey, typename TData>
TScanTable<TKey, TData>::TScanTable(int _maxSize)
{
	if (_maxSize <= 0)
	{
		throw"Error";
	}

	this->maxSize = _maxSize;
	recs = new TTabRecord<TKey, TData>*[this->maxSize];
	for (int i = 0; i < this->maxSize; i++)
	{
		recs[i] = nullptr;
	}
	this->count = 0;
	this->currPos = -1;
}

template<typename TKey, typename TData>
TScanTable<TKey, TData>::TScanTable(const TScanTable<TKey, TData>& ScanTable)
{
	this->maxSize = ScanTable.maxSize;
	this->count = ScanTable.count;
	this->currPos = ScanTable.currPos;

	recs = new TTabRecord<TKey, TData>*[this->maxSize];
	for (int i = 0; i < this->count; i++)
	{
		TKey _key = ScanTable.recs[i]->key;
		TData* _data = ScanTable.recs[i]->data;
		recs[i] = new TTabRecord<TKey, TData>(_key, _data);
	}
}


template<typename TKey, typename TData>
TScanTable<TKey, TData>::~TScanTable()
{
	if (recs != nullptr)
	{
		for (int i = 0; i < this->count; i++)
		{
			if (recs[i] != nullptr)
				delete recs[i];
		}
		delete recs;
	}
}

template<typename TKey, typename TData>
void TScanTable<TKey, TData>::Insert(const TKey& _key, TData* _data)
{
	if (this->IsFull())
	{
		throw"Error";
	}
	TTabRecord<TKey, TData>* flag = Find(_key);
	if (flag != nullptr)
	{
		throw"Error: record is exist";
	}
	else
	{
		recs[this->count] = new TTabRecord<TKey, TData>(_key, _data);
		this->count++;
	}

}

template<typename TKey, typename TData>
void TScanTable<TKey, TData>::Remove(const TKey& _key)
{
	if (this->IsEmpty())
	{
		throw"Error";
	}
	if (Find(_key) != nullptr)
	{
		delete recs[this->currPos];
		recs[this->currPos] = recs[(this->count) - 1];
		this->count--;
	}
	else
	{
		throw"Error";
	}
}

template<typename TKey, typename TData>
TTabRecord<TKey, TData>* TScanTable<TKey, TData>::Find(const TKey& _key)
{
	TTabRecord<TKey, TData>* res = nullptr;

	for (int i = 0; i < this->count; i++)
	{
		if (recs[i]->GetKey() == _key)
		{
			this->currPos = i;
			res = recs[i];
			break;
		}
	}
	return res;
}

















#endif // !_SCANTABLE_H_


