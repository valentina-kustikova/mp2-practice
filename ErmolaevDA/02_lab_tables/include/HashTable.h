
#include "Table.h"

// Класса Хеш-таблица
template <typename TData, typename TKey>
class HashTable : public Table<TData,TKey>
{
  public:
  char* freePos;								// 0 пусто, 1 заполнена, -1 удалена
  int HashFunc(const TKey& key) const;
  int HashFunc2(int pos) const;
  unsigned int hashStep;
  // Конструкторы, деструктор
  HashTable(unsigned int n = 100, int step = 1);
  HashTable(const HashTable<TData,TKey>& T1);
  ~HashTable();
  // Методы
  virtual void InsertRecord(const TData Data, const TKey Key);
  virtual void RemoveRecord(const TKey Key) ;
  virtual TData* FindRecord(const TKey Key);
  void SetNext();
  void Reset();
  friend ostream& operator<<(ostream& os, const HashTable<TData,TKey>& T1)
  { if (T1.dataCount)
	{ for (int i = 0; i < T1.tabSize; i++)
      { if (T1.freePos[i])
        {  os <<"Key:"<< left << T1.records[i]->GetKey() << " |Polinom: " << *(T1.records[i]->GetData()) << '\n';}
	  }
    }
	else
    { os << "\n\tTable is Empty\n" << endl;}
	return os;
  }
};

// Pелизация функциий для класса Хеш-таблиц
// Конструкторы, деструктор	


template <typename TData, typename TKey>
HashTable<TData, TKey>::HashTable(unsigned int n, int step): Table<TData,TKey>(n)
{
    hashStep = step;
    freePos = new char[n];
    for (int i = 0; i < this->tabSize; i++)
    {
        freePos[i] = 0;
    }
}




template <typename TData, typename TKey>
HashTable<TData, TKey>::HashTable(const HashTable<TData, TKey>& T1)
{
    this->tabSize = T1.tabSize;
	hashStep = T1.hashStep;
    this->dataCount = T1.dataCount;
    this->currPos = T1.currPos;
    this->records = new TabRecord<TData, TKey>*[this->tabSize];
    freePos = new char[this->tabSize];
    for (int i = 0; i < this->tabSize; i++)
	{
		freePos[i] = T1.freePos[i];
		if (freePos[i] == 1)
		{
            this->records[i] = new TabRecord<TData, TKey>(*(T1.records[i]));
		}
	}
}
template <typename TData, typename TKey>
HashTable<TData, TKey>::~HashTable()
{
	delete[] freePos;
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
    return h % this->tabSize;
}
template <typename TData, typename TKey>
int HashTable<TData, TKey>::HashFunc2(int pos) const
{
    return (pos + hashStep) % this->tabSize;
}
template <typename TData, typename TKey>
void HashTable<TData, TKey>::SetNext()
{
    if (!this->IsEmpty())
	{
		do
		{
            this->currPos = (this->currPos + 1) % this->tabSize;
        } while (freePos[this->currPos] != 1);
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
        this->currPos = 0;
        while (freePos[this->currPos] != 1)
		{
            this->currPos++;
		}
	}
	else
	{
        this->currPos = -1;
	}
}
template <typename TData, typename TKey>
void HashTable<TData, TKey>::InsertRecord(const TData data1, const TKey key1)
{
	try {
		if (this->IsFull())
		{
			throw 1;
		} //Таблица переполнена
		this->currPos = HashFunc(key1);
		if (freePos[this->currPos] != 1)
		{
			this->records[this->currPos] = new TabRecord<TData, TKey>(key1, data1);
			this->dataCount++;
			freePos[this->currPos] = 1;
		}
		else
		{
			if (this->records[this->currPos]->GetKey() != key1)
			{
				int i = this->currPos;
				while (freePos[this->currPos])
				{
					this->currPos = HashFunc2(this->currPos);
				}
				this->records[this->currPos] = new TabRecord<TData, TKey>(key1, data1);
				this->dataCount++;
				freePos[this->currPos] = 1;
			}
			else
			{
				throw 1;
			}
		}
	}
	catch (int a) {
	}
}
template <typename TData, typename TKey>
TData* HashTable<TData, TKey>::FindRecord(const TKey key1)
{
	Reset();
    if (this->dataCount)
	{
        this->currPos = HashFunc(key1);
        int i = this->currPos;
        if (this->records[this->currPos]->GetKey() == key1)
		{
            return this->records[this->currPos]->GetData();
		}
		else
		{
            while (freePos[this->currPos] && ((this->currPos + hashStep) != i) && (this->records[this->currPos]->GetKey() != key1))
			{
                this->currPos = HashFunc2(this->currPos);
			}
            if (this->records[this->currPos]->GetKey() == key1)
			{
                return this->records[this->currPos]->GetData();
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
void HashTable<TData, TKey>::RemoveRecord(const TKey key1)
{
    Reset();
	if (FindRecord(key1) != nullptr)
	{
        this->records[this->currPos] = new TabRecord<TData, TKey>;
        freePos[this->currPos] = -1;
        this->dataCount--;
	}
	else
	{
		throw 1;
	}
}
