// ННГУ, ВМК, Курс "Методы программирования-2", С++, ООП
//
// tbitfield.cpp - Copyright (c) Гергель В.П. 07.05.2001
//   Переработано для Microsoft Visual Studio 2008 Сысоевым А.В. (19.04.2015)
//
// Битовое поле

#include "tbitfield.h"
#include <cmath>
// Fake variables used as placeholders in tests
static const int FAKE_INT = -1;
static TBitField FAKE_BITFIELD(1);
//int bf = 0;

TBitField::TBitField(int len)
{
    this->BitLen = len;
    MemLen = ceil(BitLen / 8*sizeof(TELEM));
    pMem = new TELEM[MemLen];
}

TBitField::TBitField(const TBitField& bf) // конструктор копирования
{
    this->BitLen = bf.BitLen;
    this->MemLen = bf.MemLen;
    pMem = new TELEM[this->MemLen];
    for (int i = 0; i < this->MemLen; ++i) {
        pMem[i] = bf.pMem[i];
    }
}

TBitField::~TBitField()
{
    delete[] pMem;
}

int TBitField::GetMemIndex(const int n) const // индекс Мем для бита n
{
    return n/(8*sizeof(TELEM));
    return FAKE_INT;
}

TELEM TBitField::GetMemMask(const int n) const // битовая маска для бита n
{
    return ((TELEM)1 << (n%(8*sizeof(TELEM))));//приведение типов во избежании потери битов на границе
    return FAKE_INT;
}

// доступ к битам битового поля

int TBitField::GetLength(void) const // получить длину (к-во битов)
{
    return BitLen;
    return FAKE_INT;
}

void TBitField::SetBit(const int n) // установить бит
{
    TELEM mask = GetMemMask(n);
    int staten = GetMemIndex(n);
    pMem[staten] |= mask;
}

void TBitField::ClrBit(const int n) // очистить бит
{
    TELEM mask = GetMemMask(n);
    int staten = GetMemIndex(n);
    pMem[staten] &= ~mask;
}

int TBitField::GetBit(const int n) const // получить значение бита
{
    TELEM mask = GetMemMask(n);
    int staten = GetMemIndex(n);
    if ((pMem[staten] & mask) != 0) {
        return 1;
    }
    else {
        return 0;
    }
    return FAKE_INT;
}

// битовые операции

const TBitField& TBitField::operator=(const TBitField &bf) // присваивание
{
    if (this == &bf) {
        return *this;
    }
    this->BitLen = bf.BitLen;
    this->MemLen = bf.MemLen;
    delete[] pMem;
    pMem = new TELEM[this->MemLen];
    for (int i = 0; i < this->MemLen; ++i) {
        pMem[i] = bf.pMem[i];
    }
    return FAKE_BITFIELD;
}

int TBitField::operator==(const TBitField &bf) const // сравнение
{
    if (this->BitLen != bf.BitLen) {
        return 0;
    }
    else{
        for (int i = 0; i < MemLen; ++i) {
            if (pMem[i] != bf.pMem[i]) {
                return 0;
            }
        }
        return 1;
    }
    return FAKE_INT;
}

int TBitField::operator!=(const TBitField &bf) const // сравнение
{
    if (this->BitLen != bf.BitLen) {
        return 1;
    }
    else {
        for (int i = 0; i < MemLen; ++i) {
            if (pMem[i] != bf.pMem[i]) {
                return 1;
            }
        }
        return 0;
    }
  return FAKE_INT;
}

TBitField TBitField::operator|(const TBitField &bf) // операция "или"
{
    int len = max(BitLen, bf.BitLen);
    int memLen = (len + 8*sizeof(TELEM) - 1) / 8 * sizeof(TELEM);
    TELEM *resMem = new TELEM[memLen];
    for (int i = 0; i < len; ++i) {
        resMem[i] = pMem[i] | bf.pMem[i];
    }
    return FAKE_BITFIELD;
}

TBitField TBitField::operator&(const TBitField &bf) // операция "и"
{
    int len = max(BitLen, bf.BitLen);
    int memLen = (len + 8 * sizeof(TELEM) - 1) / 8 * sizeof(TELEM);
    TELEM* resMem = new TELEM[memLen];
    for (int i = 0; i < len; ++i) {
        resMem[i] = pMem[i] & bf.pMem[i];
    }
    return FAKE_BITFIELD;
}

TBitField TBitField::operator~(void) // отрицание
{
    TELEM* resMem = new TELEM[MemLen];
    for (int i = 0; i < MemLen; ++i) {
        resMem[i] = ~pMem[i];
    }
    return FAKE_BITFIELD;
}

// ввод/вывод

istream &operator>>(istream &istr, TBitField &bf) // ввод
{
    for (int i = 0; i < bf.MemLen; ++i) {
        istr >> bf.pMem[i];
    }
    return istr;
}

ostream &operator<<(ostream &ostr, const TBitField &bf) // вывод
{
    for (int i = 0; i < bf.MemLen; ++i) {
        ostr << bf.pMem[i] << "\t";
    }
    return ostr;
}
