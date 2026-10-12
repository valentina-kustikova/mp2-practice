// ННГУ, ВМК, Курс "Методы программирования-2", С++, ООП
//
// tbitfield.cpp - Copyright (c) Гергель В.П. 07.05.2001
// Переработано для Microsoft Visual Studio 2008 Сысоевым А.В. (19.04.2015)
//
// Битовое поле

#include "tbitfield.h"

// Fake variables used as placeholders in tests
static const int FAKE_INT = -1;
static TBitField FAKE_BITFIELD(1);


TBitField::TBitField(int len) {
    if (len < 0) throw std::invalid_argument("length cannot be negative");
    BitLen = len;
    MemLen = (BitLen + size_of_Memlen - 1) / size_of_Memlen;
    pMem = new TELEM[MemLen];
    for (int i = 0; i < MemLen; i++) {
        pMem[i] = 0;
    }
}

TBitField::TBitField(const TBitField& bf) {
    BitLen = bf.BitLen;
    MemLen = bf.MemLen;
    pMem = new TELEM[MemLen];
    for (int i = 0; i < MemLen; i++) {
        pMem[i] = bf.pMem[i];
    }
}

TBitField::~TBitField() {
    delete[] pMem;
}

int TBitField::GetMemIndex(const int n) const {
    if (n < 0 || n >= BitLen) throw std::out_of_range("index out of range");
    return n / size_of_Memlen;
}

TELEM TBitField::GetMemMask(const int n) const {
    return 1 << (n % size_of_Memlen);
}

// доступ к битам битового поля

int TBitField::GetLength(void) const {
    return BitLen;
}

void TBitField::SetBit(const int n) {
    if (n < 0 || n >= BitLen) throw std::out_of_range("index out of range");
    pMem[GetMemIndex(n)] = pMem[GetMemIndex(n)] | GetMemMask(n);
}

void TBitField::ClrBit(const int n) {
    if (n < 0 || n >= BitLen) throw std::out_of_range("index out of range");
    pMem[GetMemIndex(n)] = pMem[GetMemIndex(n)] & ~GetMemMask(n);

    int lastbit = BitLen % size_of_Memlen;
    if (lastbit == 0) return;

    for (int i = lastbit; i < size_of_Memlen; i++) {
        pMem[MemLen - 1] &= ~(1 << i);
    }
}

int TBitField::GetBit(const int n) const {
    if (n < 0 || n >= BitLen) throw std::out_of_range("index out of range");
    return (pMem[GetMemIndex(n)] & GetMemMask(n)) != 0;
}

// битовые операции

const TBitField& TBitField::operator=(const TBitField& bf) {
    if (this == &bf) return *this;
    if (MemLen == bf.MemLen) {
        BitLen = bf.BitLen;
        for (int i = 0; i < MemLen; i++) {
            pMem[i] = bf.pMem[i];
        }
    }
    else {
        delete[] pMem;
        BitLen = bf.BitLen;
        MemLen = bf.MemLen;
        pMem = new TELEM[MemLen];
        for (int i = 0; i < MemLen; i++) {
            pMem[i] = bf.pMem[i];
        }
    }
    return *this;
}

int TBitField::operator==(const TBitField& bf) const {
    if (BitLen != bf.BitLen) return 0;
    for (int i = 0; i < MemLen; i++) {
        if (pMem[i] != bf.pMem[i]) return 0;
    }
    return 1;
}

int TBitField::operator!=(const TBitField& bf) const {
    if (*this == bf) return 0;
    return 1;
}

TBitField TBitField::operator|(const TBitField& bf) {
    int maxLen = (BitLen > bf.BitLen) ? BitLen : bf.BitLen;
    TBitField res(maxLen);
    int minMemLen = (MemLen < bf.MemLen) ? MemLen : bf.MemLen;

    for (int i = 0; i < minMemLen; i++) {
        res.pMem[i] = pMem[i] | bf.pMem[i];
    }
    if (MemLen > bf.MemLen) {
        for (int i = minMemLen; i < MemLen; i++) {
            res.pMem[i] = pMem[i];
        }
    }
    else {
        for (int i = minMemLen; i < bf.MemLen; i++) {
            res.pMem[i] = bf.pMem[i];
        }
    }
    return res;
}

TBitField TBitField::operator&(const TBitField& bf) {
    int maxLen = (BitLen > bf.BitLen) ? BitLen : bf.BitLen;
    TBitField res(maxLen);
    int minMemLen = (MemLen < bf.MemLen) ? MemLen : bf.MemLen;

    for (int i = 0; i < minMemLen; i++) {
        res.pMem[i] = pMem[i] & bf.pMem[i];
    }
    return res;
}

TBitField TBitField::operator~(void) {
    TBitField res(BitLen);
    for (int i = 0; i < MemLen; i++) {
        res.pMem[i] = ~pMem[i];
    }
    int lastBits = BitLen % size_of_Memlen;
    if (lastBits != 0) {
        for (int i = lastBits; i < size_of_Memlen; i++) {
            res.pMem[MemLen - 1] = res.pMem[MemLen - 1] & ~(1 << i);
        }   
    }
    return res;
}

// ввод/вывод

istream& operator>>(istream& istr, TBitField& bf) {
    for (int i = 0; i < bf.BitLen; i++) {
        int bit;
        istr >> bit;
        if (bit) {
            bf.SetBit(i);
        }
        else {
            bf.ClrBit(i);
        }
    }
    return istr;
}

ostream& operator<<(ostream& ostr, const TBitField& bf) // вывод
{
    for (int i = 0; i < bf.BitLen; i++) {
        ostr << bf.GetBit(i);
    }
    return ostr;
}