#include "tbitfield.h"

TBitField::TBitField(int len)
{
    if (len <= 0) {
        throw("Некорректная длина множества!");
    }
    BitLen = len;
    MemLen = (len + BitSize - 1) / BitSize;
    pMem = new TELEM[MemLen];
    memset(pMem, 0, sizeof(TELEM) * MemLen);
    
}

TBitField::TBitField(const TBitField &tmp) 
{
    BitLen = tmp.BitLen;
    MemLen = tmp.MemLen;
    pMem = new TELEM[MemLen];
    for (int i = 0; i < MemLen; i++) {
        pMem[i] = tmp.pMem[i];
    }
}

TBitField::~TBitField()
{
    delete[] pMem;
}

int TBitField::GetMemIndex(const int n) const 
{ 
    if (n < 0 || n >= BitLen) {
        throw("Некорректный индекс!");
    }
    return n >> BitShift;
    
}

TELEM TBitField::GetMemMask(const int n) const
{
    if (n < 0 || n >= BitLen) {
        throw("Некорректный индекс!");
    }
    return 1 << (n & (BitSize - 1));
}

int TBitField::GetLength(void) const 
{
  return BitLen;
}

void TBitField::SetBit(const int n) 
{
    if (n < 0 || n >= BitLen) {
        throw("Некорректный индекс!");
    }
    pMem[n >> BitShift] |= GetMemMask(n);
}

void TBitField::ClrBit(const int n) 
{
    if (n < 0 || n >= BitLen) {
        throw("Некорректный индекс!");
    }
    pMem[n >> BitShift] &= ~GetMemMask(n);
    
}

int TBitField::GetBit(const int n) const 
{
    if (n < 0 || n >= BitLen) {
        throw("Некорректный индекс!");
    }
    return (pMem[n >> BitShift] & GetMemMask(n));
}


const TBitField& TBitField::operator=(const TBitField &tmp) 
{
    if (this == &tmp) {
        return *this;
    }
    
    if (MemLen != tmp.MemLen) {
        MemLen = tmp.MemLen;
        delete[] pMem;
        pMem = new TELEM[MemLen];
    }
    BitLen = tmp.BitLen;
    for (int i = 0; i < MemLen; i++) {
        pMem[i] = tmp.pMem[i];
    }
    
    return (*this);
}

int TBitField::operator==(const TBitField &tmp) const 
{
    if (this->BitLen == tmp.BitLen) {
        for (int i = 0; i < MemLen; i++) {
            if (pMem[i] != tmp.pMem[i]) {
                return false;
            }
        }
        return true;
    }

  return false;
}

int TBitField::operator!=(const TBitField &tmp) const 
{
    return !((*this) == tmp);
}

TBitField TBitField::operator|(const TBitField& tmp) const
{
    const TBitField& MaxLenTBitfield = (this->BitLen > tmp.BitLen) ? *this : tmp;
    const TBitField& MinLenTBitfield = (this->BitLen <= tmp.BitLen) ? *this : tmp;

    TBitField res(MaxLenTBitfield);
    for (int i = 0; i < MinLenTBitfield.MemLen; i++) {
        res.pMem[i] |= MinLenTBitfield.pMem[i];
    }

    return res;
}

TBitField TBitField::operator&(const TBitField& tmp) const
{
    const TBitField& MaxLenTBitfield = (this->BitLen > tmp.BitLen) ? *this : tmp;
    const TBitField& MinLenTBitfield = (this->BitLen <= tmp.BitLen) ? *this : tmp;

    TBitField res(MaxLenTBitfield);
    for (int i = 0; i < MinLenTBitfield.MemLen; i++) {
        res.pMem[i] &= MinLenTBitfield.pMem[i];
    }

    for (int i = MinLenTBitfield.MemLen; i < MaxLenTBitfield.MemLen; i++) {
        res.pMem[i] = 0;
    }
    return res;
}

TBitField TBitField::operator~(void) const
{
    TBitField res(BitLen); 
    for (int i = 0; i < MemLen; i++) {
        res.pMem[i] = ~(this->pMem[i]);
    }

    int used = BitLen % BitSize;
    if (used != 0) {
        TELEM mask = (1 << used) - 1;
        res.pMem[MemLen - 1] &= mask;
    }
    return res;
}

istream &operator>>(istream &is, TBitField &tmp) 
{
    std::string sField;
    is >> sField;

    if (sField.size() != tmp.BitLen) {
        is.setstate(ios::failbit);
        return is;
    }

    TBitField newTmp(tmp.BitLen);
    for (int i = 0; i < tmp.BitLen; i++) {
        if (sField[i] == '1') {
            newTmp.SetBit(tmp.BitLen - 1 - i);
        }
        else if (sField[i] != '0') {
            is.setstate(ios::failbit);
            return is;
        }
    }
    tmp = newTmp;

    return is;
}

ostream &operator<<(ostream &os, const TBitField &tmp) 
{
    std::string sField;
    sField.reserve(tmp.BitLen);
    for (int i = tmp.BitLen - 1; i >= 0; i--) {
        sField += tmp.GetBit(i) ? '1' : '0';
    }

    os << sField;
    return os;
}