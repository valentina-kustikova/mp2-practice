#pragma once
#include "Table.h" 

//����� ��������������� ������
template <typename TData, typename TKey>
class ScanTable : public Table<TData,TKey>
{ public: 
  // ������������, ����������	
  ScanTable(unsigned int n = 10) : Table<TData,TKey>(n) {};
  ScanTable(const ScanTable<TData,TKey>& T1);
  ~ScanTable() {};
  // ������ 
  virtual void Insert(const TData Data, const TKey Key);
  virtual TData* Search(const TKey Key);
  virtual void Delete(const TKey Key);
}; 

// P�������� �������� ��� ������ �������������� ������
// �����������
template <typename TData, typename TKey>
ScanTable<TData,TKey>::ScanTable(const ScanTable<TData,TKey>& T1)
{ Size = T1.Size;
  dataCount = T1.dataCount ;
  ind = T1.ind;
  rec = new TabRecord<TData,TKey>*[Size];
  for (int i = 0; i < dataCount ; i++)
    { rec[i] = new TabRecord<TData,TKey>(*(T1.rec[i]));}
} 
// ������ 
template <typename TData, typename TKey>
void ScanTable<TData,TKey>::Insert(const TData Data, const TKey Key)
{ if ( IsFull())
  { throw 1; } //������� �����������
  TabRecord<TData,TKey> R(Key, Data);
  Reset();
   if (( IsEmpty()) || (Search(Key)==nullptr)) 
   { rec[dataCount] = new TabRecord<TData,TKey>(R);
     dataCount ++;
   }
   else
  { throw 1; } // ��������� ������� ��������
   Reset();
} 
template <typename TData, typename TKey>
TData* ScanTable<TData,TKey>::Search(const TKey Key)
{ if ( IsEmpty())
  { throw 1; } //������� ����� 
  Reset();
  while (!( IsEnd()) && Key != rec[ind]->GetKey())
  { ind++;}
  if (!( IsEnd()))
  { return rec[ ind]->GetData();}
  else
  { return nullptr; }
} 
template <typename TData, typename TKey>
void ScanTable<TData,TKey>::Delete(TKey Key)
{ if (Search(Key) == nullptr)
  { throw 1; } // �������� ��� �������� ��� � �������
  else
  { rec[ind] = new TabRecord<TData,TKey>(*rec[dataCount - 1]);
    rec[dataCount - 1] = NULL;
    dataCount = dataCount - 1;
    ind = dataCount - 1;
  }
}

