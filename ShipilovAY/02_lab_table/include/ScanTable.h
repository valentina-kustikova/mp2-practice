#pragma once
#include "Table.h"
#include "ArrayHashTable.h"

template <class TData, class TKey>
class ScanTable : public ArrayTable<TData, TKey>
{
public:
	ScanTable(int Size = 10) : ArrayTable<TData, TKey>(Size) {};
	virtual ~ScanTable() {};
	virtual void Insert(const TData& _data, const TKey& _key);
	virtual void Delete(const TKey& _key);
	virtual TData* Search(const TKey& _key);
	virtual int GetMaxSize() { return MaxSize; };
	virtual int GetCurrent() { return current; };
};

template <class TData, class TKey>
void ScanTable<TData, TKey>::Insert(const TData& _data, const TKey& _key)
{
	for (int i = 0; i < this->Top; i++)
	{
		if ((*(this->DataTab[i])).GetKey() == _key)
		{
			throw "duplicated key";
		}
	}
	this->DataTab[this->Top++] = new TabRecord<TData, TKey>(_data, _key);
};

template <class TData, class TKey>
void ScanTable<TData, TKey>::Delete(const TKey& _key)
{
	int i = 0;
	int flag = 0;
	while ((i < this->Top) && (flag == 0)) {
		if ((*(this->DataTab[i])).GetKey() == _key) flag = 1;
		i++;
	}
	if (flag == 1) {
		i--;
		delete this->DataTab[i];
		while (i < this->Top - 1) {
			this->DataTab[i] = this->DataTab[i + 1];
			i++;
		}
		this->DataTab[i] = NULL;
		this->Top--;
	}
	else cout << "Element is not in AnSort" << '\n';
};

template <class TData, class TKey>
TData* ScanTable<TData, TKey>::Search(const TKey& _key)
{
	int i = 0;
	while (i < this->Top)
	{
		if ((*(this->DataTab[i])).GetKey() == _key)
			return this->DataTab[i]->GetData();
		i++;
	}
	throw "element doesn't exist";
};
