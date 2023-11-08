// ННГУ, ВМК, Курс "Методы программирования-2", С++, ООП
//
// tset.cpp - Copyright (c) Гергель В.П. 04.10.2001
//   Переработано для Microsoft Visual Studio 2008 Сысоевым А.В. (19.04.2015)
//
// Множество - реализация через битовые поля

#include "tset.h"
#include <string>
#include <sstream>

TSet::TSet(int mp) : BitField(mp)
{
    if (mp >= 0)
        MaxPower = mp;
    else
        throw "Size error";
}

// конструктор копирования
TSet::TSet(const TSet& s) : BitField(s.BitField)
{
    MaxPower = s.MaxPower;
}

// конструктор преобразования типа
TSet::TSet(const TBitField& bf) : BitField(bf)
{
    MaxPower = bf.GetLength();
}

TSet::operator TBitField()
{
    return BitField;
}

int TSet::GetMaxPower(void) const // получить макс. к-во эл-тов
{
    return MaxPower;
}

int TSet::IsMember(const int Elem) const // элемент множества?
{
    if (Elem >= MaxPower || Elem < 0) 
        throw "Error";
    return BitField.GetBit(Elem);
}

void TSet::InsElem(const int Elem) // включение элемента множества
{
    if (Elem >= MaxPower || Elem < 0)
        throw "Error";
    return BitField.SetBit(Elem);
}

void TSet::DelElem(const int Elem) // исключение элемента множества
{
    if (Elem >= MaxPower || Elem < 0)
        throw "Error";
    return BitField.ClrBit(Elem);
}

// теоретико-множественные операции

const TSet& TSet::operator=(const TSet &s)  // присваивание
{
    if (this != &s)
    {
        MaxPower = s.MaxPower;
        BitField = s.BitField;
    }
    return *this;
}

int TSet::operator==(const TSet &s) const // сравнение
{
    return BitField == s.BitField;;
}

int TSet::operator!=(const TSet &s) const // сравнение
{
    return BitField != s.BitField;
}

TSet TSet::operator+(const TSet &s) // объединение
{
    size_t newMaxPower;
    if (MaxPower > s.MaxPower)
        newMaxPower = MaxPower;
    else
        newMaxPower = s.MaxPower;
    TSet result(newMaxPower);
    result.BitField = BitField | s.BitField;
    return result;
}

TSet TSet::operator+(const int Elem) // объединение с элементом
{
    if (Elem >= MaxPower || Elem < 0)
        throw "Error";
    TSet temp(*this);
    temp.BitField.SetBit(Elem);
    return temp;
}

TSet TSet::operator-(const int Elem) // разность с элементом
{
    if (Elem >= MaxPower || Elem < 0)
        throw "Error";
    TSet tmp(*this);
    tmp.BitField.ClrBit(Elem);
    return tmp;
}

TSet TSet::operator*(const TSet &s) // пересечение
{
    size_t newMaxPower;
    if (MaxPower > s.MaxPower)
        newMaxPower = MaxPower;
    else
        newMaxPower = s.MaxPower;
    TSet result(newMaxPower);
    result.BitField = BitField & s.BitField;
    return result;
}

TSet TSet::operator~(void) // дополнение
{
    TSet result(MaxPower);
    result.BitField = ~BitField;
    return result;
}

// перегрузка ввода/вывода

istream& operator>>(istream& istr, TSet& s) // ввод
{
    int elem, n = 0;
    do
    {
        cout << "Enter the number of digits you want to enter: ";
        istr >> n;
    } while (n <= 0 || n > s.MaxPower);
    for (int i = 0; i < n; i++)
    {
        istr >> elem;
        if (elem > 0 || elem <= s.MaxPower)
            s.InsElem(elem);
        else
            throw "error";
    }
    return istr;
}

ostream& operator<<(ostream &ostr, const TSet &s) // вывод
{
    for (int i = 0; i < s.MaxPower; i++)
        if (s.IsMember(i))
            ostr << i << ' ';
    return ostr;
}
