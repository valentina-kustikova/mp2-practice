#include "tset.h"
#include <sstream>
#include <string>

TSet::TSet(int mp) : BitField(mp), MaxPower(mp)
{
}

TSet::TSet(const TSet& tmp) : MaxPower(tmp.MaxPower), BitField(tmp.BitField)
{
}

TSet::TSet(const TBitField &bf) : BitField(bf), MaxPower(bf.GetLength())
{
}

TSet::operator TBitField()
{
    return BitField;
}

int TSet::GetMaxPower(void) const 
{
    return MaxPower;
}

int TSet::IsMember(const int Elem) const 
{
    return BitField.GetBit(Elem);
}

void TSet::InsElem(const int Elem) 
{
    BitField.SetBit(Elem);
}

void TSet::DelElem(const int Elem) 
{
    BitField.ClrBit(Elem);
}

// теоретико-множественные операции

const TSet& TSet::operator=(const TSet &tmp) 
{
    if (this != &tmp) {
        MaxPower = tmp.MaxPower;
        BitField = tmp.BitField;
    }
    return *this;
}

int TSet::operator==(const TSet &tmp) const 
{
    if (MaxPower == tmp.MaxPower) {
        return BitField == tmp.BitField;
    }
    return false;
}

int TSet::operator!=(const TSet &tmp) const 
{
    return !((*this) == tmp);
}

TSet TSet::operator+(const TSet &s) const 
{
    return TSet(BitField | s.BitField);
}

TSet TSet::operator+(const int Elem) const // объединение с элементом
{
    TSet res(*this);
    res.BitField.SetBit(Elem);
    return res;
}

TSet TSet::operator-(const int Elem) const // разность с элементом
{
    TSet res(*this);
    res.BitField.ClrBit(Elem);
    return res;
}

TSet TSet::operator*(const TSet &s) const
{
    return TSet(BitField & s.BitField);
}

TSet TSet::operator~(void) const
{
    return TSet(~BitField);
}

// перегрузка ввода/вывода

istream &operator>>(istream &is, TSet &s) 
{
    std::string numberline;
    getline(is, numberline);

    istringstream numberStream(numberline);
    TSet temp(s.MaxPower);

    int number;
    while (numberStream >> number) {
        if (number < 0 || number > s.MaxPower) {
            is.setstate(ios::failbit);
            return is;
        }
        temp.InsElem(number);
    }

    s = temp;
    return is;
}

ostream& operator<<(ostream& ostr, const TSet& s) {
    ostr << "{";

    bool first = true;
    for (int i = 0; i < s.MaxPower; i++) {
        if (s.IsMember(i)) {
            if (!first) ostr << ", ";
            ostr << i;
            first = false;
        }
    }

    ostr << '}';

    return ostr;
}
