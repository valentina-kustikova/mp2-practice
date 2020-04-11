#pragma once

#include "TException.h"

class TSet
{
    size_t size;
    int* keys;

public:
    TSet(size_t size_ = 10);
    TSet(size_t size_, int* array_);
    ~TSet();

    //Создание подмножества
    void createSubset(int id);
    //Объединение подмножеств
    void uniteSubsets(int a, int b);
    //Возвращение имени подмножества, которому принадлежит элемент
    int getSubsetName(int id);
};