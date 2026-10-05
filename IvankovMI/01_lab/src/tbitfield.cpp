// ННГУ, ВМК, Курс "Методы программирования-2", С++, ООП
//
// tbitfield.cpp - Copyright (c) Гергель В.П. 07.05.2001
//   Переработано для Microsoft Visual Studio 2008 Сысоевым А.В. (19.04.2015)
//
// Битовое поле

#include <stdexcept>
#include "tbitfield.h"

namespace {
    const int BITS_PER_ELEM = sizeof(TELEM) * 8;
}

TBitField::TBitField(int len)
{
    if (len < 0)
        throw std::invalid_argument("TBitField: length cannot be negative");

    BitLen = len;
    MemLen = (BitLen + BITS_PER_ELEM - 1) / BITS_PER_ELEM;

    if (MemLen > 0) {
        pMem = new TELEM[MemLen];
        for (int i = 0; i < MemLen; ++i)
            pMem[i] = 0;
    }
    else {
        pMem = nullptr;
    }
}

TBitField::TBitField(const TBitField& bf) // конструктор копирования
{
    BitLen = bf.BitLen;
    MemLen = bf.MemLen;

    if (MemLen > 0) {
        pMem = new TELEM[MemLen];
        for (int i = 0; i < MemLen; ++i)
            pMem[i] = bf.pMem[i];
    }
    else {
        pMem = nullptr;
    }
}

TBitField::~TBitField()
{
    delete[] pMem;
}

int TBitField::GetMemIndex(const int n) const // индекс Мем для бита n
{
    return n / BITS_PER_ELEM;
}

TELEM TBitField::GetMemMask(const int n) const // битовая маска для бита n
{
    return TELEM(1) << (n % BITS_PER_ELEM);
}

// доступ к битам битового поля

int TBitField::GetLength(void) const // получить длину (к-во битов)
{
    return BitLen;
}

void TBitField::SetBit(const int n) // установить бит
{
    if (n < 0 || n >= BitLen)
        throw std::out_of_range("TBitField::SetBit: index out of range");

    pMem[GetMemIndex(n)] |= GetMemMask(n);
}

void TBitField::ClrBit(const int n) // очистить бит
{
    if (n < 0 || n >= BitLen)
        throw std::out_of_range("TBitField::ClrBit: index out of range");

    pMem[GetMemIndex(n)] &= ~GetMemMask(n);
}

int TBitField::GetBit(const int n) const // получить значение бита
{
    if (n < 0 || n >= BitLen)
        throw std::out_of_range("TBitField::GetBit: index out of range");

    return (pMem[GetMemIndex(n)] & GetMemMask(n)) ? 1 : 0;
}

// битовые операции

const TBitField& TBitField::operator=(const TBitField& bf) // присваивание
{
    if (this != &bf) {
        delete[] pMem;

        BitLen = bf.BitLen;
        MemLen = bf.MemLen;

        if (MemLen > 0) {
            pMem = new TELEM[MemLen];
            for (int i = 0; i < MemLen; ++i)
                pMem[i] = bf.pMem[i];
        }
        else {
            pMem = nullptr;
        }
    }
    return *this;
}

int TBitField::operator==(const TBitField& bf) const // сравнение
{
    if (BitLen != bf.BitLen)
        return 0;

    for (int i = 0; i < MemLen; ++i) {
        if (pMem[i] != bf.pMem[i])
            return 0;
    }
    return 1;
}

int TBitField::operator!=(const TBitField& bf) const // сравнение
{
    return !(*this == bf);
}

TBitField TBitField::operator|(const TBitField& bf) // операция "или"
{
    int maxLen = (BitLen > bf.BitLen) ? BitLen : bf.BitLen;
    TBitField res(maxLen);

    for (int i = 0; i < maxLen; ++i) {
        int a = (i < BitLen) ? GetBit(i) : 0;
        int b = (i < bf.BitLen) ? bf.GetBit(i) : 0;
        if (a || b)
            res.SetBit(i);
    }
    return res;
}

TBitField TBitField::operator&(const TBitField& bf) // операция "и"
{
    int maxLen = (BitLen > bf.BitLen) ? BitLen : bf.BitLen;
    TBitField res(maxLen);

    for (int i = 0; i < maxLen; ++i) {
        if (i < BitLen && i < bf.BitLen && GetBit(i) && bf.GetBit(i))
            res.SetBit(i);
    }
    return res;
}

TBitField TBitField::operator~(void) // отрицание
{
    TBitField res(BitLen);

    for (int i = 0; i < BitLen; ++i) {
        if (!GetBit(i))
            res.SetBit(i);
    }
    return res;
}

// ввод/вывод

istream& operator>>(istream& istr, TBitField& bf) // ввод
{
    for (int i = bf.BitLen - 1; i >= 0; --i) {
        char c;
        istr >> c;

        if (c == '1')
            bf.SetBit(i);
        else
            bf.ClrBit(i);
    }
    return istr;
}

ostream& operator<<(ostream& ostr, const TBitField& bf) // вывод
{
    for (int i = bf.BitLen - 1; i >= 0; --i)
        ostr << bf.GetBit(i);

    return ostr;
}