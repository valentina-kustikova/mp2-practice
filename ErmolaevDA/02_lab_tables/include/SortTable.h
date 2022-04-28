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
 virtual void InsertRecord(const TData data, const TKey key);
 virtual TData* FindRecord(const TKey key);
 virtual void RemoveRecord(const TKey key);
 virtual void Clear();

};

// Pелизация функциий для класса упорядоченных таблиц
// Конструктор
template <typename TData, typename TKey>
SortTable<TData, TKey>::SortTable(const SortTable<TData, TKey>& T1)
{
 this->tabSize = T1.tabSize;
 this->currPos = T1.currPos;
 this->dataCount = T1.dataCount;
 this->records = new TabRecord<TData, TKey>*[this->tabSize];
 for (int i = 0; i < this->dataCount; i++)
	{
  this->records[i] = new TabRecord<TData, TKey>(*(T1.records[i]));
	}
}
template <typename TData, typename TKey>
SortTable<TData, TKey>::SortTable(const ScanTable<TData, TKey>& T1) //Здесь было Scan
{
 this->tabSize = T1.tabSize;
 this->dataCount = T1.dataCount;
 this->currPos = T1.currPos;
 this->records = new TabRecord<TData, TKey>*[this->tabSize];
 for (int i = 0; i < this->dataCount; i++)
	{
  this->records[i] = T1.records[i];
	}
	SortData();
}
// Методы 
template <typename TData, typename TKey>
void SortTable<TData, TKey>::InsertRecord(const TData data, const TKey key)
{
	bool flag = 0;
	try {
		if (this->IsFull()) { throw "The SortTable is full, so InsertRecord cannot be executed"; } //Таблица переполнена
		else {
			TabRecord<TData, TKey> R(key, data);
			this->Reset();
			while (!(this->IsTabEnded()) && key >= this->records[this->currPos]->GetKey())
			{

				if (this->records[this->currPos]->GetKey() == key)
				{
					flag = 1;
					//throw "This key is already in the SortTable, so InsertRecord cannot be executed";
					break;
				} //Ключ уже есть в таблице
				this->currPos++;
			}
			if (flag == 1) {
				throw "This key is already in the SortTable, so InsertRecord cannot be executed";
			}
			else {
				if (this->IsEmpty())
				{
					this->currPos++;
				}
				this->dataCount++;
				for (int i = this->dataCount - 1; i > this->currPos; i--)
				{
					this->records[i] = this->records[i - 1];
				}
				this->records[this->currPos] = new TabRecord<TData, TKey>(R);
			}
		}
		
	}
	catch (const char* exception)
	{
		std::cerr << "Error: " << exception << '\n';
		return;
	}
 //this->Reset();
}
template <typename TData, typename TKey>
TData* SortTable<TData, TKey>::FindRecord(const TKey key)
{
 this->Reset();
	TData* tmp = nullptr;
	try {
		if (!(this->IsEmpty()))
		{
			int i = -1, j = this->dataCount;
			int mid;
			while (i < j - 1)
			{
				mid = (j + i) / 2;
				if (key >= this->records[mid]->GetKey())
				{
					i = mid;
				}
				else
				{
					j = mid;
				}
			}
			if (key == this->records[i]->GetKey())
			{
				this->currPos = i;
				tmp = this->records[this->currPos]->GetData();
			}
			else
			{
				return nullptr;
			}
		}
		else
		{
			throw "SortTable is empty, FindRecord cannot be executed";
		}
	}
	catch (const char* exception)
	{
		std::cerr << "Error: " << exception << '\n';
	}
	return tmp;
}
template <typename TData, typename TKey>
void SortTable<TData, TKey>::RemoveRecord(const TKey key)
{
 this->Reset();
	try {
		if (FindRecord(key) == nullptr)
		{
			throw "There is no element to delete in the SortTable, you cannot execute RemoveRecord";
		} // элемента для удаления нет в таблице
		else
		{
			if (this->dataCount > 1)
			{
				this->dataCount--;
				for (int i = this->currPos; i < this->dataCount; i++)
				{
					this->records[i] = this->records[i + 1];
				}
				this->Reset();
			}
			else
			{
				this->dataCount = 0;
			}
		}
	}
	catch(const char* exception)
	{
		std::cerr << "Error: " << exception << '\n';
	}
}
template<typename TData, typename TKey>
inline void SortTable<TData, TKey>::Clear()
{
	if (!this->IsEmpty())
	{
		this->Reset();
		while (!(this->IsTabEnded()))
		{
			this->records[this->currPos] = nullptr;
			this->currPos++;
		}
		this->dataCount = 0;

	}
}
template <typename TData, typename TKey>
void SortTable<TData, TKey>::SortData()
{
 for (int i = 0; i < this->dataCount; i++) {
		bool flag = true;
  for (int j = 0; j < this->dataCount - (i + 1); j++) {
   if (this->records[j]->GetKey() < this->records[j + 1]->GetKey()) {
				flag = false;
				TabRecord<TData, TKey>* temp;
    temp = this->records[j];
    this->records[j] = this->records[j + 1];
    this->records[j + 1] = temp;
			}
		}
		if (flag) {
			break;
		}
	}
}
