
#include "Table.h"

// Класса Хеш-таблица
template <typename TData, typename TKey>
class HashTable : public Table<TData,TKey>
{
  public:
  char* mark;								// 0 пусто, 1 заполнена, -1 удалена
  int HashFunc(const TKey& key) const;
  int HashFunc2(int in) const;
  unsigned int step;
  // Конструкторы, деструктор	
  //HashTable(unsigned int n = 10, unsigned int step1 = 1);
  HashTable(const HashTable<TData,TKey>& T1);
  ~HashTable();
  // Методы
  virtual void Insert(const TData Data, const TKey Key);
  virtual void Delete(const TKey Key) ;
  virtual TData* Search(const TKey Key);
  void SetNext();
  void Reset();
  friend ostream& operator<<(ostream& os, const HashTable<TData,TKey>& T1)
  { if (T1.dataCount)
	{ for (int i = 0; i < T1.Size; i++)
      { if (T1.mark[i])
        {  os <<"\t"<< left << T1.rec[i]->GetKey() << "\t | " << *(T1.rec[i]->GetData()) << '\n';}
	  }
    }
	else
    { os << "\n\tTable is Empty\n" << endl;}
	return os;
  }

  HashTable(unsigned int n, unsigned int step1): Table<TData,TKey>(n)
  {
      step = step1;
      mark = new char[n];
      for (int i = 0; i < this->Size; i++)
      {
          mark[i] = 0;
      }
  }
};

// Pелизация функциий для класса Хеш-таблиц
// Конструкторы, деструктор	
template <typename TData, typename TKey>
HashTable<TData, TKey>::HashTable(const HashTable<TData, TKey>& T1)
{
    this->Size = T1.Size;
	step = T1.step;
    this->dataCount = T1.dataCount;
    this->ind = T1.ind;
    this->rec = new TabRecord<TData, TKey>*[this->Size];
    mark = new char[this->Size];
    for (int i = 0; i < this->Size; i++)
	{
		mark[i] = T1.mark[i];
		if (mark[i] == 1)
		{
            this->rec[i] = new TabRecord<TData, TKey>(*(T1.rec[i]));
		}
	}
}
template <typename TData, typename TKey>
HashTable<TData, TKey>::~HashTable()
{
	delete[] mark;
}
// Методы 
template <typename TData, typename TKey>
int HashTable<TData, TKey>::HashFunc(const TKey& key) const
{
	int h = 0;
	for (int i = 0; i < key.length(); i++)
	{
		h = h + int(key[i]);
	}
    return h % this->Size;
}
template <typename TData, typename TKey>
int HashTable<TData, TKey>::HashFunc2(int in) const
{
    return (in + step) % this->Size;
}
template <typename TData, typename TKey>
void HashTable<TData, TKey>::SetNext()
{
    if (!this->IsEmpty())
	{
		do
		{
            this->ind = (this->ind + 1) % this->Size;
        } while (mark[this->ind] != 1);
	}
	else
	{
		throw 1;
	}
}
template <typename TData, typename TKey>
void HashTable<TData, TKey>::Reset()
{
    if (this->dataCount)
	{
        this->ind = 0;
        while (mark[this->ind] != 1)
		{
            this->ind++;
		}
	}
	else
	{
        this->ind = -1;
	}
}
template <typename TData, typename TKey>
void HashTable<TData, TKey>::Insert(const TData data1, const TKey key1)
{
    if (this->IsFull())
	{
		throw 1;
	} //Таблица переполнена
    this->ind = HashFunc(key1);
    if (mark[this->ind] != 1)
	{
        this->rec[this->ind] = new TabRecord<TData, TKey>(key1, data1);
        this->dataCount++;
        mark[this->ind] = 1;
	}
	else
	{
        if (this->rec[this->ind]->GetKey() != key1)
		{
            int i = this->ind;
            while (mark[this->ind])
			{
                this->ind = HashFunc2(this->ind);
			}
            this->rec[this->ind] = new TabRecord<TData, TKey>(key1, data1);
            this->dataCount++;
            mark[this->ind] = 1;
		}
		else
		{
			throw 1;
		}
	}
}
template <typename TData, typename TKey>
TData* HashTable<TData, TKey>::Search(const TKey key1)
{
	Reset();
    if (this->dataCount)
	{
        this->ind = HashFunc(key1);
        int i = this->ind;
        if (this->rec[this->ind]->GetKey() == key1)
		{
            return this->rec[this->ind]->GetData();
		}
		else
		{
            while (mark[this->ind] && ((this->ind + step) != i) && (this->rec[this->ind]->GetKey() != key1))
			{
                this->ind = HashFunc2(this->ind);
			}
            if (this->rec[this->ind]->GetKey() == key1)
			{
                return this->rec[this->ind]->GetData();
			}
			else
			{
				return nullptr;
			}
		}
	}
	else
	{
		throw 1;
	}
}
template <typename TData, typename TKey>
void HashTable<TData, TKey>::Delete(const TKey key1)
{
	Reset();
	if (Search(key1) != nullptr)
	{
        this->rec[this->ind] = new TabRecord<TData, TKey>;
        mark[this->ind] = -1;
        this->dataCount--;
	}
	else
	{
		throw 1;
	}
}
