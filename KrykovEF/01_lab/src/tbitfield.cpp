// ННГУ, ВМК, Курс "Методы программирования-2", С++, ООП
//
// tbitfield.cpp - Copyright (c) Гергель В.П. 07.05.2001
//   Переработано для Microsoft Visual Studio 2008 Сысоевым А.В. (19.04.2015)
//
// Битовое поле

#include "tbitfield.h"
#include <cstring>

// Fake variables used as placeholders in tests
static const int FAKE_INT = -1;
static TBitField FAKE_BITFIELD(1);

TBitField::TBitField(int len)
{
    if (len <= 0)
        throw "negative_length";
    this->BitLen = len;

    if (this->BitLen % (sizeof(TELEM) * 8) == 0)
        this->MemLen = this->BitLen / (sizeof(TELEM) * 8);
    else
        this->MemLen = (this->BitLen / (sizeof(TELEM) * 8)) + 1;

    this->pMem = new TELEM[this->MemLen]();
    memset(this->pMem, 0, this->MemLen * sizeof(TELEM));
}

TBitField::TBitField(const TBitField &bf) // конструктор копирования
{
    this->BitLen = bf.BitLen;
    this->MemLen = bf.MemLen;
    this->pMem = new TELEM[MemLen];

    for (int i = 0; i < this->MemLen; ++i)
        this->pMem[i] = bf.pMem[i];
}

TBitField::~TBitField()
{
    delete[] this->pMem;
}

int TBitField::GetMemIndex(const int n) const // индекс Мем для бита n
{
    return n/ (sizeof(TELEM) * 8);
}

TELEM TBitField::GetMemMask(const int n) const // битовая маска для бита n
{
    return 1 << (n% (sizeof(TELEM) * 8));
}

// доступ к битам битового поля

int TBitField::GetLength(void) const // получить длину (к-во битов)
{
  return this->BitLen;
}

void TBitField::SetBit(const int n) // установить бит
{
    if (n >= this->BitLen)
        throw "too_large_index";
    if (n < 0)
        throw "negative_index";
    this->pMem[GetMemIndex(n)] |= GetMemMask(n);
}

void TBitField::ClrBit(const int n) // очистить бит
{
    if (n >= this->BitLen)
        throw "too_large_index";
    if (n < 0)
        throw "negative_index";
    this->pMem[GetMemIndex(n)] &= ~GetMemMask(n);
}

int TBitField::GetBit(const int n) const // получить значение бита
{
    if (n >= this->BitLen)
        throw "too_large_index";
    if (n < 0)
        throw "negative_index";
    return (this->pMem[GetMemIndex(n)] & GetMemMask(n)) >> (n % (sizeof(TELEM) * 8));
}

// битовые операции

const TBitField& TBitField::operator=(const TBitField &bf) // присваивание
{
    if (this != &bf) {
        this->BitLen = bf.BitLen;
        this->MemLen = bf.MemLen;

        delete[] this->pMem;
        this->pMem = new TELEM[this->MemLen];

        for (int i = 0; i < this->MemLen; i++)
            this->pMem[i] = bf.pMem[i];

    }
    
    return *this;
}

int TBitField::operator==(const TBitField &bf) const // сравнение
{
    if (this->MemLen != bf.MemLen)
        return 0;
    for (int i = 0; i < this->MemLen; i++)
        if (this->pMem[i] != bf.pMem[i])
            return 0;
    return 1;
}

int TBitField::operator!=(const TBitField &bf) const // сравнение
{
    if (this->operator==(bf))
    {
        return 0;
    }
    return 1;
}

TBitField TBitField::operator|(const TBitField &bf) // операция "или"
{
    TBitField tmp(max(this->BitLen, bf.BitLen));
    for (int i = 0; i < this->MemLen; i++)
        tmp.pMem[i] = this->pMem[i];
    for (int i = 0; i < tmp.MemLen; i++)
        tmp.pMem[i] |= bf.pMem[i];
    return tmp;
}

TBitField TBitField::operator&(const TBitField &bf) // операция "и"
{
    TBitField tmp(max(this->BitLen, bf.BitLen));
    for (int i = 0; i < this->MemLen; i++)
        tmp.pMem[i] = this->pMem[i];
    for (int i = 0; i < tmp.MemLen; i++)
        tmp.pMem[i] &= bf.pMem[i];
    return tmp;
}

TBitField TBitField::operator~(void) // отрицание
{
    TBitField tmp(*this);
    for (int i = 0; i < this->BitLen; i++)
    {
        if (GetBit(i) == 0)
            tmp.SetBit(i);
        else
            tmp.ClrBit(i);
    }
    return tmp;
}

// ввод/вывод

istream &operator>>(istream &istr, TBitField &bf) // ввод
{
    for (int i = 0; i < (bf.BitLen); i++) {
        int bit;
        istr >> bit;
        if (bit) {
            bf.SetBit(i);
        }
    }
    return istr;
}

ostream &operator<<(ostream &ostr, const TBitField &bf) // вывод
{
    for (int i = 0; i < bf.BitLen; i++) {
        ostr << bf.GetBit(i);
    }
    ostr << "\n";
    return ostr;
}
