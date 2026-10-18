// ННГУ, ВМК, Курс "Методы программирования-2", С++, ООП
//
// tbitfield.cpp - Copyright (c) Гергель В.П. 07.05.2001
//   Переработано для Microsoft Visual Studio 2008 Сысоевым А.В. (19.04.2015)
//
// Битовое поле

#include "tbitfield.h"
#include <iostream>
#include <stdexcept>
#include <algorithm>

using namespace std;

static const int BITS_PER_WORD = sizeof(TELEM) * 8;

static void CheckInd(const int n, const int len) {
    if (n<0 || n >= len) {
        throw invalid_argument("индекс за границами массива");
    }
}

TBitField::TBitField(int len)
{
    if (len < 0) {
        throw invalid_argument("длина битового поля не может быть отрицательной");
    }
    BitLen = len;
    MemLen = (BitLen + BITS_PER_WORD - 1) / BITS_PER_WORD;
    pMem = new TELEM[MemLen];
    for (int i = 0; i < MemLen; i++) {
        pMem[i] = 0;
    }
}

TBitField::TBitField(const TBitField &bf) // конструктор копирования
{
    BitLen = bf.BitLen;
    MemLen = bf.MemLen;
    pMem = new TELEM[MemLen];
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
    return n / BITS_PER_WORD;
}

TELEM TBitField::GetMemMask(const int n) const // битовая маска для бита n
{
    return 1u << (n % BITS_PER_WORD);
}

// доступ к битам битового поля

int TBitField::GetLength(void) const // получить длину (к-во битов)
{
  return BitLen;
}

void TBitField::SetBit(const int n) // установить бит
{
    CheckInd(n, BitLen);
    pMem[GetMemIndex(n)] |= GetMemMask(n);
}

void TBitField::ClrBit(const int n) // очистить бит
{
    CheckInd(n, BitLen);
    pMem[GetMemIndex(n)] &= ~GetMemMask(n);
}

int TBitField::GetBit(const int n) const // получить значение бита
{
  CheckInd(n, BitLen);
  return (pMem[GetMemIndex(n)] & GetMemMask(n))?1:0;
}

// битовые операции

const TBitField& TBitField::operator=(const TBitField &bf) // присваивание
{
    if (this == &bf) return *this;
    delete[] pMem;
    BitLen = bf.BitLen;
    MemLen = bf.MemLen;
    pMem = new TELEM[MemLen];
    for (int i = 0; i < MemLen; i++) {
        pMem[i] = bf.pMem[i];
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
  return !(*this==bf);
}

TBitField TBitField::operator|(const TBitField &bf) // 
{
    int minlenMem = std::min(MemLen, bf.MemLen);
    int maxlen = std::max(BitLen, bf.BitLen);
    TBitField result(maxlen);
    int i = 0;
    for (i; i < minlenMem; i++) {
        result.pMem[i] = pMem[i] | bf.pMem[i];
    }
    while (i < MemLen) {
        result.pMem[i] = pMem[i];
        i++;
    }
    while (i < bf.MemLen) {
        result.pMem[i] = bf.pMem[i];
        i++;
     }
    return result;
}

TBitField TBitField::operator&(const TBitField &bf) // 
{
    int minlenMem = std::min(MemLen, bf.MemLen);
    int maxlen = std::max(BitLen, bf.BitLen);
    TBitField result(maxlen);
    for (int i = 0; i < minlenMem; i++) {
        result.pMem[i] = pMem[i] & bf.pMem[i];
    }
    return result;
}

TBitField TBitField::operator~(void) // отрицание
{
    TBitField result(BitLen);
    for (int i = 0; i < result.MemLen; i++) {
        result.pMem[i] = ~pMem[i];
    }
    if (BitLen % BITS_PER_WORD) {
        int lastInd = MemLen - 1;
        TELEM mask = (1u << (BitLen % BITS_PER_WORD)) - 1;
        result.pMem[lastInd] &= mask;
    }
    return result;
}

// ввод/вывод

istream &operator>>(istream &istr, TBitField &bf) // ввод
{
    for (int i = 0; i < bf.BitLen; i++) {
        int bit;
        istr >> bit;
        if (bit) bf.SetBit(i);
        else bf.ClrBit(i);
    }
    return istr;
}

ostream &operator<<(ostream &ostr, const TBitField &bf) // вывод
{
    for (int i = bf.BitLen - 1; i >= 0; i--) {
        ostr << bf.GetBit(i);
    }
    return ostr;
}
