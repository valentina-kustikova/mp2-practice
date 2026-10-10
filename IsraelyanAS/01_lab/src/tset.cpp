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
    if (mp<0) {
        throw std::out_of_range("0");
    }
    this->MaxPower = mp;
    //BitField = TBitField(mp);
}

// конструктор копирования
TSet::TSet(const TSet& s) : BitField(s.BitField)
{
    MaxPower = s.MaxPower;
    BitField = s.BitField;

}

// конструктор преобразования типа
TSet::TSet(const TBitField& bf) : BitField(bf)
{
    MaxPower = bf.GetLength();
    //BitField = bf;
}

TSet::operator TBitField()
{
    return BitField;
    //return FAKE_BITFIELD;
}

int TSet::GetMaxPower(void) const // получить макс. к-во эл-тов
{
    return MaxPower;
    //return FAKE_INT;
}

int TSet::IsMember(const int Elem) const // элемент множества?
{
    if (Elem<0 || Elem >= BitField.GetLength()) {
        throw std::out_of_range("0");
    }
    return BitField.GetBit(Elem);
    //return FAKE_INT;
}

void TSet::InsElem(const int Elem) // включение элемента множества
{
    if (Elem<0 || Elem >= BitField.GetLength()) {
        throw std::out_of_range("0");
    }
    BitField.SetBit(Elem);
}

void TSet::DelElem(const int Elem) // исключение элемента множества
{
    if (Elem<0 || Elem >= BitField.GetLength()) {
        throw std::out_of_range("0");
    }
    BitField.ClrBit(Elem);
}

// теоретико-множественные операции

const TSet& TSet::operator=(const TSet& s) // присваивание
{
    if (this == &s) {
        return *this;
    }
    else {
        MaxPower = s.MaxPower;
        BitField = s.BitField;
        return *this;
    }
}

int TSet::operator==(const TSet& s) const // сравнение
{
    if (MaxPower != s.MaxPower) {
        return 0;
    }
    return BitField == s.BitField;
}

int TSet::operator!=(const TSet& s) const // сравнение
{
    if (MaxPower != s.MaxPower) {
        return 1;
    }
    return BitField != s.BitField;
}

TSet TSet::operator+(const TSet& s) // объединение
{
    int len = max(BitField.GetLength(), s.BitField.GetLength());
    TSet res(len);
    res.BitField = BitField | s.BitField;
    return res;
}

TSet TSet::operator+(const int Elem) // объединение с элементом
{
    TSet res(*this);
    res.InsElem(Elem);
    return res;
}

TSet TSet::operator-(const int Elem) // разность с элементом
{
    if (Elem<0 || Elem > BitField.GetLength()) {
        throw std::out_of_range("0");
    }
    TSet res(*this);
    res.DelElem(Elem);
    return res;
}

TSet TSet::operator*(const TSet& s) // пересечение
{
    int len = max(BitField.GetLength(), s.BitField.GetLength());
    TSet res(len);
    res.BitField = BitField & s.BitField;
    return res;
}

TSet TSet::operator~(void) // дополнение
{
    TSet res(*this);
    res.BitField = ~BitField;
    return res;
}

// перегрузка ввода/вывода

istream& operator>>(istream& istr, TSet& s) // ввод
{
    istr >> s.BitField;
    return istr;
}

ostream& operator<<(ostream& ostr, const TSet& s) // вывод
{
    ostr << s.BitField << "\t";
    return ostr;
}