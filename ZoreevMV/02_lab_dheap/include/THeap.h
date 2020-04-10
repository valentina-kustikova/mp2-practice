#pragma once

#include "TException.h"

template <typename Type>
class THeap
{
    size_t max_size; //Максимальное число элементов 
    size_t size;     //Текущее число элементов
    const size_t d = 2;        //Поряд кучи
    Type* keys;      //Элементы

public:
    THeap(size_t max_size_, size_t size_, Type* keys_);
    ~THeap();

    //Транспонирование элементов
    void Transpose(size_t a, size_t b);
    //Всплытие элемента
    void moveUp(size_t id);
    //Погружение элемента
    void moveDown(size_t id);

    //Вставка элемента
    void insert(const Type& element);

    //Возврат наименьшего ключа
    Type getMinKey() const;
    //Удаление элемента с наименьшим ключом
    void removeMinKey();

    //Возвращение индекса наименьшего потомка
    size_t getMinChild(size_t id);

    //Проверка на пустоту
    bool empty() const;

    //Проверка на полноту
    bool full() const;

    //Окучивание
    void Heaping();
};

template <typename Type>
THeap<Type>::THeap(size_t max_size_, size_t size_, Type* keys_)
{
    max_size = max_size_;
    d = d_;
    size = size_;
        keys = keys_;
    Heaping();
}

template <typename Type>
THeap<Type>::~THeap()
{
    max_size = 0;
    d = 0;
    size = 0;
}

template <typename Type>
void THeap<Type>::Transpose(size_t a, size_t b)
{
    Type temp = keys[a];
    keys[a] = keys[b];
    keys[b] = temp;
}

template <typename Type>
void THeap<Type>::moveUp(size_t id)
{
    int parent = (id - 1) / d;
    while (id > 0)
    {
        if (keys[parent] > keys[id])
        {
            Transpose(parent, id);
            id = parent;
        }
        else break;
    }
}

template <typename Type>
void THeap<Type>::moveDown(size_t id)
{
    size_t current = getMinChild(id);
    while (current != id && keys[current] < keys[id])
    {
        Transpose(id, current);
        id = current;
        current = getMinChild(id);
    }
}

template <typename Type>
void THeap<Type>::insert(const Type& element)
{
    if (size == max_size) throw TException(ContainerIsFull, __LINE__);
    keys[size++] = element;
    Heaping();
}

template <typename Type>
Type THeap<Type>::getMinKey() const
{
    return keys[0];
}

template <typename Type>
void THeap<Type>::removeMinKey()
{
    Transpose(0, size - 1);
    size--;
    moveDown(0);
}

template <typename Type>
size_t THeap<Type>::getMinChild(size_t id)
{
    if (id * d + 1 >= size) return id; //Если детей нет, то возвращает себя
    size_t a = id * d + 1, b = 0;
    if ((size - 1) < (id * d + d))
    {
        b = size - 1;
    }
    else
    {
        b = id * d + d;
    }
    size_t min = a;
    for (size_t i = a; i <= b; i++)
    {
        if (keys[i] < keys[min]) min = i;
    }
    return min;
}

template <typename Type>
bool THeap<Type>::empty() const
{
    return (size == 0);
}

template <typename Type>
bool THeap<Type>::full() const
{
    return (size >= max_size);
}

template <typename Type>
void THeap<Type>::Heaping()
{
    for (int i = size - 1; i >= 0; i--)
    {
        moveDown(i);
    }
}