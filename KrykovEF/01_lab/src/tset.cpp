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

TSet::TSet(int mp) : BitField(TBitField(mp))
{
    this->MaxPower = mp;
}

// конструктор копирования
TSet::TSet(const TSet &s) : BitField(TBitField(s.BitField))
{
    this->MaxPower = s.MaxPower;
}

// конструктор преобразования типа
TSet::TSet(const TBitField &bf) : BitField(TBitField(bf))
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

const TSet& TSet::operator=(const TSet &s) // присваивание
{
    this->MaxPower = s.MaxPower;
    this->BitField = s.BitField;
    return *this;
}

int TSet::operator==(const TSet &s) const // сравнение
{
    if (this->MaxPower != s.MaxPower) {
        return 0;
    }
    return this->BitField == s.BitField;
}

int TSet::operator!=(const TSet &s) const // сравнение
{
    if (this->MaxPower != s.MaxPower) {
        return 1;
    }
    return this->BitField != s.BitField;;
}

TSet TSet::operator+(const TSet &s) // объединение
{
    this->MaxPower = max(this->MaxPower, s.MaxPower);
    this->BitField = this->BitField | s.BitField;
    return *this;
}

TSet TSet::operator+(const int Elem) // объединение с элементом
{
    this->BitField.SetBit(Elem);
    return *this;
}

TSet TSet::operator-(const int Elem) // разность с элементом
{
    this->BitField.ClrBit(Elem);
    return *this;
}

TSet TSet::operator*(const TSet &s) // пересечение
{
    this->MaxPower = max(this->MaxPower, s.MaxPower);
    this->BitField = this->BitField & s.BitField;
    return *this;
}

TSet TSet::operator~(void) // дополнение
{
    this->BitField = ~(this->BitField);
    return *this;
}

// перегрузка ввода/вывода

istream &operator>>(istream &istr, TSet &s) // ввод (откуда?)
{
    return istr;
}

ostream& operator<<(ostream &ostr, const TSet &s) // вывод
{
    ostr << s.BitField;
    return ostr;
}
