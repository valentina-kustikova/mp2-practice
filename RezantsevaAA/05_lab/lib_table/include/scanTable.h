#ifndef __SCANTABLE_H__
#define __SCANTABLE_H__
#include "table.h"
#include <iomanip>
template<typename TKey, typename TData>
class TScanTable : public TTable<TKey,TData>
{
protected:
	TTabRecord<TKey, TData>** records;
public:
	TScanTable(int _maxSize);
	TScanTable(const TScanTable<TKey, TData>& obj);
	~TScanTable();
	//
	void Insert(const TKey& k, const TData& d)  override;
	virtual void Remove(const TKey& k) override;
	virtual TTabRecord<TKey, TData>* Find(const TKey& k) override;
	//Get
	virtual TKey GetKey() const override;
	virtual TData* GetData() const override;

	friend std::ostream& operator<<(std::ostream& out, const TScanTable<TKey, TData>& stab)
	{
		std::cout << "-------------------------------------" << std::endl;
		for (int i = 0; i < stab.maxSize; i++) {

			if (stab.records[i] != nullptr)
			{
				out << "| " << std::setw(20) << stab.records[i]->GetKey() << " | " << std::setw(20) << *(stab.records[i]->GetData()) << std::endl;

			}
		}
		return out;
	}

};

template<typename TKey, typename TData> TScanTable<TKey, TData>::TScanTable(int _maxSize) 
{
	records = new TTabRecord<TKey, TData>*[_maxSize]();
	for (int i = 0; i < _maxSize; i++)
	{
		records[i] = nullptr;
	}
	size = 0;
	currPos = 0;
	maxSize = _maxSize;
}
template<typename TKey, typename TData> TScanTable<TKey, TData>::TScanTable(const TScanTable<TKey, TData>& obj)
{
	size = obj.size;
	currPos = obj.currPos;
	maxSize = obj.maxSize;

	records = new TTabRecord<TKey, TData>*[maxSize]();
	for (int i = 0; i < maxSize; i++)
	{
		if (obj.records[i])
			records[i] = new TTabRecord<TKey, TData>(*obj.records[i]);
		else
			records[i] = nullptr;
	}
}
template<typename TKey, typename TData> TScanTable<TKey, TData>::~TScanTable()
{
	for (int i = 0; i < maxSize; i++)
	{
		if (records[i])
		{
			delete records[i];
		}
	}
	delete[] records;
}

template<typename TKey, typename TData> void TScanTable<TKey, TData>::Insert(const TKey& k, const TData& d)
{
	if (IsFull())
	{
		throw "Table is full. Can't insert";
	}
	records[size++] = new TTabRecord<TKey,TData>(k, d);
}

template<typename TKey, typename TData> TTabRecord<TKey, TData>* TScanTable<TKey, TData>::Find(const TKey& k)
{
	for (int i = 0; i < size; i++)
	{
		if (records[i]->GetKey() == k) {
			currPos = i;
			return records[i];
		}
	}
	return nullptr;
}

template<typename TKey, typename TData> void TScanTable<TKey, TData>::Remove(const TKey& k)
{
	if ( this->IsEmpty()) {
		throw "Nothing to remove. Table is empty";
	}
	if (this->Find(k) != nullptr) {
		delete records[currPos];
		for (int i = currPos; i < size; i++) {
			records[i] = records[i + 1];
			size--;
		}
	}
	else
		throw "Record not found";

}

template <class TKey, class TData> TKey TScanTable<TKey, TData>::GetKey() const
{
	if (currPos < size)
		return records[currPos]->GetKey();
	else
	{
		throw "Can't get key.Current position is out of range";
	}
}
template <class TKey, class TData> TData* TScanTable<TKey, TData>::GetData() const
{
	if (currPos < size)
		return records[currPos]->GetData();
	else
	{
		throw "Can't get data. Current position is out of range";
	}
}

#endif