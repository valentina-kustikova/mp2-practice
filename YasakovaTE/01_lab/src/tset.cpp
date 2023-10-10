// ННГУ, ВМК, Курс "Методы программирования-2", С++, ООП
//
// tset.cpp - Copyright (c) Гергель В.П. 04.10.2001
//   Переработано для Microsoft Visual Studio 2008 Сысоевым А.В. (19.04.2015)
//
// Множество - реализация через битовые поля

#include "tset.h"

TSet::TSet(int mp) : BitField(mp)
{
    if (mp >= 0) {
        MaxPower = mp;
    }
    else {
        throw "error: Set size < 0";
    }
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

// доступ к битам
int TSet::GetMaxPower(void) const noexcept // получить макс. к-во эл-тов
{
    return MaxPower;
}
bool TSet::IsMember(const int Elem) const // элемент множества?
{
    if (Elem >= MaxPower || Elem < 0) throw "error: index out of range";

    if (BitField.GetBit(Elem))
        return true;
    return false;
}
void TSet::InsElem(const int Elem) // включение элемента множества
{
    if (Elem >= MaxPower || Elem < 0) throw "error: index out of range";
    BitField.SetBit(Elem);
}
void TSet::DelElem(const int Elem) // исключение элемента множества
{
    if (Elem >= MaxPower || Elem < 0) throw "error: index out of range";
    BitField.ClrBit(Elem);
}

// теоретико-множественные операции
const TSet& TSet::operator=(const TSet& s) // присваивание
{
    MaxPower = s.MaxPower;
    BitField = s.BitField;
    return *this;
}
bool TSet::operator==(const TSet& s) const // сравнение
{
    if (MaxPower != s.MaxPower) return false;
    return (BitField == s.BitField);
}
bool  TSet::operator!=(const TSet& s) const // сравнение
{
    return !(*this == s);
}
TSet TSet::operator+(const TSet& s) // объединение
{
    int len = (MaxPower > s.MaxPower) ? MaxPower : s.MaxPower;
    TSet res(len);

    res.BitField = BitField | s.BitField;
    return res;
}
TSet TSet::operator+(const int Elem) // объединение с элементом
{
    if (Elem >= MaxPower || Elem < 0) throw "error: index out of range";

    TSet res(*this);
    res.InsElem(Elem);
    return res;
}
TSet TSet::operator-(const int Elem) // разность с элементом
{
    if (Elem >= MaxPower || Elem < 0) throw "error: index out of range";

    TSet res(*this);
    res.DelElem(Elem);
    return res;
}
TSet TSet::operator*(const TSet& s) // пересечение
{
    int len = (MaxPower > s.MaxPower) ? MaxPower : s.MaxPower;
    TSet res(len);

    res.BitField = BitField & s.BitField;
    return res;
}
TSet TSet::operator~(void) // дополнение
{
    TSet res(MaxPower);
    res.BitField = ~BitField;
    return res;
}

// перегрузка ввода/вывода
istream& operator>>(istream& in, TSet& s) // ввод
{
    in >> s.BitField;
    return in;
}
ostream& operator<<(ostream& out, const TSet& s) // вывод
{
    out << s.BitField;
    return out;
}