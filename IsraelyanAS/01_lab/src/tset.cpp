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

TSet::TSet(int mp) : BitField(-1)
{
    this->MaxPower = mp;
    BitField = TBitField(mp);
}

// конструктор копирования
TSet::TSet(const TSet &s) : BitField(-1)
{
    MaxPower = s.MaxPower;
    BitField = s.BitField;

}

// конструктор преобразования типа
TSet::TSet(const TBitField &bf) : BitField(-1)
{
    MaxPower = bf.GetLength();
    BitField = bf;
}

TSet::operator TBitField()
{
    return BitField;
    return FAKE_BITFIELD;
}

int TSet::GetMaxPower(void) const // получить макс. к-во эл-тов
{
    return MaxPower;
    return FAKE_INT;
}

int TSet::IsMember(const int Elem) const // элемент множества?
{
    return BitField.GetBit(Elem);
    return FAKE_INT;
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
    if (this == &s) {
        return 0;
    }
    else {
        MaxPower = s.MaxPower;
        BitField = s.BitField;
        return *this;
    }
    return FAKE_SET;
}

int TSet::operator==(const TSet &s) const // сравнение
{
    if (MaxPower != s.MaxPower) {
        return 0;
    }
    return BitField == s.BitField;
    return FAKE_INT;
}

int TSet::operator!=(const TSet &s) const // сравнение
{
    if (MaxPower != s.MaxPower) {
        return 1;
    }
    return BitField != s.BitField;
    return FAKE_INT;
}

TSet TSet::operator+(const TSet &s) // объединение
{
    int len = max(BitField.GetLength(), s.BitField.GetLength());
    TSet res(len);
    res.BitField = BitField | s.BitField;
    return res.BitField;
    return FAKE_SET;
}

TSet TSet::operator+(const int Elem) // объединение с элементом
{
    TSet res(max(BitField.GetLength(), Elem));
    res.BitField = BitField | Elem;
    return res.BitField;
    return FAKE_SET;
}

TSet TSet::operator-(const int Elem) // разность с элементом
{
    TSet res(max(BitField.GetLength(), Elem));
    res.BitField = BitField & (~Elem);
    return res.BitField;
    return FAKE_SET;
}

TSet TSet::operator*(const TSet &s) // пересечение
{
    int len = max(BitField.GetLength(), s.BitField.GetLength());
    TSet res(len);
    res.BitField = BitField & s.BitField;
    return res.BitField;
    return FAKE_SET;
}

TSet TSet::operator~(void) // дополнение
{
    return ~BitField;
    return FAKE_SET;
}

// перегрузка ввода/вывода

istream &operator>>(istream &istr, TSet &s) // ввод
{
    istr >> s.BitField;
    return istr;
}

ostream& operator<<(ostream &ostr, const TSet &s) // вывод
{
    ostr << s.BitField << "\t";
    return ostr;
}
