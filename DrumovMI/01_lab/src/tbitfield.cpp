// ННГУ, ВМК, Курс "Методы программирования-2", С++, ООП
//
// tbitfield.cpp - Copyright (c) Гергель В.П. 07.05.2001
//   Переработано для Microsoft Visual Studio 2008 Сысоевым А.В. (19.04.2015)
//
// Битовое поле

#include "tbitfield.h"

TBitField::TBitField(int len)
{
    if (len < 0)
        throw invalid_argument("Bad TBitField length");
    BitLen = len;
    MemLen = (len + sizeof(TELEM) - 1) / sizeof(TELEM);
    pMem = new TELEM[MemLen]{ 0 };
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
    return n / sizeof(TELEM);
}

TELEM TBitField::GetMemMask(const int n) const // битовая маска для бита n
{
    return 1 << (n & 31);
}

// доступ к битам битового поля

int TBitField::GetLength(void) const // получить длину (к-во битов)
{
    return BitLen;
}

void TBitField::SetBit(const int n) // установить бит
{
    if (n < 0 || n >= BitLen)
        throw out_of_range("Out-of-bounds index (TBitField::SetBit(const int))");
    pMem[GetMemIndex(n)] |= GetMemMask(n);
}

void TBitField::ClrBit(const int n) // очистить бит
{
    if (n < 0 || n >= BitLen)
        throw out_of_range("Out-of-bounds index (TBitField::ClrBit(const int))");
    pMem[GetMemIndex(n)] &= ~GetMemMask(n);
}

int TBitField::GetBit(const int n) const // получить значение бита
{
    if (n < 0 || n >= BitLen)
        throw out_of_range("Out-of-bounds index (TBitField::GetBit(const int))");
    return (pMem[GetMemIndex(n)] & GetMemMask(n)) >> (n & 31);
}

// битовые операции

const TBitField& TBitField::operator=(const TBitField& bf) // присваивание
{
    if (this == &bf)
        return *this;
    if (MemLen != bf.MemLen) {
        delete[] pMem;
        pMem = new TELEM[bf.MemLen];
    }
    BitLen = bf.BitLen;
    MemLen = bf.MemLen;
    for (int i = 0; i < MemLen; i++)
        pMem[i] = bf.pMem[i];
    return *this;
}

int TBitField::operator==(const TBitField& bf) const // сравнение
{
    if (BitLen != bf.BitLen)
        return 0;
    for (int i = 0; i < BitLen; i++)
        if (GetBit(i) != bf.GetBit(i))
            return 0;
    return 1;
}

int TBitField::operator!=(const TBitField& bf) const // сравнение
{
    return !(*this == bf);
}

TBitField TBitField::operator|(const TBitField& bf) // операция "или"
{
    TBitField ans(max(BitLen, bf.BitLen));
    int i;
    for (i = 0; i < min(BitLen, bf.BitLen); i++)
        if (GetBit(i) | bf.GetBit(i))
            ans.SetBit(i);
    for (; i < BitLen; i++)
        if (GetBit(i))
            ans.SetBit(i);
    for (; i < bf.BitLen; i++)
        if (bf.GetBit(i))
            ans.SetBit(i);
    return ans;
}

TBitField TBitField::operator&(const TBitField& bf) // операция "и"
{
    TBitField ans(max(BitLen, bf.BitLen));
    for (int i = 0; i < min(BitLen, bf.BitLen); i++)
        if (GetBit(i) & bf.GetBit(i))
            ans.SetBit(i);
    return ans;
}

TBitField TBitField::operator~(void) // отрицание
{
    TBitField ans(*this);
    for (int i = 0; i < MemLen; i++)
        ans.pMem[i] = ~ans.pMem[i];
    return ans;
}

// ввод/вывод

istream& operator>>(istream& istr, TBitField& bf) // ввод
{
    for (int i = 0; i < bf.BitLen; i++) {
        char bit;
        cin >> bit;
        if (bit == '1')
            bf.SetBit(i);
        else if (bit == '0')
            bf.ClrBit(i);
        else
            throw exception("Incorrect input TBitField format");
    }
    return istr;
}

ostream& operator<<(ostream& ostr, const TBitField& bf) // вывод
{
    for (int i = 0; i < bf.BitLen; i++)
        if (bf.GetBit(i))
            cout << "1";
        else
            cout << "0";
    return ostr;
}
