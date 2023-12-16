// ННГУ, ВМК, Курс "Методы программирования-2", С++, ООП
//
// tbitfield.cpp - Copyright (c) Гергель В.П. 07.05.2001
//   Переработано для Microsoft Visual Studio 2008 Сысоевым А.В. (19.04.2015)
//
// Битовое поле

#include "tbitfield.h"

using namespace std;

TBitField::TBitField(int len)
{
    if (len < 0)
        throw exception("Negative size");
    BitLen = len;
    MemLen = (len + BitsInMem - 1) >> shiftSize;
    pMem = new TELEM[MemLen];
    memset(pMem, 0, MemLen * sizeof(TELEM));
}

TBitField::TBitField(const TBitField &bf) // конструктор копирования
{
    BitLen = bf.BitLen;
    MemLen = bf.MemLen;
    pMem = new TELEM[MemLen];
    memcpy(pMem, bf.pMem, MemLen * sizeof(TELEM));
}

TBitField::~TBitField()
{
    delete[] pMem;
}

int TBitField::GetMemIndex(const int n) const // индекс Мем для бита n
{
    return n >> shiftSize;
}

TELEM TBitField::GetMemMask(const int n) const // битовая маска для бита n
{
    return 1 << (n & (BitsInMem - 1));
}

// доступ к битам битового поля

int TBitField::GetLength(void) const // получить длину (к-во битов)
{
    return BitLen;
}

void TBitField::SetBit(const int n) // установить бит
{
    if (n < 0 || n >= BitLen) {
        throw exception("Negative length");
    }
    pMem[GetMemIndex(n)] = pMem[GetMemIndex(n)] | GetMemMask(n);
}

void TBitField::ClrBit(const int n) // очистить бит
{
    if (n < 0 || n >= BitLen) {
        throw exception("Negative length");
    }
    pMem[GetMemIndex(n)] = pMem[GetMemIndex(n)] & ~GetMemMask(n);
}

int TBitField::GetBit(const int n) const // получить значение бита
{
    if (n < 0 || n >= BitLen) {
        throw exception("Negative length");
    }
    return (pMem[GetMemIndex(n)] & GetMemMask(n));
}

// битовые операции

TBitField& TBitField::operator=(const TBitField &bf) // присваивание
{
    if (this == &bf)
        return *this;
    BitLen = bf.BitLen;
    if (MemLen != bf.MemLen) {
        TELEM* p = new TELEM[bf.MemLen];
        MemLen = bf.MemLen;
        delete[] pMem;
        pMem = p;
    }
    memcpy(pMem, bf.pMem, MemLen);
    return *this;
}

int TBitField::operator==(const TBitField &bf) const // сравнение
{
    if (BitLen != bf.BitLen)
        return false;
    for (size_t i = 0; i < MemLen; i++)
        if (pMem[i] != bf.pMem[i])
            return false;
    return true;
}

int TBitField::operator!=(const TBitField &bf) const // сравнение
{
    return !(*this == bf);
}

TBitField TBitField::operator|(const TBitField &bf) // операция "или"
{
    const TBitField* max_field = this;
    int min_size = bf.BitLen;
    if (BitLen < min_size) {
        max_field = &bf;
        min_size = BitLen;
    }
    TBitField tmp(*max_field);
    for (int i = 0; i < min_size; i++)
        if ((GetBit(i) || bf.GetBit(i)) == 1)
            tmp.SetBit(i);
    return tmp;
}

TBitField TBitField::operator&(const TBitField &bf) // операция "и"
{
    int max_size = BitLen;
    int min_size = bf.BitLen;
    if (bf.BitLen > max_size) {
        max_size = bf.BitLen;
        min_size = BitLen;
    }
    TBitField tmp(max_size);
    for (int i = 0; i < min_size; i++)
        if ((GetBit(i) && bf.GetBit(i)) == 1)
            tmp.SetBit(i);
    return tmp;
}

TBitField TBitField::operator~(void) // отрицание
{
    TBitField tmp = (*this);
    for (int i = 0; i < BitLen; i++) {
        if (tmp.GetBit(i))
            tmp.ClrBit(i);
        else
            tmp.SetBit(i);
    }
    return tmp;
}