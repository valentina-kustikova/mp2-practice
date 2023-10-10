#include "tset.h"
#include "tbitfield.h"

TSet::operator TBitField() {
    TBitField tmp(BitField);
    return tmp;
}

int TSet::GetMaxPower(void) const {
    return MaxPower;
}

void TSet::InsElem(const int Elem) {
    if (Elem >= MaxPower)
        throw std::exception("Elem is out of univers");

    BitField.SetBit(Elem);
}

void TSet::DelElem(const int Elem) {
    if (Elem >= MaxPower)
        throw std::exception("Elem is out of univers");

    BitField.ClrBit(Elem);
}

int TSet::IsMember(const int Elem) const {
    return BitField.GetBit(Elem);
}

int TSet::operator==(const TSet& s) const {
    return BitField == s.BitField;
}

int TSet::operator!=(const TSet& s) const {
    return !(*this == s);
}

TSet& TSet::operator=(const TSet& s) {
    MaxPower = s.MaxPower;
    BitField = s.BitField;

    return *this;
}

TSet TSet::operator+(const int Elem) {
    TSet res(BitField);
    res.InsElem(Elem);
    return res;
}

TSet TSet::operator- (const int Elem) {
    TSet res(BitField);
    res.DelElem(Elem);
    return res;
}

TSet TSet::operator+(const TSet& s) {
    if (MaxPower != s.MaxPower)
        throw std::exception("Different size of set's universes");

    return TSet(BitField | s.BitField);
}

TSet TSet::operator*(const TSet& s) {
    if (MaxPower != s.MaxPower)
        throw std::exception("Different size of set's universes");

    return TSet(BitField & s.BitField);
}

TSet TSet::operator~(void) {
    return TSet(~BitField);
}