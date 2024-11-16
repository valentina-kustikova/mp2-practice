#include "tset.h"

TSet::TSet(int mp) : MaxPower(mp), BitField(mp)
{
}

TSet::TSet(const TSet& s) :MaxPower(s.MaxPower), BitField(s.BitField)
{
}

TSet::TSet(const TBitField& bf) :MaxPower(bf.GetLength()) ,BitField(bf)
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

const TSet& TSet::operator=(const TSet& s) 
{
    MaxPower = s.GetMaxPower();
    BitField = s.BitField;
    return *this;
}

int TSet::operator==(const TSet& s) const 
{
    return (BitField == s.BitField);
}

int TSet::operator!=(const TSet& s) const 
{
    return (BitField != s.BitField);
}

TSet TSet::operator+(const TSet& s) 
{
    TSet ts(max(GetMaxPower(), s.GetMaxPower()));
    ts.BitField = BitField | s.BitField;
    return ts;
}

TSet TSet::operator+(const int Elem) 
{
    TSet ts(BitField);
    ts.InsElem(Elem);
    return ts;
}

TSet TSet::operator-(const int Elem) 
{
    TSet ts(BitField);
    ts.DelElem(Elem);
    return *this;
}

TSet TSet::operator*(const TSet& s) 
{
    TSet t1(max(GetMaxPower(), s.GetMaxPower()));
    t1.BitField = BitField & s.BitField;
    return t1;
}

TSet TSet::operator~(void) 
{
    TSet ts(GetMaxPower());
    ts.BitField = ~BitField;
    return ts;
}

istream& operator>>(istream& istr, TSet& s)
{
    int n;
    do {
        cin >> n;
        s.InsElem(n);
    } while (s.GetMaxPower() <= n && n < 0);
    istr >> s;
    return istr;
}

ostream& operator<<(ostream& ostr, const TSet& s)
{
    for (int i = 0; i < s.GetMaxPower(); i++) {
        if (s.IsMember(i)) {
            ostr << i << " ";
        }

    }
    return ostr;
}