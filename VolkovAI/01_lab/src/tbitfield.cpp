// ННГУ, ВМК, Курс "Методы программирования-2", С++, ООП
//
// tbitfield.cpp - Copyright (c) Гергель В.П. 07.05.2001
//   Переработано для Microsoft Visual Studio 2008 Сысоевым А.В. (19.04.2015)
//
// Битовое поле

#include "tbitfield.h"

TBitField::TBitField(int len)
{
    if (len <= 0) {
        throw len;
    }
    this->BitLen = len;
    this->MemLen = (len / (sizeof(TELEM) * 8)) + 1;
    this->pMem = new TELEM[this->MemLen];
    for (int i = 0; i < this->MemLen; i++) {
        this->pMem[i] = 0;
    }
}

TBitField::TBitField(const TBitField& bf) // конструктор копирования
{
    this->BitLen = bf.BitLen;
    this->MemLen = bf.MemLen;
    this->pMem = new TELEM[this->MemLen];
    for (int i = 0; i < this->MemLen; i++) {
        this->pMem[i] = bf.pMem[i];
    }
}

TBitField::~TBitField()
{
    if (this->pMem != nullptr) {
        delete [] this->pMem;
    }
}

int TBitField::GetMemIndex(const int n) const // индекс Мем для бита n
{
    return n / (sizeof(TELEM) * 8);
}

TELEM TBitField::GetMemMask(const int n) const // битовая маска для бита n
{
    return 1 << n % (sizeof(TELEM) * 8);
}

// доступ к битам битового поля

int TBitField::GetLength(void) const // получить длину (к-во битов)
{
    return this->BitLen;
}

void TBitField::SetBit(const int n) // установить бит
{
    if ((n < 0) || (n > this->BitLen))
    {
        throw n;
    }
    int index = GetMemIndex(n);
    TELEM temp = GetMemMask(n);
    this->pMem[index] |= temp;
}

void TBitField::ClrBit(const int n) // очистить бит
{
    if ((n < 0) || (n > this->BitLen))
    {
        throw n;
    }
    int index = GetMemIndex(n);
    TELEM temp = GetMemMask(n);
    this->pMem[index] &= ~temp;
}

int TBitField::GetBit(const int n) const // получить значение бита
{
    if ((n < 0) || (n > this->BitLen))
    {
        throw n;
        return 0;
    }
    int index = GetMemIndex(n);
    TELEM temp = GetMemMask(n);
    if (temp == (temp & this->pMem[index])) {
        return 1;
    }
}

// битовые операции

const TBitField& TBitField::operator=(const TBitField& bf) // присваивание
{
    if (this == &bf) {
        return *this;
    }
    if (this->MemLen != bf.MemLen)
    {
        delete[] this->pMem;
        this->MemLen = bf.MemLen;
        this->pMem = new TELEM[this->MemLen];
    }
    this->BitLen = bf.BitLen;
    for (int i = 0; i < MemLen; i++) {
        this->pMem[i] = bf.pMem[i];
    }
    return (*this);
}

int TBitField::operator==(const TBitField& bf) const // сравнение
{
    if (this->BitLen != bf.BitLen) {
        return 0;
    }
    for (int i = 0; i < this->MemLen; i++) {
        if (this->pMem[i] != bf.pMem[i]) {
            return 0;
        }
    }
    return 1;
}

int TBitField::operator!=(const TBitField& bf) const // сравнение
{
    return !(*this == bf);
}

TBitField TBitField::operator|(const TBitField& bf) // операция "или"
{
    int max_len = this->BitLen;
    if (max_len < bf.BitLen) {
        max_len = bf.BitLen;
    }
    TBitField Result(max_len);

    for (int i = 0; i < this->MemLen; i++) {
        Result.pMem[i] = this->pMem[i];
    }
    for (int i = 0; i < bf.MemLen; i++) {
        Result.pMem[i] |= bf.pMem[i];
    }

    return Result;
}

TBitField TBitField::operator&(const TBitField& bf) // операция "и"
{
    int max_len = this->BitLen;
    if (max_len < bf.BitLen) {
        max_len = bf.BitLen;
    }
    TBitField Result(max_len);
    for (int i = 0; i < this->MemLen; i++) {
        Result.pMem[i] = this->pMem[i];
    }
    for (int i = 0; i < bf.MemLen; i++) {
        Result.pMem[i] &= bf.pMem[i];
    }
    return Result;
}

TBitField TBitField::operator~(void) // отрицание
{
    TBitField Result(this->BitLen);
    for (int i = 0; i < this->BitLen; i++) {
        if (GetBit(i) == 0) {
            Result.SetBit(i);
        }
    }
    return Result;
}

// ввод/вывод

istream& operator>>(istream& istr, TBitField& bf) // ввод
{
    string k;
    istr >> k;
    if (k.size() != bf.BitLen)
    {
        throw "Input and bitfield have different sizes.";
    }
    for (int i = 0; i < bf.BitLen; i++) {
        if (k[i] == '1') {
            bf.SetBit(i);
        }
    }
    return istr;
}

ostream& operator<<(ostream& ostr, const TBitField& bf) // вывод
{
    for (int i = 0; i < bf.GetLength(); i++)
        ostr << bf.GetBit(i);
    return ostr;
}
