// ННГУ, ВМК, Курс "Методы программирования-2", С++, ООП
//
// tbitfield.cpp - Copyright (c) Гергель В.П. 07.05.2001
//   Переработано для Microsoft Visual Studio 2008 Сысоевым А.В. (19.04.2015)
//
// Битовое поле

#include "tbitfield.h"

TBitField::TBitField(int len)
{
    if (len <= 0)
        throw "len_is_equal_zero!";
    BitLen = len;
    MemLen = ((len + bitsInElem - 1) >> shiftSize);
    pMem = new TELEM[MemLen];

    for (int i = 0; i < MemLen; ++i)
    {
        pMem[i] = 0;
    }
}

TBitField::TBitField(const TBitField &bf) // конструктор копирования
{
    BitLen = bf.BitLen;
    MemLen = bf.MemLen;
    pMem = new TELEM[MemLen];
    for (int i = 0; i < MemLen; ++i)
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
        throw "n_is_below_zero";
    return n >> shiftSize; //сдвиг n вправо на shiftSize бит
}

TELEM TBitField::GetMemMask(const int n) const // битовая маска для бита n 
{
    if (n > BitLen)
        throw "overload_n";
    if (n < 0)
        throw "n_is_below_zero";
    return 1 << (n & (bitsInElem - 1)); //сдвиг 1 влево на (n & (bitsInElem - 1)) бит
}

// доступ к битам битового поля

int TBitField::GetLength(void) const // получить длину (к-во битов)
{
    return BitLen;
}

void TBitField::SetBit(const int n) // установить бит 
{
    if (n > BitLen)
        throw "overload_n";
    if (n < 0)
        throw "n_is_below_zero";

    pMem[GetMemIndex(n)] |= GetMemMask(n);;
}

void TBitField::ClrBit(const int n) // очистить бит 
{
    if (n > BitLen)
        throw "overload_n";
    if (n < 0)
        throw "n_is_below_zero";
    pMem[GetMemIndex(n)] &= ~GetMemMask(n);;
}

int TBitField::GetBit(const int n) const // получить значение бита
{
    if (n > BitLen)
        throw "overload_n";
    if (n < 0)
        throw "n_is_below_zero";
    return ((pMem[GetMemIndex(n)] & GetMemMask(n)) >> (n & (bitsInElem - 1)));
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
            MemLen = bf.MemLen;
            pMem = new TELEM[MemLen];
        }
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
    if (BitLen != bf.GetLength())
        return 0;
    else
    {
        for (int i = 0; i < BitLen; ++i)
        {
            if (GetBit(i) != bf.GetBit(i))
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
    int maxlen = max(GetLength(), bf.GetLength());
    int minlen = min(GetLength(), bf.GetLength());
    TBitField tmp(1);
    if (GetLength() > bf.GetLength())
        tmp = *this;
    else
        tmp = bf;
    int i = 0;
    for (; i < minlen; ++i)
    {
        if (GetBit(i) || bf.GetBit(i))
            tmp.SetBit(i);
    }
    return tmp;
}

TBitField TBitField::operator&(const TBitField& bf) // операция "и"
{
    int maxlen = max(GetLength(), bf.GetLength());
    int minlen = min(GetLength(), bf.GetLength());
    TBitField tmp(maxlen);
    int i = 0;
    for (; i < minlen; ++i)
    {
        if (GetBit(i) && bf.GetBit(i))
            tmp.SetBit(i);
    }
    return tmp;
}

TBitField TBitField::operator~(void) // отрицание 
{
    TBitField tmp(GetLength());
    for (int i = 0; i <= GetMemIndex(GetLength()); ++i)
    {
       tmp.pMem[i] = ~pMem[i];
    }
    return tmp;
}

// ввод/вывод

istream &operator>>(istream &istr, TBitField &bf) // ввод 
{
    for (int i = 0; i < bf.GetLength(); ++i)
    {
        int val;
        istr >> val;
        if (val) bf.SetBit(i);
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
