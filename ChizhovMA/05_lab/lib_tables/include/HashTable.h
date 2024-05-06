#ifndef HASHTABLE_H
#define HASHTABLE_H

#include "Tables.h"

template<class TKey,class TData>
class THashTable : public Table<TKey, TData>
{
protected:
    virtual size_t hash_func(const TKey& key);
public:
	THashTable(size_t size) : Table<TKey, TData>(size) {};
};
template<class TKey, class TData>
size_t THashTable<TKey,TData>::hash_func(const TKey& key)  //функция хэширования с методом горизонтального хэширования
{
    size_t hash = 0;
    for (char c : key) 
        hash +=  c; // Хорошо подойдет для хеширования строк
    
    return hash % maxsize;
}

#endif
