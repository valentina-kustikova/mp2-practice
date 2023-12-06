// ННГУ, ВМК, Курс "Методы программирования-2", С++, ООП
//
// tbitfield.cpp - Copyright (c) Гергель В.П. 07.05.2001
//   Переработано для Microsoft Visual Studio 2008 Сысоевым А.В. (19.04.2015)
//
// Битовое поле

#include "tbitfield.h"
#define UnsignedInt 32

TBitField::TBitField(int len)
{
    if (len <= 0)
        throw "the length is specified incorrectly";
    if (len > 0)
    {

        BitLen = len;
        MemLen = ((BitLen - 1) / UnsignedInt) + 1;
        pMem = new TELEM[MemLen];

        for (int i = 0; i < MemLen; i++)
        {
            pMem[i] = 0;
        }

    }
    
}

TBitField::TBitField(const TBitField &bf) // конструктор копирования
{
    BitLen = bf.BitLen;
    MemLen = bf.MemLen;
    pMem = new TELEM[MemLen];
    for (int i = 0; i < MemLen; i++)
    {
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
        throw" n < 0 !!!"; 
    return (n ) / UnsignedInt;
}

TELEM TBitField::GetMemMask(const int n) const // битовая маска для бита n
{
    if ((n >= BitLen)|| (n < 0))
        throw "wrong number";
    return 1 << (n % (UnsignedInt));
    
}

// доступ к битам битового поля

int TBitField::GetLength(void) const // получить длину (к-во битов)
{
    return BitLen;
}

void TBitField::SetBit(const int n) // установить бит
{
    if ((n >= BitLen) || (n < 0))
        throw "wrong number";
    if ((n >= 0) && (n < BitLen))
        pMem[GetMemIndex(n)] |= GetMemMask(n);
}

void TBitField::ClrBit(const int n) // очистить бит
{
    int index = GetMemIndex(n);
    int BitIndex = n % UnsignedInt;
    unsigned int element = pMem[index];
    unsigned int BitMask = ~(GetMemMask(BitIndex));
    pMem[index] = element & BitMask;
}

int TBitField::GetBit(const int n) const // получить значение бита
{
    if ((n >= BitLen) || (n < 0))
        throw "wrong number";
    else
    {
        int index = GetMemIndex(n);// индекс элемента массива
        int BitIndex = n % UnsignedInt;//индекс бита в элементе массива 
        unsigned int element = pMem[index];
        unsigned int bitMask = GetMemMask(BitIndex);
        return(element & bitMask) != 0;
    }

}

// битовые операции

TBitField& TBitField::operator=(const TBitField& bf) // присваивание
{
    if (this != &bf)
    {
        if (BitLen != bf.BitLen)
        {
            delete[] pMem;
            pMem = new TELEM[MemLen];
        }

        MemLen = bf.MemLen;
        BitLen = bf.BitLen;
        for (int i = 0; i < MemLen; i++)
        {
            pMem[i] = bf.pMem[i];
        }

    }
    return *this;
}

int TBitField::operator==(const TBitField &bf) const // сравнение
{
    if (BitLen != bf.BitLen)
        return 0;
    else
    {
        for (int i = 0; i < BitLen; i++)
        {
            if (GetBit(i)!=bf.GetBit(i))
                return 0;
        }

    }

    return 1;
}

int TBitField::operator!=(const TBitField &bf) const // сравнение
{/*
    if (BitLen != bf.BitLen)
        return 1;
    else
    {
        for (int i = 0; i < BitLen; i++)
        {
            if (GetBit(i) != bf.GetBit(i))
                return 1;
        }

    }

    return 0;

*/
    return !((*this) == bf);
}

TBitField TBitField::operator&(const TBitField &bf) // операция "и"
{
    int maxLen = max(GetLength(), bf.GetLength());
    int minLen = min(GetLength(), bf.GetLength());
    TBitField tmp(maxLen);
    for (int i = 0; i < MemLen; i++)
    {
        tmp.pMem[i] = pMem[i];
    }
    for (int i = 0; i < bf.MemLen; i++)
    {
        tmp.pMem[i] &= bf.pMem[i];
    }
    return tmp;
}

TBitField TBitField::operator|(const TBitField& bf) // операция "или"
{
    int maxLen = max(GetLength(), bf.GetLength());
    int minLen = min(GetLength(), bf.GetLength());
    TBitField tmp(maxLen);

    for (int i = 0; i < MemLen; i++)
    {
        tmp.pMem[i] = pMem[i];
    }
    for (int i = 0; i < bf.MemLen; i++)
    {
        tmp.pMem[i] |= bf.pMem[i];
    }
    return tmp;
}

TBitField TBitField::operator~(void) // отрицание
{
    TBitField tmp(BitLen);
    for (int i = 0; i < BitLen; i++)
    {
        if (GetBit(i) == 0)
            tmp.SetBit(i);
    }
    return tmp;
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
    for (int i = 0; i < bf.BitLen; i++)
    {
        ostr << bf.GetBit(i);
    }
    return ostr;
}
