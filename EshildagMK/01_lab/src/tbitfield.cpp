// ННГУ, ВМК, Курс "Методы программирования-2", С++, ООП
//
// tbitfield.cpp - Copyright (c) Гергель В.П. 07.05.2001
//   Переработано для Microsoft Visual Studio 2008 Сысоевым А.В. (19.04.2015)
//
// Битовое поле

#include "tbitfield.h"

static const int BITS_FOR_ELEM = sizeof(TELEM) * 8;

TBitField::TBitField(int len)
{
    if (len <= 0) {
        throw("Некорректная длина!");
    }
    BitLen = len;
    MemLen = (len + BITS_FOR_ELEM - 1) / BITS_FOR_ELEM;
    pMem = new TELEM[MemLen]();
}

TBitField::TBitField(const TBitField &bf) // конструктор копирования
{
    BitLen = bf.BitLen;
    MemLen = bf.MemLen;
    pMem = new TELEM[MemLen]();
    for (int i = 0; i < MemLen; i++) {
        pMem[i] = bf.pMem[i];
    }
}

TBitField::~TBitField()
{
    delete[] pMem;
}

int TBitField::GetMemIndex(const int n) const // индекс Мем для бита n
{
    return n / BITS_FOR_ELEM;
}

TELEM TBitField::GetMemMask(const int n) const // битовая маска для бита n
{
    return 1 << (n % BITS_FOR_ELEM);
}

// доступ к битам битового поля

int TBitField::GetLength(void) const // получить длину (к-во битов)
{
  return BitLen;
}

void TBitField::SetBit(const int n) // установить бит
{
    if (n < 0 || n >= BitLen) {
        throw("Некорректный индекс!");
    }
    pMem[GetMemIndex(n)] |= GetMemMask(n);
}

void TBitField::ClrBit(const int n) // очистить бит
{
    if (n < 0 || n >= BitLen) {
        throw("Некорректный индекс!");
    }
    pMem[GetMemIndex(n)] &= ~GetMemMask(n);
}

int TBitField::GetBit(const int n) const
{
    if (n < 0 || n >= BitLen) {
        throw("Некорректный индекс!");
    }
    return (pMem[GetMemIndex(n)] >> (n % BITS_FOR_ELEM)) & 1;
}

// битовые операции

const TBitField& TBitField::operator=(const TBitField &bf) // присваивание
{
    if (this != &bf) {
        delete[] pMem;
        BitLen = bf.BitLen;
        MemLen = bf.MemLen;
        pMem = new TELEM[MemLen]();
        for (int i = 0; i < MemLen; i++) {
            pMem[i] = bf.pMem[i];
        }
    }
    return *this;
}

int TBitField::operator==(const TBitField &bf) const // сравнение
{
    if (BitLen != bf.BitLen) return 0;
    for (int i = 0; i < MemLen; i++) {
        if (pMem[i] != bf.pMem[i]) return 0;
    }
    return 1;
}

int TBitField::operator!=(const TBitField &bf) const // сравнение
{
    return !(*this == bf);
}

TBitField TBitField::operator|(const TBitField& bf) const// или
{
    int maxBit = (BitLen > bf.BitLen) ? BitLen : bf.BitLen;
    TBitField result(maxBit);
    for (int i = 0; i < maxBit; i++) {
        int a = (i < BitLen) ? GetBit(i) : 0;
        int b = (i < bf.BitLen) ? bf.GetBit(i) : 0;
        if (a | b) result.SetBit(i);
    }
    return result;
}

TBitField TBitField::operator&(const TBitField& bf) const // и
{
    int maxBit = (BitLen > bf.BitLen) ? BitLen : bf.BitLen;
    TBitField result(maxBit);
    for (int i = 0; i < maxBit; i++) {
        int a = (i < BitLen) ? GetBit(i) : 0;
        int b = (i < bf.BitLen) ? bf.GetBit(i) : 0;
        if (a & b) result.SetBit(i);
    }
    return result;
}

TBitField TBitField::operator~(void) const// отрицание
{
    TBitField newField(BitLen);
    int end_bits = BitLen % BITS_FOR_ELEM;
    for (int i = 0; i < MemLen; i++) {
        newField.pMem[i] = ~pMem[i];
    }
    if (end_bits != 0) {
        TELEM mask = (1 << end_bits) - 1;
        newField.pMem[MemLen - 1] &= mask;
    }
    return newField;
}

// ввод/вывод

istream& operator>>(istream& istr, TBitField& bf) // ввод
{
    string s;
    istr >> s;
    for (int i = 0; i < bf.BitLen && i < (int)s.length(); i++) {
        if (s[i] == '1') {
            bf.SetBit(i);
        }
        else {
            bf.ClrBit(i);
        }
    }
    return istr;
}

ostream& operator<<(ostream& ostr, const TBitField& bf) // вывод
{
    for (int i = bf.BitLen - 1; i >= 0; i--) {
        ostr << bf.GetBit(i);
    }
    return ostr;
}

