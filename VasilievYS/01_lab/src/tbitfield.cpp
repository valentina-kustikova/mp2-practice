// ННГУ, ВМК, Курс "Методы программирования-2", С++, ООП
//
// tbitfield.cpp - Copyright (c) Гергель В.П. 07.05.2001
//   Переработано для Microsoft Visual Studio 2008 Сысоевым А.В. (19.04.2015)
//
// Битовое поле

#include "tbitfield.h"

static const unsigned int BITS = sizeof(TELEM) * 8;
static const unsigned int Power_of_two = 5;

TBitField::TBitField(int len)
{
    if (len < 0) throw invalid_argument("BitField negative lenght");
    BitLen = len;
    MemLen = (len + BITS - 1) / BITS;
    pMem = new TELEM[MemLen]();
}

TBitField::TBitField(const TBitField &bf)
    :BitLen(bf.BitLen), MemLen(bf.MemLen) // конструктор копирования
{
    pMem = new TELEM[MemLen];
    for (int i = 0; i < MemLen; i++)
    {
        pMem[i] = bf.pMem[i];
    }
}

TBitField::~TBitField()
{
    delete []pMem;
}

int TBitField::GetMemIndex(const int n) const // индекс Мем для бита n
{
    if (n<0 || n >= BitLen) throw out_of_range("GetMemIndex out_of_range");
    return n >> Power_of_two;
}

TELEM TBitField::GetMemMask(const int n) const // битовая маска для бита n
{
    if(n<0 || n>=BitLen) throw out_of_range("GetMemMask out_of_range");
    return 1u << (n&(BITS-1));
}

// доступ к битам битового поля

int TBitField::GetLength(void) const // получить длину (к-во битов)
{
  return BitLen;
}

void TBitField::SetBit(const int n) // установить бит
{
    pMem[GetMemIndex(n)] |= GetMemMask(n);
}

void TBitField::ClrBit(const int n) // очистить бит
{
    pMem[GetMemIndex(n)] &= ~GetMemMask(n);
}

int TBitField::GetBit(const int n) const // получить значение бита
{
    return  (pMem[GetMemIndex(n)] & GetMemMask(n)) >> (n&(BITS-1));
}

// битовые операции

const TBitField& TBitField::operator=(const TBitField &bf) // присваивание
{
    if (this != &bf)
    {
        if (bf.BitLen != BitLen)
        {
            BitLen = bf.BitLen;
            MemLen = bf.MemLen;
            delete[]pMem;
            pMem = new TELEM[MemLen];
        }
        for (int i = 0; i < MemLen; i++)
        {
            pMem[i] = bf.pMem[i];
        }
    }
    return *this;
}

int TBitField::operator==(const TBitField& bf) const // сравнение
{

    if (this == &bf) return 1;
    if (BitLen != bf.BitLen) return 0;
    for (int i = 0; i < MemLen; i++)
    {
        if (pMem[i] != bf.pMem[i])
        {
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
    int max_Bitlen, min_Memlen;
    if (BitLen >= bf.BitLen) 
    {
        max_Bitlen = BitLen; 
        min_Memlen = bf.MemLen;
    }
    else
    {
        max_Bitlen = bf.BitLen;
        min_Memlen = MemLen;
    }
    TBitField res(max_Bitlen);
    int i = 0;
    for (; i < min_Memlen; i++)
    {
        res.pMem[i] = pMem[i] | bf.pMem[i];
    }
    if (MemLen > bf.MemLen)
    {
        for (; i < MemLen; i++)
        {
            res.pMem[i] = pMem[i];
        }
    }
    else if (bf.MemLen > MemLen)
    {
        for (; i < bf.MemLen; i++)
        {
            res.pMem[i] = bf.pMem[i];
        }
    }
    return res;
}

TBitField TBitField::operator&(const TBitField &bf) // операция "и"
{
    int max_Bitlen, min_Memlen;
    if (BitLen >= bf.BitLen)
    {
        max_Bitlen = BitLen;
        min_Memlen = bf.MemLen;
    }
    else
    {
        max_Bitlen = bf.BitLen;
        min_Memlen = MemLen;
    }
    TBitField res(max_Bitlen);
    for (int i = 0; i < min_Memlen; i++)
    {
        res.pMem[i] = pMem[i] & bf.pMem[i];
    }
    return res;
}

TBitField TBitField::operator~(void) // отрицание
{
    TBitField res(BitLen);
    for (int i = 0; i < MemLen; i++)
    {
        res.pMem[i] = ~pMem[i];
    }
    if ((BitLen & (BITS - 1)) != 0)
    {
        res.pMem[MemLen - 1] &= (1u << (BitLen & (BITS - 1))) - 1;
    }
    return res;
}

// ввод/вывод

istream &operator>>(istream &istr, TBitField &bf) // ввод
{
    string str;
    istr >> str;
    if (str.size() > bf.BitLen) 
        throw out_of_range("input out_of_range");
    int i = 0;
    for (; i < str.size(); i++)
    {
        if (str[i] == '1') bf.SetBit(i);
        else if (str[i] == '0') bf.ClrBit(i);
        else throw invalid_argument("input unexpected value");
    }
    for (; i < bf.BitLen; i++)
    {
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