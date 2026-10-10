// ННГУ, ВМК, Курс "Методы программирования-2", С++, ООП
//
// tbitfield.cpp - Copyright (c) Гергель В.П. 07.05.2001
//   Переработано для Microsoft Visual Studio 2008 Сысоевым А.В. (19.04.2015)
//
// Битовое поле
#include <stdexcept>
#include "tbitfield.h"
#include <cmath>
// Fake variables used as placeholders in tests
static const int FAKE_INT = -1;
static TBitField FAKE_BITFIELD(1);

TBitField::TBitField(int len)
{
    if (len < 0) {
        throw std::out_of_range("0");
    }
    BitLen = len;
    MemLen = (BitLen + 8 * (sizeof(TELEM)) - 1) / (8 * sizeof(TELEM));
    pMem = new TELEM[MemLen];
    std::memset(pMem, 0, sizeof(TELEM) * MemLen); 
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
    if (n<0 || n >= GetLength()) {
        throw std::out_of_range("0");
    }
    return n / (8 * sizeof(TELEM));
}

TELEM TBitField::GetMemMask(const int n) const // битовая маска для бита n
{
    if (n<0 || n >= GetLength()) {
        throw std::out_of_range("0");
    }
    return ((TELEM)1 << (n % (8 * sizeof(TELEM))));
}

// доступ к битам битового поля

int TBitField::GetLength(void) const // получить длину (к-во битов)
{
    return BitLen;
}

void TBitField::SetBit(const int n) // установить бит
{
    if (n<0 || n >= GetLength()) {
        throw std::out_of_range("0");
    }
    TELEM mask = GetMemMask(n);
    int staten = GetMemIndex(n);
    pMem[staten] |= mask;
}

void TBitField::ClrBit(const int n) // очистить бит
{
    if (n<0 || n >= GetLength()) {
        throw std::out_of_range("0");
    }
    TELEM mask = GetMemMask(n);
    int staten = GetMemIndex(n);
    pMem[staten] &= ~mask;
}

int TBitField::GetBit(const int n) const // получить значение бита
{
    if (n<0 || n >= GetLength()) {
        throw std::out_of_range("0");
    }
    TELEM mask = GetMemMask(n);
    int staten = GetMemIndex(n);
    if ((pMem[staten] & mask) != 0) {
        return 1;
    }
    else {
        return 0;
    }
}

// битовые операции

const TBitField& TBitField::operator=(const TBitField& bf) // присваивание
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
    return *this;
}

int TBitField::operator==(const TBitField& bf) const // сравнение
{
    if (this->BitLen != bf.BitLen) {
        return 0;
    }
    else {
        for (int i = 0; i < MemLen; ++i) {
            if (pMem[i] != bf.pMem[i]) {
                return 0;
            }
        }
    }
    return 1;
}

int TBitField::operator!=(const TBitField& bf) const // сравнение
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
    }
    return 0;
}

TBitField TBitField::operator|(const TBitField& bf) // операция "или"
{
    int len = max(BitLen, bf.BitLen);
    TBitField res(len);                       
    for (int i = 0; i < res.MemLen; ++i) {
        TELEM a = (i < MemLen) ? pMem[i] : 0;
        TELEM b = (i < bf.MemLen) ? bf.pMem[i] : 0;
        res.pMem[i] = a | b;
    }
    return res;
}

TBitField TBitField::operator&(const TBitField& bf) // операция "и"
{
    int len = max(BitLen, bf.BitLen);
    TBitField res(len);         
    for (int i = 0; i < res.MemLen; ++i) {
        TELEM a = (i < MemLen) ? pMem[i] : 0;
        TELEM b = (i < bf.MemLen) ? bf.pMem[i] : 0;
        res.pMem[i] = a & b;
    }
    return res;
}

TBitField TBitField::operator~(void) // отрицание
{
    TBitField res(BitLen);
    for (int i = 0; i < MemLen; ++i) {
        res.pMem[i] = ~pMem[i];
    }
    int t = BitLen % (8 * sizeof(TELEM));
    if (t != 0 && res.MemLen > 0) {
        TELEM mask = ((TELEM)1 << t) - 1;
        res.pMem[res.MemLen - 1] &= mask;
    }
    return res;
}

// ввод/вывод

istream& operator>>(istream& istr, TBitField& bf) // ввод
{
    for (int i = 0; i < bf.BitLen; ++i) {
        istr >> bf.pMem[i];
    }
    return istr;
}

ostream& operator<<(ostream& ostr, const TBitField& bf) // вывод
{
    for (int i = 0; i < bf.BitLen; ++i) {
        ostr << bf.GetBit(i) << "\t";
    }
    return ostr;
}