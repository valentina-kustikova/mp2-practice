// ННГУ, ВМК, Курс "Методы программирования-2", С++, ООП
//
// tbitfield.cpp - Copyright (c) Гергель В.П. 07.05.2001
//   Переработано для Microsoft Visual Studio 2008 Сысоевым А.В. (19.04.2015)
//
// Битовое поле

#include "tbitfield.h"

static const int Mem = 32;
static const int Pow = 5;

TBitField::TBitField(int len)
{
    if (len < 0)
        throw std::exception("Incorrect argument");
    BitLen = len;
    if (len - Mem * (len >> Pow) == 0)
        MemLen = len >> Pow;
    else
        MemLen = (len >> Pow) + 1;
    pMem = new TELEM[MemLen]();
}

TBitField::TBitField(const TBitField &bf): BitLen(bf.BitLen), MemLen(bf.MemLen)// конструктор копирования
{
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
    return n >> Pow;
}

TELEM TBitField::GetMemMask(const int n) const // битовая маска для бита n
{
    return 1 << (n - Mem*GetMemIndex(n));
}

// доступ к битам битового поля

int TBitField::GetLength(void) const // получить длину (к-во битов)
{
  return BitLen;
}

void TBitField::SetBit(const int n) // установить бит
{
    if ((n < 0)||(n >= BitLen))
        throw std::exception("index out of range");
    pMem[GetMemIndex(n)] |= GetMemMask(n);
}

void TBitField::ClrBit(const int n) // очистить бит
{
    if ((n < 0) || (n >= BitLen))
        throw std::exception("index out of range");
    pMem[GetMemIndex(n)] &= (~GetMemMask(n));
}

int TBitField::GetBit(const int n) const // получить значение бита
{
    if ((n < 0) || (n >= BitLen))
        throw std::exception("index out of range");
    return (pMem[GetMemIndex(n)] & GetMemMask(n)) >> (n - Mem * (n >> Pow));
}
 
// битовые операции

const TBitField& TBitField::operator=(const TBitField &bf) // присваивание
{
    if (this == &bf)
        return *this;
    if (BitLen != bf.BitLen)
    {
        BitLen = bf.BitLen;
        MemLen = bf.MemLen;
        delete[] pMem;
        pMem = new TELEM[MemLen];
    }
    for (int i = 0; i < MemLen; i++)
    {
        pMem[i] = bf.pMem[i];
    }
    return *this;
}

int TBitField::operator==(const TBitField &bf) const // сравнение
{
    int flag = 1;
    if (BitLen != bf.BitLen)
    {
        return 0;
    }
    for (int i = 0; i < MemLen; i++)
    {
        if (pMem[i] != bf.pMem[i])
        {
            flag = 0;
            break;
        }
    }
    return flag;
}

int TBitField::operator!=(const TBitField &bf) const // сравнение
{
    return  ~(*this == bf);
}

TBitField TBitField::operator|(const TBitField &bf) // операция "или"
{
    int MaxBitLen = max(BitLen, bf.BitLen);
    int MinMemLen = min(MemLen, bf.MemLen);
    TBitField NewSet(MaxBitLen);
    int i;
    for (i = 0; i < MinMemLen; i++)
        NewSet.pMem[i] = pMem[i] | bf.pMem[i];
    while (i < MemLen)
    {
        NewSet.pMem[i] = pMem[i];
        i++;
    }
    while (i < bf.MemLen)
    {
        NewSet.pMem[i] = bf.pMem[i];
        i++;
    }
    return NewSet;
}

TBitField TBitField::operator&(const TBitField &bf) // операция "и"
{
    int MaxBitLen = max(BitLen, bf.BitLen);
    int MinMemLen = min(MemLen, bf.MemLen);
    TBitField NewSet(MaxBitLen);
    for (int i = 0; i < MinMemLen; i++)
        NewSet.pMem[i] = pMem[i] & bf.pMem[i];
    return NewSet;
}

TBitField TBitField::operator~(void) // отрицание
{
    TBitField NewSet(BitLen);
    for (int i = 0; i < MemLen; i++)
    {
        NewSet.pMem[i] = ~pMem[i];
    }
    int extra = BitLen << Pow;
    if (extra != 0 && NewSet.MemLen > 0)
        NewSet.pMem[MemLen - 1] &= (1 << (BitLen & (Mem - 1))) - 1;
    return NewSet;
}

// ввод/вывод

istream &operator>>(istream &istr, TBitField &bf) // ввод
{   
    string s;
    istr >> s;
    for (int i = 0; i < s.size(); i++)
        if (s[i] == '1')
            bf.SetBit(i);
    return istr;
}

ostream &operator<<(ostream &ostr, const TBitField &bf) // вывод
{   
    for (int i = 0; i < bf.BitLen; i++)
        ostr << bf.GetBit(i);
    return ostr;
}
