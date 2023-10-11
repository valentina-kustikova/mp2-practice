// ННГУ, ВМК, Курс "Методы программирования-2", С++, ООП
//
// tbitfield.cpp - Copyright (c) Гергель В.П. 07.05.2001
//   Переработано для Microsoft Visual Studio 2008 Сысоевым А.В. (19.04.2015)
//
// Битовое поле

#include "tbitfield.h"
#include <iostream>

TBitField::TBitField(int len)
{
 
    if (len < 0)
        throw "out of range";
    BitLen = len;
    MemLen = BitLen / Bits + 1;
    pMem = new TELEM[MemLen];
    for (int i = 0; i < MemLen; i++) {
        pMem[i] = 0;
    }
}

TBitField::TBitField(const TBitField &bf) // конструктор копирования
{
    BitLen = bf.BitLen;
    MemLen = bf.MemLen;
    pMem = new TELEM[MemLen];
    for (int i = 0; i < MemLen; ++i){
        pMem[i] = bf.pMem[i];
    }
}

TBitField::~TBitField()
{
    delete[] pMem;
}

int TBitField::GetMemIndex(const int n) const // индекс Мем для бита n
{
    if (n < 0)
        throw "out of range";
    return n / Bits;
   
}

TELEM TBitField::GetMemMask(const int n) const // битовая маска для бита n
{
    return 1 << (n & (Bits - 1));
}

// доступ к битам битового поля

int TBitField::GetLength(void) const // получить длину (к-во битов)
{
    return BitLen;
}

void TBitField::SetBit(const int n) // установить бит
{
    if (n >= BitLen || n < 0)
        throw "out of range";
    pMem[GetMemIndex(n)] |= GetMemMask(n);
}

void TBitField::ClrBit(const int n) // очистить бит
{
    if (n >= BitLen || n < 0)
        throw "out of range";

    pMem[GetMemIndex(n)] &= ~(GetMemMask(n));
}

int TBitField::GetBit(const int n) const // получить значение бита
{
    if (n >= BitLen || n < 0)
        throw "out of range";
    if (pMem[GetMemIndex(n)] & GetMemMask(n)) 
        return 1; 
    else return 0;
}

// битовые операции

TBitField& TBitField::operator=(const TBitField &bf) // присваивание
{
    if (*this == bf) 
        return *this;
    BitLen = bf.BitLen;
    if (MemLen != bf.MemLen) {
        MemLen = bf.MemLen;
        delete[] pMem;
        pMem = new TELEM[MemLen];
    }

    for (int i = 0; i < MemLen; i++) {
        pMem[i] = bf.pMem[i];
    }
    return *this;
}

int TBitField::operator==(const TBitField &bf) const // сравнение
{
    if (BitLen != bf.BitLen)
        return 0;

    for (int i = 0; i < MemLen; i++)
        if (pMem[i] != bf.pMem[i])
            return 0;

    return 1;
}

int TBitField::operator!=(const TBitField &bf) const // сравнение
{
    return !((*this) == bf);
}

TBitField TBitField::operator|(const TBitField &bf) // операция "или"
{
    int len = max(BitLen, bf.BitLen);
    TBitField result(len);
    for (int i = 0; i < result.MemLen; i++)
        result.pMem[i] = pMem[i] | bf.pMem[i];
    return result;
}

TBitField TBitField::operator&(const TBitField &bf) // операция "и"
{
    int len = max(BitLen, bf.BitLen);
    TBitField result(len);
    for (int i = 0; i < result.MemLen; i++) {
        result.pMem[i] = pMem[i] & bf.pMem[i];
    }
    return result;
}

TBitField TBitField::operator~(void) // отрицание
{
    TBitField result(BitLen);
    for (int i = 0; i < BitLen; i++)
        if (GetBit(i)) 
            result.ClrBit(i);
        else result.SetBit(i);
    return result;
}

// ввод/вывод

istream &operator>>(istream &istr, TBitField &bf) // ввод
{
    int bit;
    for (int i = 0; i < bf.BitLen; i++) 
    {
        istr >> bit;
        if (bit == 0) 
        {
            bf.ClrBit(i);
        }
        else if (bit == 1) 
        {
            bf.SetBit(i);
        }
        else 
        {
            throw ("Error");
        }
    }
    return istr;
}

ostream &operator<<(ostream &ostr, const TBitField &bf) // вывод
{
    ostr << "{ ";
    for (int i = bf.BitLen - 1; i >= 0; i--)
    {
        ostr << bf.GetBit(i) << " ";
    }
    ostr << "}";
    return ostr;
}
