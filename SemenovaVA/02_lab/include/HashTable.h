#pragma once
#include "Table.h"

// Класса Хеш-таблица
template <typename TData>
class HashTable : public Table<TData>
{ protected:
  int* mark;
  int HashFunc(const string& key) const;
  unsigned int step;
  public:
  // Конструкторы, деструктор	
  HashTable(unsigned int n = 10, unsigned int step1 = 1);
  HashTable(const HashTable<TData>& T1);
  ~HashTable();
  // Методы
  virtual void Insert(const TData Data, const string Key);
  virtual void Delete(const string Key) ;
  virtual TData* Search(const string Key);
  void SetNext();
  void Reset();
  template <class TData> friend ostream& operator<<(ostream& os, const HashTable<TData>& T1)
  { if (T1.dataCount)
	{ for (int i = 0; i < T1.Size; i++)
      { if (T1.mark[i])
        {  os <<"\t"<< left << setw(15) << T1.rec[i]->GetKey() << " | " << *(T1.rec[i]->GetData()) << '\n';}
	  }
    }
	else
    { os << "Table is Empty\n" << endl;}
	return os;
  }
};

// Pелизация функциий для класса Хеш-таблиц
// Конструкторы, деструктор	
template<typename TData>
HashTable<TData>::HashTable(unsigned int n, unsigned int step1) : Table(n)
{ step=step1;
  mark = new int[n];
  for (int i = 0; i < Size; i++)
  { mark[i] = 0;}
}
template<typename TData>
HashTable<TData>::HashTable(const HashTable<TData>& T1)
{ Size = T1.Size;
  step=T1.step;
  dataCount = T1.dataCount;
  ind = T1.ind;
  rec = new TabRecord<TData>*[Size];
  mark = new int[Size];
  for (int i = 0; i < Size; i++)
  { mark[i] = T1.mark[i];
    if (mark[i] == 1)
	{ rec[i] = new TabRecord<TData>(*(T1.rec[i]));}
  }
}
template<typename TData>
HashTable<TData>::~HashTable()
{ delete[] mark; }
// Методы 
template<typename TData>
int HashTable<TData>::HashFunc(const string& key) const
{ int h = 0;
  for (int i = 0; i < key.length(); i++)
  { h = h + int(key[i]);}
  return h % Size;
}
template<typename TData>
void HashTable<TData>::SetNext()
{ if (!IsEmpty())
  { do 
	{ ind = (ind + 1) % Size;}
	while (mark[ind] != 1);
  }
   else
   { throw 1;}
}
template<typename TData>
void HashTable<TData>::Reset()
{ if (dataCount)
  {	ind = 0;
	while (mark[ind] != 1)
	{ ind++;}
   }
  else
  { ind = -1;}
}
template<typename TData>
void HashTable<TData>::Insert(const TData data1, const string key1)
{ if ( IsFull())
  { throw 1; } //Таблица переполнена
  ind = HashFunc(key1);
  if (mark[ind]!=1)
  { rec[ind] = new TabRecord<TData>(key1, data1);
	dataCount++;
	mark[ind] = 1;
  }
  else
  {	if (rec[ind]->GetKey() != key1)
	{ int i = ind;
	  while (mark[ind])
	  {ind = (ind + step) % Size;}
	  rec[ind] = new TabRecord<TData>(key1, data1);
	  dataCount++;
	  mark[ind] = 1;
	}
    else
    { throw 1; }
  }
}
template<typename TData>
TData* HashTable<TData>::Search(const string key1)
{ Reset();
 if (dataCount)
 { ind = HashFunc(key1);
   int i = ind;
   if (rec[ind]->GetKey() == key1)
   { return rec[ind]->GetData();}
   else
   { while (mark[ind] && ((ind + step) != i) && (rec[ind]->GetKey() != key1))
     { ind = (ind + step) % Size;}
	 if (rec[ind]->GetKey() == key1)
	 { return rec[ind]->GetData();}
	 else
	 { return nullptr;}
   }
  }
 else
 { throw 1;}
}
template<typename TData>
void HashTable<TData>::Delete(const string key1)
{ Reset();
  if (dataCount)
  { ind = HashFunc(key1);
	int i = ind;
	if (mark[ind])
	{ if (rec[ind]->GetKey() != key1)
	  { while (mark[ind] && ((ind + 1) != i) && (rec[ind]->GetKey() != key1))
	    { ind = (ind + 1) % Size;}
		if (!mark[ind] || rec[ind]->GetKey() != key1)
		{ throw 1;}
		else
		{ rec[ind] = new TabRecord<TData>;
		  mark[ind] = -1;
		  dataCount--;
		}
	  }
	  else
	  { rec[ind] = new TabRecord<TData>;
		mark[ind] = 0;
		dataCount--;
	  }
	}
	else { throw 1; }
  }
  else
  {throw 1;}
}