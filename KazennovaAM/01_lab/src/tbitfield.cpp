// ННГУ, ВМК, Курс "Методы программирования-2", С++, ООП
//
// tbitfield.cpp - Copyright (c) Гергель В.П. 07.05.2001
//   Переработано для Microsoft Visual Studio 2008 Сысоевым А.В. (19.04.2015)
//
// Битовое поле

#include "tbitfield.h"

TBitField::TBitField(int len)
{
    if (len < 0) {
        throw "it was not copied";
    }
    BitLen = len;
    MemLen = (len / (sizeof(TELEM) * 8)) + 1;
    pMem = new TELEM[MemLen];
    for (int i = 0; i < MemLen; i++) {
        pMem[i] = 0;
    }
}

TBitField::TBitField(const TBitField &bf) // конструктор копирования
{
    BitLen = bf.BitLen;
    MemLen = bf.MemLen;
    pMem = new TELEM[bf.MemLen];
    for (int i = 0; i < MemLen; i++) {
        pMem[i] = bf.pMem[i];
    }
}

TBitField::~TBitField()
{
    delete[] this->pMem;
}

int TBitField::GetMemIndex(const int n) const // индекс Мем для бита n
{
    if (n < 0 || n >= BitLen) {
        throw "There is no index";
    }
    else
        return n / (sizeof(TELEM) * 8);
}

TELEM TBitField::GetMemMask(const int n) const // битовая маска для бита n
{
    return 1 << (n % (sizeof(TELEM) * 8));
}

// доступ к битам битового поля

int TBitField::GetLength(void) const // получить длину (к-во битов)
{
    return BitLen;
}

void TBitField::SetBit(const int n) // установить бит
{
    if (n >= 0 && n < BitLen) {
        pMem[GetMemIndex(n)] |= GetMemMask(n); //Побитовое или, совмещённое с присваиванием
    }
    else {
        throw "There is no index";
    }
}

void TBitField::ClrBit(const int n) // очистить бит
{
    if (n >= 0 && n < BitLen) {
        pMem[GetMemIndex(n)] &= ~GetMemMask(n);
    }
    else {
        throw "There is no index";
    }
}

int TBitField::GetBit(const int n) const // получить значение бита
{
    if (n >= 0 && n < BitLen) {
        return (pMem[GetMemIndex(n)] & GetMemMask(n)) != 0;
    }
    else {
        throw "There is no index";
    }
}

// битовые операции

const TBitField& TBitField::operator=(const TBitField &bf) // присваивание
{
    if (this != &bf) {
        BitLen = bf.BitLen;
        MemLen = bf.MemLen;
        delete[] this->pMem;
        pMem = new TELEM[MemLen];
        for (int i = 0; i < MemLen; i++) {
            pMem[i] = bf.pMem[i];
        }
    }

    return *this;
}

int TBitField::operator==(const TBitField &bf) const // сравнение
{
    if (BitLen != bf.BitLen) {
        return 0;
    }
    for (int i = 0; i < MemLen; ++i) {
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
    int max_len;
    if (BitLen <= bf.BitLen) {
        max_len = bf.BitLen;
    }
    else
        max_len = BitLen;
    TBitField res(max_len);
    if (MemLen > bf.MemLen) {
        for (int i = 0; i < bf.MemLen; i++) {
            res.pMem[i] = this->pMem[i] | bf.pMem[i];
        }
        for (int i = bf.MemLen; i < MemLen; i++) {
            res.pMem[i] = this->pMem[i];
        }
    }
    else {
        for (int i = 0; i < MemLen; i++) {
            res.pMem[i] = this->pMem[i] | bf.pMem[i];
        }
        for (int i = MemLen; i < bf.MemLen; i++) {
            res.pMem[i] = bf.pMem[i];

        }

    }
    return res;
}

TBitField TBitField::operator&(const TBitField &bf) // операция "и"
{
    int max_len;
    if (BitLen <= bf.BitLen) {
        max_len = bf.BitLen;
    }
    else
        max_len = BitLen;
    TBitField res(max_len);
    for (int i = 0; i < std::min(MemLen, bf.MemLen); ++i) {
        res.pMem[i] = this->pMem[i] & bf.pMem[i];
    }

    return res;
}

TBitField TBitField::operator~(void) // отрицание
{
    TBitField res(BitLen);

    for (int i = 0; i < MemLen; ++i) {
        res.pMem[i] = ~pMem[i];
    }

    int last_bit = BitLen % (sizeof(TELEM) * 8);
    if (last_bit != 0) {
        TELEM mask = (static_cast<TELEM>(1 << last_bit) - 1);
        res.pMem[MemLen - 1] &= mask;
    }

    return res;
}

// ввод/вывод

istream &operator>>(istream &istr, TBitField &bf) // ввод
{
    char ch;
    for (int i = 0; i < bf.BitLen; ++i) {
        istr >> ch;
        if (ch == '1') {
            bf.SetBit(i); //setbit - установить бит
        }
        else {
            bf.ClrBit(i); // очистить бит
        }
    }
    return istr;
}

ostream &operator<<(ostream &ostr, const TBitField &bf) // вывод
{
    for (int i = 0; i < bf.BitLen; ++i) {
        if (bf.GetBit(i)) { //получить значение
            ostr << '1';
        }
        else {
            ostr << '0';
        }
    }
    return ostr;
}
