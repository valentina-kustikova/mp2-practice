#include "tbitfield.h"
#include <iostream>

TBitField::TBitField(int len) {
    if (len < 0) {
        throw invalid_argument("Length cannot be negative");
    }
    BitLen = len;
    MemLen = (len + bitsInElem - 1) / bitsInElem;
    pMem = new TELEM[MemLen];
    memset(pMem, 0, MemLen * sizeof(TELEM));
}

TBitField::TBitField(const TBitField& bf) {
    BitLen = bf.BitLen;
    MemLen = bf.MemLen;
    pMem = new TELEM[MemLen];
    memcpy(pMem, bf.pMem, MemLen * sizeof(TELEM));
}

TBitField::~TBitField() {
    delete[] pMem; 
}

int TBitField::GetMemIndex(const int n) const {
    if (n < 0 || n >= BitLen) {
        throw out_of_range("Bit index is out of range");
    }
    return n / bitsInElem;
}

TELEM TBitField::GetMemMask(const int n) const {
    if (n < 0 || n >= BitLen) {
        throw out_of_range("Bit index is out of range");
    }
    int bitIndex = n % bitsInElem;
    TELEM mask = 1; 
    mask <<= bitIndex; 
    return mask;
}

int TBitField::GetLength(void) const {
    return BitLen;
}

void TBitField::SetBit(const int n) {
    if (n < 0 || n >= BitLen) {
        throw out_of_range("Bit index is out of range");
    }
    int index = GetMemIndex(n);
    TELEM mask = GetMemMask(n); 
    pMem[index] |= mask;
}

void TBitField::ClrBit(const int n) {
    if (n < 0 || n >= BitLen) {
        throw out_of_range("Bit index is out of range");
    }
    int index = GetMemIndex(n); 
    TELEM mask = GetMemMask(n);
    pMem[index] &= ~mask;
}

int TBitField::GetBit(const int n) const {
    if (n < 0 || n >= BitLen) {
        throw out_of_range("Bit index is out of range");
    }
    int index = GetMemIndex(n);
    TELEM mask = GetMemMask(n); 
    return (pMem[index] & mask) ? 1 : 0; 
}

int TBitField::operator==(const TBitField& bf) const {
    if (BitLen != bf.BitLen) {
        return 0; 
    }
    for (int i = 0; i < MemLen; i++) {
        if (pMem[i] != bf.pMem[i]) {
            return 0; 
        }
    }
    return 1; 
}

int TBitField::operator!=(const TBitField& bf) const {
    return !(*this == bf); 
}

const TBitField& TBitField::operator=(const TBitField& bf) {
    if (this == &bf) {
        return *this; 
    }
    if (BitLen != bf.BitLen) {
        delete[] pMem; 
        BitLen = bf.BitLen;
        MemLen = bf.MemLen;
        pMem = new TELEM[MemLen];
    }
    for (int i = 0; i < MemLen; i++) {
        pMem[i] = bf.pMem[i]; 
    }
    return *this;
}

TBitField TBitField::operator|(const TBitField& bf) {
    int len = (BitLen > bf.BitLen) ? BitLen : bf.BitLen;
    TBitField result(len); 
    for (int i = 0; i < MemLen; i++) {
        result.pMem[i] = pMem[i] | bf.pMem[i];
    }
    return result;
}

TBitField TBitField::operator&(const TBitField& bf) {
    int len = (BitLen > bf.BitLen) ? BitLen : bf.BitLen;
    TBitField result(len); 
    for (int i = 0; i < MemLen; i++) {
        result.pMem[i] = pMem[i] & bf.pMem[i]; 
    }
    return result;
}

TBitField TBitField::operator~(void) {
    TBitField result(BitLen); 
    for (int i = 0; i < BitLen; i++) {
        if (!GetBit(i))
            result.SetBit(i);
    }
    return result;
}

istream& operator>>(istream& istr, TBitField& bf) {
    int inputBit;
    for (int i = 0; i < bf.BitLen; i++) {
        istr >> inputBit;
        if (inputBit == 0) {
            bf.ClrBit(i); 
        }
        else if (inputBit == 1) {
            bf.SetBit(i); 
        }
        else {
            throw invalid_argument("Invalid input. Use 0 or 1.");
        }
    }
    return istr;
}

ostream& operator<<(ostream& ostr, const TBitField& bf) {
    for (int i = 0; i < bf.BitLen; i++) {
        ostr << bf.GetBit(i) << " "; 
    }
    return ostr;
}