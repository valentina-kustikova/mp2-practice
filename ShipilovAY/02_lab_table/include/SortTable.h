#pragma once
#include "Table.h"
#include "ScanTable.h"

template <class TData, class TKey>
class SortTable : public ScanTable<TData, TKey>
{
private:
	int BinSearch(const TKey& Key) const;
	void merge(int left, int mid, int right);
	void SortData();
public:
	SortTable(int Size = 10) : ScanTable<TData, TKey>(Size) {};
	SortTable(const SortTable<TData, TKey>& Table);
	SortTable(const ScanTable<TData, TKey>& Table);
	virtual ~SortTable() {};
	virtual void Insert(const TData& _data, const TKey& _key);
	virtual void Delete(const TKey& _key);
	virtual int GetCurrent() { return current; };
	virtual TData* Search(const TKey& _key);
};

template <class TData, class TKey>
SortTable<TData, TKey>::SortTable(const SortTable<TData, TKey>& Table)
{
	MaxSize = Table.MaxSize;
	current = Table.current;
	Top = Table.Top;
	DataTab = new TabRecord<TData, TKey>*[MaxSize];
	for (int i = 0; i < current; i++)
	{
		DataTab[i] = new TabRecord<TData, TKey>(*(Table.DataTab[i]));
	}
}
template <class TData, class TKey>
SortTable<TData, TKey>::SortTable(const ScanTable<TData, TKey>& Table)
	:ScanTable(Table)
{
	SortData();
}

template <class TData, class TKey>
int SortTable <TData, TKey>::BinSearch(const TKey& _key) const
{
	int tail = this->Top - 1;
	int mid = 0;
	int start = 0;
	while (start <= tail)
	{
		mid = (tail + start) / 2;
		if ((*(this->DataTab[mid])).GetKey() < _key)
			start = mid + 1;
		else if ((*(this->DataTab[mid])).GetKey() > _key)
			tail = mid - 1;
		else return mid;
	}
	if (start > tail)
		mid = start;
	return mid;
}

template<class TData, class TKey>
inline void SortTable<TData, TKey>::merge(int left, int mid, int right)
{
	int il = 0;
	int ir = 0;
	TabRecord<TData, TKey>** res = new TabRecord<TData, TKey>*[right - left];

	while (left + il < mid && mid + ir < right)
	{
		if (*DataTab[left + il] < *DataTab[mid + ir])
		{
			res[il + ir] = DataTab[left + il];
			il++;
		}
		else
		{
			res[il + ir] = DataTab[mid + ir];
			ir++;
		}
	}
	while (left + il < mid)
	{
		res[il + ir] = DataTab[left + il];
		il++;
	}
	while (mid + ir < right)
	{
		res[il + ir] = DataTab[mid + ir];
		ir++;
	}

	for (int i = 0; i < il + ir; i++)
	{
		DataTab[left + i] = res[i];
	}

	delete[] res;
}

template <class TData, class TKey>
void SortTable <TData, TKey>::Insert(const TData& _data, const TKey& _key)
{
	int area = BinSearch(_key);
	int j;
	if ((this->DataTab[area] == NULL) || ((*(this->DataTab[area])).GetKey() != _key))
	{
		for (j = this->Top; j > area; j--)
			this->DataTab[j] = this->DataTab[j - 1];
		this->DataTab[j] = new TabRecord<TData, TKey>(_data, _key);
		this->Top++;
	}
	else throw "duplicate key";
}

template <class TData, class TKey>
void  SortTable <TData, TKey>::Delete(const TKey& _key)
{
	int area = BinSearch(_key);

	if ((this->DataTab[area] != NULL) && ((*(this->DataTab[area])).GetKey() == _key))
	{
		delete this->DataTab[area];
		for (int i = area; i < this->Top; i++)
			this->DataTab[i] = this->DataTab[i + 1];
		this->Top -= 1;
	}
	else
		cout << "Element not in Sort" << '\n';
}

template <class TData, class TKey>
TData* SortTable <TData, TKey>::Search(const TKey& _key)
{
	int area = BinSearch(_key);
	if ((this->DataTab[area] != NULL) && ((*(this->DataTab[area])).GetKey() == _key))
		return this->DataTab[area]->GetData();
	else throw "element doesn't exist";
}

template <class TData, class TKey>
void SortTable<TData, TKey>::SortData()//написать сортировку слиянием
{
	for (int i = 1; i < Top; i *= 2)
	{
		for (int j = 0; j < Top - i; j += 2 * i)
		{
			merge(j, j + i, min(j + 2 * i, Top));
		}
	}
}
