// ННГУ, ВМК, Курс "Методы программирования-2", С++, ООП
//
// tbitfield.cpp - Copyright (c) Гергель В.П. 07.05.2001
//   Переработано для Microsoft Visual Studio 2008 Сысоевым А.В. (19.04.2015)
//
// 
// 
// Битовое поле

#include "tbitfield.h"
const int bitsInElem = 32;
const int shiftSize = 5;//Значение для сдвига

TBitField::TBitField(int Len)//Конструктор по умолчанию
{
    if (Len > 0) {
        BitLen = Len;// длина битового поля - макс. к-во битов
        MemLen = ((Len + bitsInElem - 1) >> shiftSize); // к-во эл-тов Мем для представления бит.поля
        pMem = new TELEM[MemLen];//Массив для предоставления битового поля
        memset(pMem, 0, MemLen * sizeof(TELEM));//Функция копирования одного объекта в другой заданное количество раз
    }
    else if (Len < 0)
    {
        throw ("Field less than 0");
    }
    else if (Len == 0) {
        MemLen = 0;// к-во эл-тов Мем для представления бит.поля
        BitLen = 0;// длина битового поля - макс. к-во битов
        pMem = nullptr;//Значение пустого указателя
    }
}

TBitField::TBitField(const TBitField& bf) //Конструктор копирования 
{
    BitLen = bf.BitLen;
    MemLen = bf.MemLen;
    if (MemLen) {
        pMem = new TELEM[MemLen];
        memcpy(pMem, bf.pMem, MemLen * sizeof(TELEM));
    }
    else {
        pMem = nullptr;
    }
}

TBitField::~TBitField()
{
    delete[] pMem;
}

int TBitField::GetMemIndex(const int n) const
{
    return n >> shiftSize;
}

TELEM TBitField::GetMemMask(const int n) const
{
    return 1 << (n & (bitsInElem - 1));
}

int TBitField::GetLength(void) const
{
    return BitLen;
}

void TBitField::SetBit(const int n)
{
    if (n >= BitLen || n < 0)
        throw("bit position is out of range");
    pMem[GetMemIndex(n)] |= GetMemMask(n);
}

void TBitField::ClrBit(const int n)
{
    if (n >= BitLen || n < 0)
        throw("bit position is out of range");
    pMem[GetMemIndex(n)] &= ~GetMemMask(n);
}

int TBitField::GetBit(const int n) const {
    if (n >= BitLen || n < 0)
        throw("bit position is out of range");
    return (pMem[GetMemIndex(n)] & GetMemMask(n)) ? 1 : 0;
}

TBitField& TBitField::operator=(const TBitField& bf)
{
    if (this == &bf)
        return *this;
    if (BitLen != bf.BitLen)
    {
        delete[] pMem;
        BitLen = bf.BitLen;
        MemLen = bf.MemLen;
        pMem = new TELEM[MemLen];
    }
    for (int i = 0; i < MemLen; ++i)
    {
        pMem[i] = bf.pMem[i];
    }
    return *this;
}

int TBitField::operator==(const TBitField& bf) const
{
    if (BitLen != bf.BitLen) return 0;
    for (int i = 0; i < MemLen; i++) {
        if (pMem[i] != bf.pMem[i]) {
            return 0;

        }
    }
    return 1;
}

int TBitField::operator!=(const TBitField& bf) const
{
    return !((*this) == bf);
}

TBitField TBitField::operator|(const TBitField& bf)
{
    int Len = max(BitLen, bf.BitLen);
    TBitField obj(Len);
    for (int i = 0; i < obj.MemLen; i++)
        obj.pMem[i] = pMem[i] | bf.pMem[i];
    return obj;
}

TBitField TBitField::operator&(const TBitField& bf)
{
    int Len = max(BitLen, bf.BitLen);
    TBitField obj(Len);
    for (int i = 0; i < obj.MemLen; i++) {
        obj.pMem[i] = pMem[i] & bf.pMem[i];
    }
    return obj;
}

TBitField TBitField::operator~()
{
    TBitField obj(BitLen);
    for (int i = 0; i < BitLen; i++)
        if (GetBit(i) == 0)
            obj.SetBit(i);
    return obj;
}

istream& operator>>(istream& istr, TBitField& bf) {
    int ans;
    for (int i = 0; i < bf.BitLen; i++) {
        istr >> ans;
        if (ans == 0) {
            bf.ClrBit(i);
        }
        else if (ans == 1) {
            bf.SetBit(i);
        }
        else {
            throw ("The entered element does not match the bit field");
            break;
        }
    }
    return istr;
}

ostream& operator<<(ostream& ostr, const TBitField& bf)
{
    for (int i = 0; i < bf.GetLength(); ++i)
    {
        ostr << bf.GetBit(i) << " ";
    }
    return ostr;
}