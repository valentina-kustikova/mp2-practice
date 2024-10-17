// ННГУ, ВМК, Курс "Методы программирования-2", С++, ООП
//
// tset.cpp - Copyright (c) Гергель В.П. 04.10.2001
//   Переработано для Microsoft Visual Studio 2008 Сысоевым А.В. (19.04.2015)
//
// Множество - реализация через битовые поля

#include "tset.h"

// Fake variables used as placeholders in tests
static const int FAKE_INT = -1;
static TBitField FAKE_BITFIELD(1);
static TSet FAKE_SET(1);

TSet::TSet(int mp) : BitField(mp)
{
    this->MaxPower = mp;
    this->BitField = TBitField(mp);
}

// конструктор копирования
TSet::TSet(const TSet& s) : BitField(s.BitField)
{
    this->MaxPower = s.MaxPower;
    this->BitField = s.BitField;
}

// конструктор преобразования типа
TSet::TSet(const TBitField& bf) : BitField(bf)
{
    this->MaxPower = bf.GetLength();
}

TSet::operator TBitField()
{
    return this->BitField;
}

int TSet::GetMaxPower(void) const // получить макс. к-во эл-тов
{
    return this->MaxPower;
}

int TSet::IsMember(const int Elem) const // элемент множества?
{
    if (Elem <= 0)
        throw Elem;
    return this->BitField.GetBit(Elem);
}

void TSet::InsElem(const int Elem) // включение элемента множества
{
    this->BitField.SetBit(Elem);
}

void TSet::DelElem(const int Elem) // исключение элемента множества
{
    this->BitField.ClrBit(Elem);
}

// теоретико-множественные операции

const TSet& TSet::operator=(const TSet& s) // присваивание
{
    this->BitField = s.BitField;
    this->MaxPower = s.MaxPower;
    return *this;
}

int TSet::operator==(const TSet& s) const // сравнение
{
    if (this->MaxPower == s.MaxPower)
    {
        if (this->BitField == s.BitField) {
            return 1;
        }
    }
    return 0;
}

int TSet::operator!=(const TSet& s) const // сравнение
{
    if (this->MaxPower != s.MaxPower)
    {
        if (this->BitField == s.BitField)
        {
            return 0;
        }      
    }
    return 1;
}

TSet TSet::operator+(const TSet& s) // объединение
{
    TBitField temp(MaxPower);
    temp = this->BitField | s.BitField;
    TSet new_temp(temp);
    return new_temp;
}

TSet TSet::operator+(const int Elem) // объединение с элементом
{
    TSet temp(*this);
    temp.BitField.SetBit(Elem);
    return temp;
}

TSet TSet::operator-(const int Elem) // разность с элементом
{
    TSet temp(*this);
    temp.BitField.ClrBit(Elem);
    return temp;
}

TSet TSet::operator*(const TSet& s) // пересечение
{
    TBitField temp(MaxPower);
    temp = this->BitField & s.BitField;
    TSet new_temp(temp);
    return new_temp;
}

TSet TSet::operator~(void) // дополнение
{
    TSet new_temp(MaxPower);
    new_temp.BitField = ~this->BitField;
    return new_temp;
}

// перегрузка ввода/вывода

istream& operator>>(istream& istr, TSet& s) // ввод
{
    int i = 0;
    while ((i >= 0) && (i < s.MaxPower))
    {
        s.InsElem(i);
        istr >> i;
    }
    return istr;
}

ostream& operator<<(ostream& ostr, const TSet& s) // вывод
{
    for (int i = 0; i < s.MaxPower; i++)
        if (s.BitField.GetBit(i))
            ostr << i;
    return ostr;
}
