// ННГУ, ВМК, Курс "Методы программирования-2", С++, ООП
//
// tset.cpp - Copyright (c) Гергель В.П. 04.10.2001
//   Переработано для Microsoft Visual Studio 2008 Сысоевым А.В. (19.04.2015)
//
// Множество - реализация через битовые поля

#include "tset.h"

TSet::TSet(int mp) : BitField(mp)
{
    MaxPower = mp;
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
    if (Elem >= MaxPower) throw "Element not in universe";
    if (BitField.GetBit(Elem)) return 1;
    return 0;
}

void TSet::InsElem(const int Elem) // включение элемента множества
{
    if (Elem >= MaxPower) throw "Element not in universe";
    BitField.SetBit(Elem);
}

void TSet::DelElem(const int Elem) // исключение элемента множества
{
    if (Elem >= MaxPower) throw "Element not in universe";
    BitField.ClrBit(Elem);
}

// теоретико-множественные операции

const TSet& TSet::operator=(const TSet& s) // присваивание
{
    if (s == (*this)) return (*this);
    MaxPower = s.MaxPower;
    BitField = s.BitField;
    return (*this);
}

int TSet::operator==(const TSet& s) const // сравнение
{
    if (MaxPower != s.MaxPower) return 0;
    return (BitField == s.BitField);
}

int TSet::operator!=(const TSet& s) const // сравнение
{
    return !((*this) == s);
}

TSet TSet::operator+(const TSet& s) // объединение
{
    TSet tmp(max(MaxPower, s.GetMaxPower()));
    tmp.BitField = BitField | s.BitField;
    return tmp;
}

TSet TSet::operator+(const int Elem) // объединение с элементом
{
    if (Elem >= MaxPower) throw "Element not in universe";
    TSet tmp(MaxPower);
    tmp.BitField = BitField;
    tmp.BitField.SetBit(Elem);
    return tmp;
}

TSet TSet::operator-(const int Elem) // разность с элементом
{
    if (Elem >= MaxPower) throw "Element not in universe";
    TSet tmp(MaxPower);
    tmp.BitField = BitField;
    tmp.BitField.ClrBit(Elem);
    return tmp;
}

TSet TSet::operator*(const TSet& s) // пересечение
{
    TSet tmp(max(MaxPower, s.GetMaxPower()));
    tmp.BitField = (BitField & s.BitField);
    return tmp;
}

TSet TSet::operator~(void) // дополнение
{
    TSet tmp(MaxPower);
    tmp.BitField = ~BitField;
    return tmp;
}

// перегрузка ввода/вывода

istream& operator>>(istream& istr, TSet& s) // ввод
{
    for (int i = 0; i < s.MaxPower; i++) {
        int val;
        cin >> val;
        s.BitField.SetBit(val);
    }
    return istr;
}

ostream& operator<<(ostream& ostr, const TSet& s) // вывод
{
    for (int i = 0; i < s.MaxPower; i++) {
        if (s.BitField.GetBit(i)) cout << i << " ";
    }
    return ostr;
}
