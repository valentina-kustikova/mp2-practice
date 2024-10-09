// ННГУ, ВМК, Курс "Методы программирования-2", С++, ООП
//
// tbitfield.cpp - Copyright (c) Гергель В.П. 07.05.2001
//   Переработано для Microsoft Visual Studio 2008 Сысоевым А.В. (19.04.2015)
//
// Битовое поле

#include "tbitfield.h"

// Fake variables used as placeholders in tests
static const int FAKE_INT = -1;
static TBitField FAKE_BITFIELD(1);

TBitField::TBitField(int len)
{
    if (len > 0) {
        this->BitLen = len;
        MemLen = (len / (sizeof(TELEM) * 8)) + 1;
        this->pMem = new TELEM[this->MemLen];
        for (int i = 0; i < this->MemLen; i++) {
            this->pMem[i] = 0;
        }
    }
    else {
       throw len;
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
    if (pMem != nullptr) {
        delete [] pMem;
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
    return BitLen;
}

void TBitField::SetBit(const int n) // установить бит
{
    if ((n > -1) && (n < BitLen))
    {
        int index = GetMemIndex(n);
        TELEM temp = GetMemMask(n);
        this->pMem[index] |= temp;
    }
    else { throw n; }
}

void TBitField::ClrBit(const int n) // очистить бит
{
    if ((n > -1) && (n < BitLen))
    {
        int index = GetMemIndex(n);
        TELEM temp = GetMemMask(n);
        this->pMem[index] &= ~temp;
    }
    else { throw n; }
}

int TBitField::GetBit(const int n) const // получить значение бита
{
    if ((n > -1) && (n < BitLen))
    {
        int index = GetMemIndex(n);
        TELEM temp = GetMemMask(n);
        if (temp == (temp & this->pMem[index])) { return 1; }
    }
    else { throw n; }
    return 0;
}

// битовые операции

const TBitField& TBitField::operator=(const TBitField& bf) // присваивание
{
    if (this != &bf) {
        delete[] this->pMem;
        this->BitLen = bf.BitLen;
        this->MemLen = bf.MemLen;
        this->pMem = new TELEM[this->MemLen];
        for (int i = 0; i < MemLen; i++) {
            this->pMem[i] = bf.pMem[i];
        }
    }
    return (*this);
}

int TBitField::operator==(const TBitField& bf) const // сравнение
{
    if (this->BitLen != bf.BitLen) {
        return 0;
    }
    else {
        for (int i = 0; i < this->MemLen; i++) {
            if (this->pMem[i] != bf.pMem[i]) {
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
        for (int i = 0; i < this->BitLen; i++) {
            if (this->pMem[i] == bf.pMem[i]) {
                continue;
            }
            else {
                return 1;
            }
        }
    }
    return 0;
}

TBitField TBitField::operator|(const TBitField& bf) // операция "или"
{
    int max_len = (this->BitLen > bf.BitLen) ? this->BitLen : bf.BitLen;
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
    int k;
    for (int i = 0; i < bf.GetLength(); i++)
    {
        istr >> k;
        if (k == 1) {
            bf.SetBit(i);
        }
        else if (k == 0)
        {
            bf.ClrBit(i);
        }
        else {
            break;
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
