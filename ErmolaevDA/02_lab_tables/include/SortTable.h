#pragma once
#include "ScanTable.h"
#include "TabRecord.h"
//Класс упорядоченные таблицы
template <typename TData, typename TKey>
class SortTable : public ScanTable<TData,TKey>
{ 
  public:
  void SortData(); // метод сортировки записей по ключам
  // Конструкторы, деструктор	
  SortTable(unsigned int n = 10) : ScanTable<TData,TKey>(n) {};
  SortTable(const SortTable<TData,TKey>& T1);
  SortTable(const ScanTable<TData,TKey>& T1);
  ~SortTable() {};
  // Методы 
  virtual void Insert(const TData data, const TKey key);
  virtual TData* Search(const TKey key);
  virtual void Delete(const TKey key);
};

// Pелизация функциий для класса упорядоченных таблиц
// Конструктор
template <typename TData, typename TKey>
SortTable<TData, TKey>::SortTable(const SortTable<TData, TKey>& T1)
{
	Size = T1.Size;
	ind = T1.ind;
	dataCount = T1.dataCount;
	rec = new TabRecord<TData, TKey>*[Size];
	for (int i = 0; i < dataCount; i++)
	{
		rec[i] = new TabRecord<TData, TKey>(*(T1.rec[i]));
	}
}
template <typename TData, typename TKey>
SortTable<TData, TKey>::SortTable(const ScanTable<TData, TKey>& T1) //Здесь было Scan
{
	Size = T1.Size;
	dataCount = T1.dataCount;
	ind = T1.ind;
	rec = new TabRecord<TData, TKey>*[Size];
	for (int i = 0; i < dataCount; i++)
	{
		rec[i] = T1.rec[i];
	}
	SortData();
}
// Методы 
template <typename TData, typename TKey>
void SortTable<TData, TKey>::Insert(const TData data, const TKey key)
{
	if (IsFull()) { throw 1; } //Таблица переполнена
	TabRecord<TData, TKey> R(key, data);
	Reset();
	while (!(IsEnd()) && key >= rec[ind]->GetKey())
	{
		if (rec[ind]->GetKey() == key)
		{
			throw - 1;
		} //Ключ уже есть в таблице
		ind++;
	}
	if (IsEmpty())
	{
		ind++;
	}
	dataCount++;
	for (int i = dataCount - 1; i > ind; i--)
	{
		rec[i] = rec[i - 1];
	}
	rec[ind] = new TabRecord<TData, TKey>(R);
	Reset();
}
template <typename TData, typename TKey>
TData* SortTable<TData, TKey>::Search(const TKey key)
{
	Reset();
	TData* tmp = nullptr;
	if (!(IsEmpty()))
	{
		int i = -1, j = dataCount;
		int mid;
		while (i < j - 1)
		{
			mid = (j + i) / 2;
			if (key >= rec[mid]->GetKey())
			{
				i = mid;
			}
			else
			{
				j = mid;
			}
		}
		if (key == rec[i]->GetKey())
		{
			ind = i;
			tmp = rec[ind]->GetData();
		}
		else
		{
			return nullptr;
		}
	}
	else
	{
		throw 1;
	}
	return tmp;
}
template <typename TData, typename TKey>
void SortTable<TData, TKey>::Delete(const TKey key)
{
	Reset();
	if (Search(key) == nullptr)
	{
		throw 1;
	} // элемента для удаления нет в таблице
	else
	{
		if (dataCount > 1)
		{
			dataCount--;
			for (int i = ind; i < dataCount; i++)
			{
				rec[i] = rec[i + 1];
			}
			Reset();
		}
		else
		{
			dataCount = 0;
		}
	}
}
template <typename TData, typename TKey>
void SortTable<TData, TKey>::SortData()
{
	int i, j;
	/*for (i = 0; i < dataCount; i++)
	{ for (j = 0; j < dataCount; j++)
	  { if (rec[i]->GetKey() < rec[j]->GetKey())
		{ TabRecord<TData,TKey>* temp (rec[i]);
		 rec[i] = rec[j];
		 rec[j] = temp;
		}
	  }
	}*/
	for (int i = 0; i < dataCount; i++) {
		bool flag = true;
		for (int j = 0; j < dataCount - (i + 1); j++) {
			if (rec[j]->GetKey() < rec[j + 1]->GetKey()) {
				flag = false;
				TabRecord<TData, TKey>* temp;
				temp = rec[j];
				rec[j] = rec[j + 1];
				rec[j + 1] = temp;
			}
		}
		if (flag) {
			break;
		}
	}
}
