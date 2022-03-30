#pragma once 
#include <string>
#include <iostream>
using namespace std;

//Класс Запись
template <typename TData>
class TabRecord
{ protected:
  string key="";
  TData* data;
  public:
  // Конструкторы, деструктор	
  TabRecord(string k="", TData d={}) { key = k; data = new TData(d); }
  TabRecord(const TabRecord& T1) { key = T1.key; data = new TData(*(T1.data)); } // конструктор копирования
  ~TabRecord() { delete data; }
  //Методы
  TData* GetData() const { return data; }
  string GetKey() const { return key; }
  void SetData(TData* d) { data = d; }
  void SetKey(const string& k) { key = k; }
  // Перегрузка операций
  TabRecord<TData>& operator=(const TabRecord<TData>& TabR) 
  { data = new TData(*(TabR.data)); key = TabR.key; return *this; }
};

//Класс Таблица
template <typename TData>
class Table
{ protected:
  TabRecord<TData>** rec;
  unsigned int Size;
  unsigned int dataCount ;
  int ind;
  public:
  // Конструкторы, деструктор	
  Table(unsigned int n = 10);
  virtual ~Table() { delete[] rec; }
  // Методы 
  virtual void Insert(const TData Data, const string Key) = 0;
  virtual void Delete(const string Key) = 0;
  virtual TData* Search(const string Key) = 0;
  void Reset();
  void SetNext();
  bool IsEnd() const { return ind == dataCount  || ind == -1; }
  bool IsFull() const { return dataCount  == Size; }
  bool IsEmpty() const { return dataCount  == 0; }
  int GetCount() const { return dataCount; }
  int GetSize() const { return Size; }
  TData* GetData() const;
  string GetKey() const;
  template<class TData> friend std::ostream& operator<< (std::ostream& os, const Table<TData>& Tab)
  { unsigned int i = 0;
	while (i < Tab.dataCount)
	{ os <<"\t"<< left << setw(15) << Tab.rec[i]->GetKey() << " | " << *(Tab.rec[i]->GetData()) << '\n';
	  i++;
	}
	if (Tab.dataCount == 0)
	os << "Table is Empty\n";
	return os;
  }
};

// Pелизация функциий для класса таблиц
// Конструкторы, деструктор	
template<typename TData>
Table<TData>::Table(unsigned int n)
{ Size = n;
  dataCount  = 0;
  ind = -1;
  rec = new TabRecord<TData>*[Size];
}
// Методы 
template<typename TData>
void Table<TData>::Reset()
{ if (dataCount  > 0)
  { ind = 0;}
  else
  { ind = -1;}
}
template<typename TData>
void Table<TData>::SetNext()
{ if (ind != -1) { ind++;}
  else { throw -1; } //Таблица пуста
  if (IsEnd()) { Reset();}
}
template<typename TData>
TData* Table<TData>::GetData() const 
{  if (!IsEmpty())
  { return rec[ind]->GetData();}
  else
  {	throw - 1;} //Таблица пуста
}
template<typename TData>
string Table<TData>::GetKey() const
{  if (!IsEmpty())
  { return rec[ind]->GetKey();}
  else
  {	throw - 1;} //Таблица пуста
}
