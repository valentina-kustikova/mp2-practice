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
        throw("Incorrect length");
    BitLen = len;
    MemLen = ((BitLen - 1) / BitSize) + 1;
    pMem = new TELEM[MemLen];
    memset(pMem, 0, MemLen * sizeof(TELEM));
}

TBitField::TBitField(const TBitField& bf) // конструктор копирования
{
    BitLen = bf.BitLen;
    MemLen = bf.MemLen;
    pMem = new TELEM[MemLen];
    for (int i = 0; i < MemLen; i++)
        pMem[i] = bf.pMem[i];
}

TBitField::~TBitField()
{
    delete[] pMem;
}

int TBitField::GetMemIndex(const int n) const // индекс Мем для бита n
{
    if (n < 0 || n >= BitLen)
        throw("Incorrect bit");
    return n >> BitSizePower;
}

TELEM TBitField::GetMemMask(const int n) const // битовая маска для бита n
{
    if (n < 0 || n >= BitLen)
        throw("Incorrect bit");
    return 1 << (n & (BitSize - 1));
}

// доступ к битам битового поля

int TBitField::GetLength(void) const // получить длину (к-во битов)
{
    return BitLen;
}

void TBitField::SetBit(const int n) // установить бит
{
    if (n < 0 || n >= BitLen)
        throw("Incorrect bit");
    pMem[GetMemIndex(n)] |= GetMemMask(n);
}

void TBitField::ClrBit(const int n) // очистить бит
{
    if (n < 0 || n >= BitLen)
        throw("Incorrect bit");
    pMem[GetMemIndex(n)] &= ~(GetMemMask(n));
}

int TBitField::GetBit(const int n) const // получить значение бита
{
    if (n < 0 || n >= BitLen)
        throw("Incorrect bit");
    return (pMem[GetMemIndex(n)] & GetMemMask(n)) >> (n & (BitSize - 1));
}

// битовые операции

const TBitField& TBitField::operator=(const TBitField& bf) // присваивание
{
    if (this == &bf)
        return *this;

    if (MemLen != bf.MemLen) {
        delete[] pMem;
;
        MemLen = bf.MemLen;
        pMem = new TELEM[MemLen];
    }

    BitLen = bf.BitLen;

    for (int i = 0; i < MemLen; i++)
        pMem[i] = bf.pMem[i];

    return *this;
}

int TBitField::operator==(const TBitField& bf) const // сравнение
{
    if (BitLen != bf.BitLen)
        return 0;

    for (int i = 0; i < MemLen; i++)
        if (pMem[i] != bf.pMem[i])
            return 0;

    return 1;
}

int TBitField::operator!=(const TBitField& bf) const // сравнение
{
    return !(*this == bf);
}

TBitField TBitField::operator|(const TBitField& bf) // операция "или"
{
    const TBitField& MaxLenField = (this->BitLen > bf.BitLen) ? *this : bf;
    const TBitField& MinLenField = (this->BitLen <= bf.BitLen) ? *this : bf;

    TBitField result(MaxLenField);
    for (int i = 0; i < MinLenField.MemLen; i++)
        result.pMem[i] |= MinLenField.pMem[i];

    return result;
}

TBitField TBitField::operator&(const TBitField& bf) // операция "и"
{
    const TBitField& MaxLenField = (this->BitLen > bf.BitLen) ? *this : bf;
    const TBitField& MinLenField = (this->BitLen <= bf.BitLen) ? *this : bf;

    TBitField result(MaxLenField);
    for (int i = 0; i < MinLenField.MemLen; i++)
        result.pMem[i] &= MinLenField.pMem[i];

    for (int i = MinLenField.MemLen; i < MaxLenField.MemLen; i++)
        result.pMem[i] = 0;

    return result;
}

TBitField TBitField::operator~(void) // отрицание
{
    TBitField result(BitLen);

    for (int i = 0; i < MemLen; i++)
        result.pMem[i] = ~pMem[i];

    int lastBits = BitLen % BitSize;

    if (lastBits != 0)
        for (int i = lastBits; i < BitSize; i++)
            result.pMem[MemLen - 1] &= ~(1 << i);

    return result;
}

// ввод/вывод

istream& operator>>(istream& istr, TBitField& bf) // ввод
{
    char c;

    for (int i = 0; i < bf.BitLen; i++) {
        istr >> c;

        if (c == '1')
            bf.SetBit(i);
        else if (c == '0')
            bf.ClrBit(i);
        else
            throw("Incorrect bit");
    }
    return istr;
}

ostream& operator<<(ostream& ostr, const TBitField& bf) // вывод
{
    for (int i = 0; i < bf.BitLen; i++)
        ostr << bf.GetBit(i);

    return ostr;
}