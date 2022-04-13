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
  SortTable(unsigned int n = 100) : ScanTable<TData,TKey>(n) {};
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
    this->Size = T1.Size;
    this->ind = T1.ind;
    this->dataCount = T1.dataCount;
    this->rec = new TabRecord<TData, TKey>*[this->Size];
    for (int i = 0; i < this->dataCount; i++)
	{
        this->rec[i] = new TabRecord<TData, TKey>(*(T1.rec[i]));
	}
}
template <typename TData, typename TKey>
SortTable<TData, TKey>::SortTable(const ScanTable<TData, TKey>& T1) //Здесь было Scan
{
    this->Size = T1.Size;
    this->dataCount = T1.dataCount;
    this->ind = T1.ind;
    this->rec = new TabRecord<TData, TKey>*[this->Size];
    for (int i = 0; i < this->dataCount; i++)
	{
        this->rec[i] = T1.rec[i];
	}
	SortData();
}
// Методы 
template <typename TData, typename TKey>
void SortTable<TData, TKey>::Insert(const TData data, const TKey key)
{
    if (this->IsFull()) { throw 1; } //Таблица переполнена
	TabRecord<TData, TKey> R(key, data);
    this->Reset();
    while (!(this->IsEnd()) && key >= this->rec[this->ind]->GetKey())
	{
        if (this->rec[this->ind]->GetKey() == key)
		{
			throw - 1;
		} //Ключ уже есть в таблице
        this->ind++;
	}
    if (this->IsEmpty())
	{
        this->ind++;
	}
    this->dataCount++;
    for (int i = this->dataCount - 1; i > this->ind; i--)
	{
        this->rec[i] = this->rec[i - 1];
	}
    this->rec[this->ind] = new TabRecord<TData, TKey>(R);
    this->Reset();
}
template <typename TData, typename TKey>
TData* SortTable<TData, TKey>::Search(const TKey key)
{
    this->Reset();
	TData* tmp = nullptr;
    if (!(this->IsEmpty()))
	{
        int i = -1, j = this->dataCount;
		int mid;
		while (i < j - 1)
		{
			mid = (j + i) / 2;
            if (key >= this->rec[mid]->GetKey())
			{
				i = mid;
			}
			else
			{
				j = mid;
			}
		}
        if (key == this->rec[i]->GetKey())
		{
            this->ind = i;
            tmp = this->rec[this->ind]->GetData();
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
    this->Reset();
	if (Search(key) == nullptr)
	{
		throw 1;
	} // элемента для удаления нет в таблице
	else
	{
        if (this->dataCount > 1)
		{
            this->dataCount--;
            for (int i = this->ind; i < this->dataCount; i++)
			{
                this->rec[i] = this->rec[i + 1];
			}
            this->Reset();
		}
		else
		{
            this->dataCount = 0;
		}
	}
}
template <typename TData, typename TKey>
void SortTable<TData, TKey>::SortData()
{

	/*for (i = 0; i < dataCount; i++)
	{ for (j = 0; j < dataCount; j++)
	  { if (rec[i]->GetKey() < rec[j]->GetKey())
		{ TabRecord<TData,TKey>* temp (rec[i]);
		 rec[i] = rec[j];
		 rec[j] = temp;
		}
	  }
	}*/
    for (int i = 0; i < this->dataCount; i++) {
		bool flag = true;
        for (int j = 0; j < this->dataCount - (i + 1); j++) {
            if (this->rec[j]->GetKey() < this->rec[j + 1]->GetKey()) {
				flag = false;
				TabRecord<TData, TKey>* temp;
                temp = this->rec[j];
                this->rec[j] = this->rec[j + 1];
                this->rec[j + 1] = temp;
			}
		}
		if (flag) {
			break;
		}
	}
}
