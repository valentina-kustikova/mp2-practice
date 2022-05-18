#pragma once
#include "Table.h" 

//Класс Просматриваемых таблиц
template <typename TData, typename TKey>
class ScanTable : public Table<TData, TKey>
{
public:
    // Конструкторы, деструктор	
    ScanTable(unsigned int n = 10) : Table<TData, TKey>(n) {};
    ScanTable(const ScanTable<TData, TKey>& T1);
    ~ScanTable() {};
    // Методы 
    virtual void Insert(const TData Data, const TKey Key);
    virtual TData* Search(const TKey Key);
    virtual void Delete(const TKey Key);
    ScanTable<TData, TKey>& operator=(ScanTable<TData, TKey> T1)
    {
        rec = new TabRecord<TData, TKey>*[T1.Size];
        Size = T1.Size;
        ind = -1;
        T1.Reset();
        for (dataCount = 0; dataCount < T1.dataCount; dataCount++)
        {
            Insert(*(T1.GetData()), T1.GetKey());
            T1.SetNext();
        }
        return *this;
    }
};

// Pелизация функциий для класса росматриваемых таблиц
// Конструктор
template <typename TData, typename TKey>
ScanTable<TData, TKey>::ScanTable(const ScanTable<TData, TKey>& T1)
{
    Size = T1.Size;
    dataCount = T1.dataCount;
    ind = T1.ind;
    rec = new TabRecord<TData, TKey>*[Size];
    for (int i = 0; i < dataCount; i++)
    {
        rec[i] = new TabRecord<TData, TKey>(*(T1.rec[i]));
    }
}
// Методы 
template <typename TData, typename TKey>
void ScanTable<TData, TKey>::Insert(const TData Data, const TKey Key)
{
    if (IsFull())
    {
        throw std::exception("\tInsert is not possible\n");
    } //Таблица переполнена
    TabRecord<TData, TKey> R(Key, Data);
    Reset();
    if ((IsEmpty()) || (Search(Key) == nullptr))
    {
        rec[dataCount] = new TabRecord<TData, TKey>(R);
        dataCount++;
    }
    else
    {
        throw std::exception("\tInsert is not possible\n");
    } // Повторная вставка элемента
    Reset();
}
template <typename TData, typename TKey>
TData* ScanTable<TData, TKey>::Search(const TKey Key)
{
    if (IsEmpty())
    {
        throw std::exception("\Search is not possible\n");
    } //таблица пуста 
    Reset();
    while (!(IsEnd()) && Key != rec[ind]->GetKey())
    {
        ind++;
    }
    if (!(IsEnd()))
    {
        return rec[ind]->GetData();
    }
    else
    {
        return nullptr;
    }
}
template <typename TData, typename TKey>
void ScanTable<TData, TKey>::Delete(TKey Key)
{
    if (Search(Key) == nullptr)
    {
        throw  std::exception("\Delete is not possible\n");
    } // элемента для удаления нет в таблице
    else
    {
        rec[ind] = new TabRecord<TData, TKey>(*rec[dataCount - 1]);
        rec[dataCount - 1] = NULL;
        dataCount = dataCount - 1;
        ind = dataCount - 1;
    }
}

