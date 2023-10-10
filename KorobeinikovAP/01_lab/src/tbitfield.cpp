// ННГУ, ВМК, Курс "Методы программирования-2", С++, ООП
//
// tbitfield.cpp - Copyright (c) Гергель В.П. 07.05.2001
//   Переработано для Microsoft Visual Studio 2008 Сысоевым А.В. (19.04.2015)
//
// Битовое поле

#include "tbitfield.h"
#include  <math.h>

TBitField::TBitField(int len)
{
    if (len <= 0) {
        throw "length < 0";
    }
    BitLen = len;
    MemLen = (BitLen + bitsInElem - 1) >> shiftSize;
    pMem = new TELEM[MemLen];
    memset(pMem, 0, MemLen * sizeof(TELEM));
}

TBitField::TBitField(const TBitField &bf) // конструктор копирования
{
    BitLen = bf.BitLen;
    MemLen = bf.MemLen;
    pMem = new TELEM[MemLen];
    memcpy(pMem, bf.pMem, sizeof(TELEM) * MemLen);
}

TBitField::~TBitField()
{
    delete[]pMem;
}

int TBitField::GetMemIndex(const int n) const   // индекс Мем для бита n
{
    if (n < 0) {
        throw "n < 0";
    }
    return (n >> shiftSize);
}

TELEM TBitField::GetMemMask(const int n) const // битовая маска для бита 
{
    if (n < 0) {
        throw "n < 0";
    }
    return (1 << ( (n & (bitsInElem - 1) )));
   
}

// доступ к битам битового поля

int TBitField::GetLength(void) const // получить длину (к-во битов)
{
  return BitLen;
}

void TBitField::SetBit(const int n) // установить бит
{
    if (n < 0) {
        throw "n < 0";
    }
    if (n >= BitLen) {
        throw "n >= BitLen";
    }
    (pMem[GetMemIndex(n)] = pMem[GetMemIndex(n)] | GetMemMask(n));
}

void TBitField::ClrBit(const int n) // очистить бит
{
    if (n < 0) {
        throw "n < 0";
    }
    if (n >= BitLen) {
        throw "n >= 0";
    }
    pMem[GetMemIndex(n)] = pMem[GetMemIndex(n)] & ~(GetMemMask(n));
}

int TBitField::GetBit(const int n) const // получить значение бита
{
    if (n < 0) {
        throw "n < 0";
    }
    if (n >= BitLen) {
        throw "n > 0";
    }
    return ((pMem[GetMemIndex(n)] & (GetMemMask(n))) >> (n & (bitsInElem - 1)));    
}

// битовые операции

TBitField& TBitField::operator=(const TBitField &bf) // присваивание
{
    if (this == &bf) {
        return(*this);
    }
    if (BitLen != bf.BitLen) {
        BitLen = bf.BitLen;
        MemLen = bf.MemLen;
        pMem = new TELEM[MemLen];
    }
    for (int i = 0; i < BitLen; i++) {
        pMem[i] = bf.pMem[i];
    }
    return (*this);
}

int TBitField::operator== (const TBitField &bf) const // сравнение
{
    if (BitLen != bf.BitLen) {
        throw "Non Equal size";
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
    if (BitLen != bf.BitLen) {
        throw "Non Equal size";
    }
    for (int i = 0; i < MemLen; i++) {
        if (pMem[i] != bf.pMem[i]) {
            return 1;
        }
    }
    return 0;
}

TBitField TBitField::operator|(const TBitField &bf) // операция "или"
{
    /*
    TBitField tmp(max(BitLen, bf.BitLen));
    if (MemLen >= bf.MemLen) {
        tmp = *this;
    }
    else {
        tmp = bf;
    }
    for (int i = 0; i < min(MemLen, bf.MemLen); i++) {
        tmp.pMem[i] = pMem[i] | bf.pMem[i];
    }
    return (tmp);
    */
    TBitField tmp(max(BitLen, bf.BitLen));
    for (int i = 0; i < BitLen; i++) {
        if (GetBit(i)) {
            tmp.SetBit(i);
        }
    }
    for (int i = 0; i < bf.BitLen; i++) {
        tmp.pMem[i] = tmp.pMem[i] | bf.pMem[i];
    }
    return (tmp);
}

TBitField TBitField::operator&(const TBitField &bf) // операция "и"
{
    /*
    TBitField tmp(max(BitLen, bf.BitLen));
    if (MemLen >= bf.MemLen) {
        tmp = *this;
    }
    else {
        tmp = bf;
    }
    for (int i = 0; i < min(MemLen, bf.MemLen); i++) {
        tmp.pMem[i] = pMem[i] & bf.pMem[i];
    }
    for (int i = min(MemLen, bf.MemLen); i <max(MemLen, bf.MemLen); i++) {
        tmp.pMem[i] = 0;
    }
    return (tmp);
    throw "Method is not implemented";
    */
    TBitField tmp(max(BitLen, bf.BitLen));
    for (int i = 0; i < min(MemLen, bf.MemLen); i++) {
        tmp.pMem[i] = pMem[i] & bf.pMem[i];
    }
    return (tmp);  
}

TBitField TBitField::operator~(void) // отрицание
{
    TBitField tmp(BitLen);

    for (int i = 0; i < BitLen; i++) {
        if (GetBit(i)) {
            tmp.SetBit(i);
        }
    }

    for (int i = 0; i < BitLen; i++) {
        if (tmp.GetBit(i)) {
            tmp.ClrBit(i);
        }
        else {
            tmp.SetBit(i);
        }
    }
    return(tmp);
    throw "Method is not implemented";
}

// ввод/вывод

istream &operator>>(istream &istr, TBitField &bf) // ввод
{

    std::cout << "Input BitField: \n";
    int tmp;
    for (int i = 0; i < bf.BitLen; i++) {
        istr >> tmp;
        if ((i != 0) && (i != 1)) {
            throw "The bit cannot take such a value";
        }
        if (tmp == 0) {
            bf.ClrBit(i);
        }
        else {
            bf.SetBit(i);
        }
    }
    return istr;
}

ostream &operator<<(ostream &ostr, const TBitField &bf) // вывод
{

    // ostr << "Output BitField: \n";
    for (int i = 0; i < bf.BitLen; i++) {
        ostr << bf.GetBit(i) << ' ';
    }
    ostr << endl;
    return ostr;

}

