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

TSet::TSet(int mp) : BitField(mp) {
    MaxPower = mp;
}

TSet::TSet(const TSet& s) : BitField(s.BitField) {
    MaxPower = s.MaxPower;
}

TSet::TSet(const TBitField& bf) : BitField(bf) {
    MaxPower = bf.GetLength();
}

TSet::operator TBitField() {
    return BitField;
}

int TSet::GetMaxPower(void) const {
    return MaxPower;
}

int TSet::IsMember(const int Elem) const {
    if (Elem < 0 || Elem >= MaxPower) return 0;
    return BitField.GetBit(Elem);
}

void TSet::InsElem(const int Elem) {
    if (Elem < 0 || Elem >= MaxPower) return;
    BitField.SetBit(Elem);
}

void TSet::DelElem(const int Elem) {
    if (Elem < 0 || Elem >= MaxPower) return;
    BitField.ClrBit(Elem);
}

// теоретико-множественные операции

const TSet& TSet::operator=(const TSet& s) {
    if (this == &s) return *this;
    MaxPower = s.MaxPower;
    BitField = s.BitField;
    return *this;
}

int TSet::operator==(const TSet& s) const {
    if (MaxPower != s.MaxPower) return 0;
    return BitField == s.BitField;
}

int TSet::operator!=(const TSet& s) const {
    if (*this == s) return 0;
    return 1;
}

TSet TSet::operator+(const TSet& s) {
    int newPower = (MaxPower > s.MaxPower) ? MaxPower : s.MaxPower;
    TSet res(newPower);
    res.BitField = BitField | s.BitField;
    return res;
}

TSet TSet::operator+(const int Elem) {
    if (Elem < 0 || Elem >= MaxPower) throw std::out_of_range("element out of universe");
    TSet res(*this);
    if (Elem >= 0 && Elem < MaxPower) {
        res.InsElem(Elem);
    }
    return res;
}

TSet TSet::operator-(const int Elem) {
    if (Elem < 0 || Elem >= MaxPower) throw std::out_of_range("element out of universe");
    TSet res(*this);
    if (Elem >= 0 && Elem < MaxPower) {
        res.DelElem(Elem);
    }
    return res;
}

TSet TSet::operator*(const TSet& s) {
    TBitField bf = BitField & s.BitField;
    return TSet(bf);
}

TSet TSet::operator~(void) {
    TSet res(*this);
    res.BitField = ~BitField;
    return res;
}

// перегрузка ввода/вывода

istream& operator>>(istream& istr, TSet& s) {
    for (int i = 0; i < s.GetMaxPower(); i++) {
        s.BitField.ClrBit(i);
    }
    int elem;
    while (istr >> elem) {
        if (elem < 0 || elem >= s.GetMaxPower()) {
            throw std::out_of_range("element out of universe");
        }
        s.InsElem(elem);
    }
    istr.clear();
    return istr;
}

ostream& operator<<(ostream& ostr, const TSet& s) {
    ostr << "{";
    bool first = true;
    for (int i = 0; i < s.MaxPower; i++) {
        if (s.BitField.GetBit(i)) {
            if (!first) ostr << ", ";
            ostr << i;
            first = false;
        }
    }
    ostr << "}";
    return ostr;
}