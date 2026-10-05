// ННГУ, ВМК, Курс "Методы программирования-2", С++, ООП
//
// tset.cpp - Copyright (c) Гергель В.П. 04.10.2001
//   Переработано для Microsoft Visual Studio 2008 Сысоевым А.В. (19.04.2015)
//
// Множество - реализация через битовые поля

#include "tset.h"

// Конструктор: создаёт множество с максимальной мощностью mp
TSet::TSet(int mp) : MaxPower(mp), BitField(mp)
{
}

// Конструктор копирования
TSet::TSet(const TSet &s) : MaxPower(s.MaxPower), BitField(s.BitField)
{
}

// Конструктор преобразования типа из битового поля
TSet::TSet(const TBitField &bf) : MaxPower(bf.GetLength()), BitField(bf)
{
}

// Преобразование к битовому полю
TSet::operator TBitField()
{
    return BitField;
}

// Получить максимальную мощность множества
int TSet::GetMaxPower(void) const
{
    return MaxPower;
}

// Проверить наличие элемента в множестве
int TSet::IsMember(const int Elem) const
{
    return BitField.GetBit(Elem);
}

// Включить элемент в множество
void TSet::InsElem(const int Elem)
{
    BitField.SetBit(Elem);
}

// Удалить элемент из множества
void TSet::DelElem(const int Elem)
{
    BitField.ClrBit(Elem);
}

// Присваивание
const TSet& TSet::operator=(const TSet &s)
{
    if (this != &s)
    {
        MaxPower = s.MaxPower;
        BitField = s.BitField;
    }
    return *this;
}

// Сравнение на равенство
int TSet::operator==(const TSet &s) const
{
    return BitField == s.BitField;
}

// Сравнение на неравенство
int TSet::operator!=(const TSet &s) const
{
    return BitField != s.BitField;
}

// Объединение множеств
TSet TSet::operator+(const TSet &s)
{
    return TSet(BitField | s.BitField);
}

// Объединение с элементом
TSet TSet::operator+(const int Elem)
{
    TSet result(*this);
    result.InsElem(Elem);
    return result;
}

// Разность с элементом
TSet TSet::operator-(const int Elem)
{
    TSet result(*this);
    result.DelElem(Elem);
    return result;
}

// Пересечение множеств
TSet TSet::operator*(const TSet &s)
{
    return TSet(BitField & s.BitField);
}

// Дополнение множества
TSet TSet::operator~(void)
{
    return TSet(~BitField);
}

// Ввод множества (делегируется вводу битового поля)
istream &operator>>(istream &istr, TSet &s)
{
    istr >> s.BitField;
    s.MaxPower = s.BitField.GetLength();
    return istr;
}

// Вывод множества (делегируется выводу битового поля)
ostream& operator<<(ostream &ostr, const TSet &s)
{
    ostr << s.BitField;
    return ostr;
}