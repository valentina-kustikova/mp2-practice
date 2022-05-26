#pragma once 
#include <iostream>
using namespace std;

//����� ������
template <typename TData, typename TKey>
class TabRecord
{ protected:
  TKey key;
  TData* data;
  public:
  // ������������, ����������	
  TabRecord(TKey k = {}, TData d = {}) { key = k; data = new TData(d); }
  TabRecord(const TabRecord& T1) { key = T1.key; data = new TData(*(T1.data)); } // ����������� �����������
  ~TabRecord() { delete data; }
  //������
  TData* GetData() const { return data; }
  TKey GetKey() const { return key; }
  // ���������� ��������
  TabRecord<TData,TKey>& operator=(const TabRecord<TData,TKey>& TabR)
  { data = new TData(*(TabR.data)); key = TabR.key; return *this; }
};

//����� �������
template <typename TData, typename TKey>
class Table
{ protected:
  TabRecord<TData,TKey>** rec;
  unsigned int Size;
  unsigned int dataCount ;
  int ind;
  public:
  // ������������, ����������	
  Table(unsigned int n = 10);
  virtual ~Table() { delete[] rec; }
  // ������ 
  virtual void Insert(const TData Data, const TKey Key) = 0;
  virtual void Delete(const TKey Key) = 0;
  virtual TData* Search(const TKey Key) = 0;
  void Reset();
  void SetNext();
  bool IsEnd() const { return ind == dataCount  || ind == -1; }
  bool IsFull() const { return dataCount  == Size; }
  bool IsEmpty() const { return dataCount  == 0; }
  int GetCount() const { return dataCount; }
  int GetSize() const { return Size; }
  TData* GetData() const; // ��� �������� ��������
  TKey GetKey() const;  // ��� �������� ��������
  template<class TData> friend std::ostream& operator<< (std::ostream& os, const Table<TData,TKey>& Tab)
  { unsigned int i = 0;
	while (i < Tab.dataCount)
	{ os <<"\t"<< left << setw(15) << Tab.rec[i]->GetKey() << " | " << *(Tab.rec[i]->GetData()) << '\n';
	  i++;
	}
	if (Tab.dataCount == 0)
	os << "\n\tTable is Empty\n";
	return os;
  }
};

// P�������� �������� ��� ������ ������
// ������������, ����������	
template <typename TData, typename TKey>
Table<TData,TKey>::Table(unsigned int n)
{ Size = n;
  dataCount  = 0;
  ind = -1;
  rec = new TabRecord<TData,TKey>*[Size];
}
// ������ 
template <typename TData, typename TKey>
void Table<TData,TKey>::Reset()
{ if (dataCount  > 0)
  { ind = 0;}
  else
  { ind = -1;}
}
template <typename TData, typename TKey>
void Table<TData,TKey>::SetNext()
{ if (ind != -1) { ind++;}
  else { throw -1; } //������� �����
  if (IsEnd()) { Reset();}
}
template <typename TData, typename TKey>
TData* Table<TData,TKey>::GetData() const 
{  if (!IsEmpty())
  { return rec[ind]->GetData();}
  else
  {	throw - 1;} //������� �����
}
template <typename TData, typename TKey>
TKey Table<TData,TKey>::GetKey() const
{  if (!IsEmpty())
  { return rec[ind]->GetKey();}
  else
  {	throw - 1;} //������� �����
}
