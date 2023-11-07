// ННГУ, ВМК, Курс "Методы программирования-2", С++, ООП
//
// tset.cpp - Copyright (c) Гергель В.П. 04.10.2001
//   Переработано для Microsoft Visual Studio 2008 Сысоевым А.В. (19.04.2015)
//
// Множество - реализация через битовые поля

#include "tset.h"

TSet::TSet(int mp) : MaxPower(mp), BitField(mp) {}

// конструктор копирования
TSet::TSet(const TSet &s) : BitField(s.BitField), MaxPower(s.GetMaxPower()) {}

// конструктор преобразования типа
TSet::TSet(const TBitField &bf) : BitField(bf), MaxPower(bf.GetLength()){}


int TSet::GetMaxPower(void) const // получить макс. к-во эл-тов
{
    return MaxPower;
}

int TSet::IsMember(const int Elem) const // элемент множества?
{
    return BitField.GetBit(Elem);
}

void TSet::InsElem(const int Elem) // включение элемента множества
{
    BitField.SetBit(Elem);
}

void TSet::DelElem(const int Elem) // исключение элемента множества
{
    BitField.ClrBit(Elem);
}

// теоретико-множественные операции

const TSet& TSet::operator=(const TSet &s) // присваивание
{
    if (*this == s)
        return *this;
    BitField = s.BitField;
    MaxPower = s.MaxPower;
    return *this;
}

int TSet::operator==(const TSet &s) const // сравнение
{
    if (MaxPower != s.MaxPower)
        return 0;
    return (BitField == s.BitField);
}

int TSet::operator!=(const TSet &s) const // сравнение
{
    return !(*this == s);
    
}

TSet TSet::operator+(const TSet &s) // объединение
{
    TSet TStmp(max(MaxPower, s.GetMaxPower()));
    TStmp.BitField = BitField | s.BitField;
    return TStmp;
}

TSet TSet::operator+(const int Elem) // объединение с элементом
{
    TSet TStmp(*this);
    TStmp.InsElem(Elem);
    return TStmp;
}

TSet TSet::operator-(const int Elem) // разность с элементом
{
    TSet TStmp(*this);
    TStmp.DelElem(Elem);
    return TStmp;
}

TSet TSet::operator*(const TSet &s) // пересечение
{
    TSet TStmp(max(MaxPower, s.GetMaxPower()));
    TStmp.BitField = BitField & s.BitField;
    return TStmp;
}

TSet TSet::operator~(void) // дополнение
{
    TSet TStmp(MaxPower);
    TStmp.BitField = ~BitField;
    return TStmp;
}

// перегрузка ввода/вывода

istream &operator>>(istream &istr, TSet &s) // ввод
{
   int elem;
   int n;
   cout << "set length: ";
   istr >> n;
   for (int i = 0; i < n; i++) {
       istr >> elem;

       s.InsElem(elem);
   }
    return istr;
}

ostream& operator<<(ostream &ostr, const TSet &s) // вывод
{
    for (int i = 0; i < s.MaxPower; ++i)
        if (s.IsMember(i))
            ostr << i << " ";
    return ostr;
}