// ННГУ, ВМК, Курс "Методы программирования-2", С++, ООП
//
// tbitfield.cpp - Copyright (c) Гергель В.П. 07.05.2001
//   Переработано для Microsoft Visual Studio 2008 Сысоевым А.В. (19.04.2015)
//
// Битовое поле

#include <string>
#include "tbitfield.h"

TBitField::TBitField(int len)
{
    if (len < 0) {
        throw "Negative len";
    }
    BitLen = len;
    MemLen = len/(sizeof(TELEM) *8) + 1;
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
    if (n < 0 || n > BitLen) {
        throw "Incorrect index";
    }
    return n / (sizeof(TELEM) * 8);
}

TELEM TBitField::GetMemMask(const int n) const // битовая маска для бита n
{
    if (n < 0 || n > BitLen) {
        throw "Incorrect index";
    }
    return 1 << (n % (sizeof(TELEM) * 8));
}

// доступ к битам битового поля

int TBitField::GetLength(void) const // получить длину (к-во битов)
{
  return BitLen;
}

void TBitField::SetBit(const int n) // установить бит
{
    if (n < 0 || n >= BitLen) {
        throw "Incorrect index";
    }
    pMem[GetMemIndex(n)] = pMem[GetMemIndex(n)] | GetMemMask(n);
}

void TBitField::ClrBit(const int n) // очистить бит
{
    if (n < 0 || n >= BitLen) {
        throw "Incorrect index";
    }
    pMem[GetMemIndex(n)] = pMem[GetMemIndex(n)] & (~GetMemMask(n));
}

int TBitField::GetBit(const int n) const // получить значение бита
{
    if (n < 0 || n >= BitLen) {
        throw "Incorrect index";
    }
    return (pMem[GetMemIndex(n)] & GetMemMask(n));
}

// битовые операции

const TBitField& TBitField::operator=(const TBitField &bf) // присваивание
{
    if (this == &bf) {
        return *this;
    }
    if (MemLen != bf.MemLen) {
        delete[] pMem;
        MemLen = bf.MemLen;
        pMem = new TELEM[MemLen];
    }
    BitLen = bf.BitLen;
    for (int i = 0; i < MemLen; i++){
        pMem[i] = bf.pMem[i];
    }
    return *this;   
}

int TBitField::operator==(const TBitField &bf) const // сравнение
{
    if (BitLen != bf.BitLen) {
        return 0;
    }
    for (int i = 0; i < MemLen; i++) {
        if (pMem[i] != bf.pMem[i]) {
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
    int len = max(BitLen, bf.BitLen);
    TBitField temp(len);
    for (int i = 0; i < MemLen; i++) {
        temp.pMem[i] = pMem[i] | bf.pMem[i];
    }
    if (MemLen > bf.MemLen) {
        for (int i = bf.MemLen; i < MemLen; i++) {
            temp.pMem[i] = pMem[i];
        }
    }
    else {
        for (int i = MemLen; i < bf.MemLen; i++) {
            temp.pMem[i] = bf.pMem[i];
        }
    }
    return temp;
}

TBitField TBitField::operator&(const TBitField &bf) // операция "и"
{
    int len = max(BitLen, bf.BitLen);
    TBitField temp(len);
    for (int i = 0; i < MemLen; i++) {
        temp.pMem[i] = pMem[i] & bf.pMem[i];
    }
    if (MemLen > bf.MemLen) {
        for (int i = bf.MemLen; i < MemLen; i++) {
            temp.pMem[i] = pMem[i];
        }
    }
    else {
        for (int i = MemLen; i < bf.MemLen; i++) {
            temp.pMem[i] = bf.pMem[i];
        }
    }
    return temp;
}

TBitField TBitField::operator~(void) // отрицание
{
    TBitField temp(BitLen);
    for (int i = 0; i < BitLen; i++) {
        if (GetBit(i) == 0) {
            temp.SetBit(i);
        }
        else {
            temp.ClrBit(i);
        }
    }
    return temp;
}

// ввод/вывод

istream &operator>>(istream &istr, TBitField &bf) // ввод
{
    string bit;
    istr >> bit;
    for (int i = 0; i < bf.BitLen; i++) {
        if (bit[i] == '1') {
            bf.SetBit(i);
        }
        else if (bit[i] == '0') {
            bf.ClrBit(i);
        }
        else {
            throw "Incorrect bit";
        }
    }
    return istr;
}

ostream &operator<<(ostream &ostr, const TBitField &bf) // вывод
{
    for (int i = 0; i < bf.BitLen; i++){
        ostr << bf.GetBit(i); 
    }
    return ostr;
}
