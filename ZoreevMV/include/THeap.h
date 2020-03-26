#pragma once

#include "TException.h"

template <typename Type>
class THeap
{
    size_t max_size; //Максимальное число элементов 
    size_t size;     //Текущее число элементов
    size_t d;        //Поряд кучи
    Type* keys;      //Элементы
    bool owner;      //Явлеяется ли куча владельцем массива

public:
    THeap(size_t d_, size_t max_size_ = 10);
    THeap(size_t d_, size_t max_size_, size_t size_, Type* keys_, bool owner_ = true);
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
    Type getMinKey();
    //Удаление элемента с наименьшим ключом
    void removeMinKey();

    //Возвращение индекса наименьшего потомка
    size_t getMinChild(size_t id);

    //Проверка на пустоту
    bool empty();

private:
    //Окучивание
    void Heaping();
};

template <typename Type>
THeap<Type>::THeap(size_t d_, size_t max_size_)
{
    max_size = max_size_;
    d = d_;
    size = 0;
    owner = true;
    keys = new Type[max_size];
}

template <typename Type>
THeap<Type>::THeap(size_t d_, size_t max_size_, size_t size_, Type* keys_, bool owner_)
{
    max_size = max_size_;
    d = d_;
    size = size_;
    owner = owner_;
    if (owner == true)
    {
        keys = new Type[max_size];
        for (int i = 0; i < size; i++)
        {
            keys[i] = keys_[i];
        }
    }
    else
    {
        keys = keys_;
    }
    Heaping();
}

template <typename Type>
THeap<Type>::~THeap()
{
    if (owner == true)
    {
        delete[] keys;
    }
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
}

template <typename Type>
Type THeap<Type>::getMinKey()
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
bool THeap<Type>::empty()
{
    return (size == 0);
}

template <typename Type>
void THeap<Type>::Heaping()
{
    for (int i = size - 1; i >= 0; i--)
    {
        moveDown(i);
    }
}