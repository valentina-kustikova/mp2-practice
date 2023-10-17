#include "tset.h"

TSet::TSet(int mp) :MaxPower(mp), BitField(mp) {}
TSet::TSet(const TSet& s) : BitField(s.BitField), MaxPower(s.GetMaxPower()) {}
TSet::TSet(const TBitField& bf) :MaxPower(bf.GetLength()), BitField(bf) {}
int TSet::GetMaxPower() const 
{
    return MaxPower;
}
TSet::operator TBitField() 
{ 
    return BitField;
}

int TSet::IsMember(const int Elem) const
{
    if (Elem >= MaxPower || Elem < 0) 
        throw ("Error: Element is out of universe");
    return BitField.GetBit(Elem);
}

void TSet::InsElem(const int Elem)
{
    if (Elem >= MaxPower || Elem < 0)  
        throw ("Error: Element is out of universe");
    return BitField.SetBit(Elem);
}

void TSet::DelElem(const int Elem)
{
    if (Elem >= MaxPower || Elem < 0) 
        throw ("Error: Element is out of universe");
    return BitField.ClrBit(Elem);
}

TSet& TSet::operator=(const TSet& s)
{
    if (this == &s)
        return *this;
    MaxPower = s.MaxPower;
    BitField = s.BitField;
    return *this;
}

int TSet::operator==(const TSet& s) const
{
    if (MaxPower != s.GetMaxPower())
    {
        return 0;
    }
    return (BitField == s.BitField);
}

int TSet::operator!=(const TSet& s) const {
    return !(*this == s);
}

TSet TSet::operator+(const TSet& s)
{
    TSet obj(max(MaxPower, s.GetMaxPower()));
    obj.BitField = BitField | s.BitField;
    return obj;
}

TSet TSet::operator+(const int Elem)
{
    if (Elem >= MaxPower || Elem < 0) 
        throw ("Error: Element is out of universe");
    TSet obj(*this);
    obj.InsElem(Elem);
    return obj;
}

TSet TSet::operator-(const int Elem)
{
    if (Elem >= MaxPower || Elem < 0) 
        throw ("Error: Elemet is out of universe");
    TSet obj(*this);
    obj.DelElem(Elem);
    return obj;
}

TSet TSet::operator*(const TSet& s)
{
    TSet obj(std::max(MaxPower, s.GetMaxPower()));
    obj.BitField = BitField & s.BitField;
    return obj;
}

TSet TSet::operator~(void)
{
    TSet obj(MaxPower);
    obj.BitField = ~BitField;
    return obj;
}
//

istream& operator>>(istream& istr, TSet& s)
{
    int elem;
    for (int i = 0; i < s.MaxPower; i++) {
        istr >> elem;
        if (elem < 0)
            break;
        s.InsElem(elem);
    }
    return istr;
}

ostream& operator<<(ostream& ostr, const TSet& s)
{
    const int Z = s.MaxPower - 1;
    for (int i = 0; i <= Z; ++i)
    {
        ostr << s.IsMember(i) << " ";
    }
    return ostr;
}