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
    if (len < 0) {
        throw "error";
    }
    BitLen = len;
    MemLen = (len / (sizeof(TELEM) * 8)) + 1;
    pMem = new TELEM[MemLen];
    for (int i = 0; i < MemLen; i++) {
        pMem[i] = 0;
    }
}

TBitField::TBitField(const TBitField &bf) // конструктор копирования
{
    BitLen = bf.BitLen;
    MemLen = bf.MemLen;
    if (MemLen) {
        pMem = new TELEM[MemLen];
        for (int i = 0; i < MemLen; i++)
        {
            pMem[i] = bf.pMem[i];
        }
    }
    else {
        pMem = nullptr;
    }
}

TBitField::~TBitField()
{
    if (pMem != nullptr)
        delete[] pMem;
}

int TBitField::GetMemIndex(const int n) const // индекс Мем для бита n
{
    if (n < 0)
        throw" error: n < 0 !!!";
    return (n) / (sizeof(TELEM) * 8);
}

TELEM TBitField::GetMemMask(const int n) const // битовая маска для бита n
{
    return 1 << (n % (8 * sizeof(TELEM)));
}

// доступ к битам битового поля

int TBitField::GetLength(void) const // получить длину (к-во битов)
{
    return BitLen;
}

void TBitField::SetBit(const int n) // установить бит
{
    if (n >= BitLen || n < 0)
        throw "eroor: list of range";
    pMem[GetMemIndex(n)] |= GetMemMask(n);
}

void TBitField::ClrBit(const int n) // очистить бит
{
    if (n >= BitLen || n < 0)
        throw "error: list of range";

    pMem[GetMemIndex(n)] &= ~(GetMemMask(n));
}

int TBitField::GetBit(const int n) const // получить значение бита
{
    if ((n >= BitLen) || (n < 0))
        throw "error: wrong number";
    int index = GetMemIndex(n);
    TELEM mask = GetMemMask(n);
    return (pMem[index] & mask) != 0 ? 1 : 0; 
}

// битовые операции

const TBitField& TBitField::operator=(const TBitField &bf) // присваивание
{
    if (this == &bf)
    {
        return *this;
    }

    if (MemLen != bf.MemLen)
    {
        if (MemLen > 0)
        {
            delete[] pMem;            
        }
        MemLen = bf.MemLen;
        pMem = new TELEM[MemLen];
    }
    BitLen = bf.BitLen;
    for (int i = 0; i < MemLen; ++i)
    {
        pMem[i] = bf.pMem[i];
    }
    return *this;
}

int TBitField::operator==(const TBitField &bf) const // сравнение
{
 
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

int TBitField::operator!=(const TBitField &bf) const // сравнение
{
    return !(*this == bf);
}

TBitField TBitField::operator|(const TBitField &bf) // операция "или"
{
    int len = max(BitLen, bf.BitLen);
    TBitField result(len);

    for (int i = 0; i < MemLen; i++)
    {
        result.pMem[i] = pMem[i];
    }
    for (int i = 0; i < bf.MemLen; i++)
    {
        result.pMem[i] |= bf.pMem[i];
    }
    return result;
}

TBitField TBitField::operator&(const TBitField &bf) // операция "и"
{
    int len = max(BitLen, bf.BitLen);
    TBitField result(len);

    for (int i = 0; i < MemLen; i++)
    {
        result.pMem[i] = pMem[i];
    }
    for (int i = 0; i < bf.MemLen; i++)
    {
        result.pMem[i] &= bf.pMem[i];
    }
    return result;
}

TBitField TBitField::operator~(void) // отрицание
{
    TBitField result(BitLen);
    for (int i = 0; i < BitLen; i++)
    {
        if (GetBit(i) == 0)
            result.SetBit(i);
    }
    return result;
}

// ввод/вывод

istream &operator>>(istream &istr, TBitField &bf) // ввод
{
    string str;
    istr >> str;
    for (int i = 0; i < bf.BitLen; i++)
    {
        int bit = str[i] - '0';
        if (bit == 1)
            bf.SetBit(i);
        if (bit == 0)
            bf.ClrBit(i);
    }
    return istr;
}

ostream &operator<<(ostream &ostr, const TBitField &bf) // вывод
{
    for (int i = 0; i < bf.GetLength(); ++i)
    {
        ostr << bf.GetBit(i) << " ";
    }
    ostr << "\n";
    return ostr;
}
